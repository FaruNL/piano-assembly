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

void color(char filaI, char columnaI, char filaF, char columnaF) {
	_asm {
		MOV AX,0600h
		MOV BH,78h
		MOV CH,filaI
		MOV CL,columnaI
		MOV DH,filaF
		MOV DL,columnaF
		INT 10h
	}
}

void customColor(char color, char filaI, char columnaI, char filaF, char columnaF) {
	_asm {
		MOV AX,0600h
		MOV BH,color
		MOV CH,filaI
		MOV CL,columnaI
		MOV DH,filaF
		MOV DL,columnaF
		INT 10h
	}
}

void noteLabels(char columna, char fila) {
    cursorPos(4 + columna, 5 + fila);
	printS(strC);

    cursorPos(8 + columna, 2 + fila);
    printS(strCSharp);

    cursorPos(14 + columna, 5 + fila);
    printS(strD);

    cursorPos(19 + columna, 2 + fila);
    printS(strDSharp);

    cursorPos(24 + columna, 5 + fila);
    printS(strE);

    cursorPos(33 + columna, 5 + fila);
    printS(strF);

    cursorPos(37 + columna, 2 + fila);
    printS(strFSharp);

    cursorPos(43 + columna, 5 + fila);
    printS(strG);

    cursorPos(48 + columna, 2 + fila);
    printS(strGSharp);

    cursorPos(54 + columna, 5 + fila);
    printS(strA);

    cursorPos(59 + columna, 2 + fila);
    printS(strASharp);

    cursorPos(64 + columna, 5 + fila);
    printS(strB);
}

void design(char columnas, char filas) {
    color(1 + filas,1 + columnas,5 + filas,5 + columnas);
    color(4 + filas,4 + columnas,5 + filas,7 + columnas);

    color(1 + filas,12 + columnas,5 + filas,16 + columnas);
    color(4 + filas,10 + columnas,5 + filas,18 + columnas);

    color(1 + filas,23 + columnas,5 + filas,27 + columnas);
    color(4 + filas,21 + columnas,5 + filas,24 + columnas);

    color(1 + filas,30 + columnas,5 + filas,34 + columnas);
    color(4 + filas,31 + columnas,5 + filas,36 + columnas);

    color(1 + filas,41 + columnas,5 + filas,45 + columnas);
    color(4 + filas,39 + columnas,5 + filas,47 + columnas);

    color(1 + filas,52 + columnas,5 + filas,56 + columnas);
    color(4 + filas,50 + columnas,5 + filas,58 + columnas);

    color(1 + filas,63 + columnas,5 + filas,67 + columnas);
    color(4 + filas,61 + columnas,5 + filas,63 + columnas);

    customColor(8,0,0,0,9);
    cursorPos(0, 0);
    printS(guardar);

    customColor(8,0,10,0,23);
    cursorPos(10, 0);
    printS(reinc);
    
    customColor(4,0,73,0,79);
    cursorPos(73, 0);
    printS(salir);

    noteLabels(columnas, filas);
}

#endif