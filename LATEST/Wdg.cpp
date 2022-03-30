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
#define WDG_AR_RELEASE_MAJOR_VERSION                                           4
#define WDG_AR_RELEASE_MINOR_VERSION                                           3

/******************************************************************************/
/* MACROS                                                                     */
/******************************************************************************/
#if(WDG_AR_RELEASE_MAJOR_VERSION != STD_AR_RELEASE_MAJOR_VERSION)
   #error "Incompatible WDG_AR_RELEASE_MAJOR_VERSION!"
#endif

#if(WDG_AR_RELEASE_MINOR_VERSION != STD_AR_RELEASE_MINOR_VERSION)
   #error "Incompatible WDG_AR_RELEASE_MINOR_VERSION!"
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
      FUNC(void, _CODE) InitFunction(
         CONSTP2CONST(CfgModule_TypeAbstract, _CONFIG_DATA, _APPL_CONST) lptrCfgModule
      );
      FUNC(void, WDG_CODE) InitFunction   (void);
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
         0x0000
      ,  0xFFFF
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
   CONSTP2CONST(CfgWdg_Type, CFGWDG_CONFIG_DATA, CFGWDG_APPL_CONST) lptrCfgWdg
){
   if(NULL_PTR == lptrCfgWdg){
#if(STD_ON == Wdg_DevErrorDetect)
      Det_ReportError(
      );
#endif
   }
   else{
// check lptrCfgWdg for memory faults
// use PBcfg_Wdg as back-up configuration
   }
   Wdg.IsInitDone = E_OK;
}

FUNC(void, WDG_CODE) module_Wdg::DeInitFunction(void){
   Wdg.IsInitDone = E_NOT_OK;
}

FUNC(void, WDG_CODE) module_Wdg::MainFunction(void){
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

