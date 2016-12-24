#ifndef __BMS_H__
#define __BMS_H__

#include <inttypes.h>
#include <iostream>
#include <FlightData.h>
#include <windows.h>

extern "C" {
  HANDLE flightDataMemHandle = NULL;
  HANDLE flightData2MemHandle = NULL;
  HANDLE OSBDataMemHandle = NULL;
  HANDLE textureDataMemHandle = NULL;
  FlightData* flightData = NULL;
  FlightData2* flightData2 = NULL;
  OSBData* osbData = NULL;
  long* textureData = NULL;
};

#endif // __BMS_H__
