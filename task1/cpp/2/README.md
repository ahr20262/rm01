# 入门二 —— C++ 条件判断与分支练习

本目录存放「入门二」的 5 个 C++ 练习：源码、运行结果截图，以及一个可一键编译并自测的脚本。

## 一、文件清单

```text
2/
├── README.md                       # 本文件
├── cpp/                            # 源代码
│   ├── 1.cpp                       # 闰年判断                       ← images/1-P5711-leap-year.png
│   ├── 2.cpp                       # 逻辑运算符组合条件输出 0/1       ← images/2-P5710-conditions.png
│   ├── 3.cpp                       # BMI 计算与多分支判断            ← images/3-P5714-bmi.png
│   ├── 4.cpp                       # 简单 if-else 分支与字符串输出    ← images/4-P5712-apples.png
│   ├── 5.cpp                       # 整数除法（向下取整）            ← images/5-P5709-eat-speed.png
│   └── self-test.ps1               # 批量编译 + 与截图结果比对
└── images/                         # 各题运行结果截图（按题号命名）
```

## 二、各题说明

| 序号 | 源文件 | 题目编号 | 功能 | 知识点 | 验证结果 |
| --- | --- | --- | --- | --- | --- |
| 1 | [cpp/1.cpp](cpp/1.cpp) | P5711 | 输入年份，闰年输出 1，否则输出 0 | `if-else`、取模 `%`、`&&`、`!=` | 编译通过，输出与截图一致 |
| 2 | [cpp/2.cpp](cpp/2.cpp) | P5710 | 输入整数 a，按 4 组条件分别输出 0/1 | `&&`、`\|\|`、`!` 与运算符优先级 | 编译通过，输出与截图一致 |
| 3 | [cpp/3.cpp](cpp/3.cpp) | P5714 | 输入体重、身高，按 BMI 输出体重状态 | `double`、多分支 `if / else if / else`、`setprecision` | 编译通过，输出与截图一致 |
| 4 | [cpp/4.cpp](cpp/4.cpp) | P5712 | 输入苹果个数，输出 "Today, I ate N apples" | `if-else` 分支、字符串与变量混合输出 | 编译通过，输出与截图一致 |
| 5 | [cpp/5.cpp](cpp/5.cpp) | P5709 | 输入苹果数、耗时、速度，输出还能吃几个 | `int` 整数除法（自动向下取整）、多变量 `cin` | 编译通过，输出与截图一致 |

## 三、运行结果（与 `images/` 截图一致）

| 序号 | 输入 | 程序输出 |
| --- | --- | --- |
| 1 | `1900` | `年份为`、`0` |
| 2 | `12` | `1`、`1`、`0`、`0` |
| 3 | `100`、`1.68` | `35.4308`、`overweight` |
| 4 | `3` | `Today, I ate 3 apples` |
| 5 | `50`、`10`、`200` | `输入🍎，耗时，已过`、`30` |

> 截图里出现的数字输入行（如 `12`、`100`、`1.68`）是控制台回显，不属于程序输出。

## 四、编译环境

| 项目 | 内容 |
| --- | --- |
| IDE | Microsoft Visual Studio（Community），x64 |
| 编译器 | MSVC（`cl.exe`） |
| 语言标准 | C++14 及以上（默认即可） |
| 源文件编码 | UTF-8（含中文/emoji 提示文字，编译时建议加 `/utf-8`；VS 中可直接编译运行） |

## 五、编译与运行

**方式一：Visual Studio**
新建空项目 → 把某个 `.cpp` 添加进源文件 → `Ctrl+F5` 运行。

**方式二：MSVC 命令行**（在「x64 Native Tools Command Prompt for VS」中）

```powershell
cd rm01\task1\cpp\2\cpp
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
[3.cpp] 编译通过，输出与截图一致
[4.cpp] 编译通过，输出与截图一致
[5.cpp] 编译通过，输出与截图一致

自测结果：通过 5 个，未通过 0 个
```

## 六、需要说明的两处

1. **`3.cpp` 与 `5.cpp` 补充了表头文件**：截图顶部被裁掉或代码区只剩部分行，其中 `3.cpp` 用到了 `setprecision`（声明在 `<iomanip>` 中），因此按标准补上了 `#include <iomanip>`；`5.cpp` 补上 `<iostream>` 之外的默认写法，未改动任何逻辑。
2. **`4.cpp` 的 `if (a > 1)` 两个分支输出内容相同**：这是截图中原样的写法（两个分支都输出 `Today, I ate N apples`，仅在 `else` 分支里词间距少一个空格），此处按截图原样保留，未擅自精简。
