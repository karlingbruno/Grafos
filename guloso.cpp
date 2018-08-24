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
  int total = 0;
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
    total += menor;
    atual = linha ;
    zerar(adj,atual);
    linha = posicao;
    caminho[contador] = posicao + 1;
    contador++;
  }
  for(int j = 0; j < 5; j++){
    cout << "Caminho : " << caminho[j] << endl;
  }
  cout << "Total : " << total << endl;
  cout << "Pressione Enter " << endl;
  getchar();
  getchar();
  system("clear");
}
void ex01inc(int matriz[5][8]){
  int total = 0;
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
    total += menor;
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
  cout << "Total : " << total << endl;
  cout << "Pressione Enter " << endl;
  getchar();
  getchar();
  system("clear");
}
void ex02adj(int adj[7][7]){
  int total = 0;
  int caminho[4] = {1,0,0,0};
  int linha = 0;
  int menor = 0;
  int posicao = 0;
  int contador = 1;
  while(linha != 6){
    menor = 999999;
    posicao = 0;
    for(int j = 0; j < 7; j++){
      if(adj[linha][j] < menor && adj[linha][j] > 0){
        menor = adj[linha][j];
        posicao = j;
      }
    }
    total += menor;
    linha = posicao;
    caminho[contador] = posicao + 1;
    contador++;
  }
  for(int j = 0; caminho[j] != 0; j++){
    cout << "Caminho : " << caminho[j] << endl;
  }
  cout << "Total : " << total << endl;
  cout << "Pressione Enter " << endl;
  getchar();
  getchar();
  system("clear");
}
void ex02inc(int matriz[9][7]){
  int total = 0;
  int caminho[4] = {1,0,0,0};
  int menor;
  int linha;
  int coluna = 0;
  int contador = 1;
  while(coluna != 6){
    menor = 99999;
    for(int i = 0; i < 9; i++){
      if(matriz[i][coluna] < menor && matriz[i][coluna] > 0){
        menor = matriz[i][coluna];
        linha = i;
      }
    }
    total += menor;
    for(int j = 0; j < 7; j++){
      if(matriz[linha][j] == menor * -1 ){
        coluna = j;
        break;
      }
    }
    caminho[contador] = coluna + 1;
    contador ++;
  }
  for(int i = 0;caminho[i] != 0; i++){
    cout << "Caminho "<< caminho[i] << endl;
  }
  cout << "Total : " << total << endl;
  cout << "Pressione Enter " << endl;
  getchar();
  getchar();
  system("clear");
}
int main(){
                        /* 1   2   3   4   5*/
  int adj1[5][5] = /*1*/{{+00,+30,-15,+00,+20},
                  /*2*/  {-30,+00,-10,+50,+00},
                  /*3*/  {+15,+10,+00,+05,-10},
                  /*4*/  {+00,+50,-05,+00,-30},
                  /*5*/  {-20,+00,+10,+30,+00}};

                      /*a   b   c   d   e   f   g   h*/
int inc1[5][8] =/*1*/{{+20,+30,+00,-15,+00,+00,+00,+00},
                /*2*/ {+00,-30,+00,+00,-10,+00,+00,+50},
                /*3*/ {+00,+00,-10,+15,+10,+00,+05,+00},
                /*4*/ {+00,+00,+00,+00,+00,-30,-05,+50},
                /*5*/ {-20,+00,+10,+00,+00,+30,+00,+00}};


int adj2[7][7] =/*1*/{{+00,+02,+00,+06,+12,+00,+00},
                /*2*/ {-02,+00,+01,+00,+00,+05,+00},
                /*3*/ {+00,-01,+00,+00,+00,+00,+40},
                /*4*/ {-06,+00,+00,+00,+00,+04,+00},
                /*5*/ {-12,+00,+00,+00,+00,+00,+30},
                /*6*/ {+00,-05,+00,-04,+00,+00, +8},
                /*7*/ {+00,+00,-40,+00,-30, -8,-00}};

                      /*1    2   3   4   5   6   7 */
int inc2[9][7] =/*a*/{{+02,-02,+00,+00,+00,+00,+00},
                /*b*/ {+06,+00,+00,-06,+00,+00,+00},
                /*c*/ {+12,+00,+00,+00,-12,+00,+00},
                /*d*/ {+00,+01,-01,+00,+00,+00,+00},
                /*e*/ {+00,+05,+00,+00,+00,-05,+00},
                /*f*/ {+00,+00,+00,+04,+00,-04,+00},
                /*g*/ {+00,+00,+00,+00,+30,+00,-30},
                /*h*/ {+00,+00,+40,+00,+00,+00,-40},
                /*i*/ {+00,+00,+00,+00,+00, +8, -8}};
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
      case 3:
        ex02adj(adj2);
        break;
      case 4 :
        ex02inc(inc2);
        break;
      case 0 :
        break;
      default :
        cout << "Valor inválido" << endl;
    }
  }while(x != 0);

}
