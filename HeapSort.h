#define Left(i) (2*i+1)
#define Right(i) (2*i+2)
#define Parent(i) ((i-1)/2)

template <class T> void max_heapify(T heap[],int index,int size)
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

template <class T> void build_max_heap(T heap[],int size)
{
    for(int i=(size/2);i>=0;i--)
        max_heapify(heap,i,size);
}

template <class T> void sort_asc(T heap[],int size)
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

template <class T> void min_heapify(T heap[],int index,int size)
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

template <class T> void build_min_heap(T heap[],int size)
{
    for(int i=(size/2);i>=0;i--)
        min_heapify(heap,i,size);
}

template <class T> void sort_desc(T heap[],int size)
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

