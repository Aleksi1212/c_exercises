#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "../utils.h"

struct node
{
    int number;
    struct node *next;
};

void add_node(struct node** head, int number)
{
    struct node* prev_node = *head;
    struct node* new_node = (struct node*) malloc(sizeof(struct node));

    new_node->number = number;
    new_node->next = NULL;

    if (*head == NULL) {
        *head = new_node;
        return;
    }

    while (prev_node->next != NULL)
        prev_node = prev_node->next;

    prev_node->next = new_node;
}

int main(void)
{
    char number_str[100];

    struct node *linked_list = NULL;

    while (1)
    {
        validate_char_input("Enter a number (\"end\" to stop): ", number_str, sizeof(number_str));

        if (strcmp(number_str, "end") == 0)
            break;

        if (!isdigit(*number_str))
        {
            printf("Invalid input\n");
            continue;
        }
        else
        {
            add_node(&linked_list, atoi(number_str));
            printf("Succesfully added.\n");
        }
    }

    while (linked_list != NULL)
    {
        printf("%d\n", linked_list->number);
        linked_list = linked_list->next;
    }
    free(linked_list);
    

    return 0;
}