SuperStrict 
'Import maxgui.drivers
Framework qt.qtmaxgui
Import brl.eventqueue
Import brl.ramstream
Import brl.pngloader


Local splash:TGadget=CreateWindow("MaxIDE",200,200,400,140,Null,WINDOW_HIDDEN|WINDOW_CLIENTCOORDS|WINDOW_HIDDEN|WINDOW_CENTER)
			Local panel:TGadget = CreatePanel(0,0,ClientWidth(splash),ClientHeight(splash),splash,0)
			SetPanelColor panel,255,255,255;SetPanelPixmap panel, LoadPixmapPNG("splash.png"), PANELPIXMAP_FIT2
			Local progress:TGadget = CreateProgBar(2,ClientHeight(panel)-22,ClientWidth(panel)-4,20,panel)
			
			ShowGadget splash
			PollSystem

Repeat
	WaitEvent()
	Select EventID()
		Case EVENT_GADGETACTION
		Case EVENT_WINDOWCLOSE
			End
	EndSelect
Forever
