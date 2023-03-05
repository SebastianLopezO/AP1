#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <locale>
#include <vector>
#include <windows.h>
#include <fstream>

using namespace std;

void swap(int &a,int &b){
    int aux = a;
    a = b;
    b = aux;
}

int Partition(vector<int>&array,int start,int end,bool order){
	int piv=array[start];
	int i=start+1;
	for(int j=i;j<=end;j++){
		if(order){
			if(array[j]<piv){
				swap(array[i],array[j]);
				i++;
			}
		}else{
			if(array[j]>piv){
				swap(array[i],array[j]);
				i++;
			}
		}

	}
	swap(array[start],array[i-1]);
	return i-1;
}

void QuickSort(vector<int>&array,int start,int end,bool order){
	if(start<end){
		int piv=Partition(array,start,end,order);
		QuickSort(array,start,piv-1,order);
		QuickSort(array,piv+1,end,order);
	}
}


void Imprimir(vector<int>&array){
	/* Impresión de los datos de la base de datos. */
    for(int i=0;i<array.size();i++){
		cout<<array[i]<<endl;
	}
}

int main(){
	vector<int> nums={10,2,3,5,1,4,9,6,7,8};
	QuickSort(nums,0,nums.size()-1,false);
	Imprimir(nums);
}

