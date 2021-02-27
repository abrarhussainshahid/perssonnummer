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
    //printf("\nFormat is ok: %s and Length: %zu", personNummer, strlen(personNummer));
    //printf("\nLength: %zu", strlen(personNummer));

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

    return 0;
}