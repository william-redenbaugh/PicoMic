#include "I2S.h"
#include "threads_init.h"
#include "fft_module.h"

#define NUM_SAMPLES 1024

I2S i2s(INPUT);
int16_t samples[NUM_SAMPLES];

/**
 * @brief I2S Thread Initialization
*/
void i2s_thread_init_mod(void *params){
    i2s.setDATA(0);
    i2s.setBCLK(1); // Note: LRCLK = BCLK + 1
    i2s.setBitsPerSample(32);
    i2s.setFrequency(16000);
    i2s.begin();
}

/**
 * @brief I2S Thread target function
*/
void i2s_thread_mod(void *params){
    for(;;){
        int num_data_received = 0;

        while(num_data_received < 512){
            for(int i = 0; i < i2s.available(); i++){
                int32_t l, r;
                samples[i] = l / INT16_MAX;
                i2s.read32(&l, &r);
                num_data_received++;
            }
            os_thread_sleep_ms(1);
        }

        copy_fft_data(samples, NUM_SAMPLES);
        os_thread_sleep_ms(10); 
    }
}