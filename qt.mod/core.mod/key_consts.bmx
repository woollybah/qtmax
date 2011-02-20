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

Rem
bbdoc:  
End Rem
Const Qt_Key_Escape:Int = $01000000
Rem
bbdoc:  
End Rem
Const Qt_Key_Tab:Int = $01000001
Rem
bbdoc:  
End Rem
Const Qt_Key_Backtab:Int = $01000002
Rem
bbdoc:  
End Rem
Const Qt_Key_Backspace:Int = $01000003
Rem
bbdoc:  
End Rem
Const Qt_Key_Return:Int = $01000004
Rem
bbdoc: Typically located on the keypad.
End Rem
Const Qt_Key_Enter:Int = $01000005
Rem
bbdoc:  
End Rem
Const Qt_Key_Insert:Int = $01000006
Rem
bbdoc:  
End Rem
Const Qt_Key_Delete:Int = $01000007
Rem
bbdoc: The Pause/Break key (Note: Not anything to do with pausing media)
End Rem
Const Qt_Key_Pause:Int = $01000008
Rem
bbdoc:  
End Rem
Const Qt_Key_Print:Int = $01000009
Rem
bbdoc:  
End Rem
Const Qt_Key_SysReq:Int = $0100000a
Rem
bbdoc:  
End Rem
Const Qt_Key_Clear:Int = $0100000b
Rem
bbdoc:  
End Rem
Const Qt_Key_Home:Int = $01000010
Rem
bbdoc:  
End Rem
Const Qt_Key_End:Int = $01000011
Rem
bbdoc:  
End Rem
Const Qt_Key_Left:Int = $01000012
Rem
bbdoc:  
End Rem
Const Qt_Key_Up:Int = $01000013
Rem
bbdoc:  
End Rem
Const Qt_Key_Right:Int = $01000014
Rem
bbdoc:  
End Rem
Const Qt_Key_Down:Int = $01000015
Rem
bbdoc:  
End Rem
Const Qt_Key_PageUp:Int = $01000016
Rem
bbdoc:  
End Rem
Const Qt_Key_PageDown:Int = $01000017
Rem
bbdoc:  
End Rem
Const Qt_Key_Shift:Int = $01000020
Rem
bbdoc: On Mac OS X, this corresponds to the Command keys.
End Rem
Const Qt_Key_Control:Int = $01000021
Rem
bbdoc: On Mac OS X, this corresponds to the Control keys. On Windows keyboards, this key is mapped to the Windows key.
End Rem
Const Qt_Key_Meta:Int = $01000022
Rem
bbdoc:  
End Rem
Const Qt_Key_Alt:Int = $01000023
Rem
bbdoc: On Windows, when the KeyDown event for this key is sent, the Ctrl+Alt modifiers are also set.
End Rem
Const Qt_Key_AltGr:Int = $01001103
Rem
bbdoc:  
End Rem
Const Qt_Key_CapsLock:Int = $01000024
Rem
bbdoc:  
End Rem
Const Qt_Key_NumLock:Int = $01000025
Rem
bbdoc:  
End Rem
Const Qt_Key_ScrollLock:Int = $01000026
Rem
bbdoc:  
End Rem
Const Qt_Key_F1:Int = $01000030
Rem
bbdoc:  
End Rem
Const Qt_Key_F2:Int = $01000031
Rem
bbdoc:  
End Rem
Const Qt_Key_F3:Int = $01000032
Rem
bbdoc:  
End Rem
Const Qt_Key_F4:Int = $01000033
Rem
bbdoc:  
End Rem
Const Qt_Key_F5:Int = $01000034
Rem
bbdoc:  
End Rem
Const Qt_Key_F6:Int = $01000035
Rem
bbdoc:  
End Rem
Const Qt_Key_F7:Int = $01000036
Rem
bbdoc:  
End Rem
Const Qt_Key_F8:Int = $01000037
Rem
bbdoc:  
End Rem
Const Qt_Key_F9:Int = $01000038
Rem
bbdoc:  
End Rem
Const Qt_Key_F10:Int = $01000039
Rem
bbdoc:  
End Rem
Const Qt_Key_F11:Int = $0100003a
Rem
bbdoc:  
End Rem
Const Qt_Key_F12:Int = $0100003b
Rem
bbdoc:  
End Rem
Const Qt_Key_F13:Int = $0100003c
Rem
bbdoc:  
End Rem
Const Qt_Key_F14:Int = $0100003d
Rem
bbdoc:  
End Rem
Const Qt_Key_F15:Int = $0100003e
Rem
bbdoc:  
End Rem
Const Qt_Key_F16:Int = $0100003f
Rem
bbdoc:  
End Rem
Const Qt_Key_F17:Int = $01000040
Rem
bbdoc:  
End Rem
Const Qt_Key_F18:Int = $01000041
Rem
bbdoc:  
End Rem
Const Qt_Key_F19:Int = $01000042
Rem
bbdoc:  
End Rem
Const Qt_Key_F20:Int = $01000043
Rem
bbdoc:  
End Rem
Const Qt_Key_F21:Int = $01000044
Rem
bbdoc:  
End Rem
Const Qt_Key_F22:Int = $01000045
Rem
bbdoc:  
End Rem
Const Qt_Key_F23:Int = $01000046
Rem
bbdoc:  
End Rem
Const Qt_Key_F24:Int = $01000047
Rem
bbdoc:  
End Rem
Const Qt_Key_F25:Int = $01000048
Rem
bbdoc:  
End Rem
Const Qt_Key_F26:Int = $01000049
Rem
bbdoc:  
End Rem
Const Qt_Key_F27:Int = $0100004a
Rem
bbdoc:  
End Rem
Const Qt_Key_F28:Int = $0100004b
Rem
bbdoc:  
End Rem
Const Qt_Key_F29:Int = $0100004c
Rem
bbdoc:  
End Rem
Const Qt_Key_F30:Int = $0100004d
Rem
bbdoc:  
End Rem
Const Qt_Key_F31:Int = $0100004e
Rem
bbdoc:  
End Rem
Const Qt_Key_F32:Int = $0100004f
Rem
bbdoc:  
End Rem
Const Qt_Key_F33:Int = $01000050
Rem
bbdoc:  
End Rem
Const Qt_Key_F34:Int = $01000051
Rem
bbdoc:  
End Rem
Const Qt_Key_F35:Int = $01000052
Rem
bbdoc:  
End Rem
Const Qt_Key_Super_L:Int = $01000053
Rem
bbdoc:  
End Rem
Const Qt_Key_Super_R:Int = $01000054
Rem
bbdoc:  
End Rem
Const Qt_Key_Menu:Int = $01000055
Rem
bbdoc:  
End Rem
Const Qt_Key_Hyper_L:Int = $01000056
Rem
bbdoc:  
End Rem
Const Qt_Key_Hyper_R:Int = $01000057
Rem
bbdoc:  
End Rem
Const Qt_Key_Help:Int = $01000058
Rem
bbdoc:  
End Rem
Const Qt_Key_Direction_L:Int = $01000059
Rem
bbdoc:  
End Rem
Const Qt_Key_Direction_R:Int = $01000060
Rem
bbdoc:  
End Rem
Const Qt_Key_Space:Int = $20
Rem
bbdoc:  
End Rem
Const Qt_Key_Any:Int = Qt_Key_Space	 
Rem
bbdoc:  
End Rem
Const Qt_Key_Exclam:Int = $21
Rem
bbdoc:  
End Rem
Const Qt_Key_QuoteDbl:Int = $22
Rem
bbdoc:  
End Rem
Const Qt_Key_NumberSign:Int = $23
Rem
bbdoc:  
End Rem
Const Qt_Key_Dollar:Int = $24
Rem
bbdoc:  
End Rem
Const Qt_Key_Percent:Int = $25
Rem
bbdoc:  
End Rem
Const Qt_Key_Ampersand:Int = $26
Rem
bbdoc:  
End Rem
Const Qt_Key_Apostrophe:Int = $27
Rem
bbdoc:  
End Rem
Const Qt_Key_ParenLeft:Int = $28
Rem
bbdoc:  
End Rem
Const Qt_Key_ParenRight:Int = $29
Rem
bbdoc:  
End Rem
Const Qt_Key_Asterisk:Int = $2a
Rem
bbdoc:  
End Rem
Const Qt_Key_Plus:Int = $2b
Rem
bbdoc:  
End Rem
Const Qt_Key_Comma:Int = $2c
Rem
bbdoc:  
End Rem
Const Qt_Key_Minus:Int = $2d
Rem
bbdoc:  
End Rem
Const Qt_Key_Period:Int = $2e
Rem
bbdoc:  
End Rem
Const Qt_Key_Slash:Int = $2f
Rem
bbdoc:  
End Rem
Const Qt_Key_0:Int = $30
Rem
bbdoc:  
End Rem
Const Qt_Key_1:Int = $31
Rem
bbdoc:  
End Rem
Const Qt_Key_2:Int = $32
Rem
bbdoc:  
End Rem
Const Qt_Key_3:Int = $33
Rem
bbdoc:  
End Rem
Const Qt_Key_4:Int = $34
Rem
bbdoc:  
End Rem
Const Qt_Key_5:Int = $35
Rem
bbdoc:  
End Rem
Const Qt_Key_6:Int = $36
Rem
bbdoc:  
End Rem
Const Qt_Key_7:Int = $37
Rem
bbdoc:  
End Rem
Const Qt_Key_8:Int = $38
Rem
bbdoc:  
End Rem
Const Qt_Key_9:Int = $39
Rem
bbdoc:  
End Rem
Const Qt_Key_Colon:Int = $3a
Rem
bbdoc:  
End Rem
Const Qt_Key_Semicolon:Int = $3b
Rem
bbdoc:  
End Rem
Const Qt_Key_Less:Int = $3c
Rem
bbdoc:  
End Rem
Const Qt_Key_Equal:Int = $3d
Rem
bbdoc:  
End Rem
Const Qt_Key_Greater:Int = $3e
Rem
bbdoc:  
End Rem
Const Qt_Key_Question:Int = $3f
Rem
bbdoc:  
End Rem
Const Qt_Key_At:Int = $40
Rem
bbdoc:  
End Rem
Const Qt_Key_A:Int = $41
Rem
bbdoc:  
End Rem
Const Qt_Key_B:Int = $42
Rem
bbdoc:  
End Rem
Const Qt_Key_C:Int = $43
Rem
bbdoc:  
End Rem
Const Qt_Key_D:Int = $44
Rem
bbdoc:  
End Rem
Const Qt_Key_E:Int = $45
Rem
bbdoc:  
End Rem
Const Qt_Key_F:Int = $46
Rem
bbdoc:  
End Rem
Const Qt_Key_G:Int = $47
Rem
bbdoc:  
End Rem
Const Qt_Key_H:Int = $48
Rem
bbdoc:  
End Rem
Const Qt_Key_I:Int = $49
Rem
bbdoc:  
End Rem
Const Qt_Key_J:Int = $4a
Rem
bbdoc:  
End Rem
Const Qt_Key_K:Int = $4b
Rem
bbdoc:  
End Rem
Const Qt_Key_L:Int = $4c
Rem
bbdoc:  
End Rem
Const Qt_Key_M:Int = $4d
Rem
bbdoc:  
End Rem
Const Qt_Key_N:Int = $4e
Rem
bbdoc:  
End Rem
Const Qt_Key_O:Int = $4f
Rem
bbdoc:  
End Rem
Const Qt_Key_P:Int = $50
Rem
bbdoc:  
End Rem
Const Qt_Key_Q:Int = $51
Rem
bbdoc:  
End Rem
Const Qt_Key_R:Int = $52
Rem
bbdoc:  
End Rem
Const Qt_Key_S:Int = $53
Rem
bbdoc:  
End Rem
Const Qt_Key_T:Int = $54
Rem
bbdoc:  
End Rem
Const Qt_Key_U:Int = $55
Rem
bbdoc:  
End Rem
Const Qt_Key_V:Int = $56
Rem
bbdoc:  
End Rem
Const Qt_Key_W:Int = $57
Rem
bbdoc:  
End Rem
Const Qt_Key_X:Int = $58
Rem
bbdoc:  
End Rem
Const Qt_Key_Y:Int = $59
Rem
bbdoc:  
End Rem
Const Qt_Key_Z:Int = $5a
Rem
bbdoc:  
End Rem
Const Qt_Key_BracketLeft:Int = $5b
Rem
bbdoc:  
End Rem
Const Qt_Key_Backslash:Int = $5c
Rem
bbdoc:  
End Rem
Const Qt_Key_BracketRight:Int = $5d
Rem
bbdoc:  
End Rem
Const Qt_Key_AsciiCircum:Int = $5e
Rem
bbdoc:  
End Rem
Const Qt_Key_Underscore:Int = $5f
Rem
bbdoc:  
End Rem
Const Qt_Key_QuoteLeft:Int = $60
Rem
bbdoc:  
End Rem
Const Qt_Key_BraceLeft:Int = $7b
Rem
bbdoc:  
End Rem
Const Qt_Key_Bar:Int = $7c
Rem
bbdoc:  
End Rem
Const Qt_Key_BraceRight:Int = $7d
Rem
bbdoc:  
End Rem
Const Qt_Key_AsciiTilde:Int = $7e
Rem
bbdoc:  
End Rem
Const Qt_Key_nobreakspace:Int = $0a0
Rem
bbdoc:  
End Rem
Const Qt_Key_exclamdown:Int = $0a1
Rem
bbdoc:  
End Rem
Const Qt_Key_cent:Int = $0a2
Rem
bbdoc:  
End Rem
Const Qt_Key_sterling:Int = $0a3
Rem
bbdoc:  
End Rem
Const Qt_Key_currency:Int = $0a4
Rem
bbdoc:  
End Rem
Const Qt_Key_yen:Int = $0a5
Rem
bbdoc:  
End Rem
Const Qt_Key_brokenbar:Int = $0a6
Rem
bbdoc:  
End Rem
Const Qt_Key_section:Int = $0a7
Rem
bbdoc:  
End Rem
Const Qt_Key_diaeresis:Int = $0a8
Rem
bbdoc:  
End Rem
Const Qt_Key_copyright:Int = $0a9
Rem
bbdoc:  
End Rem
Const Qt_Key_ordfeminine:Int = $0aa
Rem
bbdoc:  
End Rem
Const Qt_Key_guillemotleft:Int = $0ab
Rem
bbdoc:  
End Rem
Const Qt_Key_notsign:Int = $0ac
Rem
bbdoc:  
End Rem
Const Qt_Key_hyphen:Int = $0ad
Rem
bbdoc:  
End Rem
Const Qt_Key_registered:Int = $0ae
Rem
bbdoc:  
End Rem
Const Qt_Key_macron:Int = $0af
Rem
bbdoc:  
End Rem
Const Qt_Key_degree:Int = $0b0
Rem
bbdoc:  
End Rem
Const Qt_Key_plusminus:Int = $0b1
Rem
bbdoc:  
End Rem
Const Qt_Key_twosuperior:Int = $0b2
Rem
bbdoc:  
End Rem
Const Qt_Key_threesuperior:Int = $0b3
Rem
bbdoc:  
End Rem
Const Qt_Key_acute:Int = $0b4
Rem
bbdoc:  
End Rem
Const Qt_Key_mu:Int = $0b5
Rem
bbdoc:  
End Rem
Const Qt_Key_paragraph:Int = $0b6
Rem
bbdoc:  
End Rem
Const Qt_Key_periodcentered:Int = $0b7
Rem
bbdoc:  
End Rem
Const Qt_Key_cedilla:Int = $0b8
Rem
bbdoc:  
End Rem
Const Qt_Key_onesuperior:Int = $0b9
Rem
bbdoc:  
End Rem
Const Qt_Key_masculine:Int = $0ba
Rem
bbdoc:  
End Rem
Const Qt_Key_guillemotright:Int = $0bb
Rem
bbdoc:  
End Rem
Const Qt_Key_onequarter:Int = $0bc
Rem
bbdoc:  
End Rem
Const Qt_Key_onehalf:Int = $0bd
Rem
bbdoc:  
End Rem
Const Qt_Key_threequarters:Int = $0be
Rem
bbdoc:  
End Rem
Const Qt_Key_questiondown:Int = $0bf
Rem
bbdoc:  
End Rem
Const Qt_Key_Agrave:Int = $0c0
Rem
bbdoc:  
End Rem
Const Qt_Key_Aacute:Int = $0c1
Rem
bbdoc:  
End Rem
Const Qt_Key_Acircumflex:Int = $0c2
Rem
bbdoc:  
End Rem
Const Qt_Key_Atilde:Int = $0c3
Rem
bbdoc:  
End Rem
Const Qt_Key_Adiaeresis:Int = $0c4
Rem
bbdoc:  
End Rem
Const Qt_Key_Aring:Int = $0c5
Rem
bbdoc:  
End Rem
Const Qt_Key_AE:Int = $0c6
Rem
bbdoc:  
End Rem
Const Qt_Key_Ccedilla:Int = $0c7
Rem
bbdoc:  
End Rem
Const Qt_Key_Egrave:Int = $0c8
Rem
bbdoc:  
End Rem
Const Qt_Key_Eacute:Int = $0c9
Rem
bbdoc:  
End Rem
Const Qt_Key_Ecircumflex:Int = $0ca
Rem
bbdoc:  
End Rem
Const Qt_Key_Ediaeresis:Int = $0cb
Rem
bbdoc:  
End Rem
Const Qt_Key_Igrave:Int = $0cc
Rem
bbdoc:  
End Rem
Const Qt_Key_Iacute:Int = $0cd
Rem
bbdoc:  
End Rem
Const Qt_Key_Icircumflex:Int = $0ce
Rem
bbdoc:  
End Rem
Const Qt_Key_Idiaeresis:Int = $0cf
Rem
bbdoc:  
End Rem
Const Qt_Key_ETH:Int = $0d0
Rem
bbdoc:  
End Rem
Const Qt_Key_Ntilde:Int = $0d1
Rem
bbdoc:  
End Rem
Const Qt_Key_Ograve:Int = $0d2
Rem
bbdoc:  
End Rem
Const Qt_Key_Oacute:Int = $0d3
Rem
bbdoc:  
End Rem
Const Qt_Key_Ocircumflex:Int = $0d4
Rem
bbdoc:  
End Rem
Const Qt_Key_Otilde:Int = $0d5
Rem
bbdoc:  
End Rem
Const Qt_Key_Odiaeresis:Int = $0d6
Rem
bbdoc:  
End Rem
Const Qt_Key_multiply:Int = $0d7
Rem
bbdoc:  
End Rem
Const Qt_Key_Ooblique:Int = $0d8
Rem
bbdoc:  
End Rem
Const Qt_Key_Ugrave:Int = $0d9
Rem
bbdoc:  
End Rem
Const Qt_Key_Uacute:Int = $0da
Rem
bbdoc:  
End Rem
Const Qt_Key_Ucircumflex:Int = $0db
Rem
bbdoc:  
End Rem
Const Qt_Key_Udiaeresis:Int = $0dc
Rem
bbdoc:  
End Rem
Const Qt_Key_Yacute:Int = $0dd
Rem
bbdoc:  
End Rem
Const Qt_Key_THORN:Int = $0de
Rem
bbdoc:  
End Rem
Const Qt_Key_ssharp:Int = $0df
Rem
bbdoc:  
End Rem
Const Qt_Key_division:Int = $0f7
Rem
bbdoc:  
End Rem
Const Qt_Key_ydiaeresis:Int = $0ff
Rem
bbdoc:  
End Rem
Const Qt_Key_Multi_key:Int = $01001120
Rem
bbdoc:  
End Rem
Const Qt_Key_Codeinput:Int = $01001137
Rem
bbdoc:  
End Rem
Const Qt_Key_SingleCandidate:Int = $0100113c
Rem
bbdoc:  
End Rem
Const Qt_Key_MultipleCandidate:Int = $0100113d
Rem
bbdoc:  
End Rem
Const Qt_Key_PreviousCandidate:Int = $0100113e
Rem
bbdoc:  
End Rem
Const Qt_Key_Mode_switch:Int = $0100117e
Rem
bbdoc:  
End Rem
Const Qt_Key_Kanji:Int = $01001121
Rem
bbdoc:  
End Rem
Const Qt_Key_Muhenkan:Int = $01001122
Rem
bbdoc:  
End Rem
Const Qt_Key_Henkan:Int = $01001123
Rem
bbdoc:  
End Rem
Const Qt_Key_Romaji:Int = $01001124
Rem
bbdoc:  
End Rem
Const Qt_Key_Hiragana:Int = $01001125
Rem
bbdoc:  
End Rem
Const Qt_Key_Katakana:Int = $01001126
Rem
bbdoc:  
End Rem
Const Qt_Key_Hiragana_Katakana:Int = $01001127
Rem
bbdoc:  
End Rem
Const Qt_Key_Zenkaku:Int = $01001128
Rem
bbdoc:  
End Rem
Const Qt_Key_Hankaku:Int = $01001129
Rem
bbdoc:  
End Rem
Const Qt_Key_Zenkaku_Hankaku:Int = $0100112a
Rem
bbdoc:  
End Rem
Const Qt_Key_Touroku:Int = $0100112b
Rem
bbdoc:  
End Rem
Const Qt_Key_Massyo:Int = $0100112c
Rem
bbdoc:  
End Rem
Const Qt_Key_Kana_Lock:Int = $0100112d
Rem
bbdoc:  
End Rem
Const Qt_Key_Kana_Shift:Int = $0100112e
Rem
bbdoc:  
End Rem
Const Qt_Key_Eisu_Shift:Int = $0100112f
Rem
bbdoc:  
End Rem
Const Qt_Key_Eisu_toggle:Int = $01001130
Rem
bbdoc:  
End Rem
Const Qt_Key_Hangul:Int = $01001131
Rem
bbdoc:  
End Rem
Const Qt_Key_Hangul_Start:Int = $01001132
Rem
bbdoc:  
End Rem
Const Qt_Key_Hangul_End:Int = $01001133
Rem
bbdoc:  
End Rem
Const Qt_Key_Hangul_Hanja:Int = $01001134
Rem
bbdoc:  
End Rem
Const Qt_Key_Hangul_Jamo:Int = $01001135
Rem
bbdoc:  
End Rem
Const Qt_Key_Hangul_Romaja:Int = $01001136
Rem
bbdoc:  
End Rem
Const Qt_Key_Hangul_Jeonja:Int = $01001138
Rem
bbdoc:  
End Rem
Const Qt_Key_Hangul_Banja:Int = $01001139
Rem
bbdoc:  
End Rem
Const Qt_Key_Hangul_PreHanja:Int = $0100113a
Rem
bbdoc:  
End Rem
Const Qt_Key_Hangul_PostHanja:Int = $0100113b
Rem
bbdoc:  
End Rem
Const Qt_Key_Hangul_Special:Int = $0100113f
Rem
bbdoc:  
End Rem
Const Qt_Key_Dead_Grave:Int = $01001250
Rem
bbdoc:  
End Rem
Const Qt_Key_Dead_Acute:Int = $01001251
Rem
bbdoc:  
End Rem
Const Qt_Key_Dead_Circumflex:Int = $01001252
Rem
bbdoc:  
End Rem
Const Qt_Key_Dead_Tilde:Int = $01001253
Rem
bbdoc:  
End Rem
Const Qt_Key_Dead_Macron:Int = $01001254
Rem
bbdoc:  
End Rem
Const Qt_Key_Dead_Breve:Int = $01001255
Rem
bbdoc:  
End Rem
Const Qt_Key_Dead_Abovedot:Int = $01001256
Rem
bbdoc:  
End Rem
Const Qt_Key_Dead_Diaeresis:Int = $01001257
Rem
bbdoc:  
End Rem
Const Qt_Key_Dead_Abovering:Int = $01001258
Rem
bbdoc:  
End Rem
Const Qt_Key_Dead_Doubleacute:Int = $01001259
Rem
bbdoc:  
End Rem
Const Qt_Key_Dead_Caron:Int = $0100125a
Rem
bbdoc:  
End Rem
Const Qt_Key_Dead_Cedilla:Int = $0100125b
Rem
bbdoc:  
End Rem
Const Qt_Key_Dead_Ogonek:Int = $0100125c
Rem
bbdoc:  
End Rem
Const Qt_Key_Dead_Iota:Int = $0100125d
Rem
bbdoc:  
End Rem
Const Qt_Key_Dead_Voiced_Sound:Int = $0100125e
Rem
bbdoc:  
End Rem
Const Qt_Key_Dead_Semivoiced_Sound:Int = $0100125f
Rem
bbdoc:  
End Rem
Const Qt_Key_Dead_Belowdot:Int = $01001260
Rem
bbdoc:  
End Rem
Const Qt_Key_Dead_Hook:Int = $01001261
Rem
bbdoc:  
End Rem
Const Qt_Key_Dead_Horn:Int = $01001262
Rem
bbdoc:  
End Rem
Const Qt_Key_Back:Int = $01000061
Rem
bbdoc:  
End Rem
Const Qt_Key_Forward:Int = $01000062
Rem
bbdoc:  
End Rem
Const Qt_Key_Stop:Int = $01000063
Rem
bbdoc:  
End Rem
Const Qt_Key_Refresh:Int = $01000064
Rem
bbdoc:  
End Rem
Const Qt_Key_VolumeDown:Int = $01000070
Rem
bbdoc:  
End Rem
Const Qt_Key_VolumeMute:Int = $01000071
Rem
bbdoc:  
End Rem
Const Qt_Key_VolumeUp:Int = $01000072
Rem
bbdoc:  
End Rem
Const Qt_Key_BassBoost:Int = $01000073
Rem
bbdoc:  
End Rem
Const Qt_Key_BassUp:Int = $01000074
Rem
bbdoc:  
End Rem
Const Qt_Key_BassDown:Int = $01000075
Rem
bbdoc:  
End Rem
Const Qt_Key_TrebleUp:Int = $01000076
Rem
bbdoc:  
End Rem
Const Qt_Key_TrebleDown:Int = $01000077
Rem
bbdoc: A key setting the state of the media player to play
End Rem
Const Qt_Key_MediaPlay:Int = $01000080
Rem
bbdoc: A key setting the state of the media player to stop
End Rem
Const Qt_Key_MediaStop:Int = $01000081
Rem
bbdoc:  
End Rem
Const Qt_Key_MediaPrevious:Int = $01000082
Rem
bbdoc:  
End Rem
Const Qt_Key_MediaNext:Int = $01000083
Rem
bbdoc:  
End Rem
Const Qt_Key_MediaRecord:Int = $01000084
Rem
bbdoc: A key setting the state of the media player to pause (Note: not the pause/break key)
End Rem
Const Qt_Key_MediaPause:Int = $1000085
Rem
bbdoc: A key to toggle the play/pause state in the media player (rather than setting an absolute state)
End Rem
Const Qt_Key_MediaTogglePlayPause:Int = $1000086
Rem
bbdoc:  
End Rem
Const Qt_Key_HomePage:Int = $01000090
Rem
bbdoc:  
End Rem
Const Qt_Key_Favorites:Int = $01000091
Rem
bbdoc:  
End Rem
Const Qt_Key_Search:Int = $01000092
Rem
bbdoc:  
End Rem
Const Qt_Key_Standby:Int = $01000093
Rem
bbdoc:  
End Rem
Const Qt_Key_OpenUrl:Int = $01000094
Rem
bbdoc:  
End Rem
Const Qt_Key_LaunchMail:Int = $010000a0
Rem
bbdoc:  
End Rem
Const Qt_Key_LaunchMedia:Int = $010000a1
Rem
bbdoc: On X11 this key is mapped to "My Computer" (XF86XK_MyComputer) key for legacy reasons.
End Rem
Const Qt_Key_Launch0:Int = $010000a2
Rem
bbdoc: On X11 this key is mapped to "Calculator" (XF86XK_Calculator) key for legacy reasons.
End Rem
Const Qt_Key_Launch1:Int = $010000a3
Rem
bbdoc: On X11 this key is mapped to XF86XK_Launch0 key for legacy reasons.
End Rem
Const Qt_Key_Launch2:Int = $010000a4
Rem
bbdoc: On X11 this key is mapped to XF86XK_Launch1 key for legacy reasons.
End Rem
Const Qt_Key_Launch3:Int = $010000a5
Rem
bbdoc: On X11 this key is mapped to XF86XK_Launch2 key for legacy reasons.
End Rem
Const Qt_Key_Launch4:Int = $010000a6
Rem
bbdoc: On X11 this key is mapped to XF86XK_Launch3 key for legacy reasons.
End Rem
Const Qt_Key_Launch5:Int = $010000a7
Rem
bbdoc: On X11 this key is mapped to XF86XK_Launch4 key for legacy reasons.
End Rem
Const Qt_Key_Launch6:Int = $010000a8
Rem
bbdoc: On X11 this key is mapped to XF86XK_Launch5 key for legacy reasons.
End Rem
Const Qt_Key_Launch7:Int = $010000a9
Rem
bbdoc: On X11 this key is mapped to XF86XK_Launch6 key for legacy reasons.
End Rem
Const Qt_Key_Launch8:Int = $010000aa
Rem
bbdoc: On X11 this key is mapped to XF86XK_Launch7 key for legacy reasons.
End Rem
Const Qt_Key_Launch9:Int = $010000ab
Rem
bbdoc: On X11 this key is mapped to XF86XK_Launch8 key for legacy reasons.
End Rem
Const Qt_Key_LaunchA:Int = $010000ac
Rem
bbdoc: On X11 this key is mapped to XF86XK_Launch9 key for legacy reasons.
End Rem
Const Qt_Key_LaunchB:Int = $010000ad
Rem
bbdoc: On X11 this key is mapped to XF86XK_LaunchA key for legacy reasons.
End Rem
Const Qt_Key_LaunchC:Int = $010000ae
Rem
bbdoc: On X11 this key is mapped to XF86XK_LaunchB key for legacy reasons.
End Rem
Const Qt_Key_LaunchD:Int = $010000af
Rem
bbdoc: On X11 this key is mapped to XF86XK_LaunchC key for legacy reasons.
End Rem
Const Qt_Key_LaunchE:Int = $010000b0
Rem
bbdoc: On X11 this key is mapped to XF86XK_LaunchD key for legacy reasons.
End Rem
Const Qt_Key_LaunchF:Int = $010000b1
Rem
bbdoc: On X11 this key is mapped to XF86XK_LaunchE key for legacy reasons.
End Rem
Const Qt_Key_LaunchG:Int = $0100010e
Rem
bbdoc: On X11 this key is mapped to XF86XK_LaunchF key for legacy reasons.
End Rem
Const Qt_Key_LaunchH:Int = $0100010f
Rem
bbdoc:  
End Rem
Const Qt_Key_MonBrightnessUp:Int = $010000b2
Rem
bbdoc:  
End Rem
Const Qt_Key_MonBrightnessDown:Int = $010000b3
Rem
bbdoc:  
End Rem
Const Qt_Key_KeyboardLightOnOff:Int = $010000b4
Rem
bbdoc:  
End Rem
Const Qt_Key_KeyboardBrightnessUp:Int = $010000b5
Rem
bbdoc:  
End Rem
Const Qt_Key_KeyboardBrightnessDown:Int = $010000b6
Rem
bbdoc:  
End Rem
Const Qt_Key_PowerOff:Int = $010000b7
Rem
bbdoc:  
End Rem
Const Qt_Key_WakeUp:Int = $010000b8
Rem
bbdoc:  
End Rem
Const Qt_Key_Eject:Int = $010000b9
Rem
bbdoc:  
End Rem
Const Qt_Key_ScreenSaver:Int = $010000ba
Rem
bbdoc:  
End Rem
Const Qt_Key_WWW:Int = $010000bb
Rem
bbdoc:  
End Rem
Const Qt_Key_Memo:Int = $010000bc
Rem
bbdoc:  
End Rem
Const Qt_Key_LightBulb:Int = $010000bd
Rem
bbdoc:  
End Rem
Const Qt_Key_Shop:Int = $010000be
Rem
bbdoc:  
End Rem
Const Qt_Key_History:Int = $010000bf
Rem
bbdoc:  
End Rem
Const Qt_Key_AddFavorite:Int = $010000c0
Rem
bbdoc:  
End Rem
Const Qt_Key_HotLinks:Int = $010000c1
Rem
bbdoc:  
End Rem
Const Qt_Key_BrightnessAdjust:Int = $010000c2
Rem
bbdoc:  
End Rem
Const Qt_Key_Finance:Int = $010000c3
Rem
bbdoc:  
End Rem
Const Qt_Key_Community:Int = $010000c4
Rem
bbdoc:  
End Rem
Const Qt_Key_AudioRewind:Int = $010000c5
Rem
bbdoc:  
End Rem
Const Qt_Key_BackForward:Int = $010000c6
Rem
bbdoc:  
End Rem
Const Qt_Key_ApplicationLeft:Int = $010000c7
Rem
bbdoc:  
End Rem
Const Qt_Key_ApplicationRight:Int = $010000c8
Rem
bbdoc:  
End Rem
Const Qt_Key_Book:Int = $010000c9
Rem
bbdoc:  
End Rem
Const Qt_Key_CD:Int = $010000ca
Rem
bbdoc: On X11 this key is not mapped for legacy reasons. Use Qt::Key_Launch1 instead.
End Rem
Const Qt_Key_Calculator:Int = $010000cb
Rem
bbdoc:  
End Rem
Const Qt_Key_ToDoList:Int = $010000cc
Rem
bbdoc:  
End Rem
Const Qt_Key_ClearGrab:Int = $010000cd
Rem
bbdoc:  
End Rem
Const Qt_Key_Close:Int = $010000ce
Rem
bbdoc:  
End Rem
Const Qt_Key_Copy:Int = $010000cf
Rem
bbdoc:  
End Rem
Const Qt_Key_Cut:Int = $010000d0
Rem
bbdoc:  
End Rem
Const Qt_Key_Display:Int = $010000d1
Rem
bbdoc:  
End Rem
Const Qt_Key_DOS:Int = $010000d2
Rem
bbdoc:  
End Rem
Const Qt_Key_Documents:Int = $010000d3
Rem
bbdoc:  
End Rem
Const Qt_Key_Excel:Int = $010000d4
Rem
bbdoc:  
End Rem
Const Qt_Key_Explorer:Int = $010000d5
Rem
bbdoc:  
End Rem
Const Qt_Key_Game:Int = $010000d6
Rem
bbdoc:  
End Rem
Const Qt_Key_Go:Int = $010000d7
Rem
bbdoc:  
End Rem
Const Qt_Key_iTouch:Int = $010000d8
Rem
bbdoc:  
End Rem
Const Qt_Key_LogOff:Int = $010000d9
Rem
bbdoc:  
End Rem
Const Qt_Key_Market:Int = $010000da
Rem
bbdoc:  
End Rem
Const Qt_Key_Meeting:Int = $010000db
Rem
bbdoc:  
End Rem
Const Qt_Key_MenuKB:Int = $010000dc
Rem
bbdoc:  
End Rem
Const Qt_Key_MenuPB:Int = $010000dd
Rem
bbdoc:  
End Rem
Const Qt_Key_MySites:Int = $010000de
Rem
bbdoc:  
End Rem
Const Qt_Key_News:Int = $010000df
Rem
bbdoc:  
End Rem
Const Qt_Key_OfficeHome:Int = $010000e0
Rem
bbdoc:  
End Rem
Const Qt_Key_Option:Int = $010000e1
Rem
bbdoc:  
End Rem
Const Qt_Key_Paste:Int = $010000e2
Rem
bbdoc:  
End Rem
Const Qt_Key_Phone:Int = $010000e3
Rem
bbdoc:  
End Rem
Const Qt_Key_Calendar:Int = $010000e4
Rem
bbdoc:  
End Rem
Const Qt_Key_Reply:Int = $010000e5
Rem
bbdoc:  
End Rem
Const Qt_Key_Reload:Int = $010000e6
Rem
bbdoc:  
End Rem
Const Qt_Key_RotateWindows:Int = $010000e7
Rem
bbdoc:  
End Rem
Const Qt_Key_RotationPB:Int = $010000e8
Rem
bbdoc:  
End Rem
Const Qt_Key_RotationKB:Int = $010000e9
Rem
bbdoc:  
End Rem
Const Qt_Key_Save:Int = $010000ea
Rem
bbdoc:  
End Rem
Const Qt_Key_Send:Int = $010000eb
Rem
bbdoc:  
End Rem
Const Qt_Key_Spell:Int = $010000ec
Rem
bbdoc:  
End Rem
Const Qt_Key_SplitScreen:Int = $010000ed
Rem
bbdoc:  
End Rem
Const Qt_Key_Support:Int = $010000ee
Rem
bbdoc:  
End Rem
Const Qt_Key_TaskPane:Int = $010000ef
Rem
bbdoc:  
End Rem
Const Qt_Key_Terminal:Int = $010000f0
Rem
bbdoc:  
End Rem
Const Qt_Key_Tools:Int = $010000f1
Rem
bbdoc:  
End Rem
Const Qt_Key_Travel:Int = $010000f2
Rem
bbdoc:  
End Rem
Const Qt_Key_Video:Int = $010000f3
Rem
bbdoc:  
End Rem
Const Qt_Key_Word:Int = $010000f4
Rem
bbdoc:  
End Rem
Const Qt_Key_Xfer:Int = $010000f5
Rem
bbdoc:  
End Rem
Const Qt_Key_ZoomIn:Int = $010000f6
Rem
bbdoc:  
End Rem
Const Qt_Key_ZoomOut:Int = $010000f7
Rem
bbdoc:  
End Rem
Const Qt_Key_Away:Int = $010000f8
Rem
bbdoc:  
End Rem
Const Qt_Key_Messenger:Int = $010000f9
Rem
bbdoc:  
End Rem
Const Qt_Key_WebCam:Int = $010000fa
Rem
bbdoc:  
End Rem
Const Qt_Key_MailForward:Int = $010000fb
Rem
bbdoc:  
End Rem
Const Qt_Key_Pictures:Int = $010000fc
Rem
bbdoc:  
End Rem
Const Qt_Key_Music:Int = $010000fd
Rem
bbdoc:  
End Rem
Const Qt_Key_Battery:Int = $010000fe
Rem
bbdoc:  
End Rem
Const Qt_Key_Bluetooth:Int = $010000ff
Rem
bbdoc:  
End Rem
Const Qt_Key_WLAN:Int = $01000100
Rem
bbdoc:  
End Rem
Const Qt_Key_UWB:Int = $01000101
Rem
bbdoc:  
End Rem
Const Qt_Key_AudioForward:Int = $01000102
Rem
bbdoc:  
End Rem
Const Qt_Key_AudioRepeat:Int = $01000103
Rem
bbdoc:  
End Rem
Const Qt_Key_AudioRandomPlay:Int = $01000104
Rem
bbdoc:  
End Rem
Const Qt_Key_Subtitle:Int = $01000105
Rem
bbdoc:  
End Rem
Const Qt_Key_AudioCycleTrack:Int = $01000106
Rem
bbdoc:  
End Rem
Const Qt_Key_Time:Int = $01000107
Rem
bbdoc:  
End Rem
Const Qt_Key_Hibernate:Int = $01000108
Rem
bbdoc:  
End Rem
Const Qt_Key_View:Int = $01000109
Rem
bbdoc:  
End Rem
Const Qt_Key_TopMenu:Int = $0100010a
Rem
bbdoc:  
End Rem
Const Qt_Key_PowerDown:Int = $0100010b
Rem
bbdoc:  
End Rem
Const Qt_Key_Suspend:Int = $0100010c
Rem
bbdoc:  
End Rem
Const Qt_Key_ContrastAdjust:Int = $0100010d
Rem
bbdoc:  
End Rem
Const Qt_Key_MediaLast:Int = $0100ffff
Rem
bbdoc:  
End Rem
Const Qt_Key_unknown:Int = $01ffffff
Rem
bbdoc: A key to answer or initiate a call (see Qt::Key_ToggleCallHangup for a key to toggle current call state)
End Rem
Const Qt_Key_Call:Int = $01100004
Rem
bbdoc: A key to activate the camera shutter
End Rem
Const Qt_Key_Camera:Int = $01100020
Rem
bbdoc: A key to focus the camera
End Rem
Const Qt_Key_CameraFocus:Int = $01100021
Rem
bbdoc:  
End Rem
Const Qt_Key_Context1:Int = $01100000
Rem
bbdoc:  
End Rem
Const Qt_Key_Context2:Int = $01100001
Rem
bbdoc:  
End Rem
Const Qt_Key_Context3:Int = $01100002
Rem
bbdoc:  
End Rem
Const Qt_Key_Context4:Int = $01100003
Rem
bbdoc:  
End Rem
Const Qt_Key_Flip:Int = $01100006
Rem
bbdoc: A key to end an ongoing call (see Qt::Key_ToggleCallHangup for a key to toggle current call state)
End Rem
Const Qt_Key_Hangup:Int = $01100005
Rem
bbdoc:  
End Rem
Const Qt_Key_No:Int = $01010002
Rem
bbdoc:  
End Rem
Const Qt_Key_Select:Int = $01010000
Rem
bbdoc:  
End Rem
Const Qt_Key_Yes:Int = $01010001
Rem
bbdoc: A key to toggle the current call state (ie. either answer, or hangup) depending on current call state
End Rem
Const Qt_Key_ToggleCallHangup:Int = $01100007
Rem
bbdoc:  
End Rem
Const Qt_Key_VoiceDial:Int = $01100008
Rem
bbdoc:  
End Rem
Const Qt_Key_LastNumberRedial:Int = $01100009
Rem
bbdoc:  
End Rem
Const Qt_Key_Execute:Int = $01020003
Rem
bbdoc:  
End Rem
Const Qt_Key_Printer:Int = $01020002
Rem
bbdoc:  
End Rem
Const Qt_Key_Play:Int = $01020005
Rem
bbdoc:  
End Rem
Const Qt_Key_Sleep:Int = $01020004
Rem
bbdoc:  
End Rem
Const Qt_Key_Zoom:Int = $01020006
Rem
bbdoc:  
End Rem
Const Qt_Key_Cancel:Int = $01020001

