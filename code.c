#include <stdio.h>

void merge(int arr[], int inicio, int meio, int fim) {// O(n)
  int i, j, k = 0;
  int n1 = meio - inicio + 1;    // O(1)
  int n2 = fim - meio;           // O(1)
  int esquerdo[n1], direito[n2]; // O(1)

  for (i = 0; i < n1; i++) {       // O(n)
    esquerdo[i] = arr[inicio + i]; // O(1)
  }
  for (j = 0; j < n2; j++) {        // O(n)
    direito[j] = arr[meio + 1 + j]; // O(1)
  }

  i = 0;      // O(1)
  j = 0;      // O(1)
  k = inicio; // O(1)

  while (i < n1 && j < n2) {         // O(n)
    if (esquerdo[i] <= direito[j]) { // O(1)
      arr[k] = esquerdo[i];          // O(1)
      i++;                           // O(1)
    } else {
      arr[k] = direito[j]; // O(1)
      j++;                 // O(1)
    }
    k++;
  }

  while (i < n1) {// O(n)
    arr[k] = esquerdo[i];// O(1)
    i++;// O(1)
    k++;// O(1)
  }

  while (j < n2) {// O(n)
    arr[k] = direito[j];// O(1)
    j++;// O(1)
    k++;// O(1)
  }
}

void mergeSort(int v[], int inicio, int fim) { // O(n**2)
  if (inicio < fim) {                          // O(1)
    int meio = (inicio + fim) / 2;             // O(1)

    mergeSort(v, inicio, meio);  // O(1)
    mergeSort(v, meio + 1, fim); // O(1)

    merge(v, inicio, meio, fim); // O(n)
  }
}

void reverse(int *arr, int inicio, int tamanhoArray) {// O(n)
  int aux;// O(1)
  if (inicio < tamanhoArray){ // O(1){
    aux = arr[inicio];// O(1)
    arr[inicio] = arr[tamanhoArray];// O(1)
    arr[tamanhoArray] = aux;// O(1)
    reverse(arr, inicio + 1, tamanhoArray - 1);// O(n)
  }
}

int main(void) {
  int qtdPartidas, qtdLinhas = 0; // O(1)
  int *placar;                    // O(1)

  scanf("%d %d", &qtdPartidas, &qtdLinhas); // O(1)

  if (qtdPartidas < 1 && qtdPartidas > 10000) // O(1)
    return 1;                                 // O(1)
  if (qtdLinhas < 1 && qtdLinhas > 500)
    return 1;                  // O(1)
  if (qtdLinhas > qtdPartidas) // O(1)
    return 1;                  // O(1)

  placar = malloc(qtdPartidas * sizeof(int)); // O(1)

  if (placar == NULL) {                        // O(1)
    printf("Falha na alocação de memória.\n"); // O(1)
    return 1;                                  // O(1)
  }

  for (int i = 0; i < qtdPartidas; i++) { // O(n)
    scanf("%d", &placar[i]);              // O(1)
  }

  mergeSort(placar, 0, qtdPartidas - 1); // O(1)
  reverse(placar, 0, qtdPartidas - 1);   // O(1)
  printf("\n\n");                        // O(1)

  for (int i = 0; i < qtdLinhas; i++) { // O(n)
    printf("%d\n", placar[i]);          // O(1)
  }

  free(placar); // O(1)
  return 0;     // O(1)
}