TARGET=bin/out/dbview
INCLUDE=include
SRC=$(wildcard src/*.c)
OBJ=$(patsubst src/%.c, bin/obj/%.o, $(SRC))

run: clean default
	./$(TARGET) ./Experiments/my-db.db

default: $(TARGET)

$(TARGET): $(OBJ)
	gcc -o $@ $?

bin/obj/%.o: src/%.c
	gcc -I$(INCLUDE) -c $< -o $@

clean:
	rm -rf $(TARGET)/*
	rm -rf bin/obj/*