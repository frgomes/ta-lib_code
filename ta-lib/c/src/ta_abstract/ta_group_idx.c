/* Important: This file is automatically generated by the utility gen_code.
 *            Any modification will be lost on next execution of gen_code.
 *
 * The goal of this file is to build the following global
 * constant:
 *       TA_PerGroupFuncDef
 *       TA_PerGroupSize
 *       TA_TotalNbFunction
 *
 * These constant allows mainly to speed optimized functionality related to
 * accessing sequentially TA_DefFunc by TA_GroupId (see ta_abstract.c)
 */
#include <stddef.h>
#include "ta_def_ui.h"
#include "ta_abstract.h"

extern const TA_FuncDef TA_DEF_MAX;
extern const TA_FuncDef TA_DEF_MIN;
extern const TA_FuncDef TA_DEF_BBANDS;
extern const TA_FuncDef TA_DEF_DEMA;
extern const TA_FuncDef TA_DEF_EMA;
extern const TA_FuncDef TA_DEF_MA;
extern const TA_FuncDef TA_DEF_MIDPRICE;
extern const TA_FuncDef TA_DEF_MIDPOINT;
extern const TA_FuncDef TA_DEF_SAR;
extern const TA_FuncDef TA_DEF_SMA;
extern const TA_FuncDef TA_DEF_TEMA;
extern const TA_FuncDef TA_DEF_WMA;
extern const TA_FuncDef TA_DEF_ATR;
extern const TA_FuncDef TA_DEF_TRANGE;
extern const TA_FuncDef TA_DEF_ADX;
extern const TA_FuncDef TA_DEF_ADXR;
extern const TA_FuncDef TA_DEF_APO;
extern const TA_FuncDef TA_DEF_CCI;
extern const TA_FuncDef TA_DEF_DX;
extern const TA_FuncDef TA_DEF_MACD;
extern const TA_FuncDef TA_DEF_MACDEXT;
extern const TA_FuncDef TA_DEF_MACDFIX;
extern const TA_FuncDef TA_DEF_MINUS_DI;
extern const TA_FuncDef TA_DEF_MINUS_DM;
extern const TA_FuncDef TA_DEF_MOM;
extern const TA_FuncDef TA_DEF_PPO;
extern const TA_FuncDef TA_DEF_PLUS_DI;
extern const TA_FuncDef TA_DEF_PLUS_DM;
extern const TA_FuncDef TA_DEF_ROC;
extern const TA_FuncDef TA_DEF_ROCP;
extern const TA_FuncDef TA_DEF_ROCR;
extern const TA_FuncDef TA_DEF_ROCR100;
extern const TA_FuncDef TA_DEF_RSI;
extern const TA_FuncDef TA_DEF_STOCH;
extern const TA_FuncDef TA_DEF_TRIX;
extern const TA_FuncDef TA_DEF_OBV;
extern const TA_FuncDef TA_DEF_STDDEV;
extern const TA_FuncDef TA_DEF_VAR;
extern const TA_FuncDef TA_DEF_AVGPRICE;
extern const TA_FuncDef TA_DEF_MEDPRICE;
extern const TA_FuncDef TA_DEF_TYPPRICE;
extern const TA_FuncDef TA_DEF_WCLPRICE;

const TA_FuncDef *TA_PerGroupFunc_0[] = {
&TA_DEF_MAX,
&TA_DEF_MIN,
NULL };
#define SIZE_GROUP_0 ((sizeof(TA_PerGroupFunc_0)/sizeof(const TA_FuncDef *))-1)

const TA_FuncDef *TA_PerGroupFunc_1[] = {
NULL };
#define SIZE_GROUP_1 ((sizeof(TA_PerGroupFunc_1)/sizeof(const TA_FuncDef *))-1)

const TA_FuncDef *TA_PerGroupFunc_2[] = {
&TA_DEF_BBANDS,
&TA_DEF_DEMA,
&TA_DEF_EMA,
&TA_DEF_MA,
&TA_DEF_MIDPRICE,
&TA_DEF_MIDPOINT,
&TA_DEF_SAR,
&TA_DEF_SMA,
&TA_DEF_TEMA,
&TA_DEF_WMA,
NULL };
#define SIZE_GROUP_2 ((sizeof(TA_PerGroupFunc_2)/sizeof(const TA_FuncDef *))-1)

