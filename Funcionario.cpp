#include "Funcionario.h"
#include "Endereco.h"
#include "Data.h"

#include <iostream>

using namespace std;

Funcionario::Funcionario(){

}

Funcionario::Funcionario(int codigo,
                        string nome,
                        Endereco endereco,
                        string telefone,
                        Data dataIngresso,
                        string designacao,
                        double salario){

}

void Funcionario::setCodigo(int codigo){
    this->codigo = codigo;
}
void Funcionario::setNome(string nome){
    this->nome = nome;
}
void Funcionario::setEndereco(Endereco endereco){
    this->endereco = endereco;
}
void Funcionario::setTelefone(string telefone){
    this->telefone = telefone;
}
void Funcionario::setDataIngresso(Data dataIngresso){
    this->dataIngresso = dataIngresso;
}
void Funcionario::setDesignacao(string designacao){
    this->designacao = designacao;
}
void Funcionario::setSalario(double salario){
    this->salario = salario;   
}

int Funcionario::getCodigo(){
    return codigo;
}
string Funcionario::getNome(){
    return nome;
}
Endereco Funcionario::getEndereco(){
    return endereco;
}
string Funcionario::getTelefone(){
    return telefone;
}
Data Funcionario::getDataIngresso(){
    return dataIngresso;
}
string Funcionario::getDesignacao(){
    return designacao;
}
double Funcionario::getSalario(){
    return salario;
}

void Funcionario::exibirRegistroFuncionario(){
    cout << "Codigo: " << codigo << endl;
    cout << "Nome: " << nome << endl;
    //cout << "Endereco: " << endereco.exibirEndereco() << endl;    //CORRIGIR ESSE ERRO
    cout << "Telefone: " << telefone << endl;
    cout << "Data de Ingresso: " << dataIngresso.getDia() << "/" << dataIngresso.getMes() << "/" << dataIngresso.getAno() << endl;
    cout << "Designacao: " << designacao << endl;
    cout << "Salario: " << salario << endl;
}
void Funcionario::excluirFuncionario(int codigo){

}