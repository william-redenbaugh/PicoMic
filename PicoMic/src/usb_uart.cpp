#include <Arduino.h>
#include "thread_modules.h"
#include "os_thread.h"

/**
 * @brief USB Serial Thread Intialization
*/
void usb_thread_init_mod(void *params){
    Serial.begin(115200);
}

/**
 * @brief USB Serial Thread target function
*/
void usb_thread_mod(void *params){

    for(;;){
        Serial.println("Hello world");
        os_thread_sleep_s(1);
    }
}