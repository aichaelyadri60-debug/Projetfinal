#include <stdio.h>
#include <string.h>



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
    printf("ID          :%d.\n",client[0].id);
    printf("NOM         :%s.\n",client[0].nom);
    printf("PRENOM      :%s.\n",client[0].prenom);
    printf("email       :%s\n",client[0].email);
    printf("SOLDE       :%.2f.\n",client[0].solde);
}
void modificationclient(){
    printf("Entrer nom :");
    scanf(" %[^\n]",client[0].nom);
    printf("Entrer prenom de :");
    scanf(" %[^\n]",client[0].prenom);
    sprintf(client[0].email,"%s.%s@gmail.com",client[0].prenom ,client[0].nom);
}

void affichesolde(){
    printf("le client :%s %s",client[0].nom ,client[0].prenom);
    printf("le solde disponible est : %.2f  .",client[0].solde);
}


void Alimentationsolde(){
    float Montant ;
    printf("entrer la valeur qui tu veux verser :");
    scanf("%f",&Montant);
    if(Montant>0){
        client[0].solde +=Montant;
        printf("Montant ajouter avec succes nouveau solde est %.2f \n.",client[0].solde);
    }else{
        printf("Montant invalide.\n");
    }
}


void acheter(){
    char nom[50];
    int trouve =0;
    printf("entrer le nom de produit qui tu veux acheter :");
    scanf(" %[^\n]",nom);
    for(int i=0;i<nbproduits;i++){
        if(strcmp(produit[i].nomP , nom)==0){
            trouve =1;
            if(produit[i].stock>0){
                if(client[0].solde >=produit[i].prix){
                    client[0].solde -=produit[i].prix ;
                    produit[i].stock --;
                    strcpy(historique[nbhistorique].produit ,produit[i].nomP);
                    historique[nbhistorique].prix =produit[i].prix;
                    nbhistorique++;
                    printf("achat avec succes .\n");

                }else{
                    printf("prix et superieur a votre solde .\n");
                }
            }else{
                printf("le stock de cette produit et zero .\n");
            }
            break;
        }   
    }
    if(trouve != 1){
        printf("aucun produit avec cette nom .\n");
    }
}