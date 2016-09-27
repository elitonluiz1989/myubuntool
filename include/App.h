/*
 * App.h
 *
 *  Created on: 27 de set de 2016
 *      Author: elitonluiz1989
 */

#ifndef APP_H_
#define APP_H_

#include "../include/SystemManager.h"

namespace std {

class App: public SystemManager {
	public:
		void ppa(char ppa[]);
		void install();
};

} /* namespace std */

#endif /* APP_H_ */
