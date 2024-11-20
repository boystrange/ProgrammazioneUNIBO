NULL = 

SOURCES = \
  EX1.md \
  EX2.md \
  $(NULL)

TARGETS = $(SOURCES:%.md=%.pdf)

OPTIONS = -V lang=it -V papersize:A4

all: $(TARGETS)

%: %.cpp
	g++ -o $@ $<

%.pdf: %.md
	pandoc $< $(OPTIONS) -o $@

clean:
	rm -f *.pdf
