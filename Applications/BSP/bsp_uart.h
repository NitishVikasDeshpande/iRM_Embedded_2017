/**
 * @author  Nickel_Liang <nickelliang>
 * @date    2018-04-16
 * @file    bsp_uart.h
 * @brief   Board support package for uart device
 * @log     2018-04-17 nickelliang
 */

#ifndef _BSP_UART_H_
#define _BSP_UART_H_

#include "bsp_config.h"
#include "usart.h"
#include "dma.h"
#include "bsp_error_handler.h"
#include "stm32f4xx_hal.h"
#include "cmsis_os.h"

/**
 * @ingroup bsp
 * @defgroup bsp_uart BSP UART
 * @{
 */

/**
 * Start DMA transfer with interrupt disabled
 *
 * @param  huart      Which uart to set
 * @param  pData      Data stream buffer
 * @param  size       size of data
 * @return            0 for fail, 1 for success
 * @author Nickel_Liang
 * @date   2018-04-17
 * @note   Reference from HAL_UART_Receive_DMA
 */
uint8_t uart_rx_dma_without_it(UART_HandleTypeDef* huart, uint8_t* pData, uint32_t size);

/**
 * Initialize a UART port with IDLE interrupt
 *
 * @param  huart      UART port to be initialize
 * @author Nickel_Liang
 * @date   2018-04-18
 */
void uart_port_init(UART_HandleTypeDef* huart);

/**
 * Count how many data remain in DMA buffer
 *
 * @param  dma_stream Which DMA stream to count
 * @return            Number of bytes remain in DMA buffer
 * @author Nickel_Liang
 * @date   2018-04-17
 * @source https://blog.frankvh.com/2011/08/18/stm32f2xx-dma-controllers/
 */
uint16_t dma_current_data_counter(DMA_Stream_TypeDef *dma_stream);

/**
 * This is a weak function. Implement this function in dbus library.
 *
 * @author Nickel_Liang
 * @date   2018-04-18
 */
void uart_dbus_callback(void);

/** @} */

#endif
