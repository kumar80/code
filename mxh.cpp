#include <bits/stdc++.h>
using namespace std;
int len = 0 ;
int heap[50000];
void insertKey(int key){
    int i = len;
    heap[i]=key;
    len++;
    while(i && heap[(i-1)/2] > heap[i]) {
        swap(heap[(i-1)/2], heap[i]);
        i=(i-1)/2;
    }
}
void decreaseKey(int i, int val){
    heap[i] = val;
    while(i && heap[(i-1)/2] > heap[i]) {
        swap(heap[(i-1)/2], heap[i]);
        i=(i-1)/2;
    }
}
void minHeapify(int i){
    int l = 2*i+1;
    int r = 2*i+2;
    int smallest = i;
    if(l<len && heap[l]<heap[i])
        smallest = l;
    if(r<len && heap[r]<heap[l])
        smallest = r;
    if(smallest !=i){
        swap(heap[i],heap[smallest]);
        minHeapify(smallest);
    }
}
void getMin(){
    heap[0] = heap[len-1];
    minHeapify(0);
}
void removeKey(int key){

}
int main(){

}