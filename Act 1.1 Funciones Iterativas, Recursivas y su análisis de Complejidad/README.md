# Suma directa
## Analisis de complejidad temporal
Debido a que `sumaDirecta` solamente ejecuta la expresion matematica (n^2 +
n)/2 en una sola instruccion, podemos considerar su complejidad como O(1).

# Suma Iterativa
## Análisis de complejidad temporal
Debido a que `sumaIterativa` ejecuta un ciclo `for` n veces, ejecutando una
sola instruccion con complejidad O(1) (una simple suma) en cada ciclo, entonces
su complejidad es lineal u O(n).

# Suma Recursiva
## Análisis de complejidad temporal
El caso base tiene una instruccion con complejidad O(1), por lo que cada
llamada recursiva tendra esa complejidad. Sin embargo, al realizar la llamada n
veces, entonces la complejidad es O(n).
