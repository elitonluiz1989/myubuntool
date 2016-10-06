/*
 * UBUNTU.h
 *
 *  Created on: 27 de set de 2016
 *      Author: elitonluiz1989
 */

#ifndef UBUNTU_H_
#define UBUNTU_H_

#include <stdlib.h> //system
#include <string> // string class and string handler functions
#include <iostream>

class Ubuntu {
	protected:
		std::string choice;
		bool contidion();

	public:
		void clean();
		void update();
};

#endif /* UBUNTU_H_ */
