/*
	
	TimerWindow.h
	
	Copyright ® 1998 Fumihiko Shibata,
	All Rights Reserved.
	
*/

#ifndef TIMER_WINDOW_H
#define TIMER_WINDOW_H

#include <Window.h>
#include "TimerView.h"

#define	START_B_NAME	"Start / Stop"
#define	START_B_MSG		'STRT'

#define	HP_B_NAME		"HourPlus"
#define	HP_B_MSG		'HPLS'
#define	HM_B_NAME		"HourMinus"
#define	HM_B_MSG		'HMIN'
#define	MP_B_NAME		"MinPlus"
#define	MP_B_MSG		'MPLS'
#define	MM_B_NAME		"MinMinus"
#define	MM_B_MSG		'MMIN'
#define	SP_B_NAME		"SecondPlus"
#define	SP_B_MSG		'SPLS'
#define	SM_B_NAME		"SecondMinus"
#define	SM_B_MSG		'SMIN'

class TimerWindow : public BWindow {

public:
				TimerWindow(BRect frame); 
	virtual	bool	QuitRequested();
	virtual void	MessageReceived(BMessage *message);
	private:
		TimerView	*aView;
		BButton		*aButton;
		BPictureButton	*aPictureButton;
};

#endif
