#include <cstdlib>
#include <iostream>
#include <string.h>

#include "App.h"

using namespace std;

int menu(string option = "0") {
	App menuApp;

    if (option ==  "0") {
        cout << "Escolha a opção:\n";
        cout << "1 - Atualizar sistema.\n";
        cout << "2 - Instalar um programa.\n";
        cout << "3 - Instalar programas pós-instalação de sistema.\n";
        cout << "4 - Criar projetos para programação.\n";
        cout << "5 - Sair.\n";

        cin >> option;
    }

    switch (option[0]) {
        case '1':
            menuApp.update();
            break;

        case '2':
            menuApp.installation();
            menu();
            break;

        case '3':
            cout << "3";
            menu();
            break;

        case '4':
            cout << "4";
            menu();
            break;

        case '5':
            cout << "Sair...\n";
            return EXIT_SUCCESS;

        default:
            cout << "Escolha uma opção válida.\n";
            menu("0");
    }

    return 0;
}

int main(int argc, char * argv[]) {
    string menuOption = "0";

    if (argc == 2 && strlen(argv[1]) == 1) {
        menuOption.assign(argv[1]);
    }

    menu(menuOption);

    return 0;
}
