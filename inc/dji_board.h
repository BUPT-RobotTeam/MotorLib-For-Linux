#ifndef DJI_BOARD_H_
#define DJI_BOARD_H_

#include "bupt_can.h"
#include <memory>
#include <array>

class DJIBoard
{
private: 
    std::shared_ptr<Can> can_handle;
    uint32_t boardId;
    uint8_t type[4];
    static const uint32_t DJI_BASE_ID = 0x200;
    enum CANOPTION {
        MOTORON = 1,
        MOTOROFF,
        VELCFG,
        POSCFG,
        CURCFG,
        VELCTRL,
        POSCTRL,
        CURCTRL,
        READINFO,
        VELCTRLALL,
        POSCTRLALL,
        HOMING,
        LIMITVELCFG,
        NOINITPOSCFG,
    };
public:
    explicit DJIBoard(const uint32_t &boardId,const std::shared_ptr<Can> &can_handle = nullptr);
    ~DJIBoard();
    void MotorOn(const uint16_t &motorId);
    void MotorOff(const uint16_t &motorId);
    void VelCfg(const uint16_t &motorId);
    void LimitVelCfg(const uint16_t &motorId);
    void PosCfg(const uint16_t &motorId, const int &maxPosVel);
    void NoInitPosCfg(const uint16_t &motorId, const int &maxPosVel);
    void CurCfg(const uint16_t &motorId);
    void VelCtrl(const uint16_t &motorId, const int32_t &vel);
    void PosCtrl(const uint16_t &motorId, const int32_t &pos);
    void CurCtrl(const uint16_t &motorId, const int32_t &cur);
    void VelCtrlAll(const std::array<int16_t,4> &vel);
    void PosCtrlAll(const std::array<int16_t,4> &pos);
    void ReadInfo(const uint16_t &motorId);
    void Homing(const uint16_t &motorId, const int16_t &vel, const int16_t &cur);
};

#endif // DJI_BOARD_H_