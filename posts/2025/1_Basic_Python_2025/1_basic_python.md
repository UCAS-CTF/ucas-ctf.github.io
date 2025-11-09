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

## Class 2: Python实践：凯撒密码的实现

**Contents**
- **匿名函数**		    Anonymous Function/Lambda Expression
- **三元表达式**	    Ternary Operator/Conditional Expression
- **海象运算符**	    Walrus Operator/Assignment Expression
- **推导式**		    Comprehension
- **命名空间与作用域**  Namespace & Scope
- **面向对象与类**	    OOP & Class
- **文件读写**		    File I/O (File Input/Output)
- **其他**		        Miscellaneous

**PPT**
<iframe src="https://ucas-ctf.github.io/posts/2025/1_Basic_Python_2025/1_1_Python_Syntax/CTF%20Class%201%20-%20Python_1.pdf" style="width:100%; height:240px;" frameborder="0"></iframe>

**Code 1: Anonymous Function/Lambda Expression**
```python
"""
function = lambda var: expr
"""

ADD = lambda x, y: x + y
DBL = lambda x: x ** 2
# Combine lambda expr with operations on list
li = [1, 2, 3, 4, 5, 6]

## map()
DBL_li = list(map(DBL, li)); print(DBL_li)
DBL_li_ = list(map(lambda x: x ** 2, DBL_li)); print(DBL_li_)

## filter()
f_DBL_li = list(filter(DBL, li)); print(f_DBL_li)
f_DBL_li_ = list(filter(lambda x: x % 2 == 0, li)); print(f_DBL_li_)

## reduce()
from functools import reduce
r_ADD_li = reduce(ADD, li); print(r_ADD_li)
r_ADD_li_ = reduce(lambda x, y: x + y, li); print(r_ADD_li_)

rADD = lambda li: reduce(lambda x, y: x + y, li)
print(rADD([1, 3, 4, 5, 7, 8, 9]))
rMul = lambda li: reduce(lambda x, y: x * y, li)
print(rMul([1, 3, 4, 5, 7, 8, 9]))
rFac = lambda n: reduce(lambda x, y: x * y, [i + 1 for i in range(n)])
print(rFac(5))

## all()
my_isPrime = lambda n: all(n % i != 0 for i in range(2, int(n**(1/2)) + 1))
print(f"{my_isPrime(7) = }, {my_isPrime(9) = }")
## any()
hasPrime = lambda li: any(my_isPrime(i) for i in li)
print(f"{hasPrime([2 * i + 1 for i in range(10)])}")
## sum()
primeCount = lambda li: sum(my_isPrime(i) for i in li)
print(f"{primeCount([2 * i + 1 for i in range(10)])}")
```

**Code 2: Ternary Operator/Conditional Expression**
```python
"""
expr_1 if cond else expr_2
"""

func1 = lambda x: x if x > 0 else -x

func2 = lambda x: x if x < -1 else -x if x < 1 else x
func2_ = lambda x: -x if -1 <= x < 1 else x

func3 = lambda x: "D" if x < 60 else ("C" if x < 80 else ("B" if x < 90 else "A"))
func3 = lambda x: ("D" if x < 60 else "C") if x < 80 else ("B" if x < 90 else "A")
func3 = lambda x: (("D" if x < 60 else "C") if x < 80 else "B") if x < 90 else "A"
```

**Code 3: Walrus Operator/Assignment Expression**
```python
"""
(var := expr)
expr(var)
"""

def encrypt_4(s: str, k: int = 3) -> str:
    sub = lambda ch, base, k: chr((ord(ch) - (o := ord(base)) + k) % 26 + o)
    return ''.join(sub(c, 'A', k) if c.isupper() else sub(c, 'a', k) if c.islower() else c for c in s)

s = "Hello World!"
print(encrypt_4(s))
```

**Code 4: Comprehension**
```python
"""
[expr for var in iter]
"""

n = 10
print(i ** 2 for i in range(n))
print([i ** 2 for i in range(n)])

# my_isprime = lambda n: all(n % i != 0 for i in range(2, int(n**(1/2)) + 1))
n = 100
print([k for k in range(2, n) if all(k % i != 0 for i in range(2, int(k**(1/2)) + 1))])
```

