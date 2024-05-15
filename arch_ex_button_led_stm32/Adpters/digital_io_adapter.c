/******************************************************************************
 * @file   : digital_io_adapter.c
 * @brief  : Implementation of Digital IO Peripheral interface.
 * @author : Rodrigo D. Pechoneri
 *****************************************************************************/
#include "digital_io_adapter.h"
#include "stm32f1xx_hal.h"
#include <stddef.h>

/**
 * @note See full documentation in module's header file.
 */
return_codes_t digital_io_initialize(p_digital_io_t dio, digital_io_state_t initial_state)
{
    if (NULL == dio)
    {
        return (return_invalid_input);
    }
    else
    {
        GPIO_InitTypeDef GPIO_InitStruct = { 0 };

        if(dio->type == digital_output)
        {
            /* GPIO init configuration structure */
            GPIO_InitStruct.Pin = dio->pin;
            GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
            GPIO_InitStruct.Pull = GPIO_NOPULL;
            GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
            HAL_GPIO_Init(dio->port, &GPIO_InitStruct);
            /* GPIO output initial state */
            if(initial_state == digital_io_low)
            {
                HAL_GPIO_WritePin(dio->port, dio->pin, digital_io_low);
            }
            else if(initial_state == digital_io_high)
            {
                HAL_GPIO_WritePin(dio->port, dio->pin, digital_io_high);
            }
        }
        else if(dio->type == digital_input)
        {
            GPIO_InitStruct.Pin = dio->pin;
            GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
            GPIO_InitStruct.Pull = GPIO_NOPULL;
            HAL_GPIO_Init(dio->port, &GPIO_InitStruct);
        }
        else
        {
        	return (return_error);
        }
    }

    return (return_success);
}

/**
 * @note See full documentation in module's header file.
 */
return_codes_t digital_io_deinitialize(p_digital_io_t dio)
{
    if (NULL == dio)
    {
        return (return_invalid_input);
    }
    else
    {
    	HAL_GPIO_DeInit(dio->port, dio->pin);
    }
    return (return_success);
}

/**
 * @note See full documentation in module's header file.
 */
return_codes_t digital_io_write(p_digital_io_t dio, digital_io_state_t state)
{
    if ((NULL == dio) || (dio->type != digital_output))
    {
        return (return_invalid_input);
    }
    else
    {
    	HAL_GPIO_WritePin(dio->port, dio->pin, state);
    }

    return (return_success);
}

/**
 * @note See full documentation in module's header file.
 */
return_codes_t digital_io_read(p_digital_io_t dio, digital_io_state_t *p_state)
{
    if (NULL == dio)
    {
        return (return_invalid_input);
    }
    else
    {
    	GPIO_PinState state = HAL_GPIO_ReadPin(dio->port, dio->pin);
        *p_state = (state == GPIO_PIN_RESET) ? digital_io_low : digital_io_high;
    }

    return (return_success);
}

/**
 * @note See full documentation in module's header file.
 */
return_codes_t digital_io_toggle(p_digital_io_t dio)
{
    if (NULL == dio)
    {
        return (return_invalid_input);
    }
    else
    {
    	HAL_GPIO_TogglePin(dio->port, dio->pin);
    }

    return (return_success);
}

/*** end of file ***/
