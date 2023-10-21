// nucleus/timers.c
#include <stdint.h>
#include "common.h"

volatile uint64_t timer_ticks = 0;

void timer_handler() {
    // Timer interrupt handler.
    // Increment timer ticks and perform periodic tasks.
    timer_ticks++;
}
