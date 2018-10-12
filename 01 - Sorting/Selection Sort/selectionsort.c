
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_LENGTH  UINT16_MAX

int32_t data_array[ARRAY_LENGTH];
void Selection_Sort(int32_t *array, uint16_t size);
int main(int argc, char const *argv[])
{
    printf("Hello World - Selection Sort\n");

    srand(0);

    for (uint16_t i = 0; i < ARRAY_LENGTH; i++)
    {
        data_array[i] = rand();
    }

    clock_t begin = clock();
    Selection_Sort(data_array, ARRAY_LENGTH);
    clock_t end = clock();

    printf("Tempo de execucao: %6d  ticks", (end - begin));
    getchar();
    return 0;
}

void Selection_Sort(int32_t *array, uint16_t size)
{
    uint16_t i = 0;
    uint16_t j = 0;
    uint16_t min_index = 0;

    for (i = 0; i < size; i++)
    {
        int32_t value = array[i];
        min_index = i;
        for (j = i + 1; j < size; j++)
        {
            if (array[j] < value)
            {
                value = array[j];
                min_index = j;
            }
        }

        array[min_index] = array[i];
        array[i] = value;
    }
}
