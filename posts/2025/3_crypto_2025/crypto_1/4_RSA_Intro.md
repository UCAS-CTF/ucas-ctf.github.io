# 公钥密码体制与RSA

**对称密码的困境**：如何安全地在通信双方之间共享密钥？如果信道是不安全的，我怎么把AES密钥发给你？

**公钥密码体制（Public-Key Cryptography, PKC）** 的革命性思想：

- **密钥对**：每个人都有一对密钥：**公钥 (Public Key)** 和 **私钥 (Private Key)**。
- **公钥 ($pk$)**：可以公开给任何人。
- **私钥 ($sk$)**：必须严格保密。
- **加密**：使用**公钥**加密。 $C = E_{pk}(M)$
- **解密**：使用**私钥**解密。 $M = D_{sk}(C)$

> **公钥密码体制将加密与解密的密钥利用假定的计算困难问题分割开了。**

### 数学基础快扫

#### 1. 整除与同余 (Divisibility & Congruence)

- **同余**：$a \equiv b \pmod{n}$ (读作 "$a$ 同余 $b$ 模 $n$" 或 "$a$ 与 $b$ 模 $n$ 同余")
- **含义**：$a$ 和 $b$ 除以 $n$ 的**余数相同**。
- **等价**：$n \mid (a-b)$ (即 $n$ 能整除 $a-b$)。
- **运算**：同余式可以进行加、减、乘法。
    - 若 $a \equiv b \pmod{n}$ 且 $c \equiv d \pmod{n}$
    - 则 $a+c \equiv b+d \pmod{n}$
    - 且 $a \times c \equiv b \times d \pmod{n}$
- **模逆元 (Modular Inverse)**：
    - "模除法"。我们想找一个 $x$ 使得 $a \cdot x \equiv 1 \pmod{n}$。
    - 这个 $x$ 称为 $a$ 在模 $n$ 下的**逆元**，记为 $a^{-1}$。
    - **存在条件**：$a$ 和 $n$ **互质** (即 $\gcd(a, n) = 1$)。
    - **计算**：使用**扩展欧几里得算法 (Extended Euclidean Algorithm, E-GCD)**。
- **代码实现上的常见问题**：
    - 未判定大小
    - 未判定负数

#### 2. 费马小定理 (Fermat's Little Theorem)
- **条件**：$p$ 是一个**素数**， $a$ 是一个整数且 $p \nmid a$ ( $a$ 不是 $p$ 的倍数)。
- **结论**：
$$a^{p-1} \equiv 1 \pmod{p}$$
- **代码实现上的常见问题**：
    - **未判定素数**
    - **未判定倍数**

#### 3. 欧拉定理 (Euler's Theorem)
- **费马小定理的推广**。
- **欧拉函数 $\phi(n)$**：(读作 "phi")。表示小于 $n$ 且与 $n$ **互质**的正整数的个数。
    - 若 $p$ 是素数，$\phi(p) = p-1$。
    - 若 $n = p \cdot q$ 且 $p, q$ 是不同的素数，$\phi(n) = \phi(p) \cdot \phi(q) = (p-1)(q-1)$。
    - 若 $n = \prod\limits_{i=1}^k p_i^{\alpha_i}$ 为 $n$ 的标准素因子分解，那么 $\phi(n) = n\cdot \prod\limits_{i = 1}^{k}\left( 1 - \dfrac{1}{p_i} \right)$
    - 欧拉函数是一个**积性函数**（不是完全积性函数）。
- **欧拉定理**：
    - **条件**： $a$ 和 $n$ 为正整数，且 $\gcd(a, n) = 1$ ( $a, n$ 互质)。
    - **结论**：$$a^{\phi(n)} \equiv 1 \pmod{n}$$
- **代码实现上的常见问题**：
    - **未判定互素**

#### 4. 中国剩余定理 (Chinese Remainder Theorem, CRT)
- 解决"物不知数"问题——一组关于多个两两互质的模数的同余方程组
- **定理描述**：设 $m_1, m_2, \ldots, m_k$ 是两两**互质**的大于1的整数。则对于任意的整数 $a_1, a_2, \ldots, a_k$，同余方程组：
    $$
    \begin{cases}
    x \equiv a_1 \pmod{m_1} \\
    x \equiv a_2 \pmod{m_2} \\
    \vdots \\
    x \equiv a_k \pmod{m_k}
    \end{cases}
    $$
    在模 $M = m_1 m_2 \cdots m_k$ 下有**唯一解**

