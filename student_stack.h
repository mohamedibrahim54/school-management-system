#ifndef STUDENT_STACK_H_INCLUDED
#define STUDENT_STACK_H_INCLUDED

// student data(id, name, score, ....)
typedef struct student{
    int id;
    char *name;
    int score;
    char *dateOfBirth;
    char *address;
    char *phoneNumber;
} student_t;

// node (student , next node)
typedef struct stackNode{
    student_t student;
    struct stackNode *next;
} stackNode_t;

// stack (top node, size)
typedef struct studentStack{
    stackNode_t *top;
    int size;
} studentStack_t;

void createStudentStack(studentStack_t *s);

void push(studentStack_t *s, student_t st);

void pop(studentStack_t *s, student_t *st);

void stackTop(studentStack_t *s, student_t *st);

void clearStack(studentStack_t *s);

int stackEmpty(studentStack_t *s);

int stackSize(studentStack_t *s);

#endif // STUDENT_STACK_H_INCLUDED
