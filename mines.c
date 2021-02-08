#include "main.h"
extern int mines[];

int est_une_mine(int ligne, int colonne)
{

	int position = get_position(ligne, colonne);

	return mines[position];

}


int placer_mine(int ligne, int colonne)
{

	int position = get_position(ligne, colonne);
	mines[position] = 1;

	return 0;

}


int affiche_mines(void)
{

	int size = NB_LIGNES * NB_COLONNES;

	print_letters();
	print_line();
	print_line();

	for (int i = 0; i < size; i++)
	{	

		if (i % NB_COLONNES == 0)
		{
			if (i == 0)
			{
				printf(" %i |", i + 1);
			}
			else
			{
				printf("\n");
				print_line();
				printf(" %i |", i / NB_LIGNES + 1);				
			}
		}

		// vérifie si on est au bout de la ligne, si oui on affiche | i | sinon juste | i
		(i + 1) % NB_COLONNES == 0 ? printf("| %i |", mines[i]) : printf("| %i ", mines[i]);


	}
	printf("\n");
	print_line();
	printf("\n");

	return 0;

}


void print_line(void)
{
	printf("---+");
	for (int i = 0; i < NB_COLONNES; i++)
	{
		i == NB_COLONNES - 1 ? printf("+---+") : printf("+---");
	}

	printf("\n");
}


void print_letters(void)
{	

	char c;

	printf("   |");
	for (int i = 0; i < NB_COLONNES; i++)
	{
		c = i + 97;
		printf("| %c ", c);
	}
	printf("|\n");

}


int combien_de_mine_autour(int ligne, int colonne)
{

	int position = get_position(ligne, colonne);
	int to_check[8] = { 0, 0, 0, 0, 0, 0, 0, 0 };
	int how_many_mines = 0;

	/*

	[
		n n n n
		n n M n
		M n n M
		n n M n
	]

	- nombre de col SAUF si première ligne 
	+ nombre de col SAUF si dernière ligne 
	- 1 SAUF si première colonne
 	+ 1 SAUF si dernière colonne
 	- nombre de col + 1 SAUF si dernière colonne
 	- nombre de col - 1 SAUF si première colonne
 	+ nombre de col + 1 SAUF si dernière colonne
  	+ nombre de col - 1 SAUF si première colonne

	*/

	if (position > NB_COLONNES)
	{
		to_check[0] = mines[position - NB_COLONNES]; 
	}
	if (position < NB_COLONNES * (NB_LIGNES - 1))
	{
		to_check[1] = mines[position + NB_COLONNES];
	}
	if (position % NB_COLONNES != 0) 
	{
		to_check[2] = mines[position - 1];
		if (ligne > 1)
		{
			to_check[3] = mines[position - NB_COLONNES - 1];
		}
		if (ligne < NB_LIGNES)
		{
			to_check[4] = mines[position + NB_COLONNES - 1];
		}
	}
	if ((position + 1) % NB_COLONNES != 0)
	{
		to_check[5] = mines[position + 1];
		if (ligne > 1)
		{
			to_check[6] = mines[position - NB_COLONNES + 1];
		}
		if (ligne < NB_LIGNES)
		{
			to_check[7] = mines[position + NB_COLONNES + 1];
		}
	}

	for (int i = 0; i < 8; i++)
	{
		how_many_mines += to_check[i];
	}



	return how_many_mines;

}

int get_position(int ligne, int colonne)
{

	/* (ligne - 1) * NB_COLONNES :
			retourne le nombre de case présent 
			sur les lignes précedentes
		+ (colonne - 1) :
			ajoute les cases restantes sur la ligne actuelle
			(on retire 1 car on commence à 0 donc colonne 4 = colonne[3])
	*/

	return (ligne - 1) * NB_COLONNES + (colonne - 1);

}