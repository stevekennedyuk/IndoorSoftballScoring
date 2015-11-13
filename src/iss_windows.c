#include "iss.h"
#include "iss_windows.h"
#include <pebble.h>

// BEGIN AUTO-GENERATED UI CODE; DO NOT MODIFY
static Window *s_window;
static GFont s_res_gothic_18_bold;
static GFont s_res_gothic_28;
static GFont s_res_gothic_28_bold;
static TextLayer *s_Up;
static TextLayer *s_Down;
static TextLayer *s_HomeAway;
static TextLayer *s_Status;
static TextLayer *s_HomeScore;
static TextLayer *s_AwayScore;
static TextLayer *s_TimeLeft;
static TextLayer *s_Innings;
static TextLayer *s_Home_const;
static TextLayer *s_Away_const;
static TextLayer *s_Inn_const;

static void initialise_ui(void) {
  s_window = window_create();
  #ifndef PBL_SDK_3
    window_set_fullscreen(s_window, 0);
  #endif
  
  s_res_gothic_18_bold = fonts_get_system_font(FONT_KEY_GOTHIC_18_BOLD);
  s_res_gothic_28 = fonts_get_system_font(FONT_KEY_GOTHIC_28);
  s_res_gothic_28_bold = fonts_get_system_font(FONT_KEY_GOTHIC_28_BOLD);
  // s_Up
  s_Up = text_layer_create(GRect(117, 6, 20, 20));
  text_layer_set_text(s_Up, "+");
  text_layer_set_text_alignment(s_Up, GTextAlignmentCenter);
  text_layer_set_font(s_Up, s_res_gothic_18_bold);
  layer_add_child(window_get_root_layer(s_window), (Layer *)s_Up);
  
  // s_Down
  s_Down = text_layer_create(GRect(117, 124, 20, 20));
  text_layer_set_text(s_Down, "-");
  text_layer_set_text_alignment(s_Down, GTextAlignmentCenter);
  text_layer_set_font(s_Down, s_res_gothic_18_bold);
  layer_add_child(window_get_root_layer(s_window), (Layer *)s_Down);
  
  // s_HomeAway
  s_HomeAway = text_layer_create(GRect(3, 6, 17, 26));
  text_layer_set_text(s_HomeAway, "A");
  text_layer_set_text_alignment(s_HomeAway, GTextAlignmentCenter);
  text_layer_set_font(s_HomeAway, s_res_gothic_18_bold);
  layer_add_child(window_get_root_layer(s_window), (Layer *)s_HomeAway);
  
  // s_Status
  s_Status = text_layer_create(GRect(69, 56, 73, 31));
  text_layer_set_text(s_Status, "Start");
  text_layer_set_text_alignment(s_Status, GTextAlignmentCenter);
  text_layer_set_font(s_Status, s_res_gothic_28);
  layer_add_child(window_get_root_layer(s_window), (Layer *)s_Status);
  
  // s_HomeScore
  s_HomeScore = text_layer_create(GRect(13, 47, 55, 32));
  text_layer_set_text(s_HomeScore, " ---");
  text_layer_set_text_alignment(s_HomeScore, GTextAlignmentCenter);
  text_layer_set_font(s_HomeScore, s_res_gothic_28_bold);
  layer_add_child(window_get_root_layer(s_window), (Layer *)s_HomeScore);
  
  // s_AwayScore
  s_AwayScore = text_layer_create(GRect(13, 82, 55, 32));
  text_layer_set_text(s_AwayScore, " ---");
  text_layer_set_text_alignment(s_AwayScore, GTextAlignmentCenter);
  text_layer_set_font(s_AwayScore, s_res_gothic_28_bold);
  layer_add_child(window_get_root_layer(s_window), (Layer *)s_AwayScore);
  
  // s_TimeLeft
  s_TimeLeft = text_layer_create(GRect(26, 5, 87, 37));
  text_layer_set_text(s_TimeLeft, "--:--.-");
  text_layer_set_text_alignment(s_TimeLeft, GTextAlignmentCenter);
  text_layer_set_font(s_TimeLeft, s_res_gothic_28_bold);
  layer_add_child(window_get_root_layer(s_window), (Layer *)s_TimeLeft);
  
  // s_Innings
  s_Innings = text_layer_create(GRect(33, 119, 14, 26));
  text_layer_set_text(s_Innings, "-");
  text_layer_set_text_alignment(s_Innings, GTextAlignmentCenter);
  text_layer_set_font(s_Innings, s_res_gothic_18_bold);
  layer_add_child(window_get_root_layer(s_window), (Layer *)s_Innings);
  
  // s_Home_const
  s_Home_const = text_layer_create(GRect(0, 52, 12, 20));
  text_layer_set_text(s_Home_const, "H");
  text_layer_set_text_alignment(s_Home_const, GTextAlignmentCenter);
  text_layer_set_font(s_Home_const, s_res_gothic_18_bold);
  layer_add_child(window_get_root_layer(s_window), (Layer *)s_Home_const);
  
  // s_Away_const
  s_Away_const = text_layer_create(GRect(0, 87, 12, 20));
  text_layer_set_text(s_Away_const, "A");
  text_layer_set_text_alignment(s_Away_const, GTextAlignmentCenter);
  text_layer_set_font(s_Away_const, s_res_gothic_18_bold);
  layer_add_child(window_get_root_layer(s_window), (Layer *)s_Away_const);
  
  // s_Inn_const
  s_Inn_const = text_layer_create(GRect(4, 119, 27, 26));
  text_layer_set_text(s_Inn_const, "Inn:");
  text_layer_set_font(s_Inn_const, s_res_gothic_18_bold);
  layer_add_child(window_get_root_layer(s_window), (Layer *)s_Inn_const);
}

