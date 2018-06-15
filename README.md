# hcubature_problem
Hcubature hangs on this example
```
gcc -g -o test_hc -DCUBATURE=hcubature test_hc.c hcubature.c pcubature.c -lm
hcubature.c:920:15: warning: comparison of unsigned enum expression < 0 is always false [-Wtautological-compare]
     if (norm < 0 || norm > ERROR_LINF) return FAILURE; /* invalid norm */
         ~~~~ ^ ~
1 warning generated.
pcubature.c:310:15: warning: comparison of unsigned enum expression < 0 is always false [-Wtautological-compare]
     if (norm < 0 || norm > ERROR_LINF) return FAILURE; /* invalid norm */
         ~~~~ ^ ~
1 warning generated.

bheeshma:stats naras$ make pc
gcc -g -o test_pc -DCUBATURE=pcubature test_hc.c hcubature.c pcubature.c -lm
hcubature.c:920:15: warning: comparison of unsigned enum expression < 0 is always false [-Wtautological-compare]
     if (norm < 0 || norm > ERROR_LINF) return FAILURE; /* invalid norm */
         ~~~~ ^ ~
1 warning generated.
pcubature.c:310:15: warning: comparison of unsigned enum expression < 0 is always false [-Wtautological-compare]
     if (norm < 0 || norm > ERROR_LINF) return FAILURE; /* invalid norm */
         ~~~~ ^ ~
1 warning generated.

bheeshma:stats naras$ ./test_pc
Return code : 0
Fun calls: 1089,  Integral value: [0.999834, 0.000000]

bheeshma:stats naras$ ./test_hc
<Keeps going, never terminating and hogging memory, suggesting memory leak> 
```
