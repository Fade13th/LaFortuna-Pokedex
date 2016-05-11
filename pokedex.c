/* COMP2215 15/16: Task 02---MODELANSWER */

#include "pokedex.h"

#define PKMN_NO 9
#define SPRITE_SIZE 64 
#define BG_COLOUR WHITE_SMOKE
#define FG_COLOUR BLACK

struct Pokemon *pkmn;

int8_t detail;

int8_t selected;
int8_t enc_delta(void);
volatile int8_t delta;

void format_string(char *fmt, va_list args, char *formatted_string);

void drawBorder(void) {
	rectangle r = {6, display.width-7, 6, 12};
	fill_rectangle(r, FG_COLOUR);
	rectangle r2 = {6, display.width-7, display.height-13, display.height-7};
	fill_rectangle(r2, FG_COLOUR);
	rectangle r3 = {display.width-13, display.width-7, 6, display.height-7};
	fill_rectangle(r3, FG_COLOUR);
	rectangle r4 = {6, 12, 6, display.height-7};
	fill_rectangle(r4, FG_COLOUR);
}

void printx(char *string, ...) {
	printf("   ");
	printf(string);
	
	va_list args;
	va_start(args, string);
	vprintf(string, args);
	va_end(args);
}

void drawSprite(char *a) {
	printf("\n\n   ");
	
	display_color(BG_COLOUR, FG_COLOUR);
	printf("            \n");

	display_color(FG_COLOUR, BG_COLOUR);
	printf("   ");
	display_color(BG_COLOUR, FG_COLOUR);
	printf(" ");
	display_color(FG_COLOUR, WHITE);
	printf("          ");
	display_color(BG_COLOUR, FG_COLOUR);
	printf(" \n");

	int i;	
	int8_t x;
	
	display_color(FG_COLOUR, BG_COLOUR);
	printf("   ");

	display_color(BG_COLOUR, FG_COLOUR);
	printf(" ");
	display_color(FG_COLOUR, WHITE);
	printf(" ");

	x = 0;
	for (i = 0; i < SPRITE_SIZE; i++) {
		if (x >= 8) {
			display_color(FG_COLOUR, WHITE);
			printf(" ");
			display_color(BG_COLOUR, FG_COLOUR);
			printf(" ");

			display_color(FG_COLOUR, BG_COLOUR);
			printf("\n   ");

			display_color(BG_COLOUR, FG_COLOUR);
			printf(" ");
			display_color(FG_COLOUR, WHITE);
			printf(" ");
			x = 0;
		}	
		char tmp = a[i];
		switch(tmp) {
			case 'W' : display_color(FG_COLOUR, WHITE);
				break;
			case 'G' : display_color(FG_COLOUR, GREEN);
				break;
			case 'g' : display_color(FG_COLOUR, LIGHT_GREEN);
				break;
			case 'B' : display_color(FG_COLOUR, BLUE);
				break;
			case 'b' : display_color(FG_COLOUR, LIGHT_BLUE);
				break;
			case 'C' : display_color(FG_COLOUR, CYAN);
				break;
			case 'c' : display_color(FG_COLOUR, LIGHT_CYAN);
				break;
			case 'K' : display_color(FG_COLOUR, BLACK);
				break;
			case 'R' : display_color(FG_COLOUR, DARK_RED);
				break;
			case 'r' : display_color(FG_COLOUR, RED);
				break;
			case 'M' : display_color(FG_COLOUR, MAGENTA);
				break;
			case 'm' : display_color(FG_COLOUR, ORCHID);
				break;
			case 'k' : display_color(FG_COLOUR, BROWN);
				break;
			case 'Y' : display_color(FG_COLOUR, YELLOW);
				break;
			case 'O' : display_color(FG_COLOUR, ORANGE);
				break;
			case 'F' : display_color(FG_COLOUR, DARK_GRAY);
				break;
			case 'f' : display_color(FG_COLOUR, LIGHT_GRAY);
				break;
			case 'T' : display_color(FG_COLOUR, TURQUOISE);
				break;
			case 'o' : display_color(FG_COLOUR, GOLDENROD);
				break;
			case 'P' : display_color(FG_COLOUR, DARK_ORANGE);
				break;
			case 'w' : display_color(FG_COLOUR, CORNSILK);
				break;
			default : display_color(FG_COLOUR, WHITE);
				break;
		}
		printf(" ");
		x++;
	}
	display_color(FG_COLOUR, WHITE);
	printf(" ");
	display_color(BG_COLOUR, FG_COLOUR);
	printf(" \n");

	display_color(FG_COLOUR, BG_COLOUR);
	printf("   ");
	display_color(BG_COLOUR, FG_COLOUR);
	printf(" ");
	display_color(FG_COLOUR, WHITE);
	printf("          ");
	display_color(BG_COLOUR, FG_COLOUR);
	printf(" \n");


	display_color(FG_COLOUR, BG_COLOUR);
	printf("   ");
	display_color(BG_COLOUR, FG_COLOUR);
	printf("            \n");	
}

