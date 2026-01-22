#pragma once

//Local
#include "DertLib/include/Component.h"
#include "ctre/phoenix6/Pigeon2.hpp"
#include "include/Constants.h"

class IMUTest : public dlib::Component
{
public:
	void PreStepCallback() override;
	void PostStepCallback() override;
private:
	ctre::phoenix6::hardware::Pigeon2 IMU {Constants::IMU::IMU_CAN_ID,
										   Constants::IMU::IMU_CANBus};

};
