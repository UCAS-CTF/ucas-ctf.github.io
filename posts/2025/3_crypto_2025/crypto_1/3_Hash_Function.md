# 二、哈希函数（Hash Function）

## （一）单向函数（One-way Function）

> 单向函数是密码学乃至计算机理论的理论基石，其蕴含了 $P \stackrel{?}{=} NP$ 问题的答案。

一个函数 $f(x)$ 被称为**单向函数**，如果：

1.  **易于计算**：给定 $x$，计算 $y = f(x)$ 在多项式时间内是容易的。
2.  **难以逆转**：给定 $y$，找到**任何**一个 $x$ 使得 $f(x) = y$ 在计算上是不可行的。

**哈希函数**就是基于单向函数的理念构建的。（一般我们认为哈希函数就是单向的，虽然其实并没有人能够证明单向函数确实存在）。

<details>

<summary> 补充内容 </summary>

**wOWF, sOWF 与 Yau 定理**

- **强单向函数 (sOWF - Strong One-Way Function)**：
    - 这就是我们通常所说的“单向函数”。
    - **难以逆转**的含义是：对于*所有*概率多项式时间(PPT)算法 $A$，成功反转 $f$ 的概率 $Pr[f(A(f(x))) = f(x)]$ 是**可忽略的 (negligible)**。
    - "可忽略"意味着这个概率比*任何*多项式的倒数 ($1/p(\lambda)$) 都要小。
- **弱单向函数 (wOWF - Weak One-Way Function)**：
    - 这是一个更弱的假设。
    - **难以逆转**的含义是：对于*所有*PPT算法 $A$，成功反转 $f$ 的概率**小于 1**。
    - 换句话说，存在一个**不可忽略的 (non-negligible)** 概率（例如 $1 / p(\lambda)$），使得 $A$ *无法*反转 $f(x)$。
    - (这允许 $A$ 成功反转*一部分*输入，只要它不能反转*所有*输入)。
- **Yau 定理 (1982)**：
    - 这是理论密码学的基石之一。
    - **定理**：**强单向函数 (sOWF) 存在 当且仅当 弱单向函数 (wOWF) 存在。**
    - **含义**：这个“当且仅当”是革命性的。它告诉我们，只要我们能找到*任何*一个只是*偶尔*难以反转的函数（wOWF），我们就可以通过“难度放大 (hardness amplification)”（例如，通过重复和拼接）将其“增强”为一个*总是*难以反T转的函数（sOWF）。这大大降低了寻找密码学基础的门槛。

**Levin's OWF (平均情况困难性)**

- Leonid Levin 的工作将单向函数与**平均情况复杂度 (Average-Case Complexity)** 联系起来。
- 我们知道 $NP$ 问题是“难以解决”的，但这是指**最坏情况 (Worst-Case)**。
- Levin 表明，我们可以从一个在**平均情况下**也难以解决的 $NP$ 问题（例如，一个 NP 完全问题的“平铺 (Tiling)”版本）构造出单向函数。
- 这条线索将计算复杂性理论 ($P$ vs $NP$) 与密码学的存在性联系起来。

**PRG (伪随机生成器) 与 PRF (伪随机函数)**

- **伪随机生成器 (PRG)**：
    - $G: \{0,1\}^\lambda \to \{0,1\}^{p(\lambda)}$，其中 $p(\lambda) > \lambda$ (它**扩展**输入)。
    - **安全定义**：一个PPT“区分器” $D$，无法以不可忽略的优势区分 $G(s)$ (其中 $s$ 是真随机种子) 和一个**等长的真随机字符串** $r$。
    - $|Pr[D(G(s)) = 1] - Pr[D(r) = 1]| < \text{negl}(\lambda)$
    - **定理 (Håstad, Impagliazzo, Levin, Luby)**：**PRG 存在 当且仅当 OWF 存在。**
