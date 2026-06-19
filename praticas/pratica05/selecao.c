#include "selecao.h"

int linear_search(int arr[], int n, int target) {

    for (int i = 0; i < n; i++) {

        if (arr[i] == target) {

            return i;
        }
    }

    return -1; 
}

int particiona(int arr[], int inicio, int fim) {

    int pivo = arr[fim];
    int i = (inicio - 1);
    int temp;

    for (int j = inicio; j <= fim - 1; j++) {

        if (arr[j] < pivo) {

            i++;
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    
    temp = arr[i + 1];
    arr[i + 1] = arr[fim];
    arr[fim] = temp;
    
    return (i + 1);
}

int quick_select(int arr[], int inicio, int fim, int k) {

    if (inicio <= fim) {
        
        int pi = particiona(arr, inicio, fim);
        if (pi == k) {

            return arr[pi];
        } 
    
        else if (pi > k) {

            return quick_select(arr, inicio, pi - 1, k);

        } else {

            return quick_select(arr, pi + 1, fim, k);
        }
    }

    return -1; 
}