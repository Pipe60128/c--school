#ifndef BUSQUEDA_H
#define BUSQUEDA_H

class Busqueda{
    private:
    //PRIVATE METHODS
    static void mergeSort(int arr[],int left, int right, int aux[]  );
    static void merge(int arr[], int left, int mid, int right, int aux[]);
    static void quickSort(int arr[], int left, int right);
    static int partition(int arr[], int left, int right);
    public:
    //PRINT ARRAY METHOD
    static void printArray(int array[],int size);
    //SEARCH METHODS
    static int linealSearch(int array[], int size, int target);
    static int binarySearch(int array[], int size, int target);
    //SORT METHODS
    static void selectionSort(int array[], int size);
    static void swapSort(int array[], int size);
    static void bubbleSort(int array[], int size);
    static void insertcionSort(int array[], int size);
    static void mergeSort(int array[], int size);
    static void quickSort(int array[], int size);


};

#endif //BUSQUEDA_H