- **伪随机函数 (PRF)**：
    - $F: \{0,1\}^\lambda \times \{0,1\}^n \to \{0,1\}^m$。
    - 它是一个由密钥 $k \in \{0,1\}^\lambda$ 索引的**函数族**。
    - **安全定义**：一个PPT“区分器” $D$，在给予**预言机访问 (oracle access)** 的情况下，无法以不可忽略的优势区分 $F_k(\cdot)$ ( $k$ 是随机选择的) 和一个**真随机函数** $f(\cdot)$ (即一个从输入到输出的随机查找表)。
    - PRF 是一个更强大的工具（例如，分组密码 AES 就可以被建模为一个 PRF）。

**Hardcore Predicate (硬核谓词)**

- **问题**： $f(x)$ 是一个OWF。我们知道从 $y=f(x)$ 找到 $x$ 很难。但是，我们能不能从 $y$ 猜出*关于 $x$ 的某些信息*？比如 $x$ 的最后一位？
- **硬核谓词 $h(x)$**：是一个易于计算（从 $x$）的函数（通常输出1比特），但**难以预测**（从 $f(x)$）。
- **定义**： $h$ 是 $f$ 的一个硬核谓词，如果 $h(x)$ 易于计算，但任何PPT算法 $A$ 猜测 $h(x)$ 的成功率*不会*显著高于 50%。
    - $Pr[A(f(x)) = h(x)] < 1/2 + \text{negl}(\lambda)$
- **意义**：它证明了 $f(x)$ 确实“隐藏”了 $x$ 的*所有*信息，连1比特的信息都猜不准。

**Goldreich-Levin 定理 (1989)**

- **定理**：**任何**单向函数 $f$ 都可以被“改造”成一个新的单向函数 $g$，并且这个 $g$ 拥有一个**已知的硬核谓词**。
- **构造**：
    1.  $f(x)$ 是任意 OWF。
    2.  构造 $g(x, r) = (f(x), r)$，其中 $r$ 是与 $x$ 等长的随机串。
    3.  $g$ 也是一个 OWF。
    4.  **定理证明**：$h(x, r) = x \cdot r \pmod 2$ （$x$ 和 $r$ 的内积）是 $g$ 的一个硬核谓词。
- **巨大意义**：
    1.  它证明了**任何OWF都必然隐藏了某些信息**。
    2.  它是**从 OWF 构造 PRG** 的关键步骤。
    3.  构造方法： $G(s) = (f(s), h(s))$？不是。
    4.  正确构造 (Blum-Micali)： $G(s) = (f(s), h(s))$，但 $s$ 不断迭代。更重要的是，Goldreich-Levin 允许我们从一个OWF中一次性提取出 $\lambda$ 个“硬核”比特，从而构建出PRG。
    5.  **Goldreich-Levin 定理是连接 OWF 和 PRG 的桥梁，证明了单向函数是所有对称密码学（PRG, PRF, Stream Ciphers...）的“原子”基础。**

</details>

## （二）哈希函数与碰撞

**哈希函数/散列函数/杂凑函数（Hash Function）**（或称**消息摘要，digest**）是一种算法，它将**任意长度的输入数据**映射为**固定长度**的输出字符串（称为**哈希值**或**摘要**）。

**密码学中的哈希函数的特性**：

1.  **单向性（Preimage Resistance）**： 给定 $h$，很难找到 $m$ 使得 $H(m) = h$。
2.  **第二单向性（Second Preimage Resistance）**：给定 $m_1$，很难找到 $m_2 \neq m_1$ 使得 $H(m_1) = H(m_2)$。
3.  **强抗碰撞性（Collision Resistance）**：很难找到**任意**一对 $m_1 \neq m_2$ 使得 $H(m_1) = H(m_2)$。

**碰撞（Collision）**：
根据**抽屉原理（鸽笼原理）**，由于输入空间（无限）远大于输出空间（有限，例如SHA-256的 $2^{256}$ 种可能），碰撞**必然**存在。哈希函数的目标是让找到碰撞在**计算上不可行**。

**常见的哈希函数**：

