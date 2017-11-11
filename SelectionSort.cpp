
#include <iostream>

using namespace std;

void SelectionSort(int v[], int t){	
	for(int i=0; i<t; i++){
		int min = i;
		for(int j=i; j<t; j++){
			if(v[j]<v[min]) min = j; 		
		}
		swap(v[i], v[min]);
	}
}

int main(){
	int v[] = {9, 8, 7, 6, 5, 4, 3, 2, 1};
	SelectionSort(v, 9);
	for(int i=0; i<9; i++) cout<<v[i]<<" ";
	return 0;
}
