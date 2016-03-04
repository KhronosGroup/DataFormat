# Copyright (c) 2014-2016 The Khronos Group Inc.
# Copyright notice at https://www.khronos.org/registry/speccopyright.html
all: html pdf

XMLLINT    = --no-xmllint

A2XOPTS    = -a mathjax \
	     --asciidoc-opts="-f config/mathjax-docbook.conf" \
	     --xsltproc-opts="--param generate.consistent.ids 1" \
	     $(XMLLINT) $(VERBOSE)

html:
	a2x $(A2XOPTS) -f xhtml df.txt -a a2x-format=html -a docinfo --xsl-file=config/docbook-xsl/xhtml.xsl -a toc2 -a toclevels=2
	./inline.pl > df_inline.html

pdf:
	asciidoc -d book -b docbook -f config/mathjax-docbook.conf -a a2x-format=pdf -a docinfo df.txt && \
	dblatex -b pdftex -p config/docbook-xsl/pdf.xsl -s dblatex/df.sty df.xml

clean:
	rm -f df.pdf df.xml df.html df_inline.html
