#include <stdio.h>
#include <stdlib.h>

int isVowel(char letter) {
    char vowels[5] = {'a', 'e', 'i', 'o', 'u'};
    for (int i = 0; i < 5; i++) {
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

r_list_t *list_refill(r_list_t *targetList) {
    r_list_t *this_p = targetList;
    char k;
    do {
        printf("enter key for %p node \n", this_p);
        scanf("%c", &k);
        scanf("%c", &k);
        this_p->key = k;
        this_p = this_p->next;
    } while (this_p);
    return targetList;
}

r_list_t *list_sort(r_list_t **targetList_p) {
    r_list_t *targetList = *targetList_p;
    r_list_t *prev_p = NULL;
    r_list_t *this_p = targetList;
    r_list_t *lastVowel = NULL;
    while(this_p) {
        if(isVowel(this_p->key)){
            if(this_p == targetList) { //коли голосний ключ - перший елемент списку
                lastVowel = targetList;
            }

            else if(this_p->next) { //коли голосний ключ - середній елемент списку
                prev_p->next = this_p->next;
                this_p->next = lastVowel->next;
                lastVowel->next = this_p;
            }
        }
        prev_p = this_p;
        this_p = this_p->next;
    }
}

void printList(r_list_t *targetList) {
    while (targetList) {
        printf("pointer = %p info = %c next = %p\n",
               targetList, targetList->key, targetList->next);
        targetList = targetList->next;
    }
}

int main() {
    r_list_t *myList = NULL;
    int n;
    printf("enter the size of list: ");
    scanf("%i", &n);
    for (int i = 0; i < n; i++) {
        char key;
        printf("enter the value of %i element: ", i);
        scanf("%c", &key);
        scanf("%c", &key);
        list_add(&myList, key);
    }
    printList(myList);

    return 0;
}
