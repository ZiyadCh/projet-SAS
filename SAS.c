#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char option;
int count = 20;

struct Animal {
  int id;
  char nom[50];
  char espece[50];
  int age;
  char habitat[50];
  float poids;
};

//****************************************************
//******* Ajouter *********************************
//******************************************************
struct Animal ajouter() {
  struct Animal p;
  printf("--------------------------------\n");
  printf("         Nouveau Animaux        \n");
  printf("--------------------------------\n");

  p.id = count;

  printf("-Entrer l'age:\n");
  scanf("%d", &p.age);
  printf("-Entrer le nom d'animaux:\n");
  scanf("%s", p.nom);
  p.nom[0] = toupper(p.nom[0]);
  printf("- Entrer l'espece d'animaux:\n");
  scanf("%s", p.espece);
  p.espece[0] = toupper(p.espece[0]);
  printf("- Selectionner l'habitat d'animaux:\n");
  scanf("%s", p.habitat);
  p.habitat[0] = toupper(p.habitat[0]);

  printf("-Entrer le poids d'animal:\n");
  scanf("%f", &p.poids);
  return p;
};

// aj plusierus
void ajp(struct Animal p[]) {
  int time;
  printf("--------------------------------\n");
  printf("Nombre d'animaux a ajouter:\n");
  scanf("%d", &time);
  for (int i = 0; i < time; i++) {
    printf("--------- Animal %d -----\n", i + 1);
    p[count] = ajouter();
    count++;
  }
};
//****************************************************
//******* AFFICHAGE ***********************************
//*************************************************

// afficher par ID
void affid(struct Animal p[]) {
  struct Animal tmp;

  // sort
  for (int i = 0; i < count; i++) {
    for (int j = 0; j < count - i - 1; j++) {
      if (p[j].id > p[j + 1].id) {
        tmp = p[j];
        p[j] = p[j + 1];
        p[j + 1] = tmp;
      }
    }
  }
  // display
  for (int i = 0; i < count; i++) {
    printf("|ID:       %d \n", p[i].id);
    printf("|Nom:      %s   \n", p[i].nom);
    printf("|Espece:   %s   \n", p[i].espece);
    printf("|Habitat:  %s   \n", p[i].habitat);
    printf("|Age:      %d   \n", p[i].age);
    printf("|Poids:    %.2fKg \n", p[i].poids);
    printf("|---------------------------|\n");
  }
}

// afficher par age
void affage(struct Animal p[]) {
  struct Animal tmp;

  // sort
  for (int i = 0; i < count; i++) {
    for (int j = 0; j < count - i - 1; j++) {
      if (p[j].age > p[j + 1].age) {
        tmp = p[j];
        p[j] = p[j + 1];
        p[j + 1] = tmp;
      }
    }
  }
  // display
  for (int i = 0; i < count; i++) {
    printf("|ID:       %d \n", p[i].id);
    printf("|Nom:      %s   \n", p[i].nom);
    printf("|Espece:   %s   \n", p[i].espece);
    printf("|Habitat:  %s   \n", p[i].habitat);
    printf("|Age:      %d   \n", p[i].age);
    printf("|Poids:    %.2fKg \n", p[i].poids);
    printf("|---------------------------|\n");
  }
}

// afficher par NOM

void affn(struct Animal p[]) {
  struct Animal tmp;

  // sort
  for (int i = 0; i < count; i++) {
    for (int j = 0; j < count - i - 1; j++) {
      if (strcmp(p[j].nom, p[j + 1].nom) > 0) {
        tmp = p[j];
        p[j] = p[j + 1];
        p[j + 1] = tmp;
      }
    }
  }
  // display
  for (int i = 0; i < count; i++) {
    printf("|ID:       %d \n", p[i].id);
    printf("|Nom:      %s   \n", p[i].nom);
    printf("|Espece:   %s   \n", p[i].espece);
    printf("|Habitat:  %s   \n", p[i].habitat);
    printf("|Age:      %d   \n", p[i].age);
    printf("|Poids:    %.2fKg \n", p[i].poids);
    printf("|---------------------------|\n");
  }
}

