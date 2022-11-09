/*
 * main.c - application entry point
 * 
 * Author Howdy Pierce, howdy.pierce@colorado.edu
 */

#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>

#include "cbfifo.h"
#include "sysclock.h"
#include "test_cbfifo.h"


int main(void)
{
  sysclock_init();

  // TODO: initialize the UART here


  // enter infinite loop
  while (1) {
    __asm volatile ("nop");
  }

  return 0 ;
}
