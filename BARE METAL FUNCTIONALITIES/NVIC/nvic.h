#include <stdint.h>
#define _IOM volatile

#define NVIC_BASE 0xE000E100            //NVIC Base Address
#define NVIC ((NVIC_type *) NVIC_BASE)  //NVIC_type Struct Config Address

// For the byte offest configuration in the Interrupt Priority Register
#define byte_offset(IRQn) ((uint32_t)(IRQn / 4))

//For Selecting the IPR Register according to the IRQn
#define IRQ_vector(byte_offset) (NVIC->IPR[byte_offset])

//For Defining the Bit offset for priority seeting in the IPR 
#define bit_offset(IRQn) ((uint32_t)(IRQn % 4))

//Prepars the priority bit for the further priority set operation
#define priority_offset(priority) ((uint32_t) priority << 6)

//Struct Configuration for Easy access of NVIC Registers

typedef struct{
    _IOM uint32_t ISER;                 //Interrupt Set Enable (SETENA) Register
        uint32_t reserved0[0x1FU];
    _IOM uint32_t ICER;                 //Interrupt Clear Enable Register
        uint32_t reserved1[0x1FU];
    _IOM uint32_t ISPR;                 //Interrupt Set Pending Register
        uint32_t reserved2[0x1FU];
    _IOM uint32_t ICPR;                 //Interrupt Clear Pending Register
        uint32_t reserved3[0x5EU];
    _IOM uint32_t IPR[8];               //Interrupt Priority Register
}NVIC_type;


//Function Declarations

//To enable the interrupt at CPU Level
void enable_irq(void);

//To disable the interrupt at CPU Level
void disable_irq(void);

//To enable the interrupt at NVIC
void NVIC_enable_IRQ(uint8_t IRQn);

//To clear the interrupt at NVIC
void NVIC_Clear_pending(uint8_t IRQn);

//To set the priority of the interrupt
void NVIC_SetPriority(uint8_t IRQn, uint8_t priority);

//To disable the interrupt at NVIC
void NVIC_disable_IRQ(uint8_t IRQn);

//To set the interrupt at NVIC at pending state
void NVIC_Set_pending(uint8_t IRQn);

