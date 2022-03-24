/******************************************************************************/
/* File   : Wdg.cpp                                                           */
/* Author : NAGARAJA HM (c) since 1982. All rights reserved.                  */
/******************************************************************************/

/******************************************************************************/
/* #INCLUDES                                                                  */
/******************************************************************************/
#include "module.h"
#include "CfgWdg.h"
#include "infWdg_EcuM.h"
#include "infWdg_Dcm.h"
#include "infWdg_SchM.h"

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
      FUNC(void, WDG_CODE) InitFunction   (void);
      FUNC(void, WDG_CODE) DeInitFunction (void);
      FUNC(void, WDG_CODE) GetVersionInfo (void);
      FUNC(void, WDG_CODE) MainFunction   (void);

   private:
      CONST(Std_TypeVersionInfo, WDG_CONST) VersionInfo = {
            0x0000
         ,  0xFFFF
         ,  0x01
         ,  '0'
         ,  '1'
         ,  '0'
      };
};

/******************************************************************************/
/* CONSTS                                                                     */
/******************************************************************************/

/******************************************************************************/
/* PARAMS                                                                     */
/******************************************************************************/

/******************************************************************************/
/* OBJECTS                                                                    */
/******************************************************************************/
VAR(module_Wdg, WDG_VAR) Wdg;
CONSTP2VAR(infEcuMClient, WDG_VAR, WDG_CONST) gptrinfEcuMClient_Wdg = &Wdg;
CONSTP2VAR(infDcmClient,  WDG_VAR, WDG_CONST) gptrinfDcmClient_Wdg  = &Wdg;
CONSTP2VAR(infSchMClient, WDG_VAR, WDG_CONST) gptrinfSchMClient_Wdg = &Wdg;

/******************************************************************************/
/* FUNCTIONS                                                                  */
/******************************************************************************/
FUNC(void, WDG_CODE) module_Wdg::InitFunction(void){
   Wdg.IsInitDone = E_OK;
}

FUNC(void, WDG_CODE) module_Wdg::DeInitFunction(void){
   Wdg.IsInitDone = E_NOT_OK;
}

FUNC(void, WDG_CODE) module_Wdg::GetVersionInfo(void){
#if(STD_ON == Wdg_DevErrorDetect)
//TBD: API parameter check
   Det_ReportError(
   );
#endif
}

FUNC(void, WDG_CODE) module_Wdg::MainFunction(void){
}

#include "Wdg_Unused.h"

FUNC(void, WDG_CODE) class_Wdg_Unused::SetMode(void){
}

FUNC(void, WDG_CODE) class_Wdg_Unused::SetTriggerCondition(void){
}

FUNC(void, WDG_CODE) class_Wdg_Unused::Cbk_GptNotification(void){
}

/******************************************************************************/
/* EOF                                                                        */
/******************************************************************************/

