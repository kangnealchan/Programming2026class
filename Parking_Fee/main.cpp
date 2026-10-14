#include <stdio.h>

int main() 

{
    int n = 0;
    // Input the number of cars to settle (1~10), re-enter if out of range
    while (1)
    
    {
        printf("Number of cars to settle (1-10): ");
        scanf_s("%d", &n);
        if (n >= 1 && n <= 10) {
            break;
        }
        printf("-> Please enter a number between 1 and 10.\n");
    }

    int total_revenue = 0;      // Total settlement revenue
    int max_fee = -1;           // Maximum fee
    int max_fee_car_num = 0;    // Car number with the maximum fee

    // Loop for each car
    for (int i = 1; i <= n; i++)
    {
        printf("\n[%d-th Car]\n", i);

        int car_type;
        printf("Car Type (1: Light, 2: Regular, 3: Electric): ");
        scanf_s("%d", &car_type);

        int parking_min = -1;
    
        //Re-enter parking time if it is negative
        while (1)
        {
            printf("Parking Time (minutes): ");
            scanf_s("%d", &parking_min);
            if (parking_min >= 0) {
                break;
            }
            printf("-> Please enter 0 or greater: ");
        }

        int base_fee = 0;

        //Calculate base fee
        if (parking_min <= 30)
        {
            base_fee = 0; // Free for 30 minutes or less
        }
        else 
        
        {
            int extra_min = parking_min - 30;
            // Round up for less than 10 minutes (trick: (extra_min + 9) / 10)
            int units = (extra_min + 9) / 10;
            base_fee = units * 500;

            // Maximum daily fee limit of 20,000 won
            if (base_fee > 20000)
            {
                base_fee = 20000;
            }
        }

        //Apply discount rate by car type (calculated after applying the maximum fee)
        int discount_percent = 0;
        if (car_type == 1) 
        {
            discount_percent = 50; // Light car 50% discount
        }
        else if (car_type == 2) 
        {
            discount_percent = 0;  // Regular car 0% discount
        }
        else if (car_type == 3)
        {
            discount_percent = 30; // Electric car 30% discount
        }
        else
        {
            printf("Applying regular fee policy.\n");
            discount_percent = 0;
        }

        // Calculate final fee (base fee - discount amount)
        int final_fee = base_fee * (100 - discount_percent) / 100;

        // Output results
        printf("Fee: %d won (Discount %d%%)\n", final_fee, discount_percent);

        // Accumulate total revenue
        total_revenue += final_fee;

        // Determine the car with the highest fee
        if (final_fee > max_fee) 
        {
            max_fee = final_fee;
            max_fee_car_num = i;
        }
    }

    // Output final statistics
    printf("\nTotal Revenue: %d won\n", total_revenue);
    printf("Highest Fee: Car %d (%d won)\n", max_fee_car_num, max_fee);

    return 0;
}