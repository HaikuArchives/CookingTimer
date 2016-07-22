/*
	
	Timer.cpp
	
	Copyright ® 1998 Fumihiko Shibata,
	All Rights Reserved.
	
*/

#include "Timer.h"
#include "TimerWindow.h"

main()
{	
	TimerApplication *myApplication;

	myApplication = new TimerApplication();
	myApplication->Run();
	
	delete(myApplication);
	return(0);
}

TimerApplication::TimerApplication()
		  		  : BApplication("application/x-vnd.fmhk.cktmr")
{
	TimerWindow		*aWindow;
	BRect			aRect;

	aRect.Set(100, 80, 250, 155);
	aWindow = new TimerWindow(aRect);
	aWindow->Show();
}
