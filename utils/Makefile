all: createDFDtest interpretDFDtest

clean:
	rm -f createDFDtest interpretDFDtest

createDFDtest: createdfd.c createdfdtest.c printdfd.c
	gcc createdfdtest.c createdfd.c printdfd.c -I. -o createDFDtest -ansi -W -Wall -pedantic -O2 -Wno-strict-aliasing

interpretDFDtest: createdfd.c interpretdfd.c interpretdfdtest.c printdfd.c
	gcc interpretdfd.c createdfd.c interpretdfdtest.c printdfd.c -o interpretDFDtest -I. -O -W -Wall -ansi -pedantic
