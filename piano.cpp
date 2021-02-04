#include <dos.h>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>

#include "keyboard.h"
#include "speaker.h"
#include "design.h"
#include "files.h"

short mouseButton;
char posX;
char posY;
int save = 0;

/* Limpia pantalla y ubica el cursor en la esquina superior izquierda.
 *
 * Parametros: Nada
 * Devuelve: Nada
 */
void cls() {
    _asm {
        MOV AX, 0600h
        MOV BH, 07h
        MOV CX, 0000h
        MOV DX, 184Fh
        INT 10h

        MOV AH, 02h
        MOV BH, 0h
        MOV DX, 0000h
        INT 10h
    }
}

/* Inicializa el mouse.
 *
 * Parametros: Nada
 * Devuelve: Nada
 */
void initMouse() {
    _asm {
        MOV AX, 0h
        INT 33h
    }
}

/* Muestra el puntero del mouse
 *
 * Parametros: Nada
 * Devuelve: Nada
 */
void showMouse() {
    _asm {
        MOV AX, 01h
        INT 33h
    }
}

/* Oculta el puntero del mouse
 *
 * Parametros: Nada
 * Devuelve: Nada
 */
void hideMouse() {
    _asm {
        MOV AX, 02h
        INT 33h
    }
}

/* Retorna el estado de los botones del mouse.
 * Retorna la posición del puntero del mouse.
 *
 * Parametros: Nada
 * Devuelve:
 *      [I]: mouseButton = Botón presionado {BX} (1 = Click der. | 2 = Click izq. | 4 = Click cent.)
 *      [I]: CX = Posición del puntero respecto a X
 *      [I]: DX = Posición del puntero respecto a Y
 */
void checkMouseButton() {
    _asm {
        MOV AX, 03h
        INT 33h

        MOV mouseButton, BX
    }
}

/* Guarda la posición del puntero del mouse en las respectivas variables.
 *
 * Parametros: Nada
 * Devuelve:
 *      [I]: posX = Posición del puntero respecto a X
 *      [I]: posY = Posición del puntero respecto a Y
 */
void setXandY() {
    _asm {
        MOV AX, DX
        MOV BL, 08h
        DIV BL
        MOV posY, AL

        MOV AX, CX
        MOV BL, 08h
        DIV BL
        MOV posX, AL
    }
}

/* Registra cuando se libera el botón del mouse.
 *
 * Parametros: Nada
 * Devuelve: Nada
 */
void releaseMouseButton() {
    char release;

    release:
    _asm {
        MOV AX, 03h
        INT 33h

        CMP BX, 00h
        JNE release
    }
}

/* Genera sonidos hasta que se deje de presionar el botón izq. del mouse
 * según la posición del mouse. Además guarda la nota reproducida según el
 * estado de la bandera save.
 *
 * Sonidos generados == C, C#, D, D#, E, F, F#, G, G#, A, A#, B
 *
 * Parametros:
 *      char plus = Desplazamiento respecto a X
 *
 * Devuelve: Nada
 */
void firstCheck(char plus) {
    if ( (posX >= 0 + plus) && (posX <= 6 + plus) ) {
        speakerFull(C2);
        releaseMouseButton();
        speakerOff();
        if(save == 1){writeFile(1, flC);}
    }
    if ( (posX >= 7 + plus) && (posX <= 10 + plus) ) {
        speakerFull(CSharp2);
        releaseMouseButton();
        speakerOff();
        if(save == 1){writeFile(1, flCSharp);}
    }
    if ( (posX >= 11 + plus) && (posX <= 17 + plus) ) {
        speakerFull(D2);
        releaseMouseButton();
        speakerOff();
        if(save == 1){writeFile(1, flD);}
    }
    if ( (posX >= 18 + plus) && (posX <= 21 + plus) ) {
        speakerFull(DSharp2);
        releaseMouseButton();
        speakerOff();
        if(save == 1){writeFile(1, flDSharp);}
    }
    if ( (posX >= 22 + plus) && (posX <= 28 + plus) ) {
        speakerFull(E2);
        releaseMouseButton();
        speakerOff();
        if(save == 1){writeFile(1, flE);}
    }
    if ( (posX >= 29 + plus) && (posX <= 35 + plus) ) {
        speakerFull(F2);
        releaseMouseButton();
        speakerOff();
        if(save == 1){writeFile(1, flF);}
    }
    if ( (posX >= 36 + plus) && (posX <= 39 + plus) ) {
        speakerFull(FSharp2);
        releaseMouseButton();
        speakerOff();
        if(save == 1){writeFile(1, flFSharp);}
    }
    if ( (posX >= 40 + plus) && (posX <= 46 + plus) ) {
        speakerFull(G2);
        releaseMouseButton();
        speakerOff();
        if(save == 1){writeFile(1, flG);}
    }
    if ( (posX >= 47 + plus) && (posX <= 50 + plus) ) {
        speakerFull(GSharp2);
        releaseMouseButton();
        speakerOff();
        if(save == 1){writeFile(1, flGSharp);}
    }
    if ( (posX >= 51 + plus) && (posX <= 57 + plus) ) {
        speakerFull(A2);
        releaseMouseButton();
        speakerOff();
        if(save == 1){writeFile(1, flA);}
    }
    if ( (posX >= 58 + plus) && (posX <= 61 + plus) ) {
        speakerFull(ASharp2);
        releaseMouseButton();
        speakerOff();
        if(save == 1){writeFile(1, flASharp);}
    }
    if ( (posX >= 62 + plus) && (posX <= 68 + plus) ) {
        speakerFull(B2);
        releaseMouseButton();
        speakerOff();
        if(save == 1){writeFile(1, flB);}
    }
}

