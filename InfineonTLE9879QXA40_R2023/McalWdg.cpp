/******************************************************************************/
/* File   : McalWdg.cpp                                                       */
/* Author : Nagaraja HULIYAPURADA-MATA                                        */
/* Date   : 01.02.1982                                                        */
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
VAR(module_McalWdg, MCALWDG_VAR) McalWdg;

/******************************************************************************/
/* FUNCTIONS                                                                  */
/******************************************************************************/
FUNC(void, MCALWDG_CODE) module_McalWdg::InitFunction(
      CONSTP2CONST(ConstModule_TypeAbstract, MCALWDG_CONST,       MCALWDG_APPL_CONST) lptrNvMBlocksRomModule
   ,  CONSTP2CONST(CfgModule_TypeAbstract,   MCALWDG_CONFIG_DATA, MCALWDG_APPL_CONST) lptrCfgModule
){
#if(STD_ON == McalWdg_InitCheck)
   if(
         E_OK
      != IsInitDone
   ){
#endif
      if(
            (NULL_PTR != lptrNvMBlocksRomModule)
         && (NULL_PTR != lptrCfgModule)
      ){
         lptrNvMBlocksRom = lptrNvMBlocksRomModule;
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
         ,  MCALWDG_E_UNINIT
      );
#endif
   }
#endif
}

FUNC(void, MCALWDG_CODE) module_McalWdg::DeInitFunction(
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
         ,  MCALWDG_E_UNINIT
      );
#endif
   }
#endif
}

#include "wdt1.hpp"
FUNC(void, MCALWDG_CODE) module_McalWdg::MainFunction(
   void
){
#if(STD_ON == McalWdg_InitCheck)
   if(
         E_OK
      == IsInitDone
   ){
#endif

   (void)WDT1_Service();

#if(STD_ON == McalWdg_InitCheck)
   }
   else{
#if(STD_ON == McalWdg_DevErrorDetect)
      ServiceDet_ReportError(
            0 //TBD: IdModule
         ,  0 //TBD: IdInstance
         ,  0 //TBD: IdApi
         ,  MCALWDG_E_UNINIT
      );
#endif
   }
#endif
}

FUNC(void, MCALWDG_CODE) module_McalWdg::SetMode(
   void
){
}

FUNC(void, MCALWDG_CODE) module_McalWdg::SetTriggerCondition(
   void
){
}

FUNC(void, MCALWDG_CODE) module_McalWdg::Cbk_McalGptNotification(
   void
){
}

/******************************************************************************/
/* EOF                                                                        */
/******************************************************************************/

