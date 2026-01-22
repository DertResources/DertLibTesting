#pragma once

//Local
#include "DertLib/include/Component.h"
#include "DertLib/include/TalonFXMotorGroup.h"
#include "include/Constants.h"

class KrakenTest : public dlib::Component
{
public:
	void PreStepCallback() override;
	void PostStepCallback() override;
private:
	dlib::TalonFXMotorGroup testGroup
	{
		{
			Constants::TestMotorCreateInfo
		}
	};
};
