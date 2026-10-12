# 入门一 —— C++ 基础输入输出练习

本目录存放「入门一」的 5 个 C++ 基础练习：源码、运行结果截图，以及一个可一键编译并自测的脚本。

## 一、文件清单

```text
1/
├── README.md                  # 本文件
├── cpp/                       # 源代码
│   ├── 1.cpp                  # 字符输入输出：ASCII 码 -32 转大写     ← images/1-P5704-char-out.png
│   ├── 2.cpp                  # 浮点数输入输出 + 定点小数格式化        ← images/2-P5706-drinks.png
│   ├── 3.cpp                  # Project4（截图未显示代码，待补全）      ← images/3-P1001-console-only.png
│   ├── 4.cpp                  # 整数输入 + 算术运算                   ← images/4-P5703-people.png
│   ├── 5.cpp                  # cmath 数学函数：海伦公式求三角形面积    ← images/5-P5708-triangle.png
│   └── self-test.ps1          # 批量编译 + 与截图运行结果比对
└── images/                    # 各题运行结果截图（按题号命名）
```

## 二、各题说明

| 序号 | 源文件 | 题目编号 | 功能 | 知识点 | 验证结果 |
| --- | --- | --- | --- | --- | --- |
| 1 | [cpp/1.cpp](cpp/1.cpp) | P5704 | 输入一个小写字母，输出对应大写字母 | `char`、`cin`/`cout`、ASCII 码运算 | 编译通过，输出与截图一致 |
| 2 | [cpp/2.cpp](cpp/2.cpp) | P5706 | 输入饮料总量(升)与人数，输出人均饮料量（保留 3 位小数）和所需杯子总数 | `double`/`int`、`fixed` + `setprecision` | 编译通过，输出与截图一致 |
| 3 | [cpp/3.cpp](cpp/3.cpp) | P1001 | 截图代码区为空，源码待补全 | — | 待补全 |
| 4 | [cpp/4.cpp](cpp/4.cpp) | P5703 | 输入人数，输出需要购买的饮料数（每人 10 瓶） | `int` 输入输出、算术运算 | 编译通过，输出与截图一致 |
| 5 | [cpp/5.cpp](cpp/5.cpp) | P5708 | 输入三角形三边长，输出面积（保留 1 位小数） | `<cmath>` 的 `sqrt`、海伦公式、`setprecision(1)` | 编译通过，输出与截图一致 |

## 三、运行结果（与 `images/` 截图一致）

| 序号 | 输入 | 输出 |
| --- | --- | --- |
| 1 | `h` | `H` |
| 2 | `123`、`23` | `有多少饮料` `有多少人` `每人有5.348` `一共有46杯` |
| 4 | `12` | `有多少人` `要买120` |
| 5 | `3`、`4`、`5` | `a, b, c为` `面积为6.0` |

## 四、编译环境

| 项目 | 内容 |
| --- | --- |
| IDE | Microsoft Visual Studio（Community），x64 |
| 编译器 | MSVC（`cl.exe`） |
| 语言标准 | C++14 及以上（默认即可） |
| 源文件编码 | UTF-8（含中文提示文字，编译时建议加 `/utf-8`；VS 中可直接编译运行） |

## 五、编译与运行

**方式一：Visual Studio**
新建空项目 → 把某个 `.cpp` 添加进源文件 → `Ctrl+F5` 运行。

**方式二：MSVC 命令行**（在「x64 Native Tools Command Prompt for VS」中）

```powershell
cd rm01\task1\cpp\1\cpp
cl /nologo /EHsc /utf-8 1.cpp /Fe:1.exe
.\1.exe
```

**一键自测**（自动定位 `vcvars64.bat`，编译全部源文件并与截图结果比对）

```powershell
powershell -ExecutionPolicy Bypass -File .\self-test.ps1
```

预期输出：

```text
[1.cpp] 编译通过，输出与截图一致
[2.cpp] 编译通过，输出与截图一致
[3.cpp] 编译通过，但源码为占位内容（截图未显示代码），待补全后自测
[4.cpp] 编译通过，输出与截图一致
[5.cpp] 编译通过，输出与截图一致

自测结果：通过 4 个，未通过 0 个，待补全 1 个
```

## 六、需要说明的两处

1. **`2.cpp` 补充了 `#include <iomanip>`**：截图中只有 8 行代码可见，但用到了 `setprecision`，而 `setprecision` 声明在 `<iomanip>` 中；在部分编译器上不包含该头文件会报错，因此按标准补上了这一行，并加了注释说明。
2. **`3.cpp`（Project4 / P1001）源码待补全**：该截图只截到了「Microsoft Visual Studio 调试控制台」窗口和输出面板，代码编辑区是空白的，无法从图片还原源码。已知信息只有：解决方案名为 `Project4`、状态栏显示「行 12, 字符 1、CRLF、UTF-8」（约 12 行代码）、程序退出码 0 且控制台无输出。请提供源码文本或补一张能看到代码区的截图，即可补全。