static void destroy_ui(void) {
  window_destroy(s_window);
  text_layer_destroy(s_Up);
  text_layer_destroy(s_Down);
  text_layer_destroy(s_HomeAway);
  text_layer_destroy(s_Status);
  text_layer_destroy(s_HomeScore);
  text_layer_destroy(s_AwayScore);
  text_layer_destroy(s_TimeLeft);
  text_layer_destroy(s_Innings);
  text_layer_destroy(s_Home_const);
  text_layer_destroy(s_Away_const);
  text_layer_destroy(s_Inn_const);
}
// END AUTO-GENERATED UI CODE

static void handle_window_unload(Window* window) {
  destroy_ui();
}
	

void format_time(double count_time, char* buffer) {
	int tenths = (int)(count_time * 10) % 10;
	int seconds = (int)count_time % 60;
	int minutes = (int)(count_time / 60) % 60;

	snprintf(buffer, 8, "%02d:%02d.%d", minutes, seconds, tenths);
}

double float_time_ms() {
	time_t seconds;
	uint16_t milliseconds;
	time_ms(&seconds, &milliseconds);
	return (double)seconds + ((double)milliseconds / 1000.0);
}

void handle_timer(void* data) {
	double now = float_time_ms();
	if (iss_Paused){
		app_timer_cancel(update_timer);
	}
	else {
		iss_Elapsed_time += now - iss_Last_time;
		iss_Last_time = now;
		update_timer = app_timer_register(100, handle_timer, NULL);
		iss_Display_time = INNINGS_TIME - iss_Elapsed_time;
		if (iss_Display_time <= 0){
			iss_Select_Status = ISS_CHANGE;
			app_timer_cancel(update_timer);
			text_layer_set_text(s_Status, "Change");
			vibes_long_pulse();
		} else {
			format_time(iss_Display_time, iss_T_timeleft);
			text_layer_set_text(s_TimeLeft, iss_T_timeleft);
		}
	}
}

