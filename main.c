#include "main.h"

int mines[NB_LIGNES * NB_COLONNES];
char terrain[NB_LIGNES * NB_COLONNES];
int how_many_discovered = 0;
int NB_MINES = 0;

int main(void)
{
	printf("Combien de mine voulez vous ?\n");
	NB_MINES = demande_entier();
	place_random_mines(NB_MINES);

	// placer_mine(2, 4);
	// placer_mine(3, 1);
	// placer_mine(4, 3);
	affiche_mines();

	initialiser_terrain();
	affiche_terrain();

	ask_user();

	return 0;
}