// Exemplo de uso de containers (coleções abstratas) em C++
// Containers são criados usando polimorfismo paramétrico
// compilar com -std=c++11
#include <iostream>
#include <vector> // em C++11 há o tipo array - experimente e descubra a diferença!
#define SIZE 5
#define _DEBUG 0//1//<<<<<<<<<---------------------

#include <cstdlib>
#include <ctime>
#include <string>
#include <iostream>
#include <string.h>
using namespace std;

template <class E>
class Comparable{
    private:        
    public:
        int compares_to(E outro);
};

class Pessoa: virtual public Comparable<Pessoa>{
    public:
        enum Sexo { INDEFINIDO, MASCULINO, FEMININO };
        Pessoa(); // Construtor padrão
        Pessoa(std::string, Sexo, time_t); // Construtor alternativo
        Pessoa(const Pessoa& outra); // // construtor de cópia

        Pessoa& operator=(const Pessoa& outra);
        time_t get_dtnascimento() const;
        void set_dtnascimento(time_t dtnascimento);

        std::string get_nome() const;
        void set_nome(std::string nome);

        Sexo get_sexo() const;
        void set_sexo(Sexo sexo);

        virtual std::string toString();////////////AQUI
        int compares_to(Pessoa outro);

    private:
        time_t dtnascimento;
        std::string nome;
        Sexo sexo;
};

Pessoa::Pessoa():
    Pessoa("Indefinido", INDEFINIDO, time(0)){
        if(_DEBUG) cout << "Construtor Pessoa() chamado"<< endl;
    }

Pessoa::Pessoa(std::string nome, Pessoa::Sexo sexo, time_t dtnascimento):
    nome(nome), sexo(sexo), dtnascimento(dtnascimento){
        if(_DEBUG) cout << "Construtor alternativo de Pessoa chamado" << endl;
    }

Pessoa::Pessoa(const Pessoa& outra):
    nome(outra.nome), dtnascimento(outra.dtnascimento), sexo(outra.sexo){
        if(_DEBUG) cout << "Construtor de cópia chamado" << endl;
        // este eh soh um exemplo e pode nao funcionar como esperado
        // substitua pelo seu codigo
    }
// Operador de atribuição sobrecarregado para receber uma pessoa

Pessoa& Pessoa::operator=(const Pessoa& outra){
    // este eh soh um exemplo e pode nao funcionar como esperado
    // substitua pelo seu codigo
    this->nome = outra.nome;
    this->dtnascimento = outra.dtnascimento;
    this->sexo = outra.sexo;
    if(_DEBUG) cout << "Operator= chamado" << endl;
    return *this;
}

time_t Pessoa::get_dtnascimento() const             { return this->dtnascimento; }
void Pessoa::set_dtnascimento(time_t dtnascimento)  { this->dtnascimento = dtnascimento; }

std::string Pessoa::get_nome() const    { return this->nome; }
void Pessoa::set_nome(std::string nome) { this->nome = nome; }

Pessoa::Sexo Pessoa::get_sexo() const   { return this->sexo; }
void Pessoa::set_sexo(Pessoa::Sexo sexo){ this->sexo = sexo; }

std::string Pessoa::toString(){
    time_t dtnascimento = this->get_dtnascimento();
    std::string tmp = "Pessoa{\n\tNome: ";
    std::string sexos[] = { "Indefinido", "Masculino", "Feminino" };
    tmp.append(this->get_nome());
    tmp.append("\n\tSexo: ");
    tmp.append(sexos[this->get_sexo()]);
    tmp.append("\n\tNascimento: ");
    tmp.append(ctime(&dtnascimento));
    tmp.append("}\n");
    return tmp;
}

