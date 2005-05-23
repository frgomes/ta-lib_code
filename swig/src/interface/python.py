# This python snippet is appended to the python module generated by SWIG
# customizing and extending its functionality


import re

# For ta_common

# TA_RetCodeInfo constructor can accept optional parameter

TA_RetCodeInfo.swig_init = TA_RetCodeInfo.__init__

def _temp_(self, code = 0):
    TA_RetCodeInfo.swig_init(self)
    TA_SetRetCodeInfo(code, self)

TA_RetCodeInfo.__init__ = _temp_




# Redefine TA_Timestamp.__init__ to a friendler version accepting optional parameters

TA_Timestamp.swig_init = TA_Timestamp.__init__

def _temp_(self, *params):
    TA_Timestamp.swig_init(self)

    if ( len(params) > 1 ):
        TA_SetDate( params[0], params[1], params[2], self )

    if ( len(params) > 3 ):
        TA_SetTime( params[3], params[4], params[5], self )

    if ( len(params) == 1 ): # like: "2004-02-28 15:37:55"
        rd = re.compile( r'(\d{2,4})-(\d{2})-(\d{2})' ) 
        md = rd.search( params[0] )
        if ( md ):
            TA_SetDate( int(md.group(1)), int(md.group(2)), int(md.group(3)), self )
        rt = re.compile( r'(\d{2}):(\d{2}):(\d{2})' )
        mt = rt.search( params[0] )
        if ( mt ):
            TA_SetTime( int(mt.group(1)), int(mt.group(2)), int(mt.group(3)), self )

TA_Timestamp.__init__ = _temp_




# parameter TA_Initialize is optional
# TA_Initialize protects itself against multiple calls

_initialized = False

def TA_Initialize(param = None):
    global _initialized
    if ( _initialized ):
        retCode = TA_Shutdown()
        if ( retCode != TA_SUCCESS ):
            return retCode

    retCode = _TaLib.TA_Initialize(param)
    _initialized = (retCode == TA_SUCCESS)
    return retCode



def TA_Shutdown():
    global _initialized
    if ( _initialized ):
        _initialized = False
        return _TaLib.TA_Shutdown()
    else:
        # We are more forgiving on multiple calls to TA_Shutdown
        # than TA-LIB on TA_Shutdown()
        return TA_SUCCESS




