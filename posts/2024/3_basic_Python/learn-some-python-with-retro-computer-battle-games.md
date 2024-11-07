# Learn Some Python with Retro Computer Battle Games
## About
我们将会用一些简单的远古电脑小游戏作为 Python 入门的练习.
这些小游戏来自 Computer Battle Games (For ZX Spectrum,
ZX81, TRS-80, APPLE, VIC & PET), 是一本由 [Usborne](https://usborne.com/) 出版社,
出版于 1982 年的适用于儿童的计算机普及读物.

你可以在 [Intenet Archive](https://archive.org/details/computer-battlegames) 网站上游览或者下载它,
或者你也可以在 [Usborne 的存档网站](https://usborne.com/row/books/computer-and-coding-books)​上找到同一系列的书籍.
不过本部分并不会完全按照原书的内容进行介绍 (毕竟原书是
BASIC 语言, 而非 Python). 不过你可以将其作为课外消遣读物,
不过毕竟是儿童计算机读物, 对小学生来说可能有些幼稚,
但是对大学生来说估计刚刚好.

### Pre-requirements
你应该对 Python 有稍微的了解,
这里推荐阅读 [这篇文章中的 Pythonin 20 min](./trivial-python-introduction.md) 一节,
小小花个 20 分钟入个门.

### Typo
为了方便, 对于原文中比较中二的背景设定我直接使用的是 OCR 识别,
所以如果有 typo, 请提交 issue 来修改.

### TOC
+ [Robot Missile](#robot-missile)
+ [The Vital Message](the-vital-message)
+ [Shootout](shootout)
+ [Iceberg](iceberg)

## Robot Missile
> The year is 2582 and the people of Earth are in the midst of battle
> against the Robots. A lethal Robot Missile has just landed and
> everyone is depending on you to find the secret code which unlocks
> its defuse mechanism. If you fail, the entire Earth Command
> Headquarters will be blown up.
>
> Your computer knows what the code letter is. You must type in your
> guess and it will tell you whether the code letter is earlier or
> later in the alphabet.
>
> You have four chances to find the correct letter before the missile
> blows up.

请参考 [robot-missile.py](./src/computer-battle-game/robot-missile.py).

<details>
<summary>简单写一个小游戏外挂</summary>
<div markdown="1">

我们发现这个小游戏完全可以用​[二分法](https://zh.wikipedia.org/zh-cn/二分法_(數學)) 来解决,
因为 `math.log(26) = 3.25 < 4`.

那么我们完全可以写一个简单的二分搜索小外挂:

```python
def guess_number():
    # 这里用到了一个多赋值
    left, right = 'A', 'Z'

    # 这里 // 是整除
    guess = chr((ord(left) + ord(right)) // 2)

    while True:
        if success_p(guess):
            return guess
        elif later_p(guess):
            left, right = guess, right
            guess = chr((ord(left) + ord(right)) // 2)
        else:
            left, right = left, right
            guess = chr((ord(left) + ord(right)) // 2)

        if left == right:
            return None
```

我们在课上将会介绍如何编写 `success_p` 以及 `later_p` 的函数,
来和外部的程序进行 IO 交互并且自动化输入命令. (这是一个查文档的例子)

</div>
</details>

## The Vital Message
> You are a laser communications operator. Your job is to intercept
> robot messages and relay them to Command HQ. A vital code message
> is expected. If you relay it correctly, the Robot attack will be
> crushed.
>
> This game tests your skill at remembering a group of letters which
> you see for only a very short time. The computer will ask you for a
> difficulty from 4 to 10. When you have typed in your answer, letters
> will appear top left of your screen and disappear again fairly quickly.
> Memorize them and then type them into the computer and see if you
> were right.

请参考 [vital-message.py](./src/computer-battle-game/vital-message.py).

<details>
<summary>一些说明</summary>
<div markdown="1">

这个游戏其实原理非常简单, 所以我们并不会对这个游戏的逻辑进行解释.
在这里我们将会换一些考查视角: 如果用户不按照我们想要的方式输入,
那么会发送什么? 如果用户的设备不是 Unix-like, 那么代码会发生什么?

即, 如何处理用户输入以及如何处理多端移植.

</div>
</details>

## Shootout
> You are standing back to back. You take 10 paces, turn and reach
> for your gun. How quick are you? Can you shoot first?
>
> Your computer prints the numbers 1 to 10 to represent the 10 paces,
> pauses and then prints HE DRAWS...
>
> You must be ready to press a key (any one will do) the instant these
> words come of the screen. If you are quick enough, you will win. Don't
> press a key before HE DRAWS comes up or you automatically lose.

(coming soon... or we could write it on class)

## Desert Tank Battle
> The last major stronghold of Robot forces outside the U.R.S*
> is hidden in ancient castle ruins in the middle of the desert.
> A fleet of desert hovertanks has beensent to destroy it and you
> are the commander. Your tank controls the five remaining missiles.
>
> You must assess carefully the direction and elevation before you
> launch each one. Your computer will ask you for a direction angle
> between -90° (extremeleft) and +90° (extreme right) and an elevation
> angle between 0° (along the ground) and 90° (straight up in the air).
> The elevation determines the distance the missile will travel.
>
> Is your aim good enough to destroy the robot stronghold?

老实说, 这几个代码其实都是差不多的原理, 看那么多类似的代码其实更多的是提高熟练度.

但是这是为了作为课程练习, 所以我们需要一些新的东西来不让我们像是在原地踏步.
所以在这个例子中, 我们做的事情是一个代码的 "转写" 工作. 我们会拿到一个
BASIC 代码 (其实不管是什么代码都行), 然后我们需要将其变成一个 Python 代码.

<details>
<summary>BASIC 代码</summary>
<div markdown="1">

```basic
10 PRINT "DESERT TANK BATTLE"
20 LET T=INT(RND*181)-90
30 LET D=RND

40 FOR G=1 TO 5
50 PRINT "DIRECTION (-90 TO 90) ?"
60 INPUT T1
70 PRINT "ELEVATION (0 TO 90) ?"
80 INPUT B
90 LET D1=SIN(2*(B/180*3.1416))

100 IF ABS(T-T1)<2 AND ABS(D-D1)<.05 THEN GOTO 220
110 PRINT "MISSILE LANDED ";
120 IF T1<T THEN PRINT "TO THE LEFT ";
130 IF T1>T THEN PRINT "TO THE RIGHT ";
140 IF ABS(D1-D)>.05 AND T1<>T THEN PRINT "AND ";
150 IF D-D1>.05 THEN PRINT "NOT FAR ENOUGH";
160 IF D1-D>.05 THEN PRINT "TOO FAR";
170 PRINT

180 NEXT G

190 PRINT "DISASTER - YOU FAILED:
200 PRINT "RETREAT IN DISGRACE"
210 STOP

220 PRINT "*KABOOOMMM*"
230 PRINT "YOU'VE DONE IT"
240 STOP
```

评价: 其实完全和前面的 [Robot Missile](#robot-missile) 是差不多的逻辑,
所以你也可以尝试用 Robot Missile 中写外挂的技术来进行一个外挂的编.

</div>
</details>

请参考 [desert-tank-battle.py](./src/computer-battle-game/desert-tank-battle.py).

这是一个简单的转写例子, 你可能需要随时查询 BASIC 的用法,
以及搞到一台能跑 BASIC 的模拟器.

这里推荐使用 APPLE II 的 BASIC ([applesoft 链接](https://paleotronic.com/applesoft/), 或是 [jsbasic](https://www.calormen.com/jsbasic/)).

当然, 有兴趣的同学可以尝试编写一个 BASIC 的解释器, 如果将来有时间,
我们可以考虑用这个 BASIC 来作为一个简单虚拟机的练习.

## Iceberg
> Your hull is badly damaged and you've no weapons to speak of.
> As you limp slowly home through treacherous iceberg-strewn waters,
> you become aware that an enemy ship is tailing you. Strangely it can
> detect you but not the icebergs, so your best chance is to lure it
> into hitting one.
>
> Your computer will print a grid showing the position of your ship
> (🚢), the enemy (😈) and the icebergs (🏔️). You can move one space North,
> South, East or West each go. The enemy moves towards you by the most
> direct route (it can move diagonally too). If you move into any of the
> 8 positions surrounding the enemy, you will be captured, and if you hit
> an iceberg you will sink.
>
> Can you escape?

是时候该从这些过于朴实无华的终端文本界面升级一下了,
我们将会演示如何下载并调用一个 TUI 的图形库: `curses`.



我们最终的目标是做一个能够显示如下效果的小游戏:

```text
```

### PIP, the python package manager
这里默认大家使用的是 Windows 作为自己的编程环境, 假如是 Unix-like 的环境,
那么大家可以只是看看这里的操作而不必真的执行下面的命令:

1. 打开命令提示符或者任意包含 conda / Python 的环境
2. 输入 `pip` 命令:

```shell
pip install windows-curses
```

这里, 我们使用 `pip install` 命令来下载一个叫作 `windows-curses` 的库.

类似的, 你完全可以下载其他任何的库, 比如 `numpy`, `scipy` 等等.

### 那么, 如何使用 `curses` 库呢?
首先, 相信大家的第一个想法就是跑到万能的互联网上搜索 `curses 教程`
关键词来找到或是 CSDN 或是 b 站视频或是别的什么的网站来找一个教程.

但是, 其实还有一个非常好用的文档/教程来源: 那就是官方的文档: [curses](https://docs.python.org/3/howto/curses.html).
让我们来看看下面的这段代码:

```python
# from https://docs.python.org/3/howto/curses.html#starting-and-ending-a-curses-application
from curses import wrapper

def main(stdscr):
    # Clear screen
    stdscr.clear()

    # This raises ZeroDivisionError when i == 10.
    for i in range(0, 11):
        v = i-10
        stdscr.addstr(i, 0, '10 divided by {} is {}'.format(v, 10/v))

    stdscr.refresh()
    stdscr.getkey()

wrapper(main)
```

将这段代码保存到一个 Python 文件中: [curses-example.py](./src/computer-battle-game/curses-example.py),
然后在终端中运行 `python curses-exaple.py`.

<details>
<summary>为什么一定要在终端中运行? </summary>
<div markdown="1">

因为大部分的 IDE 的终端是终端模拟器而非完整的终端,
而 curses 的背后其实是 C 的 curses 库, 需要一个终端环境.

</div>
</details>

### 假设大家已经差不多了解了 curses 这个库了 (大概)
那么请参考代码: [iceberg.py](./src/computer-battle-game/iceberg.py).

<details>
<summary>代码都写完了, 那么接下来做什么? </summary>
<div markdown="1">

其实代码写完了并不意味着这个程序就没有继续升级的地方了.
我们可以添加许多有意思的功能, 或者对代码进行重构和优化,
以提升可读性或是性能.

在这里我们将会以 Iceberg 的代码为例进行一定的优化和一般化.
假如还有时间的话, 我们可以介绍一下该如何用 OOP 的方式,
来重新构造这个小游戏的代码.

</div>
</details>
