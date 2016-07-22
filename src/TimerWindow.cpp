/*
	
	TimerWindow.cpp
	
	Copyright ® 1998 Fumihiko Shibata,
	All Rights Reserved.
	
*/

#include <Application.h>
#include <InterfaceKit.h>

#include "TimerWindow.h"
#include "TimerView.h"

TimerWindow::TimerWindow(BRect frame)
				: BWindow(frame, "Timer", B_TITLED_WINDOW, B_NOT_RESIZABLE | B_NOT_ZOOMABLE)
{
	BRect	aRect;
	SetPulseRate(1000000.0);

	aRect.Set(10, 5, 140, 30);
	aView = new TimerView(aRect, "TimerView");
	AddChild(aView);

	aRect.Set(0, 0, 7, 7);
	char plusOffData[8] = {0xFE, 0x82, 0x92, 0xBA, 0x92, 0x82, 0xFE, 0x00};
	char plusOnData[8] = {0xFE, 0xFE, 0xEE, 0xC6, 0xEE, 0xFE, 0xFE, 0x00};
	char minusOffData[8] = {0xFE, 0x82, 0x82, 0xBA, 0x82, 0x82, 0xFE, 0x00};
	char minusOnData[8] = {0xFE, 0xFE, 0xFE, 0xC6, 0xFE, 0xFE, 0xFE, 0x00};

	BBitmap *plusOffBitmap = new BBitmap(aRect, B_GRAY1);
	plusOffBitmap->SetBits(&plusOffData, 8, 0, B_GRAY1);
	BBitmap *plusOnBitmap = new BBitmap(aRect, B_GRAY1);
	plusOnBitmap->SetBits(&plusOnData, 8, 0, B_GRAY1);
	BBitmap *minusOffBitmap = new BBitmap(aRect, B_GRAY1);
	minusOffBitmap->SetBits(&minusOffData, 8, 0, B_GRAY1);
	BBitmap *minusOnBitmap = new BBitmap(aRect, B_GRAY1);
	minusOnBitmap->SetBits(&minusOnData, 8, 0, B_GRAY1);

	BView	*tView;
	tView = new BView(aRect, "TempView", B_FOLLOW_NONE, B_FRAME_EVENTS);
	AddChild(tView);

	BPicture *plusOffPict;
	tView->BeginPicture(new BPicture);
	tView->DrawBitmap(plusOffBitmap);
	plusOffPict = tView->EndPicture();

	BPicture *plusOnPict;
	tView->BeginPicture(new BPicture);
	tView->DrawBitmap(plusOnBitmap);
	plusOnPict = tView->EndPicture();

	BPicture *minusOffPict;
	tView->BeginPicture(new BPicture);
	tView->DrawBitmap(minusOffBitmap);
	minusOffPict = tView->EndPicture();

	BPicture *minusOnPict;
	tView->BeginPicture(new BPicture);
	tView->DrawBitmap(minusOnBitmap);
	minusOnPict = tView->EndPicture();

	aRect.Set(40, 45, 110, 55);
	aButton = new BButton(aRect, START_B_NAME, START_B_NAME,
					new BMessage(START_B_MSG));
	AddChild(aButton);

	aRect.Set(23, 30, 33, 40);
	aPictureButton = new BPictureButton(aRect, HP_B_NAME, plusOffPict, plusOnPict,
					new BMessage(HP_B_MSG));
	AddChild(aPictureButton);

	aRect.Set(37, 30, 47, 40);
	aPictureButton = new BPictureButton(aRect, HM_B_NAME, minusOffPict, minusOnPict,
					new BMessage(HM_B_MSG));
	AddChild(aPictureButton);

	aRect.Set(63, 30, 73, 40);
	aPictureButton = new BPictureButton(aRect, MP_B_NAME, plusOffPict, plusOnPict,
					new BMessage(MP_B_MSG));
	AddChild(aPictureButton);

	aRect.Set(77, 30, 87, 40);
	aPictureButton = new BPictureButton(aRect, MM_B_NAME, minusOffPict, minusOnPict,
					new BMessage(MM_B_MSG));
	AddChild(aPictureButton);

	aRect.Set(103, 30, 113, 40);
	aPictureButton = new BPictureButton(aRect, SP_B_NAME, plusOffPict, plusOnPict,
					new BMessage(SP_B_MSG));
	AddChild(aPictureButton);

	aRect.Set(117, 30, 127, 40);
	aPictureButton = new BPictureButton(aRect, SM_B_NAME, minusOffPict, minusOnPict,
					new BMessage(SM_B_MSG));
	AddChild(aPictureButton);
	
	plusOffBitmap->~BBitmap();
	plusOnBitmap->~BBitmap();
	minusOffBitmap->~BBitmap();
	minusOnBitmap->~BBitmap();
	RemoveChild(tView);
	tView->~BView();
}

bool TimerWindow::QuitRequested()
{
	be_app->PostMessage(B_QUIT_REQUESTED);
	return(TRUE);
}

void TimerWindow::MessageReceived(BMessage* message)
{
	long secs = aView->seconds;

	switch(message->what)
	{
		case START_B_MSG:
			aView->isRunning = !aView->isRunning;
			break;
		case HP_B_MSG:
			if ((secs / 3600) != 99)
				secs += 3600;
			break;
		case HM_B_MSG:
			if (secs / 3600) 
				secs -= 3600;
			break;
		case MP_B_MSG:
			if (((secs / 60) % 60) != 59)
				secs += 60;
			break;
		case MM_B_MSG:
			if ((secs / 60) % 60) 
				secs -= 60;
			break;
		case SP_B_MSG:
			if ((secs % 60) != 59) 
				secs += 1;
			break;
		case SM_B_MSG:
			if (secs % 60) 
				secs -= 1;
			break;
		default:
			BWindow::MessageReceived(message);
	}

	aView->seconds = secs;
	aView->UpdateSeconds();
}

