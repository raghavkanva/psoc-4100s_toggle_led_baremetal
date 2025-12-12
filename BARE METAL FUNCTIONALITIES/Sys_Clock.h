#include<stdint.h>
#define _IM     volatile const   //Read-only Permission  
#define _OM     volatile         //write only permission
#define _IOM    volatile         //Read/Write Permission

#define REG uint32_t


//The Clock Select macro 
#define CLK_SELECT *((_IOM uint32_t*) 0x40030028)

#define PERI ((PERI_type *) 0x40010000)

//Structure for Peripheral Interconnect Registers
typedef struct{
    _IOM REG DIV_CMD;           //Divider Command Register
    _IM  REG RESERVED0[63];
    _IOM REG PCLK_CTLx[18];     //Programmable clock control register
    _IM  REG RESERVED1[110];
    _IOM REG DIV_16_CTLx[11];   //Integer Divider control register (for 16.0 divider)
    
    _IOM REG DIV_16_5_CTLx[5];  //Floating Divider control register (for 16.5 divider)
    _IM  REG RESERVED2[59];
    _IOM REG DIV_24_5_CTLx[5];  //Divider control register (for 24.5 divider)   
    _IM  REG RESERVED3[63];
    _IOM REG TR_CTRL;           //Trigger control register
}PERI_type;

void sys_clk_div(uint32_t prescalar_val);
void disable_divider();
void enable_divider();
void config_div(uint32_t div_no,uint32_t div_val);
void config_HFCLK(void);