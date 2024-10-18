#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int ElemType;
struct node {
    ElemType data;
    struct node *next;
};

struct node * Stack;            // 栈顶指针
bool ErrorFlag = true;          // 报错标记，true为存在错误

#define NewSpace (struct node *)malloc(sizeof(struct node))

ElemType Top();
ElemType Pop();
void Push(ElemType data);

int main() {
    char inst[10] = "\0";
    ElemType data;

    while (1) {
        scanf("%s", inst);
        if (!strcmp(inst, "top")) {
            ElemType result = Top();
            if (!ErrorFlag) {
                printf("The top of the stack is %d\n", result);
            }
        } else if (!strcmp(inst, "pop")) {
            ElemType result = Pop();
            if (!ErrorFlag) {
                printf("Poped element %d\n", result);
            }
        } else if (!strcmp(inst, "push")) {
            scanf("%d", &data);
            Push(data);
        } else {
            printf("Error: Undefined Instruction.\n");
        }
    }

    return 0;
}

/******************************
 * Top()函数用于访问栈顶元素
 * 在栈不为空时返回一个ElemType类型的值，即栈顶元素存放的数据
 * 在栈为空时输出报错信息，将报错标记ErrorFlag置为true，并返回-1
 ******************************/

ElemType Top() {
    if (Stack == NULL) {    // 检查栈顶是否为空
        printf("Error: The stack is empty!\n");
        ErrorFlag = true;   // 产生报错信息
        return -1;
    } else {
        return Stack->data;
    }
}

/******************************
 * Pop()函数用于弹出栈顶元素
 * 在栈不为空时将栈顶元素从栈中删除，并返回一个ElemType类型的值，即栈顶元素存放的数据
 * 在栈为空时输出报错信息，将报错标记ErrorFlag置为true，并返回-1
 ******************************/

ElemType Pop() {
    if (Stack == NULL) {    // 检查栈顶是否为空
        printf("Error: The stack is empty!\n");
        ErrorFlag = true;   // 产生报错信息
        return -1;
    } else {
        struct node * ptr = Stack; 
        ElemType data = ptr->data;
        Stack = Stack->next;
        free(ptr);                  // 从链表最前端，也就是栈顶，删除一个元素
        return data;                // 一般而言，执行弹栈操作时会返回被弹出的数据
    }
}

/******************************
 * Push(ElemType data)函数用于将新元素压栈
 * 参数data为要压入栈中的数据
 ******************************/

void Push(ElemType data) {
    ErrorFlag = false;                  // 清空报错标记，因为此时栈不再为空，因而也不会触发报错
    struct node * ptr = NewSpace;       // 新的元素
    ptr->data = data;
    ptr->next = Stack;
    Stack = ptr;                        // 将新元素插入到链表的最前端，也就是栈顶
}