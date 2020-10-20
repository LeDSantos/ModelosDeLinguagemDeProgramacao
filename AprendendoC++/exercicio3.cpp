// Exemplo de uso de containers (coleções abstratas) em C++
// Containers são criados usando polimorfismo paramétrico
// compilar com -std=c++11
#include <iostream>
#include <vector> // em C++11 há o tipo array - experimente e descubra a diferença!
#define SIZE 10

#include <cstdlib>
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

        virtual std::string toString();////////////AQUI

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

class Aluno: public Pessoa{
    public:
        enum Nivel { INDEFINIDO, GRADUACAO, ESPECIALIZACAO, MESTRADO, DOUTORADO };
        Aluno();
        Aluno(std::string, Sexo, time_t, std::string, Nivel);
        Aluno(const Aluno& outro);
        Aluno& operator=(const Aluno& outro);
        const std::string get_codigo() const;
        void set_codigo(std::string codigo);
        const Nivel get_nivel() const;
        void set_nivel(Nivel nivel);
        virtual std::string toString();////////////AQUI
    private:
        std::string codigo;
        Nivel nivel;
};
Aluno::Aluno() : codigo("INDEFINIDO"), nivel(Aluno::INDEFINIDO){
    cout << "Construtor Aluno() chamado"<< endl;
}
Aluno::Aluno(const Aluno& outro){set_nome(outro.get_nome());
    set_dtnascimento(outro.get_dtnascimento());
    set_sexo(outro.get_sexo());
    set_codigo(outro.get_codigo());
    set_nivel(outro.get_nivel());
    cout << "Construtor de cópia de Aluno chamado" << endl;
}
Aluno::Aluno(std::string nome, Sexo sexo, time_t dtnascimento, std::string codigo, Nivel nivel){
    this->set_nome(nome);
    this->set_sexo(sexo);
    this->set_dtnascimento(dtnascimento);
    this->set_codigo(codigo);
    this->set_nivel(nivel);
    cout << "Construtor Alternativo Aluno() chamado"<< endl;
}
// Operador de atribuição sobrecarregado para receber uma pessoa
Aluno& Aluno::operator=(const Aluno& outro){
    set_nome(outro.get_nome());
    set_dtnascimento(outro.get_dtnascimento());
    set_sexo(outro.get_sexo());
    this->codigo = outro.get_codigo();
    this->nivel = outro.get_nivel();
    cout << "Operator=(Aluno) chamado" << endl;
    return *this;
}
const std::string Aluno::get_codigo() const{
    return this->codigo;
}
void Aluno::set_codigo(std::string codigo){
    this->codigo = codigo;
}
const Aluno::Nivel Aluno::get_nivel() const{
    return this->nivel;
}
void Aluno::set_nivel(Nivel nivel){
this->nivel = nivel;
}
    std::string Aluno::toString(){
    time_t dtnascimento = this->get_dtnascimento();
    std::string tmp = "Aluno{\n\tNome: ";
    std::string sexos[] = { "Indefinido", "Masculino", "Feminino" };
    std::string niveis[] = { "Indefinido", "Graduacao", "Especializacao", "Mestrado", "Doutorado" };
    tmp.append(this->get_nome());
    tmp.append("\n\tSexo: ");
    tmp.append(sexos[this->get_sexo()]);
    tmp.append("\n\tNascimento: ");
    tmp.append(ctime(&dtnascimento));
    tmp.append("\n\tCodigo: ");
    tmp.append(this->get_codigo());
    tmp.append("\n\tNivel: ");
    tmp.append(niveis[this->get_nivel()]);
    tmp.append("\n}\n");
    return tmp;
}
std::ostream& operator<<(std::ostream& os, Aluno::Nivel n){
    switch(n) {
        case Aluno::INDEFINIDO : os << "INDEFINIDO"; break;
        case Aluno::GRADUACAO : os << "GRADUACAO"; break;
        case Aluno::ESPECIALIZACAO : os << "ESPECIALIZACAO"; break;
        case Aluno::MESTRADO : os << "MESTRADO"; break;
        case Aluno::DOUTORADO : os << "DOUTORADO"; break;
        default : os.setstate(std::ios_base::failbit);
    }
    return os;
}

/*Exercício 3:polimorfismo por inclusão
Modifique o algoritmo anterior de maneira que ele adicione tanto pessoas Pessoas quanto Alunos. Ao adicionar, use algum método de sorteio para que algumas entidades sejam de um tipo (Aluno) e outras de outro (Pessoa). O programa deve mostrar o conteúdo do elemento em cada posição do container de acordo com o seu tipo. Para tanto, use toString() e vinculação dinâmica (lembrando que, em C++, para funcionar, o método tem de ser declarado como virtual e a variável usada para manipular os elementos deve ser um ponteiro ou referência). Em Java, por padrão os métodos são disparados por vinculação dinâmica e o problemanão ocorre. No entanto, o que você teria que fazer para que o mesmo erro que ocorre em C++ ocorresse em Java?*/
/*Teria que declarar os métodos como estáticos.*/

int main(){
    using namespace std;
    vector<Pessoa*> vetor;
    int i=0;
    // verifica tamanho atual (original)
    cout << "Tamanho do vetor = " << vetor.size() << endl;
    // coloca alguns numeros no vetor
    cout << "Inserindo alguns elementos..." << endl;
    for(i = 0; i < SIZE; i++){
        if(rand()%2)
            vetor.push_back(new Pessoa("Ana Paula", Pessoa::FEMININO, time(0))); // adiciona no final do vetor
        else
            vetor.push_back(new Aluno("Jose Silva", Pessoa::FEMININO, time(0), "01001010", Aluno::GRADUACAO));
    }
    // verifica tamanho atual
    cout << "Tamanho do vetor = " << vetor.size() << endl;
    
    // mostrando elementos adicionados
    for(i = 0; i < SIZE; i++){
        cout << "vetor[" << i << "] = " << vetor[i]->toString() << endl;
    }

    return 0;
}