/******************************************************************************
 * @file   : led.c
 * @brief  : Implementation of the LED component interface.
 * @author : Rodrigo D. Pechoneri
 *****************************************************************************/

#include "led.h"

/**
 * @details This function initializes the LED by configuring its digital I/O pin.
 * and the initial state of th LED component
 */
return_codes_t led_initialize(led_t *p_led) {
    p_led->led_io.type = digital_output;
    return digital_io_initialize(&p_led->led_io, p_led->led_state);
}

/**
 * @note See header led.h for reference.
 */
return_codes_t led_turn_on(led_t *p_led) {
    p_led->led_state = digital_io_high;
    return digital_io_write(&p_led->led_io, p_led->led_state);
}

/**
 * @note See header led.h for reference.
 */
return_codes_t led_turn_off(led_t *p_led) {
    p_led->led_state = digital_io_low;
    return digital_io_write(&p_led->led_io, p_led->led_state);
}

/**
 * @note See header led.h for reference.
 */
return_codes_t led_toggle(led_t *p_led) {
    p_led->led_state = (p_led->led_state == digital_io_high) ? digital_io_low : digital_io_high;
    return digital_io_write(&p_led->led_io, p_led->led_state);
}

/**
 * @details This Function initializes the LED controller by assigning function pointers
 * to control the LED operations.
 */
return_codes_t led_controller_initialize(led_controller_t *p_controller) {
    p_controller->turn_on = led_turn_on;
    p_controller->turn_off = led_turn_off;
    p_controller->toggle = led_toggle;
    return return_success;
}

/*** end of file ***/
