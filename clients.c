#include <stdio.h>
#include <string.h>
#include "clients.h"
#include "produits.h"

struct clients client[1];
struct Historiques historique[100];
int nbhistorique = 0;

void ajoutclient(){
    client[0].id=1;
    printf("entrer le nom de cette client :");
    scanf(" %[^\n]",client[0].nom);
    printf("entrer prenom de cette client :");
    scanf(" %[^\n]",client[0].prenom);
    client[0].solde=0.0;
    sprintf(client[0].email,"%s.%s@gmail.com",client[0].prenom ,client[0].nom);
    printf("client ajouter avec succes\n");
}
void afficherclient(){
    printf("=========================================\n");
    printf("ID          :%d.\n",client[0].id);
    printf("NOM         :%s.\n",client[0].nom);
    printf("PRENOM      :%s.\n",client[0].prenom);
    printf("email       :%s\n",client[0].email);
    printf("SOLDE       :%.2f.\n",client[0].solde);
    printf("=========================================\n");
}
void modificationclient(){
    printf("Entrer nom :");
    scanf(" %[^\n]",client[0].nom);
    printf("Entrer prenom de :");
    scanf(" %[^\n]",client[0].prenom);
    sprintf(client[0].email,"%s.%s@gmail.com",client[0].prenom ,client[0].nom);
}

void affichesolde(){
    if(client[0].id<1){
        printf("aucun client enregistrer .\n");
    }else{
        printf("=========================================\n");
        printf("le client :%s %s\n",client[0].nom ,client[0].prenom);
        printf("le solde disponible est : %.2f  .\n",client[0].solde);
        printf("=========================================\n");

    }
}


void Alimentationsolde(){
    float Montant ;
    if(client[0].id<1){
        printf("aucun client enregistrer .\n");
    }else{
        printf("entrer la valeur qui tu veux verser :");
        scanf("%f",&Montant);
        if(Montant>0){
            client[0].solde +=Montant;
            printf("Montant ajouter avec succes nouveau solde est %.2f \n",client[0].solde);
        }else{
            printf("Montant invalide\n");
        }
    }
}

void acheter(){
    char nom[50];
    int quantite ;
    int trouve =0;
    if(client[0].id<1){
        printf("aucun client enregistrer .\n");
    }else{
        printf("entrer le nom de produit qui tu veux acheter :");
        scanf(" %[^\n]",nom);
        printf("quanbien des produits tu veux :");
        scanf("%d",&quantite);
        for(int i=0;i<nbproduits;i++){
            if(strcmp(produit[i].nomP , nom)==0){
                trouve =1;
                if(produit[i].stock >= quantite){
                    float prixtotal =produit[i].prix * quantite;
                    if(client[0].solde >=produit[i].prix * quantite){
                        client[0].solde -= prixtotal ;
                        produit[i].stock -= quantite;
                        strcpy(historique[nbhistorique].produit ,produit[i].nomP);
                        historique[nbhistorique].prix =prixtotal;
                        nbhistorique++;
                        printf("achat avec succes .\n");
    
                    }else{
                        printf("prix et superieur a votre solde .\n");
                    }
                }else{
                    printf("la quantite qui tu veux et superieur a stock tu peux acheter %d.\n",produit[i].stock);
                }
                break;
            }   
        }
        if(trouve != 1){
            printf("aucun produit avec cette nom .\n");
        }

    }
}

void historiquedetail(){
    float totale =0;
    if(nbhistorique <=0 ){
        printf("aucun achat effectue .\n");
    }else{
        for(int i=0;i<nbhistorique;i++){
            printf("-----------------achat :  %d -------------------------\n",i+1);
            printf("le nom de produits est :%s\n",historique[i].produit);
            printf("le prix de cette produit est %.2f .\n",historique[i].prix);
            printf("-------------------------------------------------------\n");
            totale +=historique[i].prix;
        } 
        printf("totale des achats :%.2f\n",totale);  
    }
}

