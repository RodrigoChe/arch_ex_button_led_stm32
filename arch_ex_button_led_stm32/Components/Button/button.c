/**
 * @file   button.c
 * @brief  Implementation of the button component interface.
 * @author Rodrigo D. Pechoneri
 */

#include <stdint.h>

#include "button.h"

#define BOUNCE_COUNT (4)

static uint32_t g_idsForButtons = 0;

/**
 * @brief Counter for bounce detection per button.
 */
static uint8_t g_counting_bounces_per_button[BUTTON_MAX_NUMBER];

/**
 * @brief Current state of each button.
 */
static digital_io_state_t g_button_current_state[BUTTON_MAX_NUMBER] = 
{
    digital_io_high, 
    digital_io_high
};

/**
 * @details This function initializes the specified button by configuring its digital I/O pin.
 */
return_codes_t button_initialize(button_t *p_button) {
    p_button->button_io.type = digital_input;
    p_button->button_state = digital_io_low;
    p_button->id = g_idsForButtons++;
    return (digital_io_initialize(&p_button->button_io, p_button->button_state));
}

/**
 * @details This function checks the current state of the specified button.
 */
bool button_is_pressed(button_t *p_button) {
    bool result = false;

    digital_io_read(&p_button->button_io, &p_button->button_state);

    if (p_button->button_state != g_button_current_state[p_button->id]) 
    {
        g_counting_bounces_per_button[p_button->id]++;
        if (g_counting_bounces_per_button[p_button->id] >= BOUNCE_COUNT) 
        {
            if (g_button_current_state[p_button->id] == digital_io_low) 
            {
                g_button_current_state[p_button->id] = digital_io_high;
                result = true;
            } 
            else 
            {
                g_button_current_state[p_button->id] = digital_io_low;
                result = false;
            }
        }
    } 
    else 
    {
        g_counting_bounces_per_button[p_button->id] = 0;
    }

    return (result);
}
