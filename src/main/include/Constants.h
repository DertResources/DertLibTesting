#pragma once

#include "DertLib/include/TalonFXMotor.h"
#include "DertLib/include/CANBus.h"
#include <stdint.h>

namespace Constants
{
    static dlib::CANBus CanivoreBus{"uno"};

    static dlib::TalonFXMotorCreateInfo TestMotorCreateInfo = dlib::TalonFXMotorCreateInfo::getDefaultCreateInfo()
        .SetCanbus(CanivoreBus)
        .SetCanID(1)
        .SetDisplayName("Test Motor")
        .SetEnableFOC(true)
        .SetMotorType(dlib::TalonFXMotorType::KrakenX60);
    namespace IMU
    {
        static int IMU_CAN_ID = 2;
        static dlib::CANBus IMU_CANBus = CanivoreBus;
    };
};