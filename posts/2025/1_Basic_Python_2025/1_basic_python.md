# Python for Beginners (2025)

## Class 1: Python基础学习：变量、数据类型、控制流与库安装

**Contents**
- **输入/输出**		*Input/Output (I/O)*
- **赋值与运算**	*Assignment & Arithmetic*
- **数据类型**		*Data Types*
- **条件语句**		*Conditional Statements*
- **循环语句**		*Loops*
- **函数调用**		*Function Calls*
- **函数**		    *Functions*
- **库与库函数调用**	*Libraries & Library Functions*

**PPT**
<iframe src="https://ucas-ctf.github.io/posts/2025/1_Basic_Python_2025/1_1_Python_Syntax/CTF%20Class%201%20-%20Python_1.pdf" style="width:100%; height:240px;" frameborder="0"></iframe>

**Code 0**:
```python
print("Hello World!")
```

**Code 1**:
```python
print(print())
print(type(333))
print(type("18"))
print(type([1, 2, 3]))
print(type((4, 5, 6)))
print(type(set([7, 8, 9])))
print(type({1: "a", 2: "b"}))
print(ord("A"))
print(chr(97))
```

**Code 2**:
```python
a, b = int(input("Number1 > ")), int(input("Number2 > "))
op = input("Operator(`+`, `-`, `*`, `/`, `**`) > ")
if op == "+": print(a + b)
elif op == "-": print(a - b)
elif op == "*": print(a * b)
elif op == "/": print(a / b)
elif op == "**": print(a ** b)
else: print("Unknown operator!")
```

**Code 3**:
```python
print(3 * "2")
print(6 * [0])
print([1] + [3, 4])
print("23" + "45")
print(int("0xd", 16))
```

**Code 4**:
```python
def mycalc(a, b):
    # a$b = a * b + a - b
    c = a * b + a - b
    return c

mycalc = lambda a, b: a * b + a - b

while True:
    a, b = int(input("number1 > ")), int(input("number2 > "))
    op = input("Operator(`+`, `-`, `*`, `/`, `**`) > ")
    if op == "+": print(a + b)
    elif op == "-": print(a - b)
    elif op == "*": print(a * b)
    elif op == "/": print(a / b)
    elif op == "**": print(a ** b)
    elif op == "$": print(mycalc(a, b))
    else: print("Unknown operator!")
```
