#include <stdint.h>

#define _IOM volatile      // Read and Write Type
#define _IM volatile const // Read Only

//It is the base address of GPIO 
#define GPIO_base_address ((uint32_t)0x40040000) 
#define GPIO(vect) ((GPIO_PRT_Type *)vect)

//It defines the pad offset
#define pad_bits(pad) (pad * 3)

//It defines the pad offset for the GPIO Interrupts
#define pad_bits_intr(pad) (pad * 2)

extern volatile uint32_t startFlag  __attribute__((used));
extern volatile uint32_t invertFLag __attribute__((used));

//Structure to store different Registers Related to a GPIO Pin
typedef struct
{
    _IOM uint32_t DR;       // Port output data register
    _IM uint32_t PS;        // Port IO pad state register
    _IOM uint32_t PC;       // Port configuration register
    _IOM uint32_t INTR_CFG; // Port interrupt configuration register
    _IOM uint32_t INTR;     // Port interrupt status register
    uint32_t reserved0;
    _IOM uint32_t PC2; // Port configuration register 2
    uint32_t reserved1[10];
    _IOM uint32_t DR_SET; // Port output data set register
    _IOM uint32_t DR_CLR; // Port output data clear register
    _IOM uint32_t DR_INV; // Port output data clear register
} GPIO_PRT_Type;

//TO store the data of the port and pad of the different LED's
typedef struct
{
    _IOM uint32_t port;
    _IOM uint32_t pad;
} GPIO_LED_Config;


//Function Declaration

//To set the default output value of the GPIO Pin
void GPIO_SetPinOutput(uint32_t port, uint32_t pad, uint32_t val);

//To configure the Drive Mode of the GPIO Pin
void GPIO_ConfigDriveMode(uint32_t port, uint32_t pad, uint32_t mode);

//TO COnfigure the Interrupt of the GPIO Pin
void GPIO_ConfigInterrupt(uint32_t port, uint32_t pad, uint32_t edge_det_mode);

//To COnfigure the Drive Mode and the default output values of various led's
void GPIO_ConfigMultipleLeds(uint32_t size);

//Function to make LED's blink in the forward sequence
void GPIO_ForwardSequenceBlink(uint32_t size);

//Function to make LED's blink in the reverse sequence
void GPIO_ReverseSequenceBLink(uint32_t size);

//To Clear the Interrupt 
void GPIO_ClearInterrupt(uint32_t port, uint32_t pad);

//To Read the GPIO Pin 
uint32_t GPIO_Read(uint32_t port);

//Delay Function
void Delay(uint32_t delayNumber);