#include <stdio.h>
#include <string.h>


struct clients{
    int id;
    char nom[50];
    char prenom[50];
    char email[100];
    float solde ;
};
struct clients client[1];


struct Produits {
    int idproduit ;
    char nomP[50];
    char categorie[50];
    float prix;
    int stock ;
    char description[100];
};



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
          printf("ID          :%d.\n",produit[i].idproduit);
          printf("NOM         :%s.\n",produit[i].nomP);
          printf("CATEGORIE   :%s.\n",produit[i].categorie);
          printf("PRIX        :%.2f DH.\n",produit[i].prix);
          printf("STOCK       : %d.\n",produit[i].stock);
          printf("DESCRIPTION :%s.\n",produit[i].description);
     }
}


void tridecroissant(){
    for(int i=0;i<nbproduits-1;i++){
        for(int j=0;j<nbproduits-i-1;j++){
            if(produit[j].prix<produit[j+1].prix){
                struct Produits decroissant = produit[j];
                produit[j+1]=produit[j];
                produit[j+1]=decroissant;
            }
        }
    }
    printf("les produits ties par ordre decroissant avec succes .\n");
         for(int i=0;i<nbproduits;i++){
          printf("ID          :%d.\n",produit[i].idproduit);
          printf("NOM         :%s.\n",produit[i].nomP);
          printf("CATEGORIE   :%s.\n",produit[i].categorie);
          printf("PRIX        :%.2f DH.\n",produit[i].prix);
          printf("STOCK       : %d.\n",produit[i].stock);
          printf("DESCRIPTION :%s.\n",produit[i].description);
     }

}



void triparnom(){
    for(int i=0;i<nbproduits-1;i++){
        for(int j=0;j<nbproduits-i-1;j++){
            if(strcmp(produit[j].nomP,produit[j+1].nomP)>0){
                struct Produits croissantnom =produit[j];
                produit[j]=produit[j+1];
                croissantnom =produit[j+1];
            }
        }
    }
    printf("les produits tries par nom avec succes .\n");
    for(int i=0;i<nbproduits;i++){
          printf("ID          :%d.\n",produit[i].idproduit);
          printf("NOM         :%s.\n",produit[i].nomP);
          printf("CATEGORIE   :%s.\n",produit[i].categorie);
          printf("PRIX        :%.2f DH.\n",produit[i].prix);
          printf("STOCK       : %d.\n",produit[i].stock);
          printf("DESCRIPTION :%s.\n",produit[i].description);
     }
}


void rechercheparid(){
    int nombre;
    int trouve =0;
    printf("entrer id de produits qui tu veux :");
    scanf("%d",&nombre);
    for(int i=0 ;i<nbproduits;i++){
        if(produit[i].idproduit == nombre){
          printf("ID          :%d.\n",produit[i].idproduit);
          printf("NOM         :%s.\n",produit[i].nomP);
          printf("CATEGORIE   :%s.\n",produit[i].categorie);
          printf("PRIX        :%.2f DH.\n",produit[i].prix);
          printf("STOCK       : %d.\n",produit[i].stock);
          printf("DESCRIPTION :%s.\n",produit[i].description);
          trouve = 1;
          break;
        }
    }
    if(trouve != 1){
        printf("aucun utilisateur avec cette id .\n");
    }
}




void ajoutclient(){
    client[0].id=1;
    printf("entrer le nom de cette client :");
    scanf(" %[^\n]",client[0].nom);
    printf("entrer prenom de cette client :");
    scanf(" %[^\n]",client[0].prenom);
    client[0].solde=0.0;
    printf("client ajouter avec succes\n");
}
void afficherclient(){
    printf("ID          :%d.\n",client[0].id);
    printf("NOM         :%s.\n",client[0].nom);
    printf("PRENOM      :%s.\n",client[0].prenom);
    printf("email       :%s.%s@gmail.com.\n",client[0].prenom ,client[0].nom);
    printf("SOLDE       :%d.\n",client[0].solde);
}
void modificationclient(){
printf("Entrer nom :");
scanf(" %[^\n]",client[0].nom);
printf("Entrer prenom de :");
scanf(" %[^\n]",client[0].prenom);
}





int main(){


}






