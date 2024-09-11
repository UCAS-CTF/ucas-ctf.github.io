# C 语言基础
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

