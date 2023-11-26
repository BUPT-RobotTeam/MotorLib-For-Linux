#ifndef VESC_BOARD_H_
#define VESC_BOARD_H_

#include <cstdint>
#include "bupt_can/bupt_can.h"

class VESCBoard
{
private:
public:
    enum CAN_PACKET_ID{
        CAN_PACKET_SET_DUTY = 0,
	    CAN_PACKET_SET_CURRENT,
	    CAN_PACKET_SET_CURRENT_BRAKE,
	    CAN_PACKET_SET_RPM,
	    CAN_PACKET_SET_POS,
	    CAN_PACKET_SET_CURRENT_REL = 10,
	    CAN_PACKET_SET_CURRENT_BRAKE_REL,
	    CAN_PACKET_SET_CURRENT_HANDBRAKE,
	    CAN_PACKET_SET_CURRENT_HANDBRAKE_REL,
	    CAN_PACKET_MAKE_ENUM_32_BITS = 0xFFFFFFFF,
    };
private:
    static const int DUTY_SCALE = 100000;
    static const int CURRENT_SCALE = 1000;
    static const int CURRENT_BRAKE_SCALE = 1000;
    static const int RPM_SCALE = 1;
    static const int POS_SCALE = 1000000;
    static const int CURRENT_REL_SCALE = 100000;
    static const int CURRENT_BRAKE_REL_SCALE = 100000;
    static const int CURRENT_HANDBRAKE_SCALE = 1000;
    static const int CURRENT_HANDBRAKE_REL_SCALE = 100000;
    uint32_t vesc_id;
    std::shared_ptr<Can> can_handle;
    std::shared_ptr< std::array<uint8_t,8> > buffer;
    const int GetVESCScale(const CAN_PACKET_ID &id);
    void SetBufferWith32Bit(const uint32_t &val);
public:
    VESCBoard(const uint32_t &vesc_id, const std::shared_ptr<Can> &can_handle = nullptr);
    ~VESCBoard();
    const uint32_t SetFrameID(const uint32_t &vesc_id,const CAN_PACKET_ID &id);
    void SetDuty(const float &duty);
    void SetCurrent(const float &current);
    void SetCurrentBrake(const float &current);
    void SetRPM(const float &rpm);
    void SetPos(const float &pos);
    void SetCurrentRel(const float &current_rel);
    void SetCurrentBrakeRel(const float &current_rel);
    void SetCurrentHandBrake(const float &current);
    void SetCurrentHandBrakeRel(const float &current_rel);
    
    void SendControlMSg(const float &val, const CAN_PACKET_ID &command_id);

    // Currently not supported
    //void SetCurrentLimits(const float &min, const float &max); 
    //void SetCurrentLimitsIn(const float &min, const float &max);
};

#endif /* VESC_BOARD_H_ */
