/******************************************************************************/
/* File   : McalWdg.c                                                         */
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
/* https://github.com/RaajnaagHuliyapuradaMata?tab=repositories               */
/*                                                                            */
/******************************************************************************/

/******************************************************************************/
/* #INCLUDES                                                                  */
/******************************************************************************/
#include "Std_Types.h"

#include "CfgMcalWdg.h"

#include "infMcalWdgSwcServiceEcuM.h"
#include "infMcalWdgSwcApplStartUp.h"

#include "uC_Wdg.h"

/******************************************************************************/
/* #DEFINES                                                                   */
/******************************************************************************/

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
static boolean McalWdg_bFlagInit;

/******************************************************************************/
/* FUNCTIONS                                                                  */
/******************************************************************************/
FUNC(void, MCALWDG_CODE) infMcalWdg_vInitWdg0(void){
   WDTA0.MD = (uint8)0x47;
}

FUNC(void, MCALWDG_CODE) infMcalWdg_vInitWdg1(void){
   WDTA1.MD = (uint8)0x07;
}

#ifdef FEATURE_WdgShowOnTP2
static FUNC(void, MCALWDG_CODE) vShowTrigger(void){
   static uint8 u8Count;
   if(++u8Count & 0x01) TP2(1);
   else                 TP2(0);
}
#endif

FUNC(void, MCALWDG_CODE) infMcalWdg_vTriggerWdg0(void){
   WDTA0.WDTE = (uint8)0xAC;
#ifdef FEATURE_WdgShowOnTP2
   vShowTrigger();
#endif
}

FUNC(void, MCALWDG_CODE) infMcalWdg_vTriggerWdg1(void){
   WDTA1.WDTE = (uint8)0xAC;
}

FUNC(void, MCALWDG_CODE) infMcalWdgSwcApplStartUp_vClrFlagInit(void){
   McalWdg_bFlagInit = FALSE;
}

FUNC(void, MCALWDG_CODE) infMcalWdgSwcApplStartUp_vSetFlagInit(void){
   McalWdg_bFlagInit = TRUE;
}

FUNC(boolean, MCALWDG_CODE) infMcalWdgSwcApplStartUp_bGetFlagInit(void){
   return(
         FALSE
      != McalWdg_bFlagInit
   );
}

FUNC(void, MCALWDG_CODE) infMcalWdgSwcServiceEcuM_vInitFunction(void){
   infMcalWdg_vInitWdg0();
   infMcalWdg_vTriggerWdg0();
}

/******************************************************************************/
/* EOF                                                                        */
/******************************************************************************/

