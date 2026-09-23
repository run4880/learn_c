#include <stdio.h>

#define LOWER 0   /* нижняя граница диапазона */
#define UPPER 300 /* верхняя граница */
#define STEP 20   /* шаг */

int main()
{
    int fahr;
    for (fahr = LOWER; fahr <= UPPER; fahr = fahr + STEP)
    {
        printf("%3d %6.1f\n", fahr, (5.0 / 9.0) * (fahr - 32));
    }
}
