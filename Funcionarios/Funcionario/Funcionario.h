#pragma once

#include <iostream>

#include "../../Utilitarios/Endereco/Endereco.h"
#include "../../Utilitarios/Data/Data.h"

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
    virtual void setCodigo(int codigo);
    virtual void setNome(string nome);
    virtual void setEndereco(Endereco endereco);
    virtual void setTelefone(string telefone);
    virtual void setDataIngresso(Data dataIngresso);
    virtual void setDesignacao(string designacao);
    virtual void setSalario(double salario);

    //getters da classe Funcionario
    virtual int getCodigo();
    virtual string getNome();
    virtual Endereco getEndereco();
    virtual string getTelefone();
    virtual Data getDataIngresso();
    virtual string getDesignacao();
    virtual double getSalario();

    //metodos da classe Funcionario
    virtual void exibirRegistroFuncionario();
    virtual void excluirFuncionario(int codigo);

protected:
    int codigo;
    string nome;
    Endereco endereco;
    string telefone;
    Data dataIngresso;
    string designacao;
    double salario;
};
