#include "motor_lib/dji_board.h"

DJIBoard::DJIBoard(const uint32_t &boardId, const std::shared_ptr<Can> &can_handle)
{
    this->boardId = boardId;
    if (can_handle == nullptr)
    {
        this->can_handle = std::make_shared<Can>("can0");
    }
    else
    {
        this->can_handle = can_handle;
    }
    can_handle->can_start();
}

DJIBoard::~DJIBoard()
{
    
}

void DJIBoard::MotorOn(const uint16_t &motorId)
{
    uint32_t canId = DJI_BASE_ID + boardId;
    std::array<uint8_t, 8> data;
    data[0] = motorId & 0xff;
    data[1] = (motorId >> 8) & 0xff;
    data[2] = MOTORON;
    data[3] = 0;
    can_handle->send_can(canId, Can::CAN_ID_STD, 8, data);
}

void DJIBoard::MotorOff(const uint16_t &motorId)
{
    uint32_t canId = DJI_BASE_ID + boardId;
    std::array<uint8_t, 8> data;
    data[0] = motorId & 0xff;
    data[1] = (motorId >> 8) & 0xff;
    data[2] = MOTOROFF;
    data[3] = 0;
    can_handle->send_can(canId, Can::CAN_ID_STD, 8, data);
}

void DJIBoard::VelCfg(const uint16_t &motorId)
{
    uint32_t canId = DJI_BASE_ID + boardId;
    std::array<uint8_t, 8> data;
    data[0] = motorId & 0xff;
    data[1] = (motorId >> 8) & 0xff;
    data[2] = VELCFG;
    data[3] = 0;
    can_handle->send_can(canId, Can::CAN_ID_STD, 8, data);
}

void DJIBoard::LimitVelCfg(const uint16_t &motorId)
{
    uint32_t canId = DJI_BASE_ID + boardId;
    std::array<uint8_t, 8> data;
    data[0] = motorId & 0xff;
    data[1] = (motorId >> 8) & 0xff;
    data[2] = LIMITVELCFG;
    data[3] = 0;
    can_handle->send_can(canId, Can::CAN_ID_STD, 8, data);
}

void DJIBoard::PosCfg(const uint16_t &motorId, const int &maxPosVel)
{
    uint32_t canId = DJI_BASE_ID + boardId;
    std::array<uint8_t, 8> data;
    data[0] = motorId & 0xff;
    data[1] = (motorId >> 8) & 0xff;
    data[2] = POSCFG;
    data[3] = 0;
    data[4] = maxPosVel & 0xff;
    data[5] = (maxPosVel >> 8) & 0xff;
    data[6] = (maxPosVel >> 16) & 0xff;
    data[7] = (maxPosVel >> 24) & 0xff;
    can_handle->send_can(canId, Can::CAN_ID_STD, 8, data);
}

void DJIBoard::NoInitPosCfg(const uint16_t &motorId, const int &maxPosVel)
{
    uint32_t canId = DJI_BASE_ID + boardId;
    std::array<uint8_t, 8> data;
    data[0] = motorId & 0xff;
    data[1] = (motorId >> 8) & 0xff;
    data[2] = NOINITPOSCFG;
    data[3] = 0; 
    data[4] = maxPosVel & 0xff;
    data[5] = (maxPosVel >> 8) & 0xff;
    data[6] = (maxPosVel >> 16) & 0xff;
    data[7] = (maxPosVel >> 24) & 0xff;
    can_handle->send_can(canId, Can::CAN_ID_STD, 8, data);
}

void DJIBoard::CurCfg(const uint16_t &motorId)
{
    uint32_t canId = DJI_BASE_ID + boardId;
    std::array<uint8_t, 8> data;
    data[0] = motorId & 0xff;
    data[1] = (motorId >> 8) & 0xff;
    data[2] = CURCFG;
    data[3] = 0;
    can_handle->send_can(canId, Can::CAN_ID_STD, 8, data);
}

