#pragma once

#ifdef _WIN32
#define CLEAR "cls"
#else
#define CLEAR "clear"
#endif

#include "../Utilitarios/GerenciamentoFuncionarios/GerenciamentoFuncionarios.h"
#include "../Utilitarios/Salarios/Salarios.h"

#include <iostream>
#include <string>
#include <list>

using namespace std;

class MainMenu
{
public:
    MainMenu();

    void exibeMenu();
    void escolherOpcaoMenu();

    GerenciamentoFuncionarios gf;
    Salarios slr;
};