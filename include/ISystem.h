#ifndef ISYSTEM_H_
#define ISYSTEM_H_

#include <vector>
#include <string>

namespace std {
    class ISystem {
        public:
            virtual bool processCommand(string command) = 0;
            virtual string implode(const char * delimiter, vector<string> v) = 0;
            virtual void clean() = 0;
            virtual void update() = 0;
            virtual bool addRepositories(vector<string> repositories) = 0;
            virtual bool installPackages(vector<string> packages) = 0;
    };

} /* namespace std */

#endif /* ISYSTEM_H_ */