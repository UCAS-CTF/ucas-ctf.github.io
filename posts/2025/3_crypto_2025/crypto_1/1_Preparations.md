# **零**：环境准备

本次课我们主要使用Python，尽量使用3.9以上版本。


请大家安装以下常见的库：
  - **gmpy2**: `pip install gmpy2`
      - 常用函数：`gmpy2.iroot` (开方), `gmpy2.next_prime` (下一个素数), `gmpy2.is_prime` (素性测试), `gmpy2.invert` (求逆)
  - **Crypto**: `pip install pycryptodome`
      - 常用函数：`Crypto.Util.number` 模块下的 `getPrime` (获取素数), `isPrime` (素性测试), `bytes_to_long` (字节转长整数), `long_to_bytes` (长整数转字节), `inverse` (求逆), `GCD` (最大公约数)
      - 常用函数：`Crypto.Cipher` 模块 (如 `AES`), `Crypto.Hash` 模块 (如 `SHA256`)

```python
# 检查环境是否配置成功
import gmpy2
from Crypto.Util import number
from Crypto.Cipher import AES

print("gmpy2 loaded:", gmpy2.version())
print("pycryptodome loaded:", number.getPrime(10))
print("AES available:", AES.new(b'This is a key16', AES.MODE_ECB))
```

# **一**、前置知识介绍

## （一）CTF 密码学（Crypto）方向

CTF竞赛中的Crypto方向是涉及密码学相关挑战和任务的部分。包括密码分析、对称加密、非对称加密、数字签名和认证以及编码与编码理论等方面的问题。参赛者需要通过解密密文、破解算法、验证数字签名等方式来应对密码学挑战。参与Crypto方向的CTF竞赛需要对密码学的原理和常见算法有一定了解，并具备数学和逻辑思维能力。通过解决这些密码学问题，参赛者可以提高对密码学知识的理解，同时也锻炼密码学相关问题的解题能力。

## （二）密码学简介

密码学是研究编制密码和破译密码的科学。（**将秘密消息进行数学变换，使得通信双方可以得到应当得到的消息，而攻击者无法在通信交互过程中获得，就算他获得了变换后的消息。**）

关键词：
- 秘密消息：**明文（Plaintext）**
- 变换中所使用的关键参数：**密钥（Key）**（一旦遗失便无法恢复明文）
- 变换后的消息：**密文（Ciphertext）**
- 变换：**加密**与**解密**
- 通信交互过程：**协议（Protocol）**

$$
\textbf{密码体制} = \textbf{明文} + \textbf{密文} + \textbf{密钥} + \textbf{加密算法} + \textbf{解密算法}
$$

它涉及设计、分析和应用加密算法以及相关的通信协议和系统。**密码学的主要目标是确保在不安全的环境中传递敏感信息时，能够保证信息的机密性、完整性和身份验证（不可否认性）。**

其主要包括两个核心方面：加密和解密。

- **加密（Encrypt-Encryption）**：将原始数据转化为无法理解或解读的形式，以保证数据在传输或存储过程中不被未经授权的人所访问或修改。
- **解密（Decrypt-Decryption）**：将加密后的数据恢复成可读的原始格式。

**保密通信系统模型（Secure Communication System Model）**：

![Secure Communication System Model](./posts/2025/3_crypto_2025/crypto_1/img/SCSM.png)

密码一般分为**对称密码**和**非对称密码**两种基本类型。

- **对称密码（Symmetric Cryptography）**：使用同一个密钥进行加密和解密，速度较快，但需要安全地共享密钥。
- **非对称密码（Public-Key Cryptography, PKC）**：使用公钥进行加密，私钥进行解密，相对更安全，但速度较慢。

除了加密和解密，密码学还涉及 **数字签名（Digital Signature）、哈希函数（Hash Function常常认为哈希也属于对称密码领域，因其设计与分析方式的相通性）、密钥交换协议（Key Exchange, KEX）、密钥封装机制（Key-Ecapsulation Mechanism, KEM）、零知识证明（Zero-Knowledge Proof, ZKP）、安全多方计算（secure Multi-Party Computation, MPC）** 等其他关键概念和方法。数字签名用于验证数据的完整性和真实性，哈希函数用于生成固定长度的摘要以验证数据完整性，密钥交换协议用于安全地共享密钥等。


> **口令、隐写、密码？**
>
>   - **口令（Password）**：用于身份认证，证明“你是谁”。
>   - **隐写（Steganography）**：隐藏消息的存在性，比如在图片、音频中隐藏信息。
>   - **密码（Cryptography）**：隐藏消息的内容，消息本身是可见的（密文），但其含义是不可读的。
