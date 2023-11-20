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

### 2.1 编译

```shell
cd MotorLib-For-Linux
mkdir build
cd build
cmake ..
make
```

### 2.2 运行

```shell
./third_party/bupt_can_node/setup_can.sh
cd MotorLib-For-Linux/build
./motorLibExample
```

这会运行大疆驱动板的客户端例程，将实现的效果是：电机速度从0加速到1000，然后再减速到-1000，然后再加速到1000，如此往复。

**请注意连线问题！连线错误可能会导致烧坏电调！**

## TODO

- ODrive
- VESC
