#ifndef APP_H_
#define APP_H_

#include <map>
#include "ISystem.h"
#include "Ubuntu.h"

namespace std {

class App {
private:
    map<int, string> messages;
	ISystem *system;
protected:
	void ppa(string ppaText);
	void install();

public:
    App();
	int installation();
	int menu(int option);
};

} /* namespace std */

#endif /* APP_H_ */
