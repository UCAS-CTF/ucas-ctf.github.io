#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int ElemType;
struct node {
    ElemType data;
    struct node *next;
};

struct node *QueueHead, *QueueTail;         // 队首指针和队尾指针
bool ErrorFlag = true;

#define NewSpace (struct node *)malloc(sizeof(struct node))

void Init();
ElemType Front();
ElemType Pop();
void Push(ElemType data);
void Print(); 

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
        } else if (!strcmp(inst, "print")) {
            Print();
        } else if (!strcmp(inst, "exit")) {
            break;
        } else {
            printf("Error: Undefined Instruction.\n");
        }
    }

    return 0;
}

/******************************
 * Front()函数用于访问队首元素
 * 在队列不为空时返回一个ElemType类型的值，即队首元素存放的数据
 * 在队列为空时输出报错信息，将报错标记ErrorFlag置为true，并返回-1
 ******************************/

ElemType Front() {
    if (QueueHead == NULL) {
        printf("Error: The queue is empty!\n");
        ErrorFlag = true;
        return -1;
    } else {
        return QueueHead->data;
    }
}
// 你可能觉得上面这段代码看着有点眼熟
// 没错，我就是从栈那里复制过来的，只是修改了变量名（以及函数名）而已

ElemType Pop() {
    if (QueueHead == NULL) {
        printf("Error: The queue is empty!\n");
        ErrorFlag = true;
        return -1;
    } else {
        struct node * ptr = QueueHead;
        ElemType data = ptr->data;
        QueueHead = QueueHead->next;
        free(ptr);
        return data;
    }
}

void Push(ElemType data) {
    ErrorFlag = false;
    struct node * ptr = NewSpace;
    ptr->data = data;
    ptr->next = NULL;
    if (QueueHead == NULL) {
    	QueueHead = QueueTail = ptr;    // 注意如果队列本来是空的，要把队头也指向新元素
	} else {
		QueueTail->next = ptr;          // 由于是从队尾入队，所以注意指针的指向
		QueueTail = ptr;                    
	}
}

void Print() {
    struct node *now = QueueHead;
    int cnt = 0;
    while (now != NULL) {
        cnt++;
        printf("%d ", now->data);
        now = now->next;
    }
    printf("\nThere are %d elements in the list.\n", cnt);
}
