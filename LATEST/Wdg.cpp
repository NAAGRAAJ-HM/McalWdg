/******************************************************************************/
/* File   : Wdg.cpp                                                           */
/* Author : NAGARAJA HM (c) since 1982. All rights reserved.                  */
/******************************************************************************/

/******************************************************************************/
/* #INCLUDES                                                                  */
/******************************************************************************/
#include "Module.hpp"
#include "Wdg.hpp"
#include "infWdg_Imp.hpp"

/******************************************************************************/
/* #DEFINES                                                                   */
/******************************************************************************/
#define WDG_AR_RELEASE_VERSION_MAJOR                                           4
#define WDG_AR_RELEASE_VERSION_MINOR                                           3

/******************************************************************************/
/* MACROS                                                                     */
/******************************************************************************/
#if(WDG_AR_RELEASE_VERSION_MAJOR != STD_AR_RELEASE_VERSION_MAJOR)
   #error "Incompatible WDG_AR_RELEASE_VERSION_MAJOR!"
#endif

#if(WDG_AR_RELEASE_VERSION_MINOR != STD_AR_RELEASE_VERSION_MINOR)
   #error "Incompatible WDG_AR_RELEASE_VERSION_MINOR!"
#endif

/******************************************************************************/
/* TYPEDEFS                                                                   */
/******************************************************************************/

/******************************************************************************/
/* CONSTS                                                                     */
/******************************************************************************/
CONSTP2VAR(infEcuMClient, WDG_VAR, WDG_CONST) gptrinfEcuMClient_Wdg = &Wdg;

/******************************************************************************/
/* PARAMS                                                                     */
/******************************************************************************/

/******************************************************************************/
/* OBJECTS                                                                    */
/******************************************************************************/
VAR(module_Wdg, WDG_VAR) Wdg;

/******************************************************************************/
/* FUNCTIONS                                                                  */
/******************************************************************************/
FUNC(void, WDG_CODE) module_Wdg::InitFunction(
   CONSTP2CONST(CfgModule_TypeAbstract, WDG_CONFIG_DATA, WDG_APPL_CONST) lptrCfgModule
){
#if(STD_ON == Wdg_InitCheck)
   if(
         E_OK
      != IsInitDone
   ){
#endif
      if(NULL_PTR != lptrCfgModule){
         lptrCfg = lptrCfgModule;
      }
      else{
#if(STD_ON == Wdg_DevErrorDetect)
         Det_ReportError(
               0 //TBD: IdModule
            ,  0 //TBD: IdInstance
            ,  0 //TBD: IdApi
            ,  0 //TBD: IdError
         );
#endif
      }
#if(STD_ON == Wdg_InitCheck)
      IsInitDone = E_OK;
   }
   else{
#if(STD_ON == Wdg_DevErrorDetect)
      Det_ReportError(
            0 //TBD: IdModule
         ,  0 //TBD: IdInstance
         ,  0 //TBD: IdApi
         ,  WDG_E_UNINIT
      );
#endif
   }
#endif
}

FUNC(void, WDG_CODE) module_Wdg::DeInitFunction(
   void
){
#if(STD_ON == Wdg_InitCheck)
   if(
         E_OK
      == IsInitDone
   ){
#endif
#if(STD_ON == Wdg_InitCheck)
      IsInitDone = E_NOT_OK;
   }
   else{
#if(STD_ON == Wdg_DevErrorDetect)
      Det_ReportError(
            0 //TBD: IdModule
         ,  0 //TBD: IdInstance
         ,  0 //TBD: IdApi
         ,  WDG_E_UNINIT
      );
#endif
   }
#endif
}

FUNC(void, WDG_CODE) module_Wdg::MainFunction(
   void
){
#if(STD_ON == Wdg_InitCheck)
   if(
         E_OK
      == IsInitDone
   ){
#endif
#if(STD_ON == Wdg_InitCheck)
   }
   else{
#if(STD_ON == Wdg_DevErrorDetect)
      Det_ReportError(
            0 //TBD: IdModule
         ,  0 //TBD: IdInstance
         ,  0 //TBD: IdApi
         ,  WDG_E_UNINIT
      );
#endif
   }
#endif
}

FUNC(void, WDG_CODE) module_Wdg::SetMode(
   void
){
}

FUNC(void, WDG_CODE) module_Wdg::SetTriggerCondition(
   void
){
}

FUNC(void, WDG_CODE) module_Wdg::Cbk_GptNotification(
   void
){
}

/******************************************************************************/
/* EOF                                                                        */
/******************************************************************************/

