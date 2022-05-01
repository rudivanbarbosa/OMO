#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
#include <fstream>

using namespace std;

vector < vector <int> > ParetoOtimo(vector < vector <int> > &matriz ){
int i = 0;
int j = 1;

 while(i < matriz.size() && matriz[i][1] != 0){

            while( matriz[i][1] < matriz[j][1] && matriz[i][1] != 0){
               matriz.erase(matriz.begin()+ j);
                    }
                i = i + 1;
                j = i + 1;

 }

return matriz;

}

void Mochila(int valor[], int peso[], int C, int n){

vector < vector < int > > matriz;
vector < vector < int > > aux;
vector < int > vetor;
vector < int > solucao_final;

for(int w = 0; w < n+2; w++){vetor.push_back(0);}

matriz.push_back(vetor);

int massa = 0;
int lucro = 0;

for(int k = 0; k < n; k++ ){


    copy(matriz.begin(), matriz.end(), back_inserter(aux));
    for(int l = 0; l < matriz.size(); l++ ){
        aux[l][k+2] = 1;
    }
    copy(aux.begin(), aux.end(), back_inserter(matriz));
    aux.clear();

    for(int l = 0; l < matriz.size(); l++ ){
        for(int r = 0; r < n; r++){
        massa += matriz[l][r+2]*peso[r];
        lucro += matriz[l][r+2]*valor[r];
        }

        matriz[l][0] = lucro;
        matriz[l][1] = massa;
        lucro = 0;
        massa = 0;
    }

sort(matriz.rbegin(), matriz.rend());
ParetoOtimo(matriz);



}
ofstream saida("saida.txt");
for (int i = 0; i < matriz.size(); i++){
    for(int j = 0; j< n+2; j++){
        saida << matriz[i][j] << " ";
                    }
                    saida << "\n";
                }
int solucao = 0;
solucao_final.push_back(0);
solucao_final.push_back(0);
 for (int i = 0; i < matriz.size(); i++){
    if( (matriz[i][0] >= solucao_final[0]) && (matriz[i][1] <= C) ){
        solucao = matriz[i][0];
        solucao_final.clear();
        solucao_final.push_back(solucao);
        solucao_final.push_back(matriz[i][1]);
    }


}

cout << solucao_final[0] << " " <<  solucao_final[1] << "\n";
}




int main(){

int n = 50;
int C = 982;
int valor[n];
int peso[n];

ifstream dados("dados50.txt");
for(int i = 0; i<n; i++){
    dados >> valor[i];
    dados >> peso[i];
}
dados.close();


Mochila(valor, peso, C, n);


}
