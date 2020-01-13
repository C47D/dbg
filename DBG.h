/*
 * DBG.h
 *
 *  Created on: 08/08/2018
 *      Author: Ingenieria6
 */

#ifndef DBG_H_
#define DBG_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include <stddef.h>
#include <stdarg.h>
#include "main.h"
#include "usart.h"

#define DEBUG_ENABLE 			1

#define AVL_DBG_UART_HANDLE		huart1
#define AVL_DBG_UART_INSTANCE	UART1



#define DBG_UART_PORT	AVL_DBG_UART_HANDLE

#define BOOL_PARAM(param)	(param ? '1' : '0')


/*
 * Codigo para medir tiempo de ejecución
 */
/* DWT (Data Watchpoint and Trace) registers, only exists on ARM Cortex with a DWT unit */
#define KIN1_DWT_CONTROL             (*((volatile uint32_t*)0xE0001000))
  /*!< DWT Control register */
#define KIN1_DWT_CYCCNTENA_BIT       (1UL<<0)
  /*!< CYCCNTENA bit in DWT_CONTROL register */
#define KIN1_DWT_CYCCNT              (*((volatile uint32_t*)0xE0001004))
  /*!< DWT Cycle Counter register */
#define KIN1_DEMCR                   (*((volatile uint32_t*)0xE000EDFC))
  /*!< DEMCR: Debug Exception and Monitor Control Register */
#define KIN1_TRCENA_BIT              (1UL<<24)
  /*!< Trace enable bit in DEMCR register */

#define KIN1_InitCycleCounter() \
  KIN1_DEMCR |= KIN1_TRCENA_BIT
  /*!< TRCENA: Enable trace and debug block DEMCR (Debug Exception and Monitor Control Register */

#define KIN1_ResetCycleCounter() \
  KIN1_DWT_CYCCNT = 0
  /*!< Reset cycle counter */

#define KIN1_EnableCycleCounter() \
  KIN1_DWT_CONTROL |= KIN1_DWT_CYCCNTENA_BIT
  /*!< Enable cycle counter */

#define KIN1_DisableCycleCounter() \
  KIN1_DWT_CONTROL &= ~KIN1_DWT_CYCCNTENA_BIT
  /*!< Disable cycle counter */

#define KIN1_GetCycleCounter() \
  KIN1_DWT_CYCCNT
  /*!< Read cycle counter register */

void DBG_init(void);
void DBG_clear_screen(void);
void DBG_println(const char *fmt, ...);
void DBG_hexdump(uint8_t *buff, size_t len, size_t base);

#ifdef __cplusplus
}
#endif

#endif /* DBG_H_ */
