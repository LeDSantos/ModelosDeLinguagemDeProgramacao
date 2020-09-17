fat(0,1) :- !.
fat(N,X) :- N1 is N-1, fat(N1,X1), X is N*X1.

len_lista([],0) :- !.%criterio de parada
len_lista([H|T], R) :- len_lista(T, R2), R is R2+1.%acumula

concat_lst([], L2, L2) :- !.%parada
concat_lst([X|L1], L2, [X|D]) :- concat_lst(L1, L2, D).
%D destino

membro(Ele, [Ele|_]).
membro(Ele, [_|Cauda]) :- membro(Ele, Cauda).

% ! cut PARA
% fail falha, FALSO