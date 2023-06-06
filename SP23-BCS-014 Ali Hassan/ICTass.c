#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main()
{
    char hex[17];
    int dec = 0, val, len;
    int num, base, rem, i = 0, tempnum;

    printf("Enter your base : ");
    scanf("%d", &base);

    switch (base)
    {
    case 2:
        printf("Enter a binary number: ");
        scanf("%d", &num);

        // check if entered binary number is valid
        tempnum = num;
        while (tempnum != 0)
        {
            rem = tempnum % 10;
            if (rem != 0 && rem != 1)
            {
                printf("Error: Entered number is not a binary number.\nEnter your number again : ");
                scanf("%d", &num);
                tempnum = num;
            }
            tempnum /= 10;
        }

        // perform binary to decimal conversion
        tempnum = num;
        while (tempnum != 0)
        {
            rem = tempnum % 10;
            dec += rem * pow(base, i);
            i++;
            tempnum /= 10;
        }

        printf("Decimal = %d\n", dec);

        break;

    case 8:
        printf("Enter your number : ");
        scanf("%d", &num);

        // Check the validity of octal number
        tempnum = num;
        while (tempnum != 0)
        {
            rem = tempnum % 10;
            if (rem >= 8)
            {
                printf("Error: Entered number is not a binary number.\nEnter your number again : ");
                scanf("%d", &num);
                tempnum = num;
            }
            tempnum /= 10;
        }

        // perform octal to decimal conversion
        tempnum = num;
        while (tempnum != 0)
        {
            rem = tempnum % 10;
            dec += rem * pow(base, i);
            i++;
            tempnum /= 10;
        }

        printf("Decimal = %d\n", dec);
        break;

    case 16:

        printf("Enter a hexadecimal number : ");
        scanf("%s", &hex);

        len = strlen(hex);
        len--;

        for (i = 0; hex[i] != 0; i++)
        {
            if (hex[i] < '0' || hex[i] > '9' && hex[i] < 'A' || hex[i] > 'F')
            {
                printf("Error.Invalid Number.");
                dec = 0;
                break;
            }
            if (hex[i] >= '0' && hex[i] <= '9')
            {
                val = hex[i] - 48;
            }
            else if (hex[i] >= 'A' && hex[i] <= 'F')
            {
                val = hex[i] - 65 + 10;
            }

            dec = dec + val * pow(16, len);
            len--;
        }
        if (dec != 0)
        {
            printf("Decimal value = %d", dec);
            break;
        }
        break;
    default:
        printf("Error.Invalid Base number.");
        break;
    }
}