static void select_click_handler(ClickRecognizerRef recognizer, void *context) {
	int i;
	switch (iss_Select_Status){
		case ISS_START_GAME:
		iss_Inning=0;
		iss_TotalHome = 0;
		iss_TotalAway = 0;
		for (i = 0; i < MAX_INNINGS; i++){
			iss_HomeScore[i] = 0;
			iss_AwayScore[i] = 0;
		}
		iss_InGame = true;
		iss_Away = true;
		snprintf(iss_T_Inning, 2, "%d", (iss_Inning +1));
		text_layer_set_text(s_Innings, iss_T_Inning);
		iss_Paused = false;
		iss_Elapsed_time = 0;
		iss_Display_time = INNINGS_TIME - iss_Elapsed_time;
		iss_Select_Status = ISS_PAUSE;
		text_layer_set_text(s_Status,"Pause");
		text_layer_set_text(s_HomeAway,"A");
		text_layer_set_text(s_AwayScore," 000");
		text_layer_set_text(s_HomeScore," 000");
		iss_Display_time = INNINGS_TIME - iss_Elapsed_time;
		format_time(iss_Display_time, iss_T_timeleft);
		text_layer_set_text(s_TimeLeft, iss_T_timeleft);
		iss_Last_time = float_time_ms();
		update_timer = app_timer_register(100, handle_timer, NULL);
		break;
		
		case ISS_PAUSE:
		iss_Paused = true;
		iss_Select_Status = ISS_CONTINUE;
		text_layer_set_text(s_Status,"Start");
		break;
		
		case ISS_CONTINUE:
		iss_Paused = false;
		iss_InGame = true;
		iss_Select_Status=ISS_PAUSE;
		text_layer_set_text(s_Status,"Pause");
		iss_Last_time = float_time_ms();
		update_timer = app_timer_register(100, handle_timer, NULL);
		break;
		
		case ISS_CHANGE:
		iss_InGame = false;
		if (iss_Away){
			iss_Away = false;
			iss_Paused = false;
			iss_Elapsed_time = 0;
			iss_Display_time = INNINGS_TIME - iss_Elapsed_time;
			iss_Select_Status = ISS_CONTINUE;
			text_layer_set_text(s_HomeScore," 000");
			text_layer_set_text(s_Status,"Start");
			text_layer_set_text(s_HomeAway,"H");
		}
		else {
			iss_Inning++;
			if (iss_Inning == MAX_INNINGS){
				app_timer_cancel(update_timer);
				iss_Select_Status = ISS_END;
				text_layer_set_text(s_Status,"End");
			}
			else {
				iss_Away = true;
				snprintf(iss_T_Inning, 2, "%d", (iss_Inning +1));
				text_layer_set_text(s_Innings, iss_T_Inning);
				iss_Paused = false;
				iss_Elapsed_time = 0;
				iss_Display_time = INNINGS_TIME - iss_Elapsed_time;
				iss_Select_Status = ISS_CONTINUE;
				text_layer_set_text(s_AwayScore," 000");
				text_layer_set_text(s_HomeScore," 000");
				text_layer_set_text(s_Status,"Start");
				text_layer_set_text(s_HomeAway,"A");
			}
		}
		break;
		
		case ISS_END:
		iss_InGame = false;	
		text_layer_set_text(s_Innings,"E");
		for (i = 0; i < MAX_INNINGS; i++){
			iss_TotalAway += iss_AwayScore[i];
			iss_TotalHome += iss_HomeScore[i];
		}
		if (iss_TotalHome < 0){
				snprintf(iss_T_HomeScore,5,"%04d",iss_TotalHome);
				text_layer_set_text(s_HomeScore,iss_T_HomeScore);
			} else {
				snprintf(iss_T_HomeScore,5," %03d",iss_TotalHome);
				text_layer_set_text(s_HomeScore,iss_T_HomeScore);
		}
		if (iss_TotalAway < 0){
				snprintf(iss_T_AwayScore,5,"%04d",iss_TotalAway);
				text_layer_set_text(s_AwayScore,iss_T_AwayScore);
			} else {
				snprintf(iss_T_AwayScore,5," %03d",iss_TotalAway);
				text_layer_set_text(s_AwayScore,iss_T_AwayScore);
		}
		iss_Select_Status = ISS_START_GAME;
		text_layer_set_text(s_Status,"Start");
		break;
	}
}

static void up_click_handler(ClickRecognizerRef recognizer, void *context) {
	if (iss_Paused || iss_InGame){
		if (iss_Away){
			iss_AwayScore[iss_Inning]++;
			if (iss_AwayScore[iss_Inning] < 0 ){
				snprintf(iss_T_AwayScore,5,"%04d",iss_AwayScore[iss_Inning]);
				text_layer_set_text(s_AwayScore,iss_T_AwayScore);
			} else {
				snprintf(iss_T_AwayScore,5," %03d",iss_AwayScore[iss_Inning]);
				text_layer_set_text(s_AwayScore,iss_T_AwayScore);
			}
		}
		else {
			iss_HomeScore[iss_Inning]++;
			if (iss_HomeScore[iss_Inning] < 0){
				snprintf(iss_T_HomeScore,5,"%04d",iss_HomeScore[iss_Inning]);
				text_layer_set_text(s_HomeScore,iss_T_HomeScore);
			} else {
				snprintf(iss_T_HomeScore,5," %03d",iss_HomeScore[iss_Inning]);
				text_layer_set_text(s_HomeScore,iss_T_HomeScore);
			}
		}
	}
}

