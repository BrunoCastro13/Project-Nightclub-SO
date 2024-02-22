all: monitor simulador

monitor:
	gcc -o Monitor -pthread Monitor.c

simulador:
	gcc -o Simulador -pthread Simulador.c

clean:
	rm *.o Monitor
	rm *.o Simulador
