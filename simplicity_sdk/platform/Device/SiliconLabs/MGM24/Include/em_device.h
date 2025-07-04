/**************************************************************************//**
 * @file
 * @brief CMSIS Cortex-M Peripheral Access Layer for Silicon Laboratories
 *        microcontroller devices
 *
 * This is a convenience header file for defining the part number on the
 * build command line, instead of specifying the part specific header file.
 *
 * @verbatim
 * Example: Add "-DEFM32G890F128" to your build options, to define part
 *          Add "#include "em_device.h" to your source files

 *
 * @endverbatim
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

#ifndef EM_DEVICE_H
#define EM_DEVICE_H
#if defined(MGM240L022RNF)
#include "mgm240l022rnf.h"

#elif defined(MGM240L022VIF)
#include "mgm240l022vif.h"

#elif defined(MGM240L022VNF)
#include "mgm240l022vnf.h"

#elif defined(MGM240LA22UIF)
#include "mgm240la22uif.h"

#elif defined(MGM240LA22VIF)
#include "mgm240la22vif.h"

#elif defined(MGM240LD22VIF)
#include "mgm240ld22vif.h"

#elif defined(MGM240PA22VNA)
#include "mgm240pa22vna.h"

#elif defined(MGM240PA32VNA)
#include "mgm240pa32vna.h"

#elif defined(MGM240PA32VNN)
#include "mgm240pa32vnn.h"

#elif defined(MGM240PB22VNA)
#include "mgm240pb22vna.h"

#elif defined(MGM240PB32VNA)
#include "mgm240pb32vna.h"

#elif defined(MGM240PB32VNN)
#include "mgm240pb32vnn.h"

#elif defined(MGM240SA22VNA)
#include "mgm240sa22vna.h"

#elif defined(MGM240SB22VNA)
#include "mgm240sb22vna.h"

#elif defined(MGM240SD22VNA)
#include "mgm240sd22vna.h"

#else
#error "em_device.h: PART NUMBER undefined"
#endif

#if defined(SL_CATALOG_TRUSTZONE_SECURE_CONFIG_PRESENT) && defined(SL_TRUSTZONE_NONSECURE)
#error "Can't define SL_CATALOG_TRUSTZONE_SECURE_CONFIG_PRESENT and SL_TRUSTZONE_NONSECURE MACRO at the same time."
#endif

#if defined(SL_TRUSTZONE_SECURE) && defined(SL_TRUSTZONE_NONSECURE)
#error "Can't define SL_TRUSTZONE_SECURE and SL_TRUSTZONE_NONSECURE MACRO at the same time."
#endif
#endif /* EM_DEVICE_H */
