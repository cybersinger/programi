#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<string.h>
#define MAX 100

char *multiply(char *p, char *q) {
    printf("%s, %s\n", p, q);
    int a[100],b[100];
    int ans[200]={0};
    int i,j,tmp;

    int l1 = strlen(p);
    int l2 = strlen(q);
    
    for(i = l1-1,j=0;i>=0;i--,j++) {
        a[j] = p[i]-'0'; // ovako dobijamo int iz char, ali ne ASCII vrednost char nego bas taj int. Alternativa: a[j]=p[i]-48 (gde je 48 bez navodnika/apostrofa)
    }
    for(i = l2-1,j=0;i>=0;i--,j++) {
        b[j] = q[i]-'0';
    }
    
    for(i = 0;i < l2;i++) {
        for(j = 0;j < l1;j++) {
            ans[i+j] += b[i]*a[j]; //jednostavno mnozimo broj po broj, i dobijamo array tih (uglavnom dvocifrenih) proizvoda
        }
    }
    for(i = 0;i < l1+l2;i++) { //ova petlja sabira dvocifrene proizvode sa shiftom. Npr. u 45*3 proizvodi su 15 i 12, a ona odvaja 5 od 12+1=13.
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
    for(i=0, j=len;i<=len;i++, j--) {
        mul[j]=ans[i] + 48; // ovo nije moglo sa + '0'? Nisam ni probao, ovako je ok.
    }
    mul[len+1]='\0';
    printf("Konacan niz: %s\n\n", mul);
    if((strlen(p)==1 && a[0]==0) || (strlen(q)==1 && b[0]==0)) mul="0"; // ovo je dodato jer za nulu nije vraceno nista.
    
    return mul;
}

int main() {
    char a[]="99428311567709579181511604313454399240526518466506677040691936397412486137193745333339390";
    char b[]="606435388746372093660323878727007642392179926335914946435427127";
    char *c=multiply(a, b);
    printf("\n%s\n", c);
}