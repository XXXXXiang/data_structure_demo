#include <stdio.h>
#include <stdlib.h>
struct node {
    int data;
    struct node* next;
};

typedef struct node NODE;
NODE** enlengthLink(NODE**, bool, int);
void creatLink(NODE**,int);
int printLink(NODE**);  //return the length of the link list
void printinfo();
void delStart(NODE**);
void delEnd(NODE**);
void list_cpa_to_b(NODE** a, NODE** b, int len);

int main() {
    NODE* head = NULL;
    NODE* tail = NULL;
    NODE* head_tail[2] = {NULL,NULL};
    int command = 0;
    int link_length = 0;
    int add_data = 0;
    bool run = true;
    while (run) {
        printinfo();
        scanf("%d", &command);
        switch (command) {
        case 1:
            printf("Enter a int to head.\n");
            scanf("%d", &add_data);

            if (link_length == 0)
                creatLink(head_tail, add_data);
            else
                list_cpa_to_b(enlengthLink(head_tail, true, add_data), head_tail,2);
            break;
        case 2:
            printf("Enter a int to tail.\n");
            scanf("%d", &add_data);
            if (link_length == 0)
                creatLink(head_tail, add_data);
            else
                list_cpa_to_b(enlengthLink(head_tail, false, add_data), head_tail, 2);
            break;
        case 3:
            if (link_length ==0) 
                printf("linked list is already null\n");
            else
                delStart(head_tail);
            break;
        case 4:
            if (link_length ==0)
                printf("linked list is already null\n");
            else
                delEnd(head_tail);
            break;
        case 5:
            printf("#########  End Link list #########\n");
            run = false;
            break;
        default:
            printf("Please input from 1 to 5.\n");
            break;
        }
        if (run)
            link_length = printLink(head_tail);
    }
    return 0;
}

void list_cpa_to_b(NODE** a,NODE** b,int len) {
    for (int i = 0;i<len;i++) {
        b[i] = a[i];
    }
}

void delStart(NODE** head_tail) {
    NODE* temp = *head_tail;
    *head_tail = (*head_tail)->next;
    free(temp);
}

void delEnd(NODE** head_tail) {
    for (NODE* ptr=*head_tail;ptr!=NULL;ptr=ptr->next) {
        if (head_tail[0] == head_tail[1]) {//If there is only one node in linked list, free the node, and set head_tail to {NULL, NULL}
            head_tail[0] = NULL;
            head_tail[1] = NULL;
            free(ptr);
            break;
        }
        else if (ptr->next->next == NULL) {
            NODE* temp = ptr->next;
            free(temp);
            head_tail[1] = ptr;
            ptr->next = NULL;
        }
    }
}

int printLink(NODE** head_tail) {
    int counter = 0;
    NODE* ptr = NULL;
    if (head_tail[0] == NULL) {
        printf("No linked list\n");
        return counter;
    }
    for (ptr = head_tail[0]; ptr != NULL; ptr = ptr->next) {
        if (ptr->next != NULL) {
            printf("%d->", ptr->data);
        }
        else {
            printf("%d", ptr->data);
        }
        counter += 1;
    }
    printf("\n");
    return counter;
}

void creatLink(NODE** head_tail, int data) {
    NODE* first_node = (NODE*)malloc(sizeof(NODE));
    first_node->next = NULL;
    first_node->data = data;
    head_tail[0] = first_node;
    head_tail[1] = first_node;
}

NODE** enlengthLink(NODE** head_tail, bool add_head, int data) {
    NODE* new_node = (NODE*)malloc(sizeof(NODE));
    new_node->data = data;
    if (add_head) {
        new_node->next = head_tail[0];
        head_tail[0] = new_node;
    }
    else {
        new_node->next = NULL;
        head_tail[1]->next = new_node;
        head_tail[1] = new_node;
    }
    return head_tail;
}

void printinfo() {
    char link_list_intro_info[] = "\
        ###############################\n\
        <1> Add start\n\
        <2> Add end\n\
        <3> Remove start\n\
        <4> Remove end\n\
        <5> Exit\n\
        ###############################\n";
    printf("%s", link_list_intro_info);
}
