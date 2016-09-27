#include <cstdlib>
#include <iostream>

using namespace std;

int menu() {
    char option;

    cout << "Escolha a opção:\n";
    cout << "1 - Atualizar sistema.\n";
    cout << "2 - Instalar um programa.\n";
    cout << "3 - Instalar programas pós-instalação de sistema.\n";
    cout << "4 - Criar projetos para programação.\n";
    cout << "5 - Sair.\n";

    cin >> option;

    switch (option) {
        case '1':
            cout << "1";
            menu();
            break;

        case '2':
            cout << "2";
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
            return EXIT_SUCCESS;

        default:
            cout << "Escolha uma opção válida.\n";
            menu();
    }

    return 0;
}

int main() {
    menu();

    return 0;
}