void reset_screen(void) {
	display.x = 0;
	display.y = 0;
	rectangle r = {13, display.width-14, 13, display.height-14};
    	fill_rectangle(r, display.background);
}

void draw(void) {
	reset_screen();

	display_color(FG_COLOUR, BG_COLOUR);
	printf("\n\n\n");

	rectangle r = {0, display.width-1, 0, display.height-1};
	fill_rectangle(r, BG_COLOUR);

	int8_t j = 0;
	while (j < PKMN_NO) {
		display_color(FG_COLOUR, BG_COLOUR);
		printf("   ");
		if (j == selected) {
			display_color(BG_COLOUR, FG_COLOUR);
		}
		else {
			display_color(FG_COLOUR, BG_COLOUR);
		}
		printf(pkmn[j].name); printf("\n");
		j++;
	} 

	drawBorder(); 
}

void showDetail(int number) {
	reset_screen();

	display_color(FG_COLOUR, BG_COLOUR);

	rectangle r = {0, display.width-1, 0, display.height-1};
	fill_rectangle(r, BG_COLOUR);

	printf("\n\n\n");

	if (number < 10) {
		printf("   00%d : ", pkmn[number].index);
	}
	else if (number < 100) {
		printf("   0%d : ", pkmn[number].index);
	}
	else {
		printf("   %d : ", pkmn[number].index);
	}

	printf("%s\n", pkmn[number].name);
	printf("   Height: %sm\n", pkmn[number].height);
	printf("   Weight: %skg\n", pkmn[number].weight);

	drawSprite(pkmn[number].sprite);
	
	drawBorder();
}

void main(void) {
	uint8_t cnt = MAX_STEP/2;
	uint8_t i;
	int16_t res;
		
	init();

    /* ENABLE GLOBAL INTERRUPTS HERE */ 
	sei();	

	selected = 0;	
	detail = 0;

	pkmn = loadPokemon();

	draw();
	
    	for (;;) {
	if (get_switch_short(_BV(SWC))) {
		if (detail == 1) {
			draw();
			detail = 0;
		}
		else {
			showDetail(selected);
			detail = 1;
		}
	}

	if (detail == 0) {
		for (i=cnt; i > 0; --i) {
			_delay_ms(STEP_DELAY_MS);
			res = cnt + os_enc_delta();
			if (res > cnt) {
				cnt = MAX_STEP;
				selected--;
				while (selected < 0) {
					selected += PKMN_NO;
				}
				draw();
			} 
			else if (res < cnt) {
				cnt = MIN_STEP;
				selected = (selected+1)%PKMN_NO;
				draw();
			} 
			else {
				cnt = res;			   
		   }
		}
	}
	}
}


/* Configure I/O Ports */
void init(void) {

	/* 8MHz clock, no prescaling (DS, p. 48) */
	CLKPR = (1 << CLKPCE);
	CLKPR = 0;


    /* Configure I/O Ports */
	
	/* ENABLE ENCODER INPUTS AND PULL-UPS */
	
	DDRE  |= _BV(PE4);   /* ROTA input */
	PORTE |= _BV(PE4);   /* ROTA on */ 

	DDRE  |= _BV(PE5);   /* ROTB input */
	PORTE |= _BV(PE5);   /* ROTB on */	

	DDRE  &= ~_BV(SWC);   /* Center button input */
	PORTE |= _BV(SWC);   /* Center button on */	

	/* Timer 0 for switch scan interrupt: */

	TCCR0A = _BV(WGM01);
	TCCR0B = _BV(CS01)
          | _BV(CS00);   /* F_CPU / 64 */
          

    /* SET OCR0A FOR A 1 MS PERIOD */        
    	const uint32_t ticksPerSec = F_CPU / 64;
	
	OCR0A = ticksPerSec / 1000;
	
    /* ENABLE TIMER INTERRUPT */
	TIMSK0 |= _BV(OCIE0A);

	init_lcd();
}



 ISR( TIMER0_COMPA_vect ) {
     static int8_t last;
     int8_t new, diff;
     uint8_t wheel;


     /*
        Scan rotary encoder
        ===================
        This is adapted from Peter Dannegger's code available at:
        http://www.mikrocontroller.net/articles/Drehgeber
     */

     wheel = PINE;
     new = 0;
     if( wheel  & _BV(PE4) ) new = 3;
     if( wheel  & _BV(PE5) )
	 new ^= 1;		        	
     diff = last - new;			
     if( diff & 1 ){			
	     last = new;		       
	     delta += (diff & 2) - 1;	
     }

	scan_switches(0);
}
