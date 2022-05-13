#pragma once

#include <iostream>

#include "../../GerenciamentoFuncionarios/Endereco/Endereco.h"
#include "../../GerenciamentoFuncionarios/Data/Data.h"

using namespace std;

class Funcionario
{
public:
    Funcionario();
    Funcionario(int codigo,
                string nome,
                Endereco endereco,
                string telefone,
                Data dataIngresso,
                string designacao,
                double salario);

    //setters da classe Funcionario
    void setCodigo(int codigo);
    void setNome(string nome);
    void setEndereco(Endereco endereco);
    void setTelefone(string telefone);
    void setDataIngresso(Data dataIngresso);
    void setDesignacao(string designacao);
    void setSalario(double salario);

    //getters da classe Funcionario
    int getCodigo();
    string getNome();
    Endereco getEndereco();
    string getTelefone();
    Data getDataIngresso();
    string getDesignacao();
    double getSalario();

    //metodos da classe Funcionario
    void exibirRegistroFuncionario();
    void excluirFuncionario(int codigo);

private:
    int codigo;
    string nome;
    Endereco endereco;
    string telefone;
    Data dataIngresso;
    string designacao;
    double salario;
};
