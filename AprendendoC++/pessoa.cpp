#include "pessoa.hpp"
#include <stdlib.h>
#include <ctime>
#include <string>
#include <iostream>
//COM MUUUUUUUUUUUITOS ERROS
//using namespace std;
// Construtor
Pessoa::Pessoa(std::string nome, Sexo sexo, time_t dtnascimento):
	m_nome(nome),
	m_sexo(sexo),
	m_dtnascimento(dtnascimento){
	std::cout << "Construtor Pessoa() chamado" << std::endl;
}
// Construtor de cópia
Pessoa::Pessoa(const Pessoa& outra):
	m_nome(outra.get_nome()),
	m_dtnascimento(outra.get_dtnascimento()),
	m_sexo(outra.get_sexo()){
	std::cout <<"Construtor de cópia de Pessoa() chamado"<<std::endl;
}
	
// Operador de atribuição sobrecarregado para lidar com Pessoas
Pessoa& Pessoa::operator=(const Pessoa&outra){
	m_nome =outra.get_nome();
	m_dtnascimento =outra.get_dtnascimento();
	m_sexo =outra.get_sexo();
	std::cout <<"Operator=(Pessoa) chamado"<<std::endl;
	return *this;
}
// retorna a data de nascimento
const time_t Pessoa::get_dtnascimento() const{
	return m_dtnascimento;
}
// ajusta a data de nascimento
void Pessoa::set_dtnascimento(time_t dtnascimento){
	//TODO: verificar se data está correta
	m_dtnascimento =dtnascimento;
}
// retorna o nome
const std::string Pessoa::get_nome()const{
	return m_nome;
}
// ajusta o nome
void Pessoa::set_nome(std::string nome){
	//TODO: verificar se nome está correto
	m_nome =nome;
}
// Retorna o sexo da pessoa
const Pessoa::Sexo Pessoa::get_sexo()const{
	return m_sexo;
}
// Ajusta o sexo da pessoa
void Pessoa::set_sexo(Sexo sexo){
	//TODO: verificar se sexo está correto (se necessário)
	m_sexo =sexo;
}
// retorna uma string que representa a pessoa e seus atributos 
std::string Pessoa::toString(){
	time_t dtnascimento =m_dtnascimento;
	std::string tmp ="Pessoa{\n\tNome: ";
	std::string sexos[]={"Indefinido","Masculino","Feminino"};
	tmp.append(m_nome);
	tmp.append("\n\tSexo: ");
	tmp.append(sexos[m_sexo]);
	tmp.append("\n\tNascimento: ");
	tmp.append(ctime(&m_dtnascimento));
	tmp.append("}\n");
	return tmp;
}

// sobrecarga do operador << usado em cout
// Permite imprimir strings representativas para a enumeração Sexo
// Do contrário, imprimiria um número inteiro correspondente a cada valor de sexo 
std::ostream& operator<<(std::ostream& os,const Pessoa::Sexo s){
	switch(s){
		case Pessoa::INDEFINIDO : os << "INDEFINIDO"; break;
		case Pessoa::MASCULINO  : os << "MASCULINO"; break;
		case Pessoa::FEMININO   : os << "FEMININO"; break;
		default                 : os.setstate(std::ios_base::failbit);
	}
	return os;
}

void main(){
	std::cout << "TESTE" << std::endl;	
}