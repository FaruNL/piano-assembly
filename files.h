#ifndef FILES_H
#define FILES_H

char filename[] = "notas.txt";
short fileHandle;
char count = 50;

char flC[]      = "C";
char flCSharp[] = "c";
char flD[]      = "D";
char flDSharp[] = "d";
char flE[]      = "E";
char flF[]      = "F";
char flFSharp[] = "f";
char flG[]      = "G";
char flGSharp[] = "g";
char flA[]      = "A";
char flASharp[] = "a";
char flB[]      = "B";

int createFile(short type) {
    char created;
    char notCreated;
    _asm {
        MOV AH, 3Ch
        MOV CX, type
        LEA DX, filename
        INT 21h

        JC notCreated
        JNC created
    }
    created:
    _asm{
        MOV fileHandle, AX
    }
    return 0;
    notCreated:
    return 1;
}

int openFile(char access) {
    char opened;
    char notOpened;
    _asm {
        MOV AH, 3Dh
        MOV AL, access
        LEA DX, filename
        INT 21h

        JC notOpened
        JNC opened
    }
    opened:
    _asm{
        MOV fileHandle, AX
    }
    return 0;
    notOpened:
    return 1;
}

int closeFile() {
    char closed;
    char notClosed;
    _asm {
        MOV AH, 3Eh
        MOV BX, fileHandle
        INT 21h

        JC notClosed
        JNC closed
    }
    closed:
    return 0;
    notClosed:
    return 1;
}

int readFile(short bytes, char toStore[]) {
    char leido;
    char noLeido;
    _asm {
        MOV AH, 3Fh
        MOV BX, fileHandle
        MOV CX, bytes
        MOV DX, toStore
        INT 21h

        JC noLeido
        JNC leido
    }
    leido:
    return 0;
    noLeido:
    return 1;
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
    return 0;
    noEscrito:
    return 1;
}

#endif