#ifndef _THREAD_MODULES_H
#define _THREAD_MODULES_H

/**
 * @brief I2S Thread Initialization
*/
void i2s_thread_init_mod(void *params);

/**
 * @brief I2S Thread target function
*/
void i2s_thread_mod(void *params);

/**
 * @brief USB Serial Thread Intialization
*/
void usb_thread_init_mod(void *params);

/**
 * @brief USB Serial Thread target function
*/
void usb_thread_mod(void *params);

/**
 * @brief testing thread initialization
*/
void testing_thread_init_mod(void *params);

/**
 * @brief Testing thread target initialization
*/
void testing_thread_mod(void *params);

#endif