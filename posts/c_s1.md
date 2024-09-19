# C 语言基础

Author: [jiuhao47](https://github.com/jiuhao47)

## 基础变量类型

### 整型

```c
int a = 10;
```
<details>
<summary>int 类型的变种</summary>

<p>包括 `int`，`short`，`long`，`long long`，以及它们的无符号版本 `unsigned int`，`unsigned short`，`unsigned long`，`unsigned long long`。</p>
<pre><code>
int var_int;  
short var_short; 
long var_long; 
long long var_long_long;  
unsigned int var_unsigned_int; 
unsigned short var_unsigned_short; 
unsigned long var_unsigned_long; 
unsigned long long var_unsigned_long_long; 
</pre><code>
</details>

### 浮点型

```c
float b = 3.14;
```

<details> 
<summary>浮点型的变种</summary>

包括 `float`，`double`，`long double`。

```c
float var_float; 
double var_double; 
long double var_long_double;
```

</details>

### 字符型

```c
char c = 'A';
```

<details>
<summary>字符型的变种</summary>

`char`，以及它的无符号版本 `unsigned char`。

```c
char var_char; 
unsigned char var_unsigned_char; 
```
</details>

### 其他基本变量类型

<details>
<summary>其他基本变量类型</summary> 

`bool`（需要包含头文件 `stdbool.h`）。
```c
#include <stdbool.h>
bool var_bool; 
```
`void`，主要用在函数返回值和参数中，表示无值或任意类型。
```c
void func1();
```
`enum`，用于定义在程序中只能取一定范围内的值的类型。
```c
enum color { red, green, blue };
enum color var_color;
```
</details>


## 语句

```c
a = b + c;
a = a + 1;
```

<details>
<summary>其他的语句样式</summary>

```c
int a,b,c;
a=b=c=1;
1;
a;
a+b;
a+=c;
a++;
a,b,c;
;
a+=a,b,c++;
```
</details>

## 注释

```c
// 单行注释

/*
多行注释
*/
```

## 运算符

- 算术运算符：+, -, *, /, %
    - +: 加法
    - -: 减法
    - *: 乘法
    - /: 除法
    - %: 取余
- 关系运算符：==, !=, >, <, >=, <=
    - ==: 等于
    - !=: 不等于
    - \>: 大于
    - \<: 小于
    - \>=: 大于等于
    - \<=: 小于等于
- 赋值运算符：=, +=, -=, *=, /=, %=
    - =: 赋值

<details>
<summary>更多运算符</summary>

- 位运算符：&, |, ^, ~, <<, >>
    - &: 与
    - |: 或
    - ^: 异或
    - ~: 取反
    - <<: 左移
    - \>>: 右移
- 逻辑运算符：&&, ||, !
    - &&: 与
    - ||: 或
    - !: 非
- 赋值运算符：=, +=, -=, *=, /=, %=
    - +=: 加后赋值
    - -=: 减后赋值
    - *=: 乘后赋值
    - /=: 除后赋值
    - %=: 取余后赋值
- 其他运算符：sizeof, ?:, &, *, ->, .
    - sizeof: 计算数据类型的大小
    - ?:: 三目运算符
    - &: 取地址
    - *: 取值
    - ->: 结构体指针访问成员
</details>

## 基础库函数

### printf()

```c
printf("Hello, World!\n");

int a = 10;
printf("a = %d\n", a);

float b = 3.14;

printf("b = %f\n", b);

char c = 'A';

printf("c = %c\n", c);
```

### scanf()

```c
int a;
scanf("%d", &a);

float b;
scanf("%f", &b);

char c;
scanf("%c", &c);
```

### getchar()

```c
char c = getchar();
```

### putchar()

```c
putchar('A');

char c = getchar();
putchar(c);
```

### 示例程序——加法计算器

```c
#include <stdio.h>
int main()
{
    int a, b;
    printf("请输入两个整数：");
    scanf("%d %d", &a, &b);
    printf("%d + %d = %d\n", a, b, a + b);
    return 0;
}
```

## 条件与循环


### 条件语句

#### if 语句

```c
if (condition) {
    // code
}
```

#### if-else 语句

```c
if (condition) {
    // code
} else {
    // code
}
```

#### if-else if-else 语句

```c
if (condition1) {
    // code
} else if (condition2) {
    // code
} else {
    // code
}
```

<details>
<summary>条件语句的嵌套</summary>

```c
if (condition1) {
    if (condition2) {
        // code
    } else {
        // code
    }
} else {
    // code
}
```

</details>

<details>
<summary>不完整条件语句</summary>

```c
if (condition1) {
    // code
}
else if(condition2) {
    // code
}

```

</details>

#### 示例程序——加、减、乘计算器
```c
#include <stdio.h>
int main()
{
    int a, b;
    printf("请输入两个整数：");
    scanf("%d %d", &a, &b);
    char op;
    printf("请输入运算符：");
    scanf("%c", &op);
    if (op == '+') {
        printf("%d + %d = %d\n", a, b, a + b);
    } else if (op == '-') {
        printf("%d - %d = %d\n", a, b, a - b);
    } else if (op == '*') {
        printf("%d * %d = %d\n", a, b, a * b);
    } else {
        printf("不支持的运算符\n");
    }
    return 0;
}
```

### 循环语句

#### while 循环

```c
while (condition) {
    // code
}
```

#### do-while 循环

```c
do {
    // code
} while (condition);
```

<details>
<summary>while 和 do-while 的区别</summary>

```c
int i = 0;
while (i > 0) {
    printf("%d\n", i);
    i++;
}
// 不会输出任何内容

int j = 0;
do {
    printf("%d\n", j);
    j++;
} while (j > 0);

// 会循环输出0, 1, 2, ... 

// do-while 会先执行一次循环体，再判断循环条件
// while 先判断循环条件，再执行循环体
```

</details>

#### for 循环

```c
for (init; condition; increment) {
    // code
}
// init: 循环变量初始化，只在循环开始时执行一次，e.g. int i = 0;
// condition: 循环条件，每次循环开始前判断，为真则执行循环体，为假则跳出循环，e.g. i < 10;
// increment: 循环变量增量，每次循环结束后执行，e.g. i++;

// 示例
for (int i = 0; i < 10; i++) {
    // code
}
```

<details>   
<summary>循环语句的嵌套</summary>

```c
for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 10; j++) {
        // code
    }
}
```

</details>


<details>
<summary>死循环</summary>

```c
for (;;) {
    // code
}

while (1) {
    // code
}

do {
    // code
} while (1);
```

</details>

#### 示例程序——1-10000的累加

```c
#include <stdio.h>
int main()
{
    int sum = 0;
    for (int i = 1; i <= 10000; i++) {
        sum += i;
    }
    printf("1 + 2 + ... + 10000 = %d\n", sum);
    return 0;
}
```


### 跳转语句

#### break 语句

```c
for (int i = 0; i < 10; i++) {
    if (i == 5) {
        break;
        // 从这里跳出整个循环
    }
    printf("%d\n", i);
}
```

#### continue 语句

```c
for (int i = 0; i < 10; i++) {
    if (i == 5) {
        continue;
        // 从这里跳出本轮循环
    }
    printf("%d\n", i);
}
```

#### goto 语句

```c
for (int i = 0; i < 10; i++) {
    if (i == 5) {
        goto end;
        // 跳转到标签end
    }
    printf("%d\n", i);
}
end:
```




