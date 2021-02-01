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

void pianoKeyprintP(char columna, char fila) {
    cursorPos(columna, fila);
    printS(headerP);

    char filaLoop = fila + 6;
    char filaBody = fila + 4;

    fila++;
    while (fila < filaLoop) {
        if (fila < filaBody){
           cursorPos(columna, fila);
           printS(bodyP);
        }
        if (fila == filaBody){
           cursorPos(columna, fila);
           printS(bodyMidP);
        }
        if (fila > filaBody){
           cursorPos(columna, fila);
           printS(bodyMidVP);
        }
        fila++;
    }
    cursorPos(columna, fila);
    printS(footerP);
}

void pianoKeyprintM(char columna, char fila) {
    cursorPos(columna, fila);
    printS(headerP);

    char filaLoop = fila + 6;
    char filaBody = fila + 4;

    fila++;
    while (fila < filaLoop) {
        if (fila < filaBody){
           cursorPos(columna, fila);
           printS(bodyP);
        }
        if (fila == filaBody){
           columna --;
           columna --;
           cursorPos(columna, fila);
           printS(bodyMidM);
        }
        if (fila > filaBody){
           cursorPos(columna, fila);
           printS(bodyMidVM);
        }
        fila++;
    }
    cursorPos(columna, fila);
    printS(footerM);
}

void pianoKeyprintF(char columna, char fila) {
    cursorPos(columna, fila);
    printS(headerP);

    char filaLoop = fila + 6;
    char filaBody = fila + 4;

    fila++;
    while (fila < filaLoop) {
        if (fila < filaBody){
           cursorPos(columna, fila);
           printS(bodyP);
        }
        if (fila == filaBody){
           columna --;
           columna --;
           cursorPos(columna, fila);
           printS(bodyMidF);
        }
        if (fila > filaBody){
           cursorPos(columna, fila);
           printS(bodyMidVF);
        }
        fila++;
    }
    cursorPos(columna, fila);
    printS(footerP);
}

void pianoKeyprintS(char columna, char fila) {
    cursorPos(columna, fila);
    printS(headerS);

    char filaLoop = fila + 3;

    fila++;
    while (fila < filaLoop) {
        cursorPos(columna, fila);
        printS(bodyS);
        fila++;
    }
    cursorPos(columna, fila);
    printS(footerS);
}

void show(char columnaPlus, char fila){
    pianoKeyprintP(0 + columnaPlus, fila);
    pianoKeyprintS(7 + columnaPlus, fila);
    pianoKeyprintM(11 + columnaPlus, fila);
    pianoKeyprintS(18 + columnaPlus, fila);
    pianoKeyprintF(22 + columnaPlus, fila);
    pianoKeyprintP(29 + columnaPlus, fila);
    pianoKeyprintS(36 + columnaPlus, fila);
    pianoKeyprintM(40 + columnaPlus, fila);
    pianoKeyprintS(47 + columnaPlus, fila);
    pianoKeyprintM(51 + columnaPlus, fila);
    pianoKeyprintS(58 + columnaPlus, fila);
    pianoKeyprintF(62 + columnaPlus, fila);
}

#endif