static void up_click_handler_multi(ClickRecognizerRef recognizer, void *context) {
	if (iss_Paused || iss_InGame){
		if (iss_Away){
			iss_AwayScore[iss_Inning] += HOME_RUN;
			if (iss_AwayScore[iss_Inning] < 0 ){
				snprintf(iss_T_AwayScore,5,"%04d",iss_AwayScore[iss_Inning]);
				text_layer_set_text(s_AwayScore,iss_T_AwayScore);
			} else {
				snprintf(iss_T_AwayScore,5," %03d",iss_AwayScore[iss_Inning]);
				text_layer_set_text(s_AwayScore,iss_T_AwayScore);
			}
		}
		else {
			iss_HomeScore[iss_Inning] += HOME_RUN;
			if (iss_HomeScore[iss_Inning] < 0){
				snprintf(iss_T_HomeScore,5,"%04d",iss_HomeScore[iss_Inning]);
				text_layer_set_text(s_HomeScore,iss_T_HomeScore);
			} else {
				snprintf(iss_T_HomeScore,5," %03d",iss_HomeScore[iss_Inning]);
				text_layer_set_text(s_HomeScore,iss_T_HomeScore);
			}
		}
	}
}

static void down_click_handler(ClickRecognizerRef recognizer, void *context) {
	if (iss_Paused || iss_InGame){
		if (iss_Away){
			iss_AwayScore[iss_Inning]--;
			if (iss_AwayScore[iss_Inning] < 0){
				snprintf(iss_T_AwayScore,5,"%04d",iss_AwayScore[iss_Inning]);
				text_layer_set_text(s_AwayScore,iss_T_AwayScore);
			} else {
				snprintf(iss_T_AwayScore,4,"%03d",iss_AwayScore[iss_Inning]);
				text_layer_set_text(s_AwayScore,iss_T_AwayScore);
			}
		}
		else{
			iss_HomeScore[iss_Inning]--;
			if (iss_HomeScore[iss_Inning] < 0){
				snprintf(iss_T_HomeScore,5,"%04d",iss_HomeScore[iss_Inning]);
				text_layer_set_text(s_HomeScore,iss_T_HomeScore);
			} else {
				snprintf(iss_T_HomeScore,4,"%03d",iss_HomeScore[iss_Inning]);
				text_layer_set_text(s_HomeScore,iss_T_HomeScore);
			}
		}
	}
}

static void down_click_handler_multi(ClickRecognizerRef recognizer, void *context) {
	if (iss_Paused || iss_InGame){
		if (iss_Away){
			iss_AwayScore[iss_Inning] += CATCHER_OUT;
			if (iss_AwayScore[iss_Inning] < 0){
				snprintf(iss_T_AwayScore,5,"%04d",iss_AwayScore[iss_Inning]);
				text_layer_set_text(s_AwayScore,iss_T_AwayScore);
			} else {
				snprintf(iss_T_AwayScore,4,"%03d",iss_AwayScore[iss_Inning]);
				text_layer_set_text(s_AwayScore,iss_T_AwayScore);
			}
		}
		else{
			iss_HomeScore[iss_Inning] += CATCHER_OUT;
			if (iss_HomeScore[iss_Inning] < 0){
				snprintf(iss_T_HomeScore,5,"%04d",iss_HomeScore[iss_Inning]);
				text_layer_set_text(s_HomeScore,iss_T_HomeScore);
			} else {
				snprintf(iss_T_HomeScore,4,"%03d",iss_HomeScore[iss_Inning]);
				text_layer_set_text(s_HomeScore,iss_T_HomeScore);
			}
		}
	}
}

static void click_config_provider(void *context) {
  window_single_click_subscribe(BUTTON_ID_SELECT, select_click_handler);
  window_single_click_subscribe(BUTTON_ID_UP, up_click_handler);
  window_multi_click_subscribe(BUTTON_ID_UP, 2, 0, 0, true, up_click_handler_multi);
  window_single_click_subscribe(BUTTON_ID_DOWN, down_click_handler);
  window_multi_click_subscribe(BUTTON_ID_DOWN, 2, 0, 0, true, down_click_handler_multi);
}

void show_iss_windows(void) {
	initialise_ui();
	window_set_window_handlers(s_window, (WindowHandlers) {
    .unload = handle_window_unload,
  });
	window_set_click_config_provider(s_window, click_config_provider);
	window_stack_push(s_window, true);
}

void hide_iss_windows(void) {
  window_stack_remove(s_window, true);
}
