#include "MainMenu.h"

MainMenu::MainMenu()
{

}

void MainMenu::exibeMenu()
{
    cout << "1 - Cadastrar funcionário" << endl;
    cout << "2 - Listar funcionários" << endl;
    cout << "3 - Listar funcionários por tipo" << endl;
    cout << "4 - Alterar registro de um funcionário" << endl;
    cout << "5 - Excluir registro de um funcionário" << endl;
    cout << "6 - Buscar funcionário" << endl;
    cout << "0 - Sair" << endl;
}

void MainMenu::escolherOpcaoMenu()
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
            gf.cadastrarFuncionarios();
            break;
        case 2:
            gf.listarFuncionarios();
            break;
        case 3:
            gf.listarFuncionariosTipo();
            break;    
        case 4:
            gf.alterarRegistroFuncionario();
            break;
        case 5:
            gf.excluirRegistroFuncionario();
            break;
        case 6:
            gf.buscarFuncionario();
            break;
        case 0:
            return;
            break;
        default:
            cout << "Opção inválida" << endl;
            break;
        }
    }
    while(opcao); // != 0
}