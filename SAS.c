#include <stdio.h>
#include <stdlib.h>

struct Animal
{
    int id;
    char nom[50];
    char espece[50];
    int age;
    char habitat[50];
    float poids;
};

struct Animal ajouter()
{
    struct Animal p;
    printf("--------------------------------\n");
    printf("         Nouveau Animaux        \n");
    printf("--------------------------------\n");
    printf("-Entrer l'age:\n");
    scanf("%d", &p.age);
    printf("-Entrer le nom d'animaux:\n");
    scanf("%s", p.nom);
    return p;
};

void afficher(struct Animal p[], int count){
     for (int i = 0; i < count; i++)
    {
        printf("|ID:  %d \n",p[i].id);
        printf("|Nom: %s \n",p[i].nom);
        printf("|Espece: %s \n",p[i].espece);
        printf("|Age:    %d \n",p[i].age);
        printf("|Age:    %fKg \n",p[i].poids);
        printf("---------------------------\n");
    }
}

int main()
{
    struct Animal animaux[] = {
        {0, "Simba", "Lion", 5, "Savane", 190.5},
        {1, "Nala", "Lion", 4, "Savane", 175},
        {2, "ShereKhan", "Tigre", 8, "Jungle", 220.3},
        {3, "Baloo", "Ours", 12, "Forêt", 310},
        {4, "Raja", "Éléphant", 15, "Savane", 540.7},
        {5, "Marty", "Zèbre", 6, "Savane", 300.2},
        {6, "Gloria", "Hippopotame", 10, "Rivière", 450},
        {7, "Alex", "Lion", 7, "Savane", 200},
        {8, "Julien", "Lémurien", 3, "Jungle", 12.5},
        {9, "Melman", "Girafe", 9, "Savane", 390.8},
        {10, "Timon", "Suricate", 2, "Désert", 1.2},
        {11, "Pumbaa", "Phacochère", 5, "Savane", 120},
        {12, "Scar", "Lion", 11, "Savane", 210.4},
        {13, "Kaa", "Serpent", 6, "Jungle", 45},
        {14, "Iko", "Perroquet", 4, "Jungle", 2.1},
        {15, "Dumbo", "Éléphant", 3, "Savane", 320},
        {16, "Kiki", "Chien sauvage", 7, "Savane", 25},
        {17, "Donatello", "Tortue", 40, "Rivière", 90.5},
        {18, "Polly", "Oiseau", 5, "Jungle", 1.5},
        {19, "Kong", "Gorille", 13, "Jungle", 180}};

    char option;
    int count = 20;

    while (option != '6')
    {
        printf("+============================================+\n");
        printf("|                    ZOO                     |\n");
        printf("+============================================+\n");
        printf("|1-Ajouter un animaux                        |\n");
        printf("|2-Afficher les animaux                      |\n");
        printf("|3-Modifier un animal.                       |\n");
        printf("|4-Rechercher un animal.                     |\n");
        printf("|5-Supprimer un animal.                      |\n");
        printf("|6-Quitter                                   |\n");
        printf("+============================================+\n");
        scanf("%s", &option);
        system("cls");
        switch (option)
        {
        case '1': // AJOUTER------------------
            animaux[count] = ajouter();
            break;
        case '2': // AFFICHER---------------
            afficher(animaux,count);
            break;
        case '3': // modifier-----------
            break;
        case '4': // SUPPRIMER =-=======================
            break;
        case '5': // RECHERCHER=========================
            break;
        case '6':
            printf("Au Revoir.\n");
            break;
        case '7':
            break;
        default:
            printf("Choisi un nombre entre 1-5!\n");
            break;
        }
    }

    return 0;
}
