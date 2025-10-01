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
    if (p[i].age > 20) {
      printf("|---------------------------|\n");
      printf("!!!! AGE CRITIQUE !!!!\n");
    }
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
    if (p[i].age > 20) {
      printf("|---------------------------|\n");
      printf("!!!! AGE CRITIQUE !!!!\n");
    }
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
    if (p[i].age > 20) {
      printf("|---------------------------|\n");
      printf("!!!! AGE CRITIQUE !!!!\n");
    }
    printf("|---------------------------|\n");
  }
}

// Afficher Habitat
void affhabitat(struct Animal p[]) {
  char hab[10];
  printf("+--------------------------------------------+\n");
  printf("|Entrer Habitat:                             |\n");
  scanf("%s", hab);
  hab[0] = toupper(hab[0]);
  for (int i = 0; i < count; i++) {
    if (strcmp(hab, p[i].habitat) == 0) {
      printf("|ID:       %d \n", p[i].id);
      printf("|Nom:      %s   \n", p[i].nom);
      printf("|Espece:   %s   \n", p[i].espece);
      printf("|Habitat:  %s   \n", p[i].habitat);
      printf("|Age:      %d   \n", p[i].age);
      printf("|Poids:    %.2fKg \n", p[i].poids);
      if (p[i].age > 20) {
        printf("|---------------------------|\n");
        printf("!!!! AGE CRITIQUE !!!!\n");
      }
      printf("|---------------------------|\n");
    }
  }
}

