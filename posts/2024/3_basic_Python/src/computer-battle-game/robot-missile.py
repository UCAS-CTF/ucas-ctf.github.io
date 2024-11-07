import random

def print_title():
    # 在 Python 中, `print` 命令支持多个参量的输出, 并且可以用 `sep` 分隔.
    # 请尝试不同的 `print` `sep` 参数并看看效果如何
    print("Robot Missile",
          "",
          "Type the CORRECT CODE lettler (A-Z) to",
          "defuse the missile. ",
          "",
          "You have 4 chance:",
          sep="\n")

def guess_loop():
    # 在这里我们调用了三个函数:
    # + `chr`: int -> char
    # + `ord`: char -> int
    # + `random.randint(a : int, b : int)`: 获得 `a`, `b` 之间的一个随机整数
    # 请借助 LSP 或是你编辑器的自动文档来阅读它们的细致说明
    flag = chr(random.randint(ord('A'), ord('Z')))

    try_times  = 0
    while try_times < 4:
        # 在这里是一个简单的 IO 操作:
        # `input`: 从 stdin 中读取一个字符串
        char = input("Try: ")[0]

        # 这里是一个自增算符
        try_times += 1

        if char == flag:
            print("TICK...FZZZZ...CLICK...",
                  "YOU DID IT",
                  sep="\n")
            return True
        elif char < flag:
            print("LATER")
        else:
            print("EARLIER")

    print("BOOOOOOOOOOOMMM...",
          "YOU BLEW IT.",
          f"The correct code was '{flag}'. ",
          sep="\n")
    return False

# TODO in class:
# + add restart
# + add quit control command
if __name__ == "__main__":
    print_title()
    guess_loop()
