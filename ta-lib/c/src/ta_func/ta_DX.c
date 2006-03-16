/* TA-LIB Copyright (c) 1999-2006, Mario Fortier
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or
 * without modification, are permitted provided that the following
 * conditions are met:
 *
 * - Redistributions of source code must retain the above copyright
 *   notice, this list of conditions and the following disclaimer.
 *
 * - Redistributions in binary form must reproduce the above copyright
 *   notice, this list of conditions and the following disclaimer in
 *   the documentation and/or other materials provided with the
 *   distribution.
 *
 * - Neither name of author nor the names of its contributors
 *   may be used to endorse or promote products derived from this
 *   software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 * REGENTS OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
 * OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

/* List of contributors:
 *
 *  Initial  Name/description
 *  -------------------------------------------------------------------
 *  MF       Mario Fortier
 *  AM       Adrian Michel
 *  MIF      Mirek Fontan (mira@fontan.cz)
 *
 * Change history:
 *
 *  MMDDYY BY   Description
 *  -------------------------------------------------------------------
 *  010802 MF   Template creation.
 *  052603 MF   Adapt code to compile with .NET Managed C++
 *  082303 MF   Fix #792298. Remove rounding. Bug reported by AM.
 *  062704 MF   Fix #965557. Div by zero bug reported by MIF.
 */

/**** START GENCODE SECTION 1 - DO NOT DELETE THIS LINE ****/
/* All code within this section is automatically
 * generated by gen_code. Any modification will be lost
 * next time gen_code is run.
 */
