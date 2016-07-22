/*
	
	TimerView.h
	
	Copyright ® 1998 Fumihiko Shibata,
	All Rights Reserved.
	
*/

#ifndef TIMER_VIEW_H
#define TIMER_VIEW_H

#include <View.h>

class TimerView : public BView {

public:
				TimerView(BRect frame, char *name); 
virtual	void	AttachedToWindow();
virtual	void	Draw(BRect updateRect);
virtual void	Pulse();

		void UpdateSeconds();
		bool isRunning;
		long seconds;
};

#endif