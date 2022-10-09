//Timothy Baloukji
//202101807

#include <math.h>
#include <stdio.h>

// take 2s complement (revert bits)
// use bitwise "AND" between number and its 2s complement
// log2 gives the postition of the first set bit (from right to left)
int LSB(int n) { return log2(n & -n) + 1; };

// right shift while n > 0 and increment counter
int MSB(int n) {
    int i = 0;
    while (n > 0) {
        n = n >> 1;
        i++;
    }
    return i;
}

int main()  
{
    int numb;
    printf("Enter a number : \n");
    scanf("%d", &numb);
    int ans = MSB(numb) - LSB(numb);
	printf("%d", ans);
	return 0;
}