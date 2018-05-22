#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
using namespace std;


int main() {
    long int n, n_comp, n_comp_aux, F, swap, i;
    string nome1, nome2;

    cin >> n;
    while (n != 0) {
        cin >> F;
        n_comp = 0;
        vector <long int> componentes (F, 0);
        map <string, long int> relacoes;

        for (i = 0; i < F; i++) {
            cin >> nome1;
            cin >> nome2;
            map <string, long int>::iterator it1 = relacoes.find(nome1);
            map <string, long int>::iterator it2 = relacoes.find(nome2);
            if (it1 == relacoes.end() && it2 == relacoes.end()) { // nenhum existe
                if (nome1.compare(nome2) == 0) {
                    relacoes[nome1] = n_comp;
                    componentes[n_comp] = 1;
                    n_comp++;
                    cout << "1\n";
                } else {
                    relacoes[nome1] = n_comp;
                    relacoes[nome2] = n_comp;
                    componentes[n_comp] = 2;
                    n_comp++;
                    cout << "2\n";
                }
            }
            if (it1 != relacoes.end() && it2 == relacoes.end() ) { // existe só nome1
                relacoes[nome2] = it1->second;
                componentes[it1->second]++;
                cout << componentes[it1->second] << "\n";
            } 
            if (it1 == relacoes.end() && it2 != relacoes.end() ) { // existe só nome2
                relacoes[nome1] =  it2->second;
                componentes[it2->second]++;
                cout << componentes[it2->second] << "\n";
            } 
            if (it1 != relacoes.end() && it2 != relacoes.end() ) { // ambos ja existem
                if (it1->second == it2->second) {
                    cout << componentes[it1->second] << "\n";
                } else {
                    map <string, long int>::iterator it;
                    if (componentes[it1->second] > componentes[it2->second]) {
                        componentes[it1->second] += componentes[it2->second];
                        cout << componentes[it1->second] << "\n";
                        n_comp_aux = it2->second;
                        for (it = relacoes.begin(); it != relacoes.end(); it++) {
                            if (it->second == n_comp_aux) {
                                it->second = it1->second;
                            }
                        }
                    } else {
                        componentes[it2->second] += componentes[it1->second];
                        cout << componentes[it2->second] << "\n";
                        n_comp_aux = it1->second;
                        for (it = relacoes.begin(); it != relacoes.end(); it++) {
                            if (it->second == n_comp_aux) {
                                it->second = it2->second;
                            }
                        }
                    }
                }
            } 

        }
        n--;
    }

    return 0;
}