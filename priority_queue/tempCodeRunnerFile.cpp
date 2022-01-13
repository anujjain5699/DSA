#include<bits/stdc++.h>
using namespace std;

//Max Priority Queue 

class PriorityQueue{
    vector<int> pq;

    public:

    PriorityQueue(){
    }

    bool isEmpty(){
        return pq.size()==0;
    }

    int getSize(){
        return pq.size();
    }

    int getMax(){
        if(isEmpty())return -1;
        return pq[0];
    }

    void insert(int data){
        pq.push_back(data);

        int childIndex=pq.size()-1;
        while(childIndex>0){
            int parentIndex=(childIndex-1)/2;
            if(pq[childIndex] > pq[parentIndex]){
                int temp=pq[childIndex];
                pq[childIndex] = pq[parentIndex];
                pq[parentIndex] =temp;
            }
            else{
                break;
            }
            childIndex=parentIndex;
        }
    }

    int removeMax(){
        if(isEmpty())return -1;

        int ans=pq[0];
        pq[0]=pq[pq.size()-1];
        pq.pop_back();

        //down-heapify
        int parentIndex=0;
        int leftChildIndex=2*parentIndex+1;
        int rightChildIndex=2*parentIndex+2;

        while(leftChildIndex < pq.size()){

            int minIndex=parentIndex;

            if(pq[minIndex] < pq[leftChildIndex]){
                minIndex=leftChildIndex;
            }
            if(rightChildIndex<pq.size() && pq[minIndex] < pq[rightChildIndex]){
                minIndex=rightChildIndex;
            }
            if(minIndex == parentIndex)
            break;

            int temp=pq[minIndex];
            pq[minIndex]=pq[parentIndex];
            pq[parentIndex]=temp;

            parentIndex=minIndex;
            leftChildIndex=2*parentIndex+1;
            rightChildIndex=2*parentIndex+2;
        }
        return ans;
    }
};

int main(){
    PriorityQueue maxHeap;
    maxHeap.insert(100);
    maxHeap.insert(10);
    maxHeap.insert(15);
    maxHeap.insert(4);
    maxHeap.insert(17);
    maxHeap.insert(21);
    maxHeap.insert(67);
    cout<<"size : "<<maxHeap.getSize()<<endl;
    cout<<"minimum : "<<maxHeap.getMax()<<endl;
    while(!maxHeap.isEmpty()){
        cout<<maxHeap.removeMax()<<" ";
    }
    return 0;
}