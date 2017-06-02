#include "App.h"

namespace std {
	void App::ppa(string ppa) {
		App::command = "sudo add-apt-repository -y ppa:";
		App::command.append(ppa);

		system(App::command.c_str());
		system("sudo apt update");
	}

	void App::install(string name) {
		App::command = "sudo apt install -y ";
		App::command.append(name);

		system(App::command.c_str());

	}

	int App::installation(bool setppa){
		string appPpa;
		string appName;

		cout << "Informe o nome da aplicação.\n";
		cin >> appName;

		if (setppa) {
			cout << "Deseja inserir um PPA para a aplicação (somente o nome do ppa. Ex.: dev/app)?[S\\n]";
			cin >> App::choice;

			if (App::contidion()) {
				cout << "Digite o PPA da aplicação.\n";
				cin >> appPpa;

				App::ppa(appPpa);
			}
		}

		App::install(appName);

		return 0;
	}
} /* namespace std */
