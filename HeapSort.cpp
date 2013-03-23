#include "HeapSort.h"

void max_heapify(T heap[],int index,int size)
{
    int largest=index;
    int l=Left(index);
    int r=Right(index);
    if(l<size && heap[l]>heap[largest]) largest=l;
    if(r<size && heap[r]>heap[largest]) largest=r;
    if(largest!=index)
    {
        int temp=heap[index];
        heap[index]=heap[largest];
        heap[largest]=temp;
        max_heapify(heap,largest,size);
    }
}

void build_max_heap(T heap[],int size)
{
    for(int i=(size/2);i>=0;i--)
        max_heapify(heap,i,size);
}

void sort_asc(T heap[],int size)
{
    build_max_heap(heap,size);
    for(int i=size-1;i>0;i--)
    {
        int temp=heap[0];
        heap[0]=heap[i];
        heap[i]=temp;
        size--;
        max_heapify(heap,0,size);
    }
}

void min_heapify(T heap[],int index,int size)
{
    int largest=index;
    int l=Left(index);
    int r=Right(index);
    if(l<size && heap[l]<heap[largest]) largest=l;
    if(r<size && heap[r]<heap[largest]) largest=r;
    if(largest!=index)
    {
        int temp=heap[index];
        heap[index]=heap[largest];
        heap[largest]=temp;
        max_heapify(heap,largest,size);
    }
}

void build_min_heap(T heap[],int size)
{
    for(int i=(size/2);i>=0;i--)
        min_heapify(heap,i,size);
}

void sort_desc(T heap[],int size)
{
    build_min_heap(heap,size);
    for(int i=size-1;i>0;i--)
    {
        int temp=heap[0];
        heap[0]=heap[i];
        heap[i]=temp;
        size--;
        min_heapify(heap,0,size);
    }
}


