#include "gpio1.h"

// GPIO Port Control (GPIOPCTL) values
// CAN
const uint8_t * CAN_PERIPHERAL_PINS[4] = 
{
    CAN0PB, CAN0PE, CAN0PF, CAN1
};

const uint8_t CAN0PB[] =
{
    8,  // PB4 (CAN0Rx)
    8,  // PB5 (CAN0Tx)
};

const uint8_t CAN0PE[] =
{
    8,  // PE4 (CAN0Rx)
    8,  // PE5 (CAN0Tx)
};

const uint8_t CAN0PF[] =
{
    3,  // PF0 (CAN0Rx)
    3,  // PF3 (CAN0Tx)
};

const uint8_t CAN1[] =
{
    8,  // PA0 (CAN1Rx)
    8,  // PA1 (CAN1Tx)
};

// UART
const uint8_t * UART_PERIPHERAL_PINS[8] = 
{
    UART0, UART1, UART2, UART3, UART4, UART5, UART6, UART7
};

const uint8_t UART0[] =
{
    1,  // PA0 (U0Rx)
    1,  // PA1 (U0Tx)
};

const uint8_t UART1[] =
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

const uint8_t UART2[] =
{
    1,  // PD6 (U2Rx)
    1,  // PD7 (U2Tx)
};

const uint8_t UART3[] =
{
    1,  // PC6 (U3Rx)
    1,  // PC7 (U3Tx)
};

const uint8_t UART4[] =
{
    1,  // PC4 (U4Rx)
    1,  // PC5 (U4Tx)
};

const uint8_t UART5[] =
{
    1,  // PE4 (U5Rx)
    1,  // PE5 (U5Tx)
};

const uint8_t UART6[] =
{
    1,  // PD4 (U6Rx)
    1,  // PD5 (U6Tx)
};

const uint8_t UART7[] =
{
    1,  // PE0 (U7Rx)
    1,  // PE1 (U7Tx)
};

// I2C
const uint8_t * I2C_PERIPHERAL_PINS[4] = 
{
    I2C0, I2C1, I2C3, I2C3
};

const uint8_t I2C0[] =
{
    3,  // PB2 (I2C0SCL)
    3,  // PB3 (I2C0SDA)
};

const uint8_t I2C1[] =
{
    3,  // PA6 (I2C1SCL)
    3,  // PA7 (I2C1SDA)
};

const uint8_t I2C2[] =
{
    3,  // PE4 (I2C2SCL)
    3,  // PE5 (I2C2SDA)
};

const uint8_t I2C3[] =
{
    3,  // PD0 (I2C3SCL)
    3,  // PD1 (I2C3SDA)
};

// SSI
const uint8_t * SSI_PERIPHERAL_PINS[4] = 
{
    SSI0, SSI1, SSI2, SSI3
}

const uint8_t SSI0[] =
{
    2,  // PA2 (SSI0Clk)
    2,  // PA3 (SSI0Fss)
    2,  // PA4 (SSI0Rx)
    2,  // PA5 (SSI0Tx)
};

const uint8_t SSI1[] =
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

const uint8_t SSI2[] =
{
    2,  // PB4 (SSI2Clk)
    2,  // PB5 (SSI2Fss)
    2,  // PB6 (SSI2Rx)
    2,  // PB7 (SSI2Tx)
};

const uint8_t SSI3[] =
{
    1,  // PD0 (SSI3Clk)
    1,  // PD1 (SSI3Fss)
    1,  // PD2 (SSI3Rx)
    1,  // PD3 (SSI3Tx)
};

// USB
const uint8_t USB0[] =
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


