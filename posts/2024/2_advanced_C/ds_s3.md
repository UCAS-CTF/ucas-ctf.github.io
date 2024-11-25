# 数据结构入门：队列

Author: [doyo](https://github.com/doyo2024)

## 基本概念

**队列（queue）** 是一种特殊的线性表，它仅允许在一端进行插入，在另一端进行删除。允许删除的这一端称为**队头** 或者**队首**，允许插入的那一端称为**队尾**。

生活中一个典型的例子就是食堂打饭时的排队。食堂师傅将优先给队头的同学打饭，并让他**出队**；后来的同学则只能从队尾**入队**等待。

仔细观察，我们可以发现，队列中的元素具有“先入队的先出队，后入队的后出队”的特性。我们称这种特性为**先进先出（First-In-First-Out，FIFO）**。

## 队列的实现

下面基于[上上份讲义](https://ucas-ctf.github.io/posts/ds_s1)中的单向链表给出栈的一种实现。正如前文所述，队列实际上也是一种特殊的线性表，所以只需要对单向列表的实现略作修改，使其插入仅在其一端、删除在另一端进行即可。

&emsp;&emsp;完整代码详见<a href="https://ucas-ctf.github.io/posts/code/ds_s3/queue.c" download="queue.c">此处（点击下载）</a>。

### 队列的必要元素

跟单向列表和栈都是一样的;

```c
typedef int ElemType;
struct node {
    ElemType data;
    struct node *next;
};
```

稍微不一样的是队列需要两个指针，一个指向队首，一个指向队尾：

```c
struct node *QueueHead, *QueueTail;
```

### 访问队首元素

类似于访问栈顶元素：

```c
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
```

### 入队

与栈不同的是，新元素入队时，是从队尾入队。

```c
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
```

### 出队

与弹栈的操作类似，但是是从队首进行：

```c
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
```

## 扩展：用数组实现队列

不仅仅是栈可以用数组实现，队列也是可以的。请参考[这篇讲义](https://ucas-ctf.github.io/posts/ds_ex2)。