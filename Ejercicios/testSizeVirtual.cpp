#include <iostream>
#include <stdlib.h>
#include <string>

using namespace std;

int SizeVirtual(string array[10]){
	int size=0;
	for(int i=0;i<10;i++){
		if(array[i]!=""){
			size++;
		}
	}
	return array.size();
}

int main(){
	string nums[10]={"hola"};
	int size;
	size=SizeVirtual(nums);
	cout<<size<<endl;
}