#include "../../GerenciamentoFuncionarios/Data/Data.h"
#include "../../GerenciamentoFuncionarios/Endereco/Endereco.h"
#include "../../MainMenu/MainMenu.h"

#include "../../Funcionarios/Funcionario/Funcionario.h"
#include "../../Funcionarios/Operador/Operador.h"
#include "../../Funcionarios/Gerente/Gerente.h"
#include "../../Funcionarios/Diretor/Diretor.h"
#include "../../Funcionarios/Presidente/Presidente.h"

#include <iostream>
#include <string>
#include <list>

using namespace std;

void cadastrarFuncionario()
{
    //lista de funcionarios
    vector <Funcionario> funcionarios;

    Funcionario func;

    //variáveis auxiliares para a criação de um funcionário
    int cod;
    string nome;
    Endereco end;
    string tel;
    Data dtIngr;
    string desig;
    double sal;

    //criação de vários funcionários até que o código de um deles seja igual a zero
    while(1)
    {
        //leitura dos dados do funcionário
        cout << "Digite o código do funcionário: ";
        cin >> cod;
        cin.ignore();
        func.setCodigo(cod);

        //condição para sair do loop: o código de algum funcionário ser zero
        if(!cod)
        {
            break;
        }

        cout << endl;
        cout << "Digite o nome do funcionário: ";
        getline(cin, nome);
        func.setNome(nome);

        cout << endl;

        end.lerEndereco();
        func.setEndereco(end);
        
        cout << endl << endl;
        cout << "Digite o telefone do funcionário: ";
        getline(cin, tel);
        func.setTelefone(tel);

        cout << "\nSobre a data de ingresso do funcionário" << endl << endl;
        dtIngr.lerData();
        func.setDataIngresso(dtIngr);

        cout << endl;
        cout << "Digite a designação do funcionário: ";
        getline(cin, desig);
        func.setDesignacao(desig);

        cout << "Digite o salário do funcionário: ";
        cin >> sal;
        func.setSalario(sal);

        cout << endl << endl;
        funcionarios.push_back(func);
    }
}

void listarFuncionarios()
{
    //exibir uma lista de funcionarios

    
}

void excluirFuncionarios()
{
    //excluir um funcionario
    int cod;
    cout << "Digite o código do funcionário que deseja excluir: ";
    cin >> cod;
    cin.ignore();

    
    
    
}