#include <stdio.h>
#include <stdlib.h>
#include "student_stack.h"

void createStudentStack(studentStack_t *s){
    s->top = NULL;
    s->size = 0;
}

void push(studentStack_t *s, student_t st){
    stackNode_t *node = (stackNode_t *)malloc(sizeof(stackNode_t));
    node->student = st;
    node->next = s->top;
    s->top = node;
    s->size += 1;
}

void pop(studentStack_t *s, student_t *st){
    *st = s->top->student;

    // To avoid memory leak: save previous top location
    stackNode_t *node = s->top;

    s->top = s->top->next;
    s->size--;

    free(node);
}

void stackTop(studentStack_t *s, student_t *st){
    *st = s->top->student;
}

void clearStack(studentStack_t *s){
    stackNode_t *node = s->top;
    while(node){
        node = node->next;
        free(s->top);
        s->top = node;
    }
    s->size = 0;
}

int stackEmpty(studentStack_t *s){
    return s->top == NULL;
}

int stackSize(studentStack_t *s){
    return s->size;
}
