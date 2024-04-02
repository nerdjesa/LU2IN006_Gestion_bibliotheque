#ifndef B
#define B

typedef struct livre {
 int num ;
 char * titre ;
 char * auteur ;
 struct livre * suiv ;
 } Livre ;

 typedef struct { /* Tete fictive */
 Livre * L ; /* Premier element */
 } Biblio ;

// Signature: crée un livre 
Livre* creer_livre(int num,char* titre,char* auteur);
 //Signature: libère un livre
void liberer_livre(Livre* l);
 //création de la bibliothéque 
Biblio* creer_biblio() ;
 //liberer la bibliothéque
void liberer_biblio(Biblio* b) ;
// insere un livre en tête
void inserer_en_tete(Biblio* b,int num,char* titre,char* auteur);
// affichage d'un livre
void afficher_livre(Livre* l);
// affichage d'une bibliothéque
void afficher_biblio(Biblio* b);
// reccher par le numéro de l'ouvrage
Livre* recherche_num(Biblio* b, int n);
// receherhce par le titre de l'ouvrage
Livre* recherche_titre(Biblio* b, char* titre);
//recher par l'auteur des ouvrage
Biblio* recherche_auteur(Biblio* b, char* auteur);
// fusion de deux bibliothéque
Biblio* fusion_biblio(Biblio* b1,Biblio* b2);
//recherche des ouvrages et leurs exemplaires
Biblio* recherche_exemplaire(Biblio* b);
//vérifie si le livre est dans la bibliothèque
int est_dans_biblio(Biblio* b, Livre* livre);

#endif