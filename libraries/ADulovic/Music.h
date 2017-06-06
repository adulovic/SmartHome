/* Notes
=========1=========2=========3=========4=========5=========6=========7========*/
#define nC0  16.35
#define nDb0 17.32
#define nD0  18.35
#define nEb0 19.45
#define nE0  20.60
#define nF0  21.83
#define nGb0 23.12
#define nG0  24.50
#define nAb0 25.96
#define nA0 27.50
#define nBb0 29.14
#define nB0  30.87
#define nC1  32.70
#define nDb1 34.65
#define nD1  36.71
#define nEb1 38.89
#define nE1  41.20
#define nF1  43.65
#define nGb1 46.25
#define nG1  49.00
#define nAb1 51.91
#define nA1 55.00
#define nBb1 58.27
#define nB1  61.74
#define nC2  65.41
#define nDb2 69.30
#define nD2  73.42
#define nEb2 77.78
#define nE2  82.41
#define nF2  87.31
#define nGb2 92.50
#define nG2  98.00
#define nAb2 103.83
#define nA2 110.00
#define nBb2 116.54
#define nB2  123.47
#define nC3  130.81
#define nDb3 138.59
#define nD3  146.83
#define nEb3 155.56
#define nE3  164.81
#define nF3  174.61
#define nGb3 185.00
#define nG3  196.00
#define nAb3 207.65
#define nA3 220.00
#define nBb3 233.08
#define nB3  246.94
#define nC4  261.63
#define nDb4 277.18
#define nD4  293.66
#define nEb4 311.13
#define nE4  329.63
#define nF4  349.23
#define nGb4 369.99
#define nG4  392.00
#define nAb4 415.30
#define nA4 440.00
#define nBb4 466.16
#define nB4  493.88
#define nC5  523.25
#define nDb5 554.37
#define nD5  587.33
#define nEb5 622.25
#define nE5  659.26
#define nF5  698.46
#define nGb5 739.99
#define nG5  783.99
#define nAb5 830.61
#define nA5 880.00
#define nBb5 932.33
#define nB5  987.77
#define nC6  1046.50
#define nDb6 1108.73
#define nD6  1174.66
#define nEb6 1244.51
#define nE6  1318.51
#define nF6  1396.91
#define nGb6 1479.98
#define nG6  1567.98
#define nAb6 1661.22
#define nA6 1760.00
#define nBb6 1864.66
#define nB6  1975.53
#define nC7  2093.00
#define nDb7 2217.46
#define nD7  2349.32
#define nEb7 2489.02
#define nE7  2637.02
#define nF7  2793.83
#define nGb7 2959.96
#define nG7  3135.96
#define nAb7 3322.44
#define nA7 3520.01
#define nBb7 3729.31
#define nB7  3951.07
#define nC8  4186.01
#define nDb8 4434.92
#define nD8  4698.64
#define nEb8 4978.03

/* Durations of Notes
=========1=========2=========3=========4=========5=========6=========7========*/
#define BPM 120    //  you can change this value changing all the others
#define Q 60000/BPM //quarter 1/4 
#define H 2*Q //half 2/4
#define E Q/2   //eighth 1/8
#define S Q/4 // sixteenth 1/16
#define W 4*Q // whole 4/4

