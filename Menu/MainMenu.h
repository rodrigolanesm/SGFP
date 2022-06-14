#pragma once

#ifdef _WIN32
#define CLEAR "cls"
#include <Windows.h>
#else
#define CLEAR "clear"
#include <unistd.h>
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