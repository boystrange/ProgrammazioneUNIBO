NULL = 

SECTIONS = EX1 EX2
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

%.zip: %.cpp
	zip -o $@ $^

clean:
	rm -f *.pdf
