#include <iostream>
#include <vector>
#include <fstream>
#include <math.h>
#include <algorithm>
#include <set>

using namespace std;

vector < pair <float, float> > pareto;
set < int > conjunto;
set < int >::iterator it;

void addpareto(float v1, float v2)
	{
		pareto.push_back(make_pair(v1, v2));
	}


void mochila( float lucro[], float peso[], int Capacidade, int n)
{

vector <int> captura;

float lucro_total = 0.0;
float massa = 0.0;
float aux = 0.0;
double cont = pow(2, n);

    for (int i = 0; i < cont; i++) {
        for (int j = 0; j < n; j++) {

            if ((i & (1 << j)) != 0){
                captura.push_back(1);
                }else {
                     captura.push_back(0);
                     }
            }
        for(int k = 0; k < n; k++){
                    lucro_total += lucro[k]*captura[k];
                    massa += peso[k]*captura[k];

                }
        if( (aux <= lucro_total) && (lucro_total != 0.0) && massa <= Capacidade){
                aux = lucro_total;
                addpareto(lucro_total, massa);
        }
        lucro_total = 0.0;
        massa = 0.0;
        captura.clear();
    }

sort(pareto.rbegin(), pareto.rend());

for(int l = 0; l < pareto.size(); l++){
        conjunto.insert(l);
}

for(int l = 1; l < pareto.size(); l++){
    if(pareto[l].second >= pareto[0].second ){
       conjunto.erase(l);
    }
}

for (it = conjunto.begin(); it != conjunto.end(); it++) {
        for(int i = 0; i < pareto.size(); i++) {
            if( i == *it){cout << pareto[i].first << " " << pareto[i].second << "\n";}
        }

}



}

int main()
{
int n = 20;
int C = 994;
float lucro[n];
float peso[n];

ifstream dados("dados20.txt");
for(int i = 0; i<n; i++){
    dados >> lucro[i];
    dados >> peso[i];
}
dados.close();

mochila(lucro, peso, C, n);

    return 0;
}

