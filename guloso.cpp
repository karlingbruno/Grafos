#include<iostream>
using namespace std;
int verific(int vetor[5]){
  int soma = 0;
  for(int i = 0; i <5 ;i ++)
    soma += vetor[i];
  return soma;

}
void zerar(int matriz[5][5],int coluna){
  for(int i = 0; i < 5; i++)
    matriz[i][coluna] = 0;
}
void zerar2(int matriz[5][8],int coluna){
  for(int i = 0; i < 5; i++)
    matriz[i][coluna] = 0;
}
void ex01adj(int adj[5][5]){
  int caminho[5] = {1,0,0,0,0};
  int linha = 0;
  int menor = 0;
  int posicao = 0;
  int contador = 1;
  int atual = 1;
  while(verific(caminho) != 15){
    menor = 999999;
    posicao = 0;
    for(int j = 0; j < 5; j++){
      if(adj[linha][j] < menor && adj[linha][j] > 0){
        menor = adj[linha][j];
        posicao = j;

      }
    }
    atual = linha ;
    zerar(adj,atual);
    linha = posicao;
    caminho[contador] = posicao + 1;
    contador++;
  }
  for(int j = 0; j < 5; j++){
    cout << "Caminho : " << caminho[j] << endl;
  }
  cout << "Pressione Enter " << endl;
  getchar();
  getchar();
  system("clear");
}
void ex01inc(int matriz[5][8]){
  int caminho[5] = {1,0,0,0,0};
  int menor;
  int posicao;
  int linha = 0;
  int contador = 1;
  while(verific(caminho) != 15){
    menor = 99999;
    for(int i = 0; i < 8; i++){
      if(matriz[linha][i] < menor && matriz[linha][i] > 0){
        menor = matriz[linha][i];
        posicao = i;
      }
    }
    for(int j = 0; j < 5; j++){
      if(matriz[j][posicao] != 0 && j != linha){
        linha = j;
        break;
      }
    }
    zerar2(matriz,posicao);
    caminho[contador] = linha + 1;
    contador ++;
  }
  for(int i = 0; i < 5; i++){
    cout << "Caminho "<< caminho[i] << endl;
  }
  cout << "Pressione Enter " << endl;
  getchar();
  getchar();
  system("clear");
}
int main(){
                        /* 1   2   3   4   5*/
  int adj1[5][5] = /*1*/{{+00,+30,-15,+00,+20},
                  /*2*/ {-30,+00,-10,+50,+00},
                  /*3*/ {+15,+10,+00,+05,-10},
                  /*4*/ {+00,+50,-05,+00,-30},
                  /*5*/ {-20,+00,+10,+30,+00}};

                      /*a   b   c   d   e   f   g   h*/
int inc1[5][8] /*=1*/{{+20,+30,+00,-15,+00,+00,+00,+00},
                /*2*/ {+00,-30,+00,+00,-10,+00,+00,+50},
                /*3*/ {+00,+00,-10,+15,+10,+00,+05,+00},
                /*4*/ {+00,+00,+00,+00,+00,-30,-05,+50},
                /*5*/ {-20,+00,+10,+00,+00,+30,+00,+00}};
  int x;
  do{
    cout << "1 : Exercício 01 c/ matriz de adjacência" << endl;
    cout << "2 : Exercício 01 c/ matriz de incidência" << endl;
    cout << "3 : Exercício 02 c/ matriz de adjacência" << endl;
    cout << "4 : Exercício 02 c/ matriz de incidência" << endl;
    cout << "0 : Sair" << endl;
    cin >> x;
    switch (x) {
      case 1 :
        ex01adj(adj1);
        break;
      case 2 :
        ex01inc(inc1);
        break;
      case 0 :
        break;
      default :
        cout << "Valor inválido" << endl;
    }
  }while(x != 0);

}
