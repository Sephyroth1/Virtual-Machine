#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef enum {
	PSH,
	ADD,
	SET,
	POP,
	HLT
}ISet;

typedef enum {
	A, B, C, D, E, F,
	NUM_OF_REGISTERS
}REGISTERS;

const int program[] = {
		PSH, 11,
		PSH, 6,
		ADD,
		POP,
		HLT
	};


int ip = 0;
int sp = -1;
int stack[256];
bool running = true;
int registers[NUM_OF_REGISTERS];

int fetch(){
	return program[ip];
}

void eval(int instr){
	switch(instr){
		case HLT:
			running = false;
			break;
		case PSH:
			sp++;
			stack[sp] = program[++ip];
			break;
		case POP:
			int val_popped = stack[sp--];
			printf("popped %d\n", val_popped);
			break;
		case ADD:
			int a = stack[sp--];
			int b = stack[sp--];
			int result = a + b;
			sp++;
			stack[sp] = result;
			break;
		case SET:
			int c = stack[sp--];
			int d = stack[sp--];
			registers[d] = c;
			printf("%d \n", registers[d]);
			break;
	}
}

int main(){
	while(running){
		eval(fetch());
		ip++;
	}
	return 0;
}