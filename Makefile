main.exe: main.cpp GameMain.cpp GameInit.cpp GameEnd.cpp mylib.cpp map.cpp Player.cpp Camera.cpp Enemy.cpp Bullet.cpp UserIF.cpp
	bcc32 -W main.cpp GameMain.cpp GameInit.cpp GameEnd.cpp mylib.cpp map.cpp Player.cpp Camera.cpp Enemy.cpp Bullet.cpp UserIF.cpp

GameInit.o:
	GameInit.h
