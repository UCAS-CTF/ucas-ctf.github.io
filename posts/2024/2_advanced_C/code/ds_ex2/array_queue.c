#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define N 1000
typedef int ElemType;
ElemType Queue[N];              // 队列
int QueueHead, QueueTail;       // 队首指针和队尾指针
bool ErrorFlag = true;

void Init();
ElemType Front();
ElemType Pop();
void Push(ElemType data);

int main()
{
    char inst[10] = "\0";
    ElemType data;

    while (1) {
        scanf("%s", inst);
        if (!strcmp(inst, "front")) {
            ElemType result = Front();
            if (!ErrorFlag) {
                printf("The front of the queue is %d\n", result);
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

ElemType Front() {
    if (QueueHead == QueueTail) {
        printf("Error: The queue is empty!\n");
        ErrorFlag = true;
        return -1;
    } else {
        return Queue[QueueHead];
    }
}

ElemType Pop() {
    if (QueueHead == QueueTail) {
        printf("Error: The queue is empty!\n");
        ErrorFlag = true;
        return -1;
    } else {
        return Queue[QueueHead++];      // 注意执行顺序：向将队首元素记录为返回值，然后再挪动队首指针
    }
}

void Push(ElemType data) {
	if (QueueTail == N - 1) {
		printf("Error: The queue is full!\n");
        ErrorFlag = true;
        return;
	}
    ErrorFlag = false;
    Queue[QueueTail++] = data;          // 注意执行顺序：先将数据放在队尾，然后再挪动队尾指针
}
