#ifndef SORTS_H
#define SORTS_H

#include <vector>

template <typename T> 
class Sorts 
{
    public:
        void ordenaSeleccion(std::vector<T>&);
        void ordenaBurbuja(std::vector<T>&);
        void ordenaMerge(std::vector<T>&);
        int busqSecuencial(std::vector<T>, T);
        int busqBinaria(std::vector<T>, T);

    private:
        void swap(std::vector<T>&, int, int);
        void mergeHelper(std::vector<T>&, int, int);
        void merge(std::vector<T>&, int, int, int);
};

template<typename T>
int Sorts<T>::busqBinaria(std::vector<T> sorted, T value)
{
    int low = 0;
    int high = sorted.size() - 1;
    while (low <= high)
    {
        int mid = (high + low) / 2;
        if (sorted[mid] == value)
        {
            return mid;
        }
        else if (sorted[mid] > value)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return -1;
}

template<typename T>
int Sorts<T>::busqSecuencial(std::vector<T> sorted, T value)
{
    for (int i = 0; i < sorted.size(); i++)
    {
        if (sorted[i] == value)
        {
            return i;
        }
    }
    return -1;
}

template<typename T>
void Sorts<T>::swap(std::vector<T>& source, int i, int j)
{
    T aux = source[i];
    source[i] = source[j];
    source[j] = aux;
}

template<typename T>
void Sorts<T>::ordenaSeleccion(std::vector<T>& source)
{
    for (int i = 0; i < source.size(); i++)
    {
        int indexMin = i;
        for (int j = i + 1; j < source.size(); j++)
        {
            if (source[j] < source[indexMin])
            {
                indexMin = j;
            }
        }
        swap(source, i, indexMin);
    }
}

template<typename T>
void Sorts<T>::ordenaBurbuja(std::vector<T>& source)
{
    bool noSwaps = false;
    while (!noSwaps)
    {
        int swaps = 0;
        for (int i = 1; i < source.size(); i++)
        {
            if (source[i] < source[i - 1])
            {
                swap(source, i, i - 1);
                swaps++;
            }
        }
        if (swaps == 0)
        {
            noSwaps = true;
        }
    }
}

template<typename T>
void Sorts<T>::ordenaMerge(std::vector<T>& source)
{
    mergeHelper(source, 0, source.size() - 1);
}

template<typename T>
void Sorts<T>::mergeHelper(std::vector<T>& source, int low, int high)
{
    if (high <= low)
    {
        return;
    }
    int mid = (high + low) / 2;
    mergeHelper(source, low, mid);
    mergeHelper(source, mid + 1, high);
    merge(source, low, mid, high);
}

template<typename T>
void Sorts<T>::merge(std::vector<T>& source, int low, int mid, int high)
{
    int i = low;
    int j = mid + 1;

    std::vector<T> aux(source.size());
    for (int k = low; k <= high; k++)
    {
        aux[k] = source[k];
    }
    for (int k = low; k <= high; k++)
    {
        if (i > mid)
        {
            source[k] = aux[j++];
        }
        else if (j > high)
        {
            source[k] = aux[i++];
        }
        else if (aux[j] < aux[i])
        {
            source[k] = aux[j++];
        }
        else
        {
            source[k] = aux[i++];
        }
    }
}

#endif
