#ifndef SORTS_H
#define SORTS_H

#include <vector>

template<typename T>
class Sorts
{
    public:
        void ordenaSeleccion(std::vector<T>);
        void ordenaBurbuja(std::vector<T>);
        void ordenaMerge(std::vector<T>);
        void busqSecuencial(std::vector<T>, T);
        void busqBinaria(std::vector<T>, T);
    private:
        void swap(std::vector<T>, int, int);
};

#endif
