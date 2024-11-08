PROGRAM program0
  VAR
    CTU0 : CTU;
  END_VAR
  VAR
    BOCINA AT %QX0.0 : BOOL;
    Led1 AT %QX0.1 : BOOL;
    Led2 AT %QX0.2 : BOOL;
    Led3 AT %QX0.3 : BOOL;
    SENSOR_HALL AT %IX0.0 : WORD := 31000;
    pulsador AT %IX0.1 : BOOL;
  END_VAR
  VAR
    RS0 : RS;
    RS1 : DINT;
    tope_Superior : UINT := 34952;
    tope_Inferior : UINT := 31774;
    in_analogica : WORD := 31800;
    CTU1 : CTU;
    RS2 : RS;
    SR0 : SR;
    SR1 : SR;
    SR2 : SR;
    R_TRIG1 : R_TRIG;
    R_TRIG2 : R_TRIG;
    F_TRIG0 : F_TRIG;
    F_TRIG1 : F_TRIG;
    TP3 : TP;
    TP1 : TP;
    TP2 : TP;
    TP4 : TP;
    sonido1 : BOOL;
    sonido2 : BOOL;
    sonido3 : BOOL;
    sonido4 : BOOL;
    sonido5 : BOOL;
    display : BOOL;
    reset_leds : BOOL;
    TP0 : TP;
    F_TRIG3 : F_TRIG;
    F_TRIG4 : F_TRIG;
    F_TRIG5 : F_TRIG;
    F_TRIG6 : F_TRIG;
    _TMP_NOT55_OUT : BOOL;
    _TMP_AND54_OUT : BOOL;
    _TMP_AND36_OUT : BOOL;
    _TMP_OR35_OUT : BOOL;
    _TMP_NOT38_OUT : BOOL;
    _TMP_AND62_OUT : BOOL;
    _TMP_AND39_OUT : BOOL;
    _TMP_AND44_OUT : BOOL;
    _TMP_OR40_OUT : BOOL;
    _TMP_NOT46_OUT : BOOL;
    _TMP_AND52_OUT : BOOL;
    _TMP_AND47_OUT : BOOL;
    _TMP_AND49_OUT : BOOL;
    _TMP_OR48_OUT : BOOL;
    _TMP_GT14_OUT : BOOL;
    _TMP_AND61_OUT : BOOL;
    _TMP_LT19_OUT : BOOL;
    _TMP_AND53_OUT : BOOL;
    _TMP_OR20_OUT : BOOL;
    R_TRIG3 : R_TRIG;
    R_TRIG4 : R_TRIG;
    _TMP_AND27_OUT : BOOL;
    _TMP_NOT32_OUT : BOOL;
    _TMP_AND30_OUT : BOOL;
    _TMP_NOT31_OUT : BOOL;
    _TMP_AND29_OUT : BOOL;
  END_VAR

  TP0(IN := sonido2, PT := T#3000ms);
  F_TRIG3(CLK := TP0.Q);
  TP1(IN := sonido3, PT := T#6000ms);
  F_TRIG4(CLK := TP1.Q);
  TP2(IN := sonido4, PT := T#9000ms);
  F_TRIG5(CLK := TP2.Q);
  TP4(IN := sonido5, PT := T#12000ms);
  F_TRIG6(CLK := TP4.Q);
  TP3(IN := F_TRIG3.Q OR F_TRIG4.Q OR F_TRIG5.Q OR F_TRIG6.Q OR sonido1, PT := T#2000ms);
  BOCINA := TP3.Q;
  _TMP_NOT55_OUT := NOT(SR0.Q1);
  _TMP_AND54_OUT := AND(_TMP_NOT55_OUT, display);
  _TMP_AND36_OUT := AND(display, SR0.Q1);
  _TMP_OR35_OUT := OR(_TMP_AND36_OUT, reset_leds);
  SR0(S1 := _TMP_AND54_OUT, R := _TMP_OR35_OUT);
  Led1 := SR0.Q1;
  _TMP_NOT38_OUT := NOT(SR1.Q1);
  F_TRIG0(CLK := SR0.Q1);
  _TMP_AND62_OUT := AND(F_TRIG0.Q, display);
  _TMP_AND39_OUT := AND(_TMP_NOT38_OUT, _TMP_AND62_OUT);
  _TMP_AND44_OUT := AND(_TMP_AND62_OUT, SR1.Q1);
  _TMP_OR40_OUT := OR(_TMP_AND44_OUT, reset_leds);
  SR1(S1 := _TMP_AND39_OUT, R := _TMP_OR40_OUT);
  Led2 := SR1.Q1;
  _TMP_NOT46_OUT := NOT(SR2.Q1);
  F_TRIG1(CLK := SR1.Q1);
  _TMP_AND52_OUT := AND(F_TRIG1.Q, _TMP_AND62_OUT);
  _TMP_AND47_OUT := AND(_TMP_NOT46_OUT, _TMP_AND52_OUT);
  _TMP_AND49_OUT := AND(_TMP_AND52_OUT, SR2.Q1);
  _TMP_OR48_OUT := OR(_TMP_AND49_OUT, reset_leds);
  SR2(S1 := _TMP_AND47_OUT, R := _TMP_OR48_OUT);
  Led3 := SR2.Q1;
  reset_leds := F_TRIG5.Q;
  _TMP_GT14_OUT := GT(SENSOR_HALL, 34952);
  _TMP_AND61_OUT := AND(pulsador, _TMP_GT14_OUT);
  R_TRIG2(CLK := _TMP_AND61_OUT);
  _TMP_LT19_OUT := LT(SENSOR_HALL, 31774);
  _TMP_AND53_OUT := AND(_TMP_LT19_OUT, pulsador);
  R_TRIG1(CLK := _TMP_AND53_OUT);
  _TMP_OR20_OUT := OR(R_TRIG2.Q, R_TRIG1.Q);
  R_TRIG3(CLK := _TMP_OR20_OUT);
  RS0(S := CTU0.Q, R1 := _TMP_OR20_OUT);
  CTU0(CU := R_TRIG3.Q, R := RS0.Q1, PV := 5);
  R_TRIG4(CLK := R_TRIG1.Q);
  RS2(S := CTU1.Q, R1 := R_TRIG1.Q);
  CTU1(CU := R_TRIG4.Q, R := RS2.Q1 OR R_TRIG2.Q, PV := 3);
  _TMP_AND27_OUT := AND(CTU0.Q, CTU1.Q);
  _TMP_NOT32_OUT := NOT(_TMP_AND27_OUT);
  _TMP_AND30_OUT := AND(_TMP_NOT32_OUT, CTU1.Q);
  _TMP_NOT31_OUT := NOT(_TMP_AND27_OUT);
  _TMP_AND29_OUT := AND(CTU0.Q, _TMP_NOT31_OUT);
  sonido3 := _TMP_AND27_OUT OR _TMP_AND29_OUT OR _TMP_AND30_OUT;
  sonido2 := _TMP_AND27_OUT OR _TMP_AND29_OUT OR _TMP_AND30_OUT;
  sonido4 := _TMP_AND27_OUT OR _TMP_AND29_OUT;
  sonido5 := _TMP_AND29_OUT;
  sonido1 := _TMP_AND27_OUT OR _TMP_AND29_OUT OR _TMP_AND30_OUT;
  display := _TMP_OR20_OUT;
END_PROGRAM


CONFIGURATION Config0

  RESOURCE Res0 ON PLC
    TASK task0(INTERVAL := T#20ms,PRIORITY := 0);
    PROGRAM instance0 WITH task0 : program0;
  END_RESOURCE
END_CONFIGURATION
