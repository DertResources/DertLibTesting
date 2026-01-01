#include "include/Robot.h"

Robot::Robot() {
  frc::sim::DriverStationSim::SetEnabled(true);
  frc::sim::DriverStationSim::NotifyNewData();

  // pause to start robot
  std::this_thread::sleep_for(std::chrono::milliseconds{100});
}


void Robot::RobotPeriodic() {
  PreStep();
  //step();
  PostStep();
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
