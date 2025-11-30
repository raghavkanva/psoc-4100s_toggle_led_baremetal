#include<stdint.h>
#include "nvic.h"

void NVIC_SetPriority(uint8_t IRQn, uint8_t priority){
    IRQ_vector(byte_offset(IRQn)) &= ~(0xFF << (bit_offset(IRQn)*8));  //Clear the existing priority first
    IRQ_vector(byte_offset(IRQn)) |=  (priority_offset(priority) << (bit_offset(IRQn)*8));  //Set the priority     
} 

void NVIC_enable_IRQ(uint8_t IRQn){
    NVIC->ISER |=  (1 << IRQn);     //Set the interrupt
}

void NVIC_disable_IRQ(uint8_t IRQn){
    NVIC->ICER |=  (1 << IRQn);     //Clear the interrupt
}
void NVIC_Clear_pending(uint8_t IRQn){
    NVIC->ICPR |=  (1 << IRQn);     //Set the interrupt-clear bit
}
void NVIC_Set_pending(uint8_t IRQn){
    NVIC->ISPR |=  (1 << IRQn);     //Set the interrupt-set bit
}

//Enables the Interrupt Request in the CPU Level
void enable_irq(){
    __asm__ volatile ("cpsie i " : : : "memory");
}

//Disables the Interrupt Request in the CPU Level
void disable_irq(){
    __asm__ volatile ("cpsid i " : : : "memory");
}