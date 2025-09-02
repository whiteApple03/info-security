all : gcd pow_mod

gcd : common_gcd.c
	gcc $^ -o $@
pow_mod : pow_module.c
	gcc $^ -o $@ -lm

clear : 
	rm -rf gcd pow_mod
.PHONY : clear