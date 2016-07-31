import sys

ae = '[[c%l][c{g}[%{%Mc%spdgj=]T%aat%=O%bRu%sc]c%ti[o%n=Wcs%=No[t=T][hct%=buga[d=As%=W]e=T%ho[u%[%g]h%t[%}%'
#ae = '[[c%l][c{g}[%{%Mc%spdggfdj=]T%aat%=O%bRu%sc]c%ti[o[t=T][hct%=budsga[d=As%=W]e=T%ho[u%[%g]h%t[%}%T[]e3<'

# C0673c
ae = ae.replace("spdgj", "yb%e") # m5339d
ae = ae.replace("aat", "his") # m5337b
ae = ae.replace("buga", "Goo") # m5338c

# C0672b
ae = ae.replace("=", "_") # m5335i
ae = ae.replace("\\}", "", 1) # m5332f
ae = ae.replace("\\{", "", 1) # m5331e
ae = ae.replace("R", "f", 1) # m5334h
ae = ae.replace("c", "f", 1) # m5333g
ae = ae.replace("]", "") # m5330d
ae = ae.replace("[", "") # m5329c
ae = ae.replace("%", "") # m5328b
ae = ae.replace("c", "a") # m5327a

# C0673c
ae = ae.replace("aa", "ca") # m5336a

print ae
