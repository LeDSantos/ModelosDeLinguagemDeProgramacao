// Exemplo de uso de containers (coleções abstratas) em C++
// Containers são criados usando polimorfismo paramétrico
// compilar com -std=c++11
#include <iostream>
#include <vector> // em C++11 há o tipo array - experimente e descubra a diferença!
#define SIZE 10


#include <ctime>
#include <string>
#include <iostream>
using namespace std;

class Pessoa{
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

        std::string toString();

    private:
        time_t dtnascimento;
        std::string nome;
        Sexo sexo;
};

Pessoa::Pessoa() : Pessoa("Indefinido", INDEFINIDO, time(0)){
    cout << "Construtor Pessoa() chamado"<< endl;
}

Pessoa::Pessoa(std::string nome, Pessoa::Sexo sexo, time_t dtnascimento):
    nome(nome), sexo(sexo), dtnascimento(dtnascimento){
    cout << "Construtor alternativo de Pessoa chamado" << endl;
}

Pessoa::Pessoa(const Pessoa& outra):
    nome(outra.nome), dtnascimento(outra.dtnascimento), sexo(outra.sexo){
    cout << "Construtor de cópia chamado" << endl;
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
    cout << "Operator= chamado" << endl;
    return *this;
}

time_t Pessoa::get_dtnascimento() const{
    return this->dtnascimento;
}

void Pessoa::set_dtnascimento(time_t dtnascimento){
    this->dtnascimento = dtnascimento;
}

std::string Pessoa::get_nome() const{
    return this->nome;
}

void Pessoa::set_nome(std::string nome){
    this->nome = nome;
}

Pessoa::Sexo Pessoa::get_sexo() const{
    return this->sexo;
}
void Pessoa::set_sexo(Pessoa::Sexo sexo){
    this->sexo = sexo;
}
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

/*Depois, modifique o algoritmo anterior de maneira que ele use Pessoas ao invés de inteiros. Ao imprimir o conteúdo do vetor, use toString()para mostrar o que há dentro das pessoas(ou o operador ‘<<’sobrecarregado).*/

int main(){
    using namespace std;
    vector<Pessoa> vetor; // cria um vetor para armazenar números inteiros
    int i=0;
    // verifica tamanho atual (original)
    cout << "Tamanho do vetor = " << vetor.size() << endl;
    // coloca alguns numeros no vetor
    cout << "Inserindo alguns elementos..." << endl;
    for(i = 0; i < SIZE; i++){
        vetor.push_back(Pessoa("Ana Paula", Pessoa::FEMININO, time(0))); // adiciona no final do vetor
    }
    // verifica tamanho atual
    cout << "Tamanho do vetor = " << vetor.size() << endl;
    
    // mostrando elementos adicionados
    for(i = 0; i < SIZE; i++){
        cout << "vetor[" << i << "] = " << vetor[i].toString() << endl;
    }
    // usando iterador para acessar os elementos do vetor
    vector<Pessoa>::iterator elemento = vetor.begin();
    i=0;
    while( elemento != vetor.end()) {
        cout << " elemento " << i++ << " = " << elemento->toString() << endl;
        elemento++;
    }
    return 0;
}