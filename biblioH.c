#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "biblioH.h"
#include <math.h>
int fonctionClef(char* auteur){
    int somme= 0;
    int i=0;
    while (auteur[i]!= '\0'){
        //calcul de la clé
        somme=somme+ (int)auteur[i];
        i++;
    }
    return somme;
}


LivreH* creer_livreH(int num,char* titre,char* auteur){
    //création d'un livre
    LivreH *livre=(LivreH *)malloc(sizeof(LivreH));
    //initialisation des champs
    livre->num=num;
    livre->titre=strdup(titre);
    livre->auteur=strdup(auteur);
    livre->clef=fonctionClef(auteur);
    livre->suivant=NULL;
    return livre;
}


void liberer_livreH(LivreH* l){
    if(l!=NULL){
        //désalloue les champs
        free(l->titre);
        free(l->auteur);
        // désalloue le livre
        free(l);
    }
}

BiblioH* creer_biblioH(int m){
    //allocation d'une bibliothèqe=ue
    BiblioH* b=(BiblioH *)malloc(sizeof(BiblioH));
    b->m=m;
    b->nE=0;
    b->T=(LivreH ** )malloc(sizeof(LivreH*)*m);
    for(int i=0 ;i<m;i++){
        //intialisation de la tablede hachage
        b->T[i]=NULL;
    }
    return b;
}

void liberer_biblioH(BiblioH* b){
    int i;
    LivreH * courant ;
    LivreH * suivant;
    for(i=0;i<b->m;i++){
        if(b->T[i] != NULL){
            courant=b->T[i];
            //boucle de désallocation
            while(courant != NULL){
                suivant=courant->suivant;
                liberer_livreH(courant);
                courant=suivant;
            }
        }
    }
    free(b->T);
    free(b);
}


int fonctionHachage(int cle, int m){
    double  A =(sqrt(5)-1)/2;
    double v=cle*A;
    int vH=(int)(m*(v-(int)v));
    return vH;
}


void inserer(BiblioH* b,int num,char* titre,char* auteur){
    //création du livre
    LivreH * livre=creer_livreH(num,titre,auteur);
    
    // trouver la case
    int valeurH = fonctionHachage(livre->clef,b->m);

    //insertion
    livre->suivant= b->T[valeurH];
    b->T[valeurH]=livre;


}

void afficher_livreH(LivreH* l) {
    if(l!=NULL){
        printf("%d titre: %s auteur: %s\n", l->num, l->titre, l->auteur);
    }
   
}

void afficher_biblioH(BiblioH* b) {
    for (int i = 0; i < b->m; i++) {
        LivreH* l = b->T[i];
        while (l != NULL) {
            afficher_livreH(l);
            printf("\n");
            l = l->suivant;
        }
    }
}

LivreH* recherche_numH(BiblioH* b, int n) {
    for (int i = 0; i < b->m; i++) {
        LivreH* l = b->T[i];
        while (l != NULL && l->num != n) {
            l = l->suivant;
        }
        if (l != NULL) {
            // livre trouvé
            return l; 
        }
    }
    //livre absent
    return NULL; 
   
}

LivreH* recherche_titreH(BiblioH* b, char* titre) {
    for (int i = 0; i < b->m; i++) {
        LivreH* l = b->T[i];
        while (l != NULL && strcmp(titre, l->titre) != 0) {
            l = l->suivant;
        }
        if (l != NULL) {
            // livre trouvé
            return l; 
        }
    }
    //livre absent
    return NULL; 
}

BiblioH* recherche_auteurH(BiblioH* b, char* auteur) {
    //recupération de l'indice ou on doit fiare la recherche
    int clef=fonctionClef(auteur);
    int clefH=fonctionHachage(clef,b->m);
    BiblioH * b1=creer_biblioH(b->m);
    LivreH* l = b->T[clefH];
    while (l != NULL) {
        inserer(b1, l->num, l->titre, l->auteur);
        l = l->suivant;
    }
    return b1;
}

void supprime_livreH(BiblioH* b, int num, char* titre, char* auteur) {
    //recupération de l'indice ou on doit fiare la recherche
    int cle=fonctionClef(auteur);
    int cleh = fonctionHachage(cle, b->m);
    LivreH* courant = b->T[cleh];
    LivreH* precedent = NULL;

    while (courant != NULL) {
        if (courant->num == num && strcmp(courant->titre, titre) == 0 && strcmp(courant->auteur, auteur) == 0) {
            if (precedent == NULL) {
                // Le livre à supprimer est en tête de liste
                b->T[cleh] = courant->suivant;
            } else {
                precedent->suivant = courant->suivant;
            }
            liberer_livreH(courant);
            break;
        }

        precedent = courant;
        courant = courant->suivant;
    }
}

BiblioH* fusion_biblioH(BiblioH* b1, BiblioH* b2) {
    for (int i = 0; i < b2->m; i++) {
        LivreH* l = b2->T[i];
        while (l != NULL) {
            inserer(b1, l->num, l->titre, l->auteur);
            LivreH* temp = l;
            l = l->suivant;
            free(temp);
        }
    }

    free(b2->T);
    free(b2);

    return b1;
}

int est_dans_biblioH(BiblioH* b, LivreH* livre) {
    int i = fonctionHachage(livre->clef, b->m);
    LivreH* courant = b->T[i];

    while (courant != NULL) {
        if (courant->num == livre->num && strcmp(courant->titre, livre->titre) == 0 && strcmp(courant->auteur, livre->auteur) == 0) {
            // livre présent
            return 1; 
        }
        courant = courant->suivant;
    }
    // livre absent
    return 0; 
}

BiblioH* recherche_exemplaireH(BiblioH* b) {
    BiblioH* liste = creer_biblioH(b->m);

    for (int i = 0; i < b->m; i++) {
        LivreH* courant = b->T[i];
        while (courant != NULL) {
            //verfication de la présence du courant dans la liste
            if (est_dans_biblioH(liste, courant) == 0) {
                LivreH* suivant = courant->suivant;
                while (suivant != NULL) {
                    if (strcmp(suivant->auteur, courant->auteur) == 0 && strcmp(suivant->titre, courant->titre) == 0 && suivant->num != courant->num) {
                        if (est_dans_biblioH(liste, courant) == 0) {
                            //insertion du doublon
                            inserer(liste, courant->num, courant->titre, courant->auteur);
                        }
                        if (est_dans_biblioH(liste, suivant) == 0) {
                            //insertion du doublon
                            inserer(liste, suivant->num, suivant->titre, suivant->auteur);
                        }
                    }
                    suivant = suivant->suivant;
                }
            }
            courant = courant->suivant;
        }
    }

    return liste;
}

