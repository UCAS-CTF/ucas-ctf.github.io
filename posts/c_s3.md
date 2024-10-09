# C语言基础

Author: [dx3906999](https://github.com/dx3906999)

**首先声明**：因为本文长度有限，难免有不详尽之处，若看此讲义是有任何问题，可以在课上随时提问，或者查看[菜鸟教程](https://www.runoob.com/cprogramming/c-tutorial.html)(也可以用于预习或复习及日常查找)

## 指针


c语言中的指针是一种特殊的变量，它储存的值是一个内存中的地址，我们可以用这个地址来访问内存中的值。

### 引子

我们先以一个简单的例子来说明指针的概念：

现在有下面这样一张表，计算机将变量储存在这样的表中

| id | 变量 | 值 |
|---|---|---|
| 0 | x | 10 |
| 1 | y | 'a' |
| 2 | z | 1.23 |
|...|...|...|

其中变量 `x` 的id为0，值为 10. 如果我们想要访问变量 `x` 的值，只需要在这张表中查到它的id即可。同时，`x` 的值不止可以被理解为一个数，也可以被理解为它储存了一个id，其中id=10。这时如果我们想访问id为10的变量的值，就可以使用变量 `x` 储存的值为id在这张表中进行查找。



### 地址



在真实的计算机中，变量名会被编译成储存这个变量的地址或寄存器中，从而从内存上看会有如下结构：


```
+----------------+----------------+
|    address     |     value      |
+----------------+----------------+
| 0x7fffffffd890 |      0x1       |
| 0x7fffffffd898 | 0x7ffff7decc8a |
| 0x7fffffffd8a0 | 0x555555555149 |
| 0x7fffffffd8a8 |  0x155554040   |
| 0x7fffffffd8b0 | 0x7fffffffd8a8 |
+----------------+----------------+
```

事实上，上面是一个64位程序的**栈**的一部分。

在 x86 架构中，指针变量的大小为 4 字节（32位程序），而在 x64 架构中，指针变量的大小为 8 字节（64位程序）。

C语言中有两个地址运算符：`&` 和 `*` 

前者用于获取一个变量的地址，后者用于获取指针变量所指向的内存地址的值或者声明指针变量。

```c
int a = 10;
printf("a\'s address is %p\n", &a); // 输出 a 的地址
// %p 以指针形式输出
// a's address is 0x7ffce1a0d014
```

```c
char ch;
scanf("%c", &ch); // 输入一个字符
// ...
```

### 声明一个指针变量

声明一个指针变量，需要在变量名前面加上 `*`

```c
char *p1;
int *p2;
float *p3;
void *p4; // 无类型指针
struct student *p5;// 结构体指针
char **p6; // 指向指针的指针，多重指针
char* p7; // 这样也可以
char *p8,*p9; // 多重声明
```

`void *` 类型指针比较常见，通常见于函数返回值，我们在使用这个指针时需要进行强制类型转换变为其他指针。

从一个指针中获取指针指向地址的值，需要用 `*` 运算符


```c
int *p = NULL; // 声明一个指针变量 p
// 或者int *p;
int a = 10;
p=&a; // 将 a 的地址赋值给 p
printf("p points to %d\n", *p); // 输出 p 指向的内存地址的值
// p points to 10
```

**注意** ：下面这个例子是错误的。

```c
int *p;
*p=10; // 错误，不能对未初始化的指针指向的地址赋值
```

这是因为 `p` 现在的值是未知的，向一个未知的地址写入数据很可能造成错误。

在声明指针的时候，如果没有确切的地址可以赋值，为指针变量赋一个 `NULL` 值是一个良好的编程习惯。赋为 `NULL` 值的指针被称为空指针。这是为了防止该指针由于初始的随机值而访问到未知的内存地址，造成不可预估的结果。访问空指针会导致程序崩溃，而不是不可预期的结果

#### 函数指针

<details>
<summary>选择阅读</summary>

<div markdown="1">

还有一种指针，函数指针，它指向一个函数的地址。其声明为：

```c
return_type (*pointer_name)(parameter_type_list);
```
类型即为
```c
return_type (*)(parameter_type_list);
```

下面是一个例子


```c
int add(int a, int b){
    return a+b;
}

int sub(int a, int b){
    return a-b;
}

int main(){
    int (*p)(int, int); // 声明一个指向函数的指针变量 p
    p = add; // 将 add 函数的地址赋值给 p
    printf("%d\n", p(2, 3)); // 输出 p 指向的函数的返回值
    // 5
    p = sub; // 将 sub 函数的地址赋值给 p
    printf("%d\n", p(2, 3)); // 输出 p 指向的函数的返回值
    // -1
    return 0;
}
```

</div>

</details>

### 指针与数组

事实上，指针也可以指向数组。而数组名为该数组的第一个元素的地址。

```c
int arr[] = {1, 2, 3, 4, 5};
int *p = arr; // 声明一个指针变量 p 指向数组 arr
char *cp = arr;
printf("%p,%p,%p,%p,%d\n",p,p+1,cp,cp+1,*(p+2)); // 输出 p 指向的数组的第三个元素
```
指针的类型不同，其 `+1` 的偏移字符数也不同，通常偏移一个类型的大小。




#### 数组指针与指针数组

注意：C语言中，优先级：`()` > `[]` > `*`

##### 数组指针

意为数组的指针，即指向数组的指针。

```c
char str[] = "hello world";
char* p = str; // 声明一个指针变量 p 指向数组 str 
//(数组名==数组第一个元素的地址)
// 等价于 char* p = &str[0];
printf("%s\n", p); // 输出 p 指向的字符串
// hello world
printf("%c\n", *p); // 输出 p 指向的字符串的第一个字符
// h
printf("%c\n", *(p+1)); // 输出 p 指向的字符串的第二个字符
// e
```




```c
int (*p)[5]; // 声明一个指向长度为5的数组的指针变量 p
int arr[5] = {1, 2, 3, 4, 5};
p = &arr; // 将 arr 的地址赋值给 p
// p的类型是 int (*)[5], arr的类型为 int[5] 或 int *
// 若使用 p=arr 则会报类型错误的警告
// 但其实 p 指向的地址是 arr 的地址，所以 p 与 arr 在值上相等
printf("%d\n", (*p)[2]); // 输出 p 指向的数组的第三个元素
// 3
```

<details>

<summary>一些更为复杂的例子</summary>

<div markdown="1">

```c
int (*p)[5];
int arr[10][5]={0};// 声明一个二维数组 arr，其长度为10，每一项的长度为5
// 即 arr[i] 的值为一个长度为5的数组的地址
printf("%p\n",arr[0]);
// 0x7fffe96653b0 (这是我电脑里的地址)

// a;//代表数组首行地址，一般用a[0][0]的地址表示
// &a;//代表整个数组的地址，一般用a[0][0]地址表示
// a[i];//代表了第i行起始元素的地址，一般用a[i][0]的地址表示
// &a[i];//代表了第i行的地址，一般用a[i][0]的地址表示
// a[i]+j;//代表了第i行第j个元素地址,a[i]就是j==0的情况
// a[i][j];//代表了第i行第j个元素
// &a[i][j];//代表了第i行第j个元素的地址

p = arr; // 将 arr 的首项的地址赋值给 p
// p的类型是 int (*)[5], arr的类型为 int[10][5] 或 int (*)[5] (即arr第一项的地址)
printf("%d\n", (*p)[2][3]); // 输出 p 指向的数组的第三行第四列元素

p = &arr[2]; // 将 arr 的第三项的地址赋值给 p

printf("%d\n", (*p)[3]); // 输出 p 指向的数组的第四列元素
```

</div>

</details>

##### 字符串

字符串在内存中以字符数组的形式存储，以`\0`作为结尾，每个字符占用一个字节，可以写作如下形式：

```c
char s[]={'h', 'e', 'l', 'l', 'o', '\0'}
```


常量字符串，即在编译期间就确定了的字符串，在c语言中有两种写法，但并不等价。

```c
char s[]="hello world";
char* p="hello world";
```

根据上面的知识，我们都知道 `s` 和 `p` 都指向字符串的首地址，但前面的字符串可以被修改，后面的不能。

```c
#include <stdio.h>

int main(int argc, char const *argv[])
{
    char s[]="hello world";
    char* p="hello world";
    s[0]='a';
    p[0]='a';
    return 0;
}
```

编译执行后会输出 `Segmentation fault` 错误，主要原因是两者的储存位置不同，`s` 储存在栈上，`p` 储存在只读常量区，所以前面的字符串可以被修改而后面的不能。（详细情况可参考下一节补充资料，先了解就好）

变化的字符串与数组无太大差异，主要注意 `\0` 也是字符串长度的一部分，比如 `char s[10];` 事实上只能储存9个有效字符，若强行写入10个字符，可能会造成内存地址的泄露。


##### 指针数组

意为一个由指针组成的数组。该数组里存储的是一些地址。

```c
int* p[3]; // 声明一个指针数组 p，每个元素都是一个指针变量
// 可以理解为数组中每个元素类型为 int*
int arr1[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
int arr2[4] = {11, 12, 13, 14};
int arr3[3] = {15, 16, 17};
p[0] = arr1;
p[1] = arr2;
p[2] = arr3;
// +----------------+     
// │ array1_address │----> {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}
// +----------------+
// │ array2_address │----> {11, 12, 13, 14}
// +----------------+
// │ array3_address │----> {15, 16, 17}
// +----------------+

printf("%d\n",p[0][2]);
// 3
printf("%d\n",p[1][1]);
// 12
printf("%d\n",p[2][0]);
// 15
```

另一个更为常见的例子即是字符串数组，即一个由字符串组成的数组。

```c
char* str[3] = {"hello", "world", "c"};
printf("%s\n", str[0]);
// hello
printf("%s\n", str[1]);
// world
printf("%s\n", str[2]);
// c
```


#### 总结

1. 数组指针简单理解为“数组的指针”，首先这个变量是一个指针，其次，”数组”修饰这个指针，意思是说这个指针存放着一个数组的首地址，或者说这个指针指向一个数组的首地址。

2. 指针数组简单理解为“指针的数组”，首先这个变量是一个数组，其次，”指针p”修饰这个数组，意思是说这个数组的所有元素都是指针类型。


### 指针与结构体

用指针指向结构体

```c
typedef struct person{
    char name[20];
    int age;
    char gender;
}Person;

int main(){
    Person* p = (Person*)malloc(sizeof(Person)); // 分配一个 Person 结构体的内存
    p->name = "Alice";
    p->age = 18;
    p->gender = 'F';
    printf("%s is %d years old and %c\n", p->name, p->age, p->gender);
    // Alice is 18 years old and F
    free(p); // 释放该内存块
    p=NULL; // 置空指针
    return 0;
}
```

结构体中可以包含指针，下面是一个单链表的节点

```c
typedef struct node{
    int data;
    struct node* next;
}Node;
```




### 指针与函数

#### 指针作为函数参数

如何写一个函数，交换两参数的值？（前置：变量的作用域）

```c
#include <stdio.h>

void swap_test(int a, int b){
    int temp = a;
    a = b;
    b = temp;
}


void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main(){
    int x = 10;
    int y = 20;
    printf("before: %d %d\n", x, y);
    swap_test(x, y);
    printf("after: %d %d\n", x, y);
    printf("before: %d %d\n", x, y);
    swap(&x, &y);
    printf("after: %d %d\n", x, y);
    return 0;
}
```

数组名也是指针，若传入函数，则函数内对数组元素的修改会影响到原数组。

```c
#include <stdio.h>

void func(int arr[]){
    arr[0] = 100;
}

int main(){
    int arr[3] = {1, 2, 3};
    printf("before: %d %d %d\n", arr[0], arr[1], arr[2]);
    func(arr);
    printf("after: %d %d %d\n", arr[0], arr[1], arr[2]);
    return 0;
}

// before: 1 2 3
// after: 100 2 3
```

结构体也通常以指针的形式传入函数中，或作为函数的返回值

```c
int get_age(struct person *p){
    return p->age;
}

Node *get_next(Node* p){
    return p->next;
}
```



指针作为参数传入函数，最主要的作用是实现在函数内实现外部变量的修改。

#### 函数指针

参考上边的选择阅读部分


## 结构体

<details>
<summary>详情在上一篇教程，你要是想看也行</summary>

<div markdown="1">

用于表示一些变量的集合，可以描述一个复杂的对象。

### 定义

```c
struct student{
    char name[20];
    int age;
    char gender;
};
```

也可以在定义结构体时声明变量

```c
struct student{
    char name[20];
    int age;
    char gender;
}Alice, Bob, Tom;// 声明三个结构体变量
```

也可以这样

```c
struct student{
    char name[20];
    int age;
    char gender;
};
// ...
struct student Alice, Bob, Tom;// 声明三个结构体变量
struct student Students[10];// 声明一个结构体数组
```

定义可以在 `main` 函数里，也可以在 `main` 函数外，但推荐在 `main` 函数外。

### 初始化及访问

```c
struct student Alice = {"Alice", 18, 'F'};
struct student Bob = { 0 };
struct student Tom = { .name = "Tom", .age = 20, .gender = 'M' };
```

也可以这样访问

```c
struct student Alice;
Alice.name = "Alice";
Alice.age = 18;
Alice.gender = 'F';
```

如果定义的是一个结构体指针，则可以这样：

```c
struct student* p = &Alice;
p->name = "Alice";
p->age = 18;
p->gender = 'F';
```

嵌套

```c
struct person{
    char name[20];
    int age;
    char gender;
    struct address{
        char city[20];
        char street[20];
        int number;
    }address;
};
```

初始化时：

```c
struct person Alice = {"Alice", 18, 'F', {"Beijing", "Chaoyang", 1001}};
```

### typedef

`typedef` 关键字可以给一个类型起一个新的名字，方便使用。

```c
typedef struct{
    char name[20];
    int age;
    char gender;
}student;
// ...

student Alice = {"Alice", 18, 'F'};
```

```c
typedef bool int;// c99以前c语言中没有bool类型，用int代替
```


### 位域（自行搜索）

</div>
</details>

## 内存管理

有时候数据过大或者不能预先知道数据的大小，这时候我们需要手动分配和释放内存。

### 有关内存管理的几个函数

函数原型：

```c
void *malloc(size_t size); // 分配指定大小的内存块，返回指向该内存块的指针
void *calloc(size_t nmemb, size_t size); // 分配指定数量和大小的内存块，并初始化为0
void *realloc(void *ptr, size_t size); // 重新分配内存块，返回指向新内存块的指针
void free(void *ptr); // 释放内存块
```

例子：

```c
#include <stdio.h>
#include <stdlib.h>

int main(){
    int* p = (int*)malloc(sizeof(int)*20); // 分配20个int的内存块
    for(int i=0; i<20; i++){
        p[i] = i;
    }
    for(int i=0; i<20; i++){
        printf("%d ", p[i]);
    }
    free(p); // 释放该内存块
    p=NULL; // 置空指针
    return 0;
}
```

值得注意的是，内存的分配与释放一定要成对出现；此外，释放后的指针应该赋值为空指针，防止一种常见的漏洞 **Use After Free (UAF)**

### 变量的储存

这里主要介绍几个名词（以linux的elf可执行文件为例），感兴趣的同学可以先自行查找，具体内容后面会讲。

一般地，在函数内声明的变量储存在栈 (stack) 上；刚刚提过的、手动分配的变量储存在堆 (heap) 上；
一些常量，比如 `printf("hello");` 中的 `"hello"` 储存在程序文件内的 `.rodata` 段 (read-only data segment) 上；未初始化全局变量储存在程序文件的 `.bss` 段 (block started by symbol) 上等等。

![进程的内存空间](https://ucas-ctf.github.io/posts/image/c_s3/c_s3_1.png)

[图片源](https://img-blog.csdnimg.cn/img_convert/9e1c67c4a8d3f61041f74721935ebf0c.png)

## gdb调试

### gdb安装

```bash
sudo apt install gdb
```

推荐插件：`pwndbg` `gef` 等等

https://blog.csdn.net/qq_51232724/article/details/124133459

### 调试一个带有源码的c程序

#### 编译程序

```bash
gcc -g hellogdb.c -o hellogdb
```

这里带 `-g` 参数是为了生成调试信息（如程序源码等），方便gdb调试。

```c
#include <stdio.h>

void swap(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main(){
    int a = 1;
    int b = 2;
    swap(&a, &b);
    getchar();
    int c[3] = {1,2,3};
    for(int i=0; i<3; i++){
        printf("%d ", c[i]);
    }
    printf("\nhello gdb\n");
    return 0;
}
```


#### 调试程序

直接调试

```bash
gdb hellogdb
```

附加到进程调试

```bash
gdb hellogdb pid
# 或者
gdb -p pid
# 或者
gdb
attach pid
```

pid是进程号

获取进程号方法

```bash
ps -A
# 或者
top
# 或者
pidof hellogdb
```


#### 常用命令

- `help` 显示帮助信息
  - `help l` 显示 `l` 命令的帮助信息
- `l` 显示代码
  - `l 5` 显示当前文件第5行附近10行的代码
  - `l 1,12` 显示当前文件第1行到第12行的代码
- `r` 运行程序
- `start` 在main函数下临时断点并运行程序
- `b` 设置普通断点
  - `b 10` 设置第10行的断点
  - `b main` 设置 `main` 函数的断点
- `watch var` 设置监视断点， 当变量 `var` 被修改时，程序会自动暂停
  - `watch a` 设置监视变量 `a` 的值
- `catch` 设置异常捕获点，当程序运行到该点时，会自动暂停
  - `catch function` 设置捕获函数 `function` 发生时，程序会自动暂停
- `info` 显示信息
  - `info b` 显示所有断点信息
- `d 断点号` 删除断点
  - `d 1` 删除第1个断点
- `n` 逐过程（不进入深一层的函数）
- `s` 逐语句（进入深一层的函数）
- `c` 继续运行程序直到下一个断点
- `p` 打印变量的值
  - `p a` 打印变量 `a` 的值
  - `p *p` 打印指针 `p` 指向的地址的值
- `x` 显示内存
  - `x /20x  0x7fffffffd7fc` 以4个字节为单位，显示从 `0x7fffffffd7fc` 开始向地址增加方向的的20个单位的内容
- `set var` 修改变量的值
  - `set var a = 10` 修改变量 `a` 的值为10
  - `set {int}0x7fffffffd7fc = 10` 将地址为 `0x7fffffffd7fc` 的变量以int类型的方式赋值为10
- `display var` 显示变量的值
- `watch var` 监视变量的值，每当变量的值发生变化时，程序会自动暂停
- `undisplay` 取消监视变量的值
- `finish` 运行到当前函数返回
- `until` 运行到指定的行号
- `bt` 显示函数调用栈
- `q` 退出gdb调试

其中我们基本要掌握的有

1. `b` 设置断点
2. `r` 运行程序
3. `n` 逐过程
4. `s` 逐语句
5. `c` 继续运行程序
6. `p` 打印变量的值
7. `x` 显示内存
8. `set var` 修改变量的值
9. `display var` 显示变量的值
10. `q` 退出gdb调试

#### 更进一步

- `disassemble` 查看汇编代码
- `ni` 汇编指令的逐过程
- `si` 汇编指令的逐语句
- `!command` command是shell命令，可以在gdb内执行shell命令

还有更多更详细的命令，可以自行搜索。


## 综合应用


<details>

<summary>详情在下一篇教程（数据结构相关），你要是想看也行</summary>

<div markdown="1">


结合本次课及之前的C语言基础知识，我们可以写出一些更为复杂的东西，比如一个简短版的学生管理系统。

下面是一个简单的例子

```c
#include <stdio.h>
#include <stdlib.h>

#define MAX_STUDENTS 100
#define MAX_CLASSES 10

typedef struct{
    char name[20];
    int age;
    int score;
    char gender;
}Student;

void print_student(Student s){
    printf("%s is %d years old and %c\n", s.name, s.age, s.gender);
}

Student* create_student(char* name, int age, int score, char gender){
    student* p = (Student*)malloc(sizeof(Student));
    p->name = name;
    p->age = age;
    p->score = score;
    p->gender = gender;
    return p;
}

void delete_student(Student* p){
    free(p);
}

int main(){
    // 自行实现一些管理功能吧
    // 比如弄一个叫school的数组，里面有10个班级，每个班级有100个学生
    // 然后可以实现增删改查功能
    // 增删功能可以用函数实现，比如create_student, delete_student
    // 当然，你自己也可以定义一些函数来实现查找功能等等
    return 0;
}
```

</div>

</details>

## 补充

关于 `main` 函数参数的简介

```c
void main(int argc, char* argv[], char* envp[]){
    //...
}
```

- `argc` 代表命令行参数的个数
- `argv` 是一个指针数组，每个元素指向一个字符串，表示命令行参数
- `envp` 是一个指针数组，每个元素指向一个字符串，表示环境变量

例子

```c
#include <stdio.h>

int main(int argc, char* argv[], char* envp[]){
    printf("argc: %d\n", argc);
    for(int i=0; i<argc; i++){
        printf("argv[%d]: %s\n", i, argv[i]);
    }
    printf("envp[0]: %s\n", envp[0]);
    return 0;
}
```

上述程序打印了命令行参数的个数和对应的参数，以及第一个环境变量的值。

```bash
> gcc main_argvs.c -o main_argvs
> ./main_argvs 1 2 1+2+3 "a string" not a string
argc: 8
argv[0]: ./main_argvs
argv[1]: 1
argv[2]: 2
argv[3]: 1+2+3
argv[4]: a string
argv[5]: not
argv[6]: a
argv[7]: string
envp[0]: SHELL=/bin/bash
```




