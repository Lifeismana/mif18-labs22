#ex 1 

chaque programme lancé utilise un coeur du processeur entièrement jusqu'à ce que qu'autant de programme s'execute que le nombre de coeur.
à ce moment là, les programmes se paratagent les coeurs mais la répartition n'est pas équitable, les programmes exécuté en premier ont plus de temps d'exécution

Avec taskset, la r&partition est équitable, chaque programme s'exécute autant sur le coeur

taskset -c 0 nice -n 5 ./ex1.exe

plus un programme a une valeur de priorité faible, plus il s'execute.
2 programme avec la même priorité, s'executent autant
(ils utilisent 100% du coeur)

#ex2

Avec 2 programmes, le temps affiché correspond au temps d'execution des 2 programme (200 000 yield), avec une seule instance il correspond uniquement au temps d'execution de ce programme (100 000 yield)



1 instance :  78 000 ms
2 instances : 275 000 ms
3 instances : 470 000 ms
4 instances : 645 000 ms
5 instances : 827 000 ms


#ex3 