- **MD5** (128位)：**已完全破解**。王小云院士在2004年提出了快速寻找碰撞的方法。**绝对不能用于安全目的**。
- **SHA-1** (160位)：**已破解**。2017年Google演示了SHAttered碰撞。
- **SHA-2** (SHA-256, SHA-512)：**目前安全**。广泛用于SSL/TLS、比特币等。
- **SHA-3** (Keccak)：作为SHA-2的备选方案，结构完全不同。

**Python 示例**：
使用内置的 `hashlib` 库。

```python
import hashlib

# 1. MD5 示例
m_md5 = hashlib.md5()
m_md5.update(b"Hello")
m_md5.update(b" World") # 可以分块 update
print(f"MD5('Hello World'): {m_md5.hexdigest()}")

# 2. SHA-256 示例
m_sha256 = hashlib.sha256()
m_sha256.update(b"Hello World")
print(f"SHA-256('Hello World'): {m_sha256.hexdigest()}")

# 3. 演示“雪崩效应”
# 只改变一个bit (W -> w)
m_sha256_2 = hashlib.sha256()
m_sha256_2.update(b"Hello world")
print(f"SHA-256('Hello world'): {m_sha256_2.hexdigest()}")
# 观察：输出完全不同
```

**CTF中的哈希**：
- **MD5碰撞**：题目可能会利用MD5的已知碰撞（在线查MD5原像：[https://www.cmd5.com/](https://www.cmd5.com/)）。
- **长度扩展攻击 (Length Extension Attack)**：针对 `H(secret + message)` 这种结构的哈希（如MD5, SHA-1, SHA-2）。如果你知道 `H(secret + m1)` 和 `len(secret)`，你可以*不知道secret*的情况下，计算出 `H(secret + m1 + padding + m2)`。

### 长度扩展攻击（Length Extension Attack, LEA）

长度扩展攻击是一种针对特定哈希函数（特别是基于 **Merkle-Damgård 结构**）的攻击。

  * **受影响的函数**：MD5, SHA-1, SHA-256, SHA-512 等。
  * **不受影响的函数**：SHA-3 (Keccak)（因为它使用 "海绵" 结构）、BLAKE2 以及 **HMAC** 结构 (如 `HMAC-SHA256`)。
  * **攻击目标**：`H(secret + message)` 这种“密钥前缀”的MAC（消息认证码）构造。

要理解 LEA，必须先理解 **Merkle-Damgård (MD) 结构** 的哈希函数（如MD5, SHA-1, SHA-2）是如何工作的。

#### 1. MD 结构：迭代与内部状态

MD 哈希函数将消息分成固定大小的**块 (Block)**（例如 SHA-256 为 64 字节），然后进行迭代处理：

1.  **初始化 (IV)**：哈希函数从一个固定的**初始内部状态** (Initialization Vector, IV) 开始。这个 IV 对 SHA-256 来说是一组 8 个 32-bit 整数。
2.  **迭代压缩**：
    * `State_1 = Compress(IV, Block_1)`
    * `State_2 = Compress(State_1, Block_2)`
    * `State_N = Compress(State_{N-1}, Block_N)`
3.  **最终哈希**：**最终的哈希值就是最后一个内部状态 (State\_N)。**

#### 2. 消息填充 (Padding)

在处理之前，哈希函数必须对消息进行填充，使其长度符合要求：

1.  **追加 `0x80`**：在消息末尾添加一个 `1` 位（即 `0x80` 字节）。
2.  **追加 `0x00`**：添加 K 个 `0` 字节，直到消息总长度模 64（或 128）等于 56。
3.  **追加长度**：在末尾追加 8 字节（64-bit）的**原始消息长度（bit 为单位）**。

**示例**：
`message = "ABC"` (3 字节)
`padded = "ABC" + 0x80 + (52个 0x00) + 0x00...0x18` (3\*8=24=0x18)
`padded` 总共 64 字节（1个块）。

#### 3. 哈希值即是状态

**攻击者已知**：

1.  `H(secret + message_1)`：一个已知的哈希值（例如一个API令牌）。
2.  `len(secret)`：秘密的长度（**这是关键**，通常在CTF中可以爆破）。
3.  `message_1`：原始消息（例如 `user=guest`）。

**攻击者想计算**：
`H(secret + message_1 + padding + message_2)`，其中 `message_2` 是攻击者想追加的新数据（例如 `\&admin=true`）。

**攻击步骤**：

1.  **问题**：攻击者不知道 `secret`，所以他无法计算 `secret + message_1` 的总长度，也就无法计算出正确的 `padding`。
2.  **解决**：攻击者**知道 `len(secret)`**。因此，他可以计算出**原始总长度**：`L = len(secret) + len(message_1)`。
3.  **重构填充**：攻击者根据长度 `L`，**自己**在本地计算出哈希函数为 `secret + message_1` 所添加的**原始填充 (padding)**。
4.  **状态注入**：
    * 我们知道 `H(secret + message_1)` 是哈希函数在处理完 `secret + message_1 + padding` 后的**最终内部状态**。
    * 攻击者可以将这个**已知的哈希值**（`H(secret + message_1)`）**"注入"** 到一个新的哈希函数实例中，作为它的**初始状态 (IV)**。
5.  **追加攻击**：
    * 攻击者用这个 "被篡改" 的初始状态去哈希他的新消息 `message_2`。
    * 哈希函数将计算 `Compress((H(secret+m1)), Block_of_m2)`。
    * 由于 MD 结构的迭代性，这在数学上等价于计算 `H(secret + message_1 + padding + message_2)`。

**结果**：
攻击者**在不知道 `secret` 的情况下**，成功计算出了一个新消息 `message_1 + padding + message_2`（前缀是 `secret`）的有效哈希值。

工具：`hashpumpy` 库。


## 雪崩效应 (Avalanche Effect)
<details>
<summary> 雪崩效应补充内容</summary>

**定义**：雪崩效应是指加密算法（或哈希函数）的一个理想属性，即**输入的微小变化（例如，翻转一个比特位）会导致输出发生巨大且不可预测的变化（理想情况下，约有50%的比特位会翻转）**。

这个概念由Horst Feistel提出，是**香农 (Claude Shannon)** 提出的**混淆 (Confusion)** 和 **扩散 (Diffusion)** 两个属性的直观体现。

- **混淆 (Confusion)**：使密钥与密文之间的关系尽可能复杂。
    - (AES中的 `SubBytes` S盒主要用于此)
- **扩散 (Diffusion)**：使明文中的单个比特的影响扩散到尽可能多的密文比特上。
    - (AES中的 `ShiftRows` 和 `MixColumns` 主要用于此)

**雪崩效应是混淆和扩散的最终结果。**

- **如果一个算法没有雪E崩效应**：攻击者可以通过观察输入和输出的*差异*来推断输入（或密钥）的信息。例如，如果 `Hash("...abc")` 和 `Hash("...abd")` 的输出只有最后2位不同，这显然泄露了输入的结构。
- **如果一个算法具有雪崩效应**：如 `SHA-256("Hello World")` 和 `SHA-256("Hello world")` 的例子所示，输出完全不同，看起来是两个不相关的随机字符串。这使得攻击者无法从差异中获得任何有用的信息。

**示例**：

```python
import hashlib

h1 = hashlib.sha256(b"Hello World").hexdigest()
h2 = hashlib.sha256(b"Hello world").hexdigest()

print(f"Input 1: 'Hello World'")
print(f"Hash 1:  {h1}")
print(f"Input 2: 'Hello world'")
print(f"Hash 2:  {h2}")

# 计算汉明距离 (有多少位不同)
h1_bin = bin(int(h1, 16))[2:].zfill(256)
h2_bin = bin(int(h2, 16))[2:].zfill(256)

diff_bits = sum(b1 != b2 for b1, b2 in zip(h1_bin, h2_bin))
print(f"\nBits changed: {diff_bits} / 256")
print(f"Percentage:   {diff_bits / 256.0 * 100:.2f}%")
```

</details>
