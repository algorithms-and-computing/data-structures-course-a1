
# Ejercicios de Complejidad Computacional

Indica la complejidad de las siguientes fragmentos de código:

_Código 1_
```c++
int main () {
  int n, arr[100000];
  cin >> n;
  for(int i=0; i<n; i++){
    cin >> arr[i];
  }
  for(int i=0; i<n; i++){
    cout << arr[i];
  }
  return 0;
}
```

_Código 2_
```c++
int main () {
  int n;
  cin >> n;
  for(int i=1; i<sqrt(n); i++){
    if(i%n == 0){
      cout << i << (n/i);
    }
  }
  return 0;
}
```

_Código 3_
```c++
void ordena () {
  for(i=0;i<n;i++){
        menor = i;
        for(j=i;j<n;j++){
            if(arr[menor] > arr[j]) {
                menor = j;
            }
        }
        aux = arr[i];
        arr[i] = arr[menor];
        arr[menor] = aux;
    }
}
```

_Código 4_
```c++
void printIntToBin(int n) {
    if(n == 0) return;
    
    int bit = n&1;  // Obtain last bit to the right
  n >>= 1;    // Delete last bit to the right
  
  pritnIntToBin(n);
    cout << bit;
}
```

_Código 5_
```c++
int fib(int n) {
  if(n < 2) return 1;
  return fib(n-1) + fib(n-2);
}
```

Como ejercicio extra para esta sección, indica la complejidad de cada algoritmo que realices en los ejercicios de los siguientes temas. (Opcional)