# 这里和之前 import 整个模块名称不一样,
# 在这里我们只导入模块的一个函数,
# 并让我们可以直接用 `randint` 和 `random' 的方式去调用
from random import randint, random

def desert_tank_battle_game():
    print("DESERT TANK BATTLE")

    # 20 LET T=INT(RND*181)-90
    # 30 LET D=RND
    flag_degree = randint(90, 180)
    flag_distance = random()

    # TODO: in class
    # + we will use this as an example of
    #   converting any language code logic to python,
    #   which is useful when you're doing reversing

    # 40 FOR G=1 TO 5
    try_times = 1
    while try_times <= 5:
        # 60 INPUT T1
        # 80 INPUT B
        try_degree   = int(input("DIRECTION (-90 TO 90) ?"))
        try_distance = int(input("ELEVATION (0 TO 90) ?"))
        
        # ... more ...

if __name__ == "__main__":
    desert_tank_battle_game()
