from time import sleep
from random import randint
import curses

# 注: 这个代码为了展示重构, 所以特地把所有的内容都写在一起了,
# 请不要学习这样的错误做法.

stdscr = curses.initscr()

# 打印欢迎信息
stdscr.clear()
stdscr.addstr(0, 0, "ICEBERG")
stdscr.refresh()

## 初始化代码

# 这里我们用了一个小技巧来新建了一个 8x8 的空列表
iceberg_map = [[" " for i in range(8)] for j in range(8)]
iceberg_num = randint(4, 12)

# 这里我们使用 list of list 对双重的列表元素进行取值
for i in range(iceberg_num):
    iceberg_map[randint(0, 7)][randint(0, 7)] = "#"

# 这里我们要找一个空格子并将敌人画在上面
enemy_x, enemy_y = randint(0, 7), randint(0, 7)
while iceberg_map[enemy_y][enemy_x] != " ":
    enemy_x, enemy_y = randint(0, 7), randint(0, 7)
iceberg_map[enemy_y][enemy_x] = "Z"

# 同理, 我们将自己画在上面
# 思考: 是否这里的两段代码可以复用?
player_x, player_y = randint(0, 7), randint(0, 7)
while iceberg_map[player_y][player_x] != " ":
    player_x, player_y = randint(0, 7), randint(0, 7)
iceberg_map[player_y][player_x] = "Y"

## 老板说在这里加上一个 sleep 函数, 后期让用户花钱买显卡以升级 pro 版,
## 到时候把这个 sleep 减少一点以让用户之后买更好的卡.
sleep(1)

# event loop
while True:
    # 绘制地图
    stdscr.clear()
    for y in range(8):
        for x in range(8):
            stdscr.addstr(y, x, iceberg_map[y][x])
    stdscr.addstr(8, 0, "DIRECTION (WASD to move)")
    stdscr.refresh()

    # 读取用户按键信息并进行移动
    iceberg_map[player_y][player_x] = " "
    while True:
        direction = stdscr.getkey()
        if direction == "w" and player_y != 0:
            player_y = player_y - 1
            break
        elif direction == "s" and player_y != 7:
            player_y = player_y + 1
            break
        elif direction == "a" and player_x != 0:
            player_x = player_x - 1
            break
        elif direction == "d" and player_x != 7:
            player_x = player_x + 1
            break
        elif direction == "q":
            break

    # 游戏终止
    if direction == "q":
        stdscr.clear()
        stdscr.addstr(0, 0, "Game Aborted")
        stdscr.refresh()
        break

    # 检测是否撞到冰山
    if iceberg_map[player_y][player_x] == "#":
        stdscr.addstr(8, 0, "YOU'VE HIT AN ICEBERG!           ")
        stdscr.refresh()
        break

    # 检测是否被敌人抓住
    if iceberg_map[player_y][player_x] == "Z":
        stdscr.addstr(8, 0, "YOU'VE BEEN CAUGHT           ")
        stdscr.refresh()
        break

    # 移动
    iceberg_map[player_y][player_x] = "Y"

    # 敌人移动
    iceberg_map[enemy_y][enemy_x] = " "

    # 这里用到了 Python 的 "三目运算符"
    # 注: 只是类似的东西, 和 C 的还是有点区别
    enemy_x += 1 if player_x > enemy_x else -1
    enemy_y += 1 if player_y > enemy_y else -1

    # 检测敌人是否撞到冰山
    if iceberg_map[enemy_y][enemy_x] == "#":
        stdscr.addstr(8, 0, "YOU'RE SAFE - HE'S HIT ONE!    ")
        stdscr.refresh()
        break

    # 检测敌人是否抓到我们
    if iceberg_map[enemy_y][enemy_x] == "Y":
        stdscr.addstr(8, 0, "YOU'VE BEEN CAUGHT         ")
        stdscr.refresh()
        break

    # 移动
    iceberg_map[enemy_y][enemy_x] = "Z"

stdscr.getkey()
