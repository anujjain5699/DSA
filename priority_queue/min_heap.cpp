#include<bits/stdc++.h>
using namespace std;

//Min Priority Queue 

class MinPriorityQueue{
    vector<int> pq;

    public:

    MinPriorityQueue(){
    }

    bool isEmpty(){
        return pq.size()==0;
    }

    int getSize(){
        return pq.size();
    }

    int getMin(){
        if(isEmpty())return -1;
        return pq[0];
    }

    void insert(int data){
        pq.push_back(data);

        int childIndex=pq.size()-1;
        while(childIndex>0){
            int parentIndex=(childIndex-1)/2;
            if(pq[childIndex] < pq[parentIndex]){
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

    int remove(){
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

            if(pq[minIndex] > pq[leftChildIndex]){
                minIndex=leftChildIndex;
            }
            if(rightChildIndex<pq.size() && pq[minIndex] > pq[rightChildIndex]){
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
    MinPriorityQueue minHeap;
    minHeap.insert(100);
    minHeap.insert(10);
    minHeap.insert(15);
    minHeap.insert(4);
    minHeap.insert(17);
    minHeap.insert(21);
    minHeap.insert(67);
    cout<<"size : "<<minHeap.getSize()<<endl;
    cout<<"minimum : "<<minHeap.getMin()<<endl;
    while(!minHeap.isEmpty()){
        cout<<minHeap.remove()<<" ";
    }
    return 0;
}