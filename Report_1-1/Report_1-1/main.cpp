#include <stdio.h>

int main(void) 

{
    
    int input_num = 0; // Variable to store input

    printf("Enter the number: "); // Print prompt message
    scanf_s("%d", &input_num); // Read user input

    printf("Entered value: %d\n", input_num); // Print entered value

    return 0;

}