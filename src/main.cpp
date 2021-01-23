#include <cstdlib>
#include <iostream>
#include <string.h>

#include "App.h"

using namespace std;

int main(int argc, char * argv[]) {
	App *app = new App();
    int option = 0;

    if (argc == 2 && strlen(argv[1]) == 1) {
        option = atoi(argv[1]);
    }

    app->menu(option);

    return 0;
}
