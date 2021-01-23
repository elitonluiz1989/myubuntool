#ifndef UBUNTU_H_
#define UBUNTU_H_

#include <stdlib.h> //system
#include <vector>
#include <string>
#include <iterator>
#include <sstream>
#include <iostream>
#include "ISystem.h"

namespace std {

    class Ubuntu: public ISystem
    {
        public:
            bool processCommand(string command);
            string implode(const char * delimiter, vector<string> v);
            void clean();
            void update();
            bool addRepositories(vector<string> repositories);
            bool installPackages(vector<string> packages);
    };

} /* namespace std */

#endif /* UBUNTU_H_ */
