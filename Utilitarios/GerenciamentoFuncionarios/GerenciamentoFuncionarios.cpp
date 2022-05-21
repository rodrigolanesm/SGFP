#include "GerenciamentoFuncionarios.h"
#include "../../Menu/MainMenu.h"

#include <iostream>
#include <string>
#include <vector>

using namespace std;

GerenciamentoFuncionarios::GerenciamentoFuncionarios()
{ 

}

void GerenciamentoFuncionarios::cadastrarFuncionarios()
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

        //condição para sair do loop: o código de algum funcionário ser zero
        if(!cod)
        {
            system(CLEAR);
            break;
        }

        cout << endl;
        cout << "Digite o nome do funcionário: ";
        getline(cin, nome);

        cout << endl;
        end.lerEndereco();
        
        cout << endl << endl;
        cout << "Digite o telefone do funcionário: ";
        getline(cin, tel);

        cout << "\nSobre a data de ingresso do funcionário" << endl << endl;
        dtIngr.lerData();

        cout << endl;
        cout << "Digite a designação do funcionário: ";
        getline(cin, desig);

        /* //casting
        if(desig == "Operador")
        {
            (Operador*) func;
        }
        if (desig == "Gerente")
        {
            ((Gerente*) func)->lerDadosGerente();
        }
        if (desig == "Diretor")
        {
            ((Diretor*) func)->lerDadosDiretor();
        }
        if (desig == "Presidente")
        {
            ((Presidente*)func)->lerDadosPresidente();
        } */        

        cout << "Digite o salário do funcionário: ";
        cin >> sal;
        cin.ignore();

        cout << endl << "Funcionário cadastrado com sucesso!" << endl;
        cout << endl << endl;

        funcionarios.push_back(new Funcionario(cod, nome, end, tel, dtIngr, desig, sal));
    }
}

void GerenciamentoFuncionarios::listarFuncionarios()
{
    //exibir todos os funcionarios cadastrados
    for(int i = 0; i < funcionarios.size(); i++)
    {
        funcionarios[i]->exibirRegistroFuncionario();
        cout << endl;
    }
    
    cout << "Pressione qualquer tecla para continuar" << endl;
    getchar();
    getchar();
    system(CLEAR);
}

void GerenciamentoFuncionarios::listarFuncionariosTipo()
{
    //exibir todos os funcionarios cadastrados dependendo do tipo de funcionario especificado pelo usuario
    string tipoDesejado;

    cout << "Digite a designação de funcionário que deseja listar: ";
    cin.ignore();
    getline(cin, tipoDesejado);

    for(int i = 0; i < funcionarios.size(); i++)
    {
        if (funcionarios[i]->getDesignacao().find(tipoDesejado) != -1)
        {
            funcionarios[i]->exibirRegistroFuncionario();
            cout << endl;
        }
    }
    cout << "Pressione qualquer tecla para continuar" << endl;
    getchar();
    system(CLEAR);
}

void GerenciamentoFuncionarios::alterarRegistroFuncionario()
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
            if(funcionarios[i]->getCodigo() == cod)
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
                        funcionarios[i]->setNome(str);
                        break;
                    case 2:
                        end.lerEndereco();
                        funcionarios[i]->setEndereco(end);
                        break;
                    case 3:
                        cout << "Digite o novo telefone: ";
                        getline(cin, str);
                        funcionarios[i]->setTelefone(str);
                        break;
                    case 4:
                        dt.lerData();
                        funcionarios[i]->setDataIngresso(dt);
                        break;
                    case 5:
                        cout << "Digite a nova designação: ";
                        getline(cin, str);
                        funcionarios[i]->setDesignacao(str);
                        break;
                    case 6:
                        cout << "Digite o novo salário: ";
                        cin >> sal;
                        cin.ignore();
                        funcionarios[i]->setSalario(sal);
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

void GerenciamentoFuncionarios::excluirRegistroFuncionario()
{
    //excluir um funcionario, dado o seu código
    int cod;
    cout << "Digite o código do funcionário que deseja excluir: ";
    cin >> cod;
    cin.ignore();
    for(int i = 0; i < funcionarios.size(); i++)
    {
        if(funcionarios[i]->getCodigo() == cod)
        {
            funcionarios.erase(funcionarios.begin() + i);
        }
    }
    
    cout << "Funcionário excluído com sucesso!" << endl;
    cout << "Pressione qualquer tecla para continuar" << endl;
    getchar();
    system(CLEAR);
}

