#include <stdio.h>

// calculates hamming distance
int hammingDist(int num1, int num2)
{
    //exclusive OR (XOR) : returns 1 if input 1 & 2 are different, 0 otherwise
	int x = num1 ^ num2; 
	int final = 0;
	while (x > 0) {
		final = final + (x & 1); // x & 1 => increment by 1 only
		x = x >> 1; //binary shift right by 1 
	}
	return final;
}

int main()
{
	printf("%d", hammingDist(0, 3));
	return 0;
}