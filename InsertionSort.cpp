#include <iostream>

using namespace std;

void InsertionSort(int v[], int t){
	for(int i = 0; i<t; i++){
		for(int j=i+1; j>0; j--){
			if(v[j]<v[j-1]) swap(v[j], v[j-1]);
			else break;		
		}	
	}
}

int main(){
	int v[] = {9, 8, 7, 6, 5, 4, 3, 2, 1};
	InsertionSort(v, 9);
	for(int i=0; i<9; i++) cout<<v[i]<<" ";
	return 0;
}
