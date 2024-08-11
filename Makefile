# Copyright (c) 2014-2019 The Khronos Group Inc.
# Copyright notice at https://www.khronos.org/registry/speccopyright.html
all: compressedinlinehtml pdf header

XMLLINT    = --no-xmllint

A2XOPTS    = -a mathjax \
	     --asciidoc-opts="-f config/mathjax-docbook.conf" \
	     --xsltproc-opts="--param generate.consistent.ids 1" \
	     $(XMLLINT) $(VERBOSE) --icons

sources    := df.adoc \
	     df-docinfo.xml \
	     conversions.adoc \
	     conversionintro.adoc \
	     transferfunctions.adoc \
	     primaries.adoc \
	     colormodels.adoc \
	     quantization.adoc \
	     compformats.adoc \
	     compintro.adoc \
	     s3tc.adoc \
	     rgtc.adoc \
	     bptc.adoc \
	     etc1.adoc \
	     etc2.adoc \
	     astc.adoc \
	     pvrtc.adoc \
	     references.adoc

html_config := docbook-xsl/xhtml.xsl df-xhtml.css
html_config := $(addprefix config/,${html_config})

pdf_config  := mathjax-docbook.conf docbook-xsl/pdf.xsl
pdf_config  := $(addprefix config/,${pdf_config})

version     := 1.3
outbasename := out/dataformat.$(version)

html: $(outbasename).html out/config/df-xhtml.css out/images/Khronos_RGB_June18.svg out/images/icons/note.png
inlinehtml: $(outbasename).inline.html
compressedinlinehtml: $(outbasename).inline.html.gz
pdf: $(outbasename).pdf
header: out/headers/khr_df.h

$(outbasename).html: $(sources) $(html_config) | out
	a2x $(A2XOPTS) -f xhtml df.adoc -a svgpdf=svg -a a2xhtml=html -a docinfo --xsl-file=config/docbook-xsl/xhtml.xsl -a toc2 -a toclevels=2 -D out
	./simplifyhtmllinks.pl out/df.html out/df2.html
	rm out/df.html
	mv out/df2.html out/dataformat.1.3.html

out/config/df-xhtml.css: config/df-xhtml.css  | out out/config
	cp $< $@

out/images/Khronos_RGB_June18.svg: images/Khronos_RGB_June18.svg | out/images
	cp $< $@

out/images/icons/note.png: images/icons/note.png | out/images/icons
	cp $< $@

out out/config out/headers out/images out/images/icons:
	mkdir -p $@

$(outbasename).inline.html: $(outbasename).html inlinecss.pl inlineimages.pl
	./inlinecss.pl < out/dataformat.1.3.html | ./inlineimages.pl > $@

$(outbasename).inline.html.gz: $(outbasename).inline.html
	gzip -9 -c < out/dataformat.1.3.inline.html > out/dataformat.1.3.inline.html.gz

$(outbasename).pdf: $(sources) $(pdf_config) | out
	asciidoc -d book -b docbook -a numbered -f config/mathjax-docbook.conf -a svgpdf=pdf -a a2x-format=pdf -a docinfo df.adoc && \
	dblatex -b pdftex -p config/docbook-xsl/pdf.xsl -s dblatex/df.sty df.xml -o $@

out/headers/khr_df.h: headers/khr_df.h out/headers
	cp $< $@

clean:
	rm -f out/dataformat.1.3.pdf df.xml out/dataformat.1.3.html out/dataformat.1.3.inline.html out/dataformat.1.3.inline.html.gz
	rm -rf out/config out/images out/headers