- 求解步骤
    1. 计算总模数 $M = m_1 \times m_2 \times \cdots \times m_k$
    2. 对每个 $i$，计算 $M_i = M / m_i$
    3. 对每个 $i$，计算 $M_i$ 在模 $m_i$ 下的逆元 $y_i$（即 $M_i y_i \equiv 1 \pmod{m_i}$）
    4. 方程组的唯一解为：$$x \equiv a_1 M_1 y_1 + a_2 M_2 y_2 + \cdots + a_k M_k y_k \pmod{M}$$

### RSA密码体制

由 Rivest, Shamir, Adleman 三位在1977年提出，是第一个实用的公钥密码系统。

**安全性**：基于**大整数分解的困难性**。
(即：给你两个大素数 $p$ 和 $q$，计算 $n=pq$ 很容易。但给你 $n$，想反向分解出 $p$ 和 $q$ 是极其困难的。)

#### 1. 密钥生成 (Key Generation)

1.  **选择素数**：随机选择两个**不同**的、足够大的素数 $p$ 和 $q$。
    - (使用 `getPrime` 函数)
2.  **计算模数**：计算 $n = p \cdot q$。 $n$ 是公钥和私钥的一部分。
3.  **计算欧拉函数**：计算 $\phi(n) = (p-1)(q-1)$。 $\phi(n)$ 必须**保密**。
4.  **选择公钥指数 $e$**：
    - 选择一个整数 $e$，使得 $1 < e < \phi(n)$ 并且 $\gcd(e, \phi(n)) = 1$。
    - ( $e$ 通常选择一个小值，如 $65537$ (即 $2^{16}+1$)，以加快加密速度)。
5.  **计算私钥指数 $d$**：
    - 计算 $e$ 模 $\phi(n)$ 的**模逆元 $d$**。
    - $d \cdot e \equiv 1 \pmod{\phi(n)}$
    - (使用 `inverse(e, phi)` 函数)
6.  **打包**：
    - **公钥 ($pk$)** = $(n, e)$ (公开)
    - **私钥 ($sk$)** = $(n, d)$ (保密) (有时也包含 $p, q$ 等用于CRT)

#### 2\. 加密 (Encryption)
- 假设明文 $m$ 是一个小于 $n$ 的整数。 (如果消息长，需要先 `bytes_to_long`)
- **密文 $c$**：$$c = m^e \pmod{n}$$

#### 3\. 解密 (Decryption)
- 收到密文 $c$。
- **明文 $m$**：$$m = c^d \pmod{n}$$

### RSA密码体制正确性的证明

**目标**：证明 $m = (m^e)^d \pmod{n}$

**证明**：
1.  根据解密公式：$c^d \equiv (m^e)^d \equiv m^{ed} \pmod{n}$
2.  根据私钥 $d$ 的定义，我们知道：$ed \equiv 1 \pmod{\phi(n)}$
3.  这意味着 $ed$ 可以写成 $ed = k \cdot \phi(n) + 1$，对于某个整数 $k$。
4.  代入 (1) 中：$m^{ed} \equiv m^{k\phi(n) + 1} \equiv m \cdot (m^{\phi(n)})^k \pmod{n}$
5.  **情况一 (主要情况)**： $m$ 与 $n$ 互质，即 $\gcd(m, n) = 1$。
    - 根据**欧拉定理**，$m^{\phi(n)} \equiv 1 \pmod{n}$。
    - 代入 (4) 中：$m \cdot (1)^k \equiv m \pmod{n}$。
    - **证明成立**。
6.  **情况二 (特殊情况)**： **$m$ 与 $n$ 不互质**。
    - 因为 $n = pq$，这说明 $m$ 是 $p$ 的倍数或 $q$ 的倍数 (比如 $m=ap$ )。
    - (此情况使用中国剩余定理和费马小定理也可以证明，结果依然成立。此处略过，但结论是：**RSA对所有 $m \in [0, n-1]$ 都成立**。)

### RSA Python 代码示例

```python
from Crypto.Util.number import*
class my_RSA:
    def gen_n(BITS):
        p = getPrime(BITS)
        q = getPrime(BITS)
        n = p * q
        return n, p, q

    def encrypt(plaintext, e, n):
        m = bytes_to_long(plaintext)
        c = pow(m, e, n)
        return c

    def decrypt(p, q, e, n, c):
        phi = (p - 1) * (q - 1)
        d = inverse(e, phi)
        m = pow(c, d, n)
        pt = long_to_bytes(m)
        return pt

plaintext=b"test_RSA"
n, p, q = my_RSA.gen_n(32)
e = 0x10001
print("public key = ", (n, e))
print("c = ", my_RSA.encrypt(plaintext, e, n))
print("Your plaintext is: ", my_RSA.decrypt(p, q, e, n, my_RSA.encrypt(plaintext, e, n)))
```
