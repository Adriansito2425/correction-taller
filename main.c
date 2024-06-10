/*Desarrollar un programa de registro civil que me permita realizar las siguientes acciones:

1. Ver personas (Mostrará el total de pesonas ingresadas en el registro civil con sus datos personales
                    incluyendo si se encuentra cada o no, el estado civil(soltero o casado) se determinará en funión
                    de la 4ta caracteristica de cada persona, si esta esta como soltera se mostrará la palabra soltero,
                    si esta tiene un numero de cedula se mostrará como casada)
2. Registrar matrimocio (Vinculará dos personas a través de su número de cédula, el cual se ingresará en la 4ta caracteristica
                            de cada persona, asignando el número de cédula del conyugue en dica caracteristica.)
3. Verificar Persona (buscará una persona en función de su número de cedula, si la persona esta casada, mostrará la
                        persona con la que la misma esta casada.)

*/ 



#include <stdio.h>
#include "funciones.h"

int main (int argc, char *argv[]) {
    char personas[10][4][20]={{"Juan","Perez","1234","4567"},
                              {"Luis","Almeida","2345","soltero"},
                              {"Mateo","Ramirez","3456","soltero"},
                              {"Ana","Guerra","4567","1234"},
                              {"Lorena","Guillen","5678","soltero"},
                              {"Maria","Alvarez","6789","0987"},
                              {"Esteban","Mendez","7890","soltero"},
                              {"Jose","Ayala","0987","6789"},
                              {"Monica","Freire","9876","soltero"},
                              {"Rocio","Valle","8765","soltero"}};
       
    int opcion1,opcion2;
    do
    {
        printf("Seleccione una opcion:\n1.Ver Personas\n2.Registrar Matrimonio\n3.Verificar Persona\n>>");
        scanf("%d",&opcion1);
        switch (opcion1)
        {
        case 1:
            verPersonas(personas);
            break;
        case 2:
            registrarMatrimonio(personas);
            break;
        case 3:
            verificarPersona(personas);
            break;
        default:
            break;
        }
        printf("Desea elegir otra opcion:\n1.Si\n2.No\n>>");
        scanf("%d",&opcion2);
    } while (opcion2==1);
    
    return 0;
}