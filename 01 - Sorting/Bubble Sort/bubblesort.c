
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_LENGTH  10

int data_array[ARRAY_LENGTH] = { 100, 99, 101, 0, 2, 7, 55, 80, 135, 20};

void Bubble_Sort(int32_t * array, uint16_t length);

int MediaVetorOrdenar(int * vetor, int tamanho);

int main(int argc, char const *argv[])
{
    printf("Hello World - Selection Sort\n");

    srand(0);

    /* for (uint16_t i = 0; i < ARRAY_LENGTH; i++)
    {
        data_array[i] = rand();
    } */

    clock_t begin = clock();
    int media = MediaVetorOrdenar(data_array, ARRAY_LENGTH);
    Bubble_Sort(data_array, ARRAY_LENGTH);
    clock_t end = clock();

    printf("Tempo de execucao: %6d  ticks", (end - begin));
    getchar();
 
    return 0;
}

void Bubble_Sort(int32_t * array, uint16_t length)
{
    for(uint16_t i = 0; i < length; i++)
    {
        for(uint16_t j = 0; j < length - 1; j++)
        {
            if(array[j] > array[j + 1])
            {
                int32_t var = array[j];
                array[j] = array[j + 1];
                array[j + 1] = var;
            }
        }
    }
}
int MediaVetorOrdenar(int * vetor, int tamanho)
{
    int64_t media = 0;

    for(uint16_t i = 0; i < tamanho; i++)
    {
        for(uint16_t j = 0; j < tamanho - 1; j++)
        {
            if(vetor[j] > vetor[j + 1])
            {
                int var = vetor[j];
                vetor[j] = vetor[j + 1];
                vetor[j + 1] = var;
            }
        }

    }
    for(uint16_t i = 0; i < tamanho; i++)
    {
        media += vetor[i];
    }
    media = media / tamanho;
}