#include "gpio1.h"

// GPIO Port Control (GPIOPCTL) values
// CAN
static const uint8_t * GPIOPCTL_CAN_PERIPHERAL_PINS[4] = 
{
    CAN0PB, CAN0PE, CAN0PF, CAN1
};

static const uint8_t GPIOPCTL_CAN0PB[] =
{
    8,  // PB4 (CAN0Rx)
    8,  // PB5 (CAN0Tx)
};

static const uint8_t GPIOPCTL_CAN0PE[] =
{
    8,  // PE4 (CAN0Rx)
    8,  // PE5 (CAN0Tx)
};

static const uint8_t GPIOPCTL_CAN0PF[] =
{
    3,  // PF0 (CAN0Rx)
    3,  // PF3 (CAN0Tx)
};

static const uint8_t GPIOPCTL_CAN1[] =
{
    8,  // PA0 (CAN1Rx)
    8,  // PA1 (CAN1Tx)
};

// UART
static const uint8_t * GPIOPCTL_UART_PERIPHERAL_PINS[8] = 
{
    GPIOPCTL_UART0, GPIOPCTL_UART1, GPIOPCTL_UART2, GPIOPCTL_UART3, GPIOPCTL_UART4, GPIOPCTL_UART5, GPIOPCTL_UART6, GPIOPCTL_UART7
};

static const uint8_t GPIOPCTL_UART0[] =
{
    1,  // PA0 (U0Rx)
    1,  // PA1 (U0Tx)
};

static const uint8_t GPIOPCTL_UART1[] =
{
    1,  // PB0 (U1Rx)
    1,  // PB1 (U1Tx)
    2,  // PC4 (U1Rx)
    2,  // PC5 (U1Tx)
    14, // PC4 (U1RTS)
    14, // PC5 (U1CTS)
    1,  // PF0 (U1RTS)
    1,  // PF1 (U1CTS)
};

static const uint8_t GPIOPCTL_UART2[] =
{
    1,  // PD6 (U2Rx)
    1,  // PD7 (U2Tx)
};

static const uint8_t GPIOPCTL_UART3[] =
{
    1,  // PC6 (U3Rx)
    1,  // PC7 (U3Tx)
};

static const uint8_t GPIOPCTL_UART4[] =
{
    1,  // PC4 (U4Rx)
    1,  // PC5 (U4Tx)
};

static const uint8_t GPIOPCTL_UART5[] =
{
    1,  // PE4 (U5Rx)
    1,  // PE5 (U5Tx)
};

static const uint8_t GPIOPCTL_UART6[] =
{
    1,  // PD4 (U6Rx)
    1,  // PD5 (U6Tx)
};

static const uint8_t GPIOPCTL_UART7[] =
{
    1,  // PE0 (U7Rx)
    1,  // PE1 (U7Tx)
};

// I2C
static const uint8_t * GPIOPCTL_I2C_PERIPHERAL_PINS[4] = 
{
    GPIOPCTL_I2C0, GPIOPCTL_I2C1, GPIOPCTL_I2C3, GPIOPCTL_I2C3
};

static const uint8_t GPIOPCTL_I2C0[] =
{
    3,  // PB2 (I2C0SCL)
    3,  // PB3 (I2C0SDA)
};

static const uint8_t GPIOPCTL_I2C1[] =
{
    3,  // PA6 (I2C1SCL)
    3,  // PA7 (I2C1SDA)
};

static const uint8_t GPIOPCTL_I2C2[] =
{
    3,  // PE4 (I2C2SCL)
    3,  // PE5 (I2C2SDA)
};

static const uint8_t GPIOPCTL_I2C3[] =
{
    3,  // PD0 (I2C3SCL)
    3,  // PD1 (I2C3SDA)
};

// SSI
static const uint8_t * GPIOPCTL_SSI_PERIPHERAL_PINS[4] = 
{
    SSI0, SSI1, SSI2, SSI3
}

static const uint8_t GPIOPCTL_SSI0[] =
{
    2,  // PA2 (SSI0Clk)
    2,  // PA3 (SSI0Fss)
    2,  // PA4 (SSI0Rx)
    2,  // PA5 (SSI0Tx)
};

static const uint8_t GPIOPCTL_SSI1[] =
{
    2,  // PD0 (SSI1Clk)
    2,  // PD1 (SSI1Fss)
    2,  // PD2 (SSI1Rx)
    2,  // PD3 (SSI1Tx)
    2,  // PF0 (SSI1Rx)
    2,  // PF1 (SSI1Tx)
    2,  // PF2 (SSI1Clk)
    2,  // PF3 (SSI1Fss)
};

static const uint8_t GPIOPCTL_SSI2[] =
{
    2,  // PB4 (SSI2Clk)
    2,  // PB5 (SSI2Fss)
    2,  // PB6 (SSI2Rx)
    2,  // PB7 (SSI2Tx)
};

static const uint8_t GPIOPCTL_SSI3[] =
{
    1,  // PD0 (SSI3Clk)
    1,  // PD1 (SSI3Fss)
    1,  // PD2 (SSI3Rx)
    1,  // PD3 (SSI3Tx)
};

// USB
static const uint8_t GPIOPCTL_USB0[] =
{
    1,  // PB0 (USB0ID)
    1,  // PB1 (USB0VBUS)
    1,  // PD4 (USB0DM)
    1,  // PD5 (USB0DP)

    9,  // PC6 (USB0EPEN)
    9,  // PD2 (USB0EPEN)
    9,  // PF4 (USB0EPEN)

    9,  // PC7 (USB0PFLT)
    9,  // PD3 (USB0PFLT)
};


