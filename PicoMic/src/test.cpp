#include "thread_modules.h"
#include "os_thread.h"
/**
 * @brief testing thread initialization
*/
void testing_thread_init_mod(void *params){

}

/**
 * @brief Testing thread target initialization
*/
void testing_thread_mod(void *params){

    for(;;){
        os_thread_sleep_s(1);
    }
}