# 如何使用 shell
本文将介绍关于如何使用 shell 以及对应相关的一堆工具链, 完成本文的阅读与学习,
你将学会:
+ 基本的 shell 使用以及快捷键
+ 简单的工具链的编译与构建
+ 简单的 Linux 的一些规范与约定
+ ...

## 行文风格与符号注记
+ 正文中使用折叠的 `<details>` 来隐藏拓展和说明内容:
  + 拓展: 表示这部分折叠的内容属于可选项, 对于熟手来说算是有用的材料, 可选
  + 说明: 表示这部分折叠内容, 对于新手来说是很好的补充材料, 建议阅读
  + 选择: 表示这部分折叠内容将会根据你的当前情况来进行展开
  + 历史: 表示这部分折叠内容是历史小知识, 可以选读
+ 文中的按键描述风格如下:
  + `C-f` (按住 `Control` 键的​**同时**​按下 `f` 键)

    其他的修饰键有:
    + `M` Meta 键:
      + 在 Windows 键盘上, 是 `Alt` 键;
      + 在 macOS 键盘上, 是 `Option` 键;
    + `S` Super 键:
      + 在 Windows 键盘上, 是绘制有微软 `田` 字图标的键;
      + 在 macOS 键盘上, 是 `Command` 键;

    <details>
    <summary>拓展: 为什么用这套键盘修饰语? </summary>
    <div markdown="1">
    在一些旧电脑 (比如 Lisp Machine) 键盘上, 确实存在一一对应的 [Meta 键](https://en.wikipedia.org/wiki/Meta_key),
    以及 [Super 键](https://en.wikipedia.org/wiki/Super_key_(keyboard_button)). 这些设计语言被 [GNU](https://en.wikipedia.org/wiki/GNU) 软件集所继承了下来,
    成为了早期 (甚至到了现在) 在 Linux 中所包含的一批功能性的软件.

    由于这套规范影响深远, 所以大部分程序都会对其有一定的借鉴.
    比如 macOS 的系统默认快捷键就是如是设计.

    (当然, 也有可能是直接调库 [GNU readline](https://tiswww.case.edu/php/chet/readline/rltop.html) 导致的)

    不管怎么说, 在这里我们将会使用这套语言.
    </div>
    </details>
  + `C-k C-y` (按下 `C-k` **后**, 按下 `C-y`)
  + `Ret` 表示回车键
  + `dash` 表示 `-` 键 (主键盘上方数字键那一排靠近 `0` 的那个)

## 基本的 shell 使用以及快捷键
+ 打开你的终端 (Terminal, Shell, Console, XTerm 不论你的系统如何称呼它们),
  此时你应当看见一个 "字符界面" (TUI, **T**​ext-based **U**​ser **I**​nterface),
  类似如下:

  ```text
  user@host:~$ |
  ```

  <details>
  <summary>说明: 如何阅读上面的 prompt</summary>
  <div markdown="1">

  其中 `|` 为你的 [光标](https://en.wikipedia.org/wiki/Cursor_(user_interface)) (cursor) 所在的位置.

  其中 `user@host:~$` 这部分我们称为 prompt, 一般的, prompt 中会显示许多有用的信息,
  比如告诉我们当前操作 shell 的用户名称为 `user`, 操作的这台机器的名称为 `hostname`,
  当前所在的文件夹 (目录, current working directory) 为 `~`.

  当然, 你也可以选择 [自定义](https://www.gnu.org/software/bash/manual/bash.html#Controlling-the-Prompt) prompt 的显示内容 ([Bash Generator](https://bash-prompt-generator.org)).

  </div>
  </details>
+ 你可以尝试输入一些字符, 使用你的方向键 (←↑↓→) 来移动光标并编辑输入的内容,
  并在当前行输入完成后按下 `Ret` (回车) 来确认输入.

  <details>
  <summary>拓展: Bash 默认的操作快捷键</summary>
  <div markdown="1">

  如果你恰好使用过 Emacs, Bash 的默认操作模式叫作 [emacs-mode](https://www.gnu.org/software/bash/manual/bash.html#Command-Line-Editing), 你可以使用类似
  Emacs 中的编辑快捷键来对 Bash 中的输入进行编辑, 比如:
  + `C-f` 向前 (右) 移动一个​**字符** (**f**​orward);
  + `C-b` 向后 (左) 移动一个​**字符** (**b**​ackward);
  + `M-f` 向前 (右) 移动一个​**单词** (**f**​orward word);
  + `M-b` 向后 (左) 移动一个​**单词** (**b**​ackward word);
  + `C-n` 下一行 (**n**​ext line);
  + `C-p` 上一行 (**p**​revious line);
  + `C-o` 换行 (**o**​pen new line);
  + `C-k` 删除在当前行光标后的所有内容 (**k**​ill);
  + `C-w` 删除前一个​**单词** (**w**​ord);
  + [more](https://www.gnu.org/software/bash/manual/bash.html#Command-Line-Editing)

  </div>
  </details>
+ 接下来, 我们假设你所用的 shell 为 [BASH](https://www.gnu.org/software/bash/), 你可以通过输入 `echo $SHELL` 来判断:

  ```shell
  > echo $SHELL # Ret
  /bin/bash
  ```

  根据你的输出结果:

  <details>
  <summary markdown=1>
  选择: `bash: xxx: command not found`
  </summary>
  <div markdown="1">
  请仔细看看你的 `xxx` 部分是否输入正确, 真的是 `echo` 吗?
  若是, 则你的 Linux 可能有些不太对劲. 请检查 `PATH` 是否正确,
  发行版是否损坏, 等.
  </div>
  </details>

  <details>
  <summary>选择: 输出为空</summary>
  <div markdown="1">
  请检查你的 `$SHELL` 是否输入正确, 真的是 `%SHELL` 吗?
  若是, 则说明这个环境变量为空.
  </div>
  </details>

  <details>
  <summary markdown=1>
  选择: 输出差不多, 但是最后显示的是类似于 `zsh`, `fish` 这样的东西
  </summary>
  <div markdown="1">
  这倒不是什么大问题, 这说明你的默认 shell 是 [ZSH](https://en.wikipedia.org/wiki/Z_shell), [Fish](https://en.wikipedia.org/wiki/Fish_(Unix_shell)) 这样的 shell.
  你可以通过输入 `bash` 命令来切换到 BASH.
  </div>
  </details>

  <details>
  <summary>说明: 上面的代码干了什么? </summary>
  <div markdown="1">
  + `echo` 这个命令将会原封不动地输出后面跟着的所有的参数.
  + `$SHELL` 可以看作是两个部分 `$` 前缀以及 `SHELL` 环境变量 (env) 名称,
    将会用 `SHELL` 这个变量替换 `$SHELL` 作为输入

  没事, 到了这里还是不懂也没有关系, 你可以先看看后文.
  </div>
  </details>
+ 好了, 到了这里, 我们假设你已经学会了如何编辑输入了,
  并且你输入到的 shell 也确乎是 bash. 在这之后, 当我们提到输入 xxx  命令,
  比如输入 `ls` 命令时, 我们会默认你输入了 `ls` 命令并按下了回车确认了输入.

  + 练习: 输入命令 `ls` (**l**​i​**s**​t), 列出当前目录下的所有文件.
  + 练习: 输入命令 `pwd` (**p**​rint current **w**​orking **d**​irectory),
    打印输出当前所在的文件夹的绝对路径.

    <details>
    <summary>说明: 绝对路径 (absolute path) 和相对路径 (relative path)</summary>
    <div markdown="1">
    虽然这两个东西算是少有的光看名字就非常直观的, 我们先从相对路径开始:
    + 假设当前文件夹中有文件夹 `a`, `b`, `c`:

      ```shell
      > ls
      a b c
      ```

      在 `a` 中的文件 `a1`, 在当前文件夹看来, 就是 `a/a1`, 即 `a/a1` 就是一个相对路径;
    + 那么如果我们现在切换到了 `a` 文件夹下, 该如何找到 `b` 文件夹中的文件 `b1` 呢?

      ```shell
      cd a # 进入到文件夹 a 中
      ```

      答案是 `../a/a1`:

      ```shell
      file ../a/a1 # 检查文件 ../a/a1 的类型
      ```

      其中 `..` 表示上级目录, 而 `.` 表示当前目录.

      <details>
      <summary>历史: 隐藏文件的命名</summary>
      <div markdown=1>
      由于 `..` 和 `.` 的命名特殊性, 历史上 `ls` 命令默认会不显示这两个文件.
      而做到这一点的方式非常的粗暴: 凡是以 `.` 开头的文件都不会显示.

      Read more:
      + [file_ignored | ls.c](https://github.com/coreutils/coreutils/blob/5cecd703e57b2e1301767d82cbe5bb01cae88472/src/ls.c#L3183)
      + [Linux History: How Dot Files Became Hidden Files](https://linux-audit.com/linux-history-how-dot-files-became-hidden-files/)
      </div>
      </details>
    + 相信现在你应该大概了解相对路径了吧... 如果仍然不太了解, 下面是一个例子:

      ```shell
      > tree . # 以树状图显示当前目录下的文件结构
      .
      ├── a
      │   ├── a1
      │   │   ├── a11
      │   │   ├── a12
      │   │   └── a13
      │   ├── a2
      │   │   ├── a21
      │   │   ├── a22
      │   │   └── a23
      │   └── a3
      │       ├── a31
      │       ├── a32
      │       └── a33
      ├── b
      │   ├── b1
      │   │   ├── b11
      │   │   └── b12
      │   └── b2
      │       ├── b21
      │       └── b22
      └── test.txt
      ```

      请任意选择两个文件并指出他们之间相互的相对路径, 如:
      `a11` 相对 `b22` 的相对路径: `../../b/b22`.

    那么绝对路径就比较好理解了: 相对根目录 `/` 的相对路径就是绝对路径了.
    比如根目录下的 `/home/user`, 也就是我们的用户目录 `~`.
    </div>
    </details>
+ 参数: 回过头去看我们之前输入的 "命令", 比如以下面的为例:

  ```shell
  ls -a # 列出当前目录下所有的文件
  ```

  若将各个部分用空格分离:
  + `ls`: 即命令的执行程序本体.

    <details>
    <summary>说明: 为什么说是 "本体" (关于 executable 的寻找逻辑: PATH)</summary>
    <div markdown="1">
    你可以用 `which ls` 来找到 `ls` 程序的绝对路径.

    那么为什么 Shell 就知道 `ls` 具体在哪里呢?
    是因为 `ls` 之类的程序是 Shell 的保留关键字吗?

    并不是, Shell 通过环境变量 PATH 中指定的路径去查找当前输入的执行程序的具体所在位置,
    比如我们可以编写一个简单的程序 `hello_world.c`:

    ```shell
    > gcc -o hello_world hello_world && pwd
    /any/path/is/okay
    ```

    然后将 `hello_world` 所在的文件夹添加到 `PATH` 中:

    ```shell
    > export PATH="/any/path/is/okay:$PATH"
    ```

    注: `PATH` 中使用 `:` 分隔路径.

    这样在 Shell 中就可以用 `hello_world` 来直接调用我们编译好的程序了.

    那么对于不在 PATH 中的可执行程序, SHELL 又是如何寻找的呢?

    答案是通过相对路径 `./hello_world` 或是绝对路径 `/any/path/is/okay/hello_world`
    来进行查找.
    </div>
    </details>
  + `-a`: 即命令的参数.

    通常来说, 我们可以给一个命令输入一组参数, 比如:

    ```shell
    > ls -a -l -h
    ```

    这一组参数实际上会以一个数组 (列表) 的形式 (以空格为) 分隔传给程序.
  + `# ...` 注释, 在 `#` 后的会被 BASH 忽略

  <details>
  <summary markdown=1>拓展: 在 `main` 函数中的参数处理</summary>
  <div markdown=1>
  用一个 `main` 函数来理解估计会非常方便:

  ```c
  #include "stdio.h"

  int main(int argc, char** argv) {
    // argc: count of args + 1
    // argv: values of arg (as a array),
    //       the first *(argv) is the executable file itself

    printf("You've passed in %d arguments to executable file:\n", argc - 1);
    prinft("    %s\n", *argv);
    printf("They are:\n");

    for (int i = 1; i < argc; i++)
      printf("+ `%s'\n", *(argv + i));

    return 0;
  }
  ```

  编译并测试:

  ```shell
  > gcc -o main main.c && ./main "Hello World" "This is Second" This is Not Third
  You've passed in 6 arguments to executable file:
      /any/path/to/main
  They are:
  + `Hello World'
  + `This is Second'
  + `This'
  + `is'
  + `Not'
  + `Third'
  ```

  显然, 你可以通过编写一个 argparser 的函数来处理输入的参数, 然后根据参数,
  输出你应当输出的结果.

  </div>
  </details>
+ 输入与输出

  <details>
  <summary>说明: 输入与输出在 C 语言中</summary>
  <div markdown="1">
  这些输入与输出其实对应的就是 C 语言中我们的 `stdin` (standard input) 与
  `stdout`(standard output). 这也是为什么我们在编写 `read` 类型的函数的时候,
  会用 `EOF` (**E**​nd **O**​f **F**​ile) 来作为输入的终止.
  </div>
  </details>
  + pipline `|`: 将前一个命令的结果作为下一条命令的输入

    ```shell
    ls -a | grep "main.c" # grep 用于筛选所有包含 `main.c' 的行
    ```
  + 输入与输出的重定向 `<`, `>`
+ Shell as Script
  + 变量 `export VAR="..."`
  + 变量的嵌入 `$VAR`
  + 控制流 `&&`, `;`, `||`, ...
  + shebang

## 简单的工具链的编译与构建
在这一节, 将会有两个例子:
1. 编译一个 C 的项目;
2. 自己组织一个 C 的项目并编译

### 编译一个 C 的项目 Make, Cmake, AutoConf, ...
<details>
<summary>说明: 为什么我们在谈及 "项目" 的时候需要谈到编译工具链? </summary>
<div markdown="1">

当我们的工具的代码量并不大的情况下, 比如只有一个 `main` 函数的简单计算器,
谈及编译的时候往往是一个简单的 `CC` 命令即可完成的事情:

```shell
gcc -o calculator calculator.c
```

但是真实情况下, 譬如我们引用或调包了一个库, 比方说 [webview](https://github.com/webview/webview),
在编译的时候, 我们就需要将这个调用的库引用过来:

```shell
gcc -o webview_calculator webview_calculator.c -framework WebKit -ldl -...
```

注: 这里只是一个示意, 实际上有一大堆 link 和 compile 的参数.

那么, 为什么会这么复杂?

可以从一个更加简单的例子来看, 假设我们有一个不同系统下不同表现的函数:

```c
// simple.c
#include "stdio.h"

int main() {

#ifdef __MAC_OS_X__
  printf("This is compiled for macOS\n");
#endif

#ifdef __LINUX__
  printf("This is comipled for Linux\n");
#endif

}
```

我们在编译的时候可以使用 `-D<macro_name>(=macro_value)` 的形式来定义宏,
于是对于上面的代码, 我们可以为 `macOS` 编译:

```shell
> gcc -o simple simple.c -D__MAC_OS_X__ && ./simple
This is compiled for macOS
```

当然, 实际上并不是使用 `__MAC_OS_X__` 这样的标记手动指定编译的系统,
而是通过 [Pre-defined Compiler Macros](https://sourceforge.net/p/predef/wiki/OperatingSystems/) 中说明的宏进行自动检测.

我们完全可以替换上文中的代码 `__MAC_OS_X__` 中的 `printf`,
变成在另一个文件中定义的一个函数, 比如 `attack_mac_os.c` 中的 `attack_mac_os`,
对于 `__LINUX__` 也同样可以有 `attack_linux.c` 中的 `attack_linux` 函数.
这样我们可以选择对于不同的编译对象, 只编译部分对应的代码, 从而使得我们的程序即小巧,
又具有可移植性.

那么如何实现这一操作呢?

假设我们的 `attack_mac_os.c` 文件如下:

```c
// attack_mac_os.c
#include "stdio.h"

void attack_mac_os() {
  printf("Haha, your macOS is being cracked. \n");
}
```

而主函数文件如下:

```c
// main.c

#ifdef __APPLE__
void attack_mac_os();
#endif

int main() {
#ifdef __APPLE__
  attack_mac_os();
#endif
}
```

因为 `gcc` 一次编译一个文件, 所以我们需要先编译 `attack_mac_os` (等其他文件),
即在编译完 `main.c` 的所有依赖后, 再编译 `main.c` 文件:

```shell
> gcc -o attack_mac_os.o attack_mac_os.c -c
> gcc -o simple main.c attack_mac_os.o
> ./simple
Haha, your macOS is being cracked.
```

在这中间发生了什么? (简单但是并不准确的解释)
+ 在 `main.c` 中, 我们定义了一个 `void attack_mac_os()`,
  这是为了告诉编译器, 有一个不接受输入参数, 也不返回参数的函数,
  名字叫作 `attack_mac_os`.
+ 尽管编译器可能并不知道这个函数的具体定义是什么, 但是它确实会保留这个符号.
+ 在第一个 `gcc` 编译的时候, 我们编译了具体定义 `attack_mac_os` 这个函数的文件,
  但是通过添加一个 `-c` 的参数, 使得编译器在 **c**​ompilation 阶段就停止;
+ 在第二个 `gcc` 编译的时候, 我们将所有的结果都合并 (link) 在一起,
  那个被保留的符号 `attack_mac_os` 在这个时候也会找到自己的定义.

那么对于一个较大的项目, 我们想要编译一个结果, 肯定不会像这样手动去解决各种编译顺序和依赖,
最简单的方式就是写一个 Shell 脚本, 描述编译的全过程并进行自动化处理;
但是缺点就是 Shell 脚本可维护性较差, 所以渐渐地会有人想出如何替代,
或者如何有更好的自动化管理工具, 于是就有了 Make, CMake 之类的东西.

</div>
</details>

#### `autogen.sh`, `configure`: 以 mg 为例
1. 获得源码:

   ```shell
   git clone https://github.com/troglobit/mg.git && cd mg
   ```
2. 阅读安装手册:

   ```shell
   less README.md
   ```

   按照 `README.md` 编译. 请尝试修改不同的 `./configure` 参数,
   看看效果如何?

   请注意 `--prefix` 会将文件 "安装" (移动) 到哪里? 如果你不是 root 用户,
   该将文件移动到哪里?

   如何将安装的文件清除掉? (`make uninstall`)

**练习**: 尝试编译其他的一些项目, 可以选择的有 [neovim](https://github.com/neovim/neovim), [emacs](https://github.com/emacs-mirror/emacs)...

(注: 虽然我很想添加 [vscode](https://github.com/microsoft/vscode), 但是鉴于其并非完全开源,
你从微软官方下载的编译后的内容实际和你用源码编译出来的东西并不相同,
所以没有必要去尝试. )

#### CMake
这里并不详细介绍, 只是简单提一嘴.

你可以把 CMake 看作是 autoconf 流一样的 Makefile 生成器,
但是 CMake 的语法更加 "简洁" 一些. 其功能就是根据 CMake 的规定,
会展开成一个 Makefile (`cmake -B build` 会进行一个配置).

在配置完后, 你完全可以使用 `make` 那一套流程进行编译/安装等等.

### 自己组织一个 C 的项目并编译 Make

## 简单的 Linux 规范与约定
