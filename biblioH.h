#ifndef P
#define P
typedef struct livreh {
int clef ;
int num; /*... toutes les donnees permettant de representer un livre */
char * auteur;
char * titre;
struct livreh * suivant ;
} LivreH ;

typedef struct table {
int nE ; /*nombre d’elements contenus dans la table de hachage */
int m ; /*taille de la table de hachage */
LivreH ** T ; /*table de hachage avec resolution des collisions par chainage */
} BiblioH ;

//fonction qui crée les clefs pour chaque livre
int fonctionClef(char* auteur);
// création d'un livre
LivreH* creer_livreH(int num,char* titre,char* auteur);
// libéartion d'un livre
void liberer_livreH(LivreH* l);
//creation d'une bibliothèque
BiblioH* creer_biblioH(int m);
// fonction de hachage
int fonctionHachage(int cle, int m);
//libéartion de la bibliothèque
void liberer_biblioH(BiblioH* b);
// insertion d'un livre
void inserer(BiblioH* b,int num,char* titre,char* auteur);
// affichage d'un livre
void afficher_livreH(LivreH* l);
//affichage d'une bibliothèque
void afficher_biblioH(BiblioH* b);
//recherche par numéro
LivreH* recherche_numH(BiblioH* b, int n);
// recherche par titre
LivreH* recherche_titreH(BiblioH* b, char* titre);
//recherche par auteur
BiblioH* recherche_auteurH(BiblioH* b, char* auteur);
// suppression d'un livre
void supprime_livreH(BiblioH* b, int num, char* titre, char* auteur);
// fusion d'une bibliothèque
BiblioH* fusion_biblioH(BiblioH* b1, BiblioH* b2);
// vérification de la présence d'un livre
int est_dans_biblioH(BiblioH* b, LivreH* livre);
// recherche les doublons 
BiblioH* recherche_exemplaireH(BiblioH* b) ;
#endif