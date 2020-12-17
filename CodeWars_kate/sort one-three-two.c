#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    int array[] = {4, 5, 2, 3, 1, 9, 9};
    struct Sort {
        int praviBroj;
        int sortedBroj;
    };
    struct Sort brojevi[7];
    struct Sort temp;
    int i, j;
    for (i=0;i<7;i++) brojevi[i].praviBroj = array[i];
    for (i=0;i<7;i++){    
        switch (array[i]) {
            case 1: brojevi[i].sortedBroj = 4; break;
            case 2: brojevi[i].sortedBroj = 8; break;
            case 3: brojevi[i].sortedBroj = 7; break; 
            case 4: brojevi[i].sortedBroj = 1; break;
            case 5: brojevi[i].sortedBroj = 0; break;
            case 6: brojevi[i].sortedBroj = 6; break; 
            case 7: brojevi[i].sortedBroj = 5; break;
            case 8: brojevi[i].sortedBroj = 2; break;
            case 9: brojevi[i].sortedBroj = 3; break; 
        }
    }
    for (i=0;i<7;i++) {
        for (j=0;j<7-1;j++) {
            if (brojevi[j].sortedBroj>brojevi[j+1].sortedBroj) {
                temp=brojevi[j];
                brojevi[j]=brojevi[j+1];
                brojevi[j+1]=temp;
            }
        }
    } 
    for (i=0; i<7; i++) printf("%d\n", brojevi[i].praviBroj);
    
}