#include <stdio.h>
#include <string.h>
#include "funciones.h"

void verPersonas(char personas[][4][20]) {
    for (int i = 0; i < 10; i++) {
        printf("Nombre: %s %s\n", personas[i][0], personas[i][1]);
        printf("Cedula: %s\n", personas[i][2]);
        if (strcmp(personas[i][3], "soltero") == 0) {
            printf("Estado Civil: Soltero\n");
        } else {
            printf("Estado Civil: Casado con cedula: %s\n", personas[i][3]);
        }
        printf("**________________*_________________**\n");
    }
}
void verificarPersona(char personas[][4][20]) {
    char cedu[20];
    printf("Ingrese la cedula de la persona: ");
    scanf("%s", cedu);

    int indice = buscarPersonaXCedula(personas, cedu);

    if (indice != -1) {
        printf("Nombre: %s %s\n", personas[indice][0], personas[indice][1]);
        printf("Cedula: %s\n", personas[indice][2]);
        if (strcmp(personas[indice][3], "soltero") == 0) {
            printf("Estado Civil: Soltero\n");
        } else {
            int conyugeIndice = buscarPersonaXCedula(personas, personas[indice][3]);
            printf("Estado Civil: Casado con %s %s\n", personas[conyugeIndice][0], personas[conyugeIndice][1]);
        }
    } else {
        printf("Cedula no encontrada en el registro.\n");
    }
}

void registrarMatrimonio(char personas[][4][20]) {
    char cedu1[20], cedu2[20];
    printf("Ingrese la cedula de la primera persona: ");
    scanf("%s", cedu1);
    printf("Ingrese la cedula de la segunda persona: ");
    scanf("%s", cedu2);

    int indice1 = buscarPersonaXCedula(personas, cedu1);
    int indice2 = buscarPersonaXCedula(personas, cedu2);

    if (indice1 != -1 && indice2 != -1) {
        if (strcmp(personas[indice1][3], "soltero") == 0 && strcmp(personas[indice2][3], "soltero") == 0) {
            strcpy(personas[indice1][3], cedu2);
            strcpy(personas[indice2][3], cedu1);
            printf("Matrimonio registrado exitosamente.\n");
        } else {
            printf("Una o ambas personas ya estan casadas.\n");
        }
    } else {
        printf("Una o ambas cedulas no existen en el registro.\n");
    }
}

int buscarPersonaXCedula(char personas[][4][20], char cedu[20]) {
    for (int i = 0; i < 10; i++) {
        if (strcmp(personas[i][2], cedu) == 0) {
            return i;
        }
    }
    return -1;
}