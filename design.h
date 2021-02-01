#ifndef DESIGN_H
#define DESIGN_H

char strC[]      = "C$";
char strCSharp[] = "C#$";
char strD[]      = "D$";
char strDSharp[] = "D#$";
char strE[]      = "E$";
char strF[]      = "F$";
char strFSharp[] = "F#$";
char strG[]      = "G$";
char strGSharp[] = "G#$";
char strA[]      = "A$";
char strASharp[] = "A#$";
char strB[]      = "B$";
char salir[]     = "[salir]$";

void color(char filaESI, char columnaESI, char filaEID, char columnaEID)
{
	_asm {
		MOV AX,0600h
		MOV BH,78h
		MOV CH,filaESI
		MOV CL,columnaESI
		MOV DH,filaEID
		MOV DL,columnaEID
		INT 10h
	}
}

void colorExit(char filaESI, char columnaESI, char filaEID, char columnaEID)
{
	_asm {
		MOV AX,0600h
		MOV BH,04h
		MOV CH,filaESI
		MOV CL,columnaESI
		MOV DH,filaEID
		MOV DL,columnaEID
		INT 10h
	}
}

void noteLabels()
{
	_asm {
	    MOV AH, 02h      
        MOV BH, 0h
        MOV DH, 5h      
        MOV DL, 4h       
        INT 10h

        MOV AH, 09h      
        LEA DX, strC
        INT 21h

        MOV AH, 02h      
        MOV BH, 0h
        MOV DH, 2      
        MOV DL, 8       
        INT 10h

        MOV AH, 09h      
        LEA DX, strCSharp
        INT 21h

        MOV AH, 02h      
        MOV BH, 0h
        MOV DH, 5h      
        MOV DL, 14      
        INT 10h

        MOV AH, 09h      
        LEA DX, strD
        INT 21h

        MOV AH, 02h      
        MOV BH, 0h
        MOV DH, 2      
        MOV DL, 19      
        INT 10h

        MOV AH, 09h      
        LEA DX, strDSharp
        INT 21h

        MOV AH, 02h      
        MOV BH, 0h
        MOV DH, 5h      
        MOV DL, 24       
        INT 10h

        MOV AH, 09h      
        LEA DX, strE
        INT 21h

        MOV AH, 02h      
        MOV BH, 0h
        MOV DH, 5h      
        MOV DL, 33
        INT 10h

        MOV AH, 09h      
        LEA DX, strF
        INT 21h

        MOV AH, 02h      
        MOV BH, 0h
        MOV DH, 2      
        MOV DL, 37
        INT 10h

        MOV AH, 09h      
        LEA DX, strFSharp
        INT 21h

        MOV AH, 02h      
        MOV BH, 0h
        MOV DH, 5h      
        MOV DL, 43       
        INT 10h

        MOV AH, 09h      
        LEA DX, strG
        INT 21h

        MOV AH, 02h      
        MOV BH, 0h
        MOV DH, 2      
        MOV DL, 48      
        INT 10h

        MOV AH, 09h      
        LEA DX, strGSharp
        INT 21h

        MOV AH, 02h      
        MOV BH, 0h
        MOV DH, 5h      
        MOV DL, 54       
        INT 10h

        MOV AH, 09h      
        LEA DX, strA
        INT 21h

        MOV AH, 02h      
        MOV BH, 0h
        MOV DH, 2     
        MOV DL, 59      
        INT 10h

        MOV AH, 09h      
        LEA DX, strASharp
        INT 21h

        MOV AH, 02h      
        MOV BH, 0h
        MOV DH, 5h      
        MOV DL, 64       
        INT 10h

        MOV AH, 09h      
        LEA DX, strB
        INT 21h
	}
}

void exitLabel() {
    _asm {
        MOV AH, 02h      
        MOV BH, 0h
        MOV DH, 0
        MOV DL, 73       
        INT 10h

        MOV AH, 09h      
        LEA DX, salir
        INT 21h
    }
}

void design() {
    color(1,1,5,5);
    color(4,4,5,7);

    color(1,12,5,16);
    color(4,10,5,18);

    color(1,23,5,27);
    color(4,21,5,24);

    color(1,30,5,34);
    color(4,31,5,36);

    color(1,41,5,45);
    color(4,39,5,47);

    color(1,52,5,56);
    color(4,50,5,58);

    color(1,63,5,67);
    color(4,61,5,63);

    colorExit(0,73,0,79);
    exitLabel();

    noteLabels();
}

#endif