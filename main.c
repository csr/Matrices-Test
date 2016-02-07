// Cesare de Cal


#include <stdio.h>
#include <stdlib.h>


int acquisisciNumeroCompresoTraValori(int inserimentoMinimoConsentito, int inserimentoMassimoConsentito) {
    int inserimento;
    scanf("%d", &inserimento);
    while ((inserimento < inserimentoMinimoConsentito) || (inserimento > inserimentoMassimoConsentito)) {
        printf("'%d' non e' un inserimento valido. Inserisci un valore compreso tra %d e %d: ", inserimento, inserimentoMinimoConsentito, inserimentoMassimoConsentito);
        scanf("%d", &inserimento);
    }
    return inserimento;
}

void visualizzaValoriElementiMatrice(int matrice[][2], int numeroColonne, int numeroRighe) {
    int a, z;
    for (a = 0; a < numeroRighe; a++) {
        for (z = 0; z < numeroColonne; z++) {
            printf("%d ", matrice[a][z]);
        }
        printf("\n");
    }
}

void inserimentoDaTastieraElementiMatrice(int matrice[][2], int numeroColonne, int numeroRighe) {
    int a, z;
    for (a = 0; a < numeroRighe; a++) {
        for (z = 0; z < numeroColonne; z++) {
            printf("Inserisci un numero da assegnare alla posizione (%d, %d): ", a, z);
            scanf("%d", &matrice[a][z]);
        }
    }
}

void sommaMassimiRigheMatrici(int matrice[][2], int numeroColonne, int numeroRighe) {
    int i, k;
    int massimiRiga[numeroRighe];
    int mediaRighe[numeroRighe];
    int numeriDispari[numeroRighe];
    
    for (k = 0; k < numeroRighe; k++) {
        mediaRighe[k] = 0;
        numeriDispari[k] = 0;
        massimiRiga[k] = matrice[k][0];
    }
    
    for(k = 0; k < numeroRighe; k++) {
        for(i = 0; i < numeroColonne; i++) {
            if (matrice[k][i] > massimiRiga[k]) {
                massimiRiga[k] = matrice[k][i];
            }
            if (matrice[k][i] % 2) {
                mediaRighe[k] += matrice[k][i];
                numeriDispari[k]++;
                printf("Ho aggiunto %d alla somma totale della riga %d. Numeri dispari: %d Somma totale: %d\n", matrice[k][i], k, numeriDispari[k], mediaRighe[k]);
            }
        }
    }
    
    for (k = 0; k < numeroRighe; k++) {
        mediaRighe[k] = mediaRighe[k] / numeriDispari[k];
        if (mediaRighe[k] > massimiRiga[k]) {
            printf("La media (%d) e' piu' grande del numero massimo della riga (%d).\n", mediaRighe[k], massimiRiga[k]);
        } else if (mediaRighe[k] == massimiRiga[k]) {
            printf("La media (%d) e' uguale al numero massimo della riga (%d).\n", mediaRighe[k], massimiRiga[k]);
        } else {
            printf("La media (%d) e' piu' piccola del numero massimo della riga (%d).\n", mediaRighe[k], massimiRiga[k]);
        }
    }
}

void mediaNumeriPariPerRigaEColonna(int matrice[][2], int numeroColonne, int numeroRighe) {
    int mediaColonne[numeroColonne];
    int mediaRighe[numeroRighe];
    int i, k, numeriPari = 0;
    
    for (i = 0; i < numeroRighe; i++) {
        mediaRighe[i] = 0;
    }
    for (k = 0; k < numeroColonne; k++) {
        mediaColonne[k] = 0;
    }
    
    for (i = 0; i < numeroRighe; i++) {
        for(k = 0; k < numeroColonne; k++){
            if(!(matrice[i][k] % 2)) {
                mediaRighe[i] += matrice[i][k];
                numeriPari++;
            }
        }
        
        if (numeriPari > 0) {
            mediaRighe[i] = mediaRighe[i] / numeriPari;
            numeriPari = 0;
        }
    }
    
    for (k = 0; k < numeroColonne; k++) {
        for(i = 0; i < numeroRighe; i++){
            if(!(matrice[i][k] % 2)) {
                mediaColonne[k] += matrice[i][k];
                numeriPari++;
            }
        }
        
        mediaColonne[k] = mediaColonne[k] / numeriPari;
        numeriPari = 0;
    }
    
    for (i = 0; i < numeroRighe; i++) {
        printf("La media dei numeri pari della riga %d e': %d\n", i+1, mediaRighe[i]);
    }
    
    for (k = 0; k < numeroColonne; ++k) {
        printf("La media dei numeri pari della colonna %d e': %d\n", k+1, mediaColonne[k]);
    }
}


int main() {
    int numeroColonne = 2, numeroRighe = 5;
    int matrice[numeroRighe][numeroColonne];
    
    while (1) {
        puts("---------------------------------------------------");
        puts("1: Inserimento elementi della matrice da tastiera");
        puts("2: Visualizzazione elementi matrice");
        puts("3: Media dei numeri dispari per riga e per colonna");
        puts("4: Somma massimi di ogni riga e confronto con media");
        puts("---------------------------------------------------");
        printf("Inserisci un'opzione del menu: ");
        int scelta = acquisisciNumeroCompresoTraValori(1, 4);
        
        switch (scelta) {
            case 1:
                inserimentoDaTastieraElementiMatrice(matrice, numeroColonne, numeroRighe);
                break;
            case 2:
                visualizzaValoriElementiMatrice(matrice, numeroColonne, numeroRighe);
                break;
            case 3:
                mediaNumeriPariPerRigaEColonna(matrice, numeroColonne, numeroRighe);
                break;
            case 4:
                sommaMassimiRigheMatrici(matrice, numeroColonne, numeroRighe);
                break;
            default:
                break;
        }
    }
}