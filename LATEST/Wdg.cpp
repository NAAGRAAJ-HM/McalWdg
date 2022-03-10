/*****************************************************/
/* File   : Wdg.cpp                                  */
/* Author : Naagraaj HM                              */
/*****************************************************/

/*****************************************************/
/* #INCLUDES                                         */
/*****************************************************/
#include "module.h"
#include "infWdg_EcuM.h"
#include "infWdg_SchM.h"
#include "Wdg_Unused.h"

/*****************************************************/
/* #DEFINES                                          */
/*****************************************************/

/*****************************************************/
/* MACROS                                            */
/*****************************************************/

/*****************************************************/
/* TYPEDEFS                                          */
/*****************************************************/
class module_Wdg:
      public abstract_module
{
   public:
      FUNC(void, WDG_CODE) InitFunction   (void);
      FUNC(void, WDG_CODE) DeInitFunction (void);
      FUNC(void, WDG_CODE) GetVersionInfo (void);
      FUNC(void, WDG_CODE) MainFunction   (void);
};

/*****************************************************/
/* CONSTS                                            */
/*****************************************************/

/*****************************************************/
/* PARAMS                                            */
/*****************************************************/

/*****************************************************/
/* OBJECTS                                           */
/*****************************************************/
module_Wdg     Wdg;
infEcuMClient* gptrinfEcuMClient_Wdg = &Wdg;
infDcmClient*  gptrinfDcmClient_Wdg  = &Wdg;
infSchMClient* gptrinfSchMClient_Wdg = &Wdg;

/*****************************************************/
/* FUNCTIONS                                         */
/*****************************************************/
FUNC(void, WDG_CODE) module_Wdg::InitFunction(void){
}

FUNC(void, WDG_CODE) module_Wdg::DeInitFunction(void){
}

FUNC(void, WDG_CODE) module_Wdg::GetVersionInfo(void){
}

FUNC(void, WDG_CODE) module_Wdg::MainFunction(void){
}

FUNC(void, WDG_CODE) class_Wdg_Unused::SetMode(void){
}

FUNC(void, WDG_CODE) class_Wdg_Unused::SetTriggerCondition(void){
}

FUNC(void, WDG_CODE) class_Wdg_Unused::GetVersionInfo(void){
}

FUNC(void, WDG_CODE) class_Wdg_Unused::Cbk_GptNotification(void){
}

/*****************************************************/
/* EOF                                               */
/*****************************************************/

