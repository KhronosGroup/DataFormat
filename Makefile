all: html chunks pdf

html:
	asciidoc -b html5 -n -a toc2 -a docinfo df.txt
	./inline.pl > df_inline.html

chunks:
	cd chunked; a2x --format=chunked -a docinfo df.txt -L --resource ../images ; cd ..

pdf:
	asciidoc -b docbook -a docinfo df.txt && dblatex -b pdftex -s dblatex/df.sty df.xml

clean:
	rm -f df.pdf df.xml df.html df_inline.html
	rm -rf chunked/df.chunked