/* Genera sonidos hasta que se deje de presionar el botón izq. del mouse
 * según la posición del mouse. Además guarda la nota reproducida según el
 * estado de la bandera save.
 *
 * Sonidos generados == C, D, E, F, G, A, B
 *
 * Parametros:
 *      char plus = Desplazamiento respecto a X
 *
 * Devuelve: Nada
 */
void secondCheck(char plus) {
    if ( (posX >= 0 + plus) && (posX <= 8 + plus) ) {
        speakerFull(C2);
        releaseMouseButton();
        speakerOff();
        if(save == 1){writeFile(1, flC);}
    }
    if ( (posX >= 9 + plus) && (posX <= 19 + plus) ) {
        speakerFull(D2);
        releaseMouseButton();
        speakerOff();
        if(save == 1){writeFile(1, flD);}
    }
    if ( (posX >= 20 + plus) && (posX <= 28 + plus) ) {
        speakerFull(E2);
        releaseMouseButton();
        speakerOff();
        if(save == 1){writeFile(1, flE);}
    }
    if ( (posX >= 29 + plus) && (posX <= 37 + plus) ) {
        speakerFull(F2);
        releaseMouseButton();
        speakerOff();
        if(save == 1){writeFile(1, flF);}
    }
    if ( (posX >= 38 + plus) && (posX <= 48 + plus) ) {
        speakerFull(G2);
        releaseMouseButton();
        speakerOff();
        if(save == 1){writeFile(1, flG);}
    }
    if ( (posX >= 49 + plus) && (posX <= 59 + plus) ) {
        speakerFull(A2);
        releaseMouseButton();
        speakerOff();
        if(save == 1){writeFile(1, flA);}
    }
    if ( (posX >= 60 + plus) && (posX <= 68 + plus) ) {
        speakerFull(B2);
        releaseMouseButton();
        speakerOff();
        if(save == 1){writeFile(1, flB);}
    }
}

/* Cambia el valor de la bandera save, y cambia el color
 * de la etiqueta [guardar].
 *
 * Parametros: Nada
 * Devuelve: Nada
 */
void saveStatus() {
    releaseMouseButton();
    if(save == 0) {
        save = 1;
        hideMouse();
        customColor(2,0,0,0,9);
    } else {
        save = 0;
        hideMouse();
        customColor(8,0,0,0,9);
    }
    cursorPos(0, 0);
    printS(guardar);
}

/* Cambia momentaneamente (hasta que se suelte el click) 
 * el color de la etiqueta [reinc. arch.].
 *
 * Parametros: Nada
 * Devuelve: Nada
 */
void resetStatus() {
    hideMouse();
    customColor(1,0,10,0,23);
    cursorPos(10, 0);
    printS(reinc);
    showMouse();

    releaseMouseButton();

    hideMouse();
    customColor(8,0,10,0,23);
    cursorPos(10, 0);
    printS(reinc);
    showMouse();
}

/* Main */
void main() {
    char initX = 4;
    char initY = 9;

    cls();

    show(initX, initY);   // Muestra el gráfico del piano
    design(initX, initY); // Muestra etiquetas y colores

    cursorPos(0, initY + 7); // Cursor abajo de la interfaz

    if(openFile(1) == 1) {
        createFile(0);
        openFile(1);
    }

    initMouse();
    showMouse();

    // Ciclo del mouse
    while(1){
        checkMouseButton();
        if(mouseButton == 1) {
            setXandY();

            // Etiqueta [salir]
            if((posY == 0) && (posX >= 73) && (posX <= 79) ) {
                hideMouse();
                closeFile();
                break;
            }

            // Etiqueta [guardar]
            if((posY == 0) && (posX >= 0) && (posX <= 9) ) {
                saveStatus();
                cursorPos(0, initY + 7);
                showMouse();
            }
            
            // Etiqueta [reinc. arch.]
            if((posY == 0) && (posX >= 10) && (posX <= 23) ) {
                resetStatus();
                cursorPos(0, initY + 7);
                closeFile();
                createFile(0);
                openFile(1);
            }

            // Revisa la posición de las teclas 1
            if(posY == initY || posY == (initY + 1) || posY == (initY + 2) || posY == (initY + 3)) {
                firstCheck(initX);
            }

            // Revisa la posición de las teclas 2
            if(posY == (initY + 4) || posY == (initY + 5) || posY == (initY + 6)) {
                secondCheck(initX);
            }
        }
    }
    cls();
}
