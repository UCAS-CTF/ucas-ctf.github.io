# C 语言基础

Author: [Crazy_13754](https://github.com/Crazy-13754)

本次课将讲解C语言循环结构、C语言函数、C语言数组、递归思想、计算机抽象的概念，介绍相关的编程理念。

## 循环结构

### 为什么要引入循环结构

考虑以下问题：如果要求计算1到100的和，你会怎么做？

```c
int sum = 1 + 2 + 3 + 4 + 5 + ... + 100;
```

我们引入 label 这个概念，可以使用 goto 语句实现循环：

```c
#include <stdio.h>

int main()
{
    int i;
loop:
    if (i < 100)
    {
        printf("%d\n", i);
        i++;
        goto loop;
    }
    return 0;
}
```

但它也能写成这样：

```c
#include <stdio.h>

int main()
{
    for (int i = 0; i < 100; i++)
    {
        printf("%d\n", i);
    }
    return 0;
}
```

或是这样：

```c
#include <stdio.h>

int main()
{
    int i = 0;
    while (i < 100)
    {
        printf("%d\n", i);
        i++;
    }
    return 0;
}
```

或是这样：

```c
#include <stdio.h>

int main()
{
    int i = 0;
    do
    {
        printf("%d\n", i);
        i++;
    } while (i < 100);
    return 0;
}
```

这里只是为了后继大家快速理解汇编语言的循环结构而教大家 goto 语句，实际上，在日常的编程中，我们通常不使用 goto 语句（大工程中 goto err 等会用），而是使用 for、while、do-while 语句来实现循环。大多数的情况下，使用这三种语句来实现循环是更有利于逻辑清晰的（不然发明他们干嘛）。同时，使用这三种语句来实现循环也是为了结构化编程（很多高级语言删掉了 goto 语句）。

特别地，for 循环的条件可以省略，这时候 for 循环就变成了一个无限循环：

```c
#include <stdio.h>

int main()
{
    for (;;)
    {
        printf("Hello, World!\n");
    }
    return 0;
}
```
它被称为死循环，因为它永远不会结束。可以按下 Ctrl + C 来终止这个程序。

同样，while 和 do-while 也可以实现无限循环：

```c
#include <stdio.h>

int main()
{
    while (1)
    {
        printf("Hello, World!\n");
    }
    return 0;
}
```

```c
#include <stdio.h>

int main()
{
    do
    {
        printf("Hello, World!\n");
    } while (1);
    return 0;
}
```

### 循环结构的应用

#### 示例程序——1-10000的累加

```c
#include <stdio.h>

int main()
{
    int sum = 0;
    for (int i = 1; i <= 10000; i++)
    {
        sum += i;
    }
    printf("1 + 2 + ... + 10000 = %d\n", sum);
    return 0;
}
```

### 跳转语句

#### break 语句

```c
for (int i = 0; i < 10; i++)
{
    if (i == 5)
    {
        break;
        // 从这里跳出整个循环
    }
    printf("%d\n", i);
}
```

#### continue 语句

```c
for (int i = 0; i < 10; i++)
{
    if (i == 5)
    {
        continue;
        // 从这里跳出本轮循环
    }
    printf("%d\n", i);
}
```

## c语言数组

数组是一种线性表数据结构，它用一组连续的内存空间来存储一组具有相同类型的数据。

### 数组的定义

```c
int a[10];
```

不过，数组的定义也可以这样写：

```c
int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
```

编译器将会根据初始化列表的元素个数来确定数组的长度。

### 数组的初始化

像变量一样，数组也需要初始化，否则数组中的元素是不确定的。

```c
    int list2[5];
    for (int i = 0; i < 5; ++i)
    {
        printf("%d\n", list2[i]);
    }
```

可以通过循环来初始化数组：

```c
    int list[5];
    for (int i = 0; i < 5; ++i)
    {
        list[i] = i;
    }
    for (int i = 0; i < 5; ++i)
    {
        printf("%d\n", list[i]);
    }
```

也可以通过初始化列表来初始化数组：

```c
    int list3[5] = {1, 2, 3, 4, 5};
    for (int i = 0; i < 5; ++i)
    {
        printf("%d\n", list3[i]);
    }
```

### 数组的访问

```c
int a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
for (int i = 0; i < 10; i++)
{
    printf("%d\n", a[i]);
}
```

### 数组的长度

```c
int a[10];
int len = sizeof(a) / sizeof(a[0]);
printf("%zu\n", sizeof(a));    // 40
printf("%zu\n", sizeof(a[0])); // z 代表 size_t，u 代表 unsigned
printf("%d\n", len);
return 0;
```

### 数组的应用

#### 示例程序——数组求和

```c
#include <stdio.h>

int main()
{
    int a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int sum = 0;
    for (int i = 0; i < 10; i++)
    {
        sum += a[i];
    }
    printf("1 + 2 + ... + 10 = %d\n", sum);
    return 0;
}
```

#### 示例程序——数组的排序

```c
#include <stdio.h>

int main()
{
    int a[10] = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3};
    for (int i = 0; i < 10; i++)
    {
        for (int j = i + 1; j < 10; j++)
        {
            if (a[i] > a[j])
            {
                int temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
    for (int i = 0; i < 10; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
    return 0;
}
```

## 函数

### 函数的定义

```c
int add(int a, int b)
{
    return a + b;
}
```

### 函数的调用

```c
int sum = add(1, 2);
printf("%d\n", sum);
```

## 递归与递推思想

递推和递归是计算机科学中常用的两种算法思想。它们的区别如下：递推：从初值出发反复进行某一运算得到所需结果。递归：从所需结果出发不断回溯前一运算直到回到初值再递推得到所需结果。

#### 示例程序——阶乘

```c
#include <stdio.h>

int factorial(int n)
{
    if (n == 0)
    {
        return 1;
    }
    return n * factorial(n - 1);
}

int main()
{
    int n = 5;
    printf("%d! = %d\n", n, factorial(n));
    return 0;
}
```

#### 示例程序——斐波那契数列

```c

#include <stdio.h>

int fibonacci(int n)
{
    if (n == 0)
    {
        return 0;
    }
    if (n == 1)
    {
        return 1;
    }
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main()
{
    int n = 10;
    for (int i = 0; i < n; i++)
    {
        printf("%d ", fibonacci(i));
    }
    printf("\n");
    return 0;
}
```

递归并不是万能的，它有时候会导致栈溢出。因为递归的本质是函数的调用，每次调用函数都会在栈上分配一块内存，如果递归的层次太深，栈的内存就会被耗尽。

### 示例程序——汉诺塔

```c

#include <stdio.h>

void hanoi(int n, char A, char B, char C)
{
    if (n == 1)
    {
        printf("Move disk 1 from %c to %c\n", A, C);
    }
    else
    {
        hanoi(n - 1, A, C, B);
        printf("Move disk %d from %c to %c\n", n, A, C);
        hanoi(n - 1, B, A, C);
    }
}

int main()
{
    int n = 3;
    hanoi(n, 'A', 'B', 'C');
    return 0;
}
```

## struct 结构体

结构体是一种自定义的数据类型，它可以包含多个不同类型的成员。

### 结构体的定义

```c
struct Student
{
    char name[20];
    int age;
    float score;
};
```

### 结构体的初始化

```c
struct Student s = {"Tom", 18, 90.0};
```

### 结构体的访问

```c
printf("Name: %s\n", s.name);
printf("Age: %d\n", s.age);
printf("Score: %.1f\n", s.score);
```

### 结构体的应用

#### 示例程序——学生信息管理系统

```c
#include <stdio.h>

struct Student
{
    char name[20];
    int age;
    float score;
};

int main()
{
    struct Student s = {"Tom", 18, 90.0};
    printf("Name: %s\n", s.name);
    printf("Age: %d\n", s.age);
    printf("Score: %.1f\n", s.score);
    return 0;
}
```

多个学生信息（数组）：

```c
#include <stdio.h>

struct Student
{
    char name[20];
    int age;
    float score;
};

int main()
{
    struct Student s[3] = {{"Tom", 18, 90.0}, {"Jerry", 19, 80.0}, {"Alice", 20, 70.0}};
    for (int i = 0; i < 3; i++)
    {
        printf("Name: %s\n", s[i].name);
        printf("Age: %d\n", s[i].age);
        printf("Score: %.1f\n", s[i].score);
    }
    return 0;
}
```

## 计算机抽象

计算机抽象是计算机科学中的一个重要概念，它是指将计算机的各个部分抽象为一个个的模块，从而简化计算机的设计和实现。

这里我们讨论的是 C 语言中的抽象，C 语言中的抽象是通过函数与多文件结构来实现的。

```c
// add.h
#ifndef ADD_H
#define ADD_H

int add(int a, int b);

#endif
```

```c
// add.c
#include "add.h"

int add(int a, int b)
{
    return a + b;
}
```

```c

// main.c
#include <stdio.h>
#include "add.h"

int main()
{
    int sum = add(1, 2);
    printf("%d\n", sum);
    return 0;
}
```