#ifndef A
#define A
#include "biblioLC.h"
#include "biblioH.h"
// lire n lignes du fichier et de les stocker dans une bibliothèque 
Biblio* charger_n_entrees(char* nomfic, int n);
// stocker une bibliothéque dans un fichier au bon format
void enregistrer_biblio(Biblio *b, char* nomfic);
// lire n lignes du fichier et de les stocker dans une bibliothèque (hachage)
BiblioH* charger_n_entreesH(char* nomfic, int n);
// stocker une bibliothéque dans un fichier au bon format(hachage)
void enregistrer_biblioH(BiblioH* b, char* nomfic);
#endif