int Pessoa::compares_to(Pessoa outro){
    if(_DEBUG) cout << this->get_nome() << " com " << outro.get_nome() << endl;

    if(!this->get_nome().compare(outro.get_nome()) &&
        this->get_dtnascimento() == outro.get_dtnascimento() &&
        this->get_sexo() == outro.get_sexo()){

        if(_DEBUG) cout << "Pessoas iguais" << endl;
        return 0;
    }else{
        if(this->get_dtnascimento() < outro.get_dtnascimento()){
            if(_DEBUG) cout << "Veio antes" << endl;
            return -1;
        }else{
            if(_DEBUG) cout << "Veio depois" << endl;
            return 1;
        }
    }    
}

// sobrecarga do operador << usado em cout
// Permite imprimir strings representativas para a enumeração Sexo
// Do contrário, imprimiria um número inteiro correspondente a cada valor de sexo
std::ostream& operator<<(std::ostream& os, Pessoa::Sexo s){
    switch(s) {
        case Pessoa::INDEFINIDO : os << "INDEFINIDO"; break;
        case Pessoa::MASCULINO : os << "MASCULINO"; break;
        case Pessoa::FEMININO : os << "FEMININO"; break;
        default : os.setstate(std::ios_base::failbit);
    }
return os;
}

/*Exercício 4:juntando tudo...
Elabore uma classe abstrata (ou interface) denominada Comparable, a qual usa polimorfismo paramétrico para oferecer um método de comparação de elementos.Essa classe/interface possui somente um método denominado compares_to(), o qual possui a seguinte assinatura: int compares_to(<E>), onde <E> é o parâmetro de tipo.
Depois,modifique a classe Pessoa de maneira a herdar dessa classe abstrata (ou interface) o método compares_to(). Implemente-o de maneira a comparar duas pessoas(por exemplo, usando o nome da pessoa como base).O que o método faz é receber uma pessoa e compará-la com a instância atual. Caso as duas pessoas sejam iguais, deve retornar o valor 0. Se a pessoa atual vier antes da sendo comparada(i.e., passada como parâmetro),deve retornar um valor menor do que zero. Se a pessoa atual vier depois da que está sendo comparada, deve retornar um valor maior do que zero.Em seguida,elabore uma função sort() genérica(i.e., que usa polimorfismo paramétrico)para ordenar um container ou coleção qualquer de elementos compatíveis com a classe Comparable.Para funcionar, a função sort deve usar o método compare_to() dos elementos presentes na coleção.Finalmente,façaum programa que cria uma coleção de pessoas e usa a função sort (genérica) para ordenar as pessoas.O programa deve mostrar o resultado do container ordenado na tela*/

template <class T>
vector<T> sort(vector<T> lista){
    vector<T> lista_ordenada=lista;
    Pessoa aux;
    int i,j;
    Pessoa menor;
    for(i = 0; i < SIZE-1; lista_ordenada[i]=menor, i++){             
        for(menor=lista_ordenada[i], j = i+1; j < SIZE; j++){
            if(menor.compares_to(lista_ordenada[j])>0){
                aux=menor;
                menor=lista_ordenada[j];
                lista_ordenada[j]=aux;
            }            
        }        
    }
    return lista_ordenada;
}

int main(void){
    vector<Pessoa> vetor; // cria um vetor
    int i=0;

    cout << "Tamanho do vetor = " << vetor.size() << endl;

    cout << "Inserindo alguns elementos..." << endl;
    string nome=" aleluia";
    for(i = 0; i < SIZE; i++){
        nome[0]=rand()%20+65;
        vetor.push_back(Pessoa(nome, Pessoa::FEMININO, rand()%20)); // adiciona no final do vetor
        cout << "vetor[" << i << "] = " << vetor[i].toString() << endl;
    }

    cout << "Tamanho do vetor = " << vetor.size() << endl;
        
    cout << "VETOR ORDENADO" << endl;
    // sort == ordenamento
    vector<Pessoa> vetorORDENADO=sort(vetor);

    // mostrando elementos após ordenamento
    for(i = 0; i < SIZE; i++){
        cout << "vetor[" << i << "] = " << vetorORDENADO[i].toString() << endl;
    }
    
    if(_DEBUG) cout << "FIM" << endl;

    return 0;
}