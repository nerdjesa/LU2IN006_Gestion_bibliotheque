#include <stdio.h>
#include <stdlib.h>
#include "biblioLC.h"
#include <string.h>
Livre* creer_livre(int num,char* titre,char* auteur){
    Livre* l = (Livre*) malloc(sizeof(Livre));// allocation du nouveau livre
    //initialisation des arguments 
    l->num=num;
    l->titre=strdup(titre);
    l->auteur=strdup(auteur);
    l->suiv =NULL;

    return l;

}

void liberer_livre(Livre* l){
    if(l!=NULL){
        //libération des champs
        free(l->titre);
        free(l->auteur);
        //libération du livre
        free(l);
    }
}

Biblio* creer_biblio() {
        // allocation d'une nouvelle bibliothéque
        Biblio* b = (Biblio*) malloc(sizeof(Biblio));
        b->L=NULL;
        return b;
}

void liberer_biblio(Biblio* b){
    if(b!=NULL){
        Livre* courant= b->L;
        Livre* suivant;
        while(courant!=NULL){
                // garde le pointeur vers le livre suivant 
                suivant=courant->suiv;
                liberer_livre(courant);
                // met à jour le livre courant pour l'itération suivante
                courant=suivant;
        }
        free(b);
    }
}

void inserer_en_tete(Biblio* b,int num,char* titre,char* auteur){
    Livre* l= creer_livre(num,titre,auteur);
    l->suiv=b->L;
    // rattachement de la nouvelle tête
    b->L=l;
}

void afficher_livre(Livre* l){
    if(l!=NULL){
        printf("%d titre: %s auteur: %s\n",l->num,l->titre,l->auteur);
    }
}

void afficher_biblio(Biblio* b){
    Livre* l=b->L;
    while(l!=NULL){
        afficher_livre(l);
        printf("\n");
        l=l->suiv;
    }

}
Livre* recherche_num(Biblio* b, int n) {
    if (b == NULL) {
        return NULL;  
    }

    Livre* l = b->L;
    while (l != NULL) {
        if (l->num == n) {
            // Livre trouvé, retourne le livre
            return l;  
        }
        l = l->suiv;
    }

    // Livre non trouvé
    printf("Livre avec le numéro %d non trouvé.\n", n);
    return NULL;
}




Livre* recherche_titre(Biblio* b, char* titre){
    if(b==NULL){
        return NULL;
    }
    Livre* l=b->L;
    //boucle de recherche avce comparaion par titre
    while(l && (strcmp(titre,l->titre)!=0)){
        l=l->suiv;
    }
    return l;
}

Biblio* recherche_auteur(Biblio* b, char* auteur){
    if(b==NULL){
        return NULL;
    }
    Livre* l=b->L;
    Biblio* b1=creer_biblio();
    //boucle de recherche avce comparaion par auteur
    while(l){
        if(strcmp(auteur,l->auteur)==0){
            inserer_en_tete(b1,l->num,l->titre,l->auteur);
        }
        l=l->suiv;
    }
    return b1;
}

void supprime_livre(Biblio* b,int num,char* titre, char* auteur){
    if(b==NULL){
        printf("erreur la bibliotheque est NULL \n");
        return;
    }
    Livre* courant=b->L;
    Livre* suiv;
    while(courant!=NULL){
        if(strcmp(courant->titre,titre)==0 && strcmp(courant->auteur,auteur)==0 && courant->num==num){
            //mise à jour du suivant
            suiv=courant->suiv;
            liberer_livre(courant);
            //rattachement du courant
            courant=suiv;
            break;
        }
        courant=courant->suiv;
    }
    
}

Biblio* fusion_biblio(Biblio* b1, Biblio* b2) {
    if(b2==NULL){
        return b1;
    }
    if (b1 == NULL) {
        // Si b1 est NULL,on retourne b2
        return b2;  
    }
    if (b1->L == NULL) {
        // Si b1 est vide, b2 devient la tête de b1
        b1->L = b2->L;  
    } else {
        Livre* l = b1->L;
        while (l->suiv != NULL) {
            l = l->suiv;
        }
        // Ajouter les livres de b2 à la fin de b1
        l->suiv = b2->L;  
    }
    // Libérer la mémoire de la bibliothèque b2
    free(b2);  
    return b1;
}


int est_dans_biblio(Biblio* b, Livre* livre) {
    Livre* courant = b->L;
    while (courant != NULL) {
        if (courant->num == livre->num && strcmp(courant->titre, livre->titre) == 0 && strcmp(courant->auteur, livre->auteur) == 0) {
            // Le livre est déjà dans la bibliothèque
            return 1; 
        }
        courant = courant->suiv;
    }
    // Le livre n'est pas dans la bibliothèque
    return 0; 
}
Biblio* recherche_exemplaire(Biblio* b){
    if(b==NULL){
        return NULL;
    }
    //création de la liste 
    Biblio* liste= creer_biblio();
    Livre* courant=b->L;

    while(courant!=NULL){
        //IL FAUT VERIFIER SI COURANT N'EST PAS DANS LISTE
        if(est_dans_biblio(liste,courant) == 0){
        Livre* suiv=courant->suiv;
            while(suiv!=NULL){
                if(strcmp(suiv->auteur,courant->auteur) == 0 && strcmp(suiv->titre,courant->titre) == 0 && suiv->num != courant->num){
                    if(est_dans_biblio(liste,courant)==0){
                        //insertion du doublons dnans la liste
                        inserer_en_tete(liste,courant->num,courant->titre,courant->auteur);
                    }
                    if(est_dans_biblio(liste,suiv) == 0){
                        //insertion du doublons dnans la liste
                        inserer_en_tete(liste,suiv->num,suiv->titre,suiv->auteur);
                    }
            
                }
                suiv=suiv->suiv;
            }
        }      
        courant=courant->suiv;
    }
    return liste;
}
