# rm01 —— 机器人任务提交仓库

本仓库用于提交机器人相关课程任务（C++ / ROS 等）。**一个任务一个目录，不同 task 不需要分到不同 branch**，全部提交在 `main` 分支上即可。

- 仓库地址：<https://github.com/ahr20262/rm01>
- 提交记录文档：[task1/任务提交处.md](task1/任务提交处.md)

---

## 一、任务文件存放格式（树状结构）

```text
rm01/
├── README.md                           # 本文件：仓库说明 + 存放格式（树状结构）
└── task1/                              # 任务一
    ├── commands.md                     # 操作命令记录
    ├── 任务提交处.md                     # 任务提交处：仓库链接粘贴处
    ├── environment/                    # 配置环境
    │   ├── env-setup-notes.md          # 环境配置记录
    │   └── screenshots/                # 环境配置截图（2 张 jpg，已在仓库中，本次不修改）
    └── cpp/                            # C++ 部分
        └── 1/                          # 入门一：C++ 基础输入输出练习
            ├── README.md               # 入门一说明：文件清单、编译运行、验证结果
            ├── cpp/                    # 源代码目录（每个程序一个 .cpp）
            │   ├── 1.cpp               # 字符输入输出（ASCII 码 -32 转大写）
            │   ├── 2.cpp               # 浮点数输入输出 + 定点小数格式化
            │   ├── 3.cpp               # Project4（源码待补全）
            │   ├── 4.cpp               # 整数输入 + 算术运算
            │   ├── 5.cpp               # cmath 数学函数（海伦公式求三角形面积）
            │   └── self-test.ps1       # 批量编译 + 与截图结果比对的自测脚本
            └── images/                 # 每个程序的运行结果截图（按题号命名）
                ├── 1-P5704-char-out.png
                ├── 2-P5706-drinks.png
                ├── 3-P1001-console-only.png
                ├── 4-P5703-people.png
                └── 5-P5708-triangle.png
```

### 命名与组织约定

| 约定 | 说明 |
| --- | --- |
| 任务层级 | 根目录下按 `task1/`、`task2/` …… 逐级创建，一个任务一个目录 |
| 任务内分类 | 任务目录下按语言 / 模块分类：`cpp/`、`ros/` 等 |
| 练习层级 | 分类目录下按练习次序用数字目录：`1/`（入门一）、`2/`（入门二）…… |
| 源码 | 每道题一个 `.cpp`，**文件名 = 题号**（`1.cpp`、`2.cpp`……），与 `images/` 中的截图一一对应 |
| 截图 | 统一放在同级 `images/` 目录，命名为 `<题号>-<题目编号>-<功能简述>.png` |
| 说明文件 | 每个练习目录放一个 `README.md`，写明文件清单、环境、编译运行方式和验证结果 |
| 分支 | 所有任务都提交到 `main` 分支，不需要为每个 task 单独建 branch |

---

## 二、已提交内容一览

| 任务 | 目录 | 内容 | 状态 |
| --- | --- | --- | --- |
| task1 | `task1/environment/` | 环境配置（说明 + 配置截图） | 已提交 |
| task1 | `task1/cpp/1/` | 入门一：5 个 C++ 基础练习（源码 + 截图 + 自测脚本） | 已提交（其中 `3.cpp` 源码待补全） |
| task1 | `task1/commands.md`、`task1/任务提交处.md` | 操作命令记录、任务提交处（仓库链接） | 已提交 |
| task2 | `task2/` | 待完成 | 未提交 |

---

## 三、快速开始

```powershell
git clone https://github.com/ahr20262/rm01.git
cd rm01\task1\cpp\1\cpp

# 用 Visual Studio 直接打开单个 .cpp 编译运行，或用 MSVC 命令行：
cl /nologo /EHsc /utf-8 1.cpp /Fe:1.exe
.\1.exe

# 一键编译并自测全部练习（对比截图中的运行结果）
powershell -ExecutionPolicy Bypass -File .\self-test.ps1
```
