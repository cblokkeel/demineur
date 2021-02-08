int get_position(int ligne, int colonne);
int est_une_mine(int ligne, int colonne);
int placer_mine(int ligne, int colonne);
int affiche_mines(void);
void print_line(void);
void print_letters(void);
int combien_de_mine_autour(int ligne, int colonne);
_Bool check_value(int array[], int seek);
_Bool check_2d_array(int array[][], int seek[]);