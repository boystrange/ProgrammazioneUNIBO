NULL = 

SECTIONS = EX1 EX2 EX3 EX4 EX5
SOURCES = $(SECTIONS:%=%.md)
TARGETS = $(SECTIONS:%=%.pdf)
SOLUTIONS = $(SECTIONS:%=%.zip)

OPTIONS = -V lang=it -V papersize:A4

all: $(TARGETS) $(SOLUTIONS)

%: %.cpp
	g++ -o $@ $<

%.pdf: %.md
	pandoc $< $(OPTIONS) -o $@

EX1.zip: Coda/*.cpp Pila/*.cpp
	zip -o $@ $^

EX3.zip: List/ex?.cpp
	zip -o $@ $^

EX4.zip: Tree/*.cpp
	zip -o $@ $^

EX5.zip: Nat/*.cpp
	zip -o $@ $^

%.zip: %.cpp
	zip -o $@ $^

clean:
	rm -f *.pdf
