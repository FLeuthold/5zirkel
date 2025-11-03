$ton = 'c'
$mode = 0 #0 = dur, 1 = dorisch, 2 = phrygisch, 3 = lydisch, 4=mixolydisch, 5=moll, 6=lokrisch
$sharp = 0
$flat = 1

$wurst = 2*(([byte][char]$ton - 1)%7)
$wurst -= [int]($wurst -gt 4)
$wurst +=  $sharp - $flat - (2 * $mode )
$wurst += [int]($mode -gt 2)
$wurst += 12*[int]($wurst -lt 0)
$wurst = ($wurst + 6 * [int]($wurst % 2 -ne 0)) % 12

echo "anz kreuz: $wurst , anz b: $(12- $wurst)"


#if($ton -eq "h"){$ton = "b"}#ausser bei englisch, dort ist es eh schon richtig :)

#immer +7 halbtöne
#c, g, d, a, e, h, fis, cis
#fis, cis, gis, dis, ais, eis, his


#a, f, b, es ,as, des, ges, ces
#b, es as, des, ges, ces, fes


#a, f, b, es ,as, des, ges, ces

#b, es as, des, ges, ces, fes


