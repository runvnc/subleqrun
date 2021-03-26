int printf(char * s);
int getchar();

int RED = 1;
int GREEN = 2;
int WHITE = 15;
int BLACK = 0;
int BLUE = 4;
int YELLOW = 11;

void clearScreen() {
    printf("\x1B[2J");
}

void fgColor(int clr) {
    printf("\x1B[38;5;%dm", clr);
}

int bgColor(int clr) {
    printf("\x1B[48;5;%dm", clr);
}

int setPos(int x, int y) {
    printf("\x1B[%d;%dH",y,x);
}

int repeatChar(int ch, int times) {
    for (int i=0; i<times; i++) {
        printf("%c",ch);
    }    
}

int fillbox(int color, int x, int y, int w, int h) {
    bgColor(color);
    int s = y;
    for (int j=0; j<h; j++) {
        setPos(x,y+j);
        repeatChar(32, w);        
    }
}

int seed = 1234567;

int rand() {
    seed = (8121 * seed + 28411) % 134456;
    return seed;
}

int d6() {
    return rand() % 6 + 1; 
}

void diceline(int y, char* descr) {
    setPos(5, y);
    fgColor(WHITE);
    char* yellow = "\x1B[38;5;11m";
    char* whites = "\x1B[38;5;15m";
    printf("╔═══════════════╦════════════════════════════╗");
    setPos(5, y+1);
    printf("║ ");
    printf(descr,yellow,whites);
    printf("  ║                            ║");
    setPos(5, y+2);
    printf("╚═══════════════╩════════════════════════════╝");    
}

int rolls[101];
int lines[101];
int totals[101];

void initrolls() {
    for (int i=0; i<101; i++) {
        rolls[i] = 0;
        lines[i] = 0;
        totals[i] = 0;
    }
    lines[4] = 3;
    lines[6] = 6;
    lines[8] = 9;
    lines[10] = 12;
    lines[12] = 15;
    lines[20] = 18;
    lines[100] = 21;
}

void ui() {
    clearScreen();
    fillbox(BLUE, 1, 2, 51, 25);
    initrolls();
    diceline(lines[4],"(%s4%s)-sided   ");
    diceline(lines[6],"(%s6%s)-sided   " );
    diceline(lines[8], "(%s8%s)-sided   ");
    diceline(lines[10], "1(%s0%s)-sided  ");
    diceline(lines[12], "(%s1%s)2-sided  ");
    diceline(lines[20], "(%s2%s)0-sided  ");
    diceline(lines[100], "(%sh%s)100-sided");
}

void clearrolls() {
    initrolls();
    for (int i=0; i<101; i++) {
      if (lines[i] > 0) {
        setPos(22, lines[i]+1);
        bgColor(BLUE);
        repeatChar(' ',26);
      }
    }
}

int lastroll = 0;

int roll(int sides) {
    if (sides<0||sides>56) return 0;
    if (sides != lastroll) clearrolls();
    lastroll = sides;
    if (sides == 0) { sides = 10;}
    else if (sides == 1) { sides = 12; }
    else if (sides == 2) { sides = 20; }
    else if (sides == 56) { sides = 100; }
    if (lines[sides]==0) return 0;
    int r = rand() % sides + 1;
    int max = 7;
    if (sides == 100) max = 5;
    if (rolls[sides] == max) {
        clearrolls();
    }
    totals[sides] += r;
    rolls[sides] += 1;
    int n = 3;
    if (sides == 100) { n = 4; }
    setPos(20 + (rolls[sides] * n)+1, lines[sides]+1);
    fgColor(BLACK);
    bgColor(WHITE);
    printf("%d", r);
    fgColor(GREEN);
    bgColor(WHITE);
    setPos(45, lines[sides]+1);
    printf("%d", totals[sides]);
}


int getseed() {
   clearScreen();
   setPos(1,1);
   fgColor(WHITE);
   printf("Enter a random number seed (6 arbitrary characters): ");
   for (int i=0; i<6; i++) {
       int d = getchar();
       printf("%c", d);   
       seed -= d * i;
   }
   printf("\n");     
}

int main() {
   getseed();
   ui();
   setPos(10,10);
   fgColor(YELLOW);
   while (1) {
     int d = getchar();
     if (d == 'c') clearrolls();
     else roll(d-48);
   }
   fgColor(WHITE);
}

