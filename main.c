#include <stdio.h>
#include <stdlib.h>

typedef struct liste {
    int donnee;
    struct liste *suivant;
} liste;

liste *creer_liste(liste *tete) {
    liste *nouveau, *courant;
    int valeur;
    printf("Entrer -1 pour terminer \n");
    printf("Entrer la donnée :\n ");
    scanf("%d", &valeur);

    while (valeur != -1) {
        nouveau = (liste *)malloc(sizeof(liste));
        nouveau->donnee = valeur;

        if (tete == NULL) {
            nouveau->suivant = NULL;
            tete = nouveau;
        } else {
            courant = tete;
            while (courant->suivant != NULL)courant = courant->suivant;
            courant->suivant = nouveau;
            nouveau->suivant = NULL;
        }

        printf("Entrer la donnée: \n ");
        scanf("%d", &valeur);
    }

    return tete;
}

void afficher_liste(liste *tete) {
    liste *courant = tete;
    while (courant != NULL) {
        printf("%d -> ", courant->donnee);
        courant = courant->suivant;
    }
    printf("NULL\n");
}

int main() {
    liste *ma_liste = NULL;
    ma_liste = creer_liste(ma_liste);
    afficher_liste(ma_liste);

    // Libération de la mémoire
    liste *temp;
    while (ma_liste != NULL) {
        temp = ma_liste;
        ma_liste = ma_liste->suivant;
        free(temp);
    }

    return 0;
}
