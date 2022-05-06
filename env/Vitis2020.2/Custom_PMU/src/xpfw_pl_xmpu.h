/*
 * xpfw_pl_xmpu.h
 *
 */

#ifndef SRC_XPFW_PL_XMPU_H_
#define SRC_XPFW_PL_XMPU_H_

/***************************** Include Files ********************************/
#include "xil_types.h"
#include "xil_io.h"
#include "xil_printf.h"
#include "xpfw_core.h"
#include "zupl_xmpu.h"
#include "pmu_global.h"
/************************** Constant Definitions ****************************/

/* How often the XMpuPl Task task is called (in msecs) */
#define XMPUPL_TASK_INTERVAL 			25U

/* XMPU PL Configuration Parameters */
#define XMPU_DEVICE_ID 		XPAR_ZUPL_XMPU_0_DEVICE_ID
#define XMPU_CTRL			( XMPU_PL_CTRL_DEFRD 		\
							| XMPU_PL_CTRL_DEFWR 		\
							| XMPU_PL_CTRL_PSNATTREN 	\
							| XMPU_PL_CTRL_PSNADDREN	\
							| XMPU_PL_CTRL_ARSP_DEC)
#define XMPU_INT_EN			(XMPU_PL_IXR_WRVIO_MSK | XMPU_PL_IXR_RDVIO_MSK)
#define XMPU_LOCK_MASTERS	(XMPU_PL_MID_PMU | XMPU_PL_MID_RPU0)

/* PMU ERROR Registers */
#define PMU_PL_ERROR_MASK	(0xFU << PMU_GLOBAL_ERROR_EN_2_PL_SHIFT)

/* CSU Module */
#define PCAP_STAT_DONE_EOS	0x00000018U

/************************** Function Prototypes *****************************/
//void XMpuPl_PmuTaskInit(const XPfw_Module_t *SchModPtr);
//void XMpuPl_PmuTask(void);
void XmpuPl_Interrupt_Handler(u8 ErrorId);

/**************************** Type Definitions *******************************/

/************************** Variable Definitions *****************************/


#endif /* SRC_XPFW_PL_XMPU_H_ */