// Menu affichage
void afficher(struct Animal p[]) {
  printf("+--------------------------------------------+\n");
  printf("|                    Afficher                |\n");
  printf("|--------------------------------------------|\n");
  printf("|1-Afficher par Id.                          |\n");
  printf("|2-Afficher par Nom.                         |\n");
  printf("|3-Afficher par age.                         |\n");
  printf("|4-Afficher les animaus d'un habitant.       |\n");
  printf("|--------------------------------------------|\n");
  printf("|Autre touche pour retourner.                |\n");
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

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//+++++++++++Modifier++++++++++++++++++++++++++++++++++++++++++
// modifier AGe
void modage(struct Animal p[]) {
  int f;
  int exist = 0;

  printf("|     Entrer l'id l'animaux pour modifier l'age   |\n");
  printf("+-------------------------------------------------+\n");
  scanf("%d", &f);
  for (int i = 0; i < count; i++) {
    if (f == p[i].id) {
      printf("- Entrer nouveau age :\n");
      scanf("%d", &p[i].age);
      exist = 1;
    }
  }

  if (exist == 0) {
    printf("C'et animaux n'exist pas !!\n");
  }
}
// Modifier Habitat
void modhabit(struct Animal p[]) {
  int f;
  int exist = 0;

  printf("|  Entrer l'id l'animaux pour modifier l'habitat  |\n");
  printf("+-------------------------------------------------+\n");
  scanf("%d", &f);
  for (int i = 0; i < count; i++) {
    if (f == p[i].id) {
      printf("- Entrer Nouveau habitat d'animaux:\n");
      scanf("%s", p[i].habitat);
      p[i].habitat[0] = toupper(p[i].habitat[0]);
      exist = 1;
    }
  }
  if (exist == 0) {
    printf("C'et animaux n'exist pas !!\n");
  }
}

// Modifier
void modifier(struct Animal p[]) {

  printf("+--------------------------------------------+\n");
  printf("|                    Modifier                |\n");
  printf("|--------------------------------------------|\n");
  printf("|1-Modifier Age.                             |\n");
  printf("|2-Modifier Habitat.                         |\n");
  printf("|--------------------------------------------|\n");
  printf("|Autre touche pour retourner.                |\n");
  printf("|--------------------------------------------|\n\n\n");

  scanf(" %c", &option);
  switch (option) {
  case '1':
    modage(p);
    break;
  case '2':
    modhabit(p);
    break;
  default:
    system("clear");
    break;
  }
}

//------------------------------------------------------
//-------------------------------------------------------
// Search
// -----------------------------------------------------

// Search espece
void sespece(struct Animal p[]) {
  char f[10];
  int exist = 0;

  printf("| Entrer l'espece d'animaux |\n");
  printf("+---------------------------+\n");
  scanf("%s", f);
  f[0] = toupper(f[0]);
  for (int i = 0; i < count; i++) {
    if (strcmp(f, p[i].espece) == 0) {
      printf("|ID:       %d \n", p[i].id);
      printf("|Nom:      %s   \n", p[i].nom);
      printf("|Espece:   %s   \n", p[i].espece);
      printf("|Habitat:  %s   \n", p[i].habitat);
      printf("|Age:      %d   \n", p[i].age);
      printf("|Poids:    %.2fKg \n", p[i].poids);
      printf("|---------------------------|\n");
      exist = 1;
    }
  }
  if (exist == 0) {
    printf("C'et animaux n'exist pas !!\n");
  }
}

// Search Nom
void snom(struct Animal p[]) {
  char f[10];
  int exist = 0;

  printf("|  Entrer le nom  d'animaux |\n");
  printf("+---------------------------+\n");
  scanf("%s", f);
  f[0] = toupper(f[0]);
  for (int i = 0; i < count; i++) {
    if (strcmp(f, p[i].nom) == 0) {
      printf("|ID:       %d \n", p[i].id);
      printf("|Nom:      %s   \n", p[i].nom);
      printf("|Espece:   %s   \n", p[i].espece);
      printf("|Habitat:  %s   \n", p[i].habitat);
      printf("|Age:      %d   \n", p[i].age);
      printf("|Poids:    %.2fKg \n", p[i].poids);
      printf("|---------------------------|\n");
      exist = 1;
    }
  }
  if (exist == 0) {
    printf("C'et animaux n'exist pas !!\n");
  }
}
// Search id
void sid(struct Animal p[]) {
  int f;
  int exist = 0;

  printf("|  Entrer l'id d'animaux    |\n");
  printf("+---------------------------+\n");
  scanf("%d", &f);
  for (int i = 0; i < count; i++) {
    if (f == p[i].id) {

      printf("|ID:       %d \n", p[i].id);
      printf("|Nom:      %s   \n", p[i].nom);
      printf("|Espece:   %s   \n", p[i].espece);
      printf("|Habitat:  %s   \n", p[i].habitat);
      printf("|Age:      %d   \n", p[i].age);
      printf("|Poids:    %.2fKg \n", p[i].poids);
      printf("|---------------------------|\n");
      exist = 1;
    }
  }

  if (exist == 0) {
    printf("C'et animaux n'exist pas !!\n");
  }
}

// Menu Search
void chercher(struct Animal p[]) {
  printf("+--------------------------------------------+\n");
  printf("|                   Rechercher               |\n");
  printf("|--------------------------------------------|\n");
  printf("|1-Par Id.                                   |\n");
  printf("|2-Par nom.                                  |\n");
  printf("|3-Par espece.                               |\n");
  printf("|--------------------------------------------|\n");
  printf("|Autre touche pour retourner.                |\n");
  printf("|--------------------------------------------|\n\n\n");

  scanf(" %c", &option);
  switch (option) {
  case '1':
    sid(p);
    break;
  case '2':
    snom(p);
    break;
  case '3':
    sespece(p);
    break;
  default:
    system("clear");
    break;
  }
}

// XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXxxx
// XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXxxx
// Supprimer
// XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXxxx

void supp(struct Animal p[]) {
  int f;
  int exist = 0;

  printf("|  Entrer l'id d'animaux    |\n");
  printf("+---------------------------+\n");
  scanf("%d", &f);
  for (int j = 0; j < count; j++) {

    if (f == p[j].id) {

      for (int i = j; i < count - 1; i++) {
        p[i] = p[i + 1];
      }
      exist = 1;
    }
  }

  if (exist == 0) {
    printf("C'et animaux n'exist pas !!\n");
  }
}

// SSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSs

// moyen age
float moyage(struct Animal p[]) {
  float moyen = 0;
  for (int i = 0; i < count; i++) {
    moyen = p[i].age + moyen;
  }
  moyen = moyen / count;
  return moyen;
}

// min max
void jeune(struct Animal p[]) {
  int min = 90, max = 0;
  int mindex, maxdex;

  for (int i = 0; i < count; i++) {
    if (p[i].age < min) {
      min = p[i].age;
      mindex = p[i].id;
    }
  }

  for (int i = 0; i < count; i++) {
    if (p[i].age > max) {
      max = p[i].age;
      maxdex = p[i].id;
    }
  }

  system("clear");
  printf("|--------------------------------------------|\n");
  printf("|Le plus jeune d'animaux:                    \n");
  printf("|--------------------------------------------|\n\n\n");
  printf("|ID:       %d \n", p[mindex].id);
  printf("|Nom:      %s   \n", p[mindex].nom);
  printf("|Espece:   %s   \n", p[mindex].espece);
  printf("|Habitat:  %s   \n", p[mindex].habitat);
  printf("|Age:      %d   \n", p[mindex].age);
  printf("|Poids:   %.2fKg \n", p[mindex].poids);
  printf("|--------------------------------------------|\n");
  printf("|Le plus vieux d'animaux:                    \n");
  printf("|--------------------------------------------|\n\n\n");
  printf("|ID:       %d \n", p[maxdex].id);
  printf("|Nom:      %s   \n", p[maxdex].nom);
  printf("|Espece:   %s   \n", p[maxdex].espece);
  printf("|Habitat:  %s   \n", p[maxdex].habitat);
  printf("|Age:      %d   \n", p[maxdex].age);
  printf("|Poids:   %.2fKg \n", p[maxdex].poids);
}
// plus frequent espece
void frequent(struct Animal p[]) {
  int representations[count];
  int max = 0;
  for (int i = 0; i < count; i++) {
    representations[i] = 0;

    for (int j = 0; j < count; j++) {
      if (strcmp(p[j].espece,p[i].espece) == 0) {
        representations[i]++;
      }
    }
  
  }

  for (int i = 0;i<count;i++) {
   if (representations[i]>max) {
      max = representations[i];
    } 
  }

  printf("|--------------------------------------------|\n");
  printf("Le plus represente est: %d. \n",max);
  printf("|--------------------------------------------|\n");
}

// Stats menu
void stat(struct Animal p[]) {
  printf("+--------------------------------------------+\n");
  printf("|                  Statistiques              |\n");
  printf("|--------------------------------------------|\n");
  printf("|1-Nombre total d'animaux.                   |\n");
  printf("|2-Age Moyen des animaux.                    |\n");
  printf("|3-Plus vieux et plus jeune animaux.         |\n");
  printf("|4-L'animaux le plus represente.             |\n");
  printf("|--------------------------------------------|\n");
  printf("|Autre touche pour retourner.                |\n");
  printf("|--------------------------------------------|\n\n\n");

  scanf(" %c", &option);
  switch (option) {
  case '1':
    printf("|--------------------------------------------|\n");
    printf("|Nombre total des animaux %d                 |\n", count);
    printf("|--------------------------------------------|\n\n\n");
    break;
  case '2':
    printf("|--------------------------------------------|\n");
    printf("|L'age Moyen des animaux: %.2f |\n", moyage(p));
    printf("|--------------------------------------------|\n\n\n");
    break;
  case '3':
    jeune(p);
    break;
  case '4':
    frequent(p);
    break;
  default:
    system("clear");
    break;
  }
}

int main() {
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

  while (option != '8') {
    printf("+============================================+\n");
    printf("|                    ZOO                     |\n");
    printf("+============================================+\n");
    printf("|1-Ajouter un animaux.                       |\n");
    printf("|2-Ajouter plusieurs animaux.                |\n");
    printf("|3-Afficher les animaux.                     |\n");
    printf("|4-Modifier un animal.                       |\n");
    printf("|5-Rechercher un animal.                     |\n");
    printf("|6-Supprimer un animal.                      |\n");
    printf("|7-Statistiques.                             |\n");
    printf("|8-Quitter                                   |\n");
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
      modifier(animaux);
      break;
    case '5':
      chercher(animaux);
      break;
    case '6':
      supp(animaux);
      count--;
      break;
    case '7':
      stat(animaux);
      break;
    case '8':
      printf("Au Revoir.\n");
      break;
    default:
      printf("Choisi un nombre entre 1-5!\n");
      break;
    }
  }

  return 0;
}
