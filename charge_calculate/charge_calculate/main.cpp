#include <stdio.h>  

int main(void)
{
    int unit_price;     // Unit price of the item
    int quantity;       // Quantity
    int received_cash;  // Cash received from customer

    printf("Unit Price (won) : ");
    scanf_s("%d", &unit_price);

    printf("Quantity (pcs) : ");
    scanf_s("%d", &quantity);

    printf("Received Cash (won) : ");
    scanf_s("%d", &received_cash);

    printf("\n");

    // Price calculations
    int total_price = unit_price * quantity;     // Total price
    int discount = total_price / 10;             // 10% discount
    int payment_price = total_price - discount;  // Final payment amount
    int change = received_cash - payment_price;  // Total change

    int temp_change = change;

    int w1000 = temp_change / 1000;  // Number of 1000-won bills
    temp_change %= 1000;

    int w500 = temp_change / 500;    // Number of 500-won coins
    temp_change %= 500;

    int w100 = temp_change / 100;    // Number of 100-won coins
    temp_change %= 100;

    int w50 = temp_change / 50;      // Number of 50-won coins
    temp_change %= 50;

    int remainder = temp_change;     // Remaining change

    // Print results in English format
    printf("Total Price : %d won\n", total_price);
    printf("Discount (10%%) : -%d won\n", discount);
    printf("Payment Amount : %d won\n\n", payment_price);

    printf("Change : %d won\n", change);
    printf("1000-won bill : %d bill(s)\n", w1000);
    printf("500-won : %d coin(s)\n", w500);
    printf("100-won : %d coin(s)\n", w100);
    printf("50-won : %d coin(s)\n", w50);
    printf("Remainder : %d won\n", remainder);

    return 0;
}