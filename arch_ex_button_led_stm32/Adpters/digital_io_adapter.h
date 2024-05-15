/******************************************************************************
* @file   : digital_io_adapter.h
* @brief  : Description of Digital IO peripheral interface.
* @author : Rodrigo D. Pechoneri.
*****************************************************************************/

#ifndef DIGITAL_IO_ADAPTER_H
#define DIGITAL_IO_ADAPTER_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

/**
 * @brief Pointer to a variant type.
 */
typedef void*          variant_t;

/**
 * @brief Type definition for pin number.
 */
typedef uint8_t        pin_t;

/**
 * @brief Type definition for port.
 */
typedef variant_t      port_t;

/**
 * @brief Enumeration for digital output states.
 */
typedef enum {
    digital_io_low  = 0U, /**< Digital I/O low state */
    digital_io_high = 1U  /**< Digital I/O high state */
} digital_io_state_t;

/**
 * @brief Enumeration for digital I/O types.
 */
typedef enum {
    digital_input,  /**< Digital input */
    digital_output  /**< Digital output */
} digital_io_type_t;

/**
 * @brief Structure to represent a digital I/O pin.
 */
typedef struct digital_io {
    port_t            port;   /**< Pointer to the port */
    pin_t             pin;    /**< Pin number */
    digital_io_type_t type;   /**< Type of digital I/O pin (input/output) */
} digital_io_t, *p_digital_io_t;

/**
 * @brief Return codes for digital I/O operations.
 */
typedef enum {
    return_success      = 0, /**< Operation successful */
    return_error        = 1, /**< Error occurred */
    return_invalid_input = 2 /**< Invalid input */
} return_codes_t;

/**
 * @defgroup DigitalIOGroup Digital I/O Functions
 * @brief Functions for digital I/O operations.
 * @{
 */

/**
 * @brief Initializes the digital I/O pin.
 *
 * This function initializes the specified digital I/O pin with the given initial state.
 *
 * @param dio           Pointer to the digital I/O structure.
 * @param initial_state Default output value.
 * @return return_success or a specific error code.
 */
return_codes_t digital_io_initialize(p_digital_io_t dio, digital_io_state_t initial_state);

/**
 * @brief Deinitializes the digital I/O pin.
 *
 * This function deinitializes the specified digital I/O pin.
 *
 * @param dio  Pointer to the digital I/O structure.
 * @return return_success or a specific error code.
 */
return_codes_t digital_io_deinitialize(p_digital_io_t dio);

/**
 * @brief Writes to the digital output.
 *
 * This function writes the specified state to the digital output.
 *
 * @param dio    Pointer to the digital I/O structure.
 * @param state  State to be written.
 * @return return_success or a specific error code.
 */
return_codes_t digital_io_write(p_digital_io_t dio, digital_io_state_t state);

/**
 * @brief Reads the state of the digital output.
 *
 * This function reads the current state of the digital output.
 *
 * @param dio    Pointer to the digital I/O structure.
 * @param state  Pointer where the current output state will be saved.
 * @return return_success or a specific error code.
 */
return_codes_t digital_io_read(p_digital_io_t dio, digital_io_state_t* p_state);

/**
 * @brief Toggles the output state.
 *
 * This function toggles the output state of the digital I/O pin.
 *
 * @param dio    Pointer to the digital I/O structure.
 * @return return_success or a specific error code.
 */
return_codes_t digital_io_toggle(p_digital_io_t dio);

/** @} */

#ifdef __cplusplus
}
#endif

#endif /* DIGITAL_IO_ADAPTER_H */

/*** end of file ***/
