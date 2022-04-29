/******************************************************************************
*
* Copyright (C) 2009 - 2014 Xilinx, Inc.  All rights reserved.
*
* Permission is hereby granted, free of charge, to any person obtaining a copy
* of this software and associated documentation files (the "Software"), to deal
* in the Software without restriction, including without limitation the rights
* to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
* copies of the Software, and to permit persons to whom the Software is
* furnished to do so, subject to the following conditions:
*
* The above copyright notice and this permission notice shall be included in
* all copies or substantial portions of the Software.
*
* Use of the Software is limited solely to applications:
* (a) running on a Xilinx device, or
* (b) that interact with a Xilinx device through a bus or interconnect.
*
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
* IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
* FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
* XILINX  BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
* WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF
* OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
* SOFTWARE.
*
* Except as contained in this notice, the name of the Xilinx shall not be used
* in advertising or otherwise to promote the sale, use or other dealings in
* this Software without prior written authorization from Xilinx.
*
******************************************************************************/

/*
 * apuFaultInjection.c: simple test application injecting isolation faults
 * using reads and writes from the APU into RPU/APU Secure and Non-Secure memory
 * address locations
 *
 *
 * Modified S.Donchez for XMPU-PL isolation design testing
 *
 */

#include <stdio.h>
#include <unistd.h>
#include <stdbool.h>
#include "xil_printf.h"
#include "xil_io.h"
#include "xil_cache.h"
#include "xil_exception.h"
#include "apuFaultInjection.h"


static int 	SetupInterruptSystem(void);
void 		SAbort_SyncIntHandler(int);
void 		SAbort_SErrorAbortIntHandler(int);

static void readReg(char registerName[30], u32 registerAddress);
static void writeReg(char registerName[30], u32 registerAddress, u32 regVal);

bool 		exceptionDetected = false;



int main()
{
    SetupInterruptSystem(); //register custom interrupt handlers in this application

    // Disable caches here for demonstration purposes.  If enabled all write violations look like read violations
    // due to the cache read before a write transaction.
    Xil_DCacheDisable(); //disable data cache
    Xil_ICacheDisable(); //disable instruction cache

	print("---Starting Fault Injection Test (Running on the APU)---\n\n\r");
	print("   Since the APU is the trusted master, all operations should execute successfully");

	print("   Locations to test\n\r");
	print("   \tDFX Controller XMPU-PL Config Registers \n\r");
	print("   \tAES Engine XMPU-PL Config Registers \n\r");
	print("   \tKAC Engine XMPU-PL Config Registers \n\r");
	print("   \tTenant Upstream XPMU-PL Config Registers \n\r");
	print("   \tTenant Downstream XMPU-PL Config Registers \n\r");
	print("   \tDFX Engine Configuration Registers \n\r");


	usleep(10*DELAY_COUNT);


// Memory Checks (Read / Modify / Write / Read)

	print("\n\n   Read/Write Of Various Locations\n\r");
		print("\n\t DFX Controller XMPU-PL Config Registers\n\r");
			readReg( "XPAR_ZUPL_XMPU_0_S_AXI_XMPU_BASEADDR", XPAR_ZUPL_XMPU_0_S_AXI_XMPU_BASEADDR);
		    writeReg("XPAR_ZUPL_XMPU_0_S_AXI_XMPU_BASEADDR", XPAR_ZUPL_XMPU_0_S_AXI_XMPU_BASEADDR, 0xDEADBEEF);

		print("\n\t AES Controller XMPU-PL Config Registers\n\r");
			readReg( "XPAR_ZUPL_XMPU_1_S_AXI_XMPU_BASEADDR", XPAR_ZUPL_XMPU_1_S_AXI_XMPU_BASEADDR);
			writeReg("XPAR_ZUPL_XMPU_1_S_AXI_XMPU_BASEADDR", XPAR_ZUPL_XMPU_1_S_AXI_XMPU_BASEADDR, 0xDEADBEEF);

		print("\n\t KAC Controller XMPU-PL Config Registers\n\r");
			readReg( "XPAR_ZUPL_XMPU_2_S_AXI_XMPU_BASEADDR", XPAR_ZUPL_XMPU_2_S_AXI_XMPU_BASEADDR);
			writeReg("XPAR_ZUPL_XMPU_2_S_AXI_XMPU_BASEADDR", XPAR_ZUPL_XMPU_2_S_AXI_XMPU_BASEADDR, 0xDEADBEEF);

		print("\n\t Tenant Upstream XMPU-PL Config Registers\n\r");
			readReg( "XPAR_ZUPL_XMPU_3_S_AXI_XMPU_BASEADDR", XPAR_ZUPL_XMPU_3_S_AXI_XMPU_BASEADDR);
			writeReg("XPAR_ZUPL_XMPU_3_S_AXI_XMPU_BASEADDR", XPAR_ZUPL_XMPU_3_S_AXI_XMPU_BASEADDR, 0xDEADBEEF);

		print("\n\t Tenant Downstream XMPU-PL Config Registers\n\r");
			readReg( "XPAR_ZUPL_XMPU_4_S_AXI_XMPU_BASEADDR", XPAR_ZUPL_XMPU_4_S_AXI_XMPU_BASEADDR);
			writeReg("XPAR_ZUPL_XMPU_4_S_AXI_XMPU_BASEADDR", XPAR_ZUPL_XMPU_4_S_AXI_XMPU_BASEADDR, 0xDEADBEEF);

		print("\n\t DFX Controller Config Registers\n\r");
			readReg( "XPAR_DFX_CONTROLLER_0_SW_TRIGGER_REG", XPAR_DFX_CONTROLLER_0_BASEADDR+16);
			writeReg("XPAR_DFX_CONTROLLER_0_SW_TRIGGER_REG", XPAR_DFX_CONTROLLER_0_BASEADDR+16, 0xDEADBEEF);

	print("\n\n---Fault Injection Test Complete---\n\n\n\r");

// Done

    return 0;
}

