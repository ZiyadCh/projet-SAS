
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char option;
int count = 20;
int mid = 21;

struct Animal {
  int id;
  char nom[50];
  char espece[50];
  int age;
  char habitat[50];
  float poids;
};

//-------------------------------------------
//----------------------------------------
//----------------------------------------
struct Animal ajouter() {
  struct Animal p;

  p.id = mid++;

  printf("--------------------------------\n");
  printf("         Nouveau Animaux        \n");
  printf("--------------------------------\n");

  printf("-Entrer l'age:\n");
  while (scanf("%d", &p.age) != 1) {
    getchar();
    printf("invalide!! ressayer\n");
  }

  printf("-Entrer le nom d'animaux:\n");
  scanf("%s", p.nom);
  for (int i = 0; p.nom[i]; i++) {
    p.nom[i] = toupper(p.nom[i]);
  }

  printf("- Entrer l'espece d'animaux:\n");
  scanf("%s", p.espece);
  for (int i = 0; p.espece[i]; i++) {
    p.espece[i] = toupper(p.espece[i]);
  }

  printf("- Selectionner l'habitat d'animaux:\n");
  scanf("%s", p.habitat);
  for (int i = 0; p.habitat[i]; i++) {
    p.habitat[i] = toupper(p.habitat[i]);
  }

  printf("-Entrer le poids d'animal:\n");
  while (scanf("%f", &p.poids) != 1) {
    getchar();
    printf("invalide!! ressayer\n");
  }

  return p;
};

void ajp(struct Animal p[]) {
  int time;
  printf("--------------------------------\n");
  printf("Nombre d'animaux a ajouter:\n");

  while (scanf("%d", &time) != 1) {
    getchar();
    printf("invalide!! ressayer\n");
  }

  for (int i = 0; i < time; i++) {
    printf("--------- Animal %d -----\n", i + 1);
    p[count] = ajouter();
    count++;
  }
};

