#pragma once

#ifdef _WIN32
#define CLEAR "cls"
#else
#define CLEAR "clear"
#endif

#include "../GerenciamentoFuncionarios/GerenciamentoFuncionario/GerenciamentoFuncionarios.h"

#include <iostream>
#include <string>
#include <list>

using namespace std;

void exibeMenu()
{
    cout << "1 - Cadastrar funcionário" << endl;
    cout << "2 - Listar funcionários" << endl;
    cout << "3 - Alterar registro de um funcionário" << endl;
    cout << "4 - Excluir registro de um funcionário" << endl;
    cout << "5 - Sair" << endl;
}

void escolherOpcaoMenu()
{
    int opcao;
    do
    {   
        exibeMenu();
        cout << endl << "Selecione uma opção: ";
        cin >> opcao;
        system(CLEAR);
        switch (opcao)
        {
        case 1:
            cadastrarFuncionarios();
            break;
        case 2:
            listarFuncionarios();
            break;
        case 3:
            alterarRegistroFuncionario();
            break;
        case 4:
            excluirRegistroFuncionario();
            break;
        case 5:
            return;
            break;
        default:
            cout << "Opção inválida" << endl;
            break;
        }
    }
    while(opcao != 5);
}

