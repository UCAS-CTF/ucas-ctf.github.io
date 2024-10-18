#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define N 1010                  // 宏定义，数据规模
typedef int ElemType;
ElemType Stack[N];            	// 栈
int top = 0;                    // 栈顶指针
bool ErrorFlag = true;          // 报错标记，true为存在错误

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

ElemType Top() {
    if (top == 0) {         // 检查栈顶是否为空
        printf("Error: The stack is empty!\n");
        ErrorFlag = true;   // 产生报错信息
        return -1;
    } else {
        return Stack[top];
    }
}

ElemType Pop() {
    if (top == 0) {             // 检查栈顶是否为空
        printf("Error: The stack is empty!\n");
        ErrorFlag = true;       // 产生报错信息
        return -1;
    } else { 
        return Stack[top--];    // 注意执行的顺序：先记录弹出的元素作为返回值，然后再挪动top指针
    }
}

void Push(ElemType data) {
	if (top == N - 1) {     // 检查数组是否已满，防止数组越界
        printf("Error: The stack is full!\n");
        ErrorFlag = true;   // 产生报错信息
        return;
	}
    ErrorFlag = false;      // 清空报错标记，因为此时栈不再为空，因而也不会触发报错
    Stack[++top] = data;    // 注意执行的顺序：先挪动top指针，再写入新数据
}
