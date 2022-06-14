#include "MainMenu.h"

MainMenu::MainMenu()
{

}

void MainMenu::exibeMenu()
{
    cout << "1 - Cadastrar funcionário" << endl;
    cout << "2 - Cadastrar automaticamente o funcionário via arquivo" << endl;
    cout << "3 - Listar funcionários" << endl;
    cout << "4 - Listar funcionários por tipo" << endl;
    cout << "5 - Alterar registro de um funcionário" << endl;
    cout << "6 - Excluir registro de um funcionário" << endl;
    cout << "7 - Buscar funcionário" << endl;
    cout << "8 - Calcular folha salarial" << endl;
    cout << "9 - Calcular folha salarial de um funcionário" << endl;
    cout << "10 - Calcular folha salarial da empresa" << endl;
    cout << "11 - Conceder aumento salarial para os funcionários" << endl;
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
        cin.ignore();
        system(CLEAR);
        switch (opcao)      // exceção
        {
        case 1:
            gf.cadastrarFuncionarios();
            break;
        case 2:
            gf.lerArquivoCadastroFuncionario();
            break;
        case 3:
            gf.listarFuncionarios();
            break;
        case 4:
            gf.listarFuncionariosTipo();
            break;    
        case 5:
            gf.alterarRegistroFuncionario();
            break;
        case 6:
            gf.excluirRegistroFuncionario();
            break;
        case 7:
            gf.buscarFuncionario();
            break;
        case 8:
            gf.calcularFolhaSalarial();
            break;
        case 9:
            gf.calcularFolhaSalarialFuncionario();
            break;  
        case 10:
            gf.imprimirFolhaSalarialEmpresa();
            break;
        case 11:
            gf.concederAumentoSalarial();
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