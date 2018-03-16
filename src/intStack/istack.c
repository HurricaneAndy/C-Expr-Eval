/**
 *
 *     Stack ADT
 *
 *
 *  COMP220: Lab7 istack.c
 *  Author:  Andrew Liu
 *  Date:    Mar. 8, 2018
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include "istack.h"

node_t2* noseCreate(int value)
{
    node_t2* new_node = (node_t2*)malloc(sizeof(node_t2));
    new_node->data = value;
    new_node->next = NULL;

    return new_node;
}

IntStack_t istackCreate( )
{
    IntStack_t stack = {NULL};

    return stack;
}

void istackDestroy( IntStack_t *stack )
{
    node_t2* cur = stack->head;
    if(cur != NULL)
        while (cur != NULL)
        {
            cur = cur->next;
            free(stack->head);
            stack->head = cur;
        }
}


void istackPrint( IntStack_t stack  )
{
    printf("\n");
    node_t2* cur = stack.head;
    if(cur != NULL)
        while (cur != NULL)
        {
            printf("%d \n", cur->data);
            cur = cur->next;
        }
    printf("\n");
}

bool istackIsEmpty( IntStack_t stack )
{
    if(stack.head == NULL)
        {
            return 1;
        }
    else
        {
            return 0;
        }
}


bool istackIsFull( IntStack_t stack )
{
    return 0;
}

int istackTop( IntStack_t stack )
{
    printf("%d", stack.head->data);
    return stack.head->data;
}

int istackPop( IntStack_t *stack )
{
    int data = stack->head->data;
    if(stack->head->next != NULL)
    {
        node_t2* ptr = stack->head->next;
        free(stack->head);
        stack->head = ptr;
    }
    else
        free(stack->head);
    return data;
}

int istackPush( IntStack_t *stack, int item)
{
    node_t2 *node = noseCreate(item);
    node->next = stack->head;
    stack->head = node;

    return item;
}