/* Generated */ 
/* Generated */ #if defined( _MANAGED )
/* Generated */    #include "TA-Lib-Core.h"
/* Generated */    #define TA_INTERNAL_ERROR(Id) (NAMESPACE(TA_RetCode)TA_INTERNAL_ERROR)
/* Generated */    namespace TA { namespace Lib {
/* Generated */ #elif defined( _JAVA )
/* Generated */    #include "ta_defs.h"
/* Generated */    #define TA_INTERNAL_ERROR(Id) (NAMESPACE(TA_RetCode)TA_INTERNAL_ERROR)
/* Generated */ #else
/* Generated */    #include <string.h>
/* Generated */    #include <math.h>
/* Generated */    #include "ta_func.h"
/* Generated */ #endif
/* Generated */ 
/* Generated */ #ifndef TA_UTILITY_H
/* Generated */    #include "ta_utility.h"
/* Generated */ #endif
/* Generated */ 
/* Generated */ #ifndef TA_MEMORY_H
/* Generated */    #include "ta_memory.h"
/* Generated */ #endif
/* Generated */ 
/* Generated */ #define TA_PREFIX(x) TA_##x
/* Generated */ #define INPUT_TYPE   double
/* Generated */ 
/* Generated */ #if defined( _MANAGED )
/* Generated */ int Core::DX_Lookback( int           optInTimePeriod )  /* From 2 to 100000 */
/* Generated */ 
/* Generated */ #elif defined( _JAVA )
/* Generated */ public int DX_Lookback( int           optInTimePeriod )  /* From 2 to 100000 */
/* Generated */ 
/* Generated */ #else
/* Generated */ int TA_DX_Lookback( int           optInTimePeriod )  /* From 2 to 100000 */
/* Generated */ 
/* Generated */ #endif
/**** END GENCODE SECTION 1 - DO NOT DELETE THIS LINE ****/
{
   /* insert local variable here */

/**** START GENCODE SECTION 2 - DO NOT DELETE THIS LINE ****/
/* Generated */ #ifndef TA_FUNC_NO_RANGE_CHECK
/* Generated */    /* min/max are checked for optInTimePeriod. */
/* Generated */    if( (int)optInTimePeriod == TA_INTEGER_DEFAULT )
/* Generated */       optInTimePeriod = 14;
/* Generated */    else if( ((int)optInTimePeriod < 2) || ((int)optInTimePeriod > 100000) )
/* Generated */       return -1;
/* Generated */ 
/* Generated */ #endif /* TA_FUNC_NO_RANGE_CHECK */
/**** END GENCODE SECTION 2 - DO NOT DELETE THIS LINE ****/

   /* insert lookback code here. */
   if( optInTimePeriod > 1 )
      return optInTimePeriod + TA_GLOBALS_UNSTABLE_PERIOD(TA_FUNC_UNST_DX);
   else
      return 2;
}

/**** START GENCODE SECTION 3 - DO NOT DELETE THIS LINE ****/
/*
 * TA_DX - Directional Movement Index
 * 
 * Input  = High, Low, Close
 * Output = double
 * 
 * Optional Parameters
 * -------------------
 * optInTimePeriod:(From 2 to 100000)
 *    Number of period
 * 
 * 
 */
/* Generated */ 
/* Generated */ #if defined( _MANAGED )
/* Generated */ enum class Core::TA_RetCode Core::DX( int    startIdx,
/* Generated */                                       int    endIdx,
/* Generated */                                       cli::array<double>^ inHigh,
/* Generated */                                       cli::array<double>^ inLow,
/* Generated */                                       cli::array<double>^ inClose,
/* Generated */                                       int           optInTimePeriod, /* From 2 to 100000 */
/* Generated */                                       [Out]int%    outBegIdx,
/* Generated */                                       [Out]int%    outNbElement,
/* Generated */                                       cli::array<double>^  outReal )
/* Generated */ #elif defined( _JAVA )
/* Generated */ public TA_RetCode DX( int    startIdx,
/* Generated */                       int    endIdx,
/* Generated */                       double       inHigh[],
/* Generated */                       double       inLow[],
/* Generated */                       double       inClose[],
/* Generated */                       int           optInTimePeriod, /* From 2 to 100000 */
/* Generated */                       MInteger     outBegIdx,
/* Generated */                       MInteger     outNbElement,
/* Generated */                       double        outReal[] )
/* Generated */ #else
/* Generated */ TA_RetCode TA_DX( int    startIdx,
/* Generated */                   int    endIdx,
/* Generated */                   const double inHigh[],
/* Generated */                   const double inLow[],
/* Generated */                   const double inClose[],
/* Generated */                   int           optInTimePeriod, /* From 2 to 100000 */
/* Generated */                   int          *outBegIdx,
/* Generated */                   int          *outNbElement,
/* Generated */                   double        outReal[] )
/* Generated */ #endif
/**** END GENCODE SECTION 3 - DO NOT DELETE THIS LINE ****/
{
	/* insert local variable here */
   int today, lookbackTotal, outIdx;
   double prevHigh, prevLow, prevClose;
   double prevMinusDM, prevPlusDM, prevTR;
   double tempReal, tempReal2, diffP, diffM;
   double minusDI, plusDI;

   int i;

   #define TRUE_RANGE(TH,TL,YC,OUT) {\
      OUT = TH-TL; \
      tempReal2 = fabs(TH-YC); \
      if( tempReal2 > OUT ) \
         OUT = tempReal2; \
      tempReal2 = fabs(TL-YC); \
      if( tempReal2 > OUT ) \
         OUT = tempReal2; \
   }

/**** START GENCODE SECTION 4 - DO NOT DELETE THIS LINE ****/
/* Generated */ 
/* Generated */ #ifndef TA_FUNC_NO_RANGE_CHECK
/* Generated */ 
/* Generated */    /* Validate the requested output range. */
/* Generated */    if( startIdx < 0 )
/* Generated */       return NAMESPACE(TA_RetCode)TA_OUT_OF_RANGE_START_INDEX;
/* Generated */    if( (endIdx < 0) || (endIdx < startIdx))
/* Generated */       return NAMESPACE(TA_RetCode)TA_OUT_OF_RANGE_END_INDEX;
/* Generated */ 
/* Generated */    #if !defined(_MANAGED) && !defined(_JAVA)
/* Generated */    /* Verify required price component. */
/* Generated */    if(!inHigh||!inLow||!inClose)
/* Generated */       return NAMESPACE(TA_RetCode)TA_BAD_PARAM;
/* Generated */ 
/* Generated */    #endif /* !defined(_MANAGED) && !defined(_JAVA)*/
/* Generated */    /* min/max are checked for optInTimePeriod. */
/* Generated */    if( (int)optInTimePeriod == TA_INTEGER_DEFAULT )
/* Generated */       optInTimePeriod = 14;
/* Generated */    else if( ((int)optInTimePeriod < 2) || ((int)optInTimePeriod > 100000) )
/* Generated */       return NAMESPACE(TA_RetCode)TA_BAD_PARAM;
/* Generated */ 
/* Generated */    #if !defined(_MANAGED) && !defined(_JAVA)
/* Generated */    if( !outReal )
/* Generated */       return NAMESPACE(TA_RetCode)TA_BAD_PARAM;
/* Generated */ 
/* Generated */    #endif /* !defined(_MANAGED) && !defined(_JAVA) */
/* Generated */ #endif /* TA_FUNC_NO_RANGE_CHECK */
/* Generated */ 
/**** END GENCODE SECTION 4 - DO NOT DELETE THIS LINE ****/

   /* Insert TA function code here. */

   /* 
    * The DM1 (one period) is base on the largest part of
    * today's range that is outside of yesterdays range.
    * 
    * The following 7 cases explain how the +DM and -DM are
    * calculated on one period:
    *
    * Case 1:                       Case 2:
    *    C|                        A|
    *     |                         | C|
    *     | +DM1 = (C-A)           B|  | +DM1 = 0
    *     | -DM1 = 0                   | -DM1 = (B-D)
    * A|  |                           D| 
    *  | D|                    
    * B|
    *
    * Case 3:                       Case 4:
    *    C|                           C|
    *     |                        A|  |
    *     | +DM1 = (C-A)            |  | +DM1 = 0
    *     | -DM1 = 0               B|  | -DM1 = (B-D)
    * A|  |                            | 
    *  |  |                           D|
    * B|  |
    *    D|
    * 
    * Case 5:                      Case 6:
    * A|                           A| C|
    *  | C| +DM1 = 0                |  |  +DM1 = 0
    *  |  | -DM1 = 0                |  |  -DM1 = 0
    *  | D|                         |  |
    * B|                           B| D|
    *
    *
    * Case 7:
    * 
    *    C|
    * A|  |
    *  |  | +DM=0
    * B|  | -DM=0
    *    D|
    *
    * In case 3 and 4, the rule is that the smallest delta between
    * (C-A) and (B-D) determine which of +DM or -DM is zero.
    *
    * In case 7, (C-A) and (B-D) are equal, so both +DM and -DM are
    * zero.
    *
    * The rules remain the same when A=B and C=D (when the highs
    * equal the lows).
    *
    * When calculating the DM over a period > 1, the one-period DM
    * for the desired period are initialy sum. In other word, 
    * for a -DM14, sum the -DM1 for the first 14 days (that's 
    * 13 values because there is no DM for the first day!)
    * Subsequent DM are calculated using the Wilder's
    * smoothing approach:
    * 
    *                                    Previous -DM14
    *  Today's -DM14 = Previous -DM14 -  -------------- + Today's -DM1
    *                                         14
    *
    * Calculation of a -DI14 is as follow:
    * 
    *               -DM14
    *     -DI14 =  --------
    *                TR14
    *
    * Calculation of the TR14 is:
    *
    *                                   Previous TR14
    *    Today's TR14 = Previous TR14 - -------------- + Today's TR1
    *                                         14
    *
    *    The first TR14 is the summation of the first 14 TR1. See the
    *    TA_TRANGE function on how to calculate the true range.
    *
    * Calculation of the DX14 is:
    *    
    *    diffDI = ABS( (-DI14) - (+DI14) )
    *    sumDI  = (-DI14) + (+DI14)
    *
    *    DX14 = 100 * (diffDI / sumDI)
    *
    * Reference:
    *    New Concepts In Technical Trading Systems, J. Welles Wilder Jr
    */

   /* Original implementation from Wilder's book was doing some integer
    * rounding in its calculations.
    *
    * This was understandable in the context that at the time the book
    * was written, most user were doing the calculation by hand.
    * 
    * For a computer, rounding is unnecessary (and even problematic when inputs
    * are close to 1).
    *
    * TA-Lib does not do the rounding. Still, if you want to reproduce Wilder's examples,
    * you can comment out the following #undef/#define and rebuild the library.
    */
   #undef  round_pos
   #define round_pos(x) (x)

   if( optInTimePeriod > 1 )
      lookbackTotal = optInTimePeriod + TA_GLOBALS_UNSTABLE_PERIOD(TA_FUNC_UNST_DX);
   else
      lookbackTotal = 2;

   /* Adjust startIdx to account for the lookback period. */
   if( startIdx < lookbackTotal )
      startIdx = lookbackTotal;

   /* Make sure there is still something to evaluate. */
   if( startIdx > endIdx )
   {
      VALUE_HANDLE_DEREF_TO_ZERO(outBegIdx);
      VALUE_HANDLE_DEREF_TO_ZERO(outNbElement);
      return NAMESPACE(TA_RetCode)TA_SUCCESS;
   }

   /* Indicate where the next output should be put
    * in the outReal.
    */
   outIdx = 0;

   /* Process the initial DM and TR */
   VALUE_HANDLE_DEREF(outBegIdx) = today = startIdx;

   prevMinusDM = 0.0;
   prevPlusDM  = 0.0;
   prevTR      = 0.0;
   today       = startIdx - lookbackTotal;
   prevHigh    = inHigh[today];
   prevLow     = inLow[today];
   prevClose   = inClose[today];
   i           = optInTimePeriod-1;
   while( i-- > 0 )
   {
      today++;
      tempReal = inHigh[today];
      diffP    = tempReal-prevHigh; /* Plus Delta */
      prevHigh = tempReal;

      tempReal = inLow[today];
      diffM    = prevLow-tempReal;   /* Minus Delta */
      prevLow  = tempReal;

      if( (diffM > 0) && (diffP < diffM) )
      {
          /* Case 2 and 4: +DM=0,-DM=diffM */
          prevMinusDM += diffM;
      }
      else if( (diffP > 0) && (diffP > diffM) )
      {
          /* Case 1 and 3: +DM=diffP,-DM=0 */
          prevPlusDM += diffP;
      }

      TRUE_RANGE(prevHigh,prevLow,prevClose,tempReal);
      prevTR += tempReal;
      prevClose = inClose[today];
   }

   /* Skip the unstable period. Note that this loop must be executed
    * at least ONCE to calculate the first DI.
    */
   i = TA_GLOBALS_UNSTABLE_PERIOD(TA_FUNC_UNST_DX) + 1;
   while( i-- != 0 )
   {
      /* Calculate the prevMinusDM and prevPlusDM */
      today++;
      tempReal = inHigh[today];
      diffP    = tempReal-prevHigh; /* Plus Delta */
      prevHigh = tempReal;

      tempReal = inLow[today];
      diffM    = prevLow-tempReal;   /* Minus Delta */
      prevLow  = tempReal;

      prevMinusDM -= prevMinusDM/optInTimePeriod;
      prevPlusDM  -= prevPlusDM/optInTimePeriod;

      if( (diffM > 0) && (diffP < diffM) )
      {
         /* Case 2 and 4: +DM=0,-DM=diffM */
         prevMinusDM += diffM;
      }
      else if( (diffP > 0) && (diffP > diffM) )
      {
         /* Case 1 and 3: +DM=diffP,-DM=0 */
         prevPlusDM += diffP;
      }

      /* Calculate the prevTR */
      TRUE_RANGE(prevHigh,prevLow,prevClose,tempReal);
      prevTR = prevTR - (prevTR/optInTimePeriod) + tempReal;
      prevClose = inClose[today];
   }

   /* Write the first DX output */
   if( !TA_IS_ZERO(prevTR) )
   {
      minusDI = round_pos(100.0*(prevMinusDM/prevTR));
      plusDI  = round_pos(100.0*(prevPlusDM/prevTR));
      tempReal = minusDI+plusDI;
      if( !TA_IS_ZERO(tempReal) )
         outReal[0] = round_pos( 100.0 * (fabs(minusDI-plusDI)/tempReal) );
      else
         outReal[0] = 0.0;
   }
   else
      outReal[0] = 0.0;
   outIdx = 1;

   while( today < endIdx )
   {
      /* Calculate the prevMinusDM and prevPlusDM */
      today++;
      tempReal = inHigh[today];
      diffP    = tempReal-prevHigh; /* Plus Delta */
      prevHigh = tempReal;

      tempReal = inLow[today];
      diffM    = prevLow-tempReal;   /* Minus Delta */
      prevLow  = tempReal;

      prevMinusDM -= prevMinusDM/optInTimePeriod;
      prevPlusDM  -= prevPlusDM/optInTimePeriod;

      if( (diffM > 0) && (diffP < diffM) )
      {
         /* Case 2 and 4: +DM=0,-DM=diffM */
         prevMinusDM += diffM;
      }
      else if( (diffP > 0) && (diffP > diffM) )
      {
         /* Case 1 and 3: +DM=diffP,-DM=0 */
         prevPlusDM += diffP;
      }

      /* Calculate the prevTR */
      TRUE_RANGE(prevHigh,prevLow,prevClose,tempReal);
      prevTR = prevTR - (prevTR/optInTimePeriod) + tempReal;
      prevClose = inClose[today];

      /* Calculate the DX. The value is rounded (see Wilder book). */
      if( !TA_IS_ZERO(prevTR))
      {
         minusDI = round_pos(100.0*(prevMinusDM/prevTR));
         plusDI  = round_pos(100.0*(prevPlusDM/prevTR));
         /* This loop is just to accumulate the initial DX */
         tempReal = minusDI+plusDI;
         if( !TA_IS_ZERO(tempReal))         
            outReal[outIdx] = round_pos( 100.0 * (fabs(minusDI-plusDI)/tempReal) );
         else
            outReal[outIdx] = outReal[outIdx-1];
      }
      else
         outReal[outIdx] = outReal[outIdx-1];
      outIdx++;
   }

   VALUE_HANDLE_DEREF(outNbElement) = outIdx;

   return NAMESPACE(TA_RetCode)TA_SUCCESS;
}

/**** START GENCODE SECTION 5 - DO NOT DELETE THIS LINE ****/
/* Generated */ 
/* Generated */ #define  USE_SINGLE_PRECISION_INPUT
/* Generated */ #if !defined( _MANAGED ) && !defined( _JAVA )
/* Generated */    #undef   TA_PREFIX
/* Generated */    #define  TA_PREFIX(x) TA_S_##x
/* Generated */ #endif
/* Generated */ #undef   INPUT_TYPE
/* Generated */ #define  INPUT_TYPE float
/* Generated */ #if defined( _MANAGED )
/* Generated */ enum class Core::TA_RetCode Core::DX( int    startIdx,
/* Generated */                                       int    endIdx,
/* Generated */                                       cli::array<float>^ inHigh,
/* Generated */                                       cli::array<float>^ inLow,
/* Generated */                                       cli::array<float>^ inClose,
/* Generated */                                       int           optInTimePeriod, /* From 2 to 100000 */
/* Generated */                                       [Out]int%    outBegIdx,
/* Generated */                                       [Out]int%    outNbElement,
/* Generated */                                       cli::array<double>^  outReal )
/* Generated */ #elif defined( _JAVA )
/* Generated */ public TA_RetCode DX( int    startIdx,
/* Generated */                       int    endIdx,
/* Generated */                       float        inHigh[],
/* Generated */                       float        inLow[],
/* Generated */                       float        inClose[],
/* Generated */                       int           optInTimePeriod, /* From 2 to 100000 */
/* Generated */                       MInteger     outBegIdx,
/* Generated */                       MInteger     outNbElement,
/* Generated */                       double        outReal[] )
/* Generated */ #else
/* Generated */ TA_RetCode TA_S_DX( int    startIdx,
/* Generated */                     int    endIdx,
/* Generated */                     const float  inHigh[],
/* Generated */                     const float  inLow[],
/* Generated */                     const float  inClose[],
/* Generated */                     int           optInTimePeriod, /* From 2 to 100000 */
/* Generated */                     int          *outBegIdx,
/* Generated */                     int          *outNbElement,
/* Generated */                     double        outReal[] )
/* Generated */ #endif
/* Generated */ {
/* Generated */    int today, lookbackTotal, outIdx;
/* Generated */    double prevHigh, prevLow, prevClose;
/* Generated */    double prevMinusDM, prevPlusDM, prevTR;
/* Generated */    double tempReal, tempReal2, diffP, diffM;
/* Generated */    double minusDI, plusDI;
/* Generated */    int i;
/* Generated */    #define TRUE_RANGE(TH,TL,YC,OUT) {\
/* Generated */       OUT = TH-TL; \
/* Generated */       tempReal2 = fabs(TH-YC); \
/* Generated */       if( tempReal2 > OUT ) \
/* Generated */          OUT = tempReal2; \
/* Generated */       tempReal2 = fabs(TL-YC); \
/* Generated */       if( tempReal2 > OUT ) \
/* Generated */          OUT = tempReal2; \
/* Generated */    }
/* Generated */  #ifndef TA_FUNC_NO_RANGE_CHECK
/* Generated */     if( startIdx < 0 )
/* Generated */        return NAMESPACE(TA_RetCode)TA_OUT_OF_RANGE_START_INDEX;
/* Generated */     if( (endIdx < 0) || (endIdx < startIdx))
/* Generated */        return NAMESPACE(TA_RetCode)TA_OUT_OF_RANGE_END_INDEX;
/* Generated */     #if !defined(_MANAGED) && !defined(_JAVA)
/* Generated */     if(!inHigh||!inLow||!inClose)
/* Generated */        return NAMESPACE(TA_RetCode)TA_BAD_PARAM;
/* Generated */     #endif 
/* Generated */     if( (int)optInTimePeriod == TA_INTEGER_DEFAULT )
/* Generated */        optInTimePeriod = 14;
/* Generated */     else if( ((int)optInTimePeriod < 2) || ((int)optInTimePeriod > 100000) )
/* Generated */        return NAMESPACE(TA_RetCode)TA_BAD_PARAM;
/* Generated */     #if !defined(_MANAGED) && !defined(_JAVA)
/* Generated */     if( !outReal )
/* Generated */        return NAMESPACE(TA_RetCode)TA_BAD_PARAM;
/* Generated */     #endif 
/* Generated */  #endif 
/* Generated */    #undef  round_pos
/* Generated */    #define round_pos(x) (x)
/* Generated */    if( optInTimePeriod > 1 )
/* Generated */       lookbackTotal = optInTimePeriod + TA_GLOBALS_UNSTABLE_PERIOD(TA_FUNC_UNST_DX);
/* Generated */    else
/* Generated */       lookbackTotal = 2;
/* Generated */    if( startIdx < lookbackTotal )
/* Generated */       startIdx = lookbackTotal;
/* Generated */    if( startIdx > endIdx )
/* Generated */    {
/* Generated */       VALUE_HANDLE_DEREF_TO_ZERO(outBegIdx);
/* Generated */       VALUE_HANDLE_DEREF_TO_ZERO(outNbElement);
/* Generated */       return NAMESPACE(TA_RetCode)TA_SUCCESS;
/* Generated */    }
/* Generated */    outIdx = 0;
/* Generated */    VALUE_HANDLE_DEREF(outBegIdx) = today = startIdx;
/* Generated */    prevMinusDM = 0.0;
/* Generated */    prevPlusDM  = 0.0;
/* Generated */    prevTR      = 0.0;
/* Generated */    today       = startIdx - lookbackTotal;
/* Generated */    prevHigh    = inHigh[today];
/* Generated */    prevLow     = inLow[today];
/* Generated */    prevClose   = inClose[today];
/* Generated */    i           = optInTimePeriod-1;
/* Generated */    while( i-- > 0 )
/* Generated */    {
/* Generated */       today++;
/* Generated */       tempReal = inHigh[today];
/* Generated */       diffP    = tempReal-prevHigh; 
/* Generated */       prevHigh = tempReal;
/* Generated */       tempReal = inLow[today];
/* Generated */       diffM    = prevLow-tempReal;   
/* Generated */       prevLow  = tempReal;
/* Generated */       if( (diffM > 0) && (diffP < diffM) )
/* Generated */       {
/* Generated */           prevMinusDM += diffM;
/* Generated */       }
/* Generated */       else if( (diffP > 0) && (diffP > diffM) )
/* Generated */       {
/* Generated */           prevPlusDM += diffP;
/* Generated */       }
/* Generated */       TRUE_RANGE(prevHigh,prevLow,prevClose,tempReal);
/* Generated */       prevTR += tempReal;
/* Generated */       prevClose = inClose[today];
/* Generated */    }
/* Generated */    i = TA_GLOBALS_UNSTABLE_PERIOD(TA_FUNC_UNST_DX) + 1;
/* Generated */    while( i-- != 0 )
/* Generated */    {
/* Generated */       today++;
/* Generated */       tempReal = inHigh[today];
/* Generated */       diffP    = tempReal-prevHigh; 
/* Generated */       prevHigh = tempReal;
/* Generated */       tempReal = inLow[today];
/* Generated */       diffM    = prevLow-tempReal;   
/* Generated */       prevLow  = tempReal;
/* Generated */       prevMinusDM -= prevMinusDM/optInTimePeriod;
/* Generated */       prevPlusDM  -= prevPlusDM/optInTimePeriod;
/* Generated */       if( (diffM > 0) && (diffP < diffM) )
/* Generated */       {
/* Generated */          prevMinusDM += diffM;
/* Generated */       }
/* Generated */       else if( (diffP > 0) && (diffP > diffM) )
/* Generated */       {
/* Generated */          prevPlusDM += diffP;
/* Generated */       }
/* Generated */       TRUE_RANGE(prevHigh,prevLow,prevClose,tempReal);
/* Generated */       prevTR = prevTR - (prevTR/optInTimePeriod) + tempReal;
/* Generated */       prevClose = inClose[today];
/* Generated */    }
/* Generated */    if( !TA_IS_ZERO(prevTR) )
/* Generated */    {
/* Generated */       minusDI = round_pos(100.0*(prevMinusDM/prevTR));
/* Generated */       plusDI  = round_pos(100.0*(prevPlusDM/prevTR));
/* Generated */       tempReal = minusDI+plusDI;
/* Generated */       if( !TA_IS_ZERO(tempReal) )
/* Generated */          outReal[0] = round_pos( 100.0 * (fabs(minusDI-plusDI)/tempReal) );
/* Generated */       else
/* Generated */          outReal[0] = 0.0;
/* Generated */    }
/* Generated */    else
/* Generated */       outReal[0] = 0.0;
/* Generated */    outIdx = 1;
/* Generated */    while( today < endIdx )
/* Generated */    {
/* Generated */       today++;
/* Generated */       tempReal = inHigh[today];
/* Generated */       diffP    = tempReal-prevHigh; 
/* Generated */       prevHigh = tempReal;
/* Generated */       tempReal = inLow[today];
/* Generated */       diffM    = prevLow-tempReal;   
/* Generated */       prevLow  = tempReal;
/* Generated */       prevMinusDM -= prevMinusDM/optInTimePeriod;
/* Generated */       prevPlusDM  -= prevPlusDM/optInTimePeriod;
/* Generated */       if( (diffM > 0) && (diffP < diffM) )
/* Generated */       {
/* Generated */          prevMinusDM += diffM;
/* Generated */       }
/* Generated */       else if( (diffP > 0) && (diffP > diffM) )
/* Generated */       {
/* Generated */          prevPlusDM += diffP;
/* Generated */       }
/* Generated */       TRUE_RANGE(prevHigh,prevLow,prevClose,tempReal);
/* Generated */       prevTR = prevTR - (prevTR/optInTimePeriod) + tempReal;
/* Generated */       prevClose = inClose[today];
/* Generated */       if( !TA_IS_ZERO(prevTR))
/* Generated */       {
/* Generated */          minusDI = round_pos(100.0*(prevMinusDM/prevTR));
/* Generated */          plusDI  = round_pos(100.0*(prevPlusDM/prevTR));
/* Generated */          tempReal = minusDI+plusDI;
/* Generated */          if( !TA_IS_ZERO(tempReal))         
/* Generated */             outReal[outIdx] = round_pos( 100.0 * (fabs(minusDI-plusDI)/tempReal) );
/* Generated */          else
/* Generated */             outReal[outIdx] = outReal[outIdx-1];
/* Generated */       }
/* Generated */       else
/* Generated */          outReal[outIdx] = outReal[outIdx-1];
/* Generated */       outIdx++;
/* Generated */    }
/* Generated */    VALUE_HANDLE_DEREF(outNbElement) = outIdx;
/* Generated */    return NAMESPACE(TA_RetCode)TA_SUCCESS;
/* Generated */ }
/* Generated */ 
/* Generated */ #if defined( _MANAGED )
/* Generated */ }} // Close namespace TA.Lib
/* Generated */ #endif
/**** END GENCODE SECTION 5 - DO NOT DELETE THIS LINE ****/

