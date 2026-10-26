#include <stdio.h>

#define Menu_EXIT 0
#define Menu_VOLTAGE 1
#define Menu_CURRENT 2
#define Menu_RESISTANCE 3
#define Menu_SWEEP 4

// Read a positive value
double getPositive()
{
    double value;

    while (1)
    {
        if (scanf_s("%lf", &value) != 1)
        {
            printf("Invalid input. Enter a number: ");

            while (getchar() != '\n')
            {
            }

            continue;
        }

        if (value > 0)
        {
            return value;
        }

        printf("Value must be positive. Enter again: ");
    }
}

// Display voltage, current, resistance, and power
void printResult(double voltage, double current, double resistance)
{
    double power;

    power = voltage * current;

    printf("Voltage: %.2f V\n", voltage);
    printf("Current: %.2f A\n", current);
    printf("Resistance: %.2f Ohms\n", resistance);
    printf("Power: %.2f W\n", power);
}

// Display the main menu
void printMenu(void)
{
    printf("===== Ohm's Law Calculator =====\n");
    printf("1. Voltage  2. Current  3. Resistance\n");
    printf("4. Sweep table  0. Exit\n");
    printf("Selection: ");
}

// Calculate voltage using Ohm's law
double calcVoltage(double current, double resistance)
{
    return current * resistance;
}

// Calculate current using Ohm's law
double calcCurrent(double voltage, double resistance)
{
    return voltage / resistance;
}

// Calculate resistance using Ohm's law
double calcResistance(double voltage, double current)
{
    return voltage / current;
}

int main(void)
{
    int selection;
    double voltage, current, resistance;

    while (1)
    {
        printMenu();

        if (scanf_s("%d", &selection) != 1)
        {
            printf("Invalid selection. Enter a number.\n");

            while (getchar() != '\n')
            {
            }

            continue;
        }

        if (selection == Menu_EXIT)
        {
            printf("Exiting...\n");
            break;
        }

        switch (selection)
        {
        case Menu_VOLTAGE:
            printf("Enter current (A): ");
            current = getPositive();

            printf("Enter resistance (Ohms): ");
            resistance = getPositive();

            voltage = calcVoltage(current, resistance);

            printResult(voltage, current, resistance);
            break;

        case Menu_CURRENT:
            printf("Enter voltage (V): ");
            voltage = getPositive();

            printf("Enter resistance (Ohms): ");
            resistance = getPositive();

            current = calcCurrent(voltage, resistance);

            printResult(voltage, current, resistance);
            break;

        case Menu_RESISTANCE:
            printf("Enter voltage (V): ");
            voltage = getPositive();

            printf("Enter current (A): ");
            current = getPositive();

            resistance = calcResistance(voltage, current);

            printResult(voltage, current, resistance);
            break;

        case Menu_SWEEP:
            printf("Enter resistance (Ohms): ");
            resistance = getPositive();

            printf("Sweep table:\n");

            for (voltage = 1; voltage <= 5; voltage++)
            {
                current = calcCurrent(voltage, resistance);

                printResult(voltage, current, resistance);
                printf("\n");
            }
            break;

        default:
            printf("Invalid selection. Please try again.\n");
            break;
        }

        printf("\n");
    }

    return 0;
}