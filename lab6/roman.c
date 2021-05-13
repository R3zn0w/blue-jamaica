
/* Given two roman numbers, print sum of them (also in roman)

Input:
Two roman numbers separated with whitespace

Output:
Roman number representing sum of output

Example: 
Input:
CXXIII CCLVI

Output:
CCCLXXIX

*/

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

int value(char v) //convert roman literal to number
{
    switch (v)
    {
    case 'I':
        return 1;
        break;
    case 'V':
        return 5;
        break;
    case 'X':
        return 10;
        break;
    case 'L':
        return 50;
        break;
    case 'C':
        return 100;
        break;
    case 'D':
        return 500;
        break;
    case 'M':
        return 1000;
        break;
    default:
        break;
    }
    return -1;
}

void printRoman(int number) //print roman number from decimal
{
    int num[] = {1, 4, 5, 9, 10, 40, 50, 90, 100, 400, 500, 900, 1000}; //possible legal values
    char sym[][2] = {"I ", "IV", "V ", "IX", "X ", "XL", "L ", "XC", "C ", "CD", "D ", "CM", "M "};
    int i = 12; //iterate from highest value (1000)
    while (number > 0)
    {
        int div = number / num[i];
        number = number % num[i];
        while (div--)
        {
            printf("%c%c", sym[i][0], sym[i][1]);
        }
        i--;
    }
}

int roman_to_decimal(char *num)
{
    int number = 0, i = 0;
    while (num[i])
    {
        if (value(num[i]) >= value(num[i + 1]))
            number = number + value(num[i]);
        else
        {
            number = number + (value(num[i + 1]) - value(num[i]));
            i++;
        }
        i++;
    }
    return number;
}

int main()
{
    char num1[1000], num2[1000];
    int sum = 0;
    printf("Provide two roman numbers to sum: \n");
    scanf("%s %s", num1, num2);

    sum = roman_to_decimal(num1) + roman_to_decimal(num2);
    printRoman(sum);
    return 0;
}