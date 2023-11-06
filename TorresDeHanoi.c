//João Victor Zanatta Nascimento
//RA: N0233B4

#include<stdio.h>
#include<math.h>

//função para imprimir as torres
void imprimir(int numero,int torreA[], int torreB[], int torreC[]){
  int i=1;
  for(i=0; i<numero; i++){
    printf("\n       %i   %i   %i",torreA[i],torreB[i],torreC[i]);
  }
  printf("\n      -----------");
  printf("\ntorres A   B   C\n\n");
}

//função pegar_disco
//seleciona a posição do menor disco da torre, ou seja, aquele que esta mais acima
int pDisco(int numero, int vet[]){
  int i, x = 0;
  for(i=0; i<numero; i++){
    if (vet[i]!=0){
    x=1;
    break;
    }
  }
  if(x==0){
    i=numero-1;
  }
  return i;
}

//serve para selecionar a posição vazia mais proxima a base da torre
int cDisco(int numero, int vet[]){
  int i, x = 0;
  for(i=0; i<numero; i++){
    if (vet[i]!=0){
    x=1;
    break;
    }
  }
  if (i!=0){
    i=i-1;
  }
  if(x==0){
    i=numero-1;
  }
  return i;
}

//função para trocar os discos de lugar
//*movimentos para contar o numero de movimentos, como não podia retornar o numero, o coloquei como ponteiro
//n = numero pois eu preciso alerar o valor de n para executar as trocas entre as torres, e como eu preciso de numero com o mesmo valor sempre paras funçoes pDisco e cDisco, foi criada uma variavel de mesmo valor
//as variaveis de tipo int são as responsaveis por fazer as trocas dentro da impressao das torres, ja as variaveis tipo char, são aquelas que uso para escrever o passo a passo
//as torres foram add duas vezes na função pois com as "origem, destino e auxiliar" eu faço as trocas de posição dos discos, se usasse elas para fazer as impressões, as mesmas viriam em posiçoes erradas, então adicionei "torreA, B e C" e como elas não trocaram de posição, apenas os valores de suas posiçoes internas, as impressões vem corretas
void trocar(int n, int *movimentos, int numero, int origem[numero], int destino[numero], int auxiliar[numero], char charOrigem, char charDestino, char charAuxiliar, int torreA[numero], int torreB[numero], int torreC[numero]) {
  int i;
  if(n==1){ 
    destino[cDisco(numero, destino)]=origem[pDisco(numero, origem)];
    origem[pDisco(numero, origem)]=0;
    (*movimentos)++;;
    printf("Movimento = %d\n",*movimentos);
    printf("Mova o disco 1:\nTorre %c para Torre %c\n",charOrigem ,charDestino);
    imprimir(numero, torreA, torreB, torreC);
    return;
  }

  trocar(n-1, movimentos, numero,origem,auxiliar,destino,charOrigem,charAuxiliar,charDestino, torreA, torreB, torreC);

  destino[cDisco(numero, destino)]=origem[pDisco(numero, origem)];
  origem[pDisco(numero, origem)]=0;
  (*movimentos)++;
  printf("Movimento = %d\n",*movimentos);
  printf("Mova o disco %d:\nTorre %c para Torre %c\n",n,charOrigem,charDestino);
  imprimir(numero, torreA, torreB, torreC);

  trocar(n-1, movimentos, numero,auxiliar,destino,origem,charAuxiliar,charDestino,charOrigem, torreA, torreB, torreC);
}


//----------------------------------------------------------------------------
int main(){
  int i, numero, movimentos = 0; //movimentos minimo = (2^discos)-1

  printf("\nEntre com a quantidades de discos: ");
  scanf("%d",&numero);
  printf("Quantidade minima de movimentos: %.0f\n", pow(2,numero)-1);

  int torreA[numero+1], torreB[numero+1], torreC[numero+1];

  for (i=0; i<numero; i++){
    torreA[i]=i+1;
    torreB[i]=0;
    torreC[i]=0;
  }

  imprimir(numero, torreA, torreB, torreC);
  int n = numero;
  trocar(n, &movimentos, numero, torreA, torreB, torreC, 'A','B','C', torreA, torreB, torreC);

  system("pause");
}
