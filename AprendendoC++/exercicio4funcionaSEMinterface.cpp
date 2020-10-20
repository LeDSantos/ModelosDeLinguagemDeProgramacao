// Exemplo de uso de containers (coleções abstratas) em C++
// Containers são criados usando polimorfismo paramétrico
// compilar com -std=c++11
#include <iostream>
#include <vector> // em C++11 há o tipo array - experimente e descubra a diferença!
#define SIZE 5

#include <cstdlib>
#include <ctime>
#include <string>
#include <iostream>
#include <string.h>
using namespace std;

/*class Comparable{
    private:
        
    public:
        virtual int compares_to(Pessoa p2)=0;
};*/

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

        virtual std::string toString();////////////AQUI
        //virtual int compares_to(Pessoa p2); 
        virtual int compares_to(Pessoa p2);

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
//int Pessoa::compares_to(){
//    return 49;
//}
int Pessoa::compares_to(Pessoa p2){
        cout << this->get_nome() << endl;
        cout << p2.get_nome() << endl;
    if(!this->get_nome().compare(p2.get_nome())){ //!strcmp(x.get_nome().data(), p2.get_nome().data())){
        cout << "Nomes iguais" << endl;
        return 0;
    }else{
        if(this->get_dtnascimento() < p2.get_dtnascimento()){
            cout << "Veio antes" << endl;
            return -1;
        }else{
            cout << "Veio depois" << endl;
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

vector<Pessoa> ordemamento(vector<Pessoa> lista){
    vector<Pessoa> lista_ordenada=lista;
    Pessoa aux;
    int i,j;
    Pessoa menor=lista_ordenada[0];
    for(i = 0; i < SIZE-1; i++){   
        menor=lista_ordenada[i];     
        for( j = i+1; j < SIZE; j++){
            if(menor.compares_to(lista_ordenada[j])>0){
                aux=menor;
                menor=lista_ordenada[j];
                lista_ordenada[j]=aux;
            }            
        }
        lista_ordenada[i]=menor;
        //cout << menor.x->toString() << endl;
    }

    return lista_ordenada;
}

int main(){
    //using namespace std;
    vector<Pessoa> vetor; // cria um vetor para armazenar números inteiros
    int i=0;
    // verifica tamanho atual (original)
    cout << "Tamanho do vetor = " << vetor.size() << endl;
    // coloca alguns numeros no vetor
    cout << "Inserindo alguns elementos..." << endl;
    string nome="anaaa";
    for(i = 0; i < SIZE; i++){
        nome[1]=rand()%20+65;
        vetor.push_back(Pessoa(nome, Pessoa::FEMININO, rand()%20)); // adiciona no final do vetor
        cout << "vetor[" << i << "] = " << vetor[i].toString() << endl;
    }
    // verifica tamanho atual
    cout << "Tamanho do vetor = " << vetor.size() << endl;
    
    // usando iterador para acessar os elementos do vetor
    vector<Pessoa> vetorORDENADO=ordemamento(vetor);
//return 0;
    // mostrando elementos adicionados
    for(i = 0; i < SIZE; i++){
        cout << "vetor[" << i << "] = " << vetorORDENADO[i].toString() << endl;
    }
    return 0;
}