#pragma once

class class_Wdg{
   public:
      void InitFunction        (void);
      void SetMode             (void);
      void SetTriggerCondition (void);
      void GetVersionInfo      (void);
      void Cbk_GptNotification (void);
};

extern class_Wdg Wdg;

