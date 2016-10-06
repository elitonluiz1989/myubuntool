/*
 * App.h
 *
 *  Created on: 27 de set de 2016
 *      Author: elitonluiz1989
 */

#ifndef APP_H_
#define APP_H_

#include "Ubuntu.h"

namespace std {

class App: public Ubuntu {
	string command;
	public:
		void ppa(string ppa);
		int install(bool setppa = true);
};

} /* namespace std */

#endif /* APP_H_ */
