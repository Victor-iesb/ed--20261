#include "ordenacao.h"

void bubble_sort(int arr[], int n) {

    int temp;
    for (int i = 0; i < n - 1; i++) {

        for (int j = 0; j < n - i - 1; j++) {

            if (arr[j] > arr[j + 1]) {
               
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;

            }
        }
    }
}

void selection_sort(int arr[], int n) {

    int min_idx, temp;

    for (int i = 0; i < n - 1; i++) {

        min_idx = i;

        for (int j = i + 1; j < n; j++) {

            if (arr[j] < arr[min_idx]) {

                min_idx = j;

            }
        }
       
        temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;

    }
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

void quick_sort(int arr[], int inicio, int fim) {

    if (inicio < fim) {

        int pi = particiona(arr, inicio, fim);
        
        quick_sort(arr, inicio, pi - 1);
        quick_sort(arr, pi + 1, fim);
    }
}