$ton = 'b'
$moll = $true
$sharp = 0
$flat = 0

$wurst = 2*(([byte][char]$ton - 1)%7)
$wurst -= [int]($wurst -gt 4)
$wurst +=  $sharp - $flat + 3 * [int]$moll
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

