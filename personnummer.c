/**
 * @file personnummer.c
 * @author Abrar Hussain Shahid (abrar.hussain-shahid@yaelev.se)
 * @brief A program to check if a swedish personal identity number (personnummer)
 *       is correct or not.
 * @version 0.1
 * @date 2021-02-27
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include <stdio.h>
#include <string.h>

int main()
{

    char personNummer[12];
    char personNummerWithoutDash[12];
label:
    printf("Enter personnummer: ");
    gets(personNummer);

    //check format 811112-4321 and length
    for (int i = 0; i < strlen(personNummer); ++i)
    {
        if (personNummer[6] != '-')
        {
            printf("Personnummer not correct: %s\n", personNummer);
            goto label;
        }
    }
    printf("Personnummer format correct: %s\n", personNummer);

    //Format is ok. Remove now '-' to string 8111124321
    for (int i = 0, j = 0; personNummer[i] != '\0'; ++i)
    {
        if ((personNummer[i] >= '0' && personNummer[i] <= '9'))
        {
            personNummerWithoutDash[j] = personNummer[i];
            j++;
        }

        personNummerWithoutDash[j] = '\0';
    }
    printf("Dash '-' removed from personnummer: ");
    puts(personNummerWithoutDash);

    //Checking personnummer is valid using Luhn algorithm
    int numberSum = 0, isSecondNumber = 0; //0 = false, 1 = true

    for (int i = strlen(personNummerWithoutDash) - 1; i >= 0; i--)
    {
        int digit = personNummerWithoutDash[i] - '0'; //convert char to integer

        if (isSecondNumber == 1)
            digit = digit * 2;

        // We add two digits to handle cases that make two digits after doubling
        numberSum += digit / 10;
        numberSum += digit % 10;

        isSecondNumber = !isSecondNumber;
    }

    printf("------------------------\n");
    printf("Calculate control digit \n");
    printf("------------------------\n");

    int sumOf_9_digit, sumOfAllnumbers = 0;
    for (int i = strlen(personNummerWithoutDash) - 1; i >= 0; --i)
    {
        //convert char to integer
        int digit = personNummerWithoutDash[i] - '0';

        if (isSecondNumber == 1)
            digit = digit * 2;

        // We add two digits to handle cases that make two digits after
        // doubling
        sumOfAllnumbers += digit / 10;
        sumOfAllnumbers += digit % 10;

        isSecondNumber = !isSecondNumber;
    }

    int lastDigit = personNummerWithoutDash[9] - '0';
    sumOf_9_digit = sumOfAllnumbers - lastDigit;
    int controlDigit = (10 - (sumOf_9_digit % 10)) % 10;

    printf("Sum Of_9_digit: %d\n", sumOf_9_digit);
    printf("After modulo operation: %d\n", sumOf_9_digit % 10);
    printf("Control digit: %d\n", controlDigit);

    if ((numberSum % 10 == 0))
    {
        printf("Personnummer is valid\n");
    }
    else
    {
        printf("Personnummer is not valid\n");
    }

    return 0;
}