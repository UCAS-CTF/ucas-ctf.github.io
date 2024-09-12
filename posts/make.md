# Makefile

本教程基于[Makefile基础](https://liaoxuefeng.com/books/makefile/introduction/index.html)

## 安装
```bash
sudo apt install make
```

## 基础规则

你需要在当前目录下创建一个名为`Makefile`的文件，然后在其中编写规则。

### 文件生成指令与依赖关系
```makefile
target: dependencies
    command
```

- `target`：目标文件，可以是一个可执行文件，也可以是一个中间文件。
- `dependencies`：依赖文件，如果依赖文件的时间戳比目标文件的时间戳要新，那么`command`将会被执行。
- `command`：生成目标文件的指令。（这里并不限制command的内容，可以是任何shell命令）

#### 示例
```makefile
hello: hello.o
    gcc -o hello hello.o
hello.o: hello.c
    gcc -c hello.c
```

#### 伪目标

有时候我们需要定义一些不产生文件的目标，这种目标称为伪目标。伪目标的特点是，它总是被执行，不管依赖文件是否存在。

```makefile
# make不会将clean视为一个文件
.PHONY: clean
clean:
    rm -f hello hello.o
```

#### 多条命令

```makefile
cd_ok:
    pwd; cd ..; pwd;
# 分号用于分隔命令，这里的命令会依次执行，上一条命令的执行结果会影响下一条命令的执行结果

```
也可以写成

```makefile
cd_ok:
    pwd; \
    cd ..; \
    pwd
```

另一个例子

```makefile
cd_ok:
    pwd
    cd ..
    pwd
# 这里的命令会依次执行，上一条命令的执行结果不会影响下一条命令的执行结果
```

#### 控制打印

```makefile
# @符号用于控制make是否打印命令
@echo "hello world"
# 只会输出hello world，不会输出echo "hello world"
```

### 多文件编译C

```c
// hello.c
#include <stdio.h>

int hello()
{
    printf("hello, world!\n");
    return 0;
}
```
```c
// hello.h
int hello();
```
```c
// main.c
#include <stdio.h>
#include "hello.h"

int main()
{
    printf("start...\n");
    hello();
    printf("exit.\n");
    return 0;
}
```

编译`hello.c`,`hello.h`,`main.c`为 `world.out`
```makefile
# 生成可执行文件:
world.out: hello.o main.o
	cc -o world.out hello.o main.o

# 编译 hello.c:
hello.o: hello.c
	cc -c hello.c

# 编译 main.c:
main.o: main.c hello.h
	cc -c main.c

clean:
	rm -f *.o world.out
```

### 变量

```makefile
# 定义变量
CC = cc
CFLAGS = -Wall -g

# 使用变量
hello: hello.o
    $(CC) -o hello hello.o

hello.o: hello.c
    $(CC) -c hello.c $(CFLAGS)
```

#### 自动变量

- `$@`：表示规则中的目标文件名
- `$<`：表示规则中的第一个依赖文件名
- `$^`：表示规则中的所有依赖文件名

```makefile
hello: hello.o
    $(CC) -o $@ $^
hello.o: hello.c
    $(CC) -c $< $(CFLAGS)
```

#### 模板

```makefile
SRC_DIR = ./src
BUILD_DIR = ./build
TARGET = $(BUILD_DIR)/world.out

CC = cc
CFLAGS = -Wall

# ./src/*.c
SRCS = $(shell find $(SRC_DIR) -name '*.c')
# ./src/*.c => ./build/*.o
OBJS = $(patsubst $(SRC_DIR)/%.c,$(BUILD_DIR)/%.o,$(SRCS))
# ./src/*.c => ./build/*.d
DEPS = $(patsubst $(SRC_DIR)/%.c,$(BUILD_DIR)/%.d,$(SRCS))

# 默认目标:
all: $(TARGET)

# build/xyz.d 的规则由 src/xyz.c 生成:
$(BUILD_DIR)/%.d: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@); \
	rm -f $@; \
	$(CC) -MM $< >$@.tmp; \
	sed 's,\($*\)\.o[ :]*,$(BUILD_DIR)/\1.o $@ : ,g' < $@.tmp > $@; \
	rm -f $@.tmp

# build/xyz.o 的规则由 src/xyz.c 生成:
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c -o $@ $<

# 链接:
$(TARGET): $(OBJS)
	@echo "buiding $@..."
	@mkdir -p $(dir $@)
	$(CC) -o $(TARGET) $(OBJS)

# 清理 build 目录:
clean:
	@echo "clean..."
	rm -rf $(BUILD_DIR)

# 引入所有 .d 文件:
-include $(DEPS)
```

# Cmake

CMake是一个跨平台的编译(Build)工具,可以用简单的语句来描述所有平台的编译过程。

CMake能够输出各种各样的makefile或者project文件，能测试编译器所支持的C++特性,类似UNIX下的automake。

> 自行下载查找安装了解
