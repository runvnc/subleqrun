int printf(char * s);
int getchar();

int f_to_c(int f) {
    return (f - 32)*5/9;
}

int seed = 123456789;

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

int main() {
   printf("Enter a random number seed (6 arbitrary digits): ");
   int d1 = getchar()-48;
   printf("%d", d1);   
   int d2 = getchar()-48;
   printf("%d", d2);
   int t = getchar()
   int f = d1 * 10 + d2;
   int c = f_to_c(f);
   printf( "\nTemperature in C: %d\n", c );
   seed = f * 10 + c;
   int n = rand() % 20;
   printf("Single stat roll: %d\n", _4d6());
}

