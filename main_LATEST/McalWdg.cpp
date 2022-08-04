/******************************************************************************/
/* File   : McalWdg.cpp                                                           */
/* Author : NAGARAJA HM (c) since 1982. All rights reserved.                  */
/******************************************************************************/

/******************************************************************************/
/* #INCLUDES                                                                  */
/******************************************************************************/
#include "Module.hpp"
#include "McalWdg.hpp"
#include "infMcalWdg_Imp.hpp"

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

/******************************************************************************/
/* PARAMS                                                                     */
/******************************************************************************/

/******************************************************************************/
/* OBJECTS                                                                    */
/******************************************************************************/
VAR(module_McalWdg, WDG_VAR) McalWdg;

/******************************************************************************/
/* FUNCTIONS                                                                  */
/******************************************************************************/
FUNC(void, WDG_CODE) module_McalWdg::InitFunction(
      CONSTP2CONST(ConstModule_TypeAbstract, WDG_CONST,       WDG_APPL_CONST) lptrConstModule
   ,  CONSTP2CONST(CfgModule_TypeAbstract,   WDG_CONFIG_DATA, WDG_APPL_CONST) lptrCfgModule
){
#if(STD_ON == McalWdg_InitCheck)
   if(
         E_OK
      != IsInitDone
   ){
#endif
      if(
            (NULL_PTR != lptrConstModule)
         && (NULL_PTR != lptrCfgModule)
      ){
         lptrConst = (const ConstMcalWdg_Type*)lptrConstModule;
         lptrCfg   = lptrCfgModule;
      }
      else{
#if(STD_ON == McalWdg_DevErrorDetect)
         ServiceDet_ReportError(
               0 //TBD: IdModule
            ,  0 //TBD: IdInstance
            ,  0 //TBD: IdApi
            ,  0 //TBD: IdError
         );
#endif
      }
#if(STD_ON == McalWdg_InitCheck)
      IsInitDone = E_OK;
   }
   else{
#if(STD_ON == McalWdg_DevErrorDetect)
      ServiceDet_ReportError(
            0 //TBD: IdModule
         ,  0 //TBD: IdInstance
         ,  0 //TBD: IdApi
         ,  WDG_E_UNINIT
      );
#endif
   }
#endif
}

FUNC(void, WDG_CODE) module_McalWdg::DeInitFunction(
   void
){
#if(STD_ON == McalWdg_InitCheck)
   if(
         E_OK
      == IsInitDone
   ){
#endif
#if(STD_ON == McalWdg_InitCheck)
      IsInitDone = E_NOT_OK;
   }
   else{
#if(STD_ON == McalWdg_DevErrorDetect)
      ServiceDet_ReportError(
            0 //TBD: IdModule
         ,  0 //TBD: IdInstance
         ,  0 //TBD: IdApi
         ,  WDG_E_UNINIT
      );
#endif
   }
#endif
}

FUNC(void, WDG_CODE) module_McalWdg::MainFunction(
   void
){
#if(STD_ON == McalWdg_InitCheck)
   if(
         E_OK
      == IsInitDone
   ){
#endif
#if(STD_ON == McalWdg_InitCheck)
   }
   else{
#if(STD_ON == McalWdg_DevErrorDetect)
      ServiceDet_ReportError(
            0 //TBD: IdModule
         ,  0 //TBD: IdInstance
         ,  0 //TBD: IdApi
         ,  WDG_E_UNINIT
      );
#endif
   }
#endif
}

FUNC(void, WDG_CODE) module_McalWdg::SetMode(
   void
){
}

FUNC(void, WDG_CODE) module_McalWdg::SetTriggerCondition(
   void
){
}

FUNC(void, WDG_CODE) module_McalWdg::Cbk_McalGptNotification(
   void
){
}

/******************************************************************************/
/* EOF                                                                        */
/******************************************************************************/

