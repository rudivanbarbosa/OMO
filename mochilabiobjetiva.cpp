#include <iostream>
#include <vector>
#include <set>
#include <fstream>

using namespace std;

int ParetoOtimo(int n, int d){

ifstream entrada("dados.txt");

int matriz[n][d];

for( int i = 0; i<n; i++){
    for( int j = 0; j<d; j++){

    entrada >> matriz[i][j];

        }
}


set < int > conjunto;
 for (int l=0; l< n; l++){
    conjunto.insert(l);

 }

set<int >::iterator it;

for (int i=0; i<n; i++)
{

    for (int k=0; k<n; k++){

        for(int j=0; j<d; j++){

           if(matriz[i][j] != matriz[k][j] && (matriz[i][0] <= matriz[k][0] && matriz[i][1] <= matriz[k][1]) ){  conjunto.erase(k);}


                            }

                          }
}


for (it = conjunto.begin(); it != conjunto.end(); it++) {
       for (int i=0; i<n; i++){
            if( i == *it){
                for(int j=0; j<d; j++){  cout << matriz[i][j] << " "; }

        }

    }
    cout << "\n";
}

}

int main(){
int n = 5;
int d = 2;

ParetoOtimo(n,d);




}
