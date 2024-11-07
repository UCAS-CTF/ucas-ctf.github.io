import os
import random
import time

def clear_screen():
    """
    Poor-man's clear screen.
    """
    os.system('clear')

# 这里是我们第一次接触 Python 的 type-hint
# 这是一种给变量静态类型提示的语法,
# 有助于对我们调用函数的时候提供类型提示
# 尽管这和 C 中的类型标记并不完全相同,
# 因为你完全可以无视类型提示随便传值
#
# TODO: exercise
# + how to make the game harder?
def random_string(length : int) -> str:
    """
    Return a random string at length.
    """
    return "".join([chr(random.randint(ord('A'), ord('Z'))) for i in range(length)])

def vital_message():
    # 这里我们用到了字符串转义
    # 在字符串中 `\` 表示对后面的字符进行 "转义",
    # 即让后面跟着的字符不再是字面量字符,
    # 而是具有一定意义的控制字符. 比如说:
    # + `\n` 表示换行 (Newline)
    print("Vital Message\n")

    # 这里我们有一个新的函数 `int` (`__int__`)
    # 表示将对象转换为 `int` (整形)
    #
    # TODO: in class
    # + safety check?
    # + assert `difficulty` between 4 and 10
    difficulty = int(input("How Difficult? (4-10): "))
    flag = random_string(difficulty)

    clear_screen()
    print(f"Send this message: '{flag}'")

    # 这里用到了 `time.sleep` 来等待一段时间
    #
    # TODO: as exercise
    # + how to set different time?
    time.sleep(3)
    clear_screen()

    message = input("What is the message? Input: ")
    if message == flag:
        print("Message Correct",
              "The WAR is over",
              sep="\n")
    else:
        print("You got it wrong",
              "You should have sent:",
              flag,
              sep="\n")

if __name__ == "__main__":
    vital_message()
