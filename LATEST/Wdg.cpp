/******************************************************************************/
/* File   : Wdg.cpp                                                           */
/* Author : NAGARAJA HM (c) since 1982. All rights reserved.                  */
/******************************************************************************/

/******************************************************************************/
/* #INCLUDES                                                                  */
/******************************************************************************/
#include "Module.hpp"
#include "CfgWdg.hpp"
#include "Wdg_core.hpp"
#include "infWdg.hpp"

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
   ,  public class_Wdg_Functionality
{
   private:
/******************************************************************************/
/* OBJECTS                                                                    */
/******************************************************************************/
            Std_TypeReturn          IsInitDone{E_NOT_OK};
      const CfgModule_TypeAbstract* lptrCfg{(CfgModule_TypeAbstract*)NULL_PTR};

   public:
      module_Wdg(Std_TypeVersionInfo lVersionInfo) : abstract_module(lVersionInfo){
      }
      FUNC(void, WDG_CODE) InitFunction(
         CONSTP2CONST(CfgModule_TypeAbstract, WDG_CONFIG_DATA, WDG_APPL_CONST) lptrCfgModule
      );
      FUNC(void, WDG_CODE) DeInitFunction (void);
      FUNC(void, WDG_CODE) MainFunction   (void);
      WDG_CORE_FUNCTIONALITIES
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
   if(
         E_OK
      != IsInitDone
   ){
#endif
      if(NULL_PTR != lptrCfgModule){
         if(STD_HIGH){
            lptrCfg = lptrCfgModule;
         }
         else{
            lptrCfg = &PBcfgWdg;
         }
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

FUNC(void, WDG_CODE) module_Wdg::DeInitFunction(void){
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

FUNC(void, WDG_CODE) module_Wdg::MainFunction(void){
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

FUNC(void, WDG_CODE) module_Wdg::SetMode(void){
}

FUNC(void, WDG_CODE) module_Wdg::SetTriggerCondition(void){
}

FUNC(void, WDG_CODE) module_Wdg::Cbk_GptNotification(void){
}

/******************************************************************************/
/* EOF                                                                        */
/******************************************************************************/

