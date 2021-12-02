#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "student_stack.h"

#define MAX_STR_BUFFER 50

// -----------get student data----------

void get_student_id(int *id){
    fflush(stdin);
    printf("Student Id: ");
    scanf("%d", id);
}

void get_student_name(char *name){
    fflush(stdin);
    printf("Student Name: ");
    fgets(name, MAX_STR_BUFFER, stdin);
    name[strcspn(name, "\r\n")] = 0;
}

void get_student_score(int *score){
    fflush(stdin);
    printf("Student Score: ");
    scanf("%d", score);
}

void get_student_dateofbirth(char *date){
    fflush(stdin);
    printf("Student DateOfBirth: ");
    fgets(date, MAX_STR_BUFFER, stdin);
    date[strcspn(date, "\r\n")] = 0;
}

void get_student_address(char *address){
    fflush(stdin);
    printf("Student Address: ");
    fgets(address, MAX_STR_BUFFER, stdin);
    address[strcspn(address, "\r\n")] = 0;
}

void get_student_phonenumber(char *phone){
    fflush(stdin);
    printf("Student PhoneNumber: ");
    fgets(phone, MAX_STR_BUFFER, stdin);
    phone[strcspn(phone, "\r\n")] = 0;
}


// ------------- data manipulation functions--------------
void addStudent(studentStack_t *s){
    puts("\n<< Add Student >>\n");

    int id = 0;
    get_student_id(&id);

    char *name = (char *)malloc(MAX_STR_BUFFER);
    get_student_name(name);


    int score = 0;
    get_student_score(&score);

    char *dateOfBirth = (char *)malloc(MAX_STR_BUFFER);
    get_student_dateofbirth(dateOfBirth);


    char *address = (char *)malloc(MAX_STR_BUFFER);
    get_student_address(address);

    char *phoneNumber = (char *)malloc(MAX_STR_BUFFER);
    get_student_phonenumber(phoneNumber);

    student_t student;
    student.id = id;
    student.name = name;
    student.score = score;
    student.dateOfBirth = dateOfBirth;
    student.address = address;
    student.phoneNumber = phoneNumber;

    push(s, student);
}

void removeStudent(studentStack_t *s){
    puts("\n<< Remove Student >>\n");

    char *name = (char *)malloc(MAX_STR_BUFFER);
    printf("enter Student Name To Remove: \n");
    get_student_name(name);

    stackNode_t *prev_node = s->top;
    stackNode_t *node = s->top;
    // while(node != NULL && node->student.id != id){
    while(node != NULL && strcmp(name, node->student.name) != 0){
        prev_node = node;
        node = node->next;
    }

    if(node == NULL){
        puts("name doesn't exist!!");
        return;
    }

    if(node == s->top){
        s->top = node->next;
    } else{
        prev_node->next = node->next;
    }
    free(node);
    printf("Student removed...\n");
    s->size--;
}

void updateStudentScore(studentStack_t *s){
    puts("\n<< Update Student Score >>");

    char *name = (char *)malloc(MAX_STR_BUFFER);
    printf("enter Student Name To Update Score: \n");
    get_student_name(name);

    stackNode_t *node = s->top;
    while(node != NULL && strcmp(name, node->student.name) != 0){
        node = node->next;
    }

    if(node == NULL){
        puts("name doesn't exist!!");
        return;
    }

    int score = 0;
    printf("enter Student Score \n");
    get_student_score(&score);

    node->student.score = score;
}

void editStudent(studentStack_t *s){
    puts("\n<< Edit Student >>");

    char *name = (char *)malloc(MAX_STR_BUFFER);
    printf("enter Student Name To edit: \n");
    get_student_name(name);

    stackNode_t *node = s->top;
    while(node != NULL && strcmp(name, node->student.name) != 0){
        node = node->next;
    }

    if(node == NULL){
        puts("name doesn't exist!!");
        return;
    }
    printf("enter Student Data: \n");

    int id = 0;
    get_student_id(&id);

    char *newName = (char *)malloc(MAX_STR_BUFFER);
    get_student_name(newName);


    int score = 0;
    get_student_score(&score);

    char *dateOfBirth = (char *)malloc(MAX_STR_BUFFER);
    get_student_dateofbirth(dateOfBirth);


    char *address = (char *)malloc(MAX_STR_BUFFER);
    get_student_address(address);

    char *phoneNumber = (char *)malloc(MAX_STR_BUFFER);
    get_student_phonenumber(phoneNumber);

    node->student.id = id;
    node->student.name = newName;
    node->student.score = score;
    node->student.dateOfBirth = dateOfBirth;
    node->student.address = address;
    node->student.phoneNumber = phoneNumber;
}