**Code 5: Namespace & Scope**
```python
### Model 1 ###
a = 1
b = 2
for i in range(12):
    j = 3
    a = b + i
    print(a * i + j)

### Case 1 ###
sub = lambda ch, base, k: chr((ord(ch) - ord(base) + k) % 26 + ord(base))

def encrypt(s: str, k: int = 3) -> str:
    return ''.join(sub(c, 'A',  k) if c.isupper() else sub(c, 'a',  k) if c.islower() else c for c in s)

def decrypt(s: str, k: int = 3) -> str:
    return ''.join(sub(c, 'A', -k) if c.isupper() else sub(c, 'a', -k) if c.islower() else c for c in s)

### Case 2 ###
k: int = 3
sub = lambda ch, base, k: chr((ord(ch) - ord(base) + k) % 26 + ord(base))

def encrypt(s: str) -> str:
    return ''.join(sub(c, 'A',  k) if c.isupper() else sub(c, 'a',  k) if c.islower() else c for c in s)

def decrypt(s: str) -> str:
    return ''.join(sub(c, 'A', -k) if c.isupper() else sub(c, 'a', -k) if c.islower() else c for c in s)
```

**Code 6: OOP & Class**
```python
### Model 1
class Caesar:
    def __init__(self, k):
        self.k: int = k

        self.sub = ...

    def encrypt(self, s: str) -> str:
        ...

    def decrypt(self, s: str) -> str:
        ...

### Model 2
class Caesar:
    def __init__(self, k):
        ...

    def encrypt(self, s: str) -> str:
        ...

    def decrypt(self, s: str) -> str:
        ...

caesarUser1 = Caesar(7)
msgUser1 = "I am User One."
cfrUser1 = caesarUser1.encrypt(msgUser1)
de_cfrUser1 = caesarUser1.encrypt(cfrUser1)

import this

### Complete Model 2
class Caesar:
    def __init__(self, k: int = 3):
        self.k = k
        self.sub = lambda ch, base, k: chr((ord(ch) - ord(base) + k) % 26 + ord(base))

    def encrypt(self, m: str) -> str:
        return ''.join(self.sub(c, 'A',  self.k) if c.isupper() else self.sub(c, 'a',  self.k) if c.islower() else c for c in m)

    def decrypt(self, m: str) -> str:
        return ''.join(self.sub(c, 'A', -self.k) if c.isupper() else self.sub(c, 'a', -self.k) if c.islower() else c for c in m)

caesarUser1 = Caesar(7)
msgUser1 = "I am User One."
cfrUser1 = caesarUser1.encrypt(msgUser1)
print(f"{cfrUser1 = }")
de_cfrUser1 = caesarUser1.decrypt(cfrUser1)
print(f"{de_cfrUser1 = }")
```

**Code 7: File I/O (File Input/Output)**
```python
class Caeser:
    def __init__(self, k: int = 3):
        self.k = k
        self.sub = lambda ch, base, k: chr((ord(ch) - ord(base) + k) % 26 + ord(base))

    def encrypt(self, m: str) -> str:
        return ''.join(self.sub(c, 'A',  self.k) if c.isupper() else self.sub(c, 'a',  self.k) if c.islower() else c for c in m)

    def decrypt(self, m: str) -> str:
        return ''.join(self.sub(c, 'A', -self.k) if c.isupper() else self.sub(c, 'a', -self.k) if c.islower() else c for c in m)
    
    def encrypt_file(self, rpath, wpath):
        with open(rpath, "r", encoding = "utf-8") as f:
            m = f.read()
        with open(wpath, "w", encoding = "utf-8") as f:
            f.write(self.encrypt(m))

    def decrypt_file(self, rpath, wpath):
        f = open(rpath, "r", encoding = "utf-8")
        c = f.read()
        f.close() # Adding this line is written properly.
        f = open(wpath, "w", encoding = "utf-8")
        f.write(self.decrypt(c))
        f.close() # Adding this line is written properly.

    def test(self) -> bool:
        m = "Hello World!"
        print(f"[Encrypted!]: {(c := self.encrypt(m))}")
        print(f"[Decrypted!]: {self.decrypt(c)}")

caeser = Caeser()
caeser.test()
caeser.encrypt_file(r"MyMSG.txt", r"Enc_MyMSG.txt")
caeser.decrypt_file(r"Enc_MyMSG.txt", r"Dec_MyMSG.txt")
assert open(r"MyMSG.txt", "r", encoding = "utf-8").read() == open(r"Dec_MyMSG.txt", "r", encoding = "utf-8").read()
```

