#include <stdio.h>

float temperature1(float reading)
{
    return (reading * 9) / 5 + 32;
}

float temperature2(float reading)
{
    return (reading - 32) * 5 / 9;
}

float temperature3(float reading)
{
    return reading + 273;
}

float temperature4(float reading)
{
    return ((reading - 32) * 5 / 9) + 273;
}

float length1(float reading)
{
    return reading / 1000;
}

float length2(float reading)
{
    return reading * 1000;
}

float length3(float reading)
{
    return reading / 1.6;
}

float length4(float reading)
{
    return (reading / 1000) / 1.6;
}

float currency1(float reading)
{
    return reading * 0.013;
}

float currency2(float reading)
{
    return reading * 0.010;
}

float currency3(float reading)
{
    return reading * 74.97;
}

float currency4(float reading)
{
    return reading * 99.62;
}

int main()
{
    printf("WELCOME TO A CONVERSION PROGRAM\n");
    printf("*-------------------------------------*\n");

    while (1)
    {
        printf("\t\tMAIN MENU\n");
        printf("\t\t1. TEMPERATURE CONVERSION\n");
        printf("\t\t2. LENGTH CONVERSION\n");
        printf("\t\t3. CURRENCY CONVERSION\n");
        printf("\t\t4. EXIT\n");
        printf("*-------------------------------------*\n");

        int choice1;
        printf("Enter the Choice: ");
        scanf("%d", &choice1);

        if (choice1 == 1)
        {
            // Temperature conversion menu...
            printf("\nTEMPERATURE CONVERSION\n");
            printf("1. CELSIUS-FAHRENHEIT\n");
            printf("2. FAHRENHEIT-CELSIUS\n");
            printf("3. CELSIUS-KELVIN\n");
            printf("4. FAHRENHEIT-KELVIN\n");
            printf("5. EXIT\n");

            int choice2;
            printf("Enter the Choice: ");
            scanf("%d", &choice2);
            float reading;

            if (choice2 != 5)
            {
                
                printf("Enter the Reading: ");
                scanf("%f", &reading);
            }

            if (choice2 == 1)
            {
                printf("The Equivalent Fahrenheit is %.2f Degree Fahrenheit\n", temperature1(reading));
            }
            else if (choice2 == 2)
            {
                printf("The Equivalent Celsius is %.2f Degree Celsius\n", temperature2(reading));
            }
            else if (choice2 == 3)
            {
                printf("The Equivalent Kelvin is %.2f Degree Kelvin\n", temperature3(reading));
            }
            else if (choice2 == 4)
            {
                printf("The Equivalent Kelvin is %.2f Degree Kelvin\n", temperature4(reading));
            }
            else if (choice2 == 5)
            {
                continue;
            }
        }
        else if (choice1 == 2)
        {
            // Length conversion menu...
            printf("\nLENGTH CONVERSION\n");
            printf("1. METER-KILOMETER\n");
            printf("2. KILOMETER-METER\n");
            printf("3. KILOMETER-MILES\n");
            printf("4. METER-MILES\n");
            printf("5. EXIT\n");

            int choice3;
            printf("Enter the Choice: ");
            scanf("%d", &choice3);

            float reading;
            if (choice3 != 5)
            {
                
                printf("Enter the Reading: ");
                scanf("%f", &reading);
            }

            if (choice3 == 1)
            {
                printf("The Equivalent Kilometer is %.2f KM\n", length1(reading));
            }
            else if (choice3 == 2)
            {
                printf("The Equivalent Meter is %.2f M\n", length2(reading));
            }
            else if (choice3 == 3)
            {
                printf("The Equivalent Miles is %.2f Miles\n", length3(reading));
            }
            else if (choice3 == 4)
            {
                printf("The Equivalent Miles is %.2f Miles\n", length4(reading));
            }
            else if (choice3 == 5)
            {
                break;
            }
        }
        else if (choice1 == 3)
        {
            // Currency conversion menu...
            printf("\nCURRENCY CONVERSION\n");
            printf("1. INR-DOLLAR\n");
            printf("2. INR-POUND\n");
            printf("3. DOLLAR-INR\n");
            printf("4. POUND-INR\n");
            printf("5. EXIT\n");

            int choice4;
            printf("Enter the Choice: ");
            scanf("%d", &choice4);

            float reading;
           if (choice4 != 5)
            {
                
                printf("Enter the Reading: ");
                scanf("%f", &reading);
            }

            if (choice4 == 1)
            {
                printf("The Equivalent Dollar is %.2f Dollar\n", currency1(reading));
            }
            else if (choice4 == 2)
            {
                printf("The Equivalent Pound is %.2f Pound\n", currency2(reading));
            }
            else if (choice4 == 3)
            {
                printf("The Equivalent INR is %.2f INR\n", currency3(reading));
            }
            else if (choice4 == 4)
            {
                printf("The Equivalent INR is %.2f INR\n", currency4(reading));
            }
            else if (choice4 == 5)
            {
                break;
            }
        }
        else if (choice1 == 4)
        {
            printf("Exiting the program. Goodbye!\n");
            break;
        }
        else
        {
            printf("Oops! Incorrect Choice. Please try again.\n");
        }
    }

    return 0;
}