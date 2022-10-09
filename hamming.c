//Timothy Baloukji
//202101807

#include <stdio.h>

// calculates hamming distance
int hammingDist(int num1, int num2)
{
    //exclusive OR (XOR) : returns 1 if input 1 & 2 are different, 0 otherwise
	int x = num1 ^ num2; 
	int final = 0;
	while (x > 0) {
		final = final + (x & 1); // x & 1 => increment by 1 only
		x = x >> 1; //binary shift right by 0 11 
	}
	return final;
}

int main()
{
    int num1, num2;
    scanf("%d %d", &num1,&num2);
    while (num1 >= 0 && num2 >= 0) {
        printf("%d\n", hammingDist(num1, num2));
        scanf("%d %d", &num1,&num2);
    }
	return 0;
}