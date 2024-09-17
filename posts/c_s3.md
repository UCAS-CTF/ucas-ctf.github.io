**首先声明**：因为本文长度有限，难免有不详尽之处，若看此讲义是有任何问题，可以在课上随时提问，或者查看[菜鸟教程](https://www.runoob.com/cprogramming/c-tutorial.html)(也可以用于预习或复习及日常查找)

# 指针


c语言中的指针是一种特殊的变量，它储存的值是一个内存中的地址，我们可以用这个地址来访问内存中的值。

## 地址

地址，即一个变量在内存中的位置，在32位系统中，地址占4字节，在64位系统中，地址占8字节。

例：

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


C语言中有两个地址运算符：`&` 和 `*` 

前者用于获取一个变量的地址，后者用于获取指针变量所指向的内存地址的值。

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

## 声明一个指针

声明一个指针变量，需要在类型名后面加上 `*`

```c
char* p1;
int* p2;
float* p3;
struct student* p4;// 结构体指针
```

从一个指针中获取指针指向地址的值，需要用 `*` 运算符


```c
int* p = NULL; // 声明一个指针变量 p
// 或者int *p;
int a = 10;
p=&a; // 将 a 的地址赋值给 p
printf("p points to %d\n", *p); // 输出 p 指向的内存地址的值
// p points to 10
```

**注意** ：下面这个例子是错误的。

```c
int* p;
*p=10; // 错误，不能对未初始化的指针赋值
```

这是因为 `p` 现在的值是未知的，想一个未知的地址写入数据很可能造成错误。

在声明指针的时候，如果没有确切的地址可以赋值，为指针变量赋一个 `NULL` 值是一个良好的编程习惯。赋为 `NULL` 值的指针被称为空指针。这是为了防止该指针由于初始的随机值而访问到未知的内存地址，造成不可预估的结果。访问空指针会导致程序崩溃，而不是不可预期的结果

### 函数指针（可选）



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




## 指针与数组

事实上，指针也可以指向数组。而数组名为该数组的第一个元素的地址。

```c
int arr[] = {1, 2, 3, 4, 5};
int* p = arr; // 声明一个指针变量 p 指向数组 arr
printf("%d\n", *(p+2)); // 输出 p 指向的数组的第三个元素
// 3
```
指针的类型不同，其 `+1` 的偏移字符数也不同，通常偏移一个类型的大小。



### 数组指针与指针数组

注意：C语言中，优先级：`()` > `[]` > `*`

#### 数组指针

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


一些更为复杂的例子（选）：

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

```c
int (*p)[5];
int arr[10][5]={0};// 声明一个二维数组 arr，其长度为10，每一项的长度为5
// 即 arr[i] 的值为一个长度为5的数组的地址
printf("%p\n",arr[0]);
// 0x7fffe96653b0

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



#### 指针数组

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
### 总结

1. 数组指针简单理解为“数组的指针”，首先这个变量是一个指针，其次，”数组”修饰这个指针，意思是说这个指针存放着一个数组的首地址，或者说这个指针指向一个数组的首地址。

2. 指针数组简单理解为“指针的数组”，首先这个变量是一个数组，其次，”指针p”修饰这个数组，意思是说这个数组的所有元素都是指针类型。


## 指针与函数

### 指针作为函数参数

如何写一个函数，交换两参数的值？（前置：变量的作用域）

```c
void swap(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
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

指针作为参数传入函数，最主要的作用是实现在函数内实现外部变量的修改。




# 结构体

用于表示一些变量的集合，可以描述一个复杂的对象。

## 定义

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

## 初始化及访问

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

## typedef

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
typedef bool int;// c语言中没有bool类型，用int代替
```

## 位域（自行搜索）

略

# 内存管理


# 调试

