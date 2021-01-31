#ifndef SPEAKER_H
#define SPEAKER_H

short C2       = 4560;
short CSharp2  = 4304;
short D2       = 4063;
short DSharp2  = 3834;
short E2       = 3619;
short F2       = 3416;
short FSharp2  = 3224;
short G2       = 3043;
short GSharp2  = 2873;
short A2       = 2711;
short ASharp2  = 2559;
short B2       = 2415;

char strC2[]       = {'C2','$'};
char strCSharp2[]  = {'C2','#','$'};
char strD2[]       = {'D2','$'};
char strDSharp2[]  = {'D2','#','$'};
char strE2[]       = {'E2','$'};
char strF2[]       = {'F2','$'};
char strFSharp2[]  = {'F2','#','$'};
char strG2[]       = {'G2','$'};
char strGSharp2[]  = {'G2','#','$'};
char strA2[]       = {'A2','$'};
char strASharp2[]  = {'A2','#','$'};
char strB2[]       = {'B2','$'};

void setupSpeaker() {
    _asm {
        MOV    AL, 182
        OUT    43h, AL
    }
}

void setupFrec(short frec) {
    _asm {
        MOV    AX, frec
    }
}

void sendFrec() {
    _asm {
        OUT    42h, AL
        MOV    AL, AH
        OUT    42h, AL
    }
}

void speakerOn() {
    _asm {
        IN     AL, 61h
        OR     AL, 11b
        OUT    61h, AL
    }
}

void speakerOff(){
    _asm {
        IN     AL, 61h
        AND    AL, 11111100b
        OUT    61h, AL
    }
}
void speakerFull(short frec) {
    setupSpeaker();
    setupFrec(frec);
    sendFrec();
    speakerOn();
}

#endif