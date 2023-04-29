#include "thread_modules.h"
#include "threads_init.h"

#define I2S_MIC_STACK_SIZE 256
#define USB_SERIAL_STACK_SIZE 256
#define TEST_THREAD_STACK_SIZE 256
#define FFT_THREAD_STACK_SIZE 2048

task_init_descriptor_t THREAD_LIST[] =                                                                                          \
    {                                                                                                                           \
        {.task_fun = i2s_thread_mod, .task_init_fun =  i2s_thread_init_mod, .task_name =  "I2S Thread", .stack_size =  I2S_MIC_STACK_SIZE, .stack = NULL, 1, NULL, NULL},                  \
        {.task_fun = usb_thread_mod, .task_init_fun =  usb_thread_init_mod, .task_name = "USB Serial Thread", .stack_size =  USB_SERIAL_STACK_SIZE, .stack = NULL, 1, NULL, NULL},     \
        {.task_fun = testing_thread_mod, .task_init_fun =  testing_thread_init_mod, .task_name = "test thread", .stack_size =  TEST_THREAD_STACK_SIZE, .stack = NULL, 1, NULL, NULL},     \
        {.task_fun = fft_thread, .task_init_fun =  fft_thread_init, .task_name = "FFT Thread", .stack_size =  FFT_THREAD_STACK_SIZE, .stack = NULL, 1, NULL, NULL}     \
        
    };

int NUM_THREADS  = sizeof(THREAD_LIST)/sizeof(task_init_descriptor_t);