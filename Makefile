NULL = 

SOURCES = \
  EX1.md \
  $(NULL)

TARGETS = $(SOURCES:%.md=%.pdf)

OPTIONS = -V papersize:A4

all: $(TARGETS)

%.pdf: %.md
	pandoc $< $(OPTIONS) -o $@

clean:
	rm -f *.pdf