/*
 * SystemManager.cpp
 *
 *  Created on: 27 de set de 2016
 *      Author: elitonluiz1989
 */

#include "../include/SystemManager.h"

void SystemManager::clean() {
	system("sudo apt clean");
	system("sudo apt autoclean -y");
	system("sudo apt autoremove -y");
}

void SystemManager::update() {
    system("sudo apt update");
    system("sudo apt upgrade -y");
    system("sudo apt dist-upgrade -y");

    clean();
}
