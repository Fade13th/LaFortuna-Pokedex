#include <string.h>

struct Pokemon * loadPokemon(void);

struct Pokemon {
        int index;
        char *name;
        char *height;
        char *weight;
	char sprite[64];
};
