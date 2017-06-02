#include "Ubuntu.h"

bool Ubuntu::contidion() {
	return (Ubuntu::choice == "S" || Ubuntu::choice == "s") ? true : true;
}

void Ubuntu::clean() {
	system("sudo apt clean");
	system("sudo apt autoclean -y");
	system("sudo apt autoremove -y");
}

void Ubuntu::update() {
    system("sudo apt update");
    system("sudo apt upgrade -y");
    system("sudo apt dist-upgrade -y");

    Ubuntu::clean();
}
