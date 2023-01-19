.PHONY: precheck

PANDOC_SETTINGS:=-d pandoc_settings.yml
.DEFAULT_GOAL := all

CHAPTERS=$(shell ls Chapters | sort -n | sed 's!^!${OUTPREFIX}/Chapters/!')

test:
	echo $(PANDOC_SETTINGS)

precheck:
	which pandoc >>/dev/null || (echo "pandoc not found; run 'brew install pandoc'" && exit 1)
	which pdflatex >> /dev/null || (echo "pdflatex not found; run 'brew install basictex'" && exit 1)

out:
	mkdir -p out
	echo "*\n!.gitignore" > out/.gitignore

.PHONY: all pdf html latex epub open_pdf open_html
all: pdf html latex epub

WORKDIR:=$(shell pwd)

pdf: out precheck Chapters/*.md
	cd .. && pandoc $(PANDOC_SETTINGS) -o "${WORKDIR}/out/${OUTPREFIX}.pdf" $(CHAPTERS)

html: out precheck Chapters/*.md
	cd .. && pandoc $(PANDOC_SETTINGS) -o "${WORKDIR}/out/${OUTPREFIX}.html" $(CHAPTERS)

latex: out precheck Chapters/*.md
	cd .. && pandoc $(PANDOC_SETTINGS) -o "${WORKDIR}/out/${OUTPREFIX}.latex" $(CHAPTERS)

epub: out precheck Chapters/*.md
	cd .. && pandoc $(PANDOC_SETTINGS) -o "${WORKDIR}/out/${OUTPREFIX}.epub" $(CHAPTERS)

.ONESHELL:
ao3: out precheck Chapters/*.md
	../scripts/ao3.sh

clean: out
	rm out/*

open_pdf:
	open "out/${OUTPREFIX}.pdf"

open_html:
	open "out/${OUTPREFIX}.html"

wordcount:
	wc -w Chapters/*.md

todo:
	rg -H TODO Chapters/*.md
