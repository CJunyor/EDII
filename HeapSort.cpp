#include <iostream>

void to_heap(int v[], int t){
    int k = t/2;
    for(int i=0; i<k; i++){
        for(int j = t-1; j>1; j--){
            if(v[j]>v[j/2-1]) swap(v[j], v[j/2-1]);
        }
        if(v[1]>v[0]) swap(v[0], v[1]);
    }
}

void heap_sort(int v[], int t){
    for(int i = t; i>1; i--){
        to_heap(v, i);
        swap(v[0], v[i-1]);
    }
}

int main()
{
    int b[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int w[] = {9, 8, 7, 6, 5, 4, 3, 2, 1};
    to_heap(b, 9);
    heap_sort(b, 9);
    for(int i = 0; i<9; i++) cout<<b[i]<<" ";
	return 0;
}
