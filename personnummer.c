/**
 * @file personnummer.c
 * @author Abrar Hussain Shahid (abrar.hussain-shahid@yaelev.se)
 * @brief 
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
    if ((numberSum % 10 == 0))
    {
        printf("Personnummer is valid");
    }
    else
    {
        printf("Personnummer is not valid");
    }

    return 0;
}