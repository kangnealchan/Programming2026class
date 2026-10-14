#include <stdio.h>

int main()
{
	int total_count = 0; // Count of total items sold
	int total_revenue = 0; // Total revenue in won

	
	while (1)

	{
		int menu;
		int price = 0;

		// Display the vending machine menu

		printf("\n==== Vending Machine ====\n");
		printf("1. Coke - 1500 won\n");
		printf("2. Coffee - 1000 won\n");
		printf("3. Water - 800 won\n");
		printf("4. Exit\n");
		printf("Choose an option: ");
		scanf_s("%d", &menu);

		// Process the user's selection
		switch (menu)
		{
		case 1:
			price = 1500;
			break;
		case 2:
			price = 1000;
			break;
		case 3:
			price = 800;
			break;
		case 4:
			printf("\n==== Total results ====\n");
			printf("Today's sold: %d, Revenue: %d won\n", total_count, total_revenue);
			return 0; // Exit the program
		default:
			printf("Invalid option. Please try again.\n");
			continue;
		
		}

		int inserted_money = 0; // Amount of money inserted by the user

		// Prompt the user to insert money until it meets or exceeds the price	
		while (inserted_money < price)

		{
			int money;
			printf("insert Now %d(won)/Need(%d): ", inserted_money, price);
			scanf_s("%d", &money);

			if (money == 100 || money == 500 || money == 1000)
			{
				inserted_money += money;
			}
			else
			{
				printf("Invalid denomination. Please insert 100, 500, or 1000 won.\n");
				continue;
			}

			// Check if the inserted money is still less than the price
			if (inserted_money < price)
			{
				printf("Insufficient funds. Please insert more money.\n");
			}

		}

		// Calculate and display the change
		int change = inserted_money - price;
		printf("Help yourself! Your change is %d won.\n", change);

		if (change == 0)
		{
			printf("There is no change.\n");
		}
		else
		{
			int c500 = change / 500;
			int c100 = (change % 500) / 100;
			printf("500 won coins: %d, 100 won coins: %d\n", c500, c100);
		}

		// Update the total count and revenue
		total_count++;
		total_revenue += price;
	}

	return 0;
}