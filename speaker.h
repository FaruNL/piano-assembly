#ifndef SPEAKER_H
#define SPEAKER_H

short C        = 9121;
short CSharp   = 8609;
short D        = 8126;
short DSharp   = 7670;
short E        = 7239;
short F        = 6833;
short FSharp   = 6449;
short G        = 6087;
short GSharp   = 5746;
short A        = 5423;
short ASharp   = 5119;
short B        = 4831;
short Middle_C = 4560;
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
short C2       = 2280;
short CSharp3  = 2152;
short D3       = 2031;
short DSharp3  = 1917;
short E3       = 1809;
short F3       = 1715;
short FSharp3  = 1612;
short G3       = 1521;
short GSharp3  = 1436;
short A3       = 1355;
short ASharp3  = 1292;
short B3       = 1207;
short C3       = 1140;

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