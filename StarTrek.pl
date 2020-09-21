%1 Crie um programa em PROLOG capaz de representar os fatos nela expressos
locomocao('Enterprise','Motor de dobra').
pertence('D-deridex','Imperio Romulano').
pertence('Enterprise','Federacao').
eh_um('Enterprise','Nave').
eh_um('D-deridex','Nave').
eh_um('NX-01','Enterprise').
eh_um('NCC-1701','Enterprise').
eh_um('NCC-1701-D','Enterprise').
eh_um('Voyager','Enterprise').
eh_um('IRW TMet','D-deridex').
comanda('Archer','NX-01').
comanda('Kirk','NCC-1701').
comanda('Picard','NCC-1701-D').
comanda('Janeway','Voyager').
comanda('Almak','IRW TMet').
aconselha('Spock','Kirk').
aconselha('Diana','Picard').

%2.Com base nela, crie uma regra que permita consultar se determinado X é comandante de uma facção Y (Federação ou Império Romulano, no caso).
comandante(P,Y) :- comanda(P,A), eh_um(A,B), pertence(B,Y).

%3.Crie uma regra que teste se dois comandantes são inimigos, tendo como base a facção que eles pertencem
inimigo(X,Y) :- comandante(X,A), comandante(Y,B), A\=B.

%4.Com base na regra anterior, elabore uma cláusula que, dado um comandante, crie uma lista de todos os seus inimigos.
%lstPessoasQueGostam(Atividade, Set) :- findall(X, gosta(X,Atividade), Set).
lista_inimigo(P, L) :- findall(X, inimigo(P,X), L).

%5.Elabore uma cláusula que crie uma lista de todos os comandantes de determinada facção.
lista_faccao(F,L) :- findall(X, comandante(X, F), L).

%6.Crie uma cláusula que simule um programa que conte quantas naves possui uma dada facção.
%Ao chamar o “programa”, ele deve solicitar a federação desejada e informar a quantidade de naves, conforme o exemplo seguinte:
%?-conta_naves.
%Deseja contar as naves de qual facção?
%federação
%A federação possui 4 naves conhecidas.

conta_naves :-  write('Deseja contar as naves de qual faccao? Escreva o nome entre aspas.'),nl,
                read(Fac),                
                findall(Nave, (eh_um(Nave,A), eh_um(A, 'Nave'), pertence(A, Fac)), Lista),
                length(Lista, Comp),
                write(Fac),write(' possui '),write(Comp),write(' naves conhecidas.').