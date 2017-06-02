#ifndef APP_H_
#define APP_H_

#include "Ubuntu.h"

namespace std {

class App: public Ubuntu {
	private:
	string command;

	protected:
		void ppa(string ppa);
		void install(string name);

	public:
		int installation(bool setppa = true);
};

} /* namespace std */

#endif /* APP_H_ */
