$ton = 'b'
$moll = $false
$major = 0
$flat = 0

# ASCII-basierter Index (a=0, b=1, ..., g=6)
$index = ([byte][char]$ton) - 97
$index = ($index * 2) % 13

## Bitweise Grenzkorrektur: -1 wenn Bedingung erfüllt, sonst 0
$index += (3 - $index) -shr 31
$index += (7 - $index) -shr 31

#Variante mit logik statt arithmetik
#$index -= [int]($index -gt 2)
#$index -= [int]($index -gt 7)

# Tonartverschiebung + Mollanpassung
$index += $major - $flat + 3 * [int]$moll

# Finales Mapping in den Quintenzirkel
$index = ($index + 9) % 12
$index = ($index + 6 * [int]($index % 2 -ne 0)) % 12

# Ausgabe
echo "Anzahl Kreuz: $index , Anzahl b: $(12 - $index)"


#immer +7 halbtöne
#c, g, d, a, e, h, fis, cis
#fis, cis, gis, dis, ais, eis, his


#a, f, b, es ,as, des, ges, ces
#b, es as, des, ges, ces, fes