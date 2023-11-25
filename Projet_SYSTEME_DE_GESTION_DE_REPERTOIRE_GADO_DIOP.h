
// Ici se trouvent toutes les fonctions créées. Nous pouvons entre autres enregistrer un contact, modifier un contact, afficher la liste des contacts, rechercher un contact,//
//par son numéro, son nom ou son prénom ; bloquer un contact, afficher les contacts bloques, supprimer un contact, lancer un appel dd'urgence ou quitter le repertoire.



// Nous allons d'abord importer les bibliothèques dont nous aurons besoin.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define rep_max 150

// Declaration des variables hors fonctions
int i, b = 0, n = 0, option;

// Création de la structure principale du repertoire
struct repertoire
{
    int numero;
    char nom[30], prenom[30], adresse[30], profession[30], email[30];
};

// Création de la structure des contacts bloqués
struct bloquer
{
    int numero_bc;
    char nom_bc[30], prenom_bc[30], adresse_bc[30], profession_bc[30], email_bc[30];
};


// Nous allons à présent créer des tableaux de structures principale et des contacts bloqués afin de regrouper les informations des individus
struct repertoire gestion_rep[rep_max];
struct bloquer bloque_num[rep_max];


// Une petite précision : les caractères ne doivent pas comporter des espaces sous peine de dysfonctionnement des codes.

// Fonction pour ajouter un nouveau contact
void nouveau_repertoire()
{
    printf("\n\n");
    printf("Enregister nouveau contact  \n\n\n");

    printf("Numero de telephone : ");
    scanf("%d", &gestion_rep[n].numero);

    for (i = 0; i < n; i++)
    {
        if (gestion_rep[i].numero == gestion_rep[n].numero)
        {
            do
            {
                printf("Ce numero est deja enregistre, veuillez saisir un nouveau numero s'il vous plait !\n");
                printf("Numero de telephone : ");
                scanf("%d", &gestion_rep[n].numero);
            } while (gestion_rep[i].numero == gestion_rep[n].numero);
        }
    }

    printf("Nom : ");
    scanf("%s", gestion_rep[n].nom);
    printf("Prenom: ");
    scanf("%s", gestion_rep[n].prenom);

    for (i = 0; i < n; i++)
    {
        if (strcmp(gestion_rep[i].nom, gestion_rep[n].nom) == 0 && strcmp(gestion_rep[i].prenom, gestion_rep[n].prenom) == 0)
        // La fonction strcmp permet de comparer des chaînes de caractères. Si les chaînes sont identiques, elle renvoie 0.
        {
            do
            {
                printf("Cette personne existe deja dans votre repertoire.\n");
                printf("Veuillez changer le nom ou le prenom.\n\n");
                printf("Nom : ");
                scanf("%s", gestion_rep[n].nom);
                printf("Prenom: ");
                scanf("%s", gestion_rep[n].prenom);
            } while (strcmp(gestion_rep[i].nom, gestion_rep[n].nom) == 0 && strcmp(gestion_rep[i].prenom, gestion_rep[n].prenom) == 0);
        }
    }

    printf("Adresse: ");
    scanf("%s", gestion_rep[n].adresse);
    printf("Profession : ");
    scanf("%s", gestion_rep[n].profession);
    printf("E-mail : ");
    scanf("%s", gestion_rep[n].email);
    for (i = 0; i < n; i++)
    {
        if (strcmp(gestion_rep[i].email, gestion_rep[n].email) == 0 )
        {
            do
            {
                printf("Ce mail existe deja dans votre repertoire.\n");
                printf("Veuillez changer le mail.\n\n");
                printf("E-mail : ");
                scanf("%s", gestion_rep[n].email);

            } while (strcmp(gestion_rep[i].email, gestion_rep[n].email) == 0 );
        }
    }

    n = n + 1;
    printf("\nContact ajoute avec succes !\n\n");
    printf("\n\n");
}




