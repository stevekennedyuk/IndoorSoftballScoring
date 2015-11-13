#pragma once
#include <pebble.h>

#define INNINGS_TIME 300 /* Each Inning is 5m or 300s */
#define MAX_INNINGS 2 /* 2 innings per game */

#define HOME_RUN 5 /* hitting back wall is 5 runs */
#define CATCHER_OUT -2 /* the catcher getting an out is -2 runs */

/*
 * sort of finite state machine
 */
	
#define ISS_START_GAME 1
#define ISS_PLAYING 2
#define ISS_PAUSE 3
#define ISS_CONTINUE 4
#define ISS_CHANGE 5
#define ISS_END 6


/*
 * Text for windows
 */

static char iss_T_timeleft[8] = "00:00.0";
static char iss_T_HomeScore[5] = " 000";
static char iss_T_AwayScore[5] = " 000";
static char iss_T_Inning[2] = "-";

/*
 * Globals
 */

static bool iss_Away = true;
static int iss_HomeScore[2] = {0,0};
static int iss_AwayScore[2] = {0,0};
static int iss_TotalHome = 0;
static int iss_TotalAway = 0;
static int iss_Inning = 0;
static bool iss_InGame = false;
static bool iss_Paused = false;
static int iss_Select_Status = ISS_START_GAME;

/*
 * Time structure
 */

static double iss_Elapsed_time = 0;
static double iss_Last_time = 0;
static double iss_Display_time = INNINGS_TIME;

/*
 * Application timer structure for a 100ms timer
 */
static AppTimer* update_timer = NULL;
