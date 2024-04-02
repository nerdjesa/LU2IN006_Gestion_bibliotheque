#include <stdio.h>
#include <stdlib.h>
#include "entreeSortieLC.h"
#include "biblioH.h"
#include "biblioLC.h"
#include <time.h>
#include <string.h>
#define NB_REP 30

void menu(){
    //affichage du menu
    printf("0-sortie du programme\n");
    printf("1-liberer une bibliothèque\n");  
    printf("2-inserer un livre en tête\n");
    printf("3-afficher une bibliothèque\n");
    printf("4-recherche ouvrage par numéro\n");
    printf("5-recherche ouvrage par titre\n");
    printf("6-recherche des ouvrages d'un auteur\n");
    printf("7-fusion de deux bibliothèques \n");
    printf("8-recherche des exemplaires \n");
}
int comparaison_titre(Biblio * b1,BiblioH* b2,char*titre){
    // comparaison pour la recherche par titre
    double temps_execution_titre_LC;
    double temps_execution_titre_H;
    if( b1!=NULL && b2!=NULL ){
        clock_t debut_titre_LC, fin_titre_LC;
        clock_t debut_titre_H, fin_titre_H;
        //debut du chrono
        debut_titre_LC=clock();
        recherche_titre(b1,titre);
        fin_titre_LC=clock();
        debut_titre_H=clock();
        recherche_titreH(b2,titre);
        fin_titre_H=clock();
        temps_execution_titre_LC = ((double)(fin_titre_LC - debut_titre_LC)) / CLOCKS_PER_SEC;
        temps_execution_titre_H = ((double)(fin_titre_H - debut_titre_H)) / CLOCKS_PER_SEC;
        // insertion du temps dans un fichier pour gnuplot
        FILE *fichier = fopen("resultat.txt", "a");

        // Vérification si l'ouverture du fichier a réussi
        if (fichier == NULL) {
            fprintf(stderr, "Erreur lors de l'ouverture du fichier.\n");
            return 1; 
        }
        fprintf(fichier, "%lf\t%lf\n", temps_execution_titre_H, temps_execution_titre_LC);
        // Fermeture du fichier
        fclose(fichier);
    }
    if(temps_execution_titre_H<temps_execution_titre_LC){
        return 1;
    }else{
        return 0;
    }
}
int comparaison_numero(Biblio * b1,BiblioH* b2,int numero){
    double temps_execution_numero_LC;
    double temps_execution_numero_H;
    //recherche par numero
    if( b1!=NULL && b2!=NULL){
        clock_t debut_numero_LC, fin_numero_LC;
        clock_t debut_numero_H, fin_numero_H;
        //debut du chrono
        debut_numero_LC=clock();
        recherche_num(b1,numero);
        fin_numero_LC=clock();
        debut_numero_H=clock();
        recherche_numH(b2,numero);
        fin_numero_H=clock();
        temps_execution_numero_LC = ((double)(fin_numero_LC - debut_numero_LC)) / CLOCKS_PER_SEC;
        temps_execution_numero_H = ((double)(fin_numero_H - debut_numero_H)) / CLOCKS_PER_SEC;
        //affichage du temps dans un fichier pour gnuplot
        FILE *fichier = fopen("resultat1.txt", "a");

        // Vérification si l'ouverture du fichier a réussi
        if (fichier == NULL) {
            fprintf(stderr, "Erreur lors de l'ouverture du fichier.\n");
            return 1; // Code d'erreur
        }
        fprintf(fichier, "%lf\t%lf\n", temps_execution_numero_H, temps_execution_numero_LC);
         // Fermeture du fichier
        fclose(fichier);
    }
    if(temps_execution_numero_H<temps_execution_numero_LC){
        return 1;
    }else{
        return 0;
    }

}
int comparaison_auteur(Biblio * b1,BiblioH* b2,char*auteur){
    //recherche par auteur
    double temps_execution_auteur_LC;
    double temps_execution_auteur_H;
    if( b1!=NULL && b2!=NULL ){
        clock_t debut_auteur_LC, fin_auteur_LC;
        clock_t debut_auteur_H, fin_auteur_H;
        //debut du chrono
        debut_auteur_LC=clock();
        recherche_auteur(b1,auteur);
        fin_auteur_LC=clock();
        debut_auteur_H=clock();
        recherche_auteurH(b2,auteur);
        fin_auteur_H=clock();
        temps_execution_auteur_LC = ((double)(fin_auteur_LC - debut_auteur_LC)) / CLOCKS_PER_SEC;
        temps_execution_auteur_H = ((double)(fin_auteur_H - debut_auteur_H)) / CLOCKS_PER_SEC;
        //affichage du temps dans fichier pour gnuplot
        FILE *fichier = fopen("resultat2.txt", "a");

        // Vérification si l'ouverture du fichier a réussi
        if (fichier == NULL) {
            fprintf(stderr, "Erreur lors de l'ouverture du fichier.\n");
            return 1; // Code d'erreur
        }
        fprintf(fichier, "%lf\t%lf\n", temps_execution_auteur_H, temps_execution_auteur_LC);
        // Fermeture du fichier
        fclose(fichier);
    }
    if(temps_execution_auteur_H<temps_execution_auteur_LC){
        return 1;
    }else{
        return 0;
    }

}
int comparaison_exemplaire(Biblio * b1,BiblioH* b2){
    //recherche par auteur
    double temps_execution_ex_LC;
    double temps_execution_ex_H;
    if( b1!=NULL && b2!=NULL ){
        clock_t debut_ex_LC, fin_ex_LC;
        clock_t debut_ex_H, fin_ex_H;
        // debut du chrono
        debut_ex_LC=clock();
        recherche_exemplaire(b1);
        fin_ex_LC=clock();
        debut_ex_H=clock();
        recherche_exemplaireH(b2);
        fin_ex_H=clock();
        temps_execution_ex_LC = ((double)(fin_ex_LC - debut_ex_LC)) / CLOCKS_PER_SEC;
        temps_execution_ex_H = ((double)(fin_ex_H - debut_ex_H)) / CLOCKS_PER_SEC;
        //affichage du temps dans un fichier pour gnuplot
        FILE *fichier = fopen("resultat3.txt", "a");

        // Vérification si l'ouverture du fichier a réussi
        if (fichier == NULL) {
            fprintf(stderr, "Erreur lors de l'ouverture du fichier.\n");
            return 1; // Code d'erreur
        }
        fprintf(fichier, "%lf\t%lf\n", temps_execution_ex_H, temps_execution_ex_LC);
        // Fermeture du fichier
        fclose(fichier);
    }
    if(temps_execution_ex_H<temps_execution_ex_LC){
        return 1;
    }else{
        return 0;
    }

}


