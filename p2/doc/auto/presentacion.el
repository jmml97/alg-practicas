(TeX-add-style-hook
 "presentacion"
 (lambda ()
   (TeX-add-to-alist 'LaTeX-provided-class-options
                     '(("beamer" "spanish")))
   (TeX-add-to-alist 'LaTeX-provided-package-options
                     '(("inputenc" "utf8") ("babel" "spanish") ("fontenc" "T1") ("Chivo" "familydefault" "regular")))
   (add-to-list 'LaTeX-verbatim-environments-local "semiverbatim")
   (add-to-list 'LaTeX-verbatim-macros-with-braces-local "path")
   (add-to-list 'LaTeX-verbatim-macros-with-braces-local "url")
   (add-to-list 'LaTeX-verbatim-macros-with-braces-local "nolinkurl")
   (add-to-list 'LaTeX-verbatim-macros-with-braces-local "hyperbaseurl")
   (add-to-list 'LaTeX-verbatim-macros-with-braces-local "hyperimage")
   (add-to-list 'LaTeX-verbatim-macros-with-braces-local "hyperref")
   (add-to-list 'LaTeX-verbatim-macros-with-delims-local "path")
   (add-to-list 'LaTeX-verbatim-macros-with-delims-local "url")
   (TeX-run-style-hooks
    "latex2e"
    "beamer"
    "beamer10"
    "inputenc"
    "babel"
    "graphics"
    "tikz"
    "fontenc"
    "Chivo"
    "newtxsf"
    "listings"
    "pgfplotstable")
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
    "background"
    "text"
    "accent"
    "accent2"
    "accent3"
    "accent4"
    "accent5"
    "accent6"))
 :latex)

