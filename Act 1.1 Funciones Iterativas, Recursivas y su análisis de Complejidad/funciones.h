#ifndef FUNCIONES
#define FUNCIONES
#endif

class Funciones
{
    public:
        int sumaDirecta(int num);
        int sumaIterativa(int num);
        int sumaRecursiva(int num);
};

int Funciones::sumaDirecta(int num)
{
    return (num * num + num) / 2;
}

int Funciones::sumaIterativa(int num)
{
    int sum = 0;
    for (int i = 1; i <= num; i++)
    {
        sum += i;
    }

    return sum;
}

int Funciones::sumaRecursiva(int num)
{
    if (num == 1)
    {
        return num;
    }
    else if (num == 0)
    {
        return num;
    }
    return num + sumaRecursiva(num - 1);
}