//----------------------------------------
//----------------------------------------
//----------------------------------------
void affid(struct Animal p[]) {
  struct Animal tmp;
  for (int i = 0; i < count; i++) {
    for (int j = 0; j < count - i - 1; j++) {
      if (p[j].id > p[j + 1].id) {
        tmp = p[j];
        p[j] = p[j + 1];
        p[j + 1] = tmp;
      }
    }
  }
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

void affage(struct Animal p[]) {
  struct Animal tmp;
  for (int i = 0; i < count; i++) {
    for (int j = 0; j < count - i - 1; j++) {
      if (p[j].age > p[j + 1].age) {
        tmp = p[j];
        p[j] = p[j + 1];
        p[j + 1] = tmp;
      }
    }
  }
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

void affn(struct Animal p[]) {
  struct Animal tmp;
  for (int i = 0; i < count; i++) {
    for (int j = 0; j < count - i - 1; j++) {
      if (strcmp(p[j].nom, p[j + 1].nom) > 0) {
        tmp = p[j];
        p[j] = p[j + 1];
        p[j + 1] = tmp;
      }
    }
  }
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

void affhabitat(struct Animal p[]) {
  char hab[10];
  printf("+--------------------------------------------+\n");
  printf("|Entrer Habitat:                             |\n");
  scanf("%s", hab);
  for (int i = 0; hab[i]; i++) {
    hab[i] = toupper(hab[i]);
  }
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

//----------------------------------------
//----------------------------------------
//----------------------------------------
void modage(struct Animal p[]) {
  int f;
  int exist = 0;
  printf("|     Entrer l'id l'animaux pour modifier l'age   |\n");
  printf("+-------------------------------------------------+\n");

  while (scanf("%d", &f) != 1) {
    getchar();
    printf("invalide!! ressayer\n");
  }
  for (int i = 0; i < count; i++) {
    if (f == p[i].id) {
      printf("- Entrer nouveau age :\n");

      while (scanf("%d", &p[i].age) != 1) {
        getchar();
        printf("invalide!! ressayer\n");
      }
      exist = 1;
    }
  }
  if (exist == 0)
    printf("C'et animaux n'exist pas !!\n");
}

void modhabit(struct Animal p[]) {
  int f;
  int exist = 0;
  printf("|  Entrer l'id l'animaux pour modifier l'habitat  |\n");
  printf("+-------------------------------------------------+\n");
  while (scanf("%d", &f) != 1) {
    getchar();
    printf("invalide!! ressayer\n");
  }
  for (int i = 0; i < count; i++) {
    if (f == p[i].id) {
      printf("- Entrer Nouveau habitat d'animaux:\n");

      scanf("%s", p[i].habitat);
      for (int j = 0; p[i].habitat[j]; j++) {
        p[i].habitat[j] = toupper(p[i].habitat[j]);
      }

      exist = 1;
    }
  }
  if (exist == 0)
    printf("C'et animaux n'exist pas !!\n");
}

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

//----------------------------------------
//----------------------------------------
//----------------------------------------
void supp(struct Animal p[]) {
  int f;
  int exist = 0;
  printf("|  Entrer l'id d'animaux    |\n");
  printf("+---------------------------+\n");
  while (scanf("%d", &f) != 1) {
    getchar();
    printf("invalide!! ressayer\n");
  }
  for (int j = 0; j < count; j++) {
    if (f == p[j].id) {
      for (int i = j; i < count - 1; i++) {
        p[i] = p[i + 1];
      }
      exist = 1;
      count--;
      break;
    }
  }
  if (exist == 0)
    printf("C'et animaux n'exist pas !!\n");
}

//
//----------------------------------------
//----------------------------------------
void sespece(struct Animal p[]) {
  char f[10];
  int exist = 0;

  printf("| Entrer l'espece d'animaux |\n");
  printf("+---------------------------+\n");
  scanf("%s", f);
  scanf("%s", f);
  for (int i = 0; f[i]; i++) {
    f[i] = toupper(f[i]);
  }
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

//----------------------------------------
//----------------------------------------
//----------------------------------------
void snom(struct Animal p[]) {
  char f[10];
  int exist = 0;

  printf("|  Entrer le nom  d'animaux |\n");
  printf("+---------------------------+\n");
  scanf("%s", f);
  for (int i = 0; f[i]; i++) {
    f[i] = toupper(f[i]);
  }
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
  while (scanf("%d", &f) != 1) {
    getchar();
    printf("invalide!! ressayer\n");
  }
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

//----------------------------------------
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
//

//----------------------------------------
//----------------------------------------
//----------------------------------------
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

  int mindex = 0, maxdex = 0;
  int min = p[0].age, max = p[0].age;

  for (int i = 1; i < count; i++) {
    if (p[i].age < min) {
      min = p[i].age;
      mindex = i;
    }
    if (p[i].age > max) {
      max = p[i].age;
      maxdex = i;
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
void frequent(struct Animal p[]) {
  int representations[count];
  int max = 0;
  for (int i = 0; i < count; i++) {
    representations[i] = 0;
    for (int j = 0; j < count; j++) {
      if (strcmp(p[j].espece, p[i].espece) == 0) {
        representations[i]++;
      }
    }
  }

  char fespece[30];
  for (int i = 0; i < count; i++) {
    if (representations[i] > max) {
      max = representations[i];
      strcpy(fespece, p[i].espece);
    }
  }

  printf("|--------------------------------------------|\n");
  printf("Le plus represente est: %s %d. \n", fespece, max);
  printf("|--------------------------------------------|\n");
}

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

//----------------------------------------
//----------------------------------------
//----------------------------------------
//----------------------------------------
//----------------------------------------
//----------------------------------------
//
int main() {

  struct Animal animaux[200] = {
      {1, "SIMBA", "LION", 5, "SAVANE", 190.5},
      {2, "NALA", "LION", 4, "SAVANE", 175},
      {3, "SHEREKHAN", "TIGRE", 8, "JUNGLE", 220.3},
      {4, "BALOO", "OURS", 12, "FORET", 310},
      {5, "RAJA", "ELEPHANT", 15, "SAVANE", 540.7},
      {6, "MARTY", "ZEBRE", 6, "SAVANE", 300.2},
      {7, "GLORIA", "HIPPOPOTAME", 10, "RIVIERE", 450},
      {8, "ALEX", "LION", 7, "SAVANE", 200},
      {9, "JULIEN", "LEMURIEN", 3, "JUNGLE", 12.5},
      {10, "MELMAN", "GIRAFFE", 9, "SAVANE", 390.8},
      {11, "TIMON", "SURICATE", 2, "DESERT", 1.2},
      {12, "PUMBAA", "PHACOCHERES", 5, "SAVANE", 120},
      {13, "SCAR", "LION", 11, "SAVANE", 210.4},
      {14, "KAA", "SERPENT", 6, "JUNGLE", 45},
      {15, "IKO", "PERROQUET", 4, "JUNGLE", 2.1},
      {16, "DUMBO", "ELEPHANT", 3, "SAVANE", 320},
      {17, "KIKI", "CHIEN SAUVAGE", 7, "SAVANE", 25},
      {18, "DONATELLO", "TORTUE", 40, "RIVIERE", 90.5},
      {19, "POLLY", "OISEAU", 5, "JUNGLE", 1.5},
      {20, "KONG", "GORILLE", 13, "JUNGLE", 180}};

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
    case '1':
      animaux[count++] = ajouter();
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
      break;
    case '7':
      stat(animaux);
      break;
    case '8':
      printf("Au Revoir.\n");
      break;
    default:
      printf("Choisi un nombre entre 1-8!\n");
      break;
    }
  }
  return 0;
}
