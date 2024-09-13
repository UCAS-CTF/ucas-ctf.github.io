# C 语言基础

Author: [jiuhao47](https://github.com/jiuhao47)

## 基础变量类型

### 整型

```c
int a = 10;
```

### 浮点型

```c
float b = 3.14;
```

### 字符型

```c
char c = 'A';
```

## 语句

### 表达式语句

```c
a = b + c;
```

### 复合语句

```c
{
    // code
}
```

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
```

### gets()

```c
char str[100];
gets(str);
```

### puts()

```c
char str[100] = "Hello, World!";
puts(str);
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

#### for 循环

```c
for (init; condition; increment) {
    // code
}
```

### 跳转语句

#### break 语句

```c

for (int i = 0; i < 10; i++) {
    if (i == 5) {
        break;
    }
    printf("%d\n", i);
}
```

#### continue 语句

```c
for (int i = 0; i < 10; i++) {
    if (i == 5) {
        continue;
    }
    printf("%d\n", i);
}
```

#### goto 语句

```c
for (int i = 0; i < 10; i++) {
    if (i == 5) {
        goto end;
    }
    printf("%d\n", i);
}
end:
```



## 变量类型
### 整型（Integer Types）
包括 `int`，`short`，`long`，`long long`，以及它们的无符号版本 `unsigned int`，`unsigned short`，`unsigned long`，`unsigned long long`。
```c
int var_int;  
short var_short; 
long var_long; 
long long var_long_long;  
unsigned int var_unsigned_int; 
unsigned short var_unsigned_short; 
unsigned long var_unsigned_long; 
unsigned long long var_unsigned_long_long; 
```

### 浮点型（Floating-Point Types）

包括 `float`，`double`，`long double`。

```c
float var_float; 
double var_double; 
long double var_long_double;
```

### 字符型（Character Types）

`char`，以及它的无符号版本 `unsigned char`。

```c
char var_char; 
unsigned char var_unsigned_char; 
```

### 布尔型（Boolean Type）

`bool`（需要包含头文件 `stdbool.h`）。

```c
#include <stdbool.h>
bool var_bool; 
```

### 空类型（Void Type）

`void`，主要用在函数返回值和参数中，表示无值或任意类型。

```c
void func1();
```

### 枚举类型（Enumeration Type）

`enum`，用于定义在程序中只能取一定范围内的值的类型。

```c
enum color { red, green, blue };
enum color var_color;
```

### 派生类型

包括数组类型、结构类型、联合类型和指针类型。

#### 数组类型（Array Types）

```c
int var_array[10]; 
```

#### 结构类型（Structure Types）

```c
struct {
    int a;
    float b;
} var_struct;
```

#### 联合类型（Union Types）

```c
union {
    int a;
    float b;
} var_union;
```

#### 指针类型（Pointer Types）

```c
int *var_pointer;
```

