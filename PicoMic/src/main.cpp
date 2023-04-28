#include <Arduino.h>
#include "FreeRTOS.h"
#include "task.h"
#include "I2S.h"
#include "event_groups.h"
#include "os_thread.h"
#include "threads_init.h"

I2S i2s(INPUT);

#define BIT_0	( 1 << 0 )
#define BIT_4	( 1 << 4 )

EventGroupHandle_t xEventGroup;

void setup() {
  /*
  xEventGroup = xEventGroupCreate();

  Serial.begin(115200);
  i2s.setDATA(0);
  i2s.setBCLK(1); // Note: LRCLK = BCLK + 1
  i2s.setBitsPerSample(32);
  i2s.setFrequency(8000);
  i2s.begin();
  i2s.onReceive(on_receive_buffer);
  */

  threads_list_init();
}

void loop() {
  // No need for this loop thread
  vTaskSuspend(NULL);
}