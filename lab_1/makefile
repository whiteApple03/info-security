all : test_lab1.exe

LIB = ../lib/
INCLUDE = ../include

test_lab1.exe : $(LIB)libbase_crypto.a main.c
	gcc main.c -lbase_crypto -lm -L$(LIB) -I$(INCLUDE) -o $@

$(LIB)libbase_crypto.a : $(LIB)common_gcd.o $(LIB)pow_module.o $(LIB)test_ferma.o
	ar rcs $@ $^

$(LIB)common_gcd.o :  $(LIB)common_gcd.c
	gcc -c -I$(INCLUDE) $^ -o $@
$(LIB)pow_module.o :  $(LIB)pow_module.c
	gcc -c -I$(INCLUDE) $^ -o $@
$(LIB)test_ferma.o :  $(LIB)test_ferma.c
	gcc -c -I$(INCLUDE) $^ -o $@

clear : 
	rm -rf gcd pow_mod $(LIB)*.o $(LIB)*.a
.PHONY : clear 