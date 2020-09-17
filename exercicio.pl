/*Crie uma cláusula (regra) que receba uma lista e imprima na tela os elementos desta lista. Atenção: os elementos devem ser impressos de forma individual, um por linha. 

Dica: use os comandos write() e nl.*/

imprime_lista([])   :- !.
imprime_lista(X)    :- [H|T]=X, print(H), nl, imprime_lista(T).

/*Crie uma cláusula (regra) que receba uma lista e retorne em um parâmetro o último elemento dessa lista.

Exemplo:

ultimoLst([1,2,3,4], R). % devolve o último em R.*/

ultimoLst(X,H)      :- [H|T]=X, T == [].%, print(H). se tail está vazia, é o ultimo
ultimoLst(X,R)      :- [H|T]=X, ultimoLst(T,R).

/*Crie uma cláusula (regra) que receba uma lista e devolva em outro parâmetro essa mesma lista com seus elementos invertidos (de trás par frente).

Exemplo:
inverteLst([1,2,3,4], R). % devolve a lista invertida em R

Você não pode usar funções já prontas (disponíveis na biblioteca de comandos do PROLOG). */

%fun dos slides
concat_lst([], L2, L2) :- !.%parada
concat_lst([X|L1], L2, [X|D]) :- concat_lst(L1, L2, D).

inverteLst([], L2) :- !.
inverteLst([H|T], R) :- inverteLst(T, D), concat_lst(D,[H],R).

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

% Resposta da questao 1:

% pessoa(Nome).
pessoa('Joao').
pessoa('Maria').
pessoa('Ana').
pessoa('Jose').
pessoa('Marcio').
pessoa('Leonardo').
pessoa('Daniele').
pessoa('Carla').
pessoa('Fernando').
pessoa('Marcelo').

% feminino(Nome).
feminino('Maria').
feminino('Ana').
feminino('Carla').
feminino('Daniele').

% masculino(Nome).
masculino('Joao').
masculino('Jose').
masculino('Marcio').
masculino('Leonardo').
masculino('Fernando').
masculino('Marcelo').

%filho(Pai, Filho).
filho('Joao', 'Ana').
filho('Joao', 'Jose').
filho('Joao', 'Marcio').
filho('Maria', 'Ana').
filho('Maria', 'Jose').
filho('Maria', 'Marcio').
filho('Leonardo', 'Carla').
filho('Leonardo', 'Fernando').
filho('Marcio', 'Marcelo').
filho('Daniele', 'Carla').
filho('Daniele', 'Fenando').
filho('Carla', 'Marcelo').

%gosta(Pessoa, Gosto).
gosta('Joao', 'leitura').
gosta('Maria', 'leitura').
gosta('Leonardo', 'leitura').
gosta('Joao', 'cinema').
gosta('Marcio', 'cinema').
gosta('Carla', 'cinema').
gosta('Marcio', 'boliche').
gosta('Carla', 'boliche').
gosta('Maria', 'boliche').
gosta('Joao', 'Maria').
gosta('Maria', 'Joao').
gosta('Maria', 'peixe').
gosta('Maria', 'vinho').
gosta('Joao', 'vinho').

% pai(Pai, Filho)
ehpai(P, F):- filho(P,F).
pai(P, F):- ehpai(P,F), masculino(P).
mae(M, F):- ehpai(M,F), feminino(M).

irmaos(X, Y):- pai(P, X), pai(P,Y), mae(M, X), mae(M, Y), X\=Y.
irmao(X,Y):-irmaos(X,Y), masculino(Y).
irma(X,Y):-irmaos(X,Y), feminino(Y).

meioirmaos(X,Y):-(pai(P,X), pai(P,Y)), X\=Y.
meioirmaos(X,Y):-(mae(M,X), mae(M,Y)), X\=Y.

meioirmao(X,Y):-meioirmaos(X,Y), masculino(Y).
meioirma(X,Y):-meioirmaos(X,Y), feminino(Y).

%tios(Tio, Sobrinho).
tios(T,S):-pai(P,S), irmaos(P,T).
tios(T,S):-mae(M,S), irmaos(M,T).
tia(T,S):-tios(T,S), feminino(T).
tio(T,S):-tios(T,S), masculino(T).

%avos(Avo, Neto).
avos(A,N):-ehpai(P, N), ehpai(A,P).
avo(A,N):-avos(A,N), masculino(A).
avoh(A,N):-avos(A,N), feminino(A).

%antepassado(Antepassado, Pessoa).
antepassado(A,P):-ehpai(A,P).
antepassado(A,P):-ehpai(X,P),antepassado(A,X).

%contaAntepassados(Pessoa, Quantidade).
contaAntepassados(P,Q):-setof(X, antepassado(X,P), Ls),length(Ls, Q).

