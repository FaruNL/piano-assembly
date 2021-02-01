#include <dos.h>
#include <conio.h>
#include <stdlib.h>

#include "keyboard.h"
#include "speaker.h"
#include "design.h"

/* Variables auxiliares */
short mouseButton;
char posX;
char posY;

/* Métodos generales */
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

/* Mouse */
void initMouse() {
    _asm {
        MOV AX, 0h
        INT 33h

        MOV AX, 01h
        INT 33h
    }
}

void hideMouse() {
    _asm {
        MOV AX, 02h
        INT 33h
    }
}

void checkMouseButton() {
    _asm {
        MOV AX, 03h
        INT 33h

        MOV mouseButton, BX
    }
}

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

/* Revisiones en PosX  */
void firstCheck(char plus) {
    if ( (posX >= 0 + plus) && (posX <= 6 + plus) ) {
        speakerFull(C2);
        releaseMouseButton();
        speakerOff();
    }
    if ( (posX >= 7 + plus) && (posX <= 10 + plus) ) {
        speakerFull(CSharp2);
        releaseMouseButton();
        speakerOff();
    }
    if ( (posX >= 11 + plus) && (posX <= 17 + plus) ) {
        speakerFull(D2);
        releaseMouseButton();
        speakerOff();
    }
    if ( (posX >= 18 + plus) && (posX <= 21 + plus) ) {
        speakerFull(DSharp2);
        releaseMouseButton();
        speakerOff();
    }
    if ( (posX >= 22 + plus) && (posX <= 28 + plus) ) {
        speakerFull(E2);
        releaseMouseButton();
        speakerOff();
    }
    if ( (posX >= 29 + plus) && (posX <= 35 + plus) ) {
        speakerFull(F2);
        releaseMouseButton();
        speakerOff();
    }
    if ( (posX >= 36 + plus) && (posX <= 39 + plus) ) {
        speakerFull(FSharp2);
        releaseMouseButton();
        speakerOff();
    }
    if ( (posX >= 40 + plus) && (posX <= 46 + plus) ) {
        speakerFull(G2);
        releaseMouseButton();
        speakerOff();
    }
    if ( (posX >= 47 + plus) && (posX <= 50 + plus) ) {
        speakerFull(GSharp2);
        releaseMouseButton();
        speakerOff();
    }
    if ( (posX >= 51 + plus) && (posX <= 57 + plus) ) {
        speakerFull(A2);
        releaseMouseButton();
        speakerOff();
    }
    if ( (posX >= 58 + plus) && (posX <= 61 + plus) ) {
        speakerFull(ASharp2);
        releaseMouseButton();
        speakerOff();
    }
    if ( (posX >= 62 + plus) && (posX <= 68 + plus) ) {
        speakerFull(B2);
        releaseMouseButton();
        speakerOff();
    }
}

void secondCheck(char plus) {
    if ( (posX >= 0 + plus) && (posX <= 8 + plus) ) {
        speakerFull(C2);
        releaseMouseButton();
        speakerOff();
    }
    if ( (posX >= 9 + plus) && (posX <= 19 + plus) ) {
        speakerFull(D2);
        releaseMouseButton();
        speakerOff();
    }
    if ( (posX >= 20 + plus) && (posX <= 28 + plus) ) {
        speakerFull(E2);
        releaseMouseButton();
        speakerOff();
    }
    if ( (posX >= 29 + plus) && (posX <= 37 + plus) ) {
        speakerFull(F2);
        releaseMouseButton();
        speakerOff();
    }
    if ( (posX >= 38 + plus) && (posX <= 48 + plus) ) {
        speakerFull(G2);
        releaseMouseButton();
        speakerOff();
    }
    if ( (posX >= 49 + plus) && (posX <= 59 + plus) ) {
        speakerFull(A2);
        releaseMouseButton();
        speakerOff();
    }
    if ( (posX >= 60 + plus) && (posX <= 68 + plus) ) {
        speakerFull(B2);
        releaseMouseButton();
        speakerOff();
    }
}

/* Main */
void main() {
    char initX = 4;
    char initY = 9;

    cls();

    show(initX, initY);   // Muestra el gráfico del piano
    design(initX, initY); // Muestra etiquetas y colores

    cursorPos(0, initY + 7); // Cursor abajo de la interfaz

    initMouse();

    // Ciclo del mouse
    while(1){
        checkMouseButton();
        if(mouseButton == 1) {
            setXandY();
            if((posY == 0) && (posX >= 73) && (posX <= 79) ) {
                hideMouse();
                return;
            }
            if(posY == initY || posY == (initY + 1) || posY == (initY + 2) || posY == (initY + 3)) {
                firstCheck(initX);
            }
            if(posY == (initY + 4) || posY == (initY + 5) || posY == (initY + 6)) {
                secondCheck(initX);
            }
        }
    }
}
