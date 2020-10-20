#ifndef PESSOA
#define PESSOA
class Pessoa{
	public:
		enum Sexo {INDEFINIDO,MASCULINO,FEMININO };
		
		// Construtor de cópia
		Pessoa(const Pessoa&);
		
		// Construtor com valores default 
		// (assume valores especificados caso algum parâmetro não seja passado)
		Pessoa(std::string="indefinido",Sexo=INDEFINIDO,time_t=time(0));
		
		// Operador de atribuição sobrecarregado para receber uma pessoa
		Pessoa& operator=(const Pessoa&);
		
		// Getter e setter para Data de nascimento
		const time_t get_dtnascimento() const;
		void set_dtnascimento(time_t);
		
		// Getter e setter para Nome
		const std::string get_nome() const;
		void set_nome(std::string);
		
		// Getter e setter para Sexo
		const Sexo get_sexo() const;
		void set_sexo(Sexo);
		
		// retorna uma string com os dados da instância
		std::string toString();
		
	private:
		time_t m_dtnascimento;// armazena a data de nascimentoda pessoa
		std::string m_nome;// armazena o nome da pessoa
		Sexo m_sexo;// armazena o sexo da pessoa
};
	// indica que o operador de inserção (para cout) serásobrecarregado
	// para poder retornar (e imprimir) instâncias desta classe
std::ostream& operator<<(std::ostream&, const Pessoa&);
	
#endif
