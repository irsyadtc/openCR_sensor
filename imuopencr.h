/*******************************************************************************
* Copyright 2021 CAREM UTP
*
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
*     http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*******************************************************************************/

/* Authors: Muhammad Irsyad Sahalan */

#ifndef IMUOPENCR_H_
#define IMUOPENCR_H_

//#include "Arduino.h"
#include <ros.h>
#include <IMU.h>

#include <sensor_msgs/Imu.h>
#include <sensor_msgs/MagneticField.h>

#define ACCEL_FACTOR                      0.000598550415   // (ADC_Value / Scale) * 9.80665            => Range : +- 2[g]
                                                           //                                             Scale : +- 16384
#define GYRO_FACTOR                       0.0010642        // (ADC_Value/Scale) * (pi/180)             => Range : +- 2000[deg/s]
                                                           //                                             Scale : +- 16.4[deg/s]

#define MAG_FACTOR                        15e-8




class imuopencr
{
 public:
  imuopencr();
  ~imuopencr();

  bool init(void);

  // IMU
  void initIMU(void);
  sensor_msgs::Imu getIMU(void);
  void updateIMU(void);
  void calibrationGyro(void);

  float* getOrientation(void);
  sensor_msgs::MagneticField getMag(void);

 private:
  sensor_msgs::Imu           imu_msg_;
  sensor_msgs::MagneticField mag_msg_;
  cIMU imu_;


};

#endif // IMUOPENCR_H_
