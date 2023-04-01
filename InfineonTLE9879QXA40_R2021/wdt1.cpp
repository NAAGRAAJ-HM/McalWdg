/******************************************************************************/
/* File   : Template.hpp                                                      */
/*                                                                            */
/* Author : Nagaraja HULIYAPURADA MATA                                        */
/*                                                                            */
/* License / Warranty / Terms and Conditions                                  */
/*                                                                            */
/* Everyone is permitted to copy and distribute verbatim copies of this lice- */
/* nse document, but changing it is not allowed. This is a free, copyright l- */
/* icense for software and other kinds of works. By contrast, this license is */
/* intended to guarantee your freedom to share and change all versions of a   */
/* program, to make sure it remains free software for all its users. You have */
/* certain responsibilities, if you distribute copies of the software, or if  */
/* you modify it: responsibilities to respect the freedom of others.          */
/*                                                                            */
/* All rights reserved. Copyright © 1982 Nagaraja HULIYAPURADA MATA           */
/*                                                                            */
/* Always refer latest software version from:                                 */
/* https://github.com/NagarajaHuliyapuradaMata?tab=repositories               */
/*                                                                            */
/******************************************************************************/

/******************************************************************************/
/* #INCLUDES                                                                  */
/******************************************************************************/
#include "types.hpp"

#include "uC_Scu.hpp"

#include "wdt1.hpp"

#include "scu_defines.hpp"

/******************************************************************************/
/* #DEFINES                                                                   */
/******************************************************************************/
#define SYSTICK_DELAY_THRESHOLD 100U

/******************************************************************************/
/* MACROS                                                                     */
/******************************************************************************/

/******************************************************************************/
/* TYPEDEFS                                                                   */
/******************************************************************************/

/******************************************************************************/
/* CONSTS                                                                     */
/******************************************************************************/

/******************************************************************************/
/* PARAMS                                                                     */
/******************************************************************************/

/******************************************************************************/
/* OBJECTS                                                                    */
/******************************************************************************/
uint32 WD_Counter;
static bool bSOWactive;

/******************************************************************************/
/* FUNCTIONS                                                                  */
/******************************************************************************/
/*
void WDT1_Init(void){
   SCUPM.WDT1_TRIG.reg = (uint8) SCUPM_WDT1_TRIG;
   WD_Counter = 0u;
   bSOWactive = false;
}

void SysTick_Init(void){
   CPU.SYSTICK_RL.reg = (uint32)SysTickRL;
   CPU.SYSTICK_CUR.reg = 0u;
   CPU.SYSTICK_CS.bit.CLKSOURCE = 1u;
   CPU.SYSTICK_CS.bit.TICKINT = 1u;
   CPU.SYSTICK_CS.bit.ENABLE = 1u;
}

void WDT1_Stop(void){
   CPU.SYSTICK_CS.bit.ENABLE = 0u;
}
*/
bool WDT1_Service(void){
   bool bResult;
   bResult = false;
   if(
         (WD_Counter > (uint32)SCUPM_WDT1_TRIGGER)
      || (bSOWactive == true)
   ){
      SCUPM.WDT1_TRIG.reg = (uint8) SCUPM_WDT1_TRIG;
      WD_Counter = 0u;
      bSOWactive = false;
      bResult = true;
   }
   return(bResult);
}
/*
void WDT1_SOW_Service(uint32 NoOfSOW){
   SCUPM.WDT1_TRIG.reg = (NoOfSOW & 3u) << 6u;
   bSOWactive = true;
}

void Delay_us(uint32 delay_time_us){
   uint32 systick_target_val;
   uint32 systick_val;
   uint32 delay_count;
   uint32 systick_cur;
   uint32 systick_rl;
   systick_rl = SysTick_ReloadValue_Get();
   do{
      systick_val = SysTick_Value_Get();
   }while((systick_val < SYSTICK_DELAY_THRESHOLD) || (systick_val > (systick_rl - SYSTICK_DELAY_THRESHOLD)));
   while(delay_time_us >= (uint32)1000){
      while(SysTick_Value_Get() < systick_val){}
      while(SysTick_Value_Get() > systick_val){}
      delay_time_us -= (uint32)1000;
   }
   delay_count = delay_time_us * (uint32)One_us;
   systick_val = SysTick_Value_Get();
   if( systick_val >= delay_count){
      systick_target_val = systick_val - delay_count;
      do{
         systick_cur = SysTick_Value_Get();
      }
      while((systick_cur > systick_target_val) && (systick_cur < systick_val));
   }
   else{
      systick_target_val = systick_rl - ( delay_count - systick_val );
      while(SysTick_Value_Get() < systick_val){}
      while(SysTick_Value_Get() > systick_target_val){}
   }
   return;
}

void WDT1_Window_Count(void){
  WD_Counter++;
}

uint32 SysTick_Value_Get(void){
   return CPU.SYSTICK_CUR.reg;
}

uint32 SysTick_ReloadValue_Get(void){
   return(CPU.SYSTICK_RL.reg);
}

void SysTick_ReloadValue_Set(uint32 val){
  CPU.SYSTICK_RL.reg = val;
}
*/
/******************************************************************************/
/* EOF                                                                        */
/******************************************************************************/

