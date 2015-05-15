PAPER = paper.tex
BASE := $(basename $(PAPER))
EVERYTHING = $(BASE).pdf

OURENV = TEXINPUTS="sty:" 

LATEX = $(OURENV) pdflatex -file-line-error -interaction nonstopmode
BIBTEX = bibtex -min-crossrefs=100

main: $(BASE).pdf
all: $(EVERYTHING)
# all: $(EVERYTHING)
pieces: $(PIECEMEAL)
bios: $(BIOS)

# parts depend on the whole
$(PIECEMEAL): $(BASE).pdf

XFIGS := $(wildcard figures/*.fig)
DIAFIGS := $(wildcard figures/*.dia)
EPSFIGS := $(DIAFIGS:.dia=.eps)
PDFFIGS := $(DIAFIGS:.dia=.pdf)
TEXFIGS := $(XFIGS:.fig=.tex)
XGRAPHS := 
FIGGRAPHS := $(XGRAPHS:.gnuplot=.fig)
EPSGRAPHS := $(XGRAPHS:.gnuplot=.eps)
PDFGRAPHS := $(XGRAPHS:.gnuplot=.pdf)
TEXGRAPHS := $(XGRAPHS:.gnuplot=.tex)

TEX := $(wildcard *.tex) $(TEXFIGS)
BIBS := $(wildcard *.bib)

DEPS := $(TEX) $(BIBS) $(PDFFIGS) $(TEXGRAPHS)

GENDATA = graph/single-uni-speedup.data \
          graph/single-zipf-speedup.data \
	  graph/par-uni-throttle-speedup.data


.PRECIOUS: $(FIGGRAPHS) $(GENDATA)

%.pdf: %.svg
	inkscape -z --export-text-to-path --export-pdf=$@ $<

RERUN = egrep -q '(^LaTeX Warning:|\(natbib\)).* Rerun'
UNDEFINED = egrep -q '^(LaTeX|Package natbib) Warning:.* undefined'
HASCITATION = egrep -q '^(\\citation)'

HASLATEXMK := $(shell latexmk --version 2>/dev/null)

ifeq ($(HASLATEXMK),)
LATEXRUN = $(LATEX)
%.pdf: %.tex
	$(LATEX) $<
	! $(HASCITATION) $*.log || $(BIBTEX) $*
	! $(UNDEFINED) $*.log || $(LATEX) $<
	! $(UNDEFINED) $*.log || $(BIBTEX) $*
	! $(RERUN) $*.log || $(LATEX) $<
	! $(RERUN) $*.log || $(LATEX) $<
else
LATEXRUN = latexmk -r .latexmkrc
%.pdf: %.tex always
	$(LATEXRUN) -pdf $<
endif

$(BASE).pdf: always

$(PIECEMEAL): submit-%.pdf: proposal.pdf
	! test -f latex.out/submit-$*.tex || mv latex.out/submit-$*.tex .
	$(LATEXRUN) submit-$*.tex

$(BIOS) : %.pdf : %.tex $(BIBS)

xpdf: $(BASE).pdf
	if test -f .xpdf-running; then			\
		xpdf -remote $(BASE)-server -quit;	\
		sleep 1;				\
	fi
	touch .xpdf-running
	(xpdf -remote $(BASE)-server $(BASE).pdf; rm -f .xpdf-running) &

spell:
	@ for i in $(SPELLTEX); do aspell --mode=tex -p ./aspell.words -c $$i; done
	@ for i in $(SPELLTEX); do perl bin/double.pl $$i; done
	@ for i in $(SPELLTEX); do perl bin/abbrv.pl  $$i; done
	@ bash bin/hyphens.sh $(SPELLTEX)
	@ ( head -1 aspell.words ; tail -n +2 aspell.words | sort ) > aspell.words~
	@ mv aspell.words~ aspell.words

clean:
	-rm -rf latex.out
	-rm -f *.aux *.dvi *.log *.blg *.bbl *.bak *.lof *.lot *.toc *.brf *.out *.fls *.fdb_latexmk
	-rm -f $(EVERYTHING)
	-rm -f $(PIECEMEAL:.pdf=.tex)
	-rm -f $(BASE_NORED).pdf
	-rm -f $(EPSFIGS) $(PDFFIGS) $(EPSGRAPHS) $(PDFGRAPHS)

always:
	@:

.PHONY: clean spell always
