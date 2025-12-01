#  Bare-Metal GPIO & Interrupt Handling on CY8CKIT-149 (PSoC 4100S)

This project demonstrates **bare-metal programming** on the **Infineon CY8CKIT-149 PSoC 4100S** board without using CMSIS, HAL, or PDL libraries.  
The objective is to **toggle an LED sequence when a button press interrupt is detected**, implemented entirely using **direct register-level programming**.



##  Project Overview

### ✔ Implemented Features
- Direct **NVIC configuration**
  - Set interrupt priority  
  - Enable & disable IRQs  
  - Clear & set pending interrupts  
- Direct **GPIO peripheral configuration**
  - Pin drive mode setup  
  - Default output state configuration  
  - Peripheral interrupt configuration (falling-edge trigger)
- Custom **Interrupt Service Routine (ISR)** for button handling  
- LED sequence toggling logic  
- Debugging with logic analyzer

---

## 🛠 Hardware Used
- **Infineon CY8CKIT-149 PSoC 4100S** development board  
- Onboard **User Button** (P3.7)  
- Onboard **User LEDs**

---

## Learning Highlights

This project was completed as part of the **Infineon Technologies Embedded Systems Cohort 3** program.  
Every component was built **from scratch**, including:

- NVIC register-level setup  
- GPIO register configuration  
- Writing & mapping custom ISRs  
- Understanding vector tables and startup code  
- Handling interrupt triggering and clearance  
- Debugging peripheral interrupts using logic analyzer  

During debugging, the system entered the ISR but never returned to thread mode.  
The root cause was failing to **clear the interrupt flag at the GPIO peripheral**, causing the interrupt to retrigger instantly.

Fixing this completed the functionality and highlighted the importance of **systematic debugging in embedded systems**.

---

## 🙏 Acknowledgments

I sincerely thank **Balajee Sir, Balasubramanian Lakshminarayanan Sir, and Prakash Sir** for their constant support and motivation.  
I would also like to thank **Vinay Sir, Ananth Sir, Siddesh Sir, and Vijaykumar Sir** for their dedicated teaching and guidance.

---

## 📂 Repository Structure

