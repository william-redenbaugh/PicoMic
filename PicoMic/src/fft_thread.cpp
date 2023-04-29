#include "Arduino.h"
#include "thread_modules.h"
#include "fixed_point_fft.h"
#include "stdint.h"
#include "os_mutx.h"
#include "os_setbits.h"
#include "os_thread.h"

#define NUM_SAMPLES_POWER_2 10
#define NUM_SAMPLES 2 ^ NUM_SAMPLES_POWER_2
int16_t buffer[NUM_SAMPLES];

os_mut_t fft_mutx;

int copy_fft_data(int16_t *data, size_t size){
    if(size < NUM_SAMPLES){
        return OS_RET_INVALID_PARAM;
    }
    os_mut_entry_wait_indefinite(&fft_mutx);

    os_mut_exit(&fft_mutx);
}

void fft_thread_init(void *params){
    os_mut_init(&fft_mutx);
}

void fft_thread(void *params){
    for(;;){
        os_mut_entry_wait_indefinite(&fft_mutx);
        fix_fftr(buffer, NUM_SAMPLES_POWER_2, 0);

        Serial.println(buffer[0]);
        os_mut_exit(&fft_mutx);

        os_thread_sleep_ms(10); 
    }    
}