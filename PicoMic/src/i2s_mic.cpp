#include "threads_init.h"

/**
 * @brief I2S Thread Initialization
*/
void i2s_thread_init_mod(void *params){

}

/**
 * @brief I2S Thread target function
*/
void i2s_thread_mod(void *params){
    for(;;){
        os_thread_sleep_s(1);   
    }
}