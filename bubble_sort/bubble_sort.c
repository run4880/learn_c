#include <windows.h>
#include <stdio.h>

void print_array_of_integers(int *a, int size)
{
    for (int i = 0; i < size; i++)
        printf("%d\t", *(a + i));

    printf("\n");
}

int *bubble_sort(int *a, int size)
{
    int *b;

    b = malloc(size * sizeof(int));

    for (int i = 0; i < size; i++)
        *(b + i) = *(a + i); // Запись аналогична b[i] = a[i]

    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (b[j] > b[j + 1])
            {
                int temp = b[j];
                b[j] = b[j + 1];
                b[j + 1] = temp;
            }
        }
    }

    return b;
}

int main()
{
    SetConsoleOutputCP(CP_UTF8);

    size_t size;

    printf("Введите размер списка: ");
    scanf("%d", &size);

    int *a = malloc(size * (sizeof *a));

    for (int i = 0; i < size; i++)
    {
        printf("Элемент списка [%d]: ", i);
        scanf("%d", (a + i));
    }

    printf("Исходный список:\n");
    print_array_of_integers(a, size); // Аналогично print_array_of_integers(&a[0], SIZE);

    printf("Отсортированный список:\n");
    int *b = bubble_sort(a, size);
    print_array_of_integers(b, size);

    free(a);
    free(b);

    return 0;
}