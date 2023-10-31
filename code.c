#include <stdio.h>
#include <stdlib.h>

// Don’t change this function
double square(double x)
{
    return x * x;
}

// Don’t change this function
double cube(double x)
{
    return x * x * x;
}

// Don’t change this prototype
double *take_input(int count);

// Don’t change this function
double average(double *numbers, int count, double (*fn)(double))
{
    double sum = 0;
    for (int i = 0; i < count; i++)
    {
        sum += fn(numbers[i]);
    }
    return sum / count;
}
double *take_input(int count)
{
    double *numbers = (double *)calloc(count, sizeof(double));
    double *initial = numbers;
    while (count--)
    {
        scanf("%lf", numbers);
        numbers++;
    }
    return initial;
}
// Here, implement the function named "calculate_ratio" that will work as mentioned earlier.
double calculate_ratio(double *numbers,int count,double (*fn[])(double)){
    return (average(numbers,count,fn[0])/average(numbers,count,fn[1]));
}

// Don’t change this function
int main()
{
    int count;
    scanf("%d", &count);
    double *numbers = take_input(count);
    double (*callback_funcs[])(double) = {square, cube};
    printf("Ratio of average of squares and average of cubes: %.2lf\n",
           calculate_ratio(numbers, count, callback_funcs));
    free(numbers);
    return 0;
}