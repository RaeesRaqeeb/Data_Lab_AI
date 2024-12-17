#include <iostream>

using namespace std;

class HashTable 
{
private:
    int* table;
    int size;
    int count;
    int min_range;
    int max_range;

    int hash_function(int value) 
    {
        return value % size;
    }

    int is_prime(int value)
    {
        int i=1;
        int factor_count=0;
        while(i<=value)
        {
            if(value%i == 0)
                factor_count+=1;
            i++;
        }
        if(factor_count==2)
            return 1;
        else 
            return 0;
    }

    void rehash()
    {
        int new_size = (size * 2);
        while(is_prime(new_size)!=1)
            new_size++;
        int* new_table = new int[new_size];
        for (int i = 0; i < new_size; i++) {
            new_table[i] = -1;
        }

        for (int i = 0; i < size; i++) {
            if (table[i] != -1) {
                int index = table[i] % new_size;
                while (new_table[index] != -1) {
                    index = (index + 1) % new_size;
                }
                new_table[index] = table[i];
            }
        }

        delete[] table;
        table = new_table;
        size = new_size;
    }
public:
    HashTable(int size_passed, int min_range, int max_range) 
    {
        size = size_passed;
        this->min_range = min_range;
        this->max_range = max_range;
        table = new int[size];
        count = 0;
        for (int i = 0; i < size; i++) {
            table[i] = -1;
        }
    }

    ~HashTable() 
    {
        delete[] table;
    }

    void insertion(int value) 
    {
        if (value < min_range || value > max_range) 
        {
            cout << "value out of range" << endl;
            return;
        }

        if ((float)count / size >= 0.7)
         {
            rehash();
        }

        int index = hash_function(value);
        while (table[index] != -1) 
        {
            index = (index + 1) % size;
        }
        table[index] = value;
        count++;
    }

    void searching(int value)
    {
        if(value<min_range || value>max_range)
        {
            cout<<"value out of range"<<endl;
            return;
        }
        if(count == 0)
        {
            cout << "The hash table is empty" << endl;
            return;
        }

        int value_index = hash_function(value);
        int start_index = value_index;

        while(table[value_index] != -1)
        {
            if(table[value_index] == value)
            {
                cout << "Value is present in the hash table" << endl;
                return;
            }
            value_index = (value_index + 1) % size;
            if(value_index == start_index)
            {
                break;
            }
        }

        cout << "Value is not present in the hash table" << endl;
    }
    void display() 
    {
        for (int i = 0; i < size; i++) 
        {
            if (table[i] != -1) 
            {
                cout << "Index " << i << ": " << table[i] << endl;
            }
            else 
            {
                cout << "Index " << i << ": " << "Empty" << endl;
            }
        }
    }
};

int main()
{
    int size, min_range, max_range;
    cout << "Enter the size of the hash table: ";
    cin >> size;
    cout << "Enter the minimum range of values: ";
    cin >> min_range;
    cout << "Enter the maximum range of values: ";
    cin >> max_range;

    HashTable obj(size, min_range, max_range);

    // for (int i = min_range; i <= max_range; i += 5) {
    //     hashTable.insertion(i);
    // }

    obj.insertion(10);
    obj.insertion(23);
    obj.insertion(24);
    obj.insertion(26);
    obj.insertion(27);
    obj.insertion(28);
    obj.insertion(29);
    obj.insertion(32);
    obj.insertion(35);
    obj.insertion(31);

    cout << "Hash table after insertions:" << endl;
    hashTable.display();



    cout<<"Searching :";
    int value;
    cin>>value;
    hashTable.searching(value);

    return 0;
}