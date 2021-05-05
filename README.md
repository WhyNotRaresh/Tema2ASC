Nume: Badita Rares Octavian
Grupa: 333CB

# Tema 2 Sisteme de Operare

Organizare
-

### Solutia Neoptizata

Atat pentru solutia neoptimizata cat si pentru cea optimizata procedeul de calul decurge astfel:
```
S1 = B * Bt;
C = A * S1;
C += At * A;
```

Se tine cont de faptul ca A este superor triangulata si At este inferior triangulata la ultimele 2 inmultiri.

Matriciile transpuse nu sunt calculate in prealabil intrucat un acces la elementul (i)(j) in matricea transpusa reprezinta accesul la elementul (j)(i) din cea netranspusa.

### Solutia Optimizata

Optimizarea a fost realizata prin managementul accesului la memorie.
Liniile si coloanele accesate sunt salvate in prearabil pentru a eficientiza accesului la memorie.
Doar primele 2 inmultiri sunt optimizate, cea de-a 3a este la fel ca in varianta initiala.

### Solutia Blas



Implementare
-

* Tema este realizata integral.
* Pentru solutia optimizata am un timp de 11.8 secunde pentru testul de N=1200.


Resurse Utile
-

* Au fost utile paginile de manual pentru [functiile Blasm](https://developer.apple.com/documentation/accelerate/blas?language=objc)


[Github](https://github.com/WhyNotRaresh/Tema2ASC)
-
