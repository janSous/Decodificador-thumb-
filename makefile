all: folder app

CC  = g++
BIN = app

INC = -I./inc

ARQ =	string_to_hexa.o \
		decodificador.o \
		decodificador_cond.o \
		decodificador_reg.o \
		main.o

app: $(ARQ)
	$(CC) obj/main.o obj/decodificador_reg.o obj/decodificador_cond.o obj/decodificador.o obj/string_to_hexa.o -o bin/app	 
	
main.o: src/main.cpp
	$(CC) -o main.o -c $(INC) src/main.cpp -o obj/main.o

decodificador_reg.o: src/decodificador_reg.cpp
	$(CC) -o decodificador_reg.o -c $(INC) src/decodificador_reg.cpp -o obj/decodificador_reg.o

decodificador_cond.o: src/decodificador_cond.cpp
	$(CC) -o decodificador_cond.o -c $(INC) src/decodificador_cond.cpp -o obj/decodificador_cond.o

decodificador.o: src/decodificador.cpp
	$(CC) -o decodificador.o -c $(INC) src/decodificador.cpp -c -o obj/decodificador.o


string_to_hexa.o: src/string_to_hexa.cpp
	$(CC) -o string_to_hexa.o -c $(INC) src/string_to_hexa.cpp -o obj/string_to_hexa.o	

folder: 
	mkdir -p bin obj

clean:
	rm obj/*.o bin/*.bin -rf obj/ bin/ tags