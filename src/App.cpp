#include "App.h"

namespace std {
    App::App()
    {
        messages[0] = "Deseja inserir um PPA para a aplicação (somente o nome do ppa. Ex.: dev/app, não ppa:dev/app)?[S\\n]\n";
        messages[1] = "\nDigite o PPA da aplicação.\n";
        messages[2] = "Erro no PPA. Verifique se está correto e reinsira-o.\nCasa deseja cancelar, digite 'n'.\n";
        messages[3] = "Informe o nome da aplicação.\n";
        messages[4] = "\nHouve um erro na instalação do programa, tente reinserí-lo.\nPara cancelar digite 'n'.\n";

        system = new Ubuntu;
    }

    void App::ppa(string ppaText = "")
    {
        bool result;
        vector<string> ppa;
        string choice;

        if (ppaText.empty()) {
            cout << messages[1];
            cin >> ppaText;
        }

        ppa.push_back(ppaText);

        result = system->addRepositories(ppa);

        if (result) {
            install();
        } else {
            cout << messages[2];
            cin >> choice;

            if (choice.find('n') == string::npos) {
                App::ppa(choice);
            } else {
                install();
            }
        }
    }

	void App::install()
    {
        bool result;
        string choice;
        string nameText;
        vector<string> name;

        cout << messages[3];
        cin >> nameText;

        name.push_back(nameText);

        result = system->installPackages(name);

        cout << result;

        if (!result) {
            cout << messages[4];
            getline(cin, choice);

            if (choice.find('n') != string::npos) {
                install();
            }
        }
	}

	int App::installation()
    {
        string choice;

		cout << messages[0];
		cin >> choice;

		if (choice.find('s') != string::npos) {
			ppa();
		} else {
		    install();
        }

		return 0;
	}

    int App::menu(int option)
    {
        if (option ==  0) {
            cout << "Escolha a opção:\n";
            cout << "1 - Atualizar sistema.\n";
            cout << "2 - Instalar um programa.\n";
            cout << "3 - Instalar programas pós-instalação de sistema.\n";
            cout << "4 - Criar projetos para programação.\n";
            cout << "5 - Sair.\n";

            cin >> option;
        }

        switch (option) {
            case 1:
                system->update();
                break;

            case 2:
                installation();
                menu(0);
                break;

            case 3:
                cout << "3";
                menu(0);
                break;

            case 4:
                cout << "4";
                menu(0);
                break;

            case 5:
                cout << "Sair...\n";
                return EXIT_SUCCESS;

            default:
                cout << "Escolha uma opção válida.\n";
                menu(0);
        }

        return 1;
    }
}
