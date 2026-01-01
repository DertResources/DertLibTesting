#pragma once

#include <gtest/gtest.h>
#include <ctre/phoenix6/TalonFX.hpp>
#include <ctre/phoenix6/sim/TalonFXSimState.hpp>
#include <ctre/phoenix6/controls/DutyCycleOut.hpp>

#include <frc/simulation/DriverStationSim.h>
#include <frc/DriverStation.h>

// Frc
#include <frc/simulation/DCMotorSim.h>
#include <frc/system/plant/LinearSystemId.h>
#include <frc/system/plant/DCMotor.h>

//ctre
#include <ctre/phoenix6/TalonFX.hpp>
#include <ctre/phoenix6/sim/TalonFXSimState.hpp>

#include <frc/RobotController.h>

class TalonFXTest : public testing::Test {
protected:
   static constexpr double kGearRatio = 10.0;

   /* create the TalonFX */
   ctre::phoenix6::hardware::TalonFX m_fx{0};
   ctre::phoenix6::sim::TalonFXSimState& m_fxSim{m_fx.GetSimState()};
   /* create the simulated DC motor */
   frc::sim::DCMotorSim m_motorSim{
      frc::LinearSystemId::DCMotorSystem(
         frc::DCMotor::KrakenX60FOC(1),
         0.001_kg_sq_m,
         kGearRatio
      ),
      frc::DCMotor::KrakenX60FOC(1),
      {0,0}
   };

   void SetUp() override
   {
      /* enable the robot */
      frc::sim::DriverStationSim::SetEnabled(true);
      frc::sim::DriverStationSim::NotifyNewData();

      /* delay ~100ms so the devices can start up and enable */
      std::this_thread::sleep_for(std::chrono::milliseconds{100});
   }
};

TEST_F(TalonFXTest, RobotIsEnabled)
{
   /* verify that the robot is enabled */
   EXPECT_TRUE(frc::DriverStation::IsEnabled());
}

TEST_F(TalonFXTest, MotorDrives)
{
   /* set the voltage supplied by the battery */
   m_fxSim.SetSupplyVoltage(frc::RobotController::GetBatteryVoltage());

   auto& dutyCycle = m_fx.GetDutyCycle();

   /* wait for a fresh duty cycle signal */
   dutyCycle.WaitForUpdate(100_ms);
   /* verify that the motor output is zero */
   EXPECT_DOUBLE_EQ(dutyCycle.GetValue(), 0.0);

   /* request 100% output */
   m_fx.SetControl(ctre::phoenix6::controls::DutyCycleOut{1.0});

   /* wait for the control to apply and the motor to accelerate */
   for (int i = 0; i < 10; ++i) { 
      std::this_thread::sleep_for(std::chrono::milliseconds{20});
      m_motorSim.SetInputVoltage(m_fxSim.GetMotorVoltage());
      m_motorSim.Update(20_ms);

      m_fxSim.SetRawRotorPosition(kGearRatio * m_motorSim.GetAngularPosition());
      m_fxSim.SetRotorVelocity(kGearRatio * m_motorSim.GetAngularVelocity());
   }

   /* wait for a new duty cycle signal */
   dutyCycle.WaitForUpdate(100_ms);
   /* verify that the motor output is 1.0 */
   EXPECT_DOUBLE_EQ(dutyCycle.GetValue(), 1.0);
}