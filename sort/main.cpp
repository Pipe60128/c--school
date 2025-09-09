#include <iostream>
#include "Busqueda.cpp"
using namespace std;

// FUNCTION TO CREATE AN ARRAY BY TEH USER INPUT
int* crateArray(int n){
    int* array = new int[n];
    for (int i =0; i<n; i++){
        cout<<"Enter a number"<<endl;
        cin>>array[i];
    }
    return array;
}
int main() {
    // CASES TESTS
    /*
    */
    cout<<"TEST CASES"<<endl;
    cout<<"------------------"<<endl;
    cout<<"lineal search"<<endl;
    int array[]={1,2,3,4,5,6,7,8};
    int size= sizeof(array)/sizeof(array[0]);
    int target=5;
    cout<<"The target is "<<target<<endl;
    Busqueda :: printArray(array,size);
    int index = Busqueda :: binarySearch(array,size,target);
    if (index != -1){
        cout<<"Number found in index = "<<index<<endl;
    } else {
        cout<<"Number not found"<<endl;
    }
    cout<<"------------------"<<endl;
    cout<<"binary search"<<endl;
     int array2[]={1,2,3,4,5,6,7,8};
    int size2= sizeof(array2)/sizeof(array2[0]);
    int target2=5;
    cout<<"The target is "<<target2<<endl;
    Busqueda :: printArray(array2,size2);
    int index2 = Busqueda :: binarySearch(array2,size2,target2);
    if (index2 != -1){
        cout<<"Number found in index = "<<index2<<endl;
    } else {
        cout<<"Number not found"<<endl;
    }
    cout<<"------------------"<<endl;
    cout<<"merge sort"<<endl;
    int array3[]={5,3,8,4,2};
    int size3= sizeof(array3)/sizeof(array3[0]);
    cout<<"Array before sort"<<endl;
    Busqueda :: printArray(array3,size3);
    cout<<"Array after sort"<<endl; 
    Busqueda :: mergeSort(array3,size3);
    Busqueda :: printArray(array3,size3);
    cout<<"------------------"<<endl;
    cout<<"insercion sort"<<endl;
    int array4[]={5,3,8,4,2};
    int size4= sizeof(array4)/sizeof(array4[0]);
    cout<<"Array before sort"<<endl;
    Busqueda :: printArray(array4,size4);
    cout<<"Array after sort"<<endl; 
    Busqueda :: insercionSort(array4,size4);
    Busqueda :: printArray(array4,size4);
    cout<<"------------------"<<endl;
    cout<<"insertcion sort"<<endl;
    int array5[]={5,3,8,4,2};
    int size5= sizeof(array5)/sizeof(array5[0]);
    cout<<"Array before sort"<<endl;
    Busqueda :: printArray(array5,size5);
    cout<<"Array after sort"<<endl; 
    Busqueda :: insertcionSort(array5,size5);
    Busqueda :: printArray(array5,size5);
    cout<<"------------------"<<endl;
    cout<<"bubble sort"<<endl;
    int array6[]={5,3,8,4,2};
    int size6= sizeof(array6)/sizeof(array6[0]);
    cout<<"Array before sort"<<endl;
    Busqueda :: printArray(array6,size6);
    cout<<"Array after sort"<<endl; 
    Busqueda :: bubbleSort(array6,size6);
    Busqueda :: printArray(array6,size6);
    cout<<"------------------"<<endl;

    //BEGIN MENU
    int menu = 0;
    while (menu != 3){
        cout<<"___Menu___"<<endl;
        cout<<"1-(Search a number)\n2-(Sort a array)\n3-(Exit)"<<endl;
        cin>>menu;
        if (menu == 1){ //SEARCH A NUMBER 
            int target;
            int searchMenu = 0;
            int size;
            cout<<"You selected search a number"<<endl;
            cout <<"Do you want a binary secarh or a lineal search\n1(binary)\n2(lineal)"<<endl;
            cin>>searchMenu;
            int array[]={1,2,3,4,5,6,7,8};
            size= sizeof(array)/sizeof(array[0]);//CALCULATE ZIZE OF THE ARRAY 
            cout<<"the size of the array it is "<<size<<endl;
            cout<<"Number to find"<<endl;
            cin>>target;
            cout<<"The array that contains the number you want to find is:"<<endl;
            Busqueda :: printArray(array,size);
            if (searchMenu == 1){
                cout<<"You selected binary search"<<endl;
                int index = Busqueda :: binarySearch(array,size,target);
                if (index != -1){
                    cout<<"Number found in indesx = "<<index<<endl;
                } else {
                    cout<<"Number not found"<<endl;
                    }
            } else {
                cout<<"You selected lineal search"<<endl;
                int index = Busqueda :: linealSearch(array,size,target);
                if (index != -1){
                    cout<<"Number found in indesx = "<<index<<endl;
                } else {
                    cout<<"NUnmber not found"<<endl;
                    }
            }
            
        } else if (menu ==2){ //SORT ARRAY
            int sortMenu = 0;
            cout<<"You selected sort a array"<<endl;
            cout<<"Do you want to use a bse case or type your array\n1(use base case)\n2(type your array) "<<endl;
            cin>>sortMenu;
            if (sortMenu == 1){
                int sortType = 0;
                cout<<"What type of sort do you want to use?\n1(Bubble sort)\n2(Insertion sort)\n3(Merge sort)\n4(Insercion sort)"<<endl;
                cin>>sortType;
                int array2[]={5,3,8,4,2};
                int size2= sizeof(array2)/sizeof(array2[0]);
                cout<<"Array before sort"<<endl;
                Busqueda :: printArray(array2,size2);
                if (sortType == 1){
                    cout<<"You selected bubble sort"<<endl;
                    Busqueda :: bubbleSort(array2,size2);//bubble algorithm
                } else if (sortType == 2){
                    cout<<"You selected insertion sort"<<endl;
                    Busqueda :: insertcionSort(array2,size2);//insertion algorithm
                } else if (sortType == 3){
                    cout<<"You selected merge sort"<<endl;
                    Busqueda :: mergeSort(array2,size2);//merge algorithm
                } else if  (sortType == 4){
                    cout<<"You selected insercion sort"<<endl;
                    Busqueda :: insercionSort(array2,size2);//exchange algorithm
                } else {
                    cout<<"Invalid option"<<endl;
                }
                cout<<"Array after sort"<<endl;
                Busqueda :: printArray(array2,size2);
            } else {
                int n;
                cout<<"How many numbers do you want to sort?"<<endl;
                cin>>n;
                int* array2 = crateArray(n);
                cout<<"Array before sort"<<endl;
                Busqueda :: printArray(array2,n);
                int sortType = 0;
                cout<<"What type of sort do you want to use?\n1(Bubble sort)\n2(Insertion sort)\n3(Merge sort)\n4(Insercion sort)"<<endl;
                cin>>sortType;
                if (sortType == 1){
                    cout<<"You selected bubble sort"<<endl;
                    Busqueda :: bubbleSort(array2,n);//bubble algorithm
                } else if (sortType == 2){
                    cout<<"You selected insertion sort"<<endl;
                    Busqueda :: insertcionSort(array2,n);//insertion algorithm
                } else if (sortType == 3){
                    cout<<"You selected merge sort"<<endl;
                    Busqueda :: mergeSort(array2,n); //merge algorithm
                } else if  (sortType == 4){
                    cout<<"You selected insercion sort"<<endl;
                    Busqueda :: insercionSort(array2,n); //exchange algorithm
                } else {
                    cout<<"Invalid option"<<endl;
                }
                cout<<"Array after sort"<<endl;
                Busqueda :: printArray(array2,n);
            }
            
        }
    
    }
    cout<<"\n\n\nBYE SEE YOU SOON"<<endl;
return 0;
}