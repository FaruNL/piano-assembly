#ifndef FILES_H
#define FILES_H

char filename[] = "notas.txt";
short fileHandle;
char readed[50];
char count = 50;

void createFile(short access) {
    _asm {
        MOV AH, 3Ch
        MOV CX, access
        LEA DX, filename
        INT 21h

        MOV fileHandle, AX
    }
}

int openFile(char access) {
    char abierto;
    char noAbierto;
    _asm {
        MOV AH, 3Dh
        MOV AL, access
        LEA DX, filename
        INT 21h

        JC noAbierto
        JNC abierto
    }
    abierto:
    _asm{
        MOV fileHandle, AX
    }
    printf("Si se pudo abrir\n");
    return 0;
    noAbierto:
    printf("No se pudo abrir\n");
    return 1;
}

void closeFile() {
    _asm {
        MOV AH, 3Eh
        MOV BX, fileHandle
        INT 21h
    }
}

void readFile(short bytes, char toStore[]) {
    _asm {
        MOV AH, 3Fh
        MOV BX, fileHandle
        MOV CX, bytes
        MOV DX, toStore
        INT 21h
    }
}

int writeFile(short bytes, char toWrite[]) {
    char escrito;
    char noEscrito;
    _asm {
        MOV AH, 40h
        MOV BX, fileHandle
        MOV CX, bytes
        MOV DX, toWrite
        INT 21h

        JC noEscrito
        JNC escrito
    }
    escrito:
    printf("Si se pudo escribir\n");
    return 0;
    noEscrito:
    printf("No se pudo escribir\n");
    return 1;
}

#endif