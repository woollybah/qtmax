' createcanvas.bmx

'Import MaxGui.Drivers
Framework Qt.QtMaxGUI
Import BRL.EventQueue
Import brl.glmax2d
Import brl.timer

Strict 

Global GAME_WIDTH=320
Global GAME_HEIGHT=240

' create a centered window with client size GAME_WIDTH,GAME_HEIGHT
'DebugStop
'Local wx=(ClientWidth(Desktop())-GAME_WIDTH)/2
'Local wy=(ClientHeight(Desktop())-GAME_HEIGHT)/2
Local wx=100
Local wy=100

'DebugStop
Local window:TGadget=CreateWindow("My Canvas",wx,wy,GAME_WIDTH,GAME_HEIGHT,Null,WINDOW_TITLEBAR)'|WINDOW_CLIENTCOORDS)

' create a canvas for our game
'DebugStop
Local canvas:TGadget=CreateCanvas(0,0,320,240,window)

' create an update timer

CreateTimer 60

While WaitEvent()
	Select EventID()
		Case EVENT_TIMERTICK
			RedrawGadget canvas

		Case EVENT_GADGETPAINT
'DebugLog "EVENT_GADGETPAINT"
'DebugStop
			SetGraphics CanvasGraphics(canvas)
			SetOrigin 160,120
			SetLineWidth 5
			Cls
			Local t=MilliSecs()
			DrawLine 0,0,120*Cos(t),120*Sin(t)
			DrawLine 0,0,80*Cos(t/60),80*Sin(t/60)
			Flip

		Case EVENT_MOUSEMOVE
			Print "MOVE!"

		Case EVENT_WINDOWCLOSE
			FreeGadget canvas
			End

		Case EVENT_APPTERMINATE
			End
	End Select
Wend
