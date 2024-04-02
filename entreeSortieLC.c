
#include <stdio.h>
#include <stdlib.h>
#include "entreeSortieLC.h"

Biblio* charger_n_entrees(char* nomfic, int n){
    // ouverture du fichier en lecture
    FILE* f = fopen(nomfic, "r");
    
    // création de la bibliothéque 
    Biblio* b = creer_biblio();
    
    if(f != NULL){
        // déclaration des arguments pour la création d'un livre
        int num;
        char titre[100];
        char auteur[100];
        char buffer[500];
        char* res = fgets(buffer, 500, f);
        
        // boucle de lecture
        while (n > 0 && res != NULL) {
            sscanf(res, "%d %s %s", &num, titre, auteur);
            inserer_en_tete(b, num, titre, auteur);
            res = fgets(buffer, 500, f);
            n = n - 1;
        }
        fclose(f); // Déplacer la fermeture du fichier ici, après la boucle
    } else {
        fprintf(stderr, "Erreur : impossible d'ouvrir le fichier %s\n", nomfic);
        exit(EXIT_FAILURE);
    }
    return b;
}
void enregistrer_biblio(Biblio *b, char* nomfic){
    //ouverture du fihcher en écriture
    FILE* f=fopen(nomfic,"w");
    if(f!=NULL){
        Livre*l=b->L;
        //boucle d'écriture
         while(l!=NULL){
            fprintf(f,"%d %s %s\n",l->num,l->titre, l->auteur);
            l=l->suiv;
         }
        fclose(f);
    }else{
        exit(EXIT_FAILURE);
    }

}


BiblioH* charger_n_entreesH(char* nomfic, int n) {
    //ouverture du fichier
    FILE* f = fopen(nomfic, "r");
    if (f == NULL) {
        fprintf(stderr, "Erreur : impossible d'ouvrir le fichier %s\n", nomfic);
        exit(EXIT_FAILURE);
    }
    //création de la bibliothèque
    BiblioH* b = creer_biblioH(n);
    //déclaration des arguments pour la création d'un livre
    int num;
    char titre[100];
    char auteur[100];
    char buffer[500];
    char* res = fgets(buffer, 500, f);
    //boucle de lecture
    while (n > 0 && res != NULL) {
        sscanf(res, "%d %s %s", &num, titre, auteur);
        inserer(b, num, titre, auteur); 
        res = fgets(buffer, 500, f);
        n = n - 1;
    }

    fclose(f);
    return b;
}
void enregistrer_biblioH(BiblioH* b, char* nomfic) {
    //ouverture du fichier
    FILE* f = fopen(nomfic, "w");
    if (f == NULL) {
        fprintf(stderr, "Erreur : impossible d'ouvrir le fichier %s\n", nomfic);
        exit(EXIT_FAILURE);
    }
    //boucle d'écriture
    for (int i = 0; i < b->m; i++) {
        LivreH* l = b->T[i];
        while (l != NULL) {
            fprintf(f, "%d %s %s\n", l->num, l->titre, l->auteur);
            l = l->suivant;
        }
    }

    fclose(f);
}

