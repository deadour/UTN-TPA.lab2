void LOGGER_init__(LOGGER *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->TRIG,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->MSG,__STRING_LITERAL(0,""),retain)
  __INIT_VAR(data__->LEVEL,LOGLEVEL__INFO,retain)
  __INIT_VAR(data__->TRIG0,__BOOL_LITERAL(FALSE),retain)
}

// Code part
void LOGGER_body__(LOGGER *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  if ((__GET_VAR(data__->TRIG,) && !(__GET_VAR(data__->TRIG0,)))) {
    #define GetFbVar(var,...) __GET_VAR(data__->var,__VA_ARGS__)
    #define SetFbVar(var,val,...) __SET_VAR(data__->,var,__VA_ARGS__,val)

   LogMessage(GetFbVar(LEVEL),(char*)GetFbVar(MSG, .body),GetFbVar(MSG, .len));
  
    #undef GetFbVar
    #undef SetFbVar
;
  };
  __SET_VAR(data__->,TRIG0,,__GET_VAR(data__->TRIG,));

  goto __end;

__end:
  return;
} // LOGGER_body__() 





void PROGRAM0_init__(PROGRAM0 *data__, BOOL retain) {
  CTU_init__(&data__->CTU0,retain);
  __INIT_VAR(data__->BOCINA,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->LED1,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->LED2,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->LED3,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->SENSOR_HALL,35000,retain)
  __INIT_VAR(data__->PULSADOR,__BOOL_LITERAL(FALSE),retain)
  RS_init__(&data__->RS0,retain);
  __INIT_VAR(data__->RS1,0,retain)
  TP_init__(&data__->TP0,retain);
  __INIT_VAR(data__->TOPE_SUPERIOR,34952,retain)
  __INIT_VAR(data__->TOPE_INFERIOR,31774,retain)
  __INIT_VAR(data__->IN_ANALOGICA,31800,retain)
  CTU_init__(&data__->CTU1,retain);
  TP_init__(&data__->TP1,retain);
  RS_init__(&data__->RS2,retain);
  SR_init__(&data__->SR0,retain);
  TP_init__(&data__->TP2,retain);
  SR_init__(&data__->SR1,retain);
  SR_init__(&data__->SR2,retain);
  TON_init__(&data__->TON0,retain);
  __INIT_VAR(data__->_TMP_GT14_OUT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_TMP_LT19_OUT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_TMP_OR20_OUT,__BOOL_LITERAL(FALSE),retain)
  R_TRIG_init__(&data__->R_TRIG1,retain);
  R_TRIG_init__(&data__->R_TRIG2,retain);
  __INIT_VAR(data__->_TMP_AND27_OUT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_TMP_NOT31_OUT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_TMP_AND29_OUT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_TMP_NOT32_OUT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_TMP_AND30_OUT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_TMP_OR28_OUT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_TMP_XOR35_OUT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_TMP_AND40_OUT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_TMP_OR41_OUT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_TMP_OR45_OUT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_TMP_AND39_OUT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_TMP_XOR36_OUT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_TMP_AND46_OUT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_TMP_OR44_OUT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_TMP_XOR38_OUT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_TMP_AND47_OUT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_TMP_AND49_OUT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_TMP_OR48_OUT,__BOOL_LITERAL(FALSE),retain)
}

