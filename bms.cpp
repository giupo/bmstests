#include <windows.h>
#include "bms.h"

int main(int argc, char** argv) {
  FlightData* flightData;
  do {
    flightDataMemHandle = OpenFileMapping(FILE_MAP_ALL_ACCESS, TRUE,
					  TEXT("FalconSharedMemoryArea"));
    if(!flightDataMemHandle) {
      std::cout << "Unable to open file. Is Falcon Running?" << std::endl;
    } else {
      std::cout << "Got Shared Memory" << std::endl;
    }
  } while (!flightDataMemHandle);

  flightData = (FlightData*) MapViewOfFile(flightDataMemHandle,
                                           FILE_MAP_ALL_ACCESS, 0, 0, 0);
  while (TRUE) {
    //		std::cout << flightData->IsSet(FlightData::AOAOn) << std::endl;
    std::cout << flightData->gs << std::endl;
    for (int i = 0; i < 5; i++) {
      for (int x = 0; x < 25; x++) {
	std::cout << flightData->DEDLines[i][x] << ",";
      }
      std::cout << std::endl;
    }
  }
  // Close shared memory area
  if (flightData) {
    UnmapViewOfFile(flightData);
    flightData = NULL;
  }
  CloseHandle(flightDataMemHandle);
  return 0;
}
