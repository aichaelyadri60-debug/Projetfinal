#include <stdio.h>
#include <string.h>
#include "clients.h"
#include "produits.h"


int main(){
    int choix;
    do{
        printf("====== SYSTÈME D'ACHAT CLIENT ======\n");
        printf("1. Gestion du profil client \n");
        printf("2. Gestion du solde virtuel\n");
        printf("3. Consultation des produits\n");
        printf("4. Effectuer un achat\n");
        printf("5. Mes statistiques\n");
        printf("0. Quitter l'application\n");
        printf("Votre choix :");
        scanf("%d",&choix);
        printf("=====================================\n");
        
        switch (choix)
        {
        case 1:{
            int choix1;
            do{
                printf("======= CREATION DE PROFIL :======\n");
                printf("1. Ajout de client \n");
                printf("2. Modification du profil client \n");
                printf("3. Affichage du profil client \n");
                printf("0. reteurner a menu principale \n");
                printf("votre choix :");
                scanf("%d",&choix1);
                printf("====================================\n");
                switch(choix1){
                    case 1:ajoutclient();break;
                    case 2:modificationclient();break;
                    case 3:afficherclient();break;
                    case 0:printf("bienvenue sur menu principale\n");break;
                    default :printf("votre choix et inconnu .\n");
                }
            }while (choix1 != 0); break;
        }
        case 2: {
            int choix2;
            do {
                printf("\n======= GESTION DE SOLDE VIRTUEL :======\n");
                printf("1. Consultation du solde \n");
                printf("2. Depot d'argent\n");
                printf("0. reteurner a menu principale \n");
                printf("votre choix :");
                scanf("%d",&choix2);
                printf("====================================\n");
                switch(choix2){
                    case 1 :affichesolde();break;
                    case 2:Alimentationsolde();break;
                    case 0:printf("bienvenue sur menu principale\n");break;
                    default :printf("votre choix et inconnu .\n"); 
                }
            }while(choix2 != 0);break;
        }
        case 3:{
            int choix3;
            do{
                printf("======= CATALOGUE DES PRODUITS :======\n");
                printf("1. Affichage catalogue .\n");
                printf("2. Recherche produits par nom .\n");
                printf("3. Tri des produits par nom .\n");
                printf("4. Tri croissant  des produits  par prix. \n");
                printf("5. Tri decroissant  des produits  par prix.\n");
                printf("6. Details d'un produit .\n");
                printf("0. reteurner a menu principale .\n");
                printf("votre choix :");
                scanf("%d",&choix3);
                printf("====================================\n");
                switch (choix3){
                    case 1:afficherProduits();break;
                    case 2:Rechercheparnom();break;
                    case 3:triparnom();break;
                    case 4:tricroissant();break;
                    case 5:tridecroissant();break;
                    case 6:detailproduit();break;
                    case 0:printf("bienvenue sur menu principale\n");break;
                    default :printf("votre choix et inconnu .\n"); 
                }
            }while (choix3 != 0 );break;
        }
        case 4: acheter();break;
        case 5: {
             int choix4;
            do{
                printf("========= MES STATISTIQUES :==========\n");
                printf("1. produits disponible et non disponible  \n");
                printf("2. Historique des achats . \n");
                printf("0. reteurner a menu principale \n");
                printf("votre choix :");
                scanf("%d",&choix4);
                printf("====================================\n");
                switch(choix4){
                    case 1:disponibilite();break;
                    case 2:historiquedetail();break;
                    case 0:printf("bienvenue sur menu principale\n");break;
                    default :printf("votre choix et inconnu .\n");
                }
            }while (choix4 != 0);break;
        }
        case 0:printf("Au revoir .\n"); break;
        default:printf("cette nombre et ne pas dans le menu ");
        }
    }while(choix != 0);
}


