#pragma once

#include <iostream>

using namespace std;

class Endereco
{
public:
    Endereco();
    Endereco(string rua,
             string numero,
             string bairro,
             string cidade,
             string estado,
             string cep);

    string toString(int num);

    //getters
    string getRua();
    string getNumero();
    string getBairro();
    string getCidade();
    string getEstado();
    string getCep();

    //setters
    void setRua(string rua);
    void setNumero(string numero);
    void setBairro(string bairro);
    void setCidade(string cidade);
    void setEstado(string estado);
    void setCep(string cep);

    //método para exibir o endereco
    void exibirEndereco();

private:
    string rua;
    string numero;
    string bairro;
    string cidade;
    string estado;
    string cep;
};