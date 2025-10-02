#include <stdio.h>
#include <string.h>
#include "produits.h"



struct Produits produit[10]= {
        {1, "Ordinateur Portable", "Electronique", 8000.0, 5, "PC performant pour bureautique et gaming."},
        {2, "Smartphone", "Electronique", 3500.0, 10, "Telephone Android avec ecran AMOLED."},
        {3, "Casque Audio", "Accessoires", 750.0, 20, "Casque sans fil Bluetooth."},
        {4, "Imprimante", "Bureau", 1200.0, 8, "Imprimante multifonctions couleur."},
        {5, "Tablette", "Electronique", 2500.0, 15, "Tablette tactile Android."},
        {6, "Clavier", "Accessoires", 300.0, 25, "Clavier mecanique retroeclaire."},
        {7, "Souris", "Accessoires", 200.0, 30, "Souris optique sans fil."},
        {8, "Ecran 24 pouces", "Electronique", 1500.0, 12, "Ecran LED Full HD."},
        {9, "Disque Dur 1To", "Stockage", 600.0, 18, "Disque dur externe USB 3.0."},
        {10, "Routeur WiFi", "Reseau", 800.0, 10, "Routeur sans fil double bande."}
    };
int nbproduits=10;

void afficherProduits(){
    for(int i=0;i<nbproduits-1;i++){
        for(int j=0;j<nbproduits-i-1;j++){
            if(produit[j].idproduit>produit[j+1].idproduit){
                struct Produits p=produit[j];
                produit[j]=produit[j+1];
                produit[j+1]=p;
            }
        }
    }
    for(int i=0;i<nbproduits;i++){
        printf("-----------------------produit %d -------------------------\n",i+1);
        printf(" ID          :%d.\n",produit[i].idproduit);
        printf(" NOM         :%s.      \n",produit[i].nomP);
        printf(" CATEGORIE   :%s.      \n",produit[i].categorie);
        printf(" PRIX        :%.2f DH. \n",produit[i].prix);
        printf(" STOCK       : %d.     \n",produit[i].stock);
        printf(" DESCRIPTION :%s.      \n",produit[i].description);
        printf("----------------------------------------------------------\n");
    }
}

void Rechercheparnom(){
    char name[50];
    printf("Entrer le nom de produit qui tu veux :");
    scanf(" %[^\n]",name);
    int trouve=0;
    for(int i=0;i<nbproduits;i++){
        if(strcmp(produit[i].nomP,name)==0){
          printf("ID          :%d.\n",produit[i].idproduit);
          printf("NOM         :%s.\n",produit[i].nomP);
          printf("CATEGORIE   :%s.\n",produit[i].categorie);
          printf("PRIX        :%.2f DH.\n",produit[i].prix);
          printf("STOCK       : %d.\n",produit[i].stock);
          printf("DESCRIPTION :%s.\n",produit[i].description);
          trouve =1;
          break;
        }
        
    }
    if(trouve != 1){
        printf("aucun produit avec cette nom .\n");
    }
}

void disponibilite(){
    int disponible =0;
    int nondisponible =0;
    for(int i=0 ;i<nbproduits;i++){
        if(produit[i].stock>0){
            disponible+=1;
        }else{
            nondisponible+=1;
        }
    }
    printf("Les produits disponible %d .\n",disponible);
    printf("Les produits non disponible %d .\n",nondisponible);
}

void tricroissant(){
    for(int i=0;i<nbproduits-1;i++){
        for(int j=0;j<nbproduits-i-1;j++){
            if(produit[j].prix>produit[j+1].prix){
                struct Produits croissant = produit[j];
                produit[j]=produit[j+1];
                produit[j+1] =croissant;
            }
        }
    }
     printf("Produits tries par prix croissant avec succes .\n");
     for(int i=0;i<nbproduits;i++){
        printf("==========================================\n");
        printf("ID          :%d.\n",produit[i].idproduit);
        printf("NOM         :%s.\n",produit[i].nomP);
        printf("CATEGORIE   :%s.\n",produit[i].categorie);
        printf("PRIX        :%.2f DH.\n",produit[i].prix);
        printf("STOCK       : %d.\n",produit[i].stock);
        printf("DESCRIPTION :%s.\n",produit[i].description);
        printf("==========================================\n");
     }
}


void tridecroissant(){
    for(int i=0;i<nbproduits-1;i++){
        for(int j=0;j<nbproduits-i-1;j++){
            if(produit[j].prix<produit[j+1].prix){
                struct Produits decroissant = produit[j];
                produit[j]=produit[j+1];
                produit[j+1]=decroissant;
            }
        }
    }
    printf("les produits ties par ordre decroissant avec succes .\n");
         for(int i=0;i<nbproduits;i++){
            printf("==========================================\n");
            printf("ID          :%d.\n",produit[i].idproduit);
            printf("NOM         :%s.\n",produit[i].nomP);
            printf("CATEGORIE   :%s.\n",produit[i].categorie);
            printf("PRIX        :%.2f DH.\n",produit[i].prix);
            printf("STOCK       : %d.\n",produit[i].stock);
            printf("DESCRIPTION :%s.\n",produit[i].description);
            printf("=========================================\n");

     }

}

void triparnom(){
    for(int i=0;i<nbproduits-1;i++){
        for(int j=0;j<nbproduits-i-1;j++){
            if(strcmp(produit[j].nomP,produit[j+1].nomP)>0){
                struct Produits croissantnom =produit[j];
                produit[j]=produit[j+1];
                produit[j+1]=croissantnom ;
            }
        }
    }
    printf("les produits tries par nom avec succes .\n");
    for(int i=0;i<nbproduits;i++){
          printf("=========================================\n");
          printf("ID          :%d.\n",produit[i].idproduit);
          printf("NOM         :%s.\n",produit[i].nomP);
          printf("CATEGORIE   :%s.\n",produit[i].categorie);
          printf("PRIX        :%.2f DH.\n",produit[i].prix);
          printf("STOCK       : %d.\n",produit[i].stock);
          printf("DESCRIPTION :%s.\n",produit[i].description);
          printf("=========================================\n");
     }
}


void detailproduit(){
    int nombre;
    int trouve =0;
    printf("entrer id de produits qui tu veux :");
    scanf("%d",&nombre);
    for(int i=0 ;i<nbproduits;i++){
        if(produit[i].idproduit == nombre){
          printf("=========================================\n");
          printf("ID          :%d.\n",produit[i].idproduit);
          printf("NOM         :%s.\n",produit[i].nomP);
          printf("CATEGORIE   :%s.\n",produit[i].categorie);
          printf("PRIX        :%.2f DH.\n",produit[i].prix);
          printf("STOCK       : %d.\n",produit[i].stock);
          printf("DESCRIPTION :%s.\n",produit[i].description);
          printf("=========================================\n");
          trouve = 1;
          break;
        }
    }
    if(trouve != 1){
        printf("aucun utilisateur avec cette id .\n");
    }
}
