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

/* Crea un archivo (Llamado por defecto 'NOTAS.TXT').
 *
 * Parametros:
 *      short type    = Tipo de archivo (0 = Fichero normal | 1 = Fichero de sólo lectura | 2 = Fichero oculto | 3 = Fichero de sistema)
 *      [I]: filename = Nombre del archivo
 *
 * Devuelve:
 *      int             = 0 (Creado), 1 (No creado)
 *      [I]: fileHandle = Manejador único del archivo
 */
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

/* Abre un archivo (Llamado por defecto 'NOTAS.TXT').
 *
 * Parametros:
 *      char access   = Tipo de acceso (0 = Sólo lectura | 1 = Sólo escritura | 4 = Lectura/Escritura)
 *      [I]: filename = Nombre del archivo
 *
 * Devuelve:
 *      int             = 0 (Abierto), 1 (No abierto)
 *      [I]: fileHandle = Manejador único del archivo
 */
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

/* Cierra un archivo.
 *
 * Parametros:
 *      [I]: fileHandle = Manejador único del archivo
 *
 * Devuelve:
 *      int = 0 (Cerrado), 1 (No cerrado)
 */
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

/* Lee un archivo.
 *
 * Parametros:
 *      short bytes      = Numero de bytes a leer
 *      char[] toStore   = Arreglo donde se guardará lo leido
 *      [I]: fileHandle  = Manejador único del archivo
 *
 * Devuelve:
 *      int = 0 (Leido), 1 (No leido)
 */
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

/* Escribe en un archivo.
 *
 * Parametros:
 *      short bytes      = Numero de bytes a escribir
 *      char[] toStore   = Arreglo donde se tomará los bytes a escribir.
 *      [I]: fileHandle  = Manejador único del archivo
 *
 * Devuelve:
 *      int = 0 (Escrito), 1 (No escrito)
 */
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