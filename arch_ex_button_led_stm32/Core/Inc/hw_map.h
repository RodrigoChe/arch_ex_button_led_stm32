/**
 * @file   hw_map.h
 * @brief  Hardware pins and peripheral map for ESP32 devkit v1 board.
 * @author Rodrigo D. Pechoneri
 */

#ifndef HW_MAP
#define HW_MAP

/**
 * @defgroup HW_MAP Hardware Pin and Peripheral Map
 * @{
 */

/* Digital Outputs */

/**
 * @brief Pin number for the green LED.
 */
#define LED_GREEN_PIN   (GPIO_PIN_9)
/**
 * @brief Port number for the green LED.
 */
#define LED_GREEN_PORT  (GPIOA)

/**
 * @brief Pin number for the yellow LED.
 */
#define LED_YELLOW_PIN     (GPIO_PIN_8)
/**
 * @brief Port number for the yellow LED.
 */
#define LED_YELLOW_PORT    (GPIOA)

/* Digital Inputs */

/**
 * @brief Pin number for the first button.
 */
#define BUTTON_1_PIN    (GPIO_PIN_9)
/**
 * @brief Port number for the first button.
 */
#define BUTTON_1_PORT   (GPIOB)

/**
 * @brief Pin number for the second button.
 */
#define BUTTON_2_PIN    (GPIO_PIN_7)
/**
 * @brief Port number for the second button.
 */
#define BUTTON_2_PORT    (GPIOB)

/* @} */

#endif /* HW_MAP */