void GerenciamentoFuncionarios::exibirMenuBusca()
{
    cout << "Digite a opção de busca: " << endl;
    cout << "\t1 - Nome" << endl;
    cout << "\t2 - Endereço" << endl;
    cout << "\t3 - Data de ingresso" << endl;
    cout << "\t0 - Sair" << endl;
}

void GerenciamentoFuncionarios::buscarFuncionario()
{
    //buscar o registro de um funcionário dado parte de seu nome ou parte de seu endereço ou pelo intervalo de tempo que compreende a sua data de ingresso
    int opcao;
    do
    {
        exibirMenuBusca();
        
        cin >> opcao;
        cin.ignore();
        
        switch(opcao)
        {
            case 1:
                buscarFuncionarioNome();
                break;
            case 2:
                buscarFuncionarioEndereco();
                break;
            case 3:
                buscarFuncionarioDataIngresso();
                break;
            case 0:
                return;
            default:
                cout << "Opção inválida!" << endl;
                break;
        }
    }
    while (opcao);

    cout << "Pressione qualquer tecla para continuar" << endl;
    getchar();
    system(CLEAR);
}

void GerenciamentoFuncionarios::buscarFuncionarioNome()
{
    //buscar um funcionário dado parte de seu nome
    string nome;
    cout << "Digite um nome (ou parte do nome) do funcionário que deseja buscar: ";
    getline(cin, nome);

    for(int i = 0; i < funcionarios.size(); i++)
    {
        if(funcionarios[i]->getNome().find(nome) != -1)
        {
            funcionarios[i]->exibirRegistroFuncionario();
            cout << endl;
        }
    }
    cout << "Pressione qualquer tecla para continuar" << endl;
    getchar();
    system(CLEAR);
}

void GerenciamentoFuncionarios::buscarFuncionarioEndereco()
{
    //buscar um funcionário dado parte de seu endereço

    //endereco é a concatenação de todos os campos do endereço
    string endereco, enderecoDesejado;

    cout << "Digite um endereço (ou parte do endereço) do funcionário que deseja buscar: ";
    getline(cin, enderecoDesejado);

    for(int i = 0; i < funcionarios.size(); i++)
    {
        endereco = funcionarios[i]->getEndereco().getRua() + ", " + 
          (string) funcionarios[i]->getEndereco().getNumero() + ", " + 
                   funcionarios[i]->getEndereco().getBairro() + ", " + 
                   funcionarios[i]->getEndereco().getCidade() + ", " + 
                   funcionarios[i]->getEndereco().getEstado();
                   
        if(endereco.find(enderecoDesejado) != -1)
        {
            funcionarios[i]->exibirRegistroFuncionario();
            cout << endl;
        }
    }
    cout << "Pressione qualquer tecla para continuar" << endl;
    getchar();
    system(CLEAR);
}

void GerenciamentoFuncionarios::buscarFuncionarioDataIngresso()
{
    //buscar um funcionário dado o intervalo de tempo que compreende a sua data de ingresso
    Data dtInicio, dtFim;
    cout << "Digite a data de início do intervalo: " << endl;
    dtInicio.lerData();
    cout << "Digite a data de fim do intervalo: " << endl;
    dtFim.lerData();

    for(int i = 0; i < funcionarios.size(); i++)
    {
        if(funcionarios[i]->getDataIngresso().getDia() >= dtInicio.getDia() &&
            funcionarios[i]->getDataIngresso().getMes() >= dtInicio.getMes() &&
            funcionarios[i]->getDataIngresso().getAno() >= dtInicio.getAno() &&
            funcionarios[i]->getDataIngresso().getDia() <= dtFim.getDia() &&
            funcionarios[i]->getDataIngresso().getMes() <= dtFim.getMes() &&
            funcionarios[i]->getDataIngresso().getAno() <= dtFim.getAno())
        {
            funcionarios[i]->exibirRegistroFuncionario();
            cout << endl;
        }
    }
    cout << "Pressione qualquer tecla para continuar" << endl;
    getchar();
    system(CLEAR);
}