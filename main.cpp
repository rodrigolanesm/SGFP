#include "MainMenu/MainMenu.h"

#define CLEAR "cls"

#include <iostream>
#include <string>
#include <list>
#include <locale.h>

using namespace std;

int main(void)
{
    system (CLEAR);
    setlocale(LC_ALL, "pt_BR.UTF-8");

    //exibir menu
    exibeMenu();
    escolherOpcaoMenu();

    return 0;
}