const TA_FuncDef *TA_PerGroupFunc_3[] = {
&TA_DEF_ATR,
&TA_DEF_TRANGE,
NULL };
#define SIZE_GROUP_3 ((sizeof(TA_PerGroupFunc_3)/sizeof(const TA_FuncDef *))-1)

const TA_FuncDef *TA_PerGroupFunc_4[] = {
&TA_DEF_ADX,
&TA_DEF_ADXR,
&TA_DEF_APO,
&TA_DEF_CCI,
&TA_DEF_DX,
&TA_DEF_MACD,
&TA_DEF_MACDEXT,
&TA_DEF_MACDFIX,
&TA_DEF_MINUS_DI,
&TA_DEF_MINUS_DM,
&TA_DEF_MOM,
&TA_DEF_PPO,
&TA_DEF_PLUS_DI,
&TA_DEF_PLUS_DM,
&TA_DEF_ROC,
&TA_DEF_ROCP,
&TA_DEF_ROCR,
&TA_DEF_ROCR100,
&TA_DEF_RSI,
&TA_DEF_STOCH,
&TA_DEF_TRIX,
NULL };
#define SIZE_GROUP_4 ((sizeof(TA_PerGroupFunc_4)/sizeof(const TA_FuncDef *))-1)

const TA_FuncDef *TA_PerGroupFunc_5[] = {
NULL };
#define SIZE_GROUP_5 ((sizeof(TA_PerGroupFunc_5)/sizeof(const TA_FuncDef *))-1)

const TA_FuncDef *TA_PerGroupFunc_6[] = {
&TA_DEF_OBV,
NULL };
#define SIZE_GROUP_6 ((sizeof(TA_PerGroupFunc_6)/sizeof(const TA_FuncDef *))-1)

const TA_FuncDef *TA_PerGroupFunc_7[] = {
NULL };
#define SIZE_GROUP_7 ((sizeof(TA_PerGroupFunc_7)/sizeof(const TA_FuncDef *))-1)

const TA_FuncDef *TA_PerGroupFunc_8[] = {
&TA_DEF_STDDEV,
&TA_DEF_VAR,
NULL };
#define SIZE_GROUP_8 ((sizeof(TA_PerGroupFunc_8)/sizeof(const TA_FuncDef *))-1)

const TA_FuncDef *TA_PerGroupFunc_9[] = {
&TA_DEF_AVGPRICE,
&TA_DEF_MEDPRICE,
&TA_DEF_TYPPRICE,
&TA_DEF_WCLPRICE,
NULL };
#define SIZE_GROUP_9 ((sizeof(TA_PerGroupFunc_9)/sizeof(const TA_FuncDef *))-1)
const TA_FuncDef **TA_PerGroupFuncDef[10] = {
&TA_PerGroupFunc_0[0],
&TA_PerGroupFunc_1[0],
&TA_PerGroupFunc_2[0],
&TA_PerGroupFunc_3[0],
&TA_PerGroupFunc_4[0],
&TA_PerGroupFunc_5[0],
&TA_PerGroupFunc_6[0],
&TA_PerGroupFunc_7[0],
&TA_PerGroupFunc_8[0],
&TA_PerGroupFunc_9[0]
};

const unsigned int TA_PerGroupSize[10] = {
SIZE_GROUP_0,
SIZE_GROUP_1,
SIZE_GROUP_2,
SIZE_GROUP_3,
SIZE_GROUP_4,
SIZE_GROUP_5,
SIZE_GROUP_6,
SIZE_GROUP_7,
SIZE_GROUP_8,
SIZE_GROUP_9
};

const unsigned int TA_TotalNbFunction =
SIZE_GROUP_0+
SIZE_GROUP_1+
SIZE_GROUP_2+
SIZE_GROUP_3+
SIZE_GROUP_4+
SIZE_GROUP_5+
SIZE_GROUP_6+
SIZE_GROUP_7+
SIZE_GROUP_8+
SIZE_GROUP_9;
