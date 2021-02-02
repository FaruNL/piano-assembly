#include <dos.h>
#include <conio.h>
#include <stdlib.h>
#include <stdio.h>

#include "files.h"

char strC[]      = "C$";
char strD[]      = "D$";
char space[]     = " $";

void main() {
    if(openFile(1) == 1) {
        createFile(0);
        openFile(1);
    }
    writeFile(1, strD);
    writeFile(1, strC);
    closeFile();

    // for(int i = 0; i < 50;i++) {
    //     printf("%c\n",readed[i]);
    // }
}