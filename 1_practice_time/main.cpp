#include <stdio.h>

int main()

{

	int total_seconds = 0;
	int hours, minutes, seconds;

	//input seconds
	printf("Enter seconds: ");
	scanf_s("%d", &total_seconds);

	//calculate hours, minutes, and seconds
	hours = total_seconds / 3600;
	minutes = (total_seconds % 3600) / 60;
	seconds = total_seconds % 60;

	//output result
	printf("%d seconds = %d hours %d minutes %d seconds\n", total_seconds, hours, minutes, seconds);
		
	return 0;

}	