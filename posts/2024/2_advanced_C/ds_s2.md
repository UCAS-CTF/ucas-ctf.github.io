# 数据结构入门：栈

Author: [doyo](https://github.com/doyo2024)

## 基本概念

**栈（stack）**，又称堆栈（个人不建议采用这个称呼，因为另有一种名为堆的数据结构，很容易引起混淆），是一种特殊的线性表，其所有的插入和删除操作均限定在线性表的一端进行；允许进行这些操作的一端称为**栈顶（top）**，另一端则称之为**栈底（bottom）**。

生活中一个典型的例子就是洗盘子。水槽边的一摞脏盘子变可以视作一个栈：上面是栈顶，而下面是栈底。当新的脏盘子到来时，你会把它们堆在这一摞的最上面而不是最下面；当你要洗盘子时你从最上面取而不是最下面取。我们把“新来的盘子放在最上面”这种操作称为**压栈**，把“从最上面取出一个盘子”这种操作称为**弹栈**。

仔细观察，我们可以发现，栈中的元素具有“先进栈的后出栈，后进栈的先出栈”的特性。我们称这种特性为**后进先出（Last-In-First-Out，LIFO）**。

## 栈的基本实现

下面基于[上一份讲义](https://ucas-ctf.github.io/posts/2024/2_advanced_C/ds_s1)中的单向链表给出栈的一种实现。正如前文所述，栈实际上是一种特殊的线性表，所以只需要对单向列表的实现略作修改，使其插入、删除操作仅在其一端进行即可。

&emsp;&emsp;完整代码详见<a href="https://ucas-ctf.github.io/posts/2024/2_advanced_C/code/ds_s2/stack.c" download="stack.c">此处（点击下载）</a>。

### 栈的必要元素

与单向链表类似，栈中的每个元素也有两个必要元素：被存放的数据和用来链接元素的指针：

```c
typedef int ElemType;
struct node {
    ElemType data;
    struct node *next;
};
```

类似的，我们也需要一个栈顶指针来指向这个栈的栈顶：

```c
struct node * Stack;
```

### 访问栈顶元素

返回这个链表表头的数据即可：

```c
bool ErrorFlag = true;  // 报错标记，true为存在错误

...                     // 此处省略若干代码

ElemType Top() {
    if (Stack == NULL) {    // 检查栈顶是否为空
        printf("Error: The stack is empty!\n");
        ErrorFlag = true;   // 产生报错信息
        return -1;
    } else {
        return Stack->data;
    }
}
```

上面的代码中，我们用一个全局变量ErrorFlag来报错。return -1;是一种常用的报错方式，但是此处并不适用，因为栈顶的数据很可能就是-1，这是无法区分返回的究竟是一个报错还是一个为-1的数据。


### 压栈

压栈的操作实际上就是在这个链表的表头添加一个元素：

```c
void Push(ElemType data) {
    ErrorFlag = false;                  // 清空报错标记，因为此时栈不再为空，因而也不会触发报错
    struct node * ptr = NewSpace;       // 新的元素
    ptr->data = data;
    ptr->next = Stack;
    Stack = ptr;                        // 将新元素插入到链表的最前端，也就是栈顶
}
```

### 弹栈

弹栈的操作实际上就是从这个链表的表头删除一个元素：

```c
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
```

## 扩展：用数组实现栈

如果你（曾经）是OIer，那你或许更熟悉栈的另外一种实现方式：[用数组实现](https://ucas-ctf.github.io/posts/2024/2_advanced_C/ds_ex2)。这种方式的确会更简单一点，但丧失了一些灵活性。

## 扩展：计算机中的栈

在经过前几节课的学习，相信你已经对函数和局部变量有了一些基本的认识。那么，你有没有思考过以下问题：

1. 执行函数时，计算机怎么知道传递的参数是什么呢？
2. 函数执行结束时，计算机怎么知道该回到哪里继续执行呢？
3. 局部变量保存在哪里？计算机怎么确保它只在代码的局部有效？

[这篇讲义](https://ucas-ctf.github.io/posts/2024/2_advanced_C/ds_ex3)会告诉你答案。