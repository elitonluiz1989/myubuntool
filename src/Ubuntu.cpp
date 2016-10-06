/*
 * Ubuntu.cpp
 *
 *  Created on: 27 de set de 2016
 *      Author: elitonluiz1989
 */

#include "../include/Ubuntu.h"

void Ubuntu::clean() {
	system("sudo apt clean");
	system("sudo apt autoclean -y");
	system("sudo apt autoremove -y");
}

bool Ubuntu::contidion() {
	if (Ubuntu::choice == "S" || Ubuntu::choice == "s") {
		return true;
	} else {
		return true;
	}
}

void Ubuntu::update() {
    system("sudo apt update");
    system("sudo apt upgrade -y");
    system("sudo apt dist-upgrade -y");

    Ubuntu::clean();
}
