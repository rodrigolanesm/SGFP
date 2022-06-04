#pragma once

#include <iostream>
#include <fstream>

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
    virtual void setHorasNormais(int horasNormais);
    virtual void setHorasExtras(int horasExtras);

    //getters da classe Funcionario
    virtual int getCodigo();
    virtual string getNome();
    virtual Endereco getEndereco();
    virtual string getTelefone();
    virtual Data getDataIngresso();
    virtual string getDesignacao();
    virtual double getSalario();
    virtual int getHorasNormais();
    virtual int getHorasExtras();


    //metodos da classe Funcionario
    virtual void exibirRegistroFuncionario();
    double   calcularSalarioMensal();

    double descontosImpostoRenda();
    double descontosPrevidenciaSocial();

protected:
    int codigo;
    string nome;
    Endereco endereco;
    string telefone;
    Data dataIngresso;
    string designacao;
    double salario;

    int horasNormais;
    int horasExtras;
};