' Copyright (c) 2009 Bruce A Henderson
' 
' Permission is hereby granted, free of charge, to any person obtaining a copy
' of this software and associated documentation files (the "Software"), to deal
' in the Software without restriction, including without limitation the rights
' to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
' copies of the Software, and to permit persons to whom the Software is
' furnished to do so, subject to the following conditions:
' 
' The above copyright notice and this permission notice shall be included in
' all copies or substantial portions of the Software.
' 
' THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
' IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
' FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
' AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
' LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
' OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
' THE SOFTWARE.
' 
SuperStrict

Module Qt.QLocale

ModuleInfo "Version: 1.00"
ModuleInfo "License: MIT"
ModuleInfo "Author: Bruce A Henderson"
ModuleInfo "Copyright: (c) 2009 Bruce A Henderson"


Import "common.bmx"

Type Qlocale

	Rem
	bbdoc: The "C" locale is identical in behavior to English/UnitedStates.
	end rem
	Const Lang_C:Int = 1
	Rem
	bbdoc:  
	end rem
	Const Lang_Abkhazian:Int = 2
	Rem
	bbdoc:  
	end rem
	Const Lang_Afan:Int = 3
	Rem
	bbdoc:  
	end rem
	Const Lang_Afar:Int = 4
	Rem
	bbdoc:  
	end rem
	Const Lang_Afrikaans:Int = 5
	Rem
	bbdoc:  
	end rem
	Const Lang_Albanian:Int = 6
	Rem
	bbdoc:  
	end rem
	Const Lang_Amharic:Int = 7
	Rem
	bbdoc:  
	end rem
	Const Lang_Arabic:Int = 8
	Rem
	bbdoc:  
	end rem
	Const Lang_Armenian:Int = 9
	Rem
	bbdoc:  
	end rem
	Const Lang_Assamese:Int = 10
	Rem
	bbdoc:  
	end rem
	Const Lang_Aymara:Int = 11
	Rem
	bbdoc:  
	end rem
	Const Lang_Azerbaijani:Int = 12
	Rem
	bbdoc:  
	end rem
	Const Lang_Bashkir:Int = 13
	Rem
	bbdoc:  
	end rem
	Const Lang_Basque:Int = 14
	Rem
	bbdoc:  
	end rem
	Const Lang_Bengali:Int = 15
	Rem
	bbdoc:  
	end rem
	Const Lang_Bhutani:Int = 16
	Rem
	bbdoc:  
	end rem
	Const Lang_Bihari:Int = 17
	Rem
	bbdoc:  
	end rem
	Const Lang_Bislama:Int = 18
	Rem
	bbdoc:  
	end rem
	Const Lang_Breton:Int = 19
	Rem
	bbdoc:  
	end rem
	Const Lang_Bulgarian:Int = 20
	Rem
	bbdoc:  
	end rem
	Const Lang_Burmese:Int = 21
	Rem
	bbdoc:  
	end rem
	Const Lang_Byelorussian:Int = 22
	Rem
	bbdoc:  
	end rem
	Const Lang_Cambodian:Int = 23
	Rem
	bbdoc:  
	end rem
	Const Lang_Catalan:Int = 24
	Rem
	bbdoc:  
	end rem
	Const Lang_Chinese:Int = 25
	Rem
	bbdoc:  
	end rem
	Const Lang_Corsican:Int = 26
	Rem
	bbdoc:  
	end rem
	Const Lang_Croatian:Int = 27
	Rem
	bbdoc:  
	end rem
	Const Lang_Czech:Int = 28
	Rem
	bbdoc:  
	end rem
	Const Lang_Danish:Int = 29
	Rem
	bbdoc:  
	end rem
	Const Lang_Dutch:Int = 30
	Rem
	bbdoc:  
	end rem
	Const Lang_English:Int = 31
	Rem
	bbdoc:  
	end rem
	Const Lang_Esperanto:Int = 32
	Rem
	bbdoc:  
	end rem
	Const Lang_Estonian:Int = 33
	Rem
	bbdoc:  
	end rem
	Const Lang_Faroese:Int = 34
	Rem
	bbdoc:  
	end rem
	Const Lang_FijiLanguage:Int = 35
	Rem
	bbdoc:  
	end rem
	Const Lang_Finnish:Int = 36
	Rem
	bbdoc:  
	end rem
	Const Lang_French:Int = 37
	Rem
	bbdoc:  
	end rem
	Const Lang_Frisian:Int = 38
	Rem
	bbdoc:  
	end rem
	Const Lang_Gaelic:Int = 39
	Rem
	bbdoc:  
	end rem
	Const Lang_Galician:Int = 40
	Rem
	bbdoc:  
	end rem
	Const Lang_Georgian:Int = 41
	Rem
	bbdoc:  
	end rem
	Const Lang_German:Int = 42
	Rem
	bbdoc:  
	end rem
	Const Lang_Greek:Int = 43
	Rem
	bbdoc:  
	end rem
	Const Lang_Greenlandic:Int = 44
	Rem
	bbdoc:  
	end rem
	Const Lang_Guarani:Int = 45
	Rem
	bbdoc:  
	end rem
	Const Lang_Gujarati:Int = 46
	Rem
	bbdoc:  
	end rem
	Const Lang_Hausa:Int = 47
	Rem
	bbdoc:  
	end rem
	Const Lang_Hebrew:Int = 48
	Rem
	bbdoc:  
	end rem
	Const Lang_Hindi:Int = 49
	Rem
	bbdoc:  
	end rem
	Const Lang_Hungarian:Int = 50
	Rem
	bbdoc:  
	end rem
	Const Lang_Icelandic:Int = 51
	Rem
	bbdoc:  
	end rem
	Const Lang_Indonesian:Int = 52
	Rem
	bbdoc:  
	end rem
	Const Lang_Interlingua:Int = 53
	Rem
	bbdoc:  
	end rem
	Const Lang_Interlingue:Int = 54
	Rem
	bbdoc:  
	end rem
	Const Lang_Inuktitut:Int = 55
	Rem
	bbdoc:  
	end rem
	Const Lang_Inupiak:Int = 56
	Rem
	bbdoc:  
	end rem
	Const Lang_Irish:Int = 57
	Rem
	bbdoc:  
	end rem
	Const Lang_Italian:Int = 58
	Rem
	bbdoc:  
	end rem
	Const Lang_Japanese:Int = 59
	Rem
	bbdoc:  
	end rem
	Const Lang_Javanese:Int = 60
	Rem
	bbdoc:  
	end rem
	Const Lang_Kannada:Int = 61
	Rem
	bbdoc:  
	end rem
	Const Lang_Kashmiri:Int = 62
	Rem
	bbdoc:  
	end rem
	Const Lang_Kazakh:Int = 63
	Rem
	bbdoc:  
	end rem
	Const Lang_Kinyarwanda:Int = 64
	Rem
	bbdoc:  
	end rem
	Const Lang_Kirghiz:Int = 65
	Rem
	bbdoc:  
	end rem
	Const Lang_Korean:Int = 66
	Rem
	bbdoc:  
	end rem
	Const Lang_Kurdish:Int = 67
	Rem
	bbdoc:  
	end rem
	Const Lang_Kurundi:Int = 68
	Rem
	bbdoc:  
	end rem
	Const Lang_Laothian:Int = 69
	Rem
	bbdoc:  
	end rem
	Const Lang_Latin:Int = 70
	Rem
	bbdoc:  
	end rem
	Const Lang_Latvian:Int = 71
	Rem
	bbdoc:  
	end rem
	Const Lang_Lingala:Int = 72
	Rem
	bbdoc:  
	end rem
	Const Lang_Lithuanian:Int = 73
	Rem
	bbdoc:  
	end rem
	Const Lang_Macedonian:Int = 74
	Rem
	bbdoc:  
	end rem
	Const Lang_Malagasy:Int = 75
	Rem
	bbdoc:  
	end rem
	Const Lang_Malay:Int = 76
	Rem
	bbdoc:  
	end rem
	Const Lang_Malayalam:Int = 77
	Rem
	bbdoc:  
	end rem
	Const Lang_Maltese:Int = 78
	Rem
	bbdoc:  
	end rem
	Const Lang_Maori:Int = 79
	Rem
	bbdoc:  
	end rem
	Const Lang_Marathi:Int = 80
	Rem
	bbdoc:  
	end rem
	Const Lang_Moldavian:Int = 81
	Rem
	bbdoc:  
	end rem
	Const Lang_Mongolian:Int = 82
	Rem
	bbdoc:  
	end rem
	Const Lang_NauruLanguage:Int = 83
	Rem
	bbdoc:  
	end rem
	Const Lang_Nepali:Int = 84
	Rem
	bbdoc:  
	end rem
	Const Lang_Norwegian:Int = 85
	Rem
	bbdoc:  
	end rem
	Const Lang_NorwegianBokmal:Int = Lang_Norwegian
	Rem
	bbdoc:  
	end rem
	Const Lang_NorwegianNynorsk:Int = 141
	Rem
	bbdoc:  
	end rem
	Const Lang_Occitan:Int = 86
	Rem
	bbdoc:  
	end rem
	Const Lang_Oriya:Int = 87
	Rem
	bbdoc:  
	end rem
	Const Lang_Pashto:Int = 88
	Rem
	bbdoc:  
	end rem
	Const Lang_Persian:Int = 89
	Rem
	bbdoc:  
	end rem
	Const Lang_Polish:Int = 90
	Rem
	bbdoc:  
	end rem
	Const Lang_Portuguese:Int = 91
	Rem
	bbdoc:  
	end rem
	Const Lang_Punjabi:Int = 92
	Rem
	bbdoc:  
	end rem
	Const Lang_Quechua:Int = 93
	Rem
	bbdoc:  
	end rem
	Const Lang_RhaetoRomance:Int = 94
	Rem
	bbdoc:  
	end rem
	Const Lang_Romanian:Int = 95
	Rem
	bbdoc:  
	end rem
	Const Lang_Russian:Int = 96
	Rem
	bbdoc:  
	end rem
	Const Lang_Samoan:Int = 97
	Rem
	bbdoc:  
	end rem
	Const Lang_Sangho:Int = 98
	Rem
	bbdoc:  
	end rem
	Const Lang_Sanskrit:Int = 99
	Rem
	bbdoc:  
	end rem
	Const Lang_Serbian:Int = 100
	Rem
	bbdoc:  
	end rem
	Const Lang_SerboCroatian:Int = 101
	Rem
	bbdoc:  
	end rem
	Const Lang_Sesotho:Int = 102
	Rem
	bbdoc:  
	end rem
	Const Lang_Setswana:Int = 103
	Rem
	bbdoc:  
	end rem
	Const Lang_Shona:Int = 104
	Rem
	bbdoc:  
	end rem
	Const Lang_Sindhi:Int = 105
	Rem
	bbdoc:  
	end rem
	Const Lang_Singhalese:Int = 106
	Rem
	bbdoc:  
	end rem
	Const Lang_Siswati:Int = 107
	Rem
	bbdoc:  
	end rem
	Const Lang_Slovak:Int = 108
	Rem
	bbdoc:  
	end rem
	Const Lang_Slovenian:Int = 109
	Rem
	bbdoc:  
	end rem
	Const Lang_Somali:Int = 110
	Rem
	bbdoc:  
	end rem
	Const Lang_Spanish:Int = 111
	Rem
	bbdoc:  
	end rem
	Const Lang_Sundanese:Int = 112
	Rem
	bbdoc:  
	end rem
	Const Lang_Swahili:Int = 113
	Rem
	bbdoc:  
	end rem
	Const Lang_Swedish:Int = 114
	Rem
	bbdoc:  
	end rem
	Const Lang_Tagalog:Int = 115
	Rem
	bbdoc:  
	end rem
	Const Lang_Tajik:Int = 116
	Rem
	bbdoc:  
	end rem
	Const Lang_Tamil:Int = 117
	Rem
	bbdoc:  
	end rem
	Const Lang_Tatar:Int = 118
	Rem
	bbdoc:  
	end rem
	Const Lang_Telugu:Int = 119
	Rem
	bbdoc:  
	end rem
	Const Lang_Thai:Int = 120
	Rem
	bbdoc:  
	end rem
	Const Lang_Tibetan:Int = 121
	Rem
	bbdoc:  
	end rem
	Const Lang_Tigrinya:Int = 122
	Rem
	bbdoc:  
	end rem
	Const Lang_TongaLanguage:Int = 123
	Rem
	bbdoc:  
	end rem
	Const Lang_Tsonga:Int = 124
	Rem
	bbdoc:  
	end rem
	Const Lang_Turkish:Int = 125
	Rem
	bbdoc:  
	end rem
	Const Lang_Turkmen:Int = 126
	Rem
	bbdoc:  
	end rem
	Const Lang_Twi:Int = 127
	Rem
	bbdoc:  
	end rem
	Const Lang_Uigur:Int = 128
	Rem
	bbdoc:  
	end rem
	Const Lang_Ukrainian:Int = 129
	Rem
	bbdoc:  
	end rem
	Const Lang_Urdu:Int = 130
	Rem
	bbdoc:  
	end rem
	Const Lang_Uzbek:Int = 131
	Rem
	bbdoc:  
	end rem
	Const Lang_Vietnamese:Int = 132
	Rem
	bbdoc:  
	end rem
	Const Lang_Volapuk:Int = 133
	Rem
	bbdoc:  
	end rem
	Const Lang_Welsh:Int = 134
	Rem
	bbdoc:  
	end rem
	Const Lang_Wolof:Int = 135
	Rem
	bbdoc:  
	end rem
	Const Lang_Xhosa:Int = 136
	Rem
	bbdoc:  
	end rem
	Const Lang_Yiddish:Int = 137
	Rem
	bbdoc:  
	end rem
	Const Lang_Yoruba:Int = 138
	Rem
	bbdoc:  
	end rem
	Const Lang_Zhuang:Int = 139
	Rem
	bbdoc:  
	end rem
	Const Lang_Zulu:Int = 140
	Rem
	bbdoc:  
	end rem
	Const Lang_Bosnian:Int = 142
	Rem
	bbdoc:  
	end rem
	Const Lang_Divehi:Int = 143
	Rem
	bbdoc:  
	end rem
	Const Lang_Manx:Int = 144
	Rem
	bbdoc:  
	end rem
	Const Lang_Cornish:Int = 145
	Rem
	bbdoc:  
	end rem
	Const Lang_Akan:Int = 146
	Rem
	bbdoc:  
	end rem
	Const Lang_Konkani:Int = 147
	Rem
	bbdoc:  
	end rem
	Const Lang_Ga:Int = 148
	Rem
	bbdoc:  
	end rem
	Const Lang_Igbo:Int = 149
	Rem
	bbdoc:  
	end rem
	Const Lang_Kamba:Int = 150
	Rem
	bbdoc:  
	end rem
	Const Lang_Syriac:Int = 151
	Rem
	bbdoc:  
	end rem
	Const Lang_Blin:Int = 152
	Rem
	bbdoc:  
	end rem
	Const Lang_Geez:Int = 153
	Rem
	bbdoc:  
	end rem
	Const Lang_Koro:Int = 154
	Rem
	bbdoc:  
	end rem
	Const Lang_Sidamo:Int = 155
	Rem
	bbdoc:  
	end rem
	Const Lang_Atsam:Int = 156
	Rem
	bbdoc:  
	end rem
	Const Lang_Tigre:Int = 157
	Rem
	bbdoc:  
	end rem
	Const Lang_Jju:Int = 158
	Rem
	bbdoc:  
	end rem
	Const Lang_Friulian:Int = 159
	Rem
	bbdoc:  
	end rem
	Const Lang_Venda:Int = 160
	Rem
	bbdoc:  
	end rem
	Const Lang_Ewe:Int = 161
	Rem
	bbdoc:  
	end rem
	Const Lang_Walamo:Int = 162
	Rem
	bbdoc:  
	end rem
	Const Lang_Hawaiian:Int = 163
	Rem
	bbdoc:  
	end rem
	Const Lang_Tyap:Int = 164
	Rem
	bbdoc:  
	end rem
	Const Lang_Chewa:Int = 165
	Rem
	bbdoc:  
	end rem
	Const LastLanguage:Int = Lang_Chewa

	Rem
	bbdoc: 
	end rem
	Const Country_AnyCountry:Int = 0
	Rem
	bbdoc: 
	end rem
	Const Country_Afghanistan:Int = 1
	Rem
	bbdoc: 
	end rem
	Const Country_Albania:Int = 2
	Rem
	bbdoc: 
	end rem
	Const Country_Algeria:Int = 3
	Rem
	bbdoc: 
	end rem
	Const Country_AmericanSamoa:Int = 4
	Rem
	bbdoc: 
	end rem
	Const Country_Andorra:Int = 5
	Rem
	bbdoc: 
	end rem
	Const Country_Angola:Int = 6
	Rem
	bbdoc: 
	end rem
	Const Country_Anguilla:Int = 7
	Rem
	bbdoc: 
	end rem
	Const Country_Antarctica:Int = 8
	Rem
	bbdoc: 
	end rem
	Const Country_AntiguaAndBarbuda:Int = 9
	Rem
	bbdoc: 
	end rem
	Const Country_Argentina:Int = 10
	Rem
	bbdoc: 
	end rem
	Const Country_Armenia:Int = 11
	Rem
	bbdoc: 
	end rem
	Const Country_Aruba:Int = 12
	Rem
	bbdoc: 
	end rem
	Const Country_Australia:Int = 13
	Rem
	bbdoc: 
	end rem
	Const Country_Austria:Int = 14
	Rem
	bbdoc: 
	end rem
	Const Country_Azerbaijan:Int = 15
	Rem
	bbdoc: 
	end rem
	Const Country_Bahamas:Int = 16
	Rem
	bbdoc: 
	end rem
	Const Country_Bahrain:Int = 17
	Rem
	bbdoc: 
	end rem
	Const Country_Bangladesh:Int = 18
	Rem
	bbdoc: 
	end rem
	Const Country_Barbados:Int = 19
	Rem
	bbdoc: 
	end rem
	Const Country_Belarus:Int = 20
	Rem
	bbdoc: 
	end rem
	Const Country_Belgium:Int = 21
	Rem
	bbdoc: 
	end rem
	Const Country_Belize:Int = 22
	Rem
	bbdoc: 
	end rem
	Const Country_Benin:Int = 23
	Rem
	bbdoc: 
	end rem
	Const Country_Bermuda:Int = 24
	Rem
	bbdoc: 
	end rem
	Const Country_Bhutan:Int = 25
	Rem
	bbdoc: 
	end rem
	Const Country_Bolivia:Int = 26
	Rem
	bbdoc: 
	end rem
	Const Country_BosniaAndHerzegowina:Int = 27
	Rem
	bbdoc: 
	end rem
	Const Country_Botswana:Int = 28
	Rem
	bbdoc: 
	end rem
	Const Country_BouvetIsland:Int = 29
	Rem
	bbdoc: 
	end rem
	Const Country_Brazil:Int = 30
	Rem
	bbdoc: 
	end rem
	Const Country_BritishIndianOceanTerritory:Int = 31
	Rem
	bbdoc: 
	end rem
	Const Country_BruneiDarussalam:Int = 32
	Rem
	bbdoc: 
	end rem
	Const Country_Bulgaria:Int = 33
	Rem
	bbdoc: 
	end rem
	Const Country_BurkinaFaso:Int = 34
	Rem
	bbdoc: 
	end rem
	Const Country_Burundi:Int = 35
	Rem
	bbdoc: 
	end rem
	Const Country_Cambodia:Int = 36
	Rem
	bbdoc: 
	end rem
	Const Country_Cameroon:Int = 37
	Rem
	bbdoc: 
	end rem
	Const Country_Canada:Int = 38
	Rem
	bbdoc: 
	end rem
	Const Country_CapeVerde:Int = 39
	Rem
	bbdoc: 
	end rem
	Const Country_CaymanIslands:Int = 40
	Rem
	bbdoc: 
	end rem
	Const Country_CentralAfricanRepublic:Int = 41
	Rem
	bbdoc: 
	end rem
	Const Country_Chad:Int = 42
	Rem
	bbdoc: 
	end rem
	Const Country_Chile:Int = 43
	Rem
	bbdoc: 
	end rem
	Const Country_China:Int = 44
	Rem
	bbdoc: 
	end rem
	Const Country_ChristmasIsland:Int = 45
	Rem
	bbdoc: 
	end rem
	Const Country_CocosIslands:Int = 46
	Rem
	bbdoc: 
	end rem
	Const Country_Colombia:Int = 47
	Rem
	bbdoc: 
	end rem
	Const Country_Comoros:Int = 48
	Rem
	bbdoc: 
	end rem
	Const Country_DemocraticRepublicOfCongo:Int = 49
	Rem
	bbdoc: 
	end rem
	Const Country_PeoplesRepublicOfCongo:Int = 50
	Rem
	bbdoc: 
	end rem
	Const Country_CookIslands:Int = 51
	Rem
	bbdoc: 
	end rem
	Const Country_CostaRica:Int = 52
	Rem
	bbdoc: 
	end rem
	Const Country_IvoryCoast:Int = 53
	Rem
	bbdoc: 
	end rem
	Const Country_Croatia:Int = 54
	Rem
	bbdoc: 
	end rem
	Const Country_Cuba:Int = 55
	Rem
	bbdoc: 
	end rem
	Const Country_Cyprus:Int = 56
	Rem
	bbdoc: 
	end rem
	Const Country_CzechRepublic:Int = 57
	Rem
	bbdoc: 
	end rem
	Const Country_Denmark:Int = 58
	Rem
	bbdoc: 
	end rem
	Const Country_Djibouti:Int = 59
	Rem
	bbdoc: 
	end rem
	Const Country_Dominica:Int = 60
	Rem
	bbdoc: 
	end rem
	Const Country_DominicanRepublic:Int = 61
	Rem
	bbdoc: 
	end rem
	Const Country_EastTimor:Int = 62
	Rem
	bbdoc: 
	end rem
	Const Country_Ecuador:Int = 63
	Rem
	bbdoc: 
	end rem
	Const Country_Egypt:Int = 64
	Rem
	bbdoc: 
	end rem
	Const Country_ElSalvador:Int = 65
	Rem
	bbdoc: 
	end rem
	Const Country_EquatorialGuinea:Int = 66
	Rem
	bbdoc: 
	end rem
	Const Country_Eritrea:Int = 67
	Rem
	bbdoc: 
	end rem
	Const Country_Estonia:Int = 68
	Rem
	bbdoc: 
	end rem
	Const Country_Ethiopia:Int = 69
	Rem
	bbdoc: 
	end rem
	Const Country_FalklandIslands:Int = 70
	Rem
	bbdoc: 
	end rem
	Const Country_FaroeIslands:Int = 71
	Rem
	bbdoc: 
	end rem
	Const Country_FijiCountry:Int = 72
	Rem
	bbdoc: 
	end rem
	Const Country_Finland:Int = 73
	Rem
	bbdoc: 
	end rem
	Const Country_France:Int = 74
	Rem
	bbdoc: 
	end rem
	Const Country_MetropolitanFrance:Int = 75
	Rem
	bbdoc: 
	end rem
	Const Country_FrenchGuiana:Int = 76
	Rem
	bbdoc: 
	end rem
	Const Country_FrenchPolynesia:Int = 77
	Rem
	bbdoc: 
	end rem
	Const Country_FrenchSouthernTerritories:Int = 78
	Rem
	bbdoc: 
	end rem
	Const Country_Gabon:Int = 79
	Rem
	bbdoc: 
	end rem
	Const Country_Gambia:Int = 80
	Rem
	bbdoc: 
	end rem
	Const Country_Georgia:Int = 81
	Rem
	bbdoc: 
	end rem
	Const Country_Germany:Int = 82
	Rem
	bbdoc: 
	end rem
	Const Country_Ghana:Int = 83
	Rem
	bbdoc: 
	end rem
	Const Country_Gibraltar:Int = 84
	Rem
	bbdoc: 
	end rem
	Const Country_Greece:Int = 85
	Rem
	bbdoc: 
	end rem
	Const Country_Greenland:Int = 86
	Rem
	bbdoc: 
	end rem
	Const Country_Grenada:Int = 87
	Rem
	bbdoc: 
	end rem
	Const Country_Guadeloupe:Int = 88
	Rem
	bbdoc: 
	end rem
	Const Country_Guam:Int = 89
	Rem
	bbdoc: 
	end rem
	Const Country_Guatemala:Int = 90
	Rem
	bbdoc: 
	end rem
	Const Country_Guinea:Int = 91
	Rem
	bbdoc: 
	end rem
	Const Country_GuineaBissau:Int = 92
	Rem
	bbdoc: 
	end rem
	Const Country_Guyana:Int = 93
	Rem
	bbdoc: 
	end rem
	Const Country_Haiti:Int = 94
	Rem
	bbdoc: 
	end rem
	Const Country_HeardAndMcDonaldIslands:Int = 95
	Rem
	bbdoc: 
	end rem
	Const Country_Honduras:Int = 96
	Rem
	bbdoc: 
	end rem
	Const Country_HongKong:Int = 97
	Rem
	bbdoc: 
	end rem
	Const Country_Hungary:Int = 98
	Rem
	bbdoc: 
	end rem
	Const Country_Iceland:Int = 99
	Rem
	bbdoc: 
	end rem
	Const Country_India:Int = 100
	Rem
	bbdoc: 
	end rem
	Const Country_Indonesia:Int = 101
	Rem
	bbdoc: 
	end rem
	Const Country_Iran:Int = 102
	Rem
	bbdoc: 
	end rem
	Const Country_Iraq:Int = 103
	Rem
	bbdoc: 
	end rem
	Const Country_Ireland:Int = 104
	Rem
	bbdoc: 
	end rem
	Const Country_Israel:Int = 105
	Rem
	bbdoc: 
	end rem
	Const Country_Italy:Int = 106
	Rem
	bbdoc: 
	end rem
	Const Country_Jamaica:Int = 107
	Rem
	bbdoc: 
	end rem
	Const Country_Japan:Int = 108
	Rem
	bbdoc: 
	end rem
	Const Country_Jordan:Int = 109
	Rem
	bbdoc: 
	end rem
	Const Country_Kazakhstan:Int = 110
	Rem
	bbdoc: 
	end rem
	Const Country_Kenya:Int = 111
	Rem
	bbdoc: 
	end rem
	Const Country_Kiribati:Int = 112
	Rem
	bbdoc: 
	end rem
	Const Country_DemocraticRepublicOfKorea:Int = 113
	Rem
	bbdoc: 
	end rem
	Const Country_RepublicOfKorea:Int = 114
	Rem
	bbdoc: 
	end rem
	Const Country_Kuwait:Int = 115
	Rem
	bbdoc: 
	end rem
	Const Country_Kyrgyzstan:Int = 116
	Rem
	bbdoc: 
	end rem
	Const Country_Lao:Int = 117
	Rem
	bbdoc: 
	end rem
	Const Country_Latvia:Int = 118
	Rem
	bbdoc: 
	end rem
	Const Country_Lebanon:Int = 119
	Rem
	bbdoc: 
	end rem
	Const Country_Lesotho:Int = 120
	Rem
	bbdoc: 
	end rem
	Const Country_Liberia:Int = 121
	Rem
	bbdoc: 
	end rem
	Const Country_LibyanArabJamahiriya:Int = 122
	Rem
	bbdoc: 
	end rem
	Const Country_Liechtenstein:Int = 123
	Rem
	bbdoc: 
	end rem
	Const Country_Lithuania:Int = 124
	Rem
	bbdoc: 
	end rem
	Const Country_Luxembourg:Int = 125
	Rem
	bbdoc: 
	end rem
	Const Country_Macau:Int = 126
	Rem
	bbdoc: 
	end rem
	Const Country_Macedonia:Int = 127
	Rem
	bbdoc: 
	end rem
	Const Country_Madagascar:Int = 128
	Rem
	bbdoc: 
	end rem
	Const Country_Malawi:Int = 129
	Rem
	bbdoc: 
	end rem
	Const Country_Malaysia:Int = 130
	Rem
	bbdoc: 
	end rem
	Const Country_Maldives:Int = 131
	Rem
	bbdoc: 
	end rem
	Const Country_Mali:Int = 132
	Rem
	bbdoc: 
	end rem
	Const Country_Malta:Int = 133
	Rem
	bbdoc: 
	end rem
	Const Country_MarshallIslands:Int = 134
	Rem
	bbdoc: 
	end rem
	Const Country_Martinique:Int = 135
	Rem
	bbdoc: 
	end rem
	Const Country_Mauritania:Int = 136
	Rem
	bbdoc: 
	end rem
	Const Country_Mauritius:Int = 137
	Rem
	bbdoc: 
	end rem
	Const Country_Mayotte:Int = 138
	Rem
	bbdoc: 
	end rem
	Const Country_Mexico:Int = 139
	Rem
	bbdoc: 
	end rem
	Const Country_Micronesia:Int = 140
	Rem
	bbdoc: 
	end rem
	Const Country_Moldova:Int = 141
	Rem
	bbdoc: 
	end rem
	Const Country_Monaco:Int = 142
	Rem
	bbdoc: 
	end rem
	Const Country_Mongolia:Int = 143
	Rem
	bbdoc: 
	end rem
	Const Country_Montserrat:Int = 144
	Rem
	bbdoc: 
	end rem
	Const Country_Morocco:Int = 145
	Rem
	bbdoc: 
	end rem
	Const Country_Mozambique:Int = 146
	Rem
	bbdoc: 
	end rem
	Const Country_Myanmar:Int = 147
	Rem
	bbdoc: 
	end rem
	Const Country_Namibia:Int = 148
	Rem
	bbdoc: 
	end rem
	Const Country_NauruCountry:Int = 149
	Rem
	bbdoc: 
	end rem
	Const Country_Nepal:Int = 150
	Rem
	bbdoc: 
	end rem
	Const Country_Netherlands:Int = 151
	Rem
	bbdoc: 
	end rem
	Const Country_NetherlandsAntilles:Int = 152
	Rem
	bbdoc: 
	end rem
	Const Country_NewCaledonia:Int = 153
	Rem
	bbdoc: 
	end rem
	Const Country_NewZealand:Int = 154
	Rem
	bbdoc: 
	end rem
	Const Country_Nicaragua:Int = 155
	Rem
	bbdoc: 
	end rem
	Const Country_Niger:Int = 156
	Rem
	bbdoc: 
	end rem
	Const Country_Nigeria:Int = 157
	Rem
	bbdoc: 
	end rem
	Const Country_Niue:Int = 158
	Rem
	bbdoc: 
	end rem
	Const Country_NorfolkIsland:Int = 159
	Rem
	bbdoc: 
	end rem
	Const Country_NorthernMarianaIslands:Int = 160
	Rem
	bbdoc: 
	end rem
	Const Country_Norway:Int = 161
	Rem
	bbdoc: 
	end rem
	Const Country_Oman:Int = 162
	Rem
	bbdoc: 
	end rem
	Const Country_Pakistan:Int = 163
	Rem
	bbdoc: 
	end rem
	Const Country_Palau:Int = 164
	Rem
	bbdoc: 
	end rem
	Const Country_PalestinianTerritory:Int = 165
	Rem
	bbdoc: 
	end rem
	Const Country_Panama:Int = 166
	Rem
	bbdoc: 
	end rem
	Const Country_PapuaNewGuinea:Int = 167
	Rem
	bbdoc: 
	end rem
	Const Country_Paraguay:Int = 168
	Rem
	bbdoc: 
	end rem
	Const Country_Peru:Int = 169
	Rem
	bbdoc: 
	end rem
	Const Country_Philippines:Int = 170
	Rem
	bbdoc: 
	end rem
	Const Country_Pitcairn:Int = 171
	Rem
	bbdoc: 
	end rem
	Const Country_Poland:Int = 172
	Rem
	bbdoc: 
	end rem
	Const Country_Portugal:Int = 173
	Rem
	bbdoc: 
	end rem
	Const Country_PuertoRico:Int = 174
	Rem
	bbdoc: 
	end rem
	Const Country_Qatar:Int = 175
	Rem
	bbdoc: 
	end rem
	Const Country_Reunion:Int = 176
	Rem
	bbdoc: 
	end rem
	Const Country_Romania:Int = 177
	Rem
	bbdoc: 
	end rem
	Const Country_RussianFederation:Int = 178
	Rem
	bbdoc: 
	end rem
	Const Country_Rwanda:Int = 179
	Rem
	bbdoc: 
	end rem
	Const Country_SaintKittsAndNevis:Int = 180
	Rem
	bbdoc: 
	end rem
	Const Country_StLucia:Int = 181
	Rem
	bbdoc: 
	end rem
	Const Country_StVincentAndTheGrenadines:Int = 182
	Rem
	bbdoc: 
	end rem
	Const Country_Samoa:Int = 183
	Rem
	bbdoc: 
	end rem
	Const Country_SanMarino:Int = 184
	Rem
	bbdoc: 
	end rem
	Const Country_SaoTomeAndPrincipe:Int = 185
	Rem
	bbdoc: 
	end rem
	Const Country_SaudiArabia:Int = 186
	Rem
	bbdoc: 
	end rem
	Const Country_Senegal:Int = 187
	Rem
	bbdoc: 
	end rem
	Const Country_SerbiaAndMontenegro:Int = 241
	Rem
	bbdoc: 
	end rem
	Const Country_Seychelles:Int = 188
	Rem
	bbdoc: 
	end rem
	Const Country_SierraLeone:Int = 189
	Rem
	bbdoc: 
	end rem
	Const Country_Singapore:Int = 190
	Rem
	bbdoc: 
	end rem
	Const Country_Slovakia:Int = 191
	Rem
	bbdoc: 
	end rem
	Const Country_Slovenia:Int = 192
	Rem
	bbdoc: 
	end rem
	Const Country_SolomonIslands:Int = 193
	Rem
	bbdoc: 
	end rem
	Const Country_Somalia:Int = 194
	Rem
	bbdoc: 
	end rem
	Const Country_SouthAfrica:Int = 195
	Rem
	bbdoc: 
	end rem
	Const Country_SouthGeorgiaAndTheSouthSandwichIslands:Int = 196
	Rem
	bbdoc: 
	end rem
	Const Country_Spain:Int = 197
	Rem
	bbdoc: 
	end rem
	Const Country_SriLanka:Int = 198
	Rem
	bbdoc: 
	end rem
	Const Country_StHelena:Int = 199
	Rem
	bbdoc: 
	end rem
	Const Country_StPierreAndMiquelon:Int = 200
	Rem
	bbdoc: 
	end rem
	Const Country_Sudan:Int = 201
	Rem
	bbdoc: 
	end rem
	Const Country_Suriname:Int = 202
	Rem
	bbdoc: 
	end rem
	Const Country_SvalbardAndJanMayenIslands:Int = 203
	Rem
	bbdoc: 
	end rem
	Const Country_Swaziland:Int = 204
	Rem
	bbdoc: 
	end rem
	Const Country_Sweden:Int = 205
	Rem
	bbdoc: 
	end rem
	Const Country_Switzerland:Int = 206
	Rem
	bbdoc: 
	end rem
	Const Country_SyrianArabRepublic:Int = 207
	Rem
	bbdoc: 
	end rem
	Const Country_Taiwan:Int = 208
	Rem
	bbdoc: 
	end rem
	Const Country_Tajikistan:Int = 209
	Rem
	bbdoc: 
	end rem
	Const Country_Tanzania:Int = 210
	Rem
	bbdoc: 
	end rem
	Const Country_Thailand:Int = 211
	Rem
	bbdoc: 
	end rem
	Const Country_Togo:Int = 212
	Rem
	bbdoc: 
	end rem
	Const Country_Tokelau:Int = 213
	Rem
	bbdoc: 
	end rem
	Const Country_TongaCountry:Int = 214
	Rem
	bbdoc: 
	end rem
	Const Country_TrinidadAndTobago:Int = 215
	Rem
	bbdoc: 
	end rem
	Const Country_Tunisia:Int = 216
	Rem
	bbdoc: 
	end rem
	Const Country_Turkey:Int = 217
	Rem
	bbdoc: 
	end rem
	Const Country_Turkmenistan:Int = 218
	Rem
	bbdoc: 
	end rem
	Const Country_TurksAndCaicosIslands:Int = 219
	Rem
	bbdoc: 
	end rem
	Const Country_Tuvalu:Int = 220
	Rem
	bbdoc: 
	end rem
	Const Country_Uganda:Int = 221
	Rem
	bbdoc: 
	end rem
	Const Country_Ukraine:Int = 222
	Rem
	bbdoc: 
	end rem
	Const Country_UnitedArabEmirates:Int = 223
	Rem
	bbdoc: 
	end rem
	Const Country_UnitedKingdom:Int = 224
	Rem
	bbdoc: 
	end rem
	Const Country_UnitedStates:Int = 225
	Rem
	bbdoc: 
	end rem
	Const Country_UnitedStatesMinorOutlyingIslands:Int = 226
	Rem
	bbdoc: 
	end rem
	Const Country_Uruguay:Int = 227
	Rem
	bbdoc: 
	end rem
	Const Country_Uzbekistan:Int = 228
	Rem
	bbdoc: 
	end rem
	Const Country_Vanuatu:Int = 229
	Rem
	bbdoc: 
	end rem
	Const Country_VaticanCityState:Int = 230
	Rem
	bbdoc: 
	end rem
	Const Country_Venezuela:Int = 231
	Rem
	bbdoc: 
	end rem
	Const Country_VietNam:Int = 232
	Rem
	bbdoc: 
	end rem
	Const Country_BritishVirginIslands:Int = 233
	Rem
	bbdoc: 
	end rem
	Const Country_USVirginIslands:Int = 234
	Rem
	bbdoc: 
	end rem
	Const Country_WallisAndFutunaIslands:Int = 235
	Rem
	bbdoc: 
	end rem
	Const Country_WesternSahara:Int = 236
	Rem
	bbdoc: 
	end rem
	Const Country_Yemen:Int = 237
	Rem
	bbdoc: 
	end rem
	Const Country_Yugoslavia:Int = 238
	Rem
	bbdoc: 
	end rem
	Const Country_Zambia:Int = 239
	Rem
	bbdoc: 
	end rem
	Const Country_Zimbabwe:Int = 240

	
	Field qObjectPtr:Byte Ptr
	
	Function _create:QLocale(qObjectPtr:Byte Ptr)
		If qObjectPtr Then
			Local this:QLocale = New QLocale
			this.qObjectPtr = qObjectPtr
			Return this
		End If
	End Function
	
	Function CreateLocale:QLocale(language:Int, country:Int = Country_AnyCountry)
		Return New QLocale.Create(language, country)
	End Function
	
	Method Create:QLocale(language:Int, country:Int = Country_AnyCountry)
		qObjectPtr = bmx_qt_qlocale_create(language, country)
		Return Self
	End Method
	
	Method amText:String()
		Return bmx_qt_qlocale_amtext(qObjectPtr)
	End Method
	
	Method country:Int()
		Return bmx_qt_qlocale_country(qObjectPtr)
	End Method
	
	Method language:Int()
		Return bmx_qt_qlocale_language(qObjectPtr)
	End Method
	
	Method name:String()
		Return bmx_qt_qlocale_name(qObjectPtr)
	End Method

	Function countriesForLanguage:Int[](language:Int)
		Return bmx_qt_qlocale_countriesforlanguage(language)
	End Function
	
	Function countryToString:String(country:Int)
		Return bmx_qt_qlocale_countrytostring(country)
	End Function
	
	Function languageToString:String(language:Int)
		Return bmx_qt_qlocale_languagetostring(language)
	End Function
	
	Method Free()
		If qObjectPtr Then
			bmx_qt_qlocale_free(qObjectPtr)
			qObjectPtr = Null
		End If
	End Method
	
	Method Delete()
		Free()
	End Method
	
End Type
