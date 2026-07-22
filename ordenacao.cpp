//------------------ QuickSort
#include <stdio.h>

// Função para trocar dois elementos de posição no array
void trocar(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Função para particionar o array e retornar o índice do pivô
int particionar(int array[], int inicio, int fim) {
    int pivo = array[fim]; // Escolhendo o último elemento como pivô
    int i = (inicio - 1); // Índice do menor elemento

    for (int j = inicio; j <= fim - 1; j++) {
        // Se o elemento atual for menor ou igual ao pivô
        if (array[j] <= pivo) {
            i++; // Incrementa o índice do menor elemento
            trocar(&array[i], &array[j]);
        }
    }
    trocar(&array[i + 1], &array[fim]);
    return (i + 1);
}

// Função principal do Quicksort
void quicksort(int array[], int inicio, int fim) {
    if (inicio < fim) {
        // Obtém o índice do pivô
        int indice_pivo = particionar(array, inicio, fim);

        // Ordena os elementos antes e depois do pivô recursivamente
        quicksort(array, inicio, indice_pivo - 1);
        quicksort(array, indice_pivo + 1, fim);
    }
}

int main() {
    int array[] = {10, 7, 8, 9, 1, 5};
    int tamanho = sizeof(array) / sizeof(array[0]);

    printf("Array original:\n");
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", array[i]);
    }

    quicksort(array, 0, tamanho - 1);

    printf("\n\nArray ordenado:\n");
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    return 0;
}
