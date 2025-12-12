#include "Sys_Clock.h"

void sys_clk_div(uint32_t prescalar_val){
    //Already clear the existing prescalar divider value
    CLK_SELECT &= ~(prescalar_val);

    //Set the new existing prescalar divider value
    CLK_SELECT |= prescalar_val;
}

//To Disable the divide
void disable_divider(){
    //PERI->DIV_CMD |= (1 << 30);
    *((uint32_t *)0x40010000) = (1<<30);
}

//To Enable the divide
void enable_divider(){
    PERI->DIV_CMD |= (1 << 31);
}

//To configure the Divider
void config_div(uint32_t div_no,uint32_t div_val){
    PERI->DIV_16_CTLx[div_no] = ((div_val-1) << 8);
}

//To config High-Frequency Clock
void config_HFCLK(void){
    PERI->DIV_CMD |= (3<<14) |(63<<8)|(1<<6) | (3 << 0);
}