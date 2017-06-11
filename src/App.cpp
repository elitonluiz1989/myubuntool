#include "App.h"

namespace std {
    App::App()
    {
        App::messages[0] = "Deseja inserir um PPA para a aplicação (somente o nome do ppa. Ex.: dev/app, não ppa:dev/app)?[S\\n]\n";
        App::messages[1] = "\nDigite o PPA da aplicação.\n";
        App::messages[2] = "Erro no PPA. Verifique se está correto e reinsira-o.\nCasa deseja cancelar, digite 'n'.\n";
        App::messages[3] = "Informe o nome da aplicação.\n";
        App::messages[4] = "\nHouve um erro na instalação do programa, tente reinserí-lo.\nPara cancelar digite 'n'.\n";
    }

    void App::ppa(string ppaText = "")
    {
        bool result;
        vector<string> ppa;
        string choice;

        if (ppaText.empty()) {
            cout << App::messages[1];
            cin >> ppaText;
        }

        ppa.push_back(ppaText);

        result = App::addRepositories(ppa);

        if (result) {
            App::install();
        } else {
            cout << App::messages[2];
            cin >> choice;

            if (choice.find('n') == string::npos) {
                App::ppa(choice);
            } else {
                App::install();
            }
        }
    }

	void App::install()
    {
        bool result;
        string choice;
        string nameText;
        vector<string> name;

        cout << App::messages[3];
        cin >> nameText;

        name.push_back(nameText);

        result = App::installPackages(name);

        cout << result;

        if (!result) {
            cout << App::messages[4];
            getline(cin, choice);

            if (choice.find('n') != string::npos) {
                App::install();
            }
        }
	}

	int App::installation()
    {
        string choice;

		cout << App::messages[0];
		cin >> choice;

		if (choice.find('s') != string::npos) {
			App::ppa();
		} else {
		    App::install();
        }

		return 0;
	}
}
