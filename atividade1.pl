pessoa(X) :- masculino(X).
pessoa(X) :- feminino(X).
irmao(X,Y) :- pai(X,P),pai(Y,P),mae(X,M),mae(Y,M),Y\==X.
tioa(X,Y) :- (pai(X,P),irmao(P,Y));(mae(X,M),irmao(M,Y)).
tio(X,Y) :- tioa(X,Y),masculino(Y).
tia(X,Y) :- tioa(X,Y),feminino(Y).
avos(X,Y) :- (pai(X,PROGEN);mae(X,PROGEN)), %progenitor(a)
    (pai(PROGEN,Y); mae(PROGEN,Y)).
avof(X,Y) :- avos(X,Y),feminino(Y).
avom(X,Y) :- avos(X,Y),masculino(Y).
antepassado(X,Y) :- mae(X,Y); pai(X,Y);
                tioa(X,Y); avos(X,Y).
feminino(maria).
feminino(ana).
feminino(daniele).
feminino(carla).
masculino(joao).
masculino(jose).
masculino(marcio).
masculino(leonardo).
masculino(fernando).
masculino(marcelo).
pai(ana,joao).
pai(jose,joao).
pai(marcio,joao).
pai(carla,leonardo).
pai(fernando,leonardo).
pai(marcelo,marcio).
mae(ana,maria).
mae(jose,maria).
mae(marcio,maria).
mae(carla,daniele).
mae(fernando,daniele).
mae(marcelo,carla).
gosto(joao,ler).
gosto(maria,ler).
gosto(ana,boliche).
gosto(jose,boliche).
gosto(marcio,boliche).
gosto(leonardo,doce).
gosto(daniele,doce).
gosto(carla,salgado).
gosto(fernado,salgado).
gosto(marcelo,corrida).
% este é um comentário de uma linha
/*Este é umcomentáriode muitas
linhas.
Operador  Significado
,         And
;         Or
=         Unificação(atribuição)
\=        Negação da unificação
==        Teste de identidade
\==       Negação da identidade
=:=       Igualdade aritmética
< > >= =< Operadores relacionais
:=        Condicional
*/