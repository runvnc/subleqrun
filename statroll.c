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

int min(int a, int b) {
    if (a<b) {
      return a;
    } else {
      return b;
    }    
}

int _4d6() {
    int lowest = 0; 
    int total = 0;
    for (int i=0; i<3; i++) {
        int roll = d6();
        lowest = min(lowest,roll);
        total += roll;
    }
    total -= lowest;
    return total;
}

void diceline(int y, char* sides) {
    setPos(5, y);
    int key = sides[0];
    fgColor(WHITE);
    char* reds = "\x1B[38;5;1m";
    char* whites = "\x1B[38;5;15m";
    printf("╔═════════════╦═════════════════════════════════╗");
    setPos(5, y+1);
    printf("║  (%s%c%s)       ║                                 ║", reds,key,whites);
    setPos(5, y+2);
    printf("╚═════════════╩═════════════════════════════════╝");
    
}

int ui() {
    fillbox(BLUE, 3, 3, 40, 13);
    diceline(5,"20");
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
     int n = rand() % 20;
     printf("Single stat roll: %d\n", _4d6());
     int d = getchar();
   }
   fgColor(WHITE);
}

