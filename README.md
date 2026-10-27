# rm01 —— 机器人任务提交仓库

本仓库用于提交机器人相关课程任务（C++ / ROS 等）。**一个任务一个目录，不同 task 不需要分到不同 branch**，全部提交在 `main` 分支上即可。

- 仓库地址：<https://github.com/ahr20262/rm01>
- 提交记录文档：[task1/任务提交处.md](task1/任务提交处.md)

---

## 一、任务文件存放格式（树状结构）

```text
rm01/
├── README.md                           # 本文件：仓库说明 + 存放格式（树状结构）
├── .gitignore                          # 忽略编译中间产物（build/、*.obj、*.exe 等）
└── task1/                              # 任务一
    ├── commands.md                     # 操作命令记录
    ├── 任务提交处.md                     # 任务提交处：仓库链接粘贴处
    ├── environment/                    # 配置环境
    │   ├── env-setup-notes.md          # 环境配置记录
    │   ├── 2fa9e0820b772bc50cc407ce0fda56be.mp4   # 环境配置过程演示视频
    │   └── screenshots/                # 环境配置截图
    │       ├── 微信图片_20260928001244_1_2.jpg
    │       ├── 微信图片_20260928002409_2_2.jpg
    │       ├── ROS2-topic-pubsub.jpg       # 任务五：话题发布/订阅
    │       ├── ROS2-service-fib-demo.jpg   # 任务五：服务（斐波那契）
    │       ├── ROS2-action-sum-demo.jpg    # 任务五：动作（累加求和）
    │       └── ROS2-hello-world-node.jpg   # 任务五：自定义节点编译运行
    └── cpp/                            # C++ 部分
        ├── 1/                          # 入门一：C++ 基础输入输出练习
        │   ├── README.md               # 入门一说明：文件清单、编译运行、验证结果
        │   ├── cpp/                    # 源代码目录（每个程序一个 .cpp）
        │   │   ├── 1.cpp               # 字符输入输出（ASCII 码 -32 转大写）
        │   │   ├── 2.cpp               # 浮点数输入输出 + 定点小数格式化
        │   │   ├── 3.cpp               # 整数加法（Project4 / P1001）
        │   │   ├── 4.cpp               # 整数输入 + 算术运算
        │   │   ├── 5.cpp               # cmath 数学函数（海伦公式求三角形面积）
        │   │   └── self-test.ps1       # 批量编译 + 与截图结果比对的自测脚本
        │   └── images/                 # 每个程序的运行结果截图（按题号命名）
        │       ├── 1-P5704-char-out.png
        │       ├── 2-P5706-drinks.png
        │       ├── 3-P1001-console-only.png
        │       ├── 3-P1001-full-code.png      # 含完整代码的 Project4 截图
        │       ├── 4-P5703-people.png
        │       └── 5-P5708-triangle.png
        └── 2/                          # 入门二：C++ 条件判断与分支练习
            ├── README.md               # 入门二说明：文件清单、编译运行、验证结果
            ├── cpp/                    # 源代码目录（每个程序一个 .cpp）
            │   ├── 1.cpp               # 闰年判断（if-else、%、&&、!=）
            │   ├── 2.cpp               # 逻辑运算符组合条件输出 0/1
            │   ├── 3.cpp               # BMI 计算与多分支判断
            │   ├── 4.cpp               # 简单 if-else 分支与字符串输出
            │   ├── 5.cpp               # 整数除法（向下取整）
            │   └── self-test.ps1       # 批量编译 + 与截图结果比对的自测脚本
            └── images/                 # 每个程序的运行结果截图（按题号命名）
                ├── 1-P5711-leap-year.png
                ├── 2-P5710-conditions.png
                ├── 3-P5714-bmi.png
                ├── 4-P5712-apples.png
                └── 5-P5709-eat-speed.png
        ├── 3/                          # 入门三：C++ 循环与数组练习
        │   ├── README.md               # 入门三说明：文件清单、编译运行、验证结果
        │   ├── cpp/                    # 源代码目录（每个程序一个 .cpp）
        │   │   ├── 1.cpp               # P5718 求 n 个数中的最小值
        │   │   ├── 2.cpp               # P5720 纸张对折次数
        │   │   ├── 3.cpp               # P5721 数字直角三角形
        │   │   ├── 4.cpp               # P1035 级数求和
        │   │   ├── 5.cpp               # P1423 游泳速度递减求时间
        │   │   └── self-test.ps1       # 批量编译 + 与截图结果比对的自测脚本
        │   └── images/                 # 每个程序的运行结果截图（按题号命名）
        │       ├── 1-P5718-min.png
        │       ├── 2-P5720-fold.png
        │       ├── 3-P5721-triangle.png
        │       ├── 4-P1035-series.png
        │       └── 5-P1423-swim.png
        ├── 4/                          # 入门四：C++ 数组与模拟练习
        │   ├── README.md               # 入门四说明：文件清单、编译运行、验证结果
        │   ├── cpp/                    # 源代码目录（每个程序一个 .cpp）
        │   │   ├── 6.cpp               # P1046 陶陶摘苹果
        │   │   ├── 7.cpp               # P1047 校门外的树
        │   │   ├── 8.cpp               # P1427 小鱼的数字游戏（倒序输出）
        │   │   ├── 9.cpp               # P1428 小鱼比可爱
        │   │   ├── 10.cpp              # P2141 珠心算测验
        │   │   └── self-test.ps1       # 批量编译 + 与截图结果比对的自测脚本
        │   └── images/                 # 每个程序的运行结果截图（按题号命名）
        │       ├── 6-P1046-apples.png
        │       ├── 7-P1047-trees.png
        │       ├── 8-P1427-reverse.png
        │       ├── 9-P1428-compare.png
        │       └── 10-P2141-count.png
        └── 6/                          # 入门六：C++ 结构体专题
            ├── README.md               # 入门六说明：文件清单、编译运行、验证结果
            ├── cpp/                    # 源代码目录（每个程序一个 .cpp）
            │   ├── 1.cpp               # P5738 唱歌比赛（去最高最低分求平均）
            │   ├── 2.cpp               # P5740 最厉害的学生（结构体打擂台）
            │   ├── 3.cpp               # P5741 旗鼓相当的对手
            │   ├── 4.cpp               # P5742 评等级（函数返回字符串）
            │   ├── 5.cpp               # P5744 培训（结构体值传递与返回）
            │   └── self-test.ps1       # 批量编译 + 与截图结果比对的自测脚本
            └── images/                 # 每个程序的运行结果截图（按题号命名）
                ├── 1-P5738-average.png
                ├── 2-P5740-best-student.png
                ├── 3-P5741-rivals.png
                ├── 4-P5742-grade.png
                └── 5-P5744-training.png
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
| task1 | `task1/environment/` | 环境配置（说明 + 配置截图 + 演示视频） | 已提交 |
| task1 | `task1/cpp/1/` | 入门一：5 个 C++ 基础练习（源码 + 截图 + 自测脚本） | 已提交 |
| task1 | `task1/cpp/2/` | 入门二：5 个 C++ 条件判断练习（源码 + 截图 + 自测脚本） | 已提交 |
| task1 | `task1/cpp/3/` | 入门三：5 个 C++ 循环与数组练习（源码 + 截图 + 自测脚本） | 已提交 |
| task1 | `task1/cpp/4/` | 入门四：5 个 C++ 数组与模拟练习（源码 + 截图 + 自测脚本） | 已提交 |
| task1 | `task1/cpp/6/` | 入门六：5 个 C++ 结构体练习（源码 + 截图 + 自测脚本） | 已提交（入门五暂无内容） |
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
