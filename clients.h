#ifndef CLIENT_H
#define CLIENT_H

struct clients {
    int id;
    char nom[50];
    char prenom[50];
    char email[100];
    float solde;
};

extern struct clients client[1];

struct Historiques {
    char produit[100];
    float prix;
};

extern struct Historiques historique[100];
extern int nbhistorique;

void ajoutclient();
void afficherclient();
void modificationclient();
void affichesolde();
void Alimentationsolde();
void acheter();
void historiquedetail();

#endif