// Code part
void PROGRAM0_body__(PROGRAM0 *data__) {
  // Initialise TEMP variables

  __SET_VAR(data__->,_TMP_GT14_OUT,,GT__BOOL__WORD(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)2,
    (WORD)__GET_VAR(data__->SENSOR_HALL,),
    (WORD)34952));
  __SET_VAR(data__->,_TMP_LT19_OUT,,LT__BOOL__WORD(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)2,
    (WORD)__GET_VAR(data__->SENSOR_HALL,),
    (WORD)31774));
  __SET_VAR(data__->,_TMP_OR20_OUT,,OR__BOOL__BOOL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)2,
    (BOOL)__GET_VAR(data__->_TMP_GT14_OUT,),
    (BOOL)__GET_VAR(data__->_TMP_LT19_OUT,)));
  __SET_VAR(data__->R_TRIG1.,CLK,,__GET_VAR(data__->_TMP_OR20_OUT,));
  R_TRIG_body__(&data__->R_TRIG1);
  __SET_VAR(data__->RS0.,S,,__GET_VAR(data__->CTU0.Q,));
  __SET_VAR(data__->RS0.,R1,,__GET_VAR(data__->_TMP_OR20_OUT,));
  RS_body__(&data__->RS0);
  __SET_VAR(data__->CTU0.,CU,,__GET_VAR(data__->R_TRIG1.Q,));
  __SET_VAR(data__->CTU0.,R,,__GET_VAR(data__->RS0.Q1,));
  __SET_VAR(data__->CTU0.,PV,,2);
  CTU_body__(&data__->CTU0);
  __SET_VAR(data__->R_TRIG2.,CLK,,__GET_VAR(data__->_TMP_LT19_OUT,));
  R_TRIG_body__(&data__->R_TRIG2);
  __SET_VAR(data__->RS2.,S,,__GET_VAR(data__->CTU1.Q,));
  __SET_VAR(data__->RS2.,R1,,__GET_VAR(data__->_TMP_LT19_OUT,));
  RS_body__(&data__->RS2);
  __SET_VAR(data__->CTU1.,CU,,__GET_VAR(data__->R_TRIG2.Q,));
  __SET_VAR(data__->CTU1.,R,,(__GET_VAR(data__->RS2.Q1,) || __GET_VAR(data__->_TMP_GT14_OUT,)));
  __SET_VAR(data__->CTU1.,PV,,2);
  CTU_body__(&data__->CTU1);
  __SET_VAR(data__->,_TMP_AND27_OUT,,AND__BOOL__BOOL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)2,
    (BOOL)__GET_VAR(data__->CTU0.Q,),
    (BOOL)__GET_VAR(data__->CTU1.Q,)));
  __SET_VAR(data__->,_TMP_NOT31_OUT,,!(__GET_VAR(data__->_TMP_AND27_OUT,)));
  __SET_VAR(data__->,_TMP_AND29_OUT,,AND__BOOL__BOOL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)2,
    (BOOL)__GET_VAR(data__->CTU0.Q,),
    (BOOL)__GET_VAR(data__->_TMP_NOT31_OUT,)));
  __SET_VAR(data__->TP0.,IN,,__GET_VAR(data__->_TMP_AND29_OUT,));
  __SET_VAR(data__->TP0.,PT,,__time_to_timespec(1, 5000, 0, 0, 0, 0));
  TP_body__(&data__->TP0);
  __SET_VAR(data__->TP2.,IN,,__GET_VAR(data__->_TMP_AND27_OUT,));
  __SET_VAR(data__->TP2.,PT,,__time_to_timespec(1, 4000, 0, 0, 0, 0));
  TP_body__(&data__->TP2);
  __SET_VAR(data__->,_TMP_NOT32_OUT,,!(__GET_VAR(data__->_TMP_AND27_OUT,)));
  __SET_VAR(data__->,_TMP_AND30_OUT,,AND__BOOL__BOOL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)2,
    (BOOL)__GET_VAR(data__->_TMP_NOT32_OUT,),
    (BOOL)__GET_VAR(data__->CTU1.Q,)));
  __SET_VAR(data__->TP1.,IN,,__GET_VAR(data__->_TMP_AND30_OUT,));
  __SET_VAR(data__->TP1.,PT,,__time_to_timespec(1, 3000, 0, 0, 0, 0));
  TP_body__(&data__->TP1);
  __SET_VAR(data__->,_TMP_OR28_OUT,,OR__BOOL__BOOL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)3,
    (BOOL)__GET_VAR(data__->TP0.Q,),
    (BOOL)__GET_VAR(data__->TP2.Q,),
    (BOOL)__GET_VAR(data__->TP1.Q,)));
  __SET_VAR(data__->,BOCINA,,__GET_VAR(data__->_TMP_OR28_OUT,));
  __SET_VAR(data__->,_TMP_XOR35_OUT,,XOR__BOOL__BOOL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)2,
    (BOOL)__GET_VAR(data__->SR0.Q1,),
    (BOOL)__GET_VAR(data__->_TMP_OR20_OUT,)));
  __SET_VAR(data__->,_TMP_AND40_OUT,,AND__BOOL__BOOL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)2,
    (BOOL)__GET_VAR(data__->_TMP_OR20_OUT,),
    (BOOL)__GET_VAR(data__->SR0.Q1,)));
  __SET_VAR(data__->,_TMP_OR41_OUT,,OR__BOOL__BOOL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)2,
    (BOOL)__GET_VAR(data__->TP0.Q,),
    (BOOL)__GET_VAR(data__->TP2.Q,)));
  __SET_VAR(data__->TON0.,IN,,__GET_VAR(data__->_TMP_OR41_OUT,));
  __SET_VAR(data__->TON0.,PT,,__time_to_timespec(1, 5000, 0, 0, 0, 0));
  TON_body__(&data__->TON0);
  __SET_VAR(data__->,_TMP_OR45_OUT,,OR__BOOL__BOOL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)2,
    (BOOL)__GET_VAR(data__->_TMP_AND40_OUT,),
    (BOOL)__GET_VAR(data__->TON0.Q,)));
  __SET_VAR(data__->SR0.,S1,,__GET_VAR(data__->_TMP_XOR35_OUT,));
  __SET_VAR(data__->SR0.,R,,__GET_VAR(data__->_TMP_OR45_OUT,));
  SR_body__(&data__->SR0);
  __SET_VAR(data__->,LED1,,__GET_VAR(data__->SR0.Q1,));
  __SET_VAR(data__->,_TMP_AND39_OUT,,AND__BOOL__BOOL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)2,
    (BOOL)__GET_VAR(data__->SR0.Q1,),
    (BOOL)__GET_VAR(data__->_TMP_OR20_OUT,)));
  __SET_VAR(data__->,_TMP_XOR36_OUT,,XOR__BOOL__BOOL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)2,
    (BOOL)__GET_VAR(data__->SR1.Q1,),
    (BOOL)__GET_VAR(data__->_TMP_AND39_OUT,)));
  __SET_VAR(data__->,_TMP_AND46_OUT,,AND__BOOL__BOOL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)2,
    (BOOL)__GET_VAR(data__->SR1.Q1,),
    (BOOL)__GET_VAR(data__->_TMP_AND39_OUT,)));
  __SET_VAR(data__->,_TMP_OR44_OUT,,OR__BOOL__BOOL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)2,
    (BOOL)__GET_VAR(data__->_TMP_AND46_OUT,),
    (BOOL)__GET_VAR(data__->TON0.Q,)));
  __SET_VAR(data__->SR1.,S1,,__GET_VAR(data__->_TMP_XOR36_OUT,));
  __SET_VAR(data__->SR1.,R,,__GET_VAR(data__->_TMP_OR44_OUT,));
  SR_body__(&data__->SR1);
  __SET_VAR(data__->,LED2,,__GET_VAR(data__->SR1.Q1,));
  __SET_VAR(data__->,_TMP_XOR38_OUT,,XOR__BOOL__BOOL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)1,
    (BOOL)__GET_VAR(data__->SR2.Q1,)));
  __SET_VAR(data__->,_TMP_AND47_OUT,,AND__BOOL__BOOL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)2,
    (BOOL)__GET_VAR(data__->_TMP_AND39_OUT,),
    (BOOL)__GET_VAR(data__->SR1.Q1,)));
  __SET_VAR(data__->,_TMP_AND49_OUT,,AND__BOOL__BOOL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)2,
    (BOOL)__GET_VAR(data__->SR2.Q1,),
    (BOOL)__GET_VAR(data__->_TMP_AND47_OUT,)));
  __SET_VAR(data__->,_TMP_OR48_OUT,,OR__BOOL__BOOL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)2,
    (BOOL)__GET_VAR(data__->_TMP_AND49_OUT,),
    (BOOL)__GET_VAR(data__->TON0.Q,)));
  __SET_VAR(data__->SR2.,S1,,__GET_VAR(data__->_TMP_XOR38_OUT,));
  __SET_VAR(data__->SR2.,R,,__GET_VAR(data__->_TMP_OR48_OUT,));
  SR_body__(&data__->SR2);
  __SET_VAR(data__->,LED3,,__GET_VAR(data__->SR2.Q1,));

  goto __end;

__end:
  return;
} // PROGRAM0_body__() 




