#ifndef KEYBOARD_H
#define KEYBOARD_H

char headerP[] = {218,196,196,196,196,196,191,'$'};
char bodyP[] =   {179,' ',' ',' ',' ',' ',179,'$'};
char bodyMidP[] =   {179,' ',' ',' ',' ',' ',192,196,191,'$'};
char bodyMidVP[] =   {179,' ',' ',' ',' ',' ',' ',' ',179,'$'};
char footerP[] = {192,196,196,196,196,196,196,196,217,'$'};

char footerN[] = {192,196,196,196,196,196,217,'$'};

char bodyMidM[] =   {218,196,217,' ',' ',' ',' ',' ',192,196,191,'$'};
char bodyMidVM[] =   {179,' ',' ',' ',' ',' ',' ',' ',' ',' ',179,'$'};
char footerM[] = {192,196,196,196,196,196,196,196,196,196,217,'$'};

char bodyMidF[] =   {218,196,217,' ',' ',' ',' ',' ',179,'$'};
char bodyMidVF[] =   {179,' ',' ',' ',' ',' ',' ',' ',179,'$'};

char headerS[] = {218,196,196,191,'$'};
char bodyS[] =   {179,' ',' ',179,'$'};
char footerS[] = {192,196,196,217,'$'};

void printS(char string[]) {
    int posicion = 0;
    char letra;
    while(string[posicion] != '$') {
        letra = string[posicion];
        _asm {
		    MOV AH, 02h
		    MOV DL, letra
		    INT 21h
	    }
        posicion++;
    }
}

void cursorPos(char columna, char fila) {
    _asm {
        MOV AH, 02h
        MOV BH, 0h
        MOV DH, fila
        MOV DL, columna
        INT 10h
    }
}

void pianoKeyprintP(char columna) {
    cursorPos(columna, 0);
    printS(headerP);

    int fila = 1;
    while (fila < 6) {
        if (fila<4){
           cursorPos(columna, fila);
           printS(bodyP);
        }
        if (fila==4){
           cursorPos(columna, fila);
           printS(bodyMidP);
        }
        if (fila>4){
           cursorPos(columna, fila);
           printS(bodyMidVP);
        }
        fila++;
    }
    cursorPos(columna, fila);
    printS(footerP);
}

void pianoKeyprintM(char columna) {
    cursorPos(columna, 0);
    printS(headerP);

    int fila = 1;
    while (fila < 6) {
        if (fila<4){
           cursorPos(columna, fila);
           printS(bodyP);
        }
        if (fila==4){
           columna --;
           columna --;
           cursorPos(columna, fila);
           printS(bodyMidM);
        }
        if (fila>4){
           cursorPos(columna, fila);
           printS(bodyMidVM);
        }
        fila++;
    }
    cursorPos(columna, fila);
    printS(footerM);
}

void pianoKeyprintF(char columna) {
    cursorPos(columna, 0);
    printS(headerP);

    int fila = 1;
    while (fila < 6) {
        if (fila<4){
           cursorPos(columna, fila);
           printS(bodyP);
        }
        if (fila==4){
           columna --;
           columna --;
           cursorPos(columna, fila);
           printS(bodyMidF);
        }
        if (fila>4){
           cursorPos(columna, fila);
           printS(bodyMidVF);
        }
        fila++;
    }
    cursorPos(columna, fila);
    printS(footerP);
}

void pianoKeyprintS(char columna) {
    cursorPos(columna, 0);
    printS(headerS);

    int fila = 1;
    while (fila < 3) {
        cursorPos(columna, fila);
        printS(bodyS);
        fila++;
    }
    cursorPos(columna, fila);
    printS(footerS);
}

void pianoKeyprintN(char columna) {
    cursorPos(columna, 0);
    printS(headerP);

    int fila = 1;
    while (fila < 6) {
      cursorPos(columna, fila);
      printS(bodyP);
      fila++;
    }
    cursorPos(columna, fila);
    printS(footerN);
}

void show(){
    pianoKeyprintP(0);
    pianoKeyprintS(7);
    pianoKeyprintM(11);
    pianoKeyprintS(18);
    pianoKeyprintF(22);
    pianoKeyprintP(29);
    pianoKeyprintS(36);
    pianoKeyprintM(40);
    pianoKeyprintS(47);
    pianoKeyprintM(51);
    pianoKeyprintS(58);
    pianoKeyprintF(62);
}

#endif