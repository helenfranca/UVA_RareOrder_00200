//22441819

//#include "stdafx.h"

// http://uva.onlinejudge.org/indice.php?option=onlinejudge&page=show_problem&problem=136

//#include "UVa200.h"

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <stack>

using namespace std;

void dfs(int atual, vector<int> &cores, vector<set<int>> lista_adjacencia, stack<int> &ordem);

int main()
{
    // Step 1: Lendo entrada
    string line;
    vector<string> indice;
    while (true)
    {
        getline(cin, line);
        if (line == "#")
        {
            break;
        }
        indice.push_back(line);
    }

    // Step 2: numerando os caracteres
    map<char, int> numerando;
    map<int, char> nomeando;
 
    for (unsigned int i = 0; i < indice.size(); i++)
    {
        string s = indice[i];
        for (unsigned int c = 0; c < s.length(); c++)
        {   
           
            if (numerando.find(s[c]) == numerando.end())
            {
                int n = numerando.size();
                numerando.insert(pair<char, int>(s[c], n));
                nomeando.insert(pair<int, char>(n, s[c]));
            }
        }
        
    }

    // Step 3: Controi grafico de precedencia
    int num_nos = numerando.size();
    vector<set<int>> lista_adjacencia;
    lista_adjacencia.resize(num_nos);

    for (unsigned int i = 1; i < indice.size(); i++)
    {
        string prev = indice[i - 1];
        string next = indice[i];
        for (unsigned int c = 0; c < prev.length() && c < next.length(); c++)
        {
            if (prev[c] != next[c])
            {
                lista_adjacencia[numerando[prev[c]]].insert(numerando[next[c]]);
                break;
            }
        }
    }

    // Step 4: DFS para ordenação topológica
    vector<int> cores;
    stack<int> ordem;
    cores.resize(num_nos);
    for (int i = 0; i < num_nos; i++)
    {
        cores[i] = 0;
    }

    for (int i = 0; i < num_nos; i++)
    {
        if (cores[i] == 0)
        {
            dfs(i, cores, lista_adjacencia, ordem);
        }
    }

    while (ordem.size() > 0)
    {
        cout << nomeando[ordem.top()];
        ordem.pop();
    }
    cout << endl;

    return 0;
}

void dfs(int atual, vector<int> &cores, vector<set<int>> lista_adjacencia, stack<int> &ordem)
{
    cores[atual] = 1;
    for (set<int>::iterator ni = lista_adjacencia[atual].begin(); ni != lista_adjacencia[atual].end(); ni++)
    {
        int neighbor = *ni;
        if (cores[neighbor] == 0)
        {
            dfs(neighbor, cores, lista_adjacencia, ordem);
        }
    }
    cores[atual] = 2;
    ordem.push(atual);
}
