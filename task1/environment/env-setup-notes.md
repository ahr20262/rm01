# 环境配置记录

## 目录初始化
cd ~
mkdir -p task-submit/task1/environment
cd task-submit
ls -R

## 关联远程仓库
cd ~
rm -rf task-submit
git clone https://github.com/ahr20262/rm01.git

---

# 任务五：ROS 2 通信机制验证（Docker 容器内）

在 Docker 容器中完成 ROS 2 节点的构建与运行，分别验证 **话题（Topic）/ 服务（Service）/ 动作（Action）** 三种通信方式，以及自定义节点的编译运行。

## 5.1 话题通信（发布 / 订阅）

两个终端分别运行发布者与订阅者：

- 发布端持续输出：`[INFO] [时间戳] [item_publisher]: 发布: item_id=99, info=hello lyrical`
- 订阅端同时输出：`[INFO] [时间戳] [item_subscriber]: 收到: item_id=99, info=hello lyrical`

结论：发布/订阅链路正常，订阅端收到的 `item_id`、`info` 与发布端一致。

截图：[screenshots/ROS2-topic-pubsub.jpg](screenshots/ROS2-topic-pubsub.jpg)

## 5.2 服务通信（斐波那契服务）

先构建再分别运行服务端与客户端：

- 构建：`colcon build` → `Finished <<< fib_demo [3.08s]`、`Summary: 1 package finished [3.17s]`
- 客户端：`ros2 run fib_demo fib_client`
  - `[fib_client]: [斐波那契客户端] 启动`
  - `[fib_client]: [客户端] 发送请求：想要第1项` → `[客户端] 收到返回值：1`
  - 依次请求第 2~6 项，返回值 `1, 1, 2, 3, 5, 8` → `[fib_client]: 全部请求完成!`
- 服务端：`ros2 run fib_demo fib_server`
  - `[fib_server]: [斐波那契服务端] 启动成功，等待请求`
  - `[fib_server]: [服务端] 收到第1项请求，返回结果：1` …… 第 6 项返回 8

结论：服务的请求/响应机制正常，返回值与斐波那契数列一致。

截图：[screenshots/ROS2-service-fib-demo.jpg](screenshots/ROS2-service-fib-demo.jpg)

## 5.3 动作通信（累加求和 Action）

动作客户端与服务端同时运行：

- 客户端：`ros2 run sum_action_demo action_client`
  - `[sum_action_client]: 发送目标：累加到 10`
  - 连续收到反馈：`当前数字: 1`, `当前和=1`；`当前数字: 2`, `当前和=3` …… `当前数字: 10`, `当前和=55`
  - `[sum_action_client]: ✅任务成功！最终累加总和 = 55`
- 服务端：`ros2 run sum_action_demo action_server`
  - `[sum_action_server]: 收到目标请求：累加到 10`
  - 逐次反馈：`[服务端反馈] 正在累加: 1, 当前和=1` …… `正在累加: 10, 当前和=55`
  - `[sum_action_server]: ✅全部累加完成，最终总和=55`

结论：动作的目标/反馈/结果三段式通信正常，客户端与服务端反馈的累加过程与最终结果（55）一致。

截图：[screenshots/ROS2-action-sum-demo.jpg](screenshots/ROS2-action-sum-demo.jpg)

## 5.4 自定义节点编译运行（hello_world_node）

- 容器提示符：`root@ab2b0c85b21c`（Docker 容器）
- 工作目录：`~/docker_code/ros2_cpp_node`
- 构建：`colcon build` → 输出 `Summary: 1 package finished [2.40s]`
- 运行：`source install/setup.bash && ros2 run hello_world_node hello_pub`
- 运行现象：`[INFO] [时间戳] [minimal_publisher]: Publishing: 'Hello World: 0'`、`'Hello World: 1'` …… 持续递增发布，说明节点编译成功并正常发布话题消息

截图：[screenshots/ROS2-hello-world-node.jpg](screenshots/ROS2-hello-world-node.jpg)
