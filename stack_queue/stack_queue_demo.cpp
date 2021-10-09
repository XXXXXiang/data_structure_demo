#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};
typedef struct node NODE;

void printInfo();
void printQueueInfo();
void printStackInfo();
void stack_demo(bool*,int);
void queue_demo(bool*,int);
NODE* creatLink(int);
NODE* pushStack(NODE*,int);
NODE* popStack(NODE*);
NODE* enqueue(NODE*, int);
NODE* dequeue(NODE*);
int printLink(NODE*,bool);

int main() {
    bool run = true;
    bool* ptr_run = &run;
    bool run_stack = true;
    bool run_queue = true;
    int run_option = 0;
    int size = 0;

    int run_queue_option = 0;

    while(run){
        printInfo();
        scanf("%d", &run_option);
        switch (run_option) {
        case 1:
            printf("Decide a size for Stack.\n");
            scanf("%d",&size);
            stack_demo(ptr_run,size);
            break;
        case 2:
            printf("Decide a size for Queue.\n");
            scanf("%d", &size);
            queue_demo(ptr_run,size);
            break;
        case 3:
            run = false;
            break;
        default:
            printf("Please input from 1 to 3.\n");
            break;
        }
    }
    return 0;
}
void stack_demo(bool* ptr_run,int size) {
    bool run_stack_option = true;
    int run_option = 0;
    int data_length = 0;
    int data_input = 0;
    NODE* head = NULL;
    while (run_stack_option) {
        printStackInfo();
        scanf("%d", &run_option);
        switch (run_option) {
        case 1://Quick Push
            data_input = (rand() % 100);
            if (data_length == 0) {
                head = creatLink(data_input);
            }
            else if (data_length >= size)
                printf("Stack is full !\n");
            else
                head = pushStack(head, data_input);
            break;
        case 2://Push       
            if (data_length == 0) {
                printf("Please input a data.\n");
                scanf("%d", &data_input);
                head = creatLink(data_input);
            }
            else if (data_length >= size)
                printf("Stack is full !\n");
            else {
                printf("Please input a data.\n");
                scanf("%d", &data_input);
                head = pushStack(head, data_input);
            }
            break;
        case 3://POP
            if (data_length == 0)
                printf("No stack\n");
            else
                head = popStack(head);
            break;
        case 4:
            run_stack_option = false;
            break;
        case 5:
            run_stack_option = false;
            *ptr_run = false;
            break;
        default:
            break;
        }
        data_length = printLink(head,true);
        printf("Stack Length: %d\n",data_length);
    }
}

void queue_demo(bool* ptr_run, int size) {
    bool run_queue_option = true;
    int run_option = 0;
    int data_length = 0;
    int data_input = 0;
    NODE* head = NULL;
    while (run_queue_option) {
        printQueueInfo();
        scanf("%d", &run_option);
        switch (run_option) {
        case 1://Quick enqueue
            data_input = (rand() % 100);
            if (data_length == 0) {
                head = creatLink(data_input);
            }
            else if (data_length >= size)
                printf("Queue is full !\n");
            else
                head = enqueue(head, data_input);
            break;
        case 2://Enqueue

            if (data_length == 0) {
                printf("Enter a data to push.\n");
                scanf("%d", &data_input);
                head = creatLink(data_input);
            }
            else if (data_length >= size)
                printf("Queue is full !\n");
            else {
                printf("Enter a data to push.\n");
                scanf("%d", &data_input);
                head = enqueue(head, data_input);
            }
            break;
        case 3://Dequeue
            if (data_length == 0)
                printf("No stack\n");
            else
                head = dequeue(head);
            break;
        case 4:
            run_queue_option = false;
            break;
        case 5:
            run_queue_option = false;
            *ptr_run = false;
            break;
        default:
            break;
        }
        data_length = printLink(head,false);
        printf("Queue Length: %d\n", data_length);
    }
}
NODE* creatLink(int data) {
    NODE* head = (NODE*)malloc(sizeof(NODE));
    head->next = NULL;
    head->data = data;
    return head;
}

NODE* pushStack(NODE* head,int data) {
    NODE* new_node = (NODE*)malloc(sizeof(NODE));
    new_node->next = head;
    new_node->data = data;
    head = new_node;
    return head;
}

NODE* popStack(NODE* head) {
    NODE* temp = head;
    head = head->next;
    free(temp);
    return head;
}

NODE* enqueue(NODE* head,int data) {
    NODE* new_node = (NODE*)malloc(sizeof(NODE));
    new_node->next = head;
    new_node->data = data;
    head = new_node;
    return head;
}

NODE* dequeue(NODE* head) {
    if (head->next == NULL) {
        head = NULL;
    }
        
    else {
        for (NODE* ptr = head; ptr != NULL; ptr = ptr->next) {
            if (ptr->next->next == NULL) {
                free(ptr->next);
                ptr->next = NULL;
            }
        }
    }
    return head;
}

int printLink(NODE* head,bool stack_or_queue) {
    int count = 0;
    if (stack_or_queue)
        printf("Stack: ");
    else
        printf("Queue: ");

    for (NODE* ptr = head;ptr!=NULL;ptr=ptr->next) {
        if (ptr->next != NULL)
            printf("%d -> ", ptr->data);
        else
            printf("%d",ptr->data);
        count += 1;
    }
    printf("\n");
    return count;
}

void printInfo(){
    printf("\
###############################\n\
<1> Stack demo\n\
<2> Queue demo\n\
<3> Exit\n\
###############################\n");
}
void printQueueInfo() {
    printf("\
###############################\n\
<1> Quick Enqueue\n\
<2> Enqueue\n\
<3> Dequeue\n\
<4> Back to menu\n\
<5> Exit\n\
###############################\n");
}

void printStackInfo() {
    printf("\
###############################\n\
<1> Quick Push\n\
<2> Push\n\
<3> Pop\n\
<4> Back to menu\n\
<5> Exit\n\
###############################\n");
}
