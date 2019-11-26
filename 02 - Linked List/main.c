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
uint32_t list_counter = 0;

void InsertItem(uint8_t value)
{
    node_t *node = (node_t *)malloc(sizeof(node_t));
    node_t *temp;
    node->value = value;
    node->next = NULL;

    if (NULL == first)
    {
        first = node;
        list_counter++;
    }
    else
    {
        temp = first;

        while (NULL != temp->next)
        {
            temp = temp->next;
        }

        temp->next = node;
        list_counter++;
    }
}

void List()
{
    node_t *node = first;

    while (NULL != node)
    {
        printf("%d ", node->value);
        node = node->next;
    }
    printf("\r\n");
}

node_t *Remove(uint8_t index)
{
    node_t *current = first;
    node_t *previous = NULL;
    uint32_t count = 0;

    if (NULL == current)
    {
        return NULL;
    }

    while (((index - 1) != count) && (NULL != current->next))
    {
        previous = current;
        current = current->next;
        count++;
    }

    if ((index - 1) != count)
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
    uint32_t count = 0;

    if (NULL == current)
    {
        return;
    }

    while (((index - 1) != count) && (NULL != current->next))
    {
        current = current->next;
        count++;
    }

    if ((index - 1) != count)
    {
        return;
    }

    printf("%d\r\n", current->value);
}

void GetFirst(void)
{
    printf("%d\r\n", first->value);
}

void GetLast(void)
{
    GetItem(list_counter);
}

void ClearList(void)
{
    node_t *node = first;

    while (NULL != node)
    {
        node = first->next;
        free(first);
        first = node;
    }

    first = NULL;
    list_counter = 0;
}

int main(int argc, char const *argv[])
{
    printf("Lista Ligada - Kryptus. \r\n Comandos disponiveis:");
    printf("\r\n\tput\r\n\tget\r\n\tlist\r\n\tremove\r\n\tclear\r\n\tfirst\r\n\tlast\r\n\tsort\r\n\texit\r\n ");
    uint8_t status = 1;
    char input[201];
    char *start;

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
                node_t *rec = Remove(*start);

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
        else if (0 != (start = strstr(input, "exit")))
        {
            status = 0;
        }
    }
    printf("Finalizando programa, pressione alguma tecla para fechar.\r\n");
    getchar();
    return 0;
}
