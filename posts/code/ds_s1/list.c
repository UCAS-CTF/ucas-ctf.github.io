#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int ElemType;
struct node {
    ElemType data;          // 这个元素所保存的数据
    struct node *next;      // 后继指针，指向链表中的下一个元素
};

struct node *list;          // 链表表头指针

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
            return now;     // 返回指向找到的元素的指针
        }
        now = now->next;    // 沿着next指针向下访问
    }
    printf("Sorry, there are only %d elements in the list.\n", cnt);
    return NULL;            // 返回空指针
}

void ListModify(int k, ElemType data) {
    struct node *now = ListAccess(k);      // 复用代码
    if (now != NULL) 
    	now->data = data;
}

void ListInsert(int k, ElemType data) {
    if (k == 1) {   // 特殊处理在表头处插入元素的情况
        struct node *ptr = NewSpace;
        ptr->data = data;
        ptr->next = list;
        list = ptr;
        return;
    }
    
    struct node *now = ListAccess(k - 1);   // 找到要插入的位置处的前一个元素

    if (now != NULL) {
        struct node *ptr = NewSpace;        // 申请新空间
        ptr->data = data;
        ptr->next = now->next;              // 前一个元素原来的后继变成新元素的后继
        now->next = ptr;                    // 前一个元素现在的后继变成新元素
    }
}

void ListRemove(int k) {
    if (k == 1) {   // 特殊处理在表头处插入元素的情况
        if (list == NULL) {
            printf("Sorry, the list is empty.\n");
            return;
        }

        struct node *ptr = list;
        list = list->next;
        free(ptr);
    }
    
    struct node *now = ListAccess(k - 1);   // 找到要删除的位置处的前一个元素

    if (now != NULL) {
        struct node *ptr = now->next;
        if (ptr == NULL) {
        	printf("Sorry, there are only %d elements in the list.\n", k - 1);
		}
        now->next = ptr->next;              // 前一个元素现在的后继变成要删除元素的后继
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
