/******************************************************************************
 * @file   : led.h
 * @brief  : Description of the LED component interface.
 * @author : Rodrigo D. Pechoneri
 *****************************************************************************/

#ifndef LED_COMPONENT_H
#define LED_COMPONENT_H

#ifdef __cplusplus
extern "C" {
#endif

#include "digital_io_adapter.h"

/**
 * @brief Enumeration for LED data type.
 */
typedef enum led_data_type {
    led_off = digital_io_low, /**< LED is off */
    led_on = digital_io_high  /**< LED is on */
} led_data_t;

/**
 * @brief Structure to represent the LED.
 */
typedef struct led_type {
    digital_io_t       led_io;    /**< Reference to the digital_io_t object */
    digital_io_state_t led_state; /**< Current state of the LED */
} led_t;

/**
 * @brief Turns the LED on.
 *
 * @param p_led Pointer to the LED object.
 * @return Return code indicating the status of the operation.
 *         Possible return codes:
 *         - return_success: LED turned on successfully.
 *         - Specific error codes for failure cases.
 */
return_codes_t led_turn_on(led_t *p_led);

/**
 * @brief Turns the LED off.
 *
 * @param p_led Pointer to the LED object.
 * @return Return code indicating the status of the operation.
 *         Possible return codes:
 *         - return_success: LED turned off successfully.
 *         - Specific error codes for failure cases.
 */
return_codes_t led_turn_off(led_t *p_led);

/**
 * @brief Toggles the state of the LED.
 *
 * @param p_led Pointer to the LED object.
 * @return Return code indicating the status of the operation.
 *         Possible return codes:
 *         - return_success: LED state toggled successfully.
 *         - Specific error codes for failure cases.
 */
return_codes_t led_toggle(led_t *p_led);

/**
 * @brief Function pointer type for LED control.
 */
typedef return_codes_t (*led_handler_t)(led_t *p_led);

/**
 * @brief Structure for LED controller.
 * This structure wraps the LED behavior 
 * using specific functions to implement led actions
 */
typedef struct {
    led_handler_t turn_on;  /**< Pointer to function to turn the LED on */
    led_handler_t turn_off; /**< Pointer to function to turn the LED off */
    led_handler_t toggle;   /**< Pointer to function to toggle the LED */
} led_controller_t;

/**
 * @brief Initializes the LED object.
 *
 * @param p_led Pointer to the LED object.
 * @return Return code indicating the status of the initialization.
 *         Possible return codes:
 *         - return_success: LED object initialized successfully.
 *         - Specific error codes for failure cases.
 */
return_codes_t led_initialize(led_t *p_led);

/**
 * @brief Initializes the LED controller.
 *
 * @param p_controller Pointer to the LED controller object.
 * @return Return code indicating the status of the initialization.
 *         Possible return codes:
 *         - return_success: LED controller initialized successfully.
 *         - Specific error codes for failure cases.
 */
return_codes_t led_controller_initialize(led_controller_t *p_controller);

#ifdef __cplusplus
}
#endif

#endif /* LED_COMPONENT_H */

/*** end of file ***/
