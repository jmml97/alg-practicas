(TeX-add-style-hook
 "memoria"
 (lambda ()
   (TeX-add-to-alist 'LaTeX-provided-class-options
                     '(("article" "11pt")))
   (TeX-add-to-alist 'LaTeX-provided-package-options
                     '(("inputenc" "utf8") ("fontenc" "T1") ("FiraSans" "sfdefault" "scaled=.85") ("babel" "spanish") ("xcolor" "x11names" "rgb" "html") ("FiraMono" "scaled=.85")))
   (TeX-run-style-hooks
    "latex2e"
    "article"
    "art11"
    "inputenc"
    "fontenc"
    "FiraSans"
    "newtxsf"
    "babel"
    ""
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
    "listings")
   (LaTeX-add-color-definecolors
    "sbase03"
    "sbase02"
    "sbase01"
    "sbase00"
    "sbase0"
    "sbase1"
    "sbase2"
    "sbase3"
    "syellow"
    "sorange"
    "sred"
    "smagenta"
    "sviolet"
    "sblue"
    "scyan"
    "sgreen"
    "text"
    "accent"))
 :latex)

