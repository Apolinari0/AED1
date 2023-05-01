#include <stdio.h>
#include <stdlib.h>
#define MAX 20000

// Fun��o para ajustar o heap m�ximo
void maxHeapify(int arr[], int size, int root) {
    int largest = root; // Inicializa o maior elemento como raiz
    int left = 2 * root + 1; // �ndice do filho esquerdo
    int right = 2 * root + 2; // �ndice do filho direito

    // Verifica se o filho esquerdo � maior que a raiz
    if (left < size && arr[left] > arr[largest]) {
        largest = left;
    }

    // Verifica se o filho direito � maior que a raiz ou o filho esquerdo
    if (right < size && arr[right] > arr[largest]) {
        largest = right;
    }

    // Se o maior elemento n�o for a raiz, troca-os
    if (largest != root) {
        int temp = arr[root];
        arr[root] = arr[largest];
        arr[largest] = temp;

        // Chama recursivamente para ajustar o sub-heap afetado
        maxHeapify(arr, size, largest);
    }
}

// Fun��o principal do HeapSort
void heapSort(int arr[], int size) {
    // Constr�i um heap m�ximo a partir do array
    for (int i = size / 2 - 1; i >= 0; i--) {
        maxHeapify(arr, size, i);
    }

    // Extrai os elementos um por um do heap e os coloca em ordem crescente
    for (int i = size - 1; i > 0; i--) {
        // Move a raiz (maior elemento) para o final do array
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        // Chama a fun��o maxHeapify na submatriz reduzida
        maxHeapify(arr, i, 0);
    }
}



int main() {
    int i;
    int arr[MAX];

    for(i=0;i<MAX;i++){
        arr[i] = rand();
    }
    int size = sizeof(arr) / sizeof(arr[0]);

    heapSort(arr, size);


    return 0;
}

