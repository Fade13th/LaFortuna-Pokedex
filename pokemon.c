#include "pokemon.h"

struct Pokemon pkmn[9];

struct Pokemon * loadPokemon(void) {
	struct Pokemon bulbasaur;
	bulbasaur.index = 1;
	bulbasaur.name = "Bulbasaur";
	bulbasaur.height = "0.71";
	bulbasaur.weight = "6.9";
	char a[64] = "WWGWWWWWWgGGbWWbWgGGbbBbWgGGbKbKCCBCbbbbCCBCCCWWbCCCbCCWBbbCBbCC";
	memcpy(bulbasaur.sprite, a, 64);

	struct Pokemon ivysaur;
	ivysaur.index = 2;
	ivysaur.name = "Ivysaur";
	ivysaur.height = "0.99";
	ivysaur.weight = "13.0";
	char b[64] = "WWmMWWWWWGMMMGWWGGGGGCWCWbbbbCCCbbbbbKCKbbbbbCCCbBWWbWBWbBWWbWBW";
	memcpy(ivysaur.sprite, b, 64);

	struct Pokemon venusaur;
	venusaur.index = 3;
	venusaur.name = "Venusaur";
	venusaur.height = "2.01";
	venusaur.weight = "100.0";
	char c[64] = "WWMYMWWWWMfMfMWWGMMMMMGTbGGbGTTTbbbbbKTKbbbbbTTTbbbbbTTTWbBWWbBW";
	memcpy(venusaur.sprite, c, 64);

	struct Pokemon charmander;
	charmander.index = 4;
	charmander.name = "Charmander";
	charmander.height = "0.61";
	charmander.weight = "8.5";
	char d[64] = "WOOOWWWWOOKOWWWWOOOOOOWWWWWoOOWYWWPooOWOWWWOOOOOWWOWPWWWWWOWWPWW";
	memcpy(charmander.sprite, d, 64);

	struct Pokemon charmeleon;
	charmeleon.index = 5;
	charmeleon.name = "Charmeleon";
	charmeleon.height = "1.09";
	charmeleon.weight = "19.0";
	char e[64] = "WWrWWWWWWWrKrWWWWrrrrWWWRrrWWWWWRRrrWWWWWrrrrrWYWrWWrWrYWWrWrWWW";
	memcpy(charmeleon.sprite, e, 64);

	struct Pokemon charizard;
	charizard.index = 6;
	charizard.name = "Charizard";
	charizard.height = "1.7";
	charizard.weight = "90.5";
	char f[64] = "WWWWOWWWWOOWWOKWOccOWOOOWWccPPWWWOOOOOPWOOOOYOOPOWWWYYWWWOOOOYWW";
	memcpy(charizard.sprite, f, 64);

	struct Pokemon squirtle;
	squirtle.index = 7;
	squirtle.name = "Squirtle";
	squirtle.height = "0.51";
	squirtle.weight = "9.0";
	char g[64] = "WWWWWcccWWWWWKcKWWWWkcccWcckkwwWWcckkbwbWccckwwWWWWWcWbWWWWWcWbW";
	memcpy(squirtle.sprite, g, 64);

	struct Pokemon wartortle;
	wartortle.index = 8;
	wartortle.name = "Wartortle";
	wartortle.height = "0.99";
	wartortle.weight = "22.5";
	char h[64] = "WWcWWWWWBccWWWWWKBWWWWcWBBkkWWccWwwkkWccBBwwkcccWWWwBcWWWWWWBWWW";
	memcpy(wartortle.sprite, h, 64);

	struct Pokemon blastoise;
	blastoise.index = 9;
	blastoise.name = "Blastoise";
	blastoise.height = "1.6";
	blastoise.weight = "85.5";
	char i[64] = "WBWWWWWWKBWFWWWWBBkkfWWWWwkkkWWWBBwkkkWWWWwwBkkWWWWBBwkBWWWBWWWW";
	memcpy(blastoise.sprite, i, 64);



	pkmn[0] = bulbasaur;
	pkmn[1] = ivysaur;
	pkmn[2] = venusaur;
	pkmn[3] = charmander;
	pkmn[4] = charmeleon;
	pkmn[5] = charizard;
	pkmn[6] = squirtle;
	pkmn[7] = wartortle;
	pkmn[8] = blastoise;

	return pkmn;
}
