# Copyright (c) 2014-2016 The Khronos Group Inc.
# Copyright notice at https://www.khronos.org/registry/speccopyright.html
all: html chunks pdf

XMLLINT    = --no-xmllint

A2XOPTS    = -a mathjax \
	     --asciidoc-opts="-f config/mathjax-docbook.conf" \
	     --xsltproc-opts="--param generate.consistent.ids 1" \
	     $(XMLLINT) $(VERBOSE)

html:
	a2x $(A2XOPTS) -f xhtml df.txt -a a2xformat=html -a docinfo --xsl-file=config/docbook-xsl/xhtml.xsl -a toc2 -a toclevels=2
	./inline.pl > df_inline.html

chunks:
	cd chunked; a2x --format=chunked -a docinfo df.txt  -L --resource ../images ; cd ..

pdf:
	asciidoc -d book -b docbook -a a2xformat=pdf -a docinfo df.txt && dblatex -b pdftex -s dblatex/df.sty df.xml

clean:
	rm -f df.pdf df.xml df.html df_inline.html
	rm -rf chunked/df.chunked
