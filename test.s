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

int main() {
   printf("Enter temperature in F: ");
   int d1 = getchar()-48;
   printf("%d", d1);   
   int d2 = getchar()-48;
   printf("%d", d2);
   int f = d1 * 10 + d2;
   int c = f_to_c(f);
   printf( "\nTemperature in C: %d\n", c );
   seed = f * 10 + c;
   int n = rand() % 20;
   printf("Random number: %d\n",n);
}