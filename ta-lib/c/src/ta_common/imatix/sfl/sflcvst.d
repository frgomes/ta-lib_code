/*---------------------------------------------------------------------------*
 *  sflcvst.d - LIBERO dialog data definitions for sflcvst.c.                *
 *  Generated by LIBERO 2.30 on 24 Nov, 1997, 16:44.                         *
 *  Schema file used: lrschema.c.                                            *
 *---------------------------------------------------------------------------*/

/*- Symbolic constants and event numbers ------------------------------------*/

#define _LR_STOP                        0xFFFFL
#define _LR_NULL_EVENT                  -2
enum {
    terminate_event = -1,
    am_pm_event = 0,
    delimiter_event = 1,
    error_event = 2,
    finished_event = 3,
    number_event = 4,
    ok_event = 5
};

enum {
    _LR_defaults_state = 7,
    _LR_STATE_after_init = 0,
    _LR_STATE_expect_hour = 1,
    _LR_STATE_expect_minute = 2,
    _LR_STATE_expect_second = 3,
    _LR_STATE_expect_centisecond = 4,
    _LR_STATE_allow_am_pm = 5,
    _LR_STATE_expect_finished = 6,
    _LR_STATE_defaults = 7
};


/*- Variables used by dialog interpreter ------------------------------------*/

typedef int event_t;                    /*  Type for dialog entity           */
typedef void (fsmfunct) (void);         /*  Address of FSM function          */

static event_t
    _LR_event,                          /*  Event for state transition       */
    _LR_state,                          /*  Current dialog state             */
    _LR_savest,                         /*  Saved dialog state               */
    _LR_index,                          /*  Index into vector table          */
    the_next_event,                     /*  Next event from module           */
    the_exception_event;                /*  Exception event from module      */

static dbyte
   *_LR_vecptr;                         /*  Pointer into vector table        */

static Bool
    exception_raised;                   /*  TRUE if exception raised         */

/*- Function prototypes -----------------------------------------------------*/

#ifndef MODULE
#define MODULE  static void             /*  Libero dialog modules            */
#endif

local  raise_exception                  (event_t event);
MODULE initialise_the_program           (void);
MODULE get_external_event               (void);
MODULE get_next_component               (void);
MODULE have_hour                        (void);
MODULE have_am_pm_indicator             (void);
MODULE have_minute                      (void);
MODULE have_second                      (void);
MODULE have_centisecond                 (void);
MODULE have_complete_time               (void);
MODULE terminate_the_program            (void);
MODULE have_invalid_time                (void);
MODULE have_delimiter                   (void);

/*- Static areas ------------------------------------------------------------*/

static dbyte _LR_nextst [][6] =
{
    { 0,0,0,0,0,1 },
    { 1,0,0,0,2,0 },
    { 2,0,0,0,3,0 },
    { 3,0,0,0,4,0 },
    { 4,0,0,0,5,0 },
    { 6,0,0,0,0,0 },
    { 0,0,0,6,0,0 },
    { 7,7,7,7,7,0 }
};

static dbyte _LR_action [][6] =
{
    { 0,0,0,0,0,1 },
    { 3,0,0,0,2,0 },
    { 3,0,0,0,4,0 },
    { 3,0,0,0,5,0 },
    { 3,0,0,0,6,0 },
    { 3,0,0,0,0,0 },
    { 0,0,0,7,0,0 },
    { 8,9,8,7,8,0 }
};

static dbyte _LR_vector [][2+1] =
{
    {0},
    {0,_LR_STOP},
    {1,0,_LR_STOP},
    {2,0,_LR_STOP},
    {3,0,_LR_STOP},
    {4,0,_LR_STOP},
    {5,0,_LR_STOP},
    {6,7,_LR_STOP},
    {8,7,_LR_STOP},
    {9,0,_LR_STOP}
};

static fsmfunct *_LR_module [] =
{
    get_next_component,
    have_hour,
    have_am_pm_indicator,
    have_minute,
    have_second,
    have_centisecond,
    have_complete_time,
    terminate_the_program,
    have_invalid_time,
    have_delimiter
};

