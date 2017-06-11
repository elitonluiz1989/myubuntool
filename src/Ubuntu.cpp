#include "Ubuntu.h"

namespace std {
    bool Ubuntu::processCommand(string command)
    {
        int result;

        result = system(command.c_str());

        return (result == 0) ? true : false;
    }

    string Ubuntu::implode(const char * delimiter, vector<string> v)
    {
        if (v.size() > 1) {
            ostringstream result;
            copy(v.begin(), v.end(), ostream_iterator<string>(result, delimiter));

            return result.str();
        } else {
            return v.front();
        }
    }

    void Ubuntu::clean()
    {
        string command = "sudo apt clean";
    	command.append(" && sudo apt autoclean -y");
    	command.append(" && sudo apt autoremove -y");

        system(command.c_str());
    }

    void Ubuntu::update()
    {
        string command = "sudo apt update";
        command.append(" && sudo apt upgrade -y");
        command.append(" && sudo apt dist-upgrade -y");

        system(command.c_str());

        Ubuntu::clean();
    }

    bool Ubuntu::addRepositories(vector<string> repositories)
    {
        string command;
        const char * delimiter = " && ";
        size_t size = repositories.size();

        for (vector<string>::size_type i = 0; i < size; i++) {
            repositories[i].insert(0, "sudo add-apt-repository -y ppa:");
        }

        command = Ubuntu::implode(delimiter, repositories);

        return Ubuntu::processCommand(command);
    }

    bool Ubuntu::installPackages(vector<string> packages)
    {
        string command = "sudo apt install -y ";
        const char * delimiter = " ";
        command.append(Ubuntu::implode(delimiter, packages));

        return Ubuntu::processCommand(command);
    }
}