void DJIBoard::VelCtrl(const uint16_t &motorId, const int32_t &vel)
{
    uint32_t canId = DJI_BASE_ID + boardId;
    std::array<uint8_t, 8> data;
    data[0] = motorId & 0xff;
    data[1] = (motorId >> 8) & 0xff;
    data[2] = VELCTRL;
    data[3] = 0;
    data[4] = vel & 0xff;
    data[5] = (vel >> 8) & 0xff;
    data[6] = (vel >> 16) & 0xff;
    data[7] = (vel >> 24) & 0xff;
    can_handle->send_can(canId, Can::CAN_ID_STD, 8, data);
}

void DJIBoard::PosCtrl(const uint16_t &motorId, const int32_t &pos)
{
    uint32_t canId = DJI_BASE_ID + boardId;
    std::array<uint8_t, 8> data;
    data[0] = motorId & 0xff;
    data[1] = (motorId >> 8) & 0xff;
    data[2] = POSCTRL;
    data[3] = 0;
    data[4] = pos & 0xff;
    data[5] = (pos >> 8) & 0xff;
    data[6] = (pos >> 16) & 0xff;
    data[7] = (pos >> 24) & 0xff;
    can_handle->send_can(canId, Can::CAN_ID_STD, 8, data);
}

void DJIBoard::CurCtrl(const uint16_t &motorId, const int32_t &cur)
{
    uint32_t canId = DJI_BASE_ID + boardId;
    std::array<uint8_t, 8> data;
    data[0] = motorId & 0xff;
    data[1] = (motorId >> 8) & 0xff;
    data[2] = CURCTRL;
    data[3] = 0;
    data[4] = cur & 0xff;
    data[5] = (cur >> 8) & 0xff;
    data[6] = (cur >> 16) & 0xff;
    data[7] = (cur >> 24) & 0xff;
    can_handle->send_can(canId, Can::CAN_ID_STD, 8, data);
}

void DJIBoard::ReadInfo(const uint16_t &motorId)
{
    uint32_t canId = DJI_BASE_ID + boardId;
    std::array<uint8_t, 8> data;
    data[0] = motorId & 0xff;
    data[1] = (motorId >> 8) & 0xff;
    data[2] = READINFO;
    data[3] = 0;
    can_handle->send_can(canId, Can::CAN_ID_STD, 8, data);
}

void DJIBoard::VelCtrlAll(const std::array<int16_t,4> &vel)
{
    uint32_t canId = DJI_BASE_ID + boardId + 4;
    std::array<uint8_t, 8> data;
    for (int i = 0; i < 4; i++)
    {
        data[i * 2] = vel[i] & 0xff;
        data[i * 2 + 1] = (vel[i] >> 8) & 0xff;
    }
    can_handle->send_can(canId, Can::CAN_ID_STD, 8, data);
}

void DJIBoard::PosCtrlAll(const std::array<int16_t,4> &pos)
{
    uint32_t canId = DJI_BASE_ID + boardId + 8;
    std::array<uint8_t, 8> data;
    for (int i = 0; i < 4; i++)
    {
        data[i * 2] = pos[i] & 0xff;
        data[i * 2 + 1] = (pos[i] >> 8) & 0xff;
    }
    can_handle->send_can(canId, Can::CAN_ID_STD, 8, data);
}

void DJIBoard::Homing(const uint16_t &motorId, const int16_t &vel, const int16_t &cur)
{
    uint32_t canId = DJI_BASE_ID + boardId;
    std::array<uint8_t, 8> data;
    data[0] = (motorId >> 8) & 0xff;
    data[1] = motorId & 0xff;
    data[2] = HOMING;
    data[3] = 0;
    data[4] = vel & 0xff;
    data[5] = (vel >> 8) & 0xff;
    data[6] = cur & 0xff;
    data[7] = (cur >> 8) & 0xff;
    can_handle->send_can(canId, Can::CAN_ID_STD, 8, data);
}