void affhabitat(struct Animal p[]){
  char hab[10];
  printf("+--------------------------------------------+\n");
  printf("|Entrer Habitat:                             |\n");
  scanf("%s",hab);
  hab[0] = toupper(hab[0]);
  for (int i =0;i<count;i++) {
    if (strcmp(hab,p[i].habitat) == 0) {
    printf("|ID:       %d \n", p[i].id);
    printf("|Nom:      %s   \n", p[i].nom);
    printf("|Espece:   %s   \n", p[i].espece);
    printf("|Habitat:  %s   \n", p[i].habitat);
    printf("|Age:      %d   \n", p[i].age);
    printf("|Poids:    %.2fKg \n", p[i].poids);
    printf("|---------------------------|\n");
 
    }
  }
}

void afficher(struct Animal p[]) {
  printf("+--------------------------------------------+\n");
  printf("|                    Afficher                |\n");
  printf("|--------------------------------------------|\n");
  printf("|1-Afficher par Id.                          |\n");
  printf("|2-Afficher par Nom.                         |\n");
  printf("|3-Afficher par age.                         |\n");
  printf("|4-Afficher les animaus d'un habitant.       |\n");
  printf("|--------------------------------------------|\n");
  printf("|Autre touche- retourner.                    |\n");
  printf("|--------------------------------------------|\n\n\n");

  scanf(" %c", &option);
  switch (option) {
  case '1':
    affid(p);
    break;
  case '2':
    affn(p);
    break;
  case '3':
    affage(p);
    break;
    case '4':
    affhabitat(p);
    break;
  default:
    system("clear");
    break;
  }
}

// 00000000000000MAIN000000000000000000
int main() {

  // AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA
  struct Animal animaux[200] = {
      {0, "Simba", "Lion", 5, "Savane", 190.5},
      {1, "Nala", "Lion", 4, "Savane", 175},
      {2, "ShereKhan", "Tigre", 8, "Jungle", 220.3},
      {3, "Baloo", "Ours", 12, "Foret", 310},
      {4, "Raja", "Elephant", 15, "Savane", 540.7},
      {5, "Marty", "Zebre", 6, "Savane", 300.2},
      {6, "Gloria", "Hippopotame", 10, "Riviere", 450},
      {7, "Alex", "Lion", 7, "Savane", 200},
      {8, "Julien", "Lemurien", 3, "Jungle", 12.5},
      {9, "Melman", "Girafe", 9, "Savane", 390.8},
      {10, "Timon", "Suricate", 2, "Desert", 1.2},
      {11, "Pumbaa", "Phacocheres", 5, "Savane", 120},
      {12, "Scar", "Lion", 11, "Savane", 210.4},
      {13, "Kaa", "Serpent", 6, "Jungle", 45},
      {14, "Iko", "Perroquet", 4, "Jungle", 2.1},
      {15, "Dumbo", "Elephant", 3, "Savane", 320},
      {16, "Kiki", "Chien sauvage", 7, "Savane", 25},
      {17, "Donatello", "Tortue", 40, "Riviere", 90.5},
      {18, "Polly", "Oiseau", 5, "Jungle", 1.5},
      {19, "Kong", "Gorille", 13, "Jungle", 180}};
  // AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA

  while (option != '7') {
    printf("+============================================+\n");
    printf("|                    ZOO                     |\n");
    printf("+============================================+\n");
    printf("|1-Ajouter un animaux.                       |\n");
    printf("|2-Ajouter plusieurs animaux.                |\n");
    printf("|3-Afficher les animaux.                     |\n");
    printf("|4-Modifier un animal.                       |\n");
    printf("|5-Rechercher un animal.                     |\n");
    printf("|6-Supprimer un animal.                      |\n");
    printf("|7-Quitter                                   |\n");
    printf("+============================================+\n");
    scanf(" %c", &option);
    system("clear");
    switch (option) {
    case '1': // AJOUTER------------------
      animaux[count] = ajouter();
      count++;
      break;
    case '2':
      ajp(animaux);
      break;
    case '3':
      afficher(animaux);
      break;
    case '4':
      break;
    case '5':
      break;
    case '6':
      break;
    case '7':
      printf("Au Revoir.\n");
      break;
    default:
      printf("Choisi un nombre entre 1-5!\n");
      break;
    }
  }

  return 0;
}
