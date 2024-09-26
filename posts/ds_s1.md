# 数据结构入门：线性表与链表

## 线性表

**线性表（list）** 是最基础最简单的数据结构，它就是线性排布的一串数据。在这串数据的任何一个位置，都可以执行下列操作中的任何一个：

* 访问这个数据（读取它的值）
* 修改这个数据
* 插入一个新的数据
* 删除一个数据

## 用链表实现线性表

顾名思义，**链表**就是用指针将元素链接起来，这是实现线性表的一种常见方式。

### 链表的必要成员

从上面的介绍可以发现，链表中的元素主要有两个必要的成员：一个是被存放其中的数据，另一个是用来链接结点的指针。因此，我们可以按下述方式定义链表中的一个结点：

```C
typedef int ElemType;
struct node {
    ElemType data;
    struct node *next;
};
```

为了提高代码的可扩展性，我们用typedef来将链表存储的数据类型宏定义为ElemType。这样，如果我们想让链表适用于int以外的其它数据类型时，只需要修改这里的typedef就可以了。

由于链表是通过在一起的，我们可以通过沿着next指针向后走来访问表中的其它元素。换言之，只要知道了表中的第一个元素（称之为**表头**），我们就可以便利整个链表。所以，我们还需要一个表头指针：

```C
struct node *list;
```

### 访问第k个元素

你也许会想，我们能否向访问数组那样去访问链表中的元素？答案是否定的。对于链表，你仅知道表头在哪里，以及它与哪一个元素相连。如果你想要找到第k个元素，你只能从表头开始，沿着next指针寻找k个元素：

```C
ElemType ListAccess(int k) {
    struct node *now = list;
    int cnt = 0;
    while (now != NULL) {
        cnt++;
        if (cnt == k) {
            return now->data;   // 返回找到的数据
        }
        now = now->next;        // 沿着next指针向后跳
    }
    printf("Sorry, there are only %d elements in the list.\n", cnt);
    return -1;                  // 返回一个报错
}
```
（上述代码看上去是完全正确的，但其实有一个隐藏的bug，你能发现吗?）

这就是链表与数组最大的区别：对于随机给定的一个k，链表不能很快地找到其中的第k个元素，所以我们称链表是**不支持随机访问**的。

### 修改第k个元素

类似于访问第k个元素，只要我们能找到它，就能修改它的数据：

```C
void ListModify(int k, ElemType data) {
    struct node *now = list;
    int cnt = 0;
    while (now != NULL) {
        cnt++;
        if (cnt == k) {
            now->data = data;
            return;
        }
        now = now->next;
    }
    printf("Sorry, there are only %d elements in the list.\n", cnt);
}
```

### 在第k个位置插入一个元素

向链表中插入一个元素需要解决两个问题：

1. 我们需要新的空间来存放其中的数据；
2. 我们需要改变它前后元素的链接关系。
   
这意味着，我们需要完成一下操作：

1. 使用malloc()函数申请新的空间；
2. 记它之前的元素为pre，之后的元素为nxt，那么，在插入这个元素之前，pre的next指针指向nxt；而要插入这个元素，我们需要把pre的next指针改成指向它，将它的指针改成指向nxt；
3. 上一条的一个例外情况是表头，它没有之前的元素，但此时我们需要将表头指针改成指向这个新加入的元素。

代码如下：

```C
void ListInsert(int k, ElemType data) {
    struct node *now = list;

    if (k == 1) {
        struct node *ptr = NewSpace;
        ptr->data = data;
        ptr->next = now;
        list = ptr;
        return;
    }

    int cnt = 0;
    while (now != NULL) {
        cnt++;
        if (cnt == k - 1) {
            struct node *ptr = NewSpace;
            ptr->data = data;
            ptr->next = now->next;
            now->next = ptr;
            return;
        }
        now = now->next;
    } 
    printf("Sorry, there are only %d elements in the list.\n", cnt);
}
```

注意上述代码中，为了简化代码，我们使用NewSpace宏定义代替了调用malloc()函数的过程，这一宏定义如下：

```C
#define NewSpace (struct node *)malloc(sizeof(struct node))
```

### 删除第k个元素

删除就是上述过程的逆过程：

```C
void ListRemove(int k) {
    struct node *now = list;

    if (k == 1) {
        if (list == NULL) {
            printf("Sorry, the list is empty.\n");
            return;
        }
        // 永远别忘了检查指针是否是空的！
        struct node *ptr = list;
        list = list->next;
        free(ptr);
    }

    int cnt = 0;
    while (now != NULL) {
        cnt++;
        if (cnt == k - 1) {
            if (now -> next == NULL) {
                break;
            }
            struct node *ptr = now->next;
            now->next = now->next->next;
            free(ptr);
            return;
        }
        now = now->next;
    }
    printf("Sorry, there are only %d elements in the list.\n", cnt);
}
```

## 扩展：双向链表

上述的链表仅有一个向后的指针，仅能从一个方向访问数据，我们称之为**单向链表**。那么，如果我们再添加一个向前的指针呢？这种可以从两个方向进行访问的链表称为**双向链表**，详见：[双向链表的实现](https://ucas-ctf.github.io/posts/ds_ex1)。