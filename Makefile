# Copyright (c) 2014-2017 The Khronos Group Inc.
# Copyright notice at https://www.khronos.org/registry/speccopyright.html
all: html pdf header

XMLLINT    = --no-xmllint

A2XOPTS    = -a mathjax \
	     --asciidoc-opts="-f config/mathjax-docbook.conf" \
	     --xsltproc-opts="--param generate.consistent.ids 1" \
	     $(XMLLINT) $(VERBOSE) --icons

html:
	a2x $(A2XOPTS) -f xhtml df.txt -a svgpdf=svg -a a2xhtml=html -a docinfo --xsl-file=config/docbook-xsl/xhtml.xsl -a toc2 -a toclevels=2 -D out
	mv out/df.html out/dataformat.1.2.html
	mkdir -p out/config
	mkdir -p out/images
	mkdir -p out/images/icons
	cp config/df-xhtml.css out/config
	cp images/Khronos_Dec14.svg out/images
	cp images/icons/note.png out/images/icons/note.png

pdf:
	asciidoc -d book -b docbook -f config/mathjax-docbook.conf -a svgpdf=pdf -a a2x-format=pdf -a docinfo df.txt && \
	dblatex -b pdftex -p config/docbook-xsl/pdf.xsl -s dblatex/df.sty df.xml -o out/dataformat.1.2.pdf

header:
	mkdir -p out/headers
	cp headers/khr_df.h out/headers/khr_df.h

clean:
	rm -f out/dataformat.1.2.pdf df.xml out/dataformat.1.2.html
	rm -rf out/config out/images out/headers
