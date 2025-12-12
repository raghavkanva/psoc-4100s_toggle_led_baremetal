#include <stdint.h>

#define _IM     volatile const   //Read-only Permission  
#define _OM     volatile         //write only permission
#define _IOM    volatile         //Read/Write Permission

#define REG uint32_t
#define REGC volatile const uint32_t

//Macro for timer split size
#define timer_size 0x40u

//Define Macros for the TCPWM Timer Instance Structure
#define TCPWM_CNTx_Base_Address 0x40200100u
#define TCPWM_CNTx_Base_Address_TIMER_x(timer_base) (timer_base)
#define TCPWM_CNTx ((TCPWM_CNTx_type *) 0x40200180u)



//Define Macros for the TCPWM Global Registers Structure
#define TCPWM_Base_Address 0x40200000u
#define TCPWM ((TCPWM_type *) TCPWM_Base_Address)

//define the trigger bit
#define TRIG 26

#define TIMER_BASE_ADDRESS 

//Struct for defining registers of Timer Instance 
typedef struct{
    _IOM REG CTRL;              //Counter Control Register
    _IM  REG STATUS;            //Counter status register
    _IOM REG COUNTER;           //Counter count Register
    _IOM REG CC;                //Counter compare/capture register
    _IOM REG CC_BUFF;           //Counter buffered compare /capture register
    _IOM REG PERIOD;            //Counter period register
    _IOM REG PERIOD_BUFF;       //Counter buffered period register   
    _IM  REG RESERVED_0;
    _IOM REG TR_CTRL0;          //Counter trigger control register 0
    _IOM REG TR_CTRL1;          //Counter trigger control register 1
    _IOM REG TR_CTRL2;          //Counter trigger control register 2
    _IM  REG RESERVED_1;
    _IOM REG INTR;              //Interrupt request register
    _IOM REG INTR_SET;          //Interrupt set register
    _IOM REG INTR_MASK;         //Interrupt mask register
    _IOM REG INTR_MASKED;       //Interrupt masked request register
}TCPWM_CNTx_type;


//Struct for defining global timer registers
typedef struct{
    _IOM REG CTRL;              //TCPWM control register 0
    _IM REG RESEVED;
    _IOM REG CMD;               //TCPWM command register
    _IM REG INTR_CAUSE;         //TCPWM Counter interrupt cause register
}TCPWM_type;

//Function Declarations
void config_timer();
void enable_timer(void);
void disable_timer(void);
void counter_clr(void);
void tr_ctrl2_clr(void);
void set_period(uint32_t period);
void config_counter_mode(uint32_t mode);
void config_intr_mask(uint32_t mode);
void clear_intr(uint32_t mode);
void trig_start(void);
void clear_intr_req(uint32_t mode);