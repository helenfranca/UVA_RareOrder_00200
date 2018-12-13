//22441720

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
    // Passo 1: Lendo entrada
    string linha;
    vector<string> indice;
    linha = "!";
    
    while (linha != " ")
    {
        getline(cin, linha);
        if (linha == "#")
        {
            
            // Passo 2: numerando os caracteres
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
        
            // Passo 3: Controi grafico de precedencia
            int num_nos = numerando.size();
            vector<set<int>> lista_adjacencia;
            lista_adjacencia.resize(num_nos);
        
            for (unsigned int i = 1; i < indice.size(); i++)
            {
                string ant = indice[i - 1];
                string prox = indice[i];
                for (unsigned int c = 0; c < ant.length() && c < prox.length(); c++)
                {
                    if (ant[c] != prox[c])
                    {
                        lista_adjacencia[numerando[ant[c]]].insert(numerando[prox[c]]);
                        break;
                    }
                }
            }
        
            // Passo 4: DFS para ordenação topologica
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
                printf("%s\n", nomeando[ordem.top()]);
                ordem.pop();
            }
            indice.clear();
            getline(cin, linha);
            printf("%s\n", endl);
            
        }
        indice.push_back(linha);
    }
     
    return 0;
}

void dfs(int atual, vector<int> &cores, vector<set<int>> lista_adjacencia, stack<int> &ordem)
{
    cores[atual] = 1;
    for (set<int>::iterator ni = lista_adjacencia[atual].begin(); ni != lista_adjacencia[atual].end(); ni++)
    {
        int vizinho = *ni;
        if (cores[vizinho] == 0)
        {
            dfs(vizinho, cores, lista_adjacencia, ordem);
        }
    }
    cores[atual] = 2;
    ordem.push(atual);
}
