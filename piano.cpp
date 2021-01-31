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

char keyPressed() {
    char key;
    _asm {
        MOV     AH, 08h
        INT     21H

        MOV     key, AL
    }
    
    return key;
}

void printChar(char value) {
    _asm {
		MOV AH, 02h
        MOV DL, value
		INT 21h
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

/* Main */
void main() {
    cls();

    show(); // Muestra el gráfico del piano

    initMouse();

    // Ciclo del mouse
    while(1){
        checkMouseButton();
        if(mouseButton == 1) {
            releaseMouseButton();
            setXandY();
            switch(posY){
                case 0:
                    if ( (posX >= 0) && (posX <= 6) ) {
                        speakerFull(C);
                    }
                    if ( (posX >= 7) && (posX <= 10) ) {
                        speakerFull(CSharp);
                    }
                    if(posX == 79) {
                        hideMouse();
                        return;
                    }
                break;

                case 1:
                    if ( (posX >= 0) && (posX <= 6) ) {
                        speakerFull(C);
                    }
                    if ( (posX >= 7) && (posX <= 10) ) {
                        speakerFull(CSharp);
                    }
                break;

                case 2:
                    if ( (posX >= 0) && (posX <= 6) ) {
                        speakerFull(C);
                    }
                    if ( (posX >= 7) && (posX <= 10) ) {
                        speakerFull(CSharp);
                    }
                break;

                case 3:
                    if ( (posX >= 0) && (posX <= 6) ) {
                        speakerFull(C);
                    }
                    if ( (posX >= 7) && (posX <= 10) ) {
                        speakerFull(CSharp);
                    }
                break;

                case 4:
                    if ( (posX >= 0) && (posX <= 8) ) {
                        speakerFull(C);
                    }
                break;

                case 5:
                    if ( (posX >= 0) && (posX <= 8) ) {
                        speakerFull(C);
                    }
                break;

                case 6:
                    if ( (posX >= 0) && (posX <= 8) ) {
                        speakerFull(C);
                    }
                break;
            }
        }
    }
}
