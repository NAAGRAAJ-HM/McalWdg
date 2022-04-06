/******************************************************************************/
/* File   : Wdg.cpp                                                           */
/* Author : NAGARAJA HM (c) since 1982. All rights reserved.                  */
/******************************************************************************/

/******************************************************************************/
/* #INCLUDES                                                                  */
/******************************************************************************/
#include "Module.hpp"
#include "infWdg_EcuM.hpp"
#include "infWdg_Dcm.hpp"
#include "infWdg_SchM.hpp"

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
class module_Wdg:
      public abstract_module
{
   public:
      module_Wdg(Std_TypeVersionInfo lVersionInfo) : abstract_module(lVersionInfo){
      }
      FUNC(void, WDG_CODE) InitFunction(
         CONSTP2CONST(CfgModule_TypeAbstract, WDG_CONFIG_DATA, WDG_APPL_CONST) lptrCfgModule
      );
      FUNC(void, WDG_CODE) DeInitFunction (void);
      FUNC(void, WDG_CODE) MainFunction   (void);
};

extern VAR(module_Wdg, WDG_VAR) Wdg;

/******************************************************************************/
/* CONSTS                                                                     */
/******************************************************************************/
CONSTP2VAR(infEcuMClient, WDG_VAR, WDG_CONST) gptrinfEcuMClient_Wdg = &Wdg;
CONSTP2VAR(infDcmClient,  WDG_VAR, WDG_CONST) gptrinfDcmClient_Wdg  = &Wdg;
CONSTP2VAR(infSchMClient, WDG_VAR, WDG_CONST) gptrinfSchMClient_Wdg = &Wdg;

/******************************************************************************/
/* PARAMS                                                                     */
/******************************************************************************/
#include "CfgWdg.hpp"

/******************************************************************************/
/* OBJECTS                                                                    */
/******************************************************************************/
VAR(module_Wdg, WDG_VAR) Wdg(
   {
         WDG_AR_RELEASE_VERSION_MAJOR
      ,  WDG_AR_RELEASE_VERSION_MINOR
      ,  0x00
      ,  0xFF
      ,  0x01
      ,  '0'
      ,  '1'
      ,  '0'
   }
);

/******************************************************************************/
/* FUNCTIONS                                                                  */
/******************************************************************************/
FUNC(void, WDG_CODE) module_Wdg::InitFunction(
   CONSTP2CONST(CfgModule_TypeAbstract, WDG_CONFIG_DATA, WDG_APPL_CONST) lptrCfgModule
){
#if(STD_ON == Wdg_InitCheck)
   if(E_OK == IsInitDone){
#if(STD_ON == Wdg_DevErrorDetect)
      Det_ReportError(
      );
#endif
   }
   else{
#endif
      if(NULL_PTR == lptrCfgModule){
#if(STD_ON == Wdg_DevErrorDetect)
         Det_ReportError(
         );
#endif
      }
      else{
// check lptrCfgModule for memory faults
// use PBcfg_Wdg as back-up configuration
      }
      IsInitDone = E_OK;
#if(STD_ON == Wdg_InitCheck)
   }
#endif
}

FUNC(void, WDG_CODE) module_Wdg::DeInitFunction(void){
#if(STD_ON == Wdg_InitCheck)
   if(E_OK != IsInitDone){
#if(STD_ON == Wdg_DevErrorDetect)
      Det_ReportError(
      );
#endif
   }
   else{
#endif
      IsInitDone = E_NOT_OK;
#if(STD_ON == Wdg_InitCheck)
   }
#endif
}

FUNC(void, WDG_CODE) module_Wdg::MainFunction(void){
#if(STD_ON == Wdg_InitCheck)
   if(E_OK != IsInitDone){
#if(STD_ON == Wdg_DevErrorDetect)
      Det_ReportError(
      );
#endif
   }
   else{
#endif
#if(STD_ON == Wdg_InitCheck)
   }
#endif
}

class class_Wdg_Unused{
   public:
      FUNC(void, WDG_CODE) SetMode             (void);
      FUNC(void, WDG_CODE) SetTriggerCondition (void);
      FUNC(void, WDG_CODE) Cbk_GptNotification (void);
};

FUNC(void, WDG_CODE) class_Wdg_Unused::SetMode(void){
}

FUNC(void, WDG_CODE) class_Wdg_Unused::SetTriggerCondition(void){
}

FUNC(void, WDG_CODE) class_Wdg_Unused::Cbk_GptNotification(void){
}

/******************************************************************************/
/* EOF                                                                        */
/******************************************************************************/

