#include <stdio.h>
#include <stdlib.h>

int isVowel(char letter) {
    char vowels[6] = {'a', 'e', 'i', 'o', 'u', 'y'};
    for (int i = 0; i < 6; i++) {
        if (letter == vowels[i]) return 1;
    }
    return 0;
}

typedef struct linked_list {
    char key;
    struct linked_list *next;
} r_list_t; //reverse single-linked list

r_list_t *list_add (r_list_t **targetList_p, char key) {
    r_list_t *this_p = *targetList_p;
    if (this_p) {
        while(this_p->next){
            this_p = this_p->next;
        }
        r_list_t *node_p;
        node_p = malloc(sizeof (r_list_t));
        *node_p = (r_list_t) {key, NULL};
        this_p->next = node_p;
    }
    else {
        r_list_t *head_p;
        head_p = malloc(sizeof (r_list_t));
        *head_p = (r_list_t) {key, NULL};
        *targetList_p = head_p;
    }
    return *targetList_p;
}

r_list_t *list_sort(r_list_t **targetList_p) {
    r_list_t *targetList = *targetList_p;
    r_list_t *prev_p = NULL;
    r_list_t *this_p = targetList;
    r_list_t *lastVowel = NULL;
    while(this_p) {
        if(isVowel(this_p->key)) {
            if(this_p == targetList) { //коли голосний ключ - перший елемент списку
                lastVowel = targetList;
            }
            else { //коли голосний ключ - середній елемент списку
                prev_p->next = this_p->next;
                if (lastVowel) {
                    this_p->next = lastVowel->next;
                    lastVowel->next = this_p;
                    lastVowel = this_p;
                }
                else {
                    this_p->next = targetList;
                    *targetList_p = this_p;
                    lastVowel = this_p;
                }
            }
        }
        prev_p = this_p;
        this_p = this_p->next;
    }
    return targetList;
}

void printList(r_list_t *targetList) {
    while (targetList) {
        printf("pointer = %p info = %c next = %p\n",
               targetList, targetList->key, targetList->next);
        targetList = targetList->next;
    }
    printf("\n");
}

void list_create(r_list_t **targetList_p) {
    int n;
    printf("enter the size of list: ");
    scanf("%i", &n);
    char string[n];
    printf("enter the string of keys: ");
    scanf("%s", &string);
    for (int i = 0; i < n; i++) {
        char key = string[i];
        list_add(targetList_p, key);
    }
}

int list_clear(r_list_t **targetList_p) {
    r_list_t *this_p = *targetList_p;
    if (this_p == NULL) {
        printf("the list is empty");
        return 0;
    }
    r_list_t *next_p;
    while (this_p) {
        next_p = this_p->next;
        free(this_p);
        this_p = next_p;
    }
    *targetList_p = NULL;
    return 1;
}

int main() {
    r_list_t *myList = NULL;

    list_create(&myList);
    printf("ініціалізований список: \n");
    printList(myList);


    list_sort(&myList);
    printf("відсортований список: \n");
    printList(myList);

    list_clear(&myList);
    printf("%p", myList);

    return 0;
}