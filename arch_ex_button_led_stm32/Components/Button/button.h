/******************************************************************************
 * @file   button.h
 * @brief  Description of the button component interface.
 * @author Rodrigo D. Pechoneri.
 *****************************************************************************/

#ifndef BUTTON_H
#define BUTTON_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdbool.h>

#include "digital_io_adapter.h"

/**
 * @defgroup ButtonGroup Button Component
 * @brief Functions and structures related to buttons.
 * @{
 */

/**
 * @brief Maximum number of buttons supported.
 * @details In this macro you put the number of buttons present
 * in your hardware board
 */
#define BUTTON_MAX_NUMBER (2)

/**
 * @brief Structure definition to represent a button.
 */
typedef struct {
    digital_io_t button_io;          /**< Reference to the digital_io object */
    digital_io_state_t button_state; /**< Current state of the button */
    uint32_t id;                     /**< Button identifier */
} button_t;

/**
 * @brief Initializes a button.
 * @param p_button Pointer to the button structure.
 * @return return_success or a specific error code.
 */
return_codes_t button_initialize(button_t *p_button);

/**
 * @brief Checks if the button is pressed.
 * @param p_button Pointer to the button structure.
 * @return true if the button is pressed, false otherwise.
 */
bool button_is_pressed(button_t *p_button);

/** @} */

#ifdef __cplusplus
}
#endif

#endif /* BUTTON_H */

/*** end of file ***/
