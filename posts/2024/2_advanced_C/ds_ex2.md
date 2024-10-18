# 用数组实现栈与队列

Author: [doyo](https://github.com/doyo2024)

&emsp;&emsp;本篇补充资料将介绍如何使用数组实现栈与队列。在正课的讲义中，我们介绍了如何使用结构体和指针来实现栈队列，与这种实现方式相比，使用数组会更加简单，但代价是牺牲了灵活性：使用数组实现栈与队列时，你必须预先知道数据规模（或者有个大概的估计），否则可能会造成空间浪费或空间不足的问题。

## 用数组实现栈

&emsp;&emsp;完整代码详见<a href="https://ucas-ctf.github.io/posts/code/ds_ex2/array_stack.c" download="array_stack.c">此处（点击下载）</a>。

### 栈的必要元素

&emsp;&emsp;使用数组实现栈时，应按如下方式定义栈：

```c
#define N 1010                  // 宏定义，数据规模
typedef int ElemType;
ElemType Stack[N];            	// 栈
int top = 0;                    // 栈顶指针
```

栈被声明为一段大小为N的数组，并用一个top指针来指向栈顶。这里的N是我们估计的数据规模，我们用一个宏定义将它的值定为1010。注意，由于数组下标从0开始，所以当你声明一个大小为1000的数组（例如`int a[100]`）时，你能够正确访问的下标只有0~999；因此，对于刚入门编程的新手而言，建议在声明数组时总是声明得稍大一些（比如比数据规模大10左右）来规避可能出现的数组越界问题。

&emsp;&emsp;显然，并不是整个数组都是栈的有效区域。事实上，只有1~top这个范围内的数组单元才是当前栈中的有效数据。

### 访问栈顶元素

&emsp;&emsp;访问栈顶指针指向的数组单元即可（当然，别忘了边界检查）：

```c
ElemType Top() {
    if (top == 0) {         // 检查栈顶是否为空
        printf("Error: The stack is empty!\n");
        ErrorFlag = true;   // 产生报错信息
        return -1;
    } else {
        return Stack[top];
    }
}
```

### 压栈

&emsp;&emsp;在使用结构体和指针的实现中，我们需要为压栈的新元素申请空间，然后把栈顶指针指向它。这里的操作类似，只是我们不需要申请新空间了，因为我们已经在数组中为新元素预留了空间，因此我们只需要将栈顶指针+1来指向空余的新空间即可：

```c
void Push(ElemType data) {
	if (top == N - 1) {     // 检查数组是否已满，防止数组越界
        printf("Error: The stack is full!\n");
        ErrorFlag = true;   // 产生报错信息
        return;
	}
    ErrorFlag = false;      // 清空报错标记，因为此时栈不再为空，因而也不会触发报错
    Stack[++top] = data;    // 注意执行的顺序：先挪动top指针，再写入新数据
}
```

### 弹栈

&emsp;&emsp;类似地，弹栈时只需要挪动栈顶指针，将它-1即可。

```c
ElemType Pop() {
    if (top == 0) {             // 检查栈顶是否为空
        printf("Error: The stack is empty!\n");
        ErrorFlag = true;       // 产生报错信息
        return -1;
    } else { 
        return Stack[top--];    // 注意执行的顺序：先记录弹出的元素作为返回值，然后再挪动top指针
    }
}
```

## 用数组实现队列

&emsp;&emsp;完整代码详见<a href="https://ucas-ctf.github.io/posts/code/ds_ex2/array_queue.c" download="array_queue.c">此处（点击下载）</a>。

### 队列的必要元素

&emsp;&emsp;如下所示：

```c
#define N 1000
typedef int ElemType;
ElemType Queue[N];              // 队列
int QueueHead, QueueTail;       // 队首指针和队尾指针
```

同样的，也并非整个队列数组里的元素都是有效的，只有QueueHead~QueueTail-1范围内的单元是有效的队列中元素。

### 访问队首元素

&emsp;&emsp;类似于栈，队首指针所指即为所求：

```c
ElemType Front() {
    if (QueueHead == QueueTail) {
        printf("Error: The queue is empty!\n");
        ErrorFlag = true;
        return -1;
    } else {
        return Queue[QueueHead];
    }
}
```

### 入队

&emsp;&emsp;挪动队尾指针即可：

```c
void Push(ElemType data) {
	if (QueueTail == N - 1) {
		printf("Error: The queue is full!\n");
        ErrorFlag = true;
        return;
	}
    ErrorFlag = false;
    Queue[QueueTail++] = data;          // 注意执行顺序：先将数据放在队尾，然后再挪动队尾指针
}
```

### 出队

&emsp;&emsp;类似地，挪动队首指针即可：

```c
ElemType Pop() {
    if (QueueHead == QueueTail) {
        printf("Error: The queue is empty!\n");
        ErrorFlag = true;
        return -1;
    } else {
        return Queue[QueueHead++];      // 注意执行顺序：向将队首元素记录为返回值，然后再挪动队首指针
    }
}
```