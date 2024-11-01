#include "beremiz.h"
#ifndef __POUS_H
#define __POUS_H

#include "accessor.h"
#include "iec_std_lib.h"

__DECLARE_ENUMERATED_TYPE(LOGLEVEL,
  LOGLEVEL__CRITICAL,
  LOGLEVEL__WARNING,
  LOGLEVEL__INFO,
  LOGLEVEL__DEBUG
)
// FUNCTION_BLOCK LOGGER
// Data part
typedef struct {
  // FB Interface - IN, OUT, IN_OUT variables
  __DECLARE_VAR(BOOL,EN)
  __DECLARE_VAR(BOOL,ENO)
  __DECLARE_VAR(BOOL,TRIG)
  __DECLARE_VAR(STRING,MSG)
  __DECLARE_VAR(LOGLEVEL,LEVEL)

  // FB private variables - TEMP, private and located variables
  __DECLARE_VAR(BOOL,TRIG0)

} LOGGER;

void LOGGER_init__(LOGGER *data__, BOOL retain);
// Code part
void LOGGER_body__(LOGGER *data__);
// PROGRAM PROGRAM0
// Data part
typedef struct {
  // PROGRAM Interface - IN, OUT, IN_OUT variables

  // PROGRAM private variables - TEMP, private and located variables
  CTU CTU0;
  __DECLARE_VAR(BOOL,BOCINA)
  __DECLARE_VAR(BOOL,LED1)
  __DECLARE_VAR(BOOL,LED2)
  __DECLARE_VAR(BOOL,LED3)
  __DECLARE_VAR(WORD,SENSOR_HALL)
  __DECLARE_VAR(BOOL,PULSADOR)
  RS RS0;
  __DECLARE_VAR(DINT,RS1)
  TP TP0;
  __DECLARE_VAR(UINT,TOPE_SUPERIOR)
  __DECLARE_VAR(UINT,TOPE_INFERIOR)
  __DECLARE_VAR(WORD,IN_ANALOGICA)
  CTU CTU1;
  TP TP1;
  RS RS2;
  SR SR0;
  TP TP2;
  SR SR1;
  SR SR2;
  TON TON0;
  R_TRIG R_TRIG0;
  R_TRIG R_TRIG1;
  __DECLARE_VAR(BOOL,_TMP_GT14_OUT)
  __DECLARE_VAR(BOOL,_TMP_LT19_OUT)
  __DECLARE_VAR(BOOL,_TMP_OR20_OUT)
  R_TRIG R_TRIG2;
  R_TRIG R_TRIG3;
  __DECLARE_VAR(BOOL,_TMP_AND27_OUT)
  __DECLARE_VAR(BOOL,_TMP_NOT31_OUT)
  __DECLARE_VAR(BOOL,_TMP_AND29_OUT)
  __DECLARE_VAR(BOOL,_TMP_NOT32_OUT)
  __DECLARE_VAR(BOOL,_TMP_AND30_OUT)
  __DECLARE_VAR(BOOL,_TMP_OR28_OUT)
  __DECLARE_VAR(BOOL,_TMP_XOR35_OUT)
  __DECLARE_VAR(BOOL,_TMP_AND40_OUT)
  __DECLARE_VAR(BOOL,_TMP_OR41_OUT)
  __DECLARE_VAR(BOOL,_TMP_OR45_OUT)
  __DECLARE_VAR(BOOL,_TMP_AND39_OUT)
  __DECLARE_VAR(BOOL,_TMP_XOR36_OUT)
  __DECLARE_VAR(BOOL,_TMP_AND46_OUT)
  __DECLARE_VAR(BOOL,_TMP_OR44_OUT)
  __DECLARE_VAR(BOOL,_TMP_XOR38_OUT)
  __DECLARE_VAR(BOOL,_TMP_AND47_OUT)
  __DECLARE_VAR(BOOL,_TMP_AND49_OUT)
  __DECLARE_VAR(BOOL,_TMP_OR48_OUT)

} PROGRAM0;

void PROGRAM0_init__(PROGRAM0 *data__, BOOL retain);
// Code part
void PROGRAM0_body__(PROGRAM0 *data__);
#endif //__POUS_H
