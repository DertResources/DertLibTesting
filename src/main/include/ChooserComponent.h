#pragma once

// Local
#include "DertLib/include/Component.h"
#include "DertLib/include/Chooser.h"

class ChooserComponent : public dlib::Component
{
public:
	void PreStepCallback() override;
	void PostStepCallback() override;
private:
	double chooserOutput = 0;
	
	dlib::Chooser TestingChooser
	{
		"Testing Chooser",
		{
			{"Choice 1", 1},
			{"Choice 2", 2},
			{"Choice 3", 3},
			{"Choice 4", 4}
		},
		&chooserOutput
	};
};
