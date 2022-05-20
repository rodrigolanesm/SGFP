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

Funcionario func;

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
        cout << "Instruções: Para sair, digite 0 e pressione ENTER" << endl << endl;
        cout << "Digite o código do funcionário: ";
        cin >> cod;
        cin.ignore();
        func.setCodigo(cod);

        //condição para sair do loop: o código de algum funcionário ser zero
        if(!cod)
        {
            system(CLEAR);
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
        //associar designação às classes existentes, completando as leituras dos dados necessários
        /* if(desig == "Operador" || desig == "operador" || desig == "OPERADOR")   //é necessário tratar a designação caso seja digitada com letras maiúsculas ou minúsculas
        {
            Operador operador;
            func = &operador;
        }
        else if(desig == "Gerente")
        {
            Gerente gerente;
            func = &gerente;
            gerente.lerDadosGerente();
        }
        else if(desig == "Diretor")
        {
            Diretor diretor;
            func = &diretor;
            diretor.lerDadosDiretor();
        }
        else if(desig == "Presidente")
        {
            Presidente presidente;
            func = &presidente;
            presidente.lerDadosPresidente();
        } */

        cout << "Digite o salário do funcionário: ";
        cin >> sal;
        cin.ignore();
        func.setSalario(sal);

        cout << endl << "Funcionário cadastrado com sucesso!" << endl;
        cout << endl << endl;
        funcionarios.push_back(func);
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
    
    cout << "Pressione qualquer tecla para continuar" << endl;
    getchar();
    getchar();
    system(CLEAR);
}

void alterarRegistroFuncionario()
{
    //variáveis auxiliares para a alteração de um funcionário
    int cod;
    string str;
    Endereco end;
    Data dt;
    double sal;

    //bool auxiliar
    bool novaAlteracao = false;
    do
    {
        //perguntar apenas se o usuário deseja fazer nova alteração
        if(novaAlteracao == false)
        {
            //leitura do código do funcionário a ser alterado
            cout << "Digite o código do funcionário cujo registro deve ser alterado: ";
            cin >> cod;
            cin.ignore();
        }

        //condição para alterar o funcionário: o código do funcionário a ser alterado ser igual ao código digitado pelo usuário
        for(int i = 0; i < funcionarios.size(); i++)
        {
            if(funcionarios[i].getCodigo() == cod)
            {
                int opcao;
                cout << "Digite a informação que deseja alterar: " << endl;
                cout << "\t1 - Nome" << endl;
                cout << "\t2 - Endereço" << endl;
                cout << "\t3 - Telefone" << endl;
                cout << "\t4 - Data de ingresso" << endl;
                cout << "\t5 - Designação" << endl;
                cout << "\t6 - Salário" << endl;
                cout << "\t0 - Sair" << endl;
                
                cin >> opcao;
                cin.ignore();

                switch(opcao)
                {
                    case 1:
                        cout << "Digite o novo nome: ";
                        getline(cin, str);
                        funcionarios[i].setNome(str);
                        break;
                    case 2:
                        end.lerEndereco();
                        funcionarios[i].setEndereco(end);
                        break;
                    case 3:
                        cout << "Digite o novo telefone: ";
                        getline(cin, str);
                        funcionarios[i].setTelefone(str);
                        break;
                    case 4:
                        dt.lerData();
                        funcionarios[i].setDataIngresso(dt);
                        break;
                    case 5:
                        cout << "Digite a nova designação: ";
                        getline(cin, str);
                        funcionarios[i].setDesignacao(str);
                        break;
                    case 6:
                        cout << "Digite o novo salário: ";
                        cin >> sal;
                        cin.ignore();
                        funcionarios[i].setSalario(sal);
                        break;
                    case 0:
                        return;
                    default:
                        cout << "Opção inválida!" << endl;
                        break;
                }   
            }
        cout << "Deseja fazer outra alteração nesse registro?" << endl;
        cout << "\t1 - Sim" << endl;
        cout << "\t0 - Não" << endl;
        novaAlteracao = false;
        cin >> novaAlteracao;
        system(CLEAR);
        }
    }while(novaAlteracao);
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
    
    cout << "Funcionário excluído com sucesso!" << endl;
    cout << "Pressione qualquer tecla para continuar" << endl;
    getchar();
    system(CLEAR);
}