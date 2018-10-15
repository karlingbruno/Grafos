#include<iostream>
using namespace std;// OBS : Por questão de implementação na matriz dos vértices,"vi" sempre tem que ser o maior vértice conectado à aresta
// Para a alteração da matriz também deve se alterar o "n"
bool func(int vetori[],int vetorj[], int x , int y){//verifica se x e y estão na mesma árvore
  if(vetori[x - 1] == x){
    if(vetorj[y - 1] == y)
      return false;
  }
  return true;
}
int main(){
  int matriz[3][11]=/*pe*/{{2,3,3,4,4,7,7,7,8,8,8},
                    /*vi*/ {7,1,3,2,6,6,7,7,4,5,5},
                    /*vj*/ {6,0,0,0,5,4,4,5,2,2,3}};
  int n = 7, vetori[n], vetorj[n], cont = 0, i = 0, peso = 0;
  for(int z = 0; z < n; z++){//coloca todos os valores dos vetores = -1
    vetori[z] = -1;
    vetorj[z] = -1;
  }
  for(;cont < n ; i++){//faz o loop até n - 1 valores serem adicionados ao vetor
    if(func(vetori,vetorj,matriz[1][i],matriz[2][i])){
      vetori[matriz[1][i] - 1] = matriz[1][i];
      vetorj[matriz[2][i] - 1] = matriz[2][i];
      cout << "(" << matriz[1][i] << "," << matriz[2][i] << ")" << endl;
      peso += matriz[0][i];
      cont++;
    }else
      continue;
  }
  cout << "Peso da Árvore : " << peso << endl;
}