void readReg(char registerName[30], u32 registerAddress)
{
	u32 regVal;

	exceptionDetected = false;
		xil_printf("\t\t Reading %-30s ... ", registerName);
			regVal=Xil_In32(registerAddress);
			print(" ");
			usleep(DELAY_COUNT);
		print(exceptionDetected ? "FAILED!":"PASS!"); print("\n\r");
	exceptionDetected = false;
}

void writeReg(char registerName[30], u32 registerAddress, u32 regVal)
{
	exceptionDetected = false;
	xil_printf("\t\t Writing %-30s ... ", registerName);
			Xil_Out32(registerAddress, regVal);
			print(" ");
			usleep(DELAY_COUNT);
		print(exceptionDetected ? "FAILED!":"PASS!"); print("\n\r");
	exceptionDetected = false;
}


static int SetupInterruptSystem(void)
{
	//Connect the interrupt controller interrupt handler to the hardware
	//interrupt handling logic in the ARM processor.

	Xil_ExceptionRegisterHandler(XIL_EXCEPTION_ID_SYNC_INT,
			(Xil_ExceptionHandler) SAbort_SyncIntHandler,
			XIL_EXCEPTION_ID_SYNC_INT);

	Xil_ExceptionRegisterHandler(XIL_EXCEPTION_ID_SERROR_ABORT_INT,
			(Xil_ExceptionHandler) SAbort_SErrorAbortIntHandler,
			XIL_EXCEPTION_ID_SERROR_ABORT_INT);


	//Enable interrupts in the ARM
	Xil_ExceptionEnable();

	return 0;
}


void SAbort_SyncIntHandler(int Data)
{
	exceptionDetected = true;
	usleep(DELAY_COUNT);

	//update the return address to prevent returning to the same offending read transaction
	__asm__ __volatile ("mrs x1, ELR_EL3");
	__asm__ __volatile ("add x1, x1, #4");
	__asm__ __volatile ("msr ELR_EL3, x1");
return ;
}

void SAbort_SErrorAbortIntHandler(int Data)
{
	exceptionDetected = true;
	usleep(DELAY_COUNT);
return ;
}





