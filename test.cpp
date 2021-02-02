#include <dos.h>
#include <conio.h>
#include <stdlib.h>
#include <stdio.h>

#include "files.h"

char strC[]      = "C$";
char strD[]      = "D$";
char space[]     = " $";
char readed[50];

void main() {
    if(openFile(1) == 1) {
        printf("No se pudo abrir el archivo, creando uno nuevo...\n");
        createFile(0);
        openFile(1);
        printf("Archivo nuevo creado\n");
    } else {
        printf("Archivo abierto exitosamente\n");
    }

    if(writeFile(1, strD) == 1) {
        printf("No se pudo escribir en el archivo\n");
    } else {
        printf("Archivo escrito exitosamente\n");
    }
    if(writeFile(1, strC) == 1) {
        printf("No se pudo escribir en el archivo\n");        
    } else {
        printf("Archivo escrito exitosamente\n");
    }
    closeFile();

    if(openFile(2) == 1) {
        printf("No se pudo abrir el archivo\n");
    } else {
        printf("Archivo abierto exitosamente\n");
    }
    if(readFile(2, readed) == 1) {
        printf("No se pudo leer el archivo\n");
    } else {
        printf("Archivo leido exitosamente\n");
    }
    closeFile();



    for(int i = 0; i < 2;i++) {
        printf("%c\n",readed[i]);
    }
}