#include <stdio.h>
#include <stdint.h>
#include "nvic.h"
#include "gpio.h"



uint8_t app_heap[512] __attribute__((section(".heap")));
uint8_t app_stack[4096] __attribute__((section(".stack")));

volatile uint32_t startFlag  __attribute__((used)) = 0;
volatile uint32_t invertFLag  __attribute__((used)) = 1;

volatile uint32_t* addr = &startFlag;


int main()
{
    //Enable the interrupt at the CPU Level 
    enable_irq();

    GPIO_ConfigMultipleLeds(9);
    GPIO_ConfigDriveMode(3, 7, 1);

    //Enable the Interrupt at Peripheral Level
    GPIO_ConfigInterrupt(3, 7, 2);

    //Enable the Interrupt in NVIC
    NVIC_enable_IRQ(3);
    NVIC_SetPriority(3, 3);
    NVIC_Clear_pending(3);

    while (1)
    {
        //Till a button is pressed, no activity happens, no functions are activated
        if (startFlag == 0)
        {
            continue;
        }

        if (invertFLag == 0u)
        {
            GPIO_ReverseSequenceBLink(9);
        }
        else
        {
            
            GPIO_ForwardSequenceBlink(9);
        }
    }
}

// Interrupt HAndler
void ioss_interrupts_gpio_3_IRQHandler(void)
{
    uint32_t readVal;
    GPIO_ClearInterrupt(3,7);
    readVal = GPIO_Read(3);
    volatile uint32_t* addr2 = &startFlag;

    if (((readVal >> 7) & 1) == 0u)
    {
        if (startFlag == 0)
        {
            startFlag = 1; //To indicate that the button is pressed one time
        }
        else
        {
            invertFLag ^= 1; //To change the sequence
        }
    }
   
}

