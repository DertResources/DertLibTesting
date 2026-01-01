#pragma once

#include <frc/TimedRobot.h>
#include "DertLib/include/Component.h"
#include "include/ChooserTest.h"


#include <frc/simulation/DriverStationSim.h>




class Robot : public frc::TimedRobot {
 public:
  /** Runs once when the robot turns on */
  Robot();

  /** Runs every 20ms regardless of what state the robot is in */
  void RobotPeriodic() override;

  /** runs once when the listed state begins */
  void AutonomousInit() override;
  void TeleopInit() override;
  void DisabledInit() override;
  void TestInit() override;
  void SimulationInit() override;

  /** runs every 20ms when the robot is in the specified state */
  void AutonomousPeriodic() {};
  void TeleopPeriodic() {};
  void DisabledPeriodic() {};
  void TestPeriodic() {};
  void SimulationPeriodic() {};

  /** Takes inputs from sensors and pushes their data to simulink */
  void PreStep() {for(auto component : dlib::Component::allCreatedComponents) component->PreStepCallback();}
  
  /** Takes outputs from simulink and pushes their commands to hardware */
  void PostStep() {for(auto component : dlib::Component::allCreatedComponents) component->PostStepCallback();}

  // All Components
  ChooserTest m_ChooserComponent;
};
