Tema: Grafuri
Nume: Popa Stefan-Andrei 313CC

Implementarea acestei teme a durat in jur de doua saptamani, insumand aproximativ 30 de ore lucru.
Rezolvarea temei poate fi impartita in doua etape: definirea si implementarea unor structuri corecte care
sa reprezinte graf-ul, iar apoi rezolvarea efectiva a cerintelor folosind aceste structuri. Pe langa
structuri care reprezinta graf-ul sau listele de adiacenta, am utilizat inclusiv o structura de tip 
Coada pentru Task-urile 2 si 3.

In total, au fost rezolvate primele 3 Task-uri de la problema 1.

Structurile utilizate in rezolvare sunt definite in fisierele Graph.h si Queue.h.
Alaturi de definitiile propriu-zise ale acestora, am descris si functiile utilitare specifice fiecarei
structuri in parte: functiile de push, de initializare, de eliberare de memorie etc.
Functiile au fost testate la inceput pe foarte multe exemple particulare pentru a asigura
buna functionare si utilizare a acestora.

Pentru fiecare task, am definit cate o functie de intrare in fisierul Task.h.
La inceputul fiecarei functii, se testeaza deschiderea fisierelor de intrare si iesire si se citesc 
informatiile in mod corespunzator pentru alcatuirea grafului.

In fisierul Task.h sunt descrise semnaturile diferitelor functii utilizate pentru descrierea
algoritmului din fiecare task.

La primul Task, am mers pe un algoritm de DFS care parcurge nodurile nevizitate ale grafului
si care numara din cati subarbori este alcatuit acesta. Numarul subarborilor corespunde numarului
de componente conexe.

La al doilea Task, am mers pe un algoritm de BFS care parcurge graful pornind de la un nod de start
in mod radial. Fiecare "strat" este vizitat cu o alta culoare care determina in final distanta de la un
nod de pe strat la nodul de start.

La al treilea Task, am utilizat pseudocodul din documentatie si am incercat sa ma folosesc de o coada 
pentru stocarea pe parcurs a punctelor de articulatie. Pentru ordonarea punctelor, am utilizat un algoritm
simplu de sortare BubbleSort pentru ca dimensiunea datelor ce trebuie ordonate nu e foarte mare.

La fiecare Task, am eliberat complet toata memoria. Dimensiunea grafului difera in functie de fiecare test,
fiind necesari de la 2 MB de memorie, pana la 23 de MB in cazul unelor teste. Sursa ruleaza fara Seg Fault-uri.