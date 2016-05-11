#include <stdio.h>
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include "lcd.h"
#include "printf.h"
#include "pokemon.h"
#include "ruota.h"

#define STEP_DELAY_MS 5
#define MIN_STEP    2    /* > 0 */
#define MAX_STEP  255

void init(void);

