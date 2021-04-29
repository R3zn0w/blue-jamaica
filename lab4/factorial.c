#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

long long digits = 0;

long long digits_in_factorial(int n) //count number of digits in factorial
{
    if (n == 0)
        return 1;
    if (n == 1)
        return 1;

    double digits = 0;
    for (int i = 2; i <= n; i++)
        digits += log10(i);
    return (long long)floor(digits) + 1;
}

void multiply(int *arr, int number) //multiply array with a number
{
    int num_arr[11] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}; //10 is max integer size
    int *result = malloc(sizeof(int) * (size_t)digits);  //alloc temporary multiplying result array
    for (long long j = 0; j < digits; j++)               //initialize result array
        *(result + j) = 0;
    int i = 0;
    while (number) //convert number to array of digits
    {
        *(num_arr + i) = number % 10;
        number /= 10;
        i++;
    }

    for (long long k = 0; k < digits; k++) //multiply elements and sum them at respective indexes
    {
        for (int l = 0; l < i; l++)
        {
            result[k + l] += arr[k] * num_arr[l]; //we can do that because array is little-endian
        }
    }

    //handle carry-overs
    int carry = 0;
    for (long long p = 0; p < digits; p++)
    {
        carry = (int)result[p] / 10; //carry
        result[p] = result[p] % 10;  //remainder that's staying
        result[p + 1] += carry;
    }

    for (long long u = 0; u < digits; u++) //move result contents to main array
    {
        *(arr + u) = *(result + u);
    }
    free(result); //free temp array
}

void factorial(int *arr, int number) //simple recursive factorial
{
    if (number == 0) //0! = 0
    {
        *(arr) = 0;
        return;
    }
    if (number == 1) //1! = 1
    {
        *(arr) = 1;
        return;
    }
    factorial(arr, number - 1); //recursively call factorial
    multiply(arr, number);      //multiply current number with main array, which represents final result

    /* Now this might be confusing, we multiply AFTER calling factorial because we are operating on a single array.
    We dive deep down recurrence tree and after executing base case 1! = 1, which is assigning 1 to main array we start multiplying it
    with next numbers as the tree is collapsing.*/
}

int main()
{

    int input_number = 0;
    printf("Big factorial calculator\n");
    printf("Enter number to calculate factorial from: ");
    scanf("%d", &input_number);
    clock_t begin = clock(); //start clock for performance measurements
    digits = digits_in_factorial(input_number);
    printf("Digits: %I64d\n", digits);
    int *arr = malloc(sizeof(int) * (size_t)digits);
    for (long long i = 0; i < digits; i++) //initialize result array
        *(arr + i) = 0;
    factorial(arr, input_number);
    clock_t end = clock();                                      //stop clock
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC; //measure time
    printf("Factorial: ");
    for (long long j = digits - 1; j >= 0; j--) //print results
        printf("%d", *(arr + j));
    printf("\nCalculation time: %lf seconds.", time_spent);
    free(arr);
    return 0;
}