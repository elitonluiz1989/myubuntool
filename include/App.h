#ifndef APP_H_
#define APP_H_

#include <map>
#include "Ubuntu.h"

namespace std {

class App: public Ubuntu {
private:
    map<int, string> messages;
protected:
	void ppa(string ppaText);
	void install();

public:
    App();
	int installation();
};

} /* namespace std */

#endif /* APP_H_ */