/* Melody
=========1=========2=========3=========4=========5=========6=========7========*/
void ImperialMarch(){
    // tone(pin, note, duration)
    tone(pinA5,nA3,Q); 
    // delay should always be 1 ms more than the note in order to separate them.
    delay(1+Q);
    tone(pinA5,nA3,Q);
    delay(1+Q);
    tone(pinA5,nA3,Q);
    delay(1+Q);
    tone(pinA5,nF3,E+S);
    delay(1+E+S);
    tone(pinA5,nC4,S);
    delay(1+S);
    
    tone(pinA5,nA3,Q);
    delay(1+Q);
    tone(pinA5,nF3,E+S);
    delay(1+E+S);
    tone(pinA5,nC4,S);
    delay(1+S);
    tone(pinA5,nA3,H);
    delay(1+H);
    
    tone(pinA5,nE4,Q); 
    delay(1+Q); 
    tone(pinA5,nE4,Q);
    delay(1+Q);
    tone(pinA5,nE4,Q);
    delay(1+Q);
    tone(pinA5,nF4,E+S);
    delay(1+E+S);
    tone(pinA5,nC4,S);
    delay(1+S);
    
    tone(pinA5,nAb3,Q);
    delay(1+Q);
    tone(pinA5,nF3,E+S);
    delay(1+E+S);
    tone(pinA5,nC4,S);
    delay(1+S);
    tone(pinA5,nA3,H);
    delay(1+H);
    
    tone(pinA5,nA4,Q);
    delay(1+Q);
    tone(pinA5,nA3,E+S);
    delay(1+E+S);
    tone(pinA5,nA3,S);
    delay(1+S);
    tone(pinA5,nA4,Q);
    delay(1+Q);
    tone(pinA5,nAb4,E+S);
    delay(1+E+S);
    tone(pinA5,nG4,S);
    delay(1+S);
    
    tone(pinA5,nGb4,S);
    delay(1+S);
    tone(pinA5,nE4,S);
    delay(1+S);
    tone(pinA5,nF4,E);
    delay(1+E);
    delay(1+E);//PAUSE
    tone(pinA5,nBb3,E);
    delay(1+E);
    tone(pinA5,nEb4,Q);
    delay(1+Q);
    tone(pinA5,nD4,E+S);
    delay(1+E+S);
    tone(pinA5,nDb4,S);
    delay(1+S);
    
    tone(pinA5,nC4,S);
    delay(1+S);
    tone(pinA5,nB3,S);
    delay(1+S);
    tone(pinA5,nC4,E);
    delay(1+E);
    delay(1+E);//PAUSE QUASI FINE RIGA
    tone(pinA5,nF3,E);
    delay(1+E);
    tone(pinA5,nAb3,Q);
    delay(1+Q);
    tone(pinA5,nF3,E+S);
    delay(1+E+S);
    tone(pinA5,nA3,S);
    delay(1+S);
    
    tone(pinA5,nC4,Q);
    delay(1+Q);
     tone(pinA5,nA3,E+S);
    delay(1+E+S);
    tone(pinA5,nC4,S);
    delay(1+S);
    tone(pinA5,nE4,H);
    delay(1+H);
    
     tone(pinA5,nA4,Q);
    delay(1+Q);
    tone(pinA5,nA3,E+S);
    delay(1+E+S);
    tone(pinA5,nA3,S);
    delay(1+S);
    tone(pinA5,nA4,Q);
    delay(1+Q);
    tone(pinA5,nAb4,E+S);
    delay(1+E+S);
    tone(pinA5,nG4,S);
    delay(1+S);
    
    tone(pinA5,nGb4,S);
    delay(1+S);
    tone(pinA5,nE4,S);
    delay(1+S);
    tone(pinA5,nF4,E);
    delay(1+E);
    delay(1+E);//PAUSE
    tone(pinA5,nBb3,E);
    delay(1+E);
    tone(pinA5,nEb4,Q);
    delay(1+Q);
    tone(pinA5,nD4,E+S);
    delay(1+E+S);
    tone(pinA5,nDb4,S);
    delay(1+S);
    
    tone(pinA5,nC4,S);
    delay(1+S);
    tone(pinA5,nB3,S);
    delay(1+S);
    tone(pinA5,nC4,E);
    delay(1+E);
    delay(1+E);//PAUSE QUASI FINE RIGA
    tone(pinA5,nF3,E);
    delay(1+E);
    tone(pinA5,nAb3,Q);
    delay(1+Q);
    tone(pinA5,nF3,E+S);
    delay(1+E+S);
    tone(pinA5,nC4,S);
    delay(1+S);
    
    tone(pinA5,nA3,Q);
    delay(1+Q);
     tone(pinA5,nF3,E+S);
    delay(1+E+S);
    tone(pinA5,nC4,S);
    delay(1+S);
    tone(pinA5,nA3,H);
    delay(1+H);
    
    delay(2*H);
}
