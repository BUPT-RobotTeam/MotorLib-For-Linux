#include "bupt_can.h"
#include "dji_board.h"
#include <chrono>
#include <thread>
#include <iostream>

int main()
{
    std::shared_ptr<Can> can_handle = std::make_shared<Can>("can0");
    DJIBoard board(1,can_handle);
    board.VelCfg(1);
    board.MotorOn(1);
    int vel=0;
    int step=10;
    while (true)
    {
        board.VelCtrl(1,vel);
        vel+=step;
        if (vel==500||vel==-500) step=-step;
        std::cout<<"current speed"<<vel<<std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
    return 0;
}