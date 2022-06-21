#include "Endereco.h"

#include <iostream>
#include <string>

using namespace std;

// construtor

Endereco::Endereco()
{

}

Endereco::~Endereco()
{

}

Endereco::Endereco(string rua, string numero, string bairro, string cidade, string estado, string cep)
{
    this->rua = rua;
    this->numero = numero;
    this->bairro = bairro;
    this->cidade = cidade;
    this->estado = estado;
    this->cep = cep;
}
//getters

string Endereco::getRua()
{
    return this->rua;
}

string Endereco::getNumero()
{
    return this->numero;
}

string Endereco::getBairro()
{
    return this->bairro;
}

string Endereco::getCidade()
{
    return this->cidade;
}

string Endereco::getEstado()
{
    return this->estado;
}

string Endereco::getCep()
{
    return this->cep;
}

//setters

void Endereco::setRua(string rua)
{
    this->rua = rua;
}

void Endereco::setNumero(string numero)
{
    this->numero = numero;
}

void Endereco::setBairro(string bairro)
{
    this->bairro = bairro;
}

void Endereco::setCidade(string cidade)
{
    this->cidade = cidade;
}

void Endereco::setEstado(string estado)
{
    this->estado = estado;
}

void Endereco::setCep(string cep)
{
    this->cep = cep;
}

// leitura do endereço

void Endereco::lerEndereco()
{
    cout << "Sobre o endereço" << endl;
    cout << "\tInforme a rua: ";
    getline(cin, rua);

    cout << "\tInforme o numero: ";
    getline(cin, numero);

    cout << "\tInforme o bairro: ";
    getline(cin, bairro);

    cout << "\tInforme a cidade: ";
    getline(cin, cidade);

    cout << "\tInforme o estado: ";
    getline(cin, estado);

    cout << "\tInforme o CEP: ";
    getline(cin, cep);
}

// print do endereço

void Endereco::exibirEndereco()
{
    cout << endl;
    cout << "\tRua: " << getRua() << endl;
    cout << "\tNumero: " << getNumero() << endl;
    cout << "\tBairro: " << getBairro() << endl;
    cout << "\tCidade: " << getCidade() << endl;
    cout << "\tEstado: " << getEstado() << endl;
    cout << "\tCEP: " << getCep() << endl;
}