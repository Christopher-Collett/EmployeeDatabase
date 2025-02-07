TARGET=bin/out/dbview
INCLUDE=include
SRC=$(wildcard src/*.c)
OBJ=$(patsubst src/%.c, bin/obj/%.o, $(SRC))

run: clean default
	./$(TARGET) ./bin/out/my-db.db -n
	./$(TARGET) ./bin/out/my-db.db -a "John Doe"

default: $(TARGET)

$(TARGET): $(OBJ)
	gcc -o $@ $?

bin/obj/%.o: src/%.c
	gcc -I$(INCLUDE) -c $< -o $@

clean:
	rm -rf bin/out/*
	rm -rf bin/obj/*