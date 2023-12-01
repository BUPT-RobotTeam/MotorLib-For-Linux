#include "bupt_can/bupt_can.h"
#include "motor_lib/vesc_board.h"
#include <thread>
#include <iostream>

int main()
{
    std::shared_ptr<Can> can_handle = std::make_shared<Can>("vcan0");
    VESCBoard vesc(1, can_handle);
    can_handle->can_start();
    
    // 占空比测试
    std::cout<<"Duty test"<<std::endl;
    vesc.SetDuty(0.5);
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));

    vesc.SetDuty(0);
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));

    vesc.SetDuty(-0.5);
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));

    vesc.SetDuty(0);
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));

    // 电流环测试
    std::cout<<"Current test"<<std::endl;
    vesc.SetCurrent(0.5);
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));

    vesc.SetCurrent(0);
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));

    vesc.SetCurrent(-0.5);
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));

    vesc.SetCurrent(0);
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));

    //速度环测试
    std::cout<<"RPM test"<<std::endl;
    vesc.SetRPM(1000);
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));

    vesc.SetRPM(0);
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));

    vesc.SetRPM(-1000);
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));

    vesc.SetRPM(0);
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));

    //位置环测试
    std::cout<<"Pos test"<<std::endl;
    vesc.SetPos(120);
    std::this_thread::sleep_for(std::chrono::microseconds(1000));

    vesc.SetPos(0);
    std::this_thread::sleep_for(std::chrono::microseconds(1000));

    vesc.SetPos(-120);
    std::this_thread::sleep_for(std::chrono::microseconds(1000));

    vesc.SetPos(0);
    std::this_thread::sleep_for(std::chrono::microseconds(1000));


    return 0;
}