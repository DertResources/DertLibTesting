#include "Robot.h"

Robot::Robot() {}
void Robot::RobotPeriodic() {
}

void Robot::AutonomousInit() {}
void Robot::TeleopInit() {}
void Robot::DisabledInit() {}
void Robot::TestInit() {}
void Robot::SimulationInit() {}

#ifndef RUNNING_FRC_TESTS
int main() {
  return frc::StartRobot<Robot>();
}
#endif
