#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

typedef struct list
{
    uint8_t value;
    struct list *next;
} node_t;

node_t *first = NULL;
node_t *last = NULL;
uint32_t list_counter = 0;
void InsertItem(uint8_t value)
{
    node_t *node = (node_t*) malloc(sizeof(node_t));

    node->value = value;
    node->next = NULL;

    if (NULL == first)
    {
        first = node;
        last = node;
        list_counter++;
    }
    else
    {
        last->next = node;
        last = node;
        list_counter++;
    }

}

void List()
{
    node_t *node = first;

    while(NULL != node)
    {
        printf("%d ", node->value);
        node = node->next;
    }
    printf("\r\n");
}

node_t* Remove(uint8_t index)
{
    node_t *current = first;
    node_t *previous = NULL;

    if (NULL == current)
    {
        return NULL;
    }

    uint8_t count = 1;

    while ((count != index) && (NULL != current->next))
    {
        previous = current;
        current = current->next;
        count++;
    }

    if (count != index)
    {
        return NULL;
    }

    if (first == current)
    {
        first = first->next;
    }
    else
    {
        previous->next = current->next;
    }

    list_counter--;

    printf("%d\r\n", current->value);
    return current;
}

void GetItem(uint8_t index)
{
    node_t *current = first;

    if (NULL == current)
    {
        return;
    }

    uint8_t count = 1;

    while ((count != index) && (NULL != current->next))
    {
        current = current->next;
        count++;
    }

    if (count != index)
    {
        return;
    }

    printf ("%d\r\n", current->value);
}

void GetFirst(void)
{
    printf("%d\r\n", first->value);
}

void GetLast(void)
{
    printf("%d\r\n", last->value);
}

void ClearList(void)
{
    node_t* node = first;

    while(NULL != node)
    {
        node = first->next;
        free(first);
        first = node;
    }

    first = NULL;
    last = NULL;
    list_counter = 0;
}

void QuickSort(void)
{
    uint32_t p_index = list_counter / 2;
}

int main(int argc, char const *argv[])
{
    printf("Lista Ligada - Kryptus. \r\n Comandos disponiveis:");
    printf("\r\n\tput\r\n\tget\r\n\tlist\r\n\tremove\r\n\tclear\r\n\tfirst\r\n\tlast\r\n\tsort\r\n\texit\r\n ");
    uint8_t status = 1;
    char input[201];
    char* start;

    InsertItem(5);
    InsertItem(6);
    InsertItem(7);

    while (status)
    {
        printf("prompt> ");
        if (fgets(input, 200, stdin) == NULL)
        {
			printf("Erro na leitura da entrada\n");
			break;
		}
        else if (0 != (start = strstr(input, "put")))
        {
            start += 4;

            if (('0' <= *start) && ('9' >= *start))
            {
                *start -= '0';
                InsertItem((uint8_t)*start);
                List();
            }
            else
            {
                printf("Invalid value\r\n");
            }

        }
        else if (0 != (start = strstr(input, "get")))
        {
            start += 4;

            if (('0' <= *start) && ('9' >= *start))
            {
                *start -= '0';
                GetItem((uint8_t)*start);
            }
            else
            {
                printf("Invalid value\r\n");
            }
        }
        else if (0 != (start = strstr(input, "list")))
        {
            List();
        }
        else if (0 != (start = strstr(input, "remove")))
        {
            start += 7;

            if (('0' <= *start) && ('9' >= *start))
            {
                *start -= '0';
                node_t* rec = Remove(*start);

                if (NULL != rec)
                {
                    List();
                    free(rec);
                }
            }
            else
            {
                printf("Invalid value\r\n");
            }
        }
        else if (0 != (start = strstr(input, "clear")))
        {
            ClearList();
        }
        else if (0 != (start = strstr(input, "first")))
        {
            GetFirst();
        }
        else if (0 != (start = strstr(input, "last")))
        {
            GetLast();
        }
        else if (0 != (start = strstr(input, "sort")))
        {
            QuickSort();
        }
        else if (0 != (start = strstr(input, "exit")))
        {
            status = 0;
        }

    }
    printf("Finalizando programa, pressione alguma tecla para fechar.\r\n");
    getchar();
    return 0;
}