// Fonction pour modifier un contact
void modifier_ctct()
{
    printf("Modification du contact");
    int k=-1;
    char nom_mod[30], prenom_mod[30];
    printf("Veuillez saisir le nom du contact a modifier.\n");
    scanf("%s", nom_mod);
    printf("Veuillez saisir le prenom du contact a modifier.\n");
    scanf("%s", prenom_mod);

    for (i = 0; i < n; i++)
    {
        if (strcmp(gestion_rep[i].nom, nom_mod) == 0 && strcmp(gestion_rep[i].prenom, prenom_mod) == 0)
        {
            k = i;
        }
    }
    if (k != -1)
    {
        printf("\n\n");
        printf("Modifier le contact de %s %s :  \n\n", gestion_rep[k].nom,gestion_rep[k].prenom);
        printf("Numero de telephone : ");
        scanf("%d", &gestion_rep[k].numero);
        printf("Nom : ");
        scanf("%s", gestion_rep[k].nom);
        printf("Prenom : ");
        scanf("%s", gestion_rep[k].prenom);
        printf("Adresse : ");
        scanf("%s", gestion_rep[k].adresse);
        printf("Profession : ");
        scanf("%s", gestion_rep[k].profession);
        printf("E-mail : ");
        scanf("%s", gestion_rep[k].email);
        printf("Contact bien modifie.\n\n");
        printf("\n\n");
    }
    else
    {
        printf("Cette personne n'existe pas dans le repertoire.\n\n");
    }
}



// Fonction pour rechercher un contact par son numéro
void recherche_par_numero()
{
    printf("Les resultats de la recherche");
    int k=-1;
    int num_tel;
    printf("Veuillez saisir le numero du contact recherche.\n");
    scanf("%d", &num_tel);
    for (i = 0; i < n; i++)
    {
        if (gestion_rep[i].numero == num_tel)
        {
            k = i;
    printf("Contact de : %s %s \n\n", gestion_rep[k].nom, gestion_rep[k].prenom);
    printf("Numero : %d \n", gestion_rep[k].numero);
    printf("Adresse : %s \n", gestion_rep[k].adresse);
    printf("Profession : %s \n", gestion_rep[k].profession);
    printf("E-mail : %s \n", gestion_rep[k].email);
        }
    }
    if (k==-1){
    printf("Desole, ce numero n'a pas ete trouve !");
    }    
}



// Fonction pour rechercher un contact par son nom de famille (nom du père)
void recherche_par_nom()
{
    printf("Les resultats de la recherche");
    int k=-1;
    char nom_rch[30];
    printf("Veuillez saisir le nom du contact recherche.\n");
    scanf("%s", nom_rch);
    for (i = 0; i < n; i++)
    {
        if (strcmp(gestion_rep[i].nom, nom_rch) == 0)
        {
            k = i;
    printf("Contact de : %s %s \n\n", gestion_rep[k].nom, gestion_rep[k].prenom);
    printf("Numero : %d \n", gestion_rep[k].numero);
    printf("Adresse : %s \n", gestion_rep[k].adresse);
    printf("Profession : %s \n", gestion_rep[k].profession);
    printf("E-mail : %s \n", gestion_rep[k].email);
    printf("----------------------------------------------\n");
        }
    }
    if (k==-1)
    {
        printf("Desole, ce nom n'a pas ete trouve !");
    }    
} 



// Fonction pour rechercher un contact par son prénom
void recherche_par_prenom()
{
    printf("Les resultats de la recherche");
    int k=-1;
    char prenom_rch[30];
    printf("Veuillez saisir le prenom du contact recherche.\n");
    scanf("%s", prenom_rch);
    for (i = 0; i < n; i++)
    {
        if (strcmp(gestion_rep[i].prenom, prenom_rch) == 0)
        {
            k = i;
    printf("Contact de : %s %s \n\n", gestion_rep[k].nom, gestion_rep[k].prenom);
    printf("Numero : %d \n", gestion_rep[k].numero);
    printf("Adresse : %s \n", gestion_rep[k].adresse);
    printf("Profession : %s \n", gestion_rep[k].profession);
    printf("E-mail : %s \n", gestion_rep[k].email);
    printf("----------------------------------------------\n");
        }
    }
    if (k==-1){
    printf("Desole, ce numero n'a pas ete trouve !");
    }        
}



