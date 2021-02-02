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
char guardar[]   = "[guardar]$";
char reinc[]     = "[reinc. arch.]$";

void color(char filaESI, char columnaESI, char filaEID, char columnaEID) {
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

void colorCustom(char color, char filaESI, char columnaESI, char filaEID, char columnaEID) {
	_asm {
		MOV AX,0600h
		MOV BH,color
		MOV CH,filaESI
		MOV CL,columnaESI
		MOV DH,filaEID
		MOV DL,columnaEID
		INT 10h
	}
}

void noteLabels(char columnaPlus, char filaPlus) {
    cursorPos(4 + columnaPlus, 5 + filaPlus);
	_asm {
        MOV AH, 09h      
        LEA DX, strC
        INT 21h
    }

    cursorPos(8 + columnaPlus, 2 + filaPlus);
    _asm {
        MOV AH, 09h      
        LEA DX, strCSharp
        INT 21h
    }

    cursorPos(14 + columnaPlus, 5 + filaPlus);
    _asm {
        MOV AH, 09h      
        LEA DX, strD
        INT 21h
    }

    cursorPos(19 + columnaPlus, 2 + filaPlus);
    _asm {
        MOV AH, 09h      
        LEA DX, strDSharp
        INT 21h
    }

    cursorPos(24 + columnaPlus, 5 + filaPlus);
    _asm {
        MOV AH, 09h      
        LEA DX, strE
        INT 21h
    }

    cursorPos(33 + columnaPlus, 5 + filaPlus);
    _asm {
        MOV AH, 09h      
        LEA DX, strF
        INT 21h
    }

    cursorPos(37 + columnaPlus, 2 + filaPlus);
    _asm {
        MOV AH, 09h      
        LEA DX, strFSharp
        INT 21h
    }

    cursorPos(43 + columnaPlus, 5 + filaPlus);
    _asm {
        MOV AH, 09h      
        LEA DX, strG
        INT 21h
    }

    cursorPos(48 + columnaPlus, 2 + filaPlus);
    _asm {
        MOV AH, 09h      
        LEA DX, strGSharp
        INT 21h
    }

    cursorPos(54 + columnaPlus, 5 + filaPlus);
    _asm {
        MOV AH, 09h      
        LEA DX, strA
        INT 21h
    }

    cursorPos(59 + columnaPlus, 2 + filaPlus);
    _asm {
        MOV AH, 09h      
        LEA DX, strASharp
        INT 21h
    }

    cursorPos(64 + columnaPlus, 5 + filaPlus);
    _asm {
        MOV AH, 09h      
        LEA DX, strB
        INT 21h
	}
}

void design(char columnasPlus, char filasPlus) {
    color(1 + filasPlus,1 + columnasPlus,5 + filasPlus,5 + columnasPlus);
    color(4 + filasPlus,4 + columnasPlus,5 + filasPlus,7 + columnasPlus);

    color(1 + filasPlus,12 + columnasPlus,5 + filasPlus,16 + columnasPlus);
    color(4 + filasPlus,10 + columnasPlus,5 + filasPlus,18 + columnasPlus);

    color(1 + filasPlus,23 + columnasPlus,5 + filasPlus,27 + columnasPlus);
    color(4 + filasPlus,21 + columnasPlus,5 + filasPlus,24 + columnasPlus);

    color(1 + filasPlus,30 + columnasPlus,5 + filasPlus,34 + columnasPlus);
    color(4 + filasPlus,31 + columnasPlus,5 + filasPlus,36 + columnasPlus);

    color(1 + filasPlus,41 + columnasPlus,5 + filasPlus,45 + columnasPlus);
    color(4 + filasPlus,39 + columnasPlus,5 + filasPlus,47 + columnasPlus);

    color(1 + filasPlus,52 + columnasPlus,5 + filasPlus,56 + columnasPlus);
    color(4 + filasPlus,50 + columnasPlus,5 + filasPlus,58 + columnasPlus);

    color(1 + filasPlus,63 + columnasPlus,5 + filasPlus,67 + columnasPlus);
    color(4 + filasPlus,61 + columnasPlus,5 + filasPlus,63 + columnasPlus);

    colorCustom(8,0,0,0,9);
    cursorPos(0, 0);
    printS(guardar);

    colorCustom(8,0,10,0,23);
    cursorPos(10, 0);
    printS(reinc);
    
    colorCustom(4,0,73,0,79);
    cursorPos(73, 0);
    printS(salir);

    noteLabels(columnasPlus, filasPlus);
}

#endif