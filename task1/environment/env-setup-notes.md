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

## ROS 2 环境验证（Docker 容器内）

在 Docker 容器中构建并运行自定义 ROS 2 节点，确认环境配置可用：

- 容器提示符：`root@ab2b0c85b21c`（Docker 容器）
- 工作目录：`~/docker_code/ros2_cpp_node`
- 构建：`colcon build` → 输出 `Summary: 1 package finished [2.40s]`
- 运行：`source install/setup.bash && ros2 run hello_world_node hello_pub`
- 运行现象：`[INFO] [时间戳] [minimal_publisher]: Publishing: 'Hello World: 0'`、`'Hello World: 1'` …… 持续递增发布，说明节点编译成功并正常发布话题消息

截图见：[screenshots/ROS2-hello-world-node.jpg](screenshots/ROS2-hello-world-node.jpg)
