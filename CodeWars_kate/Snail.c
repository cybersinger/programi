
#include <stdio.h>
#include <stdlib.h>

int main() 
{ 
   int n=0; // ovaj ne prenosis
   int mx[0][0]={}; // ovo ne prenosis
   int* s = malloc((n*n+1) * sizeof(int));
   int r, a=0, b=0, ns=-1, nj=-1, k=0;
   int i,j, flip=1;
   int ctra=0, ctrb=3, ctrns=2, ctrj=0;
   int rounds=0;
   
   for (r=0;r<2*n-1;r++) {
      if (ctra==4) {
         a=a+1;
         ctra=0;
      }
      if (ctrb==4) {
         b=b+1;
         ctrb=0;
      }
      if (ctrns==4) {
         ns=ns-1;
         ctrns=0;
      }
      if (ctrj==4) {
         nj=nj-1;
         ctrj=0;
      }

      if (rounds==0) {
         for (i=a; i<=n+ns; i++) {  
            s[k]=mx[a][i];
            k++;
         }               
         //printf("loop pocinje od %d, i ide do %d. Vrednost k u krugu %d, treba do 3+1 da ide=%d\n", a, n+ns, r, k);  
      }
      if (rounds==1) {
         for (j=b; j<=n+ns; j++) {
            s[k]=mx[j][n+nj];
            k++;
         }
         //printf("loop pocinje od %d, i ide do %d. Vrednost k u krugu %d, treba do 6+1 da ide=%d\n", b, n+ns, r, k); 
      }
      if (rounds==2) {
         for (i=n+ns; i>=a; i--) {
            s[k]=mx[n+nj][i];
            k++;
         }
         //printf("i=%d, ns=%d, a=%d, k=%d\n", i, ns, a, k); 
      }
      if (rounds==3) {
         for (j=n+ns; j>=b; j-- ) {
            s[k]=mx[j][a];
            k++;
         }
         //printf("loop %d pocinje od %d, i ide do %d. Vrednost k u krugu %d, treba do 9+1 da ide=%d\n", rounds, n+ns, b, r, k); 
      }

      ctra++;
      ctrb++;
      ctrns++;
      ctrj++;
      rounds++;
      if (rounds==4) rounds=0;
      
      //printf("Krug: %d, a=%d, b=%d, ns=%d, k na kraju=%d, rounds=%d\n", r, a, b, ns, k, rounds);

   }
   printf("Rezultat: \n");
   for (int l=0;l<n*n;l++) printf("%d, ", s[l]);
   printf("\nVrednost k=%d", k);
}
