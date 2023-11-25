/* Projet d'algorithmique et programmation avec C 
Réalisé par GADO Seman Giovanni & DIOP Ousseynou
Professeur : M. CISSE */





#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Projet_SYSTEME_DE_GESTION_DE_REPERTOIRE_GADO_DIOP.h"



int main(int argc, char *argv[])
{
    system("color F0");
    do
    {
        printf("\n\n");
        printf(" =============================================\n");
        printf(" |            Repertoire du telephone        | \n");
        printf(" =============================================\n\n");
        printf("  Total des contacts : %d\n\n", n);
        printf("----------------------------------------------\n\n");
        printf("      1.  Enregistrer nouveau contact\n");
        printf("      2.  Modifier un contact\n");
        printf("      3.  Afficher les contacts \n");
        printf("      4.  Rechercher un contact par numero \n");
        printf("      5.  Rechercher un contact par nom \n");
        printf("      6.  Rechercher un contact par prenom\n");
        printf("      7.  Bloquer un contact \n");
        printf("      8.  Afficher les contacts bloques\n");
        printf("      9.  Supprimer un contact \n");
        printf("     10.  Urgence \n");
        printf("     11.  Quitter le repertoire \n\n\n");
        printf(" =============================================\n\n");
        printf("Veuillez choisir votre option : ");
        scanf("%d", &option);
        printf("\n\n");
        switch (option)
        {
        case 1:
            system("cls");
            nouveau_repertoire();
            break;
        case 2:
            system("cls");
            modifier_ctct();
            break;
        case 3:
            system("cls");
            list_rep();
            break;
        case 4:
            system("cls");
            recherche_par_numero();
            break;
        case 5:
            system("cls");
            recherche_par_nom();
            break;
        case 6:
            system("cls");
            recherche_par_prenom();
            break;
        case 7:
            system("cls");
            bloquer();
            break;
        case 8:
            system("cls");
            afficher_ctct_bloquer();
            break;
        case 9:
            system("cls");
            supprimer();
            break;
        case 10:
            system("cls");
            urgence();
            break;
        case 11:
            system("cls");
            quitter();
            printf("Merci d'avoir utilise notre repertoire. Au revoir !\n\n");
            break;
        default:
            system("cls");
            printf("Oups, option non valide !\n");
        }

    } while (option != 11);

    system("PAUSE");
    return 0;
}