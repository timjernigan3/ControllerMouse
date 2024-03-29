// Author: Tim Jernigan
// Created On: 12.26.2018 
// Updated Last: 6.12.2019
// Description : This is my main driver.
// Version: 1.05 I have basic mouse functionality.

#include "stdafx.h"
#include "XboxControl.h"
#include <string>

XboxControl* mainUser;
POINT mouse;

int main(){
	
	mainUser = new XboxControl(1);
	bool mouseModeToggle = true;
	int onOffCounter = 1;

	/* Instructions -Tim Jernigan */
	std::cout << "Instructions: " << std::endl;
	std::cout << "  By Default the Mouse is On." << std::endl;
	std::cout << "  Press DOWN on the Dpad to toggle between the controller On or Off." << std::endl;
	std::cout << "  Writen By: Tim Jernigan." << std::endl;
	std::cout << std::endl;
	std::cout << "Mouse Mode: " << std::endl;
	std::cout << "  Tap the A button once to hold left click." << std::endl;
	std::cout << "  Double Tap the A button to Left Click." << std::endl;
	std::cout << "  The B button is the Right Click." << std::endl;
	std::cout << "  The Left Joystick controlls the mouse's movement." << std::endl;
	std::cout << "  The Right Joystick controlls the scroll wheel. " << std::endl;
	std::cout << std::endl;
	std::cout << "MOUSE MODE: ON" << std::endl;

	while (true) {
		if (mainUser->IsConnected()) {
			// turns on and off
			if (mainUser->GetState().Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_DOWN) {
				Sleep(250);
				onOffCounter++;
				if (onOffCounter % 2 == 0) {
					std::cout << "XBOX Controller MODE: OFF\n" << std::endl;
					mouseModeToggle = false;
				}
				else {
					std::cout << "\nMOUSE MODE: ACTIVATED" << std::endl;
					mouseModeToggle = true;
				}
			}

			if (mouseModeToggle) {
				mainUser->mouseMode(mouse);
			}
		}
		else {
			std::cout << "\nERROR! Your XBOX Controller was not found!\n";
			std::system("Pause");
			break;
		}
	}
    return 0;
}

