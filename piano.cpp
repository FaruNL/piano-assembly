//#include <stdio.h>
#include <dos.h>
#include <conio.h>
#include <stdlib.h>

#include "keyboard.h"
#include "speaker.h"

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
void firstCheck() {
    if ( (posX >= 0) && (posX <= 6) ) {
        speakerFull(C2);
        releaseMouseButton();
        speakerOff();
    }
    if ( (posX >= 7) && (posX <= 10) ) {
        speakerFull(CSharp2);
        releaseMouseButton();
        speakerOff();
    }
    if ( (posX >= 11) && (posX <= 17) ) {
        speakerFull(D2);
        releaseMouseButton();
        speakerOff();
    }
    if ( (posX >= 18) && (posX <= 21) ) {
        speakerFull(DSharp2);
        releaseMouseButton();
        speakerOff();
    }
    if ( (posX >= 22) && (posX <= 28) ) {
        speakerFull(E2);
        releaseMouseButton();
        speakerOff();
    }
    if ( (posX >= 29) && (posX <= 35) ) {
        speakerFull(F2);
        releaseMouseButton();
        speakerOff();
    }
    if ( (posX >= 36) && (posX <= 39) ) {
        speakerFull(FSharp2);
        releaseMouseButton();
        speakerOff();
    }
    if ( (posX >= 40) && (posX <= 46) ) {
        speakerFull(G2);
        releaseMouseButton();
        speakerOff();
    }
    if ( (posX >= 47) && (posX <= 50) ) {
        speakerFull(GSharp2);
        releaseMouseButton();
        speakerOff();
    }
    if ( (posX >= 51) && (posX <= 57) ) {
        speakerFull(A2);
        releaseMouseButton();
        speakerOff();
    }
    if ( (posX >= 58) && (posX <= 61) ) {
        speakerFull(ASharp2);
        releaseMouseButton();
        speakerOff();
    }
    if ( (posX >= 62) && (posX <= 68) ) {
        speakerFull(B2);
        releaseMouseButton();
        speakerOff();
    }
}

void secondCheck() {
    if ( (posX >= 0) && (posX <= 8) ) {
        speakerFull(C2);
        releaseMouseButton();
        speakerOff();
    }
    if ( (posX >= 9) && (posX <= 19) ) {
        speakerFull(D2);
        releaseMouseButton();
        speakerOff();
    }
    if ( (posX >= 20) && (posX <= 28) ) {
        speakerFull(E2);
        releaseMouseButton();
        speakerOff();
    }
    if ( (posX >= 29) && (posX <= 37) ) {
        speakerFull(F2);
        releaseMouseButton();
        speakerOff();
    }
    if ( (posX >= 38) && (posX <= 48) ) {
        speakerFull(G2);
        releaseMouseButton();
        speakerOff();
    }
    if ( (posX >= 49) && (posX <= 59) ) {
        speakerFull(A2);
        releaseMouseButton();
        speakerOff();
    }
    if ( (posX >= 60) && (posX <= 68) ) {
        speakerFull(B2);
        releaseMouseButton();
        speakerOff();
    }
}

/* Main */
void main() {
    cls();

    show(); // Muestra el gráfico del piano

    cursorPos(0, 7);

    initMouse();

    // Ciclo del mouse
    while(1){
        checkMouseButton();
        if(mouseButton == 1) {
            setXandY();
            switch(posY){
                case 0:
                firstCheck();
                    if(posX == 79) {
                        hideMouse();
                        return;
                    }
                break;

                case 1:
                    firstCheck();
                break;

                case 2:
                    firstCheck();
                break;

                case 3:
                    firstCheck();
                break;

                case 4:
                    secondCheck();
                break;

                case 5:
                    secondCheck();
                break;

                case 6:
                    secondCheck();
                break;
            }
        }
    }
}
