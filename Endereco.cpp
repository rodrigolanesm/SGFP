#include "Endereco.h"

#include <iostream>
#include <string>

using namespace std;

Endereco::Endereco(){

}

Endereco::Endereco(string rua,
                   string numero,
                   string bairro,
                   string cidade,
                   string estado,
                   string cep)
{
    
}

//getters
string Endereco::getRua(){
    return rua;
}
string Endereco::getNumero(){
    return numero;
}
string Endereco::getBairro(){
    return bairro;
}
string Endereco::getCidade(){
    return cidade;
}
string Endereco::getEstado(){
    return estado;
}
string Endereco::getCep(){
    return cep;
}

//setters
void Endereco::setRua(string rua){
    this->rua = rua;
}
void Endereco::setNumero(string numero){
    this->numero = numero;
}
void Endereco::setBairro(string bairro){
    this->bairro = bairro;
}
void Endereco::setCidade(string cidade){
    this->cidade = cidade;
}
void Endereco::setEstado(string estado){
    this->estado = estado;
}
void Endereco::setCep(string cep){
    this->cep = cep;
}

void Endereco::exibirEndereco(){
    cout << "Rua: " << getRua() << endl;
    cout << "Numero: " << getNumero() << endl;
    cout << "Bairro: " << getBairro() << endl;
    cout << "Cidade: " << getCidade() << endl;
    cout << "Estado: " << getEstado() << endl;
    cout << "CEP: " << getCep() << endl;
}