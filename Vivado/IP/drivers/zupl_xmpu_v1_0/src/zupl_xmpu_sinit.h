/******************************************************************************
*
* Copyright (C) 2014-2020 Xilinx, Inc.  All rights reserved.
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
/*****************************************************************************/
/**
*
* @file xmpu_pl_sinit.c
* @addtogroup zupl_xmpu_v1_0
* @{
* @details
*
* XMPU_PL is an AXI based memory and peripheral protection unit soft core for
* the PL.
*
* <pre>
* MODIFICATION HISTORY:
*
* Ver   Who     Date     Changes
* ----- ------  -------- ------------------------------------------------------
* 1.0   chc     x/xx/20  First release
* </pre>
*
******************************************************************************/

#ifndef SRC_ZUPL_XMPU_SINIT_H_
#define SRC_ZUPL_XMPU_SINIT_H_

#ifdef __cplusplus
extern "C" {
#endif

/***************************** Include Files *********************************/
#include "xparameters.h"

/************************** Constant Definitions *****************************/
#define XMPU_PL_NUM_MAX	16U

#ifdef XPAR_ZUPL_XMPU_0_DEVICE_ID
#define XMPU_PL_0_DEVICE_ID XPAR_ZUPL_XMPU_0_DEVICE_ID
#define XMPU_PL_0_BASEADDR XPAR_ZUPL_XMPU_0_S_AXI_XMPU_BASEADDR
#define XMPU_PL_0_M_BASEADDR XPAR_ZUPL_XMPU_0_M_AXI_BASEADDR
#define XMPU_PL_0_M_HIGHADDR XPAR_ZUPL_XMPU_0_M_AXI_HIGHADDR
#define XMPU_PL_0_REGIONS_MAX XPAR_ZUPL_XMPU_0_REGIONS_MAX
#else
#define XMPU_PL_0_DEVICE_ID (XPAR_ZUPL_XMPU_NUM_INSTANCES+1)
#define XMPU_PL_0_BASEADDR 0U
#define XMPU_PL_0_M_BASEADDR 0U
#define XMPU_PL_0_M_HIGHADDR 0U
#define XMPU_PL_0_REGIONS_MAX 0U
#endif

#ifdef XPAR_ZUPL_XMPU_1_DEVICE_ID
#define XMPU_PL_1_DEVICE_ID XPAR_ZUPL_XMPU_1_DEVICE_ID
#define XMPU_PL_1_BASEADDR XPAR_ZUPL_XMPU_1_S_AXI_XMPU_BASEADDR
#define XMPU_PL_1_M_BASEADDR XPAR_ZUPL_XMPU_1_M_AXI_BASEADDR
#define XMPU_PL_1_M_HIGHADDR XPAR_ZUPL_XMPU_1_M_AXI_HIGHADDR
#define XMPU_PL_1_REGIONS_MAX XPAR_ZUPL_XMPU_1_REGIONS_MAX
#else
#define XMPU_PL_1_DEVICE_ID (XPAR_ZUPL_XMPU_NUM_INSTANCES+1)
#define XMPU_PL_1_BASEADDR 0U
#define XMPU_PL_1_M_BASEADDR 0U
#define XMPU_PL_1_M_HIGHADDR 0U
#define XMPU_PL_1_REGIONS_MAX 0U
#endif

#ifdef XPAR_ZUPL_XMPU_2_DEVICE_ID
#define XMPU_PL_2_DEVICE_ID XPAR_ZUPL_XMPU_2_DEVICE_ID
#define XMPU_PL_2_BASEADDR XPAR_ZUPL_XMPU_2_S_AXI_XMPU_BASEADDR
#define XMPU_PL_2_M_BASEADDR XPAR_ZUPL_XMPU_2_M_AXI_BASEADDR
#define XMPU_PL_2_M_HIGHADDR XPAR_ZUPL_XMPU_2_M_AXI_HIGHADDR
#define XMPU_PL_2_REGIONS_MAX XPAR_ZUPL_XMPU_2_REGIONS_MAX
#else
#define XMPU_PL_2_DEVICE_ID (XPAR_ZUPL_XMPU_NUM_INSTANCES+1)
#define XMPU_PL_2_BASEADDR 0U
#define XMPU_PL_2_M_BASEADDR 0U
#define XMPU_PL_2_M_HIGHADDR 0U
#define XMPU_PL_2_REGIONS_MAX 0U
#endif

#ifdef XPAR_ZUPL_XMPU_3_DEVICE_ID
#define XMPU_PL_3_DEVICE_ID XPAR_ZUPL_XMPU_3_DEVICE_ID
#define XMPU_PL_3_BASEADDR XPAR_ZUPL_XMPU_3_S_AXI_XMPU_BASEADDR
#define XMPU_PL_3_M_BASEADDR XPAR_ZUPL_XMPU_3_M_AXI_BASEADDR
#define XMPU_PL_3_M_HIGHADDR XPAR_ZUPL_XMPU_3_M_AXI_HIGHADDR
#define XMPU_PL_3_REGIONS_MAX XPAR_ZUPL_XMPU_3_REGIONS_MAX
#else
#define XMPU_PL_3_DEVICE_ID (XPAR_ZUPL_XMPU_NUM_INSTANCES+1)
#define XMPU_PL_3_BASEADDR 0U
#define XMPU_PL_3_M_BASEADDR 0U
#define XMPU_PL_3_M_HIGHADDR 0U
#define XMPU_PL_3_REGIONS_MAX 0U
#endif

#ifdef XPAR_ZUPL_XMPU_4_DEVICE_ID
#define XMPU_PL_4_DEVICE_ID XPAR_ZUPL_XMPU_4_DEVICE_ID
#define XMPU_PL_4_BASEADDR XPAR_ZUPL_XMPU_4_S_AXI_XMPU_BASEADDR
#define XMPU_PL_4_M_BASEADDR XPAR_ZUPL_XMPU_4_M_AXI_BASEADDR
#define XMPU_PL_4_M_HIGHADDR XPAR_ZUPL_XMPU_4_M_AXI_HIGHADDR
#define XMPU_PL_4_REGIONS_MAX XPAR_ZUPL_XMPU_4_REGIONS_MAX
#else
#define XMPU_PL_4_DEVICE_ID (XPAR_ZUPL_XMPU_NUM_INSTANCES+1)
#define XMPU_PL_4_BASEADDR 0U
#define XMPU_PL_4_M_BASEADDR 0U
#define XMPU_PL_4_M_HIGHADDR 0U
#define XMPU_PL_4_REGIONS_MAX 0U
#endif

#ifdef XPAR_ZUPL_XMPU_5_DEVICE_ID
#define XMPU_PL_5_DEVICE_ID XPAR_ZUPL_XMPU_5_DEVICE_ID
#define XMPU_PL_5_BASEADDR XPAR_ZUPL_XMPU_5_S_AXI_XMPU_BASEADDR
#define XMPU_PL_5_M_BASEADDR XPAR_ZUPL_XMPU_5_M_AXI_BASEADDR
#define XMPU_PL_5_M_HIGHADDR XPAR_ZUPL_XMPU_5_M_AXI_HIGHADDR
#define XMPU_PL_5_REGIONS_MAX XPAR_ZUPL_XMPU_5_REGIONS_MAX
#else
#define XMPU_PL_5_DEVICE_ID (XPAR_ZUPL_XMPU_NUM_INSTANCES+1)
#define XMPU_PL_5_BASEADDR 0U
#define XMPU_PL_5_M_BASEADDR 0U
#define XMPU_PL_5_M_HIGHADDR 0U
#define XMPU_PL_5_REGIONS_MAX 0U
#endif

#ifdef XPAR_ZUPL_XMPU_6_DEVICE_ID
#define XMPU_PL_6_DEVICE_ID XPAR_ZUPL_XMPU_6_DEVICE_ID
#define XMPU_PL_6_BASEADDR XPAR_ZUPL_XMPU_6_S_AXI_XMPU_BASEADDR
#define XMPU_PL_6_M_BASEADDR XPAR_ZUPL_XMPU_6_M_AXI_BASEADDR
#define XMPU_PL_6_M_HIGHADDR XPAR_ZUPL_XMPU_6_M_AXI_HIGHADDR
#define XMPU_PL_6_REGIONS_MAX XPAR_ZUPL_XMPU_6_REGIONS_MAX
#else
#define XMPU_PL_6_DEVICE_ID (XPAR_ZUPL_XMPU_NUM_INSTANCES+1)
#define XMPU_PL_6_BASEADDR 0U
#define XMPU_PL_6_M_BASEADDR 0U
#define XMPU_PL_6_M_HIGHADDR 0U
#define XMPU_PL_6_REGIONS_MAX 0U
#endif

#ifdef XPAR_ZUPL_XMPU_7_DEVICE_ID
#define XMPU_PL_7_DEVICE_ID XPAR_ZUPL_XMPU_7_DEVICE_ID
#define XMPU_PL_7_BASEADDR XPAR_ZUPL_XMPU_7_S_AXI_XMPU_BASEADDR
#define XMPU_PL_7_M_BASEADDR XPAR_ZUPL_XMPU_7_M_AXI_BASEADDR
#define XMPU_PL_7_M_HIGHADDR XPAR_ZUPL_XMPU_7_M_AXI_HIGHADDR
#define XMPU_PL_7_REGIONS_MAX XPAR_ZUPL_XMPU_7_REGIONS_MAX
#else
#define XMPU_PL_7_DEVICE_ID (XPAR_ZUPL_XMPU_NUM_INSTANCES+1)
#define XMPU_PL_7_BASEADDR 0U
#define XMPU_PL_7_M_BASEADDR 0U
#define XMPU_PL_7_M_HIGHADDR 0U
#define XMPU_PL_7_REGIONS_MAX 0U
#endif

#ifdef XPAR_ZUPL_XMPU_8_DEVICE_ID
#define XMPU_PL_8_DEVICE_ID XPAR_ZUPL_XMPU_8_DEVICE_ID
#define XMPU_PL_8_BASEADDR XPAR_ZUPL_XMPU_8_S_AXI_XMPU_BASEADDR
#define XMPU_PL_8_M_BASEADDR XPAR_ZUPL_XMPU_8_M_AXI_BASEADDR
#define XMPU_PL_8_M_HIGHADDR XPAR_ZUPL_XMPU_8_M_AXI_HIGHADDR
#define XMPU_PL_8_REGIONS_MAX XPAR_ZUPL_XMPU_8_REGIONS_MAX
#else
#define XMPU_PL_8_DEVICE_ID (XPAR_ZUPL_XMPU_NUM_INSTANCES+1)
#define XMPU_PL_8_BASEADDR 0U
#define XMPU_PL_8_M_BASEADDR 0U
#define XMPU_PL_8_M_HIGHADDR 0U
#define XMPU_PL_8_REGIONS_MAX 0U
#endif

#ifdef XPAR_ZUPL_XMPU_9_DEVICE_ID
#define XMPU_PL_9_DEVICE_ID XPAR_ZUPL_XMPU_9_DEVICE_ID
#define XMPU_PL_9_BASEADDR XPAR_ZUPL_XMPU_9_S_AXI_XMPU_BASEADDR
#define XMPU_PL_9_M_BASEADDR XPAR_ZUPL_XMPU_9_M_AXI_BASEADDR
#define XMPU_PL_9_M_HIGHADDR XPAR_ZUPL_XMPU_9_M_AXI_HIGHADDR
#define XMPU_PL_9_REGIONS_MAX XPAR_ZUPL_XMPU_9_REGIONS_MAX
#else
#define XMPU_PL_9_DEVICE_ID (XPAR_ZUPL_XMPU_NUM_INSTANCES+1)
#define XMPU_PL_9_BASEADDR 0U
#define XMPU_PL_9_M_BASEADDR 0U
#define XMPU_PL_9_M_HIGHADDR 0U
#define XMPU_PL_9_REGIONS_MAX 0U
#endif

#ifdef XPAR_ZUPL_XMPU_10_DEVICE_ID
#define XMPU_PL_10_DEVICE_ID XPAR_ZUPL_XMPU_10_DEVICE_ID
#define XMPU_PL_10_BASEADDR XPAR_ZUPL_XMPU_10_S_AXI_XMPU_BASEADDR
#define XMPU_PL_10_M_BASEADDR XPAR_ZUPL_XMPU_10_M_AXI_BASEADDR
#define XMPU_PL_10_M_HIGHADDR XPAR_ZUPL_XMPU_10_M_AXI_HIGHADDR
#define XMPU_PL_10_REGIONS_MAX XPAR_ZUPL_XMPU_10_REGIONS_MAX
#else
#define XMPU_PL_10_DEVICE_ID (XPAR_ZUPL_XMPU_NUM_INSTANCES+1)
#define XMPU_PL_10_BASEADDR 0U
#define XMPU_PL_10_M_BASEADDR 0U
#define XMPU_PL_10_M_HIGHADDR 0U
#define XMPU_PL_10_REGIONS_MAX 0U
#endif

#ifdef XPAR_ZUPL_XMPU_11_DEVICE_ID
#define XMPU_PL_11_DEVICE_ID XPAR_ZUPL_XMPU_11_DEVICE_ID
#define XMPU_PL_11_BASEADDR XPAR_ZUPL_XMPU_11_S_AXI_XMPU_BASEADDR
#define XMPU_PL_11_M_BASEADDR XPAR_ZUPL_XMPU_11_M_AXI_BASEADDR
#define XMPU_PL_11_M_HIGHADDR XPAR_ZUPL_XMPU_11_M_AXI_HIGHADDR
#define XMPU_PL_11_REGIONS_MAX XPAR_ZUPL_XMPU_11_REGIONS_MAX
#else
#define XMPU_PL_11_DEVICE_ID (XPAR_ZUPL_XMPU_NUM_INSTANCES+1)
#define XMPU_PL_11_BASEADDR 0U
#define XMPU_PL_11_M_BASEADDR 0U
#define XMPU_PL_11_M_HIGHADDR 0U
#define XMPU_PL_11_REGIONS_MAX 0U
#endif

#ifdef XPAR_ZUPL_XMPU_12_DEVICE_ID
#define XMPU_PL_12_DEVICE_ID XPAR_ZUPL_XMPU_12_DEVICE_ID
#define XMPU_PL_12_BASEADDR XPAR_ZUPL_XMPU_12_S_AXI_XMPU_BASEADDR
#define XMPU_PL_12_M_BASEADDR XPAR_ZUPL_XMPU_12_M_AXI_BASEADDR
#define XMPU_PL_12_M_HIGHADDR XPAR_ZUPL_XMPU_12_M_AXI_HIGHADDR
#define XMPU_PL_12_REGIONS_MAX XPAR_ZUPL_XMPU_12_REGIONS_MAX
#else
#define XMPU_PL_12_DEVICE_ID (XPAR_ZUPL_XMPU_NUM_INSTANCES+1)
#define XMPU_PL_12_BASEADDR 0U
#define XMPU_PL_12_M_BASEADDR 0U
#define XMPU_PL_12_M_HIGHADDR 0U
#define XMPU_PL_12_REGIONS_MAX 0U
#endif

#ifdef XPAR_ZUPL_XMPU_13_DEVICE_ID
#define XMPU_PL_13_DEVICE_ID XPAR_ZUPL_XMPU_13_DEVICE_ID
#define XMPU_PL_13_BASEADDR XPAR_ZUPL_XMPU_13_S_AXI_XMPU_BASEADDR
#define XMPU_PL_13_M_BASEADDR XPAR_ZUPL_XMPU_13_M_AXI_BASEADDR
#define XMPU_PL_13_M_HIGHADDR XPAR_ZUPL_XMPU_13_M_AXI_HIGHADDR
#define XMPU_PL_13_REGIONS_MAX XPAR_ZUPL_XMPU_13_REGIONS_MAX
#else
#define XMPU_PL_13_DEVICE_ID (XPAR_ZUPL_XMPU_NUM_INSTANCES+1)
#define XMPU_PL_13_BASEADDR 0U
#define XMPU_PL_13_M_BASEADDR 0U
#define XMPU_PL_13_M_HIGHADDR 0U
#define XMPU_PL_13_REGIONS_MAX 0U
#endif

#ifdef XPAR_ZUPL_XMPU_14_DEVICE_ID
#define XMPU_PL_14_DEVICE_ID XPAR_ZUPL_XMPU_14_DEVICE_ID
#define XMPU_PL_14_BASEADDR XPAR_ZUPL_XMPU_14_S_AXI_XMPU_BASEADDR
#define XMPU_PL_14_M_BASEADDR XPAR_ZUPL_XMPU_14_M_AXI_BASEADDR
#define XMPU_PL_14_M_HIGHADDR XPAR_ZUPL_XMPU_14_M_AXI_HIGHADDR
#define XMPU_PL_14_REGIONS_MAX XPAR_ZUPL_XMPU_14_REGIONS_MAX
#else
#define XMPU_PL_14_DEVICE_ID (XPAR_ZUPL_XMPU_NUM_INSTANCES+1)
#define XMPU_PL_14_BASEADDR 0U
#define XMPU_PL_14_M_BASEADDR 0U
#define XMPU_PL_14_M_HIGHADDR 0U
#define XMPU_PL_14_REGIONS_MAX 0U
#endif

#ifdef XPAR_ZUPL_XMPU_15_DEVICE_ID
#define XMPU_PL_15_DEVICE_ID XPAR_ZUPL_XMPU_15_DEVICE_ID
#define XMPU_PL_15_BASEADDR XPAR_ZUPL_XMPU_15_S_AXI_XMPU_BASEADDR
#define XMPU_PL_15_M_BASEADDR XPAR_ZUPL_XMPU_15_M_AXI_BASEADDR
#define XMPU_PL_15_M_HIGHADDR XPAR_ZUPL_XMPU_15_M_AXI_HIGHADDR
#define XMPU_PL_15_REGIONS_MAX XPAR_ZUPL_XMPU_15_REGIONS_MAX
#else
#define XMPU_PL_15_DEVICE_ID (XPAR_ZUPL_XMPU_NUM_INSTANCES+1)
#define XMPU_PL_15_BASEADDR 0U
#define XMPU_PL_15_M_BASEADDR 0U
#define XMPU_PL_15_M_HIGHADDR 0U
#define XMPU_PL_15_REGIONS_MAX 0U
#endif


#ifdef __cplusplus
}
#endif

#endif /* SRC_ZUPL_XMPU_SINIT_H_ */
/** @} */
