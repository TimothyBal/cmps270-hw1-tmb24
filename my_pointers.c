//Timothy Baloukji
//202101807

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char** merge(int m, int n, char** a, char** b){
    int i=0, j=0, k=0;
    char** ans = malloc(20 * sizeof(char*));
    for (int i =0 ; i < 10; ++i)
        ans[i] = malloc(20 * sizeof(char));
    // check if string at ith position is smaller than the string at jth position
    // if so , move the 'i' pointer forward, else move 'j' forward
    while(j<n && i<m){
        if(strcmp(a[i], b[j]) <= 0) {
            strcpy(ans[k++], a[i++]);
        } else {
            strcpy(ans[k++], b[j++]);
        };
    }
    while(i<m) {
        strcpy(ans[k++], a[i++]);
    }
    while(j<n) {
        strcpy(ans[k++], b[j++]); 
    }
    return ans;
}
int main(){
    char *a[3] = {"ab", "ac", "zd"}, *b[4] = {"za", "zb", "zzzzc"};
    char **ans = merge(3, 3, a, b);
    for(int i=0; i<6; i++) printf("%s\n", ans[i]);
    return 0;
}