**Code 8: Web Server**
```python
class Caeser:
    def __init__(self, k: int = 3):
        self.k = k
        self.sub = lambda ch, base, k: chr((ord(ch) - ord(base) + k) % 26 + ord(base))

    def encrypt(self, m: str) -> str:
        return ''.join(self.sub(c, 'A',  self.k) if c.isupper() else self.sub(c, 'a',  self.k) if c.islower() else c for c in m)

    def decrypt(self, m: str) -> str:
        return ''.join(self.sub(c, 'A', -self.k) if c.isupper() else self.sub(c, 'a', -self.k) if c.islower() else c for c in m)
    
    def encrypt_file(self, rpath, wpath):
        with open(rpath, "r", encoding = "utf-8") as f:
            m = f.read()
        with open(wpath, "w", encoding = "utf-8") as f:
            f.write(self.encrypt(m))

    def decrypt_file(self, rpath, wpath):
        f = open(rpath, "r", encoding = "utf-8")
        c = f.read()
        f.close() # Adding this line is written properly.
        f = open(wpath, "w", encoding = "utf-8")
        f.write(self.decrypt(c))
        f.close() # Adding this line is written properly.

    def test(self) -> bool:
        m = "Hello World!"
        print(f"[Encrypted!]: {(c := self.encrypt(m))}")
        print(f"[Decrypted!]: {self.decrypt(c)}")

caeser = Caeser()
caeser.test()
caeser.encrypt_file(r"MyMSG.txt", r"Enc_MyMSG.txt")
caeser.decrypt_file(r"Enc_MyMSG.txt", r"Dec_MyMSG.txt")
assert open(r"MyMSG.txt", "r", encoding = "utf-8").read() == open(r"Dec_MyMSG.txt", "r", encoding = "utf-8").read()
```

