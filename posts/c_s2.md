# C 语言基础

Author: [Crazy_13754](https://github.com/Crazy-13754)

本次课将讲解C语言循环结构、C语言函数、C语言数组、递归思想、计算机抽象的概念，介绍相关的编程理念。

## 循环结构

### 为什么要引入循环结构

考虑以下问题：如果要求计算1到100的和，你会怎么做？

```c
int sum = 1 + 2 + 3 + 4 + 5 + ... + 100;
```

但是，计算机能够理解这样的命令：
```armasm
0000000000001149 <main>:
    1149:       f3 0f 1e fa             endbr64
    114d:       55                      push   %rbp
    114e:       48 89 e5                mov    %rsp,%rbp
    1151:       48 83 ec 10             sub    $0x10,%rsp
    1155:       83 7d fc 63             cmpl   $0x63,-0x4(%rbp)
    1159:       7f 1f                   jg     117a <main+0x31>
    115b:       8b 45 fc                mov    -0x4(%rbp),%eax
    115e:       89 c6                   mov    %eax,%esi
    1160:       48 8d 05 9d 0e 00 00    lea    0xe9d(%rip),%rax        # 2004 <_IO_stdin_used+0x4>
    1167:       48 89 c7                mov    %rax,%rdi
    116a:       b8 00 00 00 00          mov    $0x0,%eax
    116f:       e8 dc fe ff ff          call   1050 <printf@plt>
    1174:       83 45 fc 01             addl   $0x1,-0x4(%rbp)
    1178:       eb db                   jmp    1155 <main+0xc>
    117a:       b8 00 00 00 00          mov    $0x0,%eax
    117f:       c9                      leave
    1180:       c3                      ret

```

这段代码在 C 语言中的实现如下：

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