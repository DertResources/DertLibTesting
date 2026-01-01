#pragma once

//Local
#include "DertLib/include/Component.h"

class NeoTest : public dlib::Component
{
public:
	void PreStepCallback() override;
	void PostStepCallback() override;
private:
};