% parentes
parente(X,Y):-irmaos(X,Y);meioirmao(X,Y).
parente(X,Y):-antepassado(X,Y). % antepassados
parente(X,Y):-antepassado(Y,X). % filhos, netos
parente(X,Y):-antepassado(Z,X), antepassado(Z,Y), not(antepassado(X,Y)), X\=Y. % sogro, sogra
parente(X,Y):-antepassado(Z,X), antepassado(Z,H), H\=X, 	irmaos(H,Y). %cunhados



/*Levando em conta o programa disponibilizado pelo professor no Moodle (genealogia.pl), crie uma regra que conte quantas cláusulas de determinado tipo existem. 

Por exemplo:

contaClausulas(pessoa, Qtd). % recebe o nome da cláusula que deverá ser contada (no caso, 'pessoa') e devolve a quantidade na variável 'Qtd'.

Dica: use o comando 'setof', 'bagof' ou similar para criar uma lista de cláusulas. Procure no google como usá-los e descubra a diferença entre eles...*/

%fun dos slides
len_lista([],0) :- !.%criterio de parada
len_lista([H|T], R) :- len_lista(T, R2), R is R2+1. %acumula

contaClausulas(Clau, Num) :- findall(Y, Clau, Set), len_lista(Set, Num).

/*Crie uma regra denominada 'tamanhoLst', que receba uma lista Lst e devolva em Q a quantidade de elementos que ela possui (i.e., seu tamanho ou quantidade de elementos).

Exemplo:

?- Lst = [1,2,3,4], tamanhoLst(Lst, Q), write(Q).

Você não pode usar a cláusula 'length' ou similar, mas pode usar um dos comandos de manipulação de listas que aprendeu na questão anterior (bagOf, setOf, findall) ou simular um contador, se preferir.*/

%fun dos slides
tamanhoLst([],0) :- !.%criterio de parada
tamanhoLst([H|T], R) :- tamanhoLst(T, R2), R is R2+1. %acumula

/*Crie uma cláusula (regra) que crie uma lista das pessoas que gostam de determinada coisa ou pessoa. 

Por exemplo, em cima da seguinte base de conhecimento: 

pessoa(ana).
pessoa(joao).
pessoa(andre).
pessoa(carla).
gosta(ana, futebol).
gosta(andre, futebol). 

Existem 4 cláusulas do tipo 'pessoa' e 2 do tipo 'gosta'. 

Uma consulta do tipo: 

?- lstPessoasQueGostam(futebol, R). 

Revolveria:

R=[ana, andre].*/

lstPessoasQueGostam(Atividade, Set) :- findall(X, gosta(X,Atividade), Set).

/*Utilize a cláusula (regra) elaborada em um exercício anterior para elaborar o seguinte programa em Prolog:

    Pedir para o usuário informar o tipo de gosto que deseja consultar (estude o comando "read" para isso);
    Use a cláusula (regra) elaborada em um exercício anterior para elaborar a lista de pessoas que gostam do gosto informado pelo usuário;
    Informe quantas pessoas existentes na base gostam do elemento informado (você pode usar a cláusula elaborada em outro exercício para contar os elementos da lista de pessoas);
    Liste as pessoas na tela, uma por linha (também há uma cláusula pronta em exercício anterior para isso). 
*/

main :-
    nl,print('Qual tipo de gosto que deseja consultar?'),nl,
    read(Consulta),nl,
    lstPessoasQueGostam(Consulta, Set),
    len_lista(Set, Num),
    print('Numero de pessoas que gostam disso: '),print(Num),nl,
    print('Pessoas:'),nl,imprime_lista(Set),
    nl,print('FIM').





/*Elabore um predicado em Prolog que simule uma função que gera os n primeiros números da série de Fibonacci.

Lembre-se de que:

    você pode criar mais de uma cláusula (cada uma com um termo ou padrão de 'entrada');
    você pode usar recursão, mas a primeira clausula deve especificar a condição de parada, já que o processo de resolução (inferência) atua de cima para baixo e da esquerda para a direita;
*/

fibonacci(0,0) :- !.
fibonacci(1,1) :- !.
fibonacci(N,R) :- N1 is N-1, N2 is N-2, fibonacci(N1,R1), fibonacci(N2,R2), R is R1+R2.

serie_fibo(0,[]) :- !.
serie_fibo(Ntermos,L) :- fibonacci(Ntermos,R), N1 is Ntermos-1, serie_fibo(N1,L2), concat_lst(L2,[R],L).

% concat_lst(D,[H],R)

/*len_lista([],0) :- !.%criterio de parada
len_lista([H|T], R) :- len_lista(T, R2), R is R2+1. %acumula*/