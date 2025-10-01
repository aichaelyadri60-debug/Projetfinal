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

struct Historiques{
    char produit[100];
    float prix ;

};
struct Historiques historique[100];
int nbhistorique =0;




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

void historiquedetail(){
    if(nbhistorique <=0 ){
        printf("aucun achat effectue .\n");
    }else{
        for(int i=0;i<nbhistorique;i++){
            printf("-----------------achat :  %d -------------------------\n",i+1);
            printf("le nom de produits est :%s\n",historique[i].produit);
            printf("le prix de cette produit est %.2f .\n",historique[i].prix);
            printf("-------------------------------------------------------\n");
        } 
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
        printf("==========================================");
        printf("ID          :%d.\n",produit[i].idproduit);
        printf("NOM         :%s.\n",produit[i].nomP);
        printf("CATEGORIE   :%s.\n",produit[i].categorie);
        printf("PRIX        :%.2f DH.\n",produit[i].prix);
        printf("STOCK       : %d.\n",produit[i].stock);
        printf("DESCRIPTION :%s.\n",produit[i].description);
        printf("==========================================");
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
            printf("==========================================");
            printf("ID          :%d.\n",produit[i].idproduit);
            printf("NOM         :%s.\n",produit[i].nomP);
            printf("CATEGORIE   :%s.\n",produit[i].categorie);
            printf("PRIX        :%.2f DH.\n",produit[i].prix);
            printf("STOCK       : %d.\n",produit[i].stock);
            printf("DESCRIPTION :%s.\n",produit[i].description);
            printf("=========================================");

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
          printf("=========================================");
          printf("ID          :%d.\n",produit[i].idproduit);
          printf("NOM         :%s.\n",produit[i].nomP);
          printf("CATEGORIE   :%s.\n",produit[i].categorie);
          printf("PRIX        :%.2f DH.\n",produit[i].prix);
          printf("STOCK       : %d.\n",produit[i].stock);
          printf("DESCRIPTION :%s.\n",produit[i].description);
          printf("=========================================");
     }
}


void detailproduit(){
    int nombre;
    int trouve =0;
    printf("entrer id de produits qui tu veux :");
    scanf("%d",&nombre);
    for(int i=0 ;i<nbproduits;i++){
        if(produit[i].idproduit == nombre){
          printf("=========================================");
          printf("ID          :%d.\n",produit[i].idproduit);
          printf("NOM         :%s.\n",produit[i].nomP);
          printf("CATEGORIE   :%s.\n",produit[i].categorie);
          printf("PRIX        :%.2f DH.\n",produit[i].prix);
          printf("STOCK       : %d.\n",produit[i].stock);
          printf("DESCRIPTION :%s.\n",produit[i].description);
          printf("=========================================");
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

int main(){
    int choix;
    int choix1;
    int choix2;
    int choix3;
    int choix4;
    do{
        printf("====== SYSTÈME D'ACHAT CLIENT ======\n");
        printf("1. 👤 Gestion du profil client \n");
        printf("2. 💰 Gestion du solde virtuel\n");
        printf("3. 🏪 Consultation des produits\n");
        printf("4. 🛒 Effectuer un achat\n");
        printf("5. 📊 Mes statistiques\n");
        printf("0. 🚪 Quitter l'application\n");
        printf("Votre choix :");
        scanf("%d",&choix);
        printf("====================================\n");
    
        switch (choix)
        {
        case 1:
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
    
        case 2: 
        do {
            printf("======= GESTION DE SOLDE VIRTUEL :======\n");
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
    
    
        case 3:
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
        case 4: acheter();break;
        case 5: 
        do{
            printf("======= MES STATISTIQUES :======\n");
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
    
        case 0:printf("Au revoir .\n"); break;
        
        
        default:printf("cette nombre et ne pas dans le menu ");
        }
    }while(choix != 0);

}




// menu_service.c
// typedef void (*Callback)(void);

// char menu_title[50];
// char menu_options[20][50];
// Callback menu_callbacks[20];
// int i = 0;

// void generate_title(char title[50])
// {
//     strcpy(menu_title, title);
// }

// void generate_new_line(char option[50], void (*callback)(void)){
//     strcpy(menu_options[i], option);
//     menu_callbacks[i] = callback;
//     i++;
// }

// void dispatch(){
//     printf("===  %s  ===",menu_title);
//     printf("============================");

//     for (int j = 0; j < i; j++)
//     {
//         printf("%d. %s", j+1, menu_options[i]);
//     }
//     int choix;
//     printf("entrer un choix : ");
//     scanf("%d", &choix);

//     menu_callbacks[choix-1]();
// }

// int main(){
    // generate_title("dazdazdazdaz");
    // generate_new_line("ajoute un client", createClient);
    // generate_new_line("modifier  le client", updateClient);
    // generate_new_line("modifier  le client", updateClient);
    // generate_new_line("modifier  le client", updateClient);
    // generate_new_line("modifier  le client", updateClient);

    // dispatch();



    // ajoutclient();
    // afficherclient();
    // modificationclient();
    // afficherclient();




//     disponibilite();


// }