**Code 9: GUI** (Generated by Deepseek)
```python
import tkinter as tk
from tkinter import ttk, messagebox, scrolledtext
import os

class CaesarCipherGUI:
    def __init__(self, root):
        self.root = root
        self.root.title("Caesar Cipher")
        self.root.geometry("800x600")
        self.root.resizable(True, True)
        self.cipher = CaesarCipher()
        
        self.setup_styles()
        self.create_widgets()
        self.bind_events()
    
    def setup_styles(self):
        style = ttk.Style()
        style.configure("TFrame", background="#f0f0f0")
        style.configure("TLabel", background="#f0f0f0", font=("Arial", 10))
        style.configure("Title.TLabel", background="#f0f0f0", font=("Arial", 16, "bold"))
        style.configure("TButton", font=("Arial", 10))
        style.configure("TEntry", font=("Arial", 10))
        style.configure("TNotebook", background="#f0f0f0")
        style.configure("TNotebook.Tab", font=("Arial", 10, "bold"))
    
    def create_widgets(self):
        
        # Main Structure
        main_frame = ttk.Frame(self.root, padding="10")
        main_frame.pack(fill=tk.BOTH, expand=True)
        
        # Title
        title_label = ttk.Label(
            main_frame, 
            text="Caesar Cipher - Enc&Dec", 
            style="Title.TLabel"
        )
        title_label.pack(pady=(0, 20))
        
        # 创建选项卡
        notebook = ttk.Notebook(main_frame)
        notebook.pack(fill=tk.BOTH, expand=True, padx=5, pady=5)
        
        # 文本加解密选项卡
        text_frame = ttk.Frame(notebook, padding="10")
        notebook.add(text_frame, text="文本加解密")
        
        # 文件加解密选项卡
        file_frame = ttk.Frame(notebook, padding="10")
        notebook.add(file_frame, text="文件加解密")

        # 填充各个选项卡
        self.create_text_tab(text_frame)
        self.create_file_tab(file_frame)
    
    def create_text_tab(self, parent):

        # 密钥设置区域
        key_frame = ttk.Frame(parent)
        key_frame.pack(fill=tk.X, pady=(0, 10))
        
        ttk.Label(key_frame, text="密钥 (位移量):").grid(row=0, column=0, sticky=tk.W, padx=(0, 10))
        self.key_var = tk.StringVar(value="3")
        key_entry = ttk.Entry(key_frame, textvariable=self.key_var, width=10)
        key_entry.grid(row=0, column=1, sticky=tk.W)
        
        # 更新密钥按钮
        ttk.Button(
            key_frame, 
            text="更新密钥", 
            command=self.update_key
        ).grid(row=0, column=2, padx=(10, 0))
        
        # 输入文本区域
        input_frame = ttk.LabelFrame(parent, text="输入文本", padding="5")
        input_frame.pack(fill=tk.BOTH, expand=True, pady=(0, 10))
        
        self.input_text = scrolledtext.ScrolledText(input_frame, height=8, wrap=tk.WORD)
        self.input_text.pack(fill=tk.BOTH, expand=True)
        
        # 按钮区域
        button_frame = ttk.Frame(parent)
        button_frame.pack(fill=tk.X, pady=(0, 10))
        
        ttk.Button(
            button_frame, 
            text="Encrypt", 
            command=self.encrypt_text
        ).pack(side=tk.LEFT, padx=(0, 10))
        
        ttk.Button(
            button_frame, 
            text="Decrypt", 
            command=self.decrypt_text
        ).pack(side=tk.LEFT, padx=(0, 10))
        
        ttk.Button(
            button_frame, 
            text="Clear", 
            command=self.clear_text
        ).pack(side=tk.LEFT)
        
        # 输出文本区域
        output_frame = ttk.LabelFrame(parent, text="Output", padding="5")
        output_frame.pack(fill=tk.BOTH, expand=True)
        
        self.output_text = scrolledtext.ScrolledText(output_frame, height=8, wrap=tk.WORD)
        self.output_text.pack(fill=tk.BOTH, expand=True)
    
    def create_file_tab(self, parent):
        # 文件选择区域
        file_select_frame = ttk.Frame(parent)
        file_select_frame.pack(fill=tk.X, pady=(0, 10))
        
        ttk.Label(file_select_frame, text="Input File Path:").grid(row=0, column=0, sticky=tk.W, padx=(0, 10))
        self.input_file_var = tk.StringVar()
        ttk.Entry(file_select_frame, textvariable=self.input_file_var, width=40).grid(row=0, column=1, sticky=tk.W)
        ttk.Button(
            file_select_frame, 
            text="浏览...", 
            command=self.browse_input_file
        ).grid(row=0, column=2, padx=(10, 0))
        
        ttk.Label(file_select_frame, text="Output File Path:").grid(row=1, column=0, sticky=tk.W, padx=(0, 10), pady=(10, 0))
        self.output_file_var = tk.StringVar()
        ttk.Entry(file_select_frame, textvariable=self.output_file_var, width=40).grid(row=1, column=1, sticky=tk.W, pady=(10, 0))
        ttk.Button(
            file_select_frame, 
            text="浏览...", 
            command=self.browse_output_file
        ).grid(row=1, column=2, padx=(10, 0), pady=(10, 0))
        
        # 按钮区域
        file_button_frame = ttk.Frame(parent)
        file_button_frame.pack(fill=tk.X, pady=(0, 10))
        
        ttk.Button(
            file_button_frame, 
            text="Encrypt", 
            command=self.encrypt_file
        ).pack(side=tk.LEFT, padx=(0, 10))
        
        ttk.Button(
            file_button_frame, 
            text="Decrypt", 
            command=self.decrypt_file
        ).pack(side=tk.LEFT)
        
        # 文件内容预览区域
        preview_frame = ttk.LabelFrame(parent, text="File Content", padding="5")
        preview_frame.pack(fill=tk.BOTH, expand=True)
        
        self.file_preview_text = scrolledtext.ScrolledText(preview_frame, height=10, wrap=tk.WORD)
        self.file_preview_text.pack(fill=tk.BOTH, expand=True)
    
    def bind_events(self):
        # 绑定文件预览事件
        self.input_file_var.trace_add("write", self.preview_file_content)
    
    def update_key(self):
        try:
            key = int(self.key_var.get())
            self.cipher.k = key
            messagebox.showinfo("成功", f"密钥已更新为: {key}")
        except ValueError:
            messagebox.showerror("错误", "密钥必须是整数!")
    
    def encrypt_text(self):
        """加密文本"""
        input_text = self.input_text.get("1.0", tk.END).strip()
        if not input_text:
            messagebox.showwarning("警告", "请输入要加密的文本!")
            return
        
        try:
            encrypted = self.cipher.encrypt(input_text)
            self.output_text.delete("1.0", tk.END)
            self.output_text.insert("1.0", encrypted)
        except Exception as e:
            messagebox.showerror("错误", f"加密过程中出现错误: {str(e)}")
    
    def decrypt_text(self):
        input_text = self.input_text.get("1.0", tk.END).strip()
        if not input_text:
            messagebox.showwarning("警告", "请输入要解密的文本!")
            return
        
        try:
            decrypted = self.cipher.decrypt(input_text)
            self.output_text.delete("1.0", tk.END)
            self.output_text.insert("1.0", decrypted)
        except Exception as e:
            messagebox.showerror("错误", f"解密过程中出现错误: {str(e)}")
    
    def clear_text(self):
        self.input_text.delete("1.0", tk.END)
        self.output_text.delete("1.0", tk.END)
    
    def browse_input_file(self):
        from tkinter import filedialog
        filename = filedialog.askopenfilename(
            title="选择输入文件",
            filetypes=[("文本文件", "*.txt"), ("所有文件", "*.*")]
        )
        if filename:
            self.input_file_var.set(filename)
    
    def browse_output_file(self):
        from tkinter import filedialog
        filename = filedialog.asksaveasfilename(
            title="选择输出文件",
            defaultextension=".txt",
            filetypes=[("文本文件", "*.txt"), ("所有文件", "*.*")]
        )
        if filename:
            self.output_file_var.set(filename)
    
    def preview_file_content(self, *args):
        filename = self.input_file_var.get()
        if filename and os.path.isfile(filename):
            try:
                with open(filename, "r", encoding="utf-8") as f:
                    content = f.read()
                self.file_preview_text.delete("1.0", tk.END)
                self.file_preview_text.insert("1.0", content)
            except Exception as e:
                self.file_preview_text.delete("1.0", tk.END)
                self.file_preview_text.insert("1.0", f"无法读取文件: {str(e)}")
    
    def encrypt_file(self):
        input_file = self.input_file_var.get()
        output_file = self.output_file_var.get()
        
        if not input_file or not output_file:
            messagebox.showwarning("警告", "请选择输入和输出文件!")
            return
        
        if not os.path.isfile(input_file):
            messagebox.showerror("错误", "输入文件不存在!")
            return
        
        try:
            self.cipher.encrypt_file(input_file, output_file)
            messagebox.showinfo("成功", f"文件已加密并保存为: {output_file}")
            
            # 更新预览
            if os.path.isfile(output_file):
                with open(output_file, "r", encoding="utf-8") as f:
                    content = f.read()
                self.file_preview_text.delete("1.0", tk.END)
                self.file_preview_text.insert("1.0", content)
        except Exception as e:
            messagebox.showerror("错误", f"文件加密失败: {str(e)}")
    
    def decrypt_file(self):
        input_file = self.input_file_var.get()
        output_file = self.output_file_var.get()
        
        if not input_file or not output_file:
            messagebox.showwarning("警告", "请选择输入和输出文件!")
            return
        
        if not os.path.isfile(input_file):
            messagebox.showerror("错误", "输入文件不存在!")
            return
        
        try:
            self.cipher.decrypt_file(input_file, output_file)
            messagebox.showinfo("成功", f"文件已解密并保存为: {output_file}")
            
            # 更新预览
            if os.path.isfile(output_file):
                with open(output_file, "r", encoding="utf-8") as f:
                    content = f.read()
                self.file_preview_text.delete("1.0", tk.END)
                self.file_preview_text.insert("1.0", content)
        except Exception as e:
            messagebox.showerror("错误", f"文件解密失败: {str(e)}")


class CaesarCipher:
    def __init__(self, k: int = 3):
        self.k = k
        self.sub = lambda ch, base, k: chr((ord(ch) - ord(base) + k) % 26 + ord(base))

    def encrypt(self, m: str) -> str:
        return ''.join(self.sub(c, 'A',  self.k) if c.isupper() else self.sub(c, 'a',  self.k) if c.islower() else c for c in m)

    def decrypt(self, m: str) -> str:
        return ''.join(self.sub(c, 'A', -self.k) if c.isupper() else self.sub(c, 'a', -self.k) if c.islower() else c for c in m)
    
    def encrypt_file(self, rpath, wpath):
        with open(rpath, "r", encoding="utf-8") as f:
            m = f.read()
        with open(wpath, "w", encoding="utf-8") as f:
            f.write(self.encrypt(m))

    def decrypt_file(self, rpath, wpath):
        with open(rpath, "r", encoding="utf-8") as f:
            c = f.read()
        with open(wpath, "w", encoding="utf-8") as f:
            f.write(self.decrypt(c))
    
    def test(self) -> bool:
        m = "Hello World!"
        print(f"[Encrypted!]: {(c := self.encrypt(m))}")
        print(f"[Decrypted!]: {self.decrypt(c)}")


def main():
    root = tk.Tk()
    app = CaesarCipherGUI(root)
    root.mainloop()


if __name__ == "__main__":
    cipher = CaesarCipher()
    # cipher.test()
    main()
```