#ifndef UBUNTU_H_
#define UBUNTU_H_

#include <stdlib.h> //system
#include <vector>
#include <string>
#include <iterator>
#include <sstream>
#include <iostream>

namespace std {

class Ubuntu {
public:
    static bool processCommand(string command);
    static string implode(const char * delimiter, vector<string> v);
	static void clean();
	static void update();
    static bool addRepositories(vector<string> repositories);
    static bool installPackages(vector<string> packages);
};

} /* namespace std */

#endif /* UBUNTU_H_ */