int main(int argc,char** argv){
    char* fichier;
    int n;
    if(argc==3){
        fichier=argv[1];
        n=atoi(argv[2]);
    }else{
        printf("argument manquant,usage: fichier,chiffre");
        exit(1);
    }
    //chargement des bibliothèques
    Biblio * b=charger_n_entrees(fichier,n);
    BiblioH * b1=charger_n_entreesH(fichier,n);
    int choix;
    do{
        menu();
        char res[256];
        printf("entrer un numéro pour effectuer une action:\n");
        fgets(res,256,stdin);
        sscanf(res,"%d",&choix);
        switch(choix){
            case 1:
               printf("liberation de la bibliothèque: \n");
               if(b!=NULL && b1!=NULL){
                    printf("liste chainée\n");
                    liberer_biblio(b);
                    printf("hachage\n");
                    liberer_biblioH(b1);
                    printf("libéartion réussie\n");
               }else{
                    printf("bibliothéque non alloué\n");
               }
               break;

            case 2:
                printf("insertion d'une oeuvre:\n");
                int numero;
                char titre[256];
                char auteur[256];
                char buffer[256];
                printf("Veuillez entrer le numero le titre et le nom de l'auteur:\n");
                /*on suppose que le titre et l'auteur n'ont pas d'espace*/
                fgets(buffer,256,stdin);
                if(sscanf(buffer,"%d %s %s",&numero,titre,auteur)==3){
                    printf("liste chainée\n");
                    inserer_en_tete(b,numero,titre,auteur);
                    printf("hachage\n");
                    inserer(b1,numero,titre,auteur);
                    printf("insertion réussie\n");
                }else{
                    printf("erreur format, usage:(int,char,char)\n");
                }
                break;
            case 3:
                printf("affichage de la bibliothèque \n");
                if(b!=NULL && b1!=NULL){
                    printf("liste chainée\n");
                    afficher_biblio(b);
                    printf("hachage\n");
                    afficher_biblioH(b1);
                    printf("affichage réussie\n");
                }else{
                    printf("bibliothéque non alloué\n");
                }
                break;
            
            case 4:
                printf("recherche d'un ouvrage par le numéro \n");
                printf("Veuillez ecrire le numero:\n");
                fgets(buffer,256,stdin);
                if(sscanf(buffer," %d",&numero)==1){
                    Livre *livre1=recherche_num(b,numero);
                    LivreH *livreh1=recherche_numH(b1,numero);
                    printf("liste chainée\n");
                    afficher_livre(livre1);
                    
                    printf("hachage\n");
                    afficher_livreH(livreh1);
                    
                    liberer_livre(livre1);
                    liberer_livreH(livreh1);
                }else{
                    printf("erreur format");
                }
                 break;
            case 5:
                printf("recherche d'un ouvrage par le titre \n");
                /*on suppose que le titre et l'auteur n'ont pas d'espace*/
                printf("Veuillez entrer le titre de l'oeuvre");
                fgets(buffer,256,stdin);
                if(sscanf(buffer," %s ",titre)==1){
                    Livre* livre2=recherche_titre(b,titre);
                    LivreH* livreh2=recherche_titreH(b1,titre);
                    printf("liste chainée\n");
                    afficher_livre(livre2);
                    printf("hachage\n");
                    afficher_livreH(livreh2);
                    liberer_livre(livre2);
                    liberer_livreH(livreh2);
                }else{
                    printf("erreur format\n");
                }
                
                break;
            case 6:
                printf("recherche d'un ouvrage par l'auteur \n");
                printf("Veuillez entrer le nom d'auteur");
                fgets(buffer,256,stdin);
                if (sscanf(buffer," %s",auteur)==1){
                    Biblio *biblio=recherche_auteur(b,auteur);
                    BiblioH* biblioh=recherche_auteurH(b1,auteur);
                    printf("liste chainée\n");
                    afficher_biblio(biblio);
                    printf("hachage\n");
                    afficher_biblioH(biblioh);
                    liberer_biblio(biblio);
                    liberer_biblioH(biblioh);
                }else{
                    printf("erreur format\n");
                }
                 break;
           
            case 7:
                printf("fusion de deux bibliothèque\n");
                printf("entrer un nombre d'entiers\n");
                int n1 ;
                fgets(buffer,256,stdin);
                if(sscanf(buffer," %d",&n1)==1){
                    Biblio* b2=charger_n_entrees(fichier,n1);
                    Biblio * fusion=fusion_biblio(b,b2);
                    BiblioH* b2h=charger_n_entreesH(fichier,n1);
                    BiblioH * fusionh=fusion_biblioH(b1,b2h);
                    printf("liste chainée\n");
                    afficher_biblio(fusion);
                    printf("hachage\n");
                    afficher_biblioH(fusionh);
                    liberer_biblio(b2);
                    liberer_biblio(fusion);
                    liberer_biblioH(b2h);
                    liberer_biblioH(fusionh);
                }else{
                    printf("il manque un argument : un entier \n");
                }
                 break;
            case 8:
                char line1[256];
                char line2[256];
                char f[256];
                int nombre;
                printf("veuillez entrer le nom du fichier ");
                fgets(line1,256,stdin);
                printf("veuillez entrer nombres d'entrées ");
                fgets(line2,256,stdin);
                if(sscanf(line1," %s",f) == 1 && sscanf(line2," %d",&nombre)==1){
                    printf("recherche des exemplaires \n");
                    Biblio * Bi=charger_n_entrees(f,nombre);
                    afficher_biblio(Bi);
                    Biblio * lis=recherche_exemplaire(Bi);
                    BiblioH * BiH=charger_n_entreesH(f,nombre);
                    BiblioH * lisH=recherche_exemplaireH(BiH);
                    printf("liste chainée\n");
                    afficher_biblio(lis);
                    printf("hacahge \n");
                    afficher_biblioH(lisH);
                    liberer_biblio(Bi);
                    liberer_biblio(lis);
                    liberer_biblioH(BiH);
                    liberer_biblioH(lisH);

                }else{
                    printf("recherche des exemplaires \n");
                    Biblio * bib=recherche_exemplaire(b);
                    BiblioH* bibh=recherche_exemplaireH(b1);
                    printf("liste chainée\n");
                    afficher_biblio(bib);
                    printf("hachage\n");
                    afficher_biblioH(bibh);
                    liberer_biblio(bib);
                    liberer_biblioH(bibh);
                }
                break;
        }
            
    }while(choix != 0);
    // test de performance
    //initialisation des scores
    int score_num_H = 0;
    int score_num_LC = 0;
    int score_titre_H = 0;
    int score_titre_LC = 0;
    int score_auteur_H = 0;
    int score_auteur_LC = 0;
    int score_ex_H = 0;
    int score_ex_LC = 0;
    int j = 0;
    //valeur à changer pour tester mettre une valeur qui est présente ou non présente
    char auteur_test[]="yhidd";
    char *p;
    p=auteur_test;
    //valeur à changer pour tester mettre une valeur qui est présente ou non présente
    char titre_test[]="WLRBBMQBHCDARZOWK";
    char *p1;
    p1=titre_test;
    //boucle de performance , on peut aussi modifier l'entier pour le numéro selon nos testsS
    while(j < NB_REP){
        int a=comparaison_auteur(b, b1,p);
        if(a){
            score_auteur_H++;
        }else{
         score_auteur_LC++;
        }
        int k=comparaison_numero(b, b1, 5);
        if(k){
            score_num_H++;
        }else{
            score_num_LC++;
        }
        int c=comparaison_titre(b, b1, p1);
        if(c){
            score_titre_H++;
        } else {
            score_titre_LC++;
        }
        j++;
    }
    // perfomance de recherche_exemplaire , i représente n , l'incrémentation de i peut être changé pour les diférent test (incrémentation positives)
    int i=1000;

    while(i<50000){
        // chargement partielles des bibliothèques
        Biblio * b3=charger_n_entrees(fichier,i);
        BiblioH* b4=charger_n_entreesH(fichier,i);
        int d=comparaison_exemplaire(b3, b4);
        if(d){
         score_ex_H++;
        } else {
         score_ex_LC++;
        }
        i=i*2;
        //libération
        liberer_biblio(b3);
        liberer_biblioH(b4);
    }

    printf("Score hachage par numéro : %d Score liste par numéro: %d\n", score_num_H, score_num_LC);
    printf("Score hachage par auteur: %d Score liste par auteur: %d\n", score_auteur_H, score_auteur_LC);
    printf("Score hachage par titre: %d Score liste par titre: %d\n", score_titre_H, score_titre_LC);
    printf("Score hachage par exmplaire: %d Score liste par exmplaire %d\n", score_ex_H, score_ex_LC);
    liberer_biblio(b);
    liberer_biblioH(b1);
    printf("Merci et au revoir!\n");
    return 0;
}

