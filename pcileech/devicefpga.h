// devicefpga.h : definitions related to the:
//     - Xilinx SP605 dev board flashed with PCILeech bitstream and FTDI UMFT601X-B addon-board.
//     - Xilinx AC701 dev board flashed with PCILeech bitstream and FTDI UMFT601X-B addon-board.
//     - PCIeScreamer board flashed with PCILeech bitstream.
//
// (c) Ulf Frisk, 2017-2018
// Author: Ulf Frisk, pcileech@frizk.net
//
#ifndef __DEVICEFPGA_H__
#define __DEVICEFPGA_H__
#include "pcileech.h"

/*
* Open a connection to the PCILeech flashed FPGA device.
* -- ctx
* -- result
*/
BOOL DeviceFPGA_Open(_Inout_ PPCILEECH_CONTEXT ctx);

#if defined(LINUX)

#include <stdio.h>
#include <stdint.h>
#include <pthread.h>

// HMODULE isn't necessary because we're not dynamically loading the library
#define HMODULE void*

#define _byteswap_uint64 __builtin_bswap64

/* BOOL and WCHAR are defined in ftd3xx and in oscompatibility
 * so we do some redefining to avoid compilation problems
 */
#define BOOL BOOL_I_DONT_CARE_ABOUT
#define WCHAR WCHAR_I_DONT_CARE_ABOUT
#include <ftd3xx.h>
#undef WCHAR
#undef BOOL

#endif /*  LINUX  */

#endif /* __DEVICEFPGA_H__ */
