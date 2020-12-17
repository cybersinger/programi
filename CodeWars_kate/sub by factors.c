#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// In C return a char *
char* sumOfDivided(int* lst, int l) {
    int i, j=3, k=1, is_prime=1;
    int primes[1000]={-1}; primes[0]=2;
    int max, maxPos=lst[0], maxNeg=lst[0];

    for (i=1; i<l; i++) {
        if (lst[i]>0 && lst[i]>maxPos) maxPos=lst[i];
        if (lst[i]<0 && lst[i]<maxNeg) maxNeg=(-1)*lst[i];
        if (maxPos>maxNeg) max=maxPos;
        else max=maxNeg;
    }

    for (i=3;i<=max;i+=2) {
        is_prime=1;
        for (j=3;j<i;j+=2) {
            if (i%j==0) {
                is_prime=0;
                break;
            }
        }
        if (is_prime==1) {
            primes[k]=i;
            k++;
        }
    }

    int sums[k];
    int r=0, flag=0, p=0;
    char* res = calloc(k+1, sizeof(char)*10);

    for (i=0;i<k;i++){
        sums[i]=0;
        for (j=0;j<l;j++) {
            if (lst[j]%primes[i]==0) {
                sums[i]=sums[i]+lst[j];
                flag=1;
            }
        }
        
        if (flag==1) {
            sprintf(&res[r], "(%d, %d)", primes[i], sums[i]);
        }
        while (res[r]!=0) r++;
        flag=0;
    }
    //printf("%s, max=%d\n", res, max);

    return res;
}

int main() {
    int d1[2] = {12, 15};
    char *res=sumOfDivided(d1, 2);
    printf("%s\n", res);
    free(res); res=NULL;
    printf("%s\n", res); // Dokaz da sam oslobodio alociranu memoriju
}