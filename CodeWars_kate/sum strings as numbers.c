#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<string.h>
#define MAX 100

char *add(char *p, char *q) {
     printf("%s, %s, %d, %d\n", p, q, strlen(p), strlen(q));
    int a[100],b[100];
    int ans[200]={0};
    int i,j,tmp;

    int l1 = strlen(p);
    int l2 = strlen(q);
    int lmax;
    if (l2>l1) lmax=l2;
    else lmax=l1;
    
    for(i = l1-1,j=0;i>=0;i--,j++) {
        a[j] = p[i]-'0'; // ovako dobijamo int iz char, ali ne ASCII vrednost char nego bas taj int. Alternativa: a[j]=p[i]-48 (gde je 48 bez navodnika/apostrofa)
    }
    for(i = l2-1,j=0;i>=0;i--,j++) {
        b[j] = q[i]-'0';
    }
    
    if (l1==0) a[0]=0;
    if (l2==0) b[0]=0;

    if (l2>l1){
        for (i=l1;i<l2;i++) a[i]=0;
    }
    else {
        for (i=l2;i<l1;i++) b[i]=0;
    }
    


    for(i = 0;i < lmax;i++) {
            ans[i] += b[i]+a[i]; //sabiramo broj po broj, i dobijamo array tih (uglavnom dvocifrenih) proizvoda
    }

    for(i=0; i<lmax+1; i++) { //ova petlja sabira dvocifrene proizvode sa shiftom. Npr. u 45*3 proizvodi su 15 i 12, a ona odvaja 5 od 12+1=13.
        tmp = ans[i]/10; 
        ans[i] = ans[i]%10;
        ans[i+1] = ans[i+1] + tmp;
    }
    for(i = l1+l2; i>= 0;i--) { // ova petlja nalazi pocetak array-a gde je smesten rezultat. Inicirali smo ans[]={0}, sad idemo dok se ne pojavi >0, i tu je i=duzina
        if(ans[i] > 0)
            break;
    }
    int len=i; // ovo sam ja dodao da bih dole opet mogao i da koristim za petlju.
    char* mul=calloc(l1+l2, sizeof(char));
    
    int zbirZbira=0;
    for (i=0;i<=len;i++) zbirZbira+=ans[i];
    if(zbirZbira==0) {mul[0]='0'; mul[1]='\0'; return mul;}
    if(strlen(p)==0 && strlen(q)==0) {mul='0'; mul[1]='\0'; return mul;}
  

    for(i=0, j=len;i<=len;i++, j--) {
        mul[j]=ans[i] + 48; // ovo nije moglo sa + '0'? Nisam ni probao, ovako je ok.
        printf("%d", ans[i]); printf("\n");
    }
    mul[len+1]='\0';
        
    return mul;
}

int main() {
    char a[]="";
    char b[]="0";
    char *c=add(a, b);
    printf("%s\n", c);
}