// Fonction pour afficher la liste des contacts
void list_rep()
{
    int i;
    for (i = 0; i < n; i++)
    {
        printf("Liste des contacts\n");
        printf(" Nom : %s \n Prenom : %s \n Numero : %d \n Adresse : %s\n Profession : %s \n E-mail : %s \n---------------------------------------------\n", gestion_rep[i].nom, gestion_rep[i].prenom, gestion_rep[i].numero, gestion_rep[i].adresse, gestion_rep[i].profession, gestion_rep[i].email);
    }
}


// Fonction pour afficher les numéros d'urgence
void urgence()
{
    printf("Sapeurs Pompiers : 18 \n");
    printf("Police Nationale: 17 \n");
    printf("SAMU : 1515 \n");
}



// Fonction pour bloquer les contacts voulus
void bloquer()
{
    printf("Les contacts bloques:\n");
    int k=-1;
    char nom_bloquer[30], prenom_bloquer[30];
    printf("Veuillez saisir le nom du contact que vous voulez bloquer : \n");
    scanf("%s", nom_bloquer);
    printf("Veuillez saisir le prenom du contact que vous voulez bloquer : \n");
    scanf("%s", prenom_bloquer);
    for (i = 0; i < n; i++)
    {
        if (strcmp(gestion_rep[i].nom, nom_bloquer) == 0 && strcmp(gestion_rep[i].prenom, prenom_bloquer) == 0)
        {
            k = i;
            bloque_num[b].numero_bc = gestion_rep[k].numero;
            strcpy(bloque_num[b].nom_bc, gestion_rep[k].nom);
            strcpy(bloque_num[b].prenom_bc, gestion_rep[k].prenom);
            strcpy(bloque_num[b].adresse_bc, gestion_rep[k].adresse);
            strcpy(bloque_num[b].profession_bc, gestion_rep[k].profession);
            strcpy(bloque_num[b].email_bc, gestion_rep[k].email);
            b = b + 1;
            printf("contact bloque !\n\n");
            return;
        }
    }
    if (k=-1)
    {
        printf("Ce numero n'existe pas dans le repertoire.\n\n");
        return;
    }
}



// Fonction pour afficher les contacts bloqués
void afficher_ctct_bloquer()
{
    int i;
    for (i = 0; i < b; i++)
    {
        printf("Les contacts bloques:\n");
        printf(" Nom : %s \n Prenom : %s \n Numero : %d \n Adresse : %s\n Profession : %s \n E-mail : %s \n---------------------------------------------\n", bloque_num[i].nom_bc, bloque_num[i].prenom_bc, bloque_num[i].numero_bc, bloque_num[i].adresse_bc, bloque_num[i].profession_bc, bloque_num[i].email_bc);
    }
}





// Fonction pour supprimer les contacts voulus
void supprimer()
{
    int j, k;
    char nom_sup[30], prenom_sup[30];
    printf("Veuillez saisir le nom du contact que vous voulez supprimer:\n ");
    scanf("%s", nom_sup);
    printf("Veuillez saisir le prenom du contact que vous voulez supprimer:\n ");
    scanf("%s", prenom_sup);
    for (k = 0; k < n; k++)
    {
        if (strcmp(gestion_rep[k].nom, nom_sup) == 0 && strcmp(gestion_rep[k].prenom, prenom_sup) == 0)
        {
            for (j = k; j < n - 1; j++)
            {
                gestion_rep[j] = gestion_rep[j + 1];
            }   
            n = n - 1;
            printf("Le contact a ete supprime avec succes.\n");
            return;
            // Ce code permetttra de décaler tous les contacts après celui supprimer ves le haut
        }
    }
    printf("Le contact n'a pas ete trouve dans le repertoire.\n");
}


// Fontion pour fermer le répertoire
void quitter()
{
    system("cls");
}
