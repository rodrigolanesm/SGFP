#include "../GerenciamentoFuncionarios/Data/Data.h"
#include "../GerenciamentoFuncionarios/Endereco/Endereco.h"
#include "../GerenciamentoFuncionarios/GerenciamentoFuncionario/GerenciamentoFuncionarios.h"

#include "../Funcionarios/Funcionario/Funcionario.h"
#include "../Funcionarios/Operador/Operador.h"
#include "../Funcionarios/Gerente/Gerente.h"
#include "../Funcionarios/Diretor/Diretor.h"
#include "../Funcionarios/Presidente/Presidente.h"

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
        switch (opcao)
        {
        case 1:
            cadastrarFuncionario();
            break;
        case 2:
            /* code */
            break;
        case 3:
            /* code */
            break;
        case 4:
            /* code */
            break;
        case 5:
            return;
            break;
        default:
            cout << "Opção inválida" << endl;
        }

    }
    while(opcao != 5);
    
}
