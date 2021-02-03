#include <bits/stdc++.h>
using namespace std;

void input(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
}

int getParent(int i){
	return (i-1)/2;
}

int getLeft(int i){
	return 2*i+1;
}

int getRight(int i){
	return 2*i+2;
}

int getMin(std::vector<int> &heap, int &heapSize){
	if(heapSize <= 0){
		cout<<"Heap underflow"<<endl;
		return -1;
	}
	return heap[0];
}

void decreaseKey(std::vector<int> &heap, int index, int value){
	heap[index] = value;
	while(index!=0 && heap[getParent(index)]>heap[index]){
		swap(heap[index], heap[getParent(index)]);
		index = getParent(index);
	}
}
void heapify(std::vector<int> &heap, int index, int &heapSize){
	int left = getLeft(index);
	int right = getRight(index);
	int smallest = index;
	if(left < heapSize && heap[smallest] > heap[left]){
		smallest = left;
	}
	if(right < heapSize && heap[smallest] > heap[right]){
		smallest = right;
	}
	if(smallest != index){
		swap(heap[smallest], heap[index]);
		heapify(heap, smallest, heapSize);
	}
}

void extractMin(std::vector<int> &heap, int &heapSize){
	if(heapSize <= 0){
		cout<<"No item in heap"<<endl;
		return;
	}
	int value = heap[0];
	heap[0] = heap[heapSize-1];
	heapSize--;
	heapify(heap, 0, heapSize);
}

void deleteKey(std::vector<int> &heap, int index, int &heapSize){
	decreaseKey(heap, index, INT_MIN);
	extractMin(heap, heapSize);
}

void insertInHeap(std::vector<int> &heap, int data, int *heapSize, int capacity){
	if(capacity == *heapSize){
		cout<<"HeapFull"<<endl;
		return;
	}
	(*heapSize)++;
	int index = (*heapSize)-1;
	heap[index] = data;
	while(index!=0 && heap[getParent(index)]>heap[index]){
		swap(heap[index], heap[getParent(index)]);
		index = getParent(index);
	}
}

int main(int argc, char const *argv[]){
	input();
	int i,j,k,l,m,n;

	static int heapSize = 0;
	int capacity = 0;

	cin>>n>>capacity;

	std::vector<int> heap(capacity,0);

	for(i=0;i<n;i++){
		cin>>k;
		insertInHeap(heap, k, &heapSize, capacity);
	}

	for(i=0;i<heapSize;i++){
		cout<<heap[i]<<" ";
	}

	deleteKey(heap, 5, heapSize);

	cout<<endl;
	for(i=0;i<heapSize;i++){
		cout<<heap[i]<<" ";
	}
	return 0;
}