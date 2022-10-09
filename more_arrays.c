//Timothy Baloukji
//202101807

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//assume each element has 3 strings each
char** concat (char *input [][3], int numOfStrings) {
    char **answer = malloc (sizeof (char *) * numOfStrings);  
    for (int i = 0; i < numOfStrings; i++) {
        answer [i] = malloc (sizeof (char) * 20); 
        int position = 0; int j = 0;
        while (j<3) {
            strcpy (answer [i] + position, input [i][j]);      //copy string to current position 
            position = strlen (answer [i]);
            strcpy (answer [i] + position, " ");            
            position++; j++;
        }
        answer [i][position - 1] = '\0'; // put "\0" to end the string
    }
    return answer;
}
int main()  
{
    char *array [][3] = {{"I", "LOVE", "CODING"}, {"THIS", "IS", "SPARTA"}};
    char **final = concat (array, 2);
    printf ("|%s|\n|%s|\n", final [0], final [1]);
    free (final [1]);free (final [0]);  //free allocated space
    return 0;
}