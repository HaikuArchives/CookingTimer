/*
	
	TimerView.cpp
	
	Copyright ® 1998 Fumihiko Shibata,
	All Rights Reserved.
	
*/

#include "TimerView.h"
#include <SupportKit.h>
#include <stdio.h>

TimerView::TimerView(BRect rect, char *name)
	   	   : BView(rect, name, B_FOLLOW_ALL, B_WILL_DRAW | B_PULSE_NEEDED)
{
}


void TimerView::AttachedToWindow()
{
	SetFont(be_fixed_font);
	SetFontSize(24);
	isRunning = false;
	seconds = 0;
}


void TimerView::Draw(BRect)
{
	UpdateSeconds();
}

void TimerView::Pulse()
{
	if (isRunning)
		if (seconds) seconds--;
		else {
			if (isRunning) beep();
			isRunning = false;
			}
	UpdateSeconds();
}

void TimerView::UpdateSeconds()
{	
	char digits[3];

	SetHighColor(240, 230, 230, 0);
	FillRect(BRect(0, 0, 130, 20));

	SetHighColor(10, 200, 20, 0);	
	MovePenTo(BPoint(10, 17));
	sprintf(digits, "%02d", seconds / 3600);
	DrawString(digits);
	DrawString(":");
	MovePenTo(BPoint(50, 17));
	sprintf(digits, "%02d", (seconds / 60) % 60);
	DrawString(digits);
	DrawString(":");
	MovePenTo(BPoint(90, 17));
	sprintf(digits, "%02d", seconds % 60);
	DrawString(digits);
}
