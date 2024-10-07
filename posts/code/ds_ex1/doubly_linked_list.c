#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int ElemType;
struct node {
    ElemType data;
    struct node *pred, *next;   // 增加了前驱指针pred，指向链表中的上一个元素
};

struct node *list;

#define NewSpace (struct node *)malloc(sizeof(struct node))

struct node* ListAccess(int k);
void ListModify(int k, ElemType data);
void ListInsert(int k, ElemType data);
void ListRemove(int k);
void ListPrint();

int main() {
    char inst[10] = "\0";
    int data, k;

    while (1) {
        scanf("%s", inst);
        if (!strcmp(inst, "access")) {
            scanf("%d", &k);
            struct node *result = ListAccess(k);
            if (result != NULL) {
                printf("The element %d\n", result->data);
            }
        } else if (!strcmp(inst, "modify")) {
            scanf("%d%d", &k, &data);
            ListModify(k, data);
        } else if (!strcmp(inst, "insert")) {
            scanf("%d%d", &k, &data);
            ListInsert(k, data);
        } else if (!strcmp(inst, "remove")) {
            scanf("%d", &k);
            ListRemove(k);
        } else if (!strcmp(inst, "print")) {
            ListPrint();
        } else if (!strcmp(inst, "exit")) {
            break;
        } else {
            printf("Error: Undefined Instruction.\n");
        }
    }

    return 0;
}

struct node* ListAccess(int k) {
    struct node *now = list;
    int cnt = 0;
    while (now != NULL) {
        cnt++;
        if (cnt == k) {
            return now;
        }
        now = now->next;
    }
    printf("Sorry, there are only %d elements in the list.\n", cnt);
    return NULL;
}

void ListModify(int k, ElemType data) {
    struct node *now = ListAccess(k);
    if (now != NULL) 
    	now->data = data;
}

void ListInsert(int k, ElemType data) {
    if (k == 1) {
        struct node *ptr = NewSpace;
        ptr->data = data;
        ptr->pred = NULL;               // 表头的前驱为空
        ptr->next = list;
        list = ptr;
        return;
    }
    
    struct node *now = ListAccess(k - 1);

    if (now != NULL) {
        struct node *ptr = NewSpace;
        ptr->data = data;
        ptr->pred = now;                // 新元素的前驱指向它的前一个元素
        ptr->next = now->next;
        now->next = ptr;
    }
}

void ListRemove(int k) {
    if (k == 1) {
        if (list == NULL) {
            printf("Sorry, the list is empty.\n");
            return;
        }

        struct node *ptr = list;
        list = list->next;
        if (list != NULL)
	        list->pred = NULL;
        free(ptr);
    }
    
    struct node *now = ListAccess(k - 1);

    if (now != NULL) {
        struct node *ptr = now->next;
        if (ptr == NULL) {
        	printf("Sorry, there are only %d elements in the list.\n", k - 1);
		}
        now->next = ptr->next;
        if (ptr->next != NULL)
        	ptr->next->pred = now;      // 被删除元素的后一个元素的前驱指向被删除元素的前一个元素
        free(ptr);
    }
}

void ListPrint() {
    struct node *now = list;
    int cnt = 0;
    while (now != NULL) {
        cnt++;
        printf("%d ", now->data);
        now = now->next;
    }
    printf("\nThere are %d elements in the list.\n", cnt);
}
