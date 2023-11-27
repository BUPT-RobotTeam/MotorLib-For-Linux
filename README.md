# MotorLib-For-Linux

电机驱动库 Linux 版

## 1.介绍

基于BUPT_Roboteam_Libraries的MotorLib开发，迁移至Linux系统下。

## 2.使用方法

### 2.0 获取源码

```shell
git clone https://github.com/BUPT-RobotTeam/MotorLib-For-Linux.git
git submodule update --init --recursive
```

依赖于[BUPT_CAN](https://github.com/nanjo712/bupt_can_node)项目

已经以子模块的形式添加到MotorLib-For-Linux中，你可以再third_party/bupt_can_node目录下找到它。

### 2.1 编译

```shell
cd MotorLib-For-Linux
mkdir build
cd build
cmake ..
make install
```

这将会导出库文件到/usr/local/lib，头文件到/usr/local/include, 你可以通过修改CMakeLists.txt中的`CMAKE_INSTALL_PREFIX`来修改安装路径。

此后如果你需要在ROS中使用，你需要在你的ROS包的CMakeLists.txt中添加：

```cmake
find_package(motor_lib REQUIRED)
```

### 2.2 运行

请在正确设置CAN设备后再运行。

```shell
cd MotorLib-For-Linux/build
./djiBoard_example
```

这会运行大疆驱动板的客户端例程，将实现的效果是：电机速度从0加速到1000，然后再减速到-1000，然后再加速到1000，如此往复。

```shell
./third_party/bupt_can_node/setup_can.sh
cd MotorLib-For-Linux/build
./vescBoard_example
```

这会运行VESC驱动板的客户端例程，对占空比，速度环，位置环，电流环进行测试。

**请注意连线问题！连线错误可能会导致烧坏电调！**

## TODO

- ODrive
- VESC (加入代码未测试)