// -------------data view functions------------

void viewStudent(studentStack_t *s){
    puts("\n<< View Student >>\n");

    fflush(stdin);
    char *name = (char *)malloc(MAX_STR_BUFFER);
    printf("enter Student Name To View: \n");
    get_student_name(name);

    stackNode_t *node = s->top;
    while(node != NULL && strcmp(name, node->student.name) != 0){
        node = node->next;
    }

    if(node != NULL){
        printf("\n **Student: \n");
        printf("id: %d\n", node->student.id);
        printf("name: %s\n", node->student.name);
        printf("score: %d\n", node->student.score);
        printf("date Of Birth:: %s\n", node->student.dateOfBirth);
        printf("address: %s\n", node->student.address);
        printf("phone Number: %s\n", node->student.phoneNumber);

    } else{
        puts("name doesn't exist!!");
    }

}

void viewAllStudents(studentStack_t *s){
    student_t *students = (student_t *)malloc(s->size * sizeof(student_t));
    stackNode_t *node = s->top;
    printf("size: %d", s->size);

    for(int i = 0; i < s->size; i++){
        students[i] = node->student;
        node = node->next;
    }

    // selection sort
    for(int i = 0; i < s->size; i++){
            char min = i;
            for(int j = i + 1; j < s->size; j++){
                if(strcmp(students[min].name, students[j].name) > 0){
                    min = j;
                }
            }

            // swap data
            student_t temp = students[i];
            students[i] = students[min];
            students[min] = temp;
    }

    for(int i = 0; i < s->size; i++){
        printf("\n*Student: \n");
        printf("id: %d\n", students[i].id);
        printf("name: %s\n", students[i].name);
        printf("score: %d\n", students[i].score);
        printf("date Of Birth:: %s\n", students[i].dateOfBirth);
        printf("address: %s\n", students[i].address);
        printf("phone Number: %s\n", students[i].phoneNumber);
    }
}

void rankStudent(studentStack_t *s){
    puts("\n<< Rank Students >>");
    student_t *students = (student_t *)malloc(s->size * sizeof(student_t));
    stackNode_t *node = s->top;
    int index = 0;
    while(node != NULL){
        students[index] = node->student;
        index++;
        node = node->next;
    }

    // selection sort
    for(int i = 0; i < s->size; i++){
            char max = i;
            for(int j = i + 1; j < s->size; j++){
                if(students[max].score < students[j].score){
                    max = j;
                }
            }

            // swap data
            student_t temp = students[i];
            students[i] = students[max];
            students[max] = temp;
    }

    for(int i = 0; i < s->size; i++){
        printf("\n*Student: \n");
        printf("id: %d\n", students[i].id);
        printf("name: %s\n", students[i].name);
        printf("score: %d\n", students[i].score);
        printf("date Of Birth:: %s\n", students[i].dateOfBirth);
        printf("address: %s\n", students[i].address);
        printf("phone Number: %s\n", students[i].phoneNumber);
    }
}

void main_menu(){
    studentStack_t stack;
    createStudentStack(&stack);
    while(1){

        puts("\n------------------------------------------------------------");
        puts("**school management system**");
        puts("------------------------------------------------------------");
        puts("1. add student");
        puts("2. remove student");
        puts("3. view student data");
        puts("4. update student score");
        puts("5. view all students in a list");
        puts("6. edit a student");
        puts("7. Rank students based on score from the highest to lowest");

        printf("enter Operation Number(1-7): ");
        int op = 0;
        scanf("%d", &op);

        switch(op){
            case 1:
                addStudent(&stack);
                break;
            case 2:
                removeStudent(&stack);
                break;
            case 3:
                viewStudent(&stack);
                break;
            case 4:
                updateStudentScore(&stack);
                break;
            case 5:
                viewAllStudents(&stack);
                break;
            case 6:
                editStudent(&stack);
                break;
            case 7:
                rankStudent(&stack);
                break;
            default:

                break;
        }
        printf("\n press any key to continue or press q to exit: ");
        fflush(stdin);
        char c = getchar();
        if(c == 'q'){
            exit(EXIT_SUCCESS);
        }
    }
}

int main(int argc, char *argv[])
{
    main_menu();

    return 0;
}
