#include <iostream>

using namespace std;

class Heap
{
private:
    int *My_array;
    int size;
    int length;

public:
    Heap(int size)
    {
        this->size = size;
        My_array = new int(size);
        length = 0;
    }

    void Heap_insertion_max_heap(int value)
    {
        if (size == length)
        {
            cout << "The heap is full" << endl;
            return;
        }

        My_array[length] = value;
        heapify_up_max(length);
        length++;
    }

    void Min_heap_insertion(int value)
    {
        if (size == length)
        {
            cout << "The heap is full" << endl;
            return;
        }

        My_array[length] = value;
        heapify_up_min(length);
        length++;
    }

    void heapify_up_max(int index)
    {
        if (index <= 0)
            return;
        int parent = (index - 1) / 2;
        if (My_array[index] > My_array[parent])
        {
            swap(My_array[index], My_array[parent]);
            heapify_up_max(parent);
        }
    }

    void heapify_up_min(int index)
    {
        if (index <= 0)
            return;
        int parent = (index - 1) / 2;
        if (My_array[index] < My_array[parent])
        {
            swap(My_array[index], My_array[parent]);
            heapify_up_min(parent);
        }
    }

    void heap_display()
    {
        if (length == 0)
        {
            cout << "the heap is empty" << endl;
            return;
        }

        for (int i = 0; i < length; i++)
        {
            cout << My_array[i] << " ";
        }
    }
    void heapify_down_min(int index)
    {
        int smallest = index;
        int leftChild = (2 * index) + 1;
        int rightChild = (2 * index) + 2;

        // Assume 'length' is the number of elements in the heap
        if (leftChild < length && My_array[leftChild] < My_array[smallest])
        {
            smallest = leftChild;
        }

        if (rightChild < length && My_array[rightChild] < My_array[smallest])
        {
            smallest = rightChild;
        }

        // If the smallest is not the current index
        if (smallest != index)
        {
            swap(My_array[index], My_array[smallest]);
            heapify_down_min(smallest);
        }
    }

    void heapify_down_max(int index) 
{
    int largest = index;
    int leftChild = (2 * index) + 1;
    int rightChild = (2 * index) + 2;

    // Assume 'length' is the number of elements in the heap
    if (leftChild < length && My_array[leftChild] > My_array[largest]) {
        largest = leftChild;
    }

    if (rightChild < length && My_array[rightChild] > My_array[largest]) {
        largest = rightChild;
    }

    // If the largest is not the current index
    if (largest != index) {
        swap(My_array[index], My_array[largest]);
        heapify_down_max(largest);
    }
}

};

int main(void)
{
    Heap obj(5);
    obj.Heap_insertion_max_heap(1);
    obj.Heap_insertion_max_heap(2);
    obj.Heap_insertion_max_heap(3);
    obj.Heap_insertion_max_heap(4);
    obj.Heap_insertion_max_heap(5);
    obj.heap_display();

    Heap obj2(6);
    obj2.Min_heap_insertion(4);
    obj2.Min_heap_insertion(5);
    obj2.Min_heap_insertion(3);
    obj2.Min_heap_insertion(2);
    obj2.Min_heap_insertion(1);
    obj2.Min_heap_insertion(0);
    cout << "\n"
         << endl;
    obj2.heap_display();
    return 0;
}