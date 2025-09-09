#include "Busqueda.h"
#include <iostream>
using namespace std;


void Busqueda::printArray(int array[],int size){
    cout <<"[";
    for (int i=0;i<size;i++){
        cout<<array[i]<<" ";
    }
    cout <<"]"<<std::endl;
}

int Busqueda::linealSearch(int array[],int size, int target){
    for (int i=0;i<size;i++){
        if(array[i]==target){
            return i;
        }
    }
    return -1;
}

int Busqueda :: binarySearch(int array[], int size, int target){
    int start=0;
    int end= size-1;
    while(start<= end){
        int mid=(start+end)/2;
        if(array[mid]==target){
            return mid;
        }
        if(array[mid]>target){
            end = mid-1;
        }else{
            start = mid+1;
        }

        
    }
    return -1;

};

void Busqueda :: insercionSort(int array[], int size){
    int aux;
    for (int i = 1; i < size; i++) {      
        int j = i;
        aux = array[i];                   
        while (j > 0 && aux < array[j - 1]) {
            array[j] = array[j - 1];
            j--;
        }
        array[j] = aux;                  
    }
}

void Busqueda :: bubbleSort(int array[], int size){
    int temp = 0;
    bool swap= true;
    for (int i=0;i < size - 1;i++){
        swap = false;
        for(int j = 0; j < size - i - 1; j++){
            if(array[j] > array[j+1]){
                temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
                swap = true;
            }
        }
    }

};

void Busqueda ::insertcionSort(int array[], int size){
    int j,aux;
    for (int i=1; i<size;i++){
        j=i;
        aux=array[i];
        while(j>0 && aux<array[j-1]){
            array[j]= array[j-1];
            j--;
        }
        array[j]=aux;
    }

}

void Busqueda :: mergeSort(int arr[], int size){
    int* temp = new(nothrow) int[size];
    mergeSort(arr,0,size-1,temp);
    
    

}

void Busqueda :: mergeSort(int arr[], int left, int right, int aux []){
    if (left<right){
        int mid = (left + right)/2 ;
        mergeSort(arr,left,mid,aux);
        mergeSort(arr,mid+1,right,aux);
        merge(arr,left,mid,right, aux);
    }
    
}

void Busqueda :: merge(int arr[], int left, int mid, int right, int aux []){
    int i = left;
    int j = mid + 1;
    int k = left;

    
    while (i <= mid && j <= right){
        if (arr[i]<arr[j]){
            aux[k] = arr[i];
            i++;
        } else {
            aux[k] = arr[j];
            j++;
        }
         k++;
    }
       
        if(i > mid){
            for (j; j<=right; j++){
                aux[k]=arr[j];
                k++;
            }
        } else {
            for (i; i <= mid; i++){
                aux[k]=arr[i];
                k++; 
            }
        }
        

        for(int m = left; m <= right; m++){
            arr[m]=aux[m];
        }

}