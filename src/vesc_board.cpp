#include "motorLib/vesc_board.h"
#include <array>



VESCBoard::VESCBoard(const uint32_t &vesc_id, const std::shared_ptr<Can> &can_handle)
{
    this->vesc_id = vesc_id;
    if (can_handle != nullptr)
        this->can_handle = can_handle;
    else 
        this->can_handle = std::make_shared<Can>("can0");
    this->can_handle->can_start();
    this->buffer = std::make_shared< std::array<uint8_t,8> >();
}

VESCBoard::~VESCBoard()
{
}

const uint32_t VESCBoard::SetFrameID(const uint32_t &vesc_id,const CAN_PACKET_ID &command_id)
{
    return vesc_id | ((uint32_t)command_id << 8);
}

void VESCBoard::SetBufferWith32Bit(const uint32_t &val)
{
    (*buffer)[0] = val >> 24 && 0xff;
    (*buffer)[1] = val >> 16 && 0xff;
    (*buffer)[2] = val >> 8 && 0xff;
    (*buffer)[3] = val && 0xff;
}

void VESCBoard::SetDuty(const float &duty)
{
    int duty_int = static_cast<int>(duty * DUTY_SCALE);
    SetBufferWith32Bit(duty_int); 
    can_handle->send_can(SetFrameID(vesc_id, CAN_PACKET_SET_DUTY),Can::CAN_ID_EXT,4,*buffer);
}

void VESCBoard::SetCurrent(const float &current)
{
    int current_int = static_cast<int>(current * CURRENT_SCALE);
    SetBufferWith32Bit(current_int);
    can_handle->send_can(SetFrameID(vesc_id, CAN_PACKET_SET_CURRENT),Can::CAN_ID_EXT,4,*buffer);
}

void VESCBoard::SetCurrentBrake(const float &current)
{
    int current_int = static_cast<int>(current * CURRENT_BRAKE_SCALE);
    SetBufferWith32Bit(current_int);
    can_handle->send_can(SetFrameID(vesc_id, CAN_PACKET_SET_CURRENT_BRAKE),Can::CAN_ID_EXT,4,*buffer);
}

void VESCBoard::SetRPM(const float &rpm)
{
    int rpm_int = static_cast<int>(rpm * RPM_SCALE);
    SetBufferWith32Bit(rpm_int);
    can_handle->send_can(SetFrameID(vesc_id, CAN_PACKET_SET_RPM),Can::CAN_ID_EXT,4,*buffer);
}

void VESCBoard::SetPos(const float &pos)
{
    int pos_int = static_cast<int>(pos * POS_SCALE);
    SetBufferWith32Bit(pos_int);
    can_handle->send_can(SetFrameID(vesc_id, CAN_PACKET_SET_POS),Can::CAN_ID_EXT,4,*buffer);
}

void VESCBoard::SetCurrentRel(const float &current)
{
    int current_int = static_cast<int>(current * CURRENT_REL_SCALE);
    SetBufferWith32Bit(current_int);
    can_handle->send_can(SetFrameID(vesc_id, CAN_PACKET_SET_CURRENT_REL),Can::CAN_ID_EXT,4,*buffer);
}

void VESCBoard::SetCurrentBrakeRel(const float &current)
{
    int current_int = static_cast<int>(current * CURRENT_BRAKE_REL_SCALE);
    SetBufferWith32Bit(current_int);
    can_handle->send_can(SetFrameID(vesc_id, CAN_PACKET_SET_CURRENT_BRAKE_REL),Can::CAN_ID_EXT,4,*buffer);
}

void VESCBoard::SetCurrentHandBrake(const float &current)
{
    int current_int = static_cast<int>(current * CURRENT_HANDBRAKE_SCALE);
    SetBufferWith32Bit(current_int);
    can_handle->send_can(SetFrameID(vesc_id, CAN_PACKET_SET_CURRENT_HANDBRAKE),Can::CAN_ID_EXT,4,*buffer);
}

void VESCBoard::SetCurrentHandBrakeRel(const float &current)
{
    int current_int = static_cast<int>(current * CURRENT_HANDBRAKE_REL_SCALE);
    SetBufferWith32Bit(current_int);
    can_handle->send_can(SetFrameID(vesc_id, CAN_PACKET_SET_CURRENT_HANDBRAKE_REL),Can::CAN_ID_EXT,4,*buffer);
}

const int VESCBoard::GetVESCScale(const VESCBoard::CAN_PACKET_ID &id)
{
    switch (id)
    {
        case CAN_PACKET_SET_DUTY:
            return DUTY_SCALE;
        case CAN_PACKET_SET_CURRENT:
            return CURRENT_SCALE;
        case CAN_PACKET_SET_CURRENT_BRAKE:
            return CURRENT_BRAKE_SCALE;
        case CAN_PACKET_SET_RPM:
            return RPM_SCALE;
        case CAN_PACKET_SET_POS:
            return POS_SCALE;
        case CAN_PACKET_SET_CURRENT_REL:
            return CURRENT_REL_SCALE;
        case CAN_PACKET_SET_CURRENT_BRAKE_REL:
            return CURRENT_BRAKE_REL_SCALE;
        case CAN_PACKET_SET_CURRENT_HANDBRAKE:
            return CURRENT_HANDBRAKE_SCALE;
        case CAN_PACKET_SET_CURRENT_HANDBRAKE_REL:
            return CURRENT_HANDBRAKE_REL_SCALE;
        default:
            return 0;
    }
}

void VESCBoard::SendControlMSg(const float &val, const CAN_PACKET_ID &command_id)
{
    int val_int = static_cast<int>(val * GetVESCScale(command_id));
    SetBufferWith32Bit(val_int);
    can_handle->send_can(SetFrameID(vesc_id, command_id),Can::CAN_ID_EXT,4,*buffer);
}
