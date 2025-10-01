#ifndef PRODUITS_H
#define PRODUITS_H


struct Produits {
    int idproduit ;
    char nomP[50];
    char categorie[50];
    float prix;
    int stock ;
    char description[100];
};
extern struct Produits produit[10];
extern int nbproduits;

void afficherProduits();
void Rechercheparnom();
void disponibilite();
void tricroissant();
void tridecroissant();
void triparnom();
void detailproduit();











#endif