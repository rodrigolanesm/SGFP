#include "Menu/MainMenu.h"

#ifdef _WIN32
#define CLEAR "cls"
#else
#define CLEAR "clear"
#endif

#include <iostream>
#include <string>
#include <list>
#include <locale.h>

using namespace std;

int main(void)
{
    system (CLEAR);
    setlocale(LC_ALL, "pt_BR.UTF-8");

    //abre o menu principal
    MainMenu menu;
    
    menu.escolherOpcaoMenu();

    return 0;
}