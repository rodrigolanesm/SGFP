#pragma once

#include "../../GerenciamentoFuncionarios/Data/Data.h"
#include "../../GerenciamentoFuncionarios/Endereco/Endereco.h"

#include "../../Funcionarios/Funcionario/Funcionario.h"
#include "../../Funcionarios/Operador/Operador.h"
#include "../../Funcionarios/Gerente/Gerente.h"
#include "../../Funcionarios/Diretor/Diretor.h"
#include "../../Funcionarios/Presidente/Presidente.h"

#include <iostream>
#include <string>
#include <vector>
#include <list>

using namespace std;

//lista de funcionarios
vector <Funcionario> funcionarios;

//utilizando alocação dinâmica
Funcionario *func;

void cadastrarFuncionarios()
{

    //variáveis auxiliares para a criação de um funcionário
    int cod;
    string nome;
    Endereco end;
    string tel;
    Data dtIngr;
    string desig;
    double sal;

    //criação de vários funcionários
    while(1)
    {
        //leitura dos dados do funcionário
        cout << "Cadastro de Funcionário" << endl;
        cout << "Instruções: Para sair, digite 0 e pressione ENTER" << endl;
        cout << "Digite o código do funcionário: ";
        cin >> cod;
        cin.ignore();
        func->setCodigo(cod);

        //condição para sair do loop: o código de algum funcionário ser zero
        if(!cod)
        {
            break;
        }

        cout << endl;
        cout << "Digite o nome do funcionário: ";
        getline(cin, nome);
        func->setNome(nome);

        cout << endl;

        end.lerEndereco();
        func->setEndereco(end);
        
        cout << endl << endl;
        cout << "Digite o telefone do funcionário: ";
        getline(cin, tel);
        func->setTelefone(tel);

        cout << "\nSobre a data de ingresso do funcionário" << endl << endl;
        dtIngr.lerData();
        func->setDataIngresso(dtIngr);

        cout << endl;
        cout << "Digite a designação do funcionário: ";
        getline(cin, desig);
        func->setDesignacao(desig);

        //associar designação às classes existentes, completando as leituras dos dados necessários
        if(desig == "Operador")
        {
            func = new Operador();
        }
        else if(desig == "Gerente")
        {
            func = new Gerente();
        }
        else if(desig == "Diretor")
        {
            func = new Diretor();
        }
        else if(desig == "Presidente")
        {
            func = new Presidente();
        }

        cout << "Digite o salário do funcionário: ";
        cin >> sal;
        cin.ignore();
        func->setSalario(sal);

        cout << endl << "Funcionário cadastrado com sucesso!" << endl;
        cout << endl << endl;
        funcionarios.push_back(*func);
    }
}

void listarFuncionarios()
{
    //exibir todos os funcionarios cadastrados
    for(int i = 0; i < funcionarios.size(); i++)
    {
        cout << "Código: " << funcionarios[i].getCodigo() << " - "
             << "Nome: " << funcionarios[i].getNome() << " - "
             << "Designação: " << funcionarios[i].getDesignacao() << endl;
        cout << endl;
    }
}

void alterarRegistroFuncionario()
{
    //variáveis auxiliares para a alteração de um funcionário
    int cod;
    string nome;
    Endereco end;
    string tel;
    Data dtIngr;
    string desig;
    double sal;

    do
    {
        //leitura do código do funcionário a ser alterado
        cout << "Digite o código do funcionário: ";
        cin >> cod;
        cin.ignore();

        //condição para sair do loop: o código de algum funcionário ser zero
        if(!cod)
        {
            cout << "Código inválido!" << endl;
        }
    } while (cod != 0); 
    

    //condição para alterar o funcionário: o código do funcionário a ser alterado ser igual ao código digitado pelo usuário
    for(int i = 0; i < funcionarios.size(); i++)
    {
        if(funcionarios[i].getCodigo() == cod)
        {
            //leitura dos dados do funcionário
            cout << "Digite o nome do funcionário: ";
            getline(cin, nome);
            funcionarios[i].setNome(nome);

            cout << endl;

            end.lerEndereco();
            funcionarios[i].setEndereco(end);
            
            cout << endl << endl;
            cout << "Digite o telefone do funcionário: ";
            getline(cin, tel);
            funcionarios[i].setTelefone(tel);

            cout << "\nSobre a data de ingresso do funcionário" << endl << endl;
            dtIngr.lerData();
            funcionarios[i].setDataIngresso(dtIngr);

            cout << endl;
            cout << "Digite a designação do funcionário: ";
            getline(cin, desig);
            funcionarios[i].setDesignacao(desig);

            cout << "Digite o salário do funcionário: ";
            cin >> sal;
            cin.ignore();
            funcionarios[i].setSalario(sal);

            cout << "Registro alterado com sucesso!" << endl << endl;
            return;
        }
    }
}

void excluirRegistroFuncionario()
{
    //excluir um funcionario, dado o seu código
    int cod;
    cout << "Digite o código do funcionário que deseja excluir: ";
    cin >> cod;
    cin.ignore();
    for(int i = 0; i < funcionarios.size(); i++)
    {
        if(funcionarios[i].getCodigo() == cod)
        {
            funcionarios.erase(funcionarios.begin() + i);
        }
    }
        
}