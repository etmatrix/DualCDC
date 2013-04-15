#ifndef HARDWARE_PROFILE
#define HARDWARE_PROFILE

#define self_power          1

#if defined(__PIC24FJ64GB002__)
#define CLOCK_FREQ 32000000
#elif defined(__32MX250F128B__)
#define CLOCK_FREQ 40000000
#endif
#define GetSystemClock() CLOCK_FREQ
#define GetPeripheralClock() CLOCK_FREQ

#define I2C_CLOCK_FREQ 400000

#endif
