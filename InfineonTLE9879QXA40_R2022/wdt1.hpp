#pragma once
/******************************************************************************/
/* File   : wdt1.hpp                                                          */
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

/******************************************************************************/
/* #DEFINES                                                                   */
/******************************************************************************/
#define One_us                                     ((uint32)SCU_FSYS / 1000000u)
#define SysTickRL                       ((uint32)SCU_FSYS / (uint32)SysTickFreq)
#define SysTickFreq                                                        1000u

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
extern uint32 WD_Counter;

/******************************************************************************/
/* FUNCTIONS                                                                  */
/******************************************************************************/
extern void   WDT1_Init                                                  (void);
extern void   SysTick_Init                                               (void);
extern void   WDT1_Stop                                                  (void);
extern bool   WDT1_Service                                               (void);
extern void   WDT1_SOW_Service                                 (uint32 NoOfSOW);
extern void   Delay_us                                   (uint32 delay_time_us);
extern void   WDT1_Window_Count                                          (void);
extern uint32 SysTick_Value_Get                                          (void);
extern void   SysTick_ReloadValue_Set                              (uint32 val);

/******************************************************************************/
/* EOF                                                                        */
/******************************************************************************/

