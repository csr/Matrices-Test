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

void massimo(int matrice[][2], int numeroColonne, int numeroRighe) {
    int a, z;
    
    int massimoRiga = matrice[0][0];
    int massimoColonna = matrice[0][0];
    int numeriDispari = 0;
    
    for(k = 0; k < numeroColonne; ++k) {
        for(i = 0; i < numeroRighe; i++){
            if (matrice[k][i] > massimoRiga) {
                massimoRiga = matrice[k][i];
            }
            
            if(!(matrice[i][k] % 2)) {
                numeriDispari++;
            }
        }
        int media =
        numeriDispari = 0;
    }
}

void mediaNumeriPariPerRigaEColonna(int matrice[][2], int numeroColonne, int numeroRighe) {
    int mediaColonne[numeroColonne];
    int mediaRighe[numeroRighe];
    int i, k, numeriPari = 0;
    
    for(i = 0; i < numeroRighe; i++) {
        mediaRighe[i] = 0;
    }
    for(k = 0; k < numeroColonne; k++) {
        mediaColonne[k] = 0;
    }
    
    for(i = 0; i < numeroRighe; i++){
        for(k=0; k < numeroColonne; ++k){
            if(!(matrice[i][k] % 2)) {
                mediaRighe[i] += matrice[i][k];
                numeriPari++;
            }
        }
        mediaRighe[i] = mediaRighe[i] / numeriPari;
        numeriPari = 0;
    }
    
    for(k = 0; k < numeroColonne; ++k) {
        for(i = 0; i < numeroRighe; i++){
            if(!(matrice[i][k] % 2)) {
                mediaColonne[k] += matrice[i][k];
                numeriPari++;
            }
        }
        mediaColonne[k] = mediaColonne[k] / numeriPari;
        numeriPari = 0;
    }
    
    for(i = 0; i < numeroRighe; i++) {
        printf("La media dei numeri pari della riga %d e': %d\n", i+1, mediaRighe[i]);
    }
    
    for(k = 0; k < numeroColonne; ++k) {
        printf("La media dei numeri pari della colonna %d e': %d\n", k+1, mediaColonne[k]);
    }
}


int main() {
    int numeroColonne = 2, numeroRighe = 5;
    int matrice[numeroRighe][numeroColonne];
    
    while (1) {
        puts("1: Inserimento elementi della matrice da tastiera");
        puts("2: Visualizzazione elementi matrice");
        puts("3: Media dei numeri dispari per riga e per colonna");
        puts("4: Massimi");
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
                massimo(matrice, numeroColonne, numeroRighe);
                break;
            default:
                break;
        }
    }
}