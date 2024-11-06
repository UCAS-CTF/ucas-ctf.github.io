# Basic Python Introduction
你将会学会:
+ Python 的安装​~~与卸载~~
+ Python 基本语法与基本数据结构
  + 赋值 (binding) `=`, ...
  + 控制流 `if`, `for`, `break`, `continue`, ...
  + 函数 `def`, `return`
  + 列表 `list`, 元组 `tuple`, 哈希 (字典) `hash`
+ 如何编写 Python 的模块
+ Advanced:
  + 一些 Meta Programming: 修饰器
  + Function Programming: Lambda 算子
  + OOP

## Python 基本语法与数据结构
### Python in 20 minutes
(本文改编自 [Ruby in Twenty Minutes](https://www.ruby-lang.org/en/documentation/quickstart/), 但是做了极大程度的精简 ~~懒得写导致的~~)

#### REPL (Read Eval Print Loop)
打开一个 Python REPL (可以使用在线的 [pythonanywhere](https://www.pythonanywhere.com)):

1. 在终端中输入 `python` 并回车

你会看到类似如下的提示:

```python
Python 3.12.4 | packaged by Anaconda, Inc. | (main, Jun 18 2024, 10:07:17) [Clang 14.0.6 ] on darwin
Type "help", "copyright", "credits" or "license" for more information.
>>>
```

尝试输入 `"Hello World"` 并回车:

```python
>>> "Hello World"
'Hello World'
```

那么发生了什么? Python REPL 读取了我们输入的命令表达式,
然后将最后的表达式的结果的值以打印输出的形式返回给我们.
那么这是一个最简单的打印 Hello World 的程序么? 不全是,
想要打印 (print) 出 `"Hello World"`, 还需要:

```python
>>> print("Hello World")
Hello World
```

`print` 是一个 Python 中的基本函数, 用于在标准输出中打印字符串.

同时也不难发现, 在 Python 中的函数调用即为 `<函数名称>(函数参数)`

<details>
<summary>那么 print 的返回值? </summary>
<div markdown="1">
其实返回值是 `None`.
</div>
</details>

#### 简单的计算器
你可以把 Python REPL 当作是一个很好用的计算器:

```python
>>> 3 + 2  # 加法 (没错, 用 `#` 开头的表示注释)
5
>>> 3 * 2  # 乘法
6
>>> 3^2    # XOR 位运算
1
>>> 3**2   # 乘幂
9
```

总之加减乘除不在话下, 那么开方呢?

```python
>>> import math
>>> math.sqrt(4)
2.0
```

这里发生的事情如下:
1. 我们载入了一个叫作 `math` 的外部库
2. 我们使用了在 `math` 外部库中的一个函数 `sqrt`, 即开根号的函数.

<details>
<summary>简单的介绍</summary>
<div markdown="1">
模块化除了可以引用已经编好的程序库, 还有一个好处, 就是可以用来防止同名符号冲突.
</div>
</details>

#### 函数
假如说你想要重复调用某一段代码, 但是又不想反复输入? 请使用函数:

```python
>>> def hi():
...     print("Hello World! ")
...
>>> hi
<function hi at 0x1037c65c0>
>>> hi()
Hello World!
```

上面的 `def hi():` 定义了函数名称和其输入的参数表 (这里是空的, 表示不需要输入参数).
并且需要注意的是, 在 Python 中的代码块是需要用 4 空格缩进标记层级的.

<details>
<summary>这里可以用 C 语言的代码块 {} 来进行一个类比</summary>
<div markdown="1">

你可以把上面的代码块类比为:

```c
void hi ()
{
  print("Hello World! ");
}
```

</div>
</details>

在 Python 中, 函数的符号名称和变量的符号名称是等价的, 所以当我们去引用符号
`hi` 的值的时候, 返回的值是一个 `function` 对象.

而 `hi()`, 也就是函数调用的形式时, 则会进行一个函数的调用.
那么如何添加函数参数呢?

```python
>>> def hi(name):
...     print(f"Hello {name}")
...
>>> hi("Ryo")
Hello Ryo
```

其中 `f"{}"` 是一种字符串格式化的特殊语法糖, 类似于:

```python
"Hello " + str(name)
```

(没错, 在 Python 中, 字符串是可以直接相加的, 这相当于将两个字符串进行拼接).

并且你还可以给一个函数提供默认的缺省值:

```python
>>> def hi(name = "World"):
...     print(f"Hello {upcase(name)}")
...
>>> hi()
Hello World
>>> hi("Blues")
Hello Blues
```

#### OOP
如果我们想要实现一个更加复杂的打招呼的 Greeter 模型, 我们可以借助 OOP
(面向对象编程) 的思路来进行构建我们的代码:

```python
>>> class Greeter:
...     def __init__(self, name = "World"):
...         self.name = name
...     def say_hi(self):
...         print(f"Hello {self.name}")
...     def say_bye(self):
...         print(f"Bye {self.name}")
...
>>> greeter = Greeter("Ryo")
>>> greeter.say_hi()
Hello Ryo
>>> greeter.say_bye()
Bye Ryo
```

<details>
<summary>用两种角度来看 OOP</summary>
<div markdown="1">

我们可以用 C 的 Struct 的方式来看一个对象:

```c
typedef struct greeter {
  char* name;
  void (*say_hi)  (struct greeter *self);
  void (*say_bye) (struct greeter *self);
} Greeter;

void greeter_say_hi(Greeter *self)
{
  printf("Hello %s\n", self->name);
}

void greeter_say_bye(Greeter *self)
{
  printf("Bye %s\n", self->name);
}

Greeter *make_greeter_instance(char* name)
{
  Greeter *greeter = malloc(sizeof(Greeter));
  greeter->name    = name;
  greeter->say_hi  = greeter_say_hi;
  greeter->say_bye = greeter_say_bye;
  return greeter;
}

int main (int argc, char** argv)
{
  if (argc != 2) {
    printf("Usage: ./main <name>\n");
    return 0;
  }

  Greeter *greeter = make_greeter_instance(argv[1]);
  greeter->say_hi(greeter);
  greeter->say_bye(greeter);
}
```

简单来说就是把实例看作是一个带有所有实例变量以及指向实例方法的数据结构.

但是是否有另外的视角呢? 我们不妨来看下面这样的代码:

```python
def make_greeter():
    name = "World"
    def greeter(method):
        nonlocal name
        if method == "hi":
            print(f"Hello {name}")
        elif method == "bye":
            print(f"Bye {name}")
        else:
            print(f"No method {method} for {greeter}")
    return greeter
```

在这里我们用 `nonlocal` 构建了一个关于函数的闭包,
即我们可以把对象实例看作是一个具有闭包数据结构的函数.

</div>
</details>

Note: 不过我们在这里并不会详细介绍 OOP 的内容, 大家这里只需要知道,
在 Python 中, 你既可以用 `len(obj)` 这样的方法, 也可以用 `obj.size`
这样的形式来调用函数中的一些方法即可. (评价就是有些混乱, 不如 Ruby 的优雅).

#### 脚本小子
那么让我们退出 REPL, 来写一些脚本吧.

在 Python REPL 中输入 `exit()` 来退出. 用你的编辑器打开并编辑一个 `greet.py` 文件:

```python
# TODO in CLASS:
# + how to support multiple names?
class Greeter:
    def __init__(self, name = "World"):
        self.name = name
    def say_hi(self):
        print(f"Hello {self.name}")
    def say_bye(self):
        print(f"Bye {self.name}")

if __name__ == "__main__":
    greeter = Greeter()
    greeter.say_hi()
    greeter.say_bye()
```

保存并使用 `python greet.py` 来运行这个代码.

这里不难注意到, 我们用了一个 `if __name__ == "__main__"`,
这段的作用是让这部分代码只在 `greet.py` 作为主函数入口运行的时候被执行,
这有点类似于 C 中的 `main`, 但是略有不同.

那么如果我们想要支持多个名字该如何?

### Python 的数据结构
我的观点是, 既然 Python 是一种胶水语言, 我们其实只需要了解如何用这胶来粘东西就好了,
至于非常细节的底层, 如果效果不好, 那么我们只需要调库调包来解决, 实在不行就祭出 CFFI
回到 C, 或者是找几个大佬帮我们解决.

所以这里我们只会非常快速地略过数据结构.

#### 列表 (list)
```python
>>> lst = ["a", 1, ["a", "asd"]]       # literal expression
>>> lst[0]                             # read
'a'
>>> lst[3]
Traceback (most recent call last):
  File "<stdin>", line 1, in <module>
IndexError: list index out of range
>>> lst[0] = "b"                       # write
>>> lst[0]
'b'
>>> lst[2]
['a', 'asd']
>>> lst[2][1]                          # nested list
'asd'
```

#### 元组 Tuple
可以看作是不可变的列表, 操作类似 List

```python
>>> tup = ("Hello", 1, 2)
```

#### 字典 (dict)
```python
>>> hash = { 'key1': 2, 'key2': 3 }
>>> hash.keys
<built-in method keys of dict object at 0x1037cdc80>
>>> hash.keys()
dict_keys(['key1', 'key2'])
>>> hash.values()
dict_values([2, 3])
```

#### 字符串
操作类似 list

## Python 模块

## Advanced

## Python 环境配置
### 如果你以后永远不会用到 Python / 只是临时使用 Python
用 `Online Python` 关键词去搜索一些在线的 Python 环境,
对于简单的代码来说是足够用了.

Python [官网](https://www.python.org)​的方案是: [pythonanywhere](https://www.pythonanywhere.com).

Note 1: 对于 Windows 用户, 可以考虑使用简单的 [Python 安装包](https://www.python.org/downloads/windows/) 来解决问题.

Note 2: 对于 Unix-like 用户, 不建议使用包管理器中的 Python.

<details>
<summary>理由</summary>
<div markdown="1">
因为各个版本的 Python 以及其各个版本的包往往被不同的软件所依赖,
随便更改主环境 (包管理器) 的 Python 往往会让你陷入恨不得把 Python
给删掉的冲动.
</div>
</details>

### PyCharm
简单使用, PyCharm Community 就够了:

1. 访问 PyCharm [官网](https://www.jetbrains.com/pycharm/)
2. 点击 `Download` 按钮
3. 在下载界面拉到最下方选择 PyCharm Community Edition

Note: 你也可以选择慈禧甄选 Profession 版本.

### 如果你不喜欢 IDE
鉴于大家可能对计算机并没有那么多狂热的爱好, 这节的内容仅适合那些比较闲的同学[^2].

首先建议使用 [conda](https://docs.conda.io/projects/conda/en/latest/user-guide/getting-started.html) 作为 Python 的版本/包管理器. (尤其是 Unix-like 用户)

这里建议安装 [miniconda](https://docs.anaconda.com/miniconda/) (下载链接及安装方法见链接).

[^2]: 当然, 使用 VSCode 的同学可能没有那么闲.

#### VSCode
打开你的插件管理器, 搜索 Python, 然后把巨硬的几个推荐插件安装一下就好了.

Note: 不了解的请上课提问/参考 [Python in Visual Studio Code](https://code.visualstudio.com/docs/languages/python).

#### 如果你不想用 VSCode
你需要的是一个叫作 LSP (Language Server Protocol) 的东西, 用于提供语法检查,
自动补全. 常见的编辑器中已经包含有类似的插件了. (当然, 旧的代替也有, 可以尝试)

如果还有 treesitter 支持的话体验会更好.

Note: 愿意到这一步的同学估计都能看懂/有能力看懂我在说什么, 如果看不懂,
建议使用 VSCode 或者 PyCharm. 这里并不建议大家把太多的时间花在配置编辑器上.

Note 2: 如果真的比较闲, 想要试试其他口味的编辑器, 这里推荐 Emacs
(一些可能有用的参考链接: [配置你的Emacs](https://ucaskernel.com/d/830-emacs/), [Emacs 和 Org-Mode... 吃我安利](https://ucaskernel.com/d/675-emacs-org-mode/))
