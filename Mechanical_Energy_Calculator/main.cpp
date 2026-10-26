#include <stdio.h>

#define Menu_EXIT 0
#define Menu_KINETIC 1
#define Menu_POTENTIAL 2
#define Menu_FREEFALL 3
#define G 9.81

// Read a positive value
double getPositive(void)
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

// Display energy in joules and kilojoules
void printEnergy(double energy)
{
    if (energy >= 1000)
    {
        printf("Energy: %.3f J (%.3f kJ)\n",
            energy, energy / 1000);
    }
    else
    {
        printf("Energy: %.3f J\n", energy);
    }
}

// Display the main menu
void printMenu(void)
{
    printf("===== Mechanical Energy Calculator =====\n");
    printf("1. Kinetic energy  2. Potential energy\n");
    printf("3. Free-fall table  0. Exit\n");
    printf("Selection: ");
}

// Calculate kinetic energy
double calcKineticEnergy(double mass, double speed)
{
    return 0.5 * mass * speed * speed;
}

// Calculate potential energy
double calcPotentialEnergy(double mass, double height)
{
    return mass * G * height;
}

// Calculate kinetic energy during free fall
double calcFreeFallKE(double mass, double startHeight, double height)
{
    return mass * G * (startHeight - height);
}

int main(void)
{
    int selection;
    double mass, speed, height;
    double energy, potentialEnergy, kineticEnergy;
    double totalEnergy;

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
            printf("Exiting the program...\n");
            break;
        }

        switch (selection)
        {
        case Menu_KINETIC:
            printf("Mass (kg): ");
            mass = getPositive();

            printf("Speed (m/s): ");
            speed = getPositive();

            energy = calcKineticEnergy(mass, speed);

            printEnergy(energy);
            break;

        case Menu_POTENTIAL:
            printf("Mass (kg): ");
            mass = getPositive();

            printf("Height (m): ");
            height = getPositive();

            energy = calcPotentialEnergy(mass, height);

            printEnergy(energy);
            break;

        case Menu_FREEFALL:
            printf("Mass (kg): ");
            mass = getPositive();

            printf("Start height (m): ");
            height = getPositive();

            totalEnergy = calcPotentialEnergy(mass, height);

            printf("\nHeight(m),PE(J),KE(J),Total(J)\n");

            for (int i = 5; i >= 0; i--)
            {
                double currentHeight;
                currentHeight = height * i / 5.0;

                potentialEnergy =
                    calcPotentialEnergy(mass, currentHeight);

                kineticEnergy =
                    calcFreeFallKE(mass, height, currentHeight);

                printf("%8.3f  %8.3f  %8.3f  %8.3f\n", currentHeight, potentialEnergy, kineticEnergy, totalEnergy);
            }

            printf("\n");
            printEnergy(totalEnergy);
            break;

        default:
            printf("Invalid selection. Please try again.\n");
            break;
        }

        printf("\n");
    }

    return 0;
}