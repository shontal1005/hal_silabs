/***************************************************************************//**
 * @file
 * @brief Reset Management Unit (RMU) peripheral API
 *******************************************************************************
 * # License
 * <b>Copyright 2018 Silicon Laboratories Inc. www.silabs.com</b>
 *******************************************************************************
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
 ******************************************************************************/

#ifndef EM_RMU_H
#define EM_RMU_H

#include "em_device.h"
#if (defined(RMU_COUNT) && (RMU_COUNT > 0)) || (_EMU_RSTCTRL_MASK)
#include "sl_assert.h"

#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

/***************************************************************************//**
 * @addtogroup rmu RMU - Reset Management Unit
 * @{
 ******************************************************************************/

/*******************************************************************************
 ********************************   ENUMS   ************************************
 ******************************************************************************/

/** RMU reset modes. */
typedef enum {
#if defined(_RMU_CTRL_PINRMODE_MASK)
  rmuResetModeDisabled = _RMU_CTRL_PINRMODE_DISABLED, /**< Reset mode disabled. */
  rmuResetModeLimited  = _RMU_CTRL_PINRMODE_LIMITED,  /**< Reset mode limited. */
  rmuResetModeExtended = _RMU_CTRL_PINRMODE_EXTENDED, /**< Reset mode extended. */
  rmuResetModeFull     = _RMU_CTRL_PINRMODE_FULL,     /**< Reset mode full. */
#elif defined(_EMU_RSTCTRL_MASK)
  rmuResetModeDisabled = 0, /**< Reset mode disabled. */
  rmuResetModeEnabled  = 1, /**< Reset mode enabled. */
#else
  rmuResetModeClear    = 0, /**< Reset mode clear. */
  rmuResetModeSet      = 1, /**< Reset mode set. */
#endif
} RMU_ResetMode_TypeDef;

/** RMU controlled peripheral reset control and reset source control. */
typedef enum {
#if defined(RMU_CTRL_BURSTEN)
  rmuResetBU = _RMU_CTRL_BURSTEN_MASK,              /**< Reset control over Backup Power domain select. */
#endif
#if defined(RMU_CTRL_LOCKUPRDIS)
  rmuResetLockUp = _RMU_CTRL_LOCKUPRDIS_MASK,       /**< Cortex lockup reset select. */
#elif defined(_RMU_CTRL_LOCKUPRMODE_MASK)
  rmuResetLockUp = _RMU_CTRL_LOCKUPRMODE_MASK,      /**< Cortex lockup reset select. */
#endif
#if defined(_RMU_CTRL_WDOGRMODE_MASK)
  rmuResetWdog = _RMU_CTRL_WDOGRMODE_MASK,          /**< WDOG reset select. */
#endif
#if defined(_RMU_CTRL_LOCKUPRMODE_MASK)
  rmuResetCoreLockup = _RMU_CTRL_LOCKUPRMODE_MASK,  /**< Cortex lockup reset select. */
#endif
#if defined(_RMU_CTRL_SYSRMODE_MASK)
  rmuResetSys = _RMU_CTRL_SYSRMODE_MASK,            /**< SYSRESET select. */
#endif
#if defined(_RMU_CTRL_PINRMODE_MASK)
  rmuResetPin = _RMU_CTRL_PINRMODE_MASK,            /**< Pin reset select. */
#endif

#if defined(_EMU_RSTCTRL_WDOG0RMODE_MASK)
  rmuResetWdog0 = _EMU_RSTCTRL_WDOG0RMODE_MASK,        /**< WDOG0 reset select */
#endif
#if defined(_EMU_RSTCTRL_WDOG1RMODE_MASK)
  rmuResetWdog1 = _EMU_RSTCTRL_WDOG1RMODE_MASK,        /**< WDOG1 reset select */
#endif
#if defined(_EMU_RSTCTRL_SYSRMODE_MASK)
  rmuResetSys = _EMU_RSTCTRL_SYSRMODE_MASK,            /**< SYSRESET select */
#endif
#if defined(_EMU_RSTCTRL_LOCKUPRMODE_MASK)
  rmuResetCoreLockup = _EMU_RSTCTRL_LOCKUPRMODE_MASK,  /**< Cortex lockup reset select */
#endif
#if defined(_EMU_RSTCTRL_AVDDBODRMODE_MASK)
  rmuResetAVDD = _EMU_RSTCTRL_AVDDBODRMODE_MASK,       /**< AVDD monitoring select */
#endif
#if defined(_EMU_RSTCTRL_IOVDD0BODRMODE_MASK)
  rmuResetIOVDD0 = _EMU_RSTCTRL_IOVDD0BODRMODE_MASK,   /**< IOVDD0 monitoring select */
#endif
#if defined(_EMU_RSTCTRL_IOVDD1BODRMODE_MASK)
  rmuResetIOVDD1 = _EMU_RSTCTRL_IOVDD1BODRMODE_MASK,   /**< IOVDD1 monitoring select */
#endif
#if defined(_EMU_RSTCTRL_IOVDD2BODRMODE_MASK)
  rmuResetIOVDD2 = _EMU_RSTCTRL_IOVDD2BODRMODE_MASK,   /**< IOVDD2 monitoring select */
#endif
#if defined(_EMU_RSTCTRL_DECBODRMODE_MASK)
  rmuResetDecouple = _EMU_RSTCTRL_DECBODRMODE_MASK,    /**< Decouple monitoring select */
#endif
#if defined(_EMU_RSTCTRL_SESYSRMODE_MASK)
  rmuResetSESys = _EMU_RSTCTRL_SESYSRMODE_MASK,        /**< M0+ (SE) system reset select */
#endif
#if defined(_EMU_RSTCTRL_SELOCKUPRMODE_MASK)
  rmuResetSELockup = _EMU_RSTCTRL_SELOCKUPRMODE_MASK,  /**< M0+ (SE) lockup select */
#endif
#if defined(_EMU_RSTCTRL_DCIRMODE_MASK)
  rmuResetDCI = _EMU_RSTCTRL_DCIRMODE_MASK,            /**< DCI reset select */
#endif
} RMU_Reset_TypeDef;

/*******************************************************************************
 *****************************   PROTOTYPES   **********************************
 ******************************************************************************/

/** RMU_LockupResetDisable kept for backwards compatibility. */
#define RMU_LockupResetDisable(A) RMU_ResetControl(rmuResetLockUp, A)

void RMU_ResetControl(RMU_Reset_TypeDef reset, RMU_ResetMode_TypeDef mode);
void RMU_ResetCauseClear(void);
uint32_t RMU_ResetCauseGet(void);

#if defined(_RMU_CTRL_RESETSTATE_MASK)
/***************************************************************************//**
 * @brief
 *   Set user reset state. Reset only by a Power-on-reset and a pin reset.
 *
 * @param[in] userState User state to set
 ******************************************************************************/
__STATIC_INLINE void RMU_UserResetStateSet(uint32_t userState)
{
  EFM_ASSERT(!(userState
               & ~(_RMU_CTRL_RESETSTATE_MASK >> _RMU_CTRL_RESETSTATE_SHIFT)));
  RMU->CTRL = (RMU->CTRL & ~_RMU_CTRL_RESETSTATE_MASK)
              | (userState << _RMU_CTRL_RESETSTATE_SHIFT);
}

/***************************************************************************//**
 * @brief
 *   Get user reset state. Reset only by a Power-on-reset and a pin reset.
 *
 * @return
 *   Reset surviving user state.
 ******************************************************************************/
__STATIC_INLINE uint32_t RMU_UserResetStateGet(void)
{
  uint32_t userState = (RMU->CTRL & _RMU_CTRL_RESETSTATE_MASK)
                       >> _RMU_CTRL_RESETSTATE_SHIFT;
  return userState;
}
#endif

/** @} (end addtogroup rmu) */

#ifdef __cplusplus
}
#endif

#endif /* defined(RMU_COUNT) && (RMU_COUNT > 0) */
#endif /* EM_RMU_H */
