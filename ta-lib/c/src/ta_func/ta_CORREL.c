/* TA-LIB Copyright (c) 1999-2003, Mario Fortier
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
 *
 *
 * Change history:
 *
 *  MMDDYY BY   Description
 *  -------------------------------------------------------------------
 *  120802 MF   Template creation.
 *  101003 MF   Initial Coding
 *
 */

/**** START GENCODE SECTION 1 - DO NOT DELETE THIS LINE ****/
/* All code within this section is automatically
 * generated by gen_code. Any modification will be lost
 * next time gen_code is run.
 */
/* Generated */ 
/* Generated */ #if defined( _MANAGED )
/* Generated */    #using <mscorlib.dll>
/* Generated */    #include "Core.h"
/* Generated */    namespace TA { namespace Lib {
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
/* Generated */ int Core::CORREL_Lookback( int           optInTimePeriod )  /* From 1 to 100000 */
/* Generated */ 
/* Generated */ #else
/* Generated */ int TA_CORREL_Lookback( int           optInTimePeriod )  /* From 1 to 100000 */
/* Generated */ 
/* Generated */ #endif
/**** END GENCODE SECTION 1 - DO NOT DELETE THIS LINE ****/
{
   /* insert lookback code here. */
   return optInTimePeriod-1;
}

/**** START GENCODE SECTION 2 - DO NOT DELETE THIS LINE ****/
/*
 * TA_CORREL - Pearson's Correlation Coefficient (r)
 * 
 * Input  = double, double
 * Output = double
 * 
 * Optional Parameters
 * -------------------
 * optInTimePeriod:(From 1 to 100000)
 *    Number of period
 * 
 * 
 */
/* Generated */ 
/* Generated */ #if defined( _MANAGED )
/* Generated */ enum Core::TA_RetCode Core::CORREL( int    startIdx,
/* Generated */                                     int    endIdx,
/* Generated */                                     double       inReal0 __gc [],
/* Generated */                                     double       inReal1 __gc [],
/* Generated */                                     int           optInTimePeriod, /* From 1 to 100000 */
/* Generated */                                     [OutAttribute]Int32 *outBegIdx,
/* Generated */                                     [OutAttribute]Int32 *outNbElement,
/* Generated */                                     double        outReal __gc [] )
/* Generated */ #else
/* Generated */ TA_RetCode TA_CORREL( int    startIdx,
/* Generated */                       int    endIdx,
/* Generated */                       const double inReal0[],
/* Generated */                       const double inReal1[],
/* Generated */                       int           optInTimePeriod, /* From 1 to 100000 */
/* Generated */                       int          *outBegIdx,
/* Generated */                       int          *outNbElement,
/* Generated */                       double        outReal[] )
/* Generated */ #endif
/**** END GENCODE SECTION 2 - DO NOT DELETE THIS LINE ****/
{
	/* insert local variable here */
    double sumXY, sumX, sumY, sumX2, sumY2, n, x, y, trailingX, trailingY;
    int lookbackTotal, today, trailingIdx, outIdx;

/**** START GENCODE SECTION 3 - DO NOT DELETE THIS LINE ****/
/* Generated */ 
/* Generated */ #ifndef TA_FUNC_NO_RANGE_CHECK
/* Generated */ 
/* Generated */    /* Validate the requested output range. */
/* Generated */    if( startIdx < 0 )
/* Generated */       return TA_OUT_OF_RANGE_START_INDEX;
/* Generated */    if( (endIdx < 0) || (endIdx < startIdx))
/* Generated */       return TA_OUT_OF_RANGE_END_INDEX;
/* Generated */ 
/* Generated */    /* Validate the parameters. */
/* Generated */    if( !inReal0 ) return TA_BAD_PARAM;
/* Generated */    if( !inReal1 ) return TA_BAD_PARAM;
/* Generated */    /* min/max are checked for optInTimePeriod. */
/* Generated */    if( (int)optInTimePeriod == TA_INTEGER_DEFAULT )
/* Generated */       optInTimePeriod = 30;
/* Generated */    else if( ((int)optInTimePeriod < 1) || ((int)optInTimePeriod > 100000) )
/* Generated */       return TA_BAD_PARAM;
/* Generated */ 
/* Generated */    if( outReal == NULL )
/* Generated */       return TA_BAD_PARAM;
/* Generated */ 
/* Generated */ #endif /* TA_FUNC_NO_RANGE_CHECK */
/* Generated */ 
/**** END GENCODE SECTION 3 - DO NOT DELETE THIS LINE ****/

   /* Insert TA function code here. */

   /* Move up the start index if there is not
    * enough initial data.
    */
   lookbackTotal = optInTimePeriod-1;
   if( startIdx < lookbackTotal )
      startIdx = lookbackTotal;

   /* Make sure there is still something to evaluate. */
   if( startIdx > endIdx )
   {
      *outBegIdx    = 0;
      *outNbElement = 0;
      return TA_SUCCESS;
   }

   *outBegIdx  = startIdx;
   trailingIdx = startIdx - lookbackTotal;

   /* Calculate the initial values. */
   sumXY = sumX = sumY = sumX2 = sumY2 = 0.0;
   for( today=trailingIdx; today <= startIdx; today++ )
   {
      x = inReal0[today];
      sumX  += x;
      sumX2 += x*x;

      y = inReal1[today];
      sumXY += x*y;
      sumY  += y;
      sumY2 += y*y;
   }

   /* Write the first output. 
    * Save first the trailing values since the input
    * and output might be the same array,
    */
   trailingX = inReal0[trailingIdx];
   trailingY = inReal1[trailingIdx++];
   n = optInTimePeriod;
   outReal[0] = (sumXY-((sumX*sumY)/n)) / sqrt( (sumX2-((sumX*sumX)/n)) * (sumY2-((sumY*sumY)/n)));


   /* Tight loop to do subsequent values. */
   outIdx = 1;
   while( today <= endIdx )
   {
      /* Remove trailing values */
      sumX  -= trailingX;
      sumX2 -= trailingX*trailingX;

      sumXY -= trailingX*trailingY;
      sumY  -= trailingY;
      sumY2 -= trailingY*trailingY;

      /* Add new values */
      x = inReal0[today];
      sumX  += x;
      sumX2 += x*x;

      y = inReal1[today++];
      sumXY += x*y;
      sumY  += y;
      sumY2 += y*y;

      /* Output new coefficient.
       * Save first the trailing values since the input
       * and output might be the same array,
       */
      trailingX = inReal0[trailingIdx];
      trailingY = inReal1[trailingIdx++];
      outReal[outIdx++] = (sumXY-((sumX*sumY)/n)) / sqrt( (sumX2-((sumX*sumX)/n)) * (sumY2-((sumY*sumY)/n)));
   }  

   *outNbElement = outIdx;

   return TA_SUCCESS;
}

/**** START GENCODE SECTION 4 - DO NOT DELETE THIS LINE ****/
/* Generated */ 
/* Generated */ #define  USE_SINGLE_PRECISION_INPUT
/* Generated */ #if !defined( _MANAGED )
/* Generated */    #undef   TA_PREFIX
/* Generated */    #define  TA_PREFIX(x) TA_S_##x
/* Generated */ #endif
/* Generated */ #undef   INPUT_TYPE
/* Generated */ #define  INPUT_TYPE float
/* Generated */ #if defined( _MANAGED )
/* Generated */ enum Core::TA_RetCode Core::CORREL( int    startIdx,
/* Generated */                                     int    endIdx,
/* Generated */                                     float        inReal0 __gc [],
/* Generated */                                     float        inReal1 __gc [],
/* Generated */                                     int           optInTimePeriod, /* From 1 to 100000 */
/* Generated */                                     [OutAttribute]Int32 *outBegIdx,
/* Generated */                                     [OutAttribute]Int32 *outNbElement,
/* Generated */                                     double        outReal __gc [] )
/* Generated */ #else
/* Generated */ TA_RetCode TA_S_CORREL( int    startIdx,
/* Generated */                         int    endIdx,
/* Generated */                         const float  inReal0[],
/* Generated */                         const float  inReal1[],
/* Generated */                         int           optInTimePeriod, /* From 1 to 100000 */
/* Generated */                         int          *outBegIdx,
/* Generated */                         int          *outNbElement,
/* Generated */                         double        outReal[] )
/* Generated */ #endif
/* Generated */ {
/* Generated */     double sumXY, sumX, sumY, sumX2, sumY2, n, x, y, trailingX, trailingY;
/* Generated */     int lookbackTotal, today, trailingIdx, outIdx;
/* Generated */  #ifndef TA_FUNC_NO_RANGE_CHECK
/* Generated */     if( startIdx < 0 )
/* Generated */        return TA_OUT_OF_RANGE_START_INDEX;
/* Generated */     if( (endIdx < 0) || (endIdx < startIdx))
/* Generated */        return TA_OUT_OF_RANGE_END_INDEX;
/* Generated */     if( !inReal0 ) return TA_BAD_PARAM;
/* Generated */     if( !inReal1 ) return TA_BAD_PARAM;
/* Generated */     if( (int)optInTimePeriod == TA_INTEGER_DEFAULT )
/* Generated */        optInTimePeriod = 30;
/* Generated */     else if( ((int)optInTimePeriod < 1) || ((int)optInTimePeriod > 100000) )
/* Generated */        return TA_BAD_PARAM;
/* Generated */     if( outReal == NULL )
/* Generated */        return TA_BAD_PARAM;
/* Generated */  #endif 
/* Generated */    lookbackTotal = optInTimePeriod-1;
/* Generated */    if( startIdx < lookbackTotal )
/* Generated */       startIdx = lookbackTotal;
/* Generated */    if( startIdx > endIdx )
/* Generated */    {
/* Generated */       *outBegIdx    = 0;
/* Generated */       *outNbElement = 0;
/* Generated */       return TA_SUCCESS;
/* Generated */    }
/* Generated */    *outBegIdx  = startIdx;
/* Generated */    trailingIdx = startIdx - lookbackTotal;
/* Generated */    sumXY = sumX = sumY = sumX2 = sumY2 = 0.0;
/* Generated */    for( today=trailingIdx; today <= startIdx; today++ )
/* Generated */    {
/* Generated */       x = inReal0[today];
/* Generated */       sumX  += x;
/* Generated */       sumX2 += x*x;
/* Generated */       y = inReal1[today];
/* Generated */       sumXY += x*y;
/* Generated */       sumY  += y;
/* Generated */       sumY2 += y*y;
/* Generated */    }
/* Generated */    trailingX = inReal0[trailingIdx];
/* Generated */    trailingY = inReal1[trailingIdx++];
/* Generated */    n = optInTimePeriod;
/* Generated */    outReal[0] = (sumXY-((sumX*sumY)/n)) / sqrt( (sumX2-((sumX*sumX)/n)) * (sumY2-((sumY*sumY)/n)));
/* Generated */    outIdx = 1;
/* Generated */    while( today <= endIdx )
/* Generated */    {
/* Generated */       sumX  -= trailingX;
/* Generated */       sumX2 -= trailingX*trailingX;
/* Generated */       sumXY -= trailingX*trailingY;
/* Generated */       sumY  -= trailingY;
/* Generated */       sumY2 -= trailingY*trailingY;
/* Generated */       x = inReal0[today];
/* Generated */       sumX  += x;
/* Generated */       sumX2 += x*x;
/* Generated */       y = inReal1[today++];
/* Generated */       sumXY += x*y;
/* Generated */       sumY  += y;
/* Generated */       sumY2 += y*y;
/* Generated */       trailingX = inReal0[trailingIdx];
/* Generated */       trailingY = inReal1[trailingIdx++];
/* Generated */       outReal[outIdx++] = (sumXY-((sumX*sumY)/n)) / sqrt( (sumX2-((sumX*sumX)/n)) * (sumY2-((sumY*sumY)/n)));
/* Generated */    }  
/* Generated */    *outNbElement = outIdx;
/* Generated */    return TA_SUCCESS;
/* Generated */ }
/* Generated */ 
/* Generated */ #if defined( _MANAGED )
/* Generated */ }} // Close namespace TA.Lib
/* Generated */ #endif
/**** END GENCODE SECTION 4 - DO NOT DELETE THIS LINE ****/

