
TEX_FILES := $(wildcard *.tex)
PDF_FILES := $(TEX_FILES:.tex=.pdf)

IMG_TEX_FILES := $(wildcard img/*.tex)
IMG_PDF_FILES := $(IMG_TEX_FILES:.tex=.pdf)

# ****** Compilación de módulos **********

.PHONY: all clean mrproper

all: memoria presentacion clean

img: $(IMG_PDF_FILES)

memoria: img
	latexmk -pdf -pdflatex="pdflatex -interaction=nonstopmode" -use-make $@.tex

presentacion: img
	latexmk -pdf -pdflatex="pdflatex -interaction=nonstopmode" -use-make $@.tex

img/%.pdf: img/%.tex
	latexmk -pdf -pdflatex="pdflatex -interaction=nonstopmode" -use-make $< -jobname=$(basename $<)

./%.pdf: ./%.tex
	latexmk -pdf -pdflatex="pdflatex -interaction=nonstopmode" -use-make $< -jobname=$(basename $<)

# ************ Limpieza ************

clean: clean-img
	-@rm -f ./*.aux ./*.synctex.gz ./*.log ./*.fls ./*.fdb_latexmk ./*.dvi ./*.nav ./*.out ./*.snm ./*.toc
	@echo "Limpiando..."

clean-img:
	-@rm -f ./img/*.aux ./img/*.synctex.gz ./img/*.log ./img/*.fls ./img/*.fdb_latexmk ./img/*.dvi ./img/*.nav ./img/*.out ./img/*.snm ./img/*.toc

mrproper: clean
	-@rm -f ./*.pdf ./img/*.pdf
	@echo "Limpieza completada."
