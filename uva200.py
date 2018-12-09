#!/usr/bin/env python
# -*- coding: utf-8 -*-

def UVA200_dfs(corrente,cores,lista_adjacencias,pilha):
    
    cores[corrente] = 1
    for a in lista_adjacencias:

        neighbor = a
        if (cores[neighbor] == 0):        
            UVA200_dfs(neighbor, cores, lista_adjacencias, pilha)
       


    cores[corrente] = 2;
    pilha.append(corrente);

def main():
    # Step 1: Lendo input
    indice = []
    linha = 'oi'

    while(linha!= " "):
        linha = input()
        if (linha == '#'):
           break
        indice.append(linha)

    # Step 2: Numbering the characters
    numbering = {}
    naming = {}

    for i in range(0,len(indice)):
        
        s = indice[i]
        for c  in range(0,len(s)):
            if s[c] in numbering:
                n = len(numbering)
                numbering[s[c]] = n
                naming[n] = s[c]
                            
    # Step 3: Build the precedence graph
    num_nos = len(numbering)
    lista_adjacencias = []
    #lista_adjacencias[num_nos]

    for i in range(1,len(indice)):
        ant = indice[i - 1]
        prox = indice[i]
        while (c < len(prox) and c < len(ant)):
            if (ant[c] != prox[c]):
                lista_adjacencias[numbering[ant[c]]].append(numbering[prox[c]])
                break


    #Step 4: DFS para ordenacao topologica
    cores = []
    pilha = []
    
    for i in range(0,num_nos):
        cores.append(0)

    for i in range(0,num_nos):    
        if (cores[i] == 0):
            UVA200_dfs(i, cores, lista_adjacencias, pilha)
        
    while (len(pilha) > 0):
        print(naming[pilha.pop()],end="")
            
    print()


if __name__ == '__main__':
	main()