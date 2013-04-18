#ifndef HARDWARE_PROFILE
#define HARDWARE_PROFILE

#define self_power          1
#define USB_BUS_SENSE       1

#define CLOCK_FREQ 40000000
#define GetSystemClock() CLOCK_FREQ
#define GetPeripheralClock() CLOCK_FREQ

#endif
