#include<iostream>
using namespace std;
bool arvore(int open[]){//verifica se ainda existem vértices abertos na fila
  for(int i = 0; i < 8; i ++){
    if(open[i] != -1)
      return false;
  }
  return true;
}
int func(int open[], int matriz[2][8]){
  int menor = 9999,posi = -1;
  for(int i = 0; i < 8; i++){
    if(matriz[0][i] < menor && matriz[0][i] > 0){
      if(open[i] == -1){
        continue;
      }else{
        menor = matriz[0][i];
        posi = i;
      }
    }
  }
  return posi;
}
bool func2(int open[],int x){
  if(open[x] == x ){
    return true;
  }else{
    return false;
  }
}
int main(){
                        //  0 1 2 3 4 5 6 7
  int matriz[8][8] = /*0*/{{0,2,0,6,5,0,0,0},
                     /*1*/ {2,0,7,7,0,0,0,0},
                     /*2*/ {0,7,0,0,6,2,0,0},
                     /*3*/ {6,7,0,0,0,0,0,0},
                     /*4*/ {5,0,6,0,0,0,4,5},
                     /*5*/ {0,0,2,0,0,0,4,6},
                     /*6*/ {0,0,0,0,4,4,0,1},
                     /*7*/ {0,0,0,0,5,6,1,0}};

  int adj[2][8] = {{00,10,10,10,10,10,10,10},
                   {-1,-1,-1,-1,-1,-1,-1,-1}};
  int open[8],linha = 0,peso = 0;
  for(int i = 0; i < 8; i++)
    open[i] = i;
  while(arvore(open) == false){
    for(int i = 0; i < 8; i++){
      if(matriz[linha][i] < adj[0][i] && matriz[linha][i] > 0 && func2(open,i)){
        adj[0][i] = matriz[linha][i];
        adj[1][i] = linha;
      }
    }
    open[linha] = -1;
    linha = func(open,adj);
  }
  for(int i = 1; i < 8; i++){
    cout << "(" << i << "," << adj[1][i] << ")" << endl;
    peso += adj[0][i];
  }
  cout << "Peso : " << peso << endl;

}
