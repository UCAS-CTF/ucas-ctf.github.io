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

