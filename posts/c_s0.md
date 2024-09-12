# C 语言基础
## Hello World
```c
// helloworld.c
#include <stdio.h>
// 头文件
int main()
{
    printf("Hello, World!\n");
    return 0;
}
```

## 编译运行
```bash
# 编译
gcc -c helloworld.c
gcc helloworld.o -o helloworld
# 运行
./helloworld
```

