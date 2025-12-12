#include "timer.h"
uint32_t timer_no = 2;
//To configure the timer 
void config_timer(){

    REGC timer_base = TCPWM_CNTx_Base_Address + (timer_no * timer_size);
}

//Enable the timer
void enable_timer(void){
    TCPWM->CTRL |= (1 << timer_no); 
}

//Disable the timer
void disable_timer(void){
    TCPWM->CTRL &= ~(1 << timer_no); 
    uint32_t ctrl_val = TCPWM->CTRL;

}

//Clear the counter register
void counter_clr(void){
    TCPWM_CNTx->COUNTER = 0; 
}

//Clear the Counter trigger control register 2
void tr_ctrl2_clr(void){
    TCPWM_CNTx->TR_CTRL2= 0; 
}

//Set the period value
void set_period(uint32_t period){
    TCPWM_CNTx->PERIOD = (period - 1); 
}

//Configure the counter mode
void config_counter_mode(uint32_t mode){
    /*
      Counter mode:
      Default Value: 0
        0x0: TIMER: Timer mode
        0x2: CAPTURE: Capture mode
        0x3: QUAD: Quadrature encoding mode
        0x4: PWM:Pulse width modulation (PWM) mode
        0x5: PWM_DT:PWM with deadtime insertion mode
        0x6: PWM_PR:Pseudo random pulse width modulation 
    */
    TCPWM_CNTx->CTRL |= (mode << 24);
}

//Configure the interrupt mask register
void config_intr_mask(uint32_t mode){
    /*
        When mode '0' is selected mask bit is configured for Terminal Count (TC) mode
        When mode '1' is selected mask bit is configured for Capture Count (CC) mode
    */
    TCPWM_CNTx->INTR_MASK |= (1 << mode);
}

//Clear the existing interrupt
void clear_intr(uint32_t mode){
    /*
        When mode '0' is selected interrupt bit is cleared for Terminal Count (TC) mode
        When mode '1' is selected interrupt bit is cleared for Capture Count (CC) mode
    */
    TCPWM_CNTx->INTR |= (1 << mode);
}

//To trigger start the timer in software in the command register
void trig_start(void){
    *((uint32_t *)0x40200008) |= (1 << (TRIG));
}

//To clear the interrupt request register
void clear_intr_req(uint32_t mode){
    TCPWM_CNTx->INTR = (1 << mode);
}