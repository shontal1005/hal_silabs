/**************************************************************************//**
 * @file
 * @brief EFR32MG21 DMA descriptor bit field definitions
 ******************************************************************************
 * # License
 * <b>Copyright 2025 Silicon Laboratories, Inc. www.silabs.com</b>
 ******************************************************************************
 *
 * SPDX-License-Identifier: Zlib
 *
 * The licensor of this software is Silicon Laboratories Inc.
 *
 * This software is provided 'as-is', without any express or implied
 * warranty. In no event will the authors be held liable for any damages
 * arising from the use of this software.
 *
 * Permission is granted to anyone to use this software for any purpose,
 * including commercial applications, and to alter it and redistribute it
 * freely, subject to the following restrictions:
 *
 * 1. The origin of this software must not be misrepresented; you must not
 *    claim that you wrote the original software. If you use this software
 *    in a product, an acknowledgment in the product documentation would be
 *    appreciated but is not required.
 * 2. Altered source versions must be plainly marked as such, and must not be
 *    misrepresented as being the original software.
 * 3. This notice may not be removed or altered from any source distribution.
 *
 *****************************************************************************/
#ifndef EFR32MG21_DMA_DESCRIPTOR_H
#define EFR32MG21_DMA_DESCRIPTOR_H

#if defined(__ICCARM__)
#pragma system_include       /* Treat file as system include file. */
#elif defined(__ARMCC_VERSION) && (__ARMCC_VERSION >= 6010050)
#pragma clang system_header  /* Treat file as system include file. */
#endif

/**************************************************************************//**
* @addtogroup Parts
* @{
******************************************************************************/
/**************************************************************************//**
 * @defgroup DMA_DESCRIPTOR DMA Descriptor
 * @{
 *****************************************************************************/
/** DMA_DESCRIPTOR Register Declaration */
typedef struct {
  /* Note! Use of double __IOM (volatile) qualifier to ensure that both */
  /* pointer and referenced memory are declared volatile. */
  __IOM uint32_t     CTRL;     /**< DMA control register */
  __IOM void * __IOM SRC;      /**< DMA source address */
  __IOM void * __IOM DST;      /**< DMA destination address */
  __IOM void * __IOM LINK;     /**< DMA link address */
} DMA_DESCRIPTOR_TypeDef;      /**< @} */

/** @} End of group Parts */

#endif // EFR32MG21_DMA_DESCRIPTOR_H
