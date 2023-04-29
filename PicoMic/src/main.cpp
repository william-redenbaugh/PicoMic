#include <Arduino.h>
#include "FreeRTOS.h"
#include "task.h"
#include "I2S.h"
#include "event_groups.h"
#include "threads_init.h"

void setup() {
  threads_list_init();
}

void loop() {
  // No need for this loop thread
  vTaskSuspend(NULL);
}