(TeX-add-style-hook
 "memoria"
 (lambda ()
   (TeX-add-to-alist 'LaTeX-provided-class-options
                     '(("article" "11pt")))
   (TeX-add-to-alist 'LaTeX-provided-package-options
                     '(("inputenc" "utf8") ("fontenc" "T1") ("FiraSans" "sfdefault" "scaled=.85") ("babel" "spanish") ("xcolor" "x11names" "rgb" "html") ("FiraMono" "scaled=.85")))
   (TeX-run-style-hooks
    "latex2e"
    "./graficos/mezcla-vectores-clasico"
    "./graficos/ajuste-clasico"
    "./graficos/mezcla-vectores-clasico-v2"
    "./graficos/ajuste-clasico-v2"
    "./graficos/mezcla-vectores-DyV"
    "./graficos/ajuste-DyV"
    "./graficos/mezcla-vectores-DyV-STL"
    "./graficos/ajuste-DyV-STL"
    "./graficos/compare"
    "article"
    "art11"
    "inputenc"
    "fontenc"
    "FiraSans"
    "newtxsf"
    "babel"
    "amssymb"
    "amsmath"
    "wasysym"
    "xcolor"
    "graphics"
    "caption"
    "lipsum"
    "float"
    "adjustbox"
    "geometry"
    "FiraMono"
    "pgfplotstable"
    "listingsutf8"))
 :latex)

