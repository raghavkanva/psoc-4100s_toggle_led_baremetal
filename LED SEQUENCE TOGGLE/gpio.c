#include "gpio.h"

//This is an array for storing the pins and pads of LED's
GPIO_LED_Config _led_iden[9] = {{1, 0}, {1, 2}, {1, 4}, {1, 6}, {2, 0}, {2, 2}, {5, 2}, {5, 5}, {5, 7}};

//This is to store the base address of a particular GPIO port
uint32_t _GPIO_Port_Base_vect;

void GPIO_SetPinOutput(uint32_t port, uint32_t pad, uint32_t val)
{
    _GPIO_Port_Base_vect = GPIO_base_address + (port * 0x100);
    if (val)
        *(uint32_t *)_GPIO_Port_Base_vect |= (1 << pad);  //Sets the bit
    else
        *(uint32_t *)_GPIO_Port_Base_vect &= ~(1 << pad); //Clears the bit
}

void GPIO_ConfigDriveMode(uint32_t port, uint32_t pad, uint32_t mode)
{
    _GPIO_Port_Base_vect = GPIO_base_address + (port * 0x100);

    *((uint32_t *)_GPIO_Port_Base_vect + 2) &= ~(0x7 << (pad * 3)); //Clear the existing mode
    *((uint32_t *)_GPIO_Port_Base_vect + 2) |= mode << (pad * 3);   //Set the new mode
}

void GPIO_ConfigInterrupt(uint32_t port, uint32_t pad, uint32_t edge_det_mode)
{
    _GPIO_Port_Base_vect = GPIO_base_address + (port * 0x100);
    GPIO(_GPIO_Port_Base_vect)->INTR_CFG &= ~(3 << (2 * pad));            //Clear the existing edge detection mode
    GPIO(_GPIO_Port_Base_vect)->INTR_CFG |= (edge_det_mode << (2 * pad)); //Set the new mode
}

void GPIO_ConfigMultipleLeds(uint32_t size)
{
    for (uint32_t i = 0; i < size; i++)
    {
        GPIO_ConfigDriveMode(_led_iden[i].port, _led_iden[i].pad, 6);       //Set the drive mode to Output
        GPIO_SetPinOutput(_led_iden[i].port, _led_iden[i].pad, 1);          //Set the Default Value as 0      
    }
}

void GPIO_ForwardSequenceBlink(uint32_t size)
{
                                                   
    for (uint32_t i = 0; i < size; i++)
    {

        GPIO_SetPinOutput(_led_iden[i].port, _led_iden[i].pad, 0);
        Delay(500000);

        GPIO_SetPinOutput(_led_iden[i].port, _led_iden[i].pad, 1);
        Delay(500000);
        if (invertFLag != 1)
        {
            break;
        }
    }
}
void GPIO_ReverseSequenceBLink(uint32_t size)
{
    for (int32_t i = size - 1; i >= 0; i--)
    {

        GPIO_SetPinOutput(_led_iden[i].port, _led_iden[i].pad, 0);
        Delay(500000);

        GPIO_SetPinOutput(_led_iden[i].port, _led_iden[i].pad, 1);
        Delay(500000);

        if (invertFLag != 0)
            return;
    }
}

void Delay(uint32_t delayNumber)
{
    for (uint32_t i = 0; i < delayNumber; i++);
    for (uint32_t i = 0; i < delayNumber; i++);
}

void GPIO_INTR_Status(uint32_t port, uint32_t pad)
{
    _GPIO_Port_Base_vect = GPIO_base_address + (port * 0x100);
    GPIO(_GPIO_Port_Base_vect)->INTR = (1 << pad);
}

void GPIO_ClearInterrupt(uint32_t port, uint32_t pad){
    _GPIO_Port_Base_vect = GPIO_base_address + (port * 0x100);
    GPIO(_GPIO_Port_Base_vect)->INTR = (1 << pad);
}

uint32_t GPIO_Read(uint32_t port){
    _GPIO_Port_Base_vect = GPIO_base_address + (port * 0x100);
    return GPIO(_GPIO_Port_Base_vect)->PS;
}