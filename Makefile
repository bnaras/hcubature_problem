hc: test_hc.c hcubature.c pcubature.c
	gcc -g -o test_hc -DCUBATURE=hcubature test_hc.c hcubature.c pcubature.c -lm

pc: test_hc.c hcubature.c pcubature.c
	gcc -g -o test_pc -DCUBATURE=pcubature test_hc.c hcubature.c pcubature.c -lm
