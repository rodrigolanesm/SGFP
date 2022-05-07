#include "Data.h"
#include "Endereco.h"
#include "Funcionario.h"
#include "Operador.h"
#include "Gerente.h"
#include "Diretor.h"
#include "Presidente.h"

#define CLEAR "cls"

#include <iostream>
#include <string>
#include <list>
#include <locale.h>


using namespace std;

int main(){
    system (CLEAR);
    setlocale(LC_ALL, "pt_BR.UTF-8");

    //lista de funcionarios
    list <Funcionario> funcionarios;
	//list <Funcionario>::iterator it;

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

    for(Funcionario func : funcionarios)
    {
        cout << endl << endl;
        func.exibirRegistroFuncionario();
    }


    return 0;
}