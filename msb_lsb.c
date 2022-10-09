#include <math.h>
#include <stdio.h>

// take 2s complement (revert bits)
// use bitwise AND between number and its 2s complement
// log2 gives the postition of the first set bit (from right to left)
int LSB(int n) { return log2(n & -n); };


int main()  
{
    int ans = LSB(28);
	printf("%d", ans);
	return 0;
}