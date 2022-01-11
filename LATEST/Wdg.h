#pragma once

#include "Std_Types.h"
#include "Compiler_Cfg_Wdg.h"

class class_Wdg{
   public:
      FUNC(void, WDG_CODE) InitFunction        (void);
      FUNC(void, WDG_CODE) SetMode             (void);
      FUNC(void, WDG_CODE) SetTriggerCondition (void);
      FUNC(void, WDG_CODE) GetVersionInfo      (void);
      FUNC(void, WDG_CODE) Cbk_GptNotification (void);
};

extern class_Wdg Wdg;

