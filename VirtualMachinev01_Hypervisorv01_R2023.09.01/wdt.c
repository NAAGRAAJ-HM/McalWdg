#include "wdt.hpp"
#include "device.hpp"

void Wdt_ShowTrigger(void){
#ifdef SHOW_WDT_ON_TP2
  static uint8 ui8Ct;
  ui8Ct++;
  if(ui8Ct&0x01)
    TP2 (1);
  else
    TP2 (0);
#endif
}

void Wdt_InitWD0(void){
  WDTA0.MD = (uint8) 0x47;
}

void Wdt_TriggerWD0(void){
  WDTA0.WDTE = (uint8) 0xAC;
  Wdt_ShowTrigger();
}

void Wdt_InitWD1(void){
  WDTA1.MD = (uint8 )0x07;   //ToTime = 2^9/240kHz = 2.1ms, no IRQ, generate reset, window 100%
}

void Wdt_TriggerWD1(void){
  WDTA1.WDTE = (uint8) 0xAC;
}

