OBJS = banque.o consommable.o ecole.o foret.o heros.o jeu.o lieu.o mission.o missioncombat.o missionmaths.o missionobjet.o nonconsommable.o objet.o pnj.o  personnage.o superette.o ville.o 
CC = g++
DEBUG = -g
CFLAGS = -Wall -c $(DEBUG)
LFLAGS = -Wall $(DEBUG)

jeurpj : $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) -o jeurpj
banque.o : banque.hpp heros.hpp jeu.hpp pnj.hpp ville.hpp banque.cpp
	$(CC) $(CFLAGS) Banque.cpp
consommable.o : consommable.cpp consommable.hpp heros.hpp jeu.hpp 
	$(CC) $(CFLAGS) consommable.cpp
ecole.o : ecole.hpp pnj.hpp heros.hpp jeu.hpp ville.hpp ecole.cpp
	$(CC) $(CFLAGS) ecole.cpp
foret.o : foret.cpp foret.hpp pnj.hpp heros.hpp jeu.hpp ville.hpp
	$(CC) $(CFLAGS) foret.cpp
heros.o : heros.cpp heros.hpp jeu.hpp pnj.hpp mission.hpp missionmaths.hpp missioncombat.hpp missionobjet.hpp consommable.hpp nonconsommable.hpp
	$(CC) $(CFLAGS) heros.cpp
jeu.o : jeu.cpp jeu.hpp heros.hpp lieu.hpp objet.hpp consommable.hpp nonconsommable.hpp mission.hpp missionmaths.hpp missionobjet.hpp missioncombat.hpp personnage.hpp pnj.hpp objet.hpp banque.hpp ville.hpp superette.hpp foret.hpp ecole.hpp
	$(CC) $(CFLAGS) jeu.cpp
lieu.o : lieu.cpp lieu.hpp heros.hpp ville.hpp
	$(CC) $(CFLAGS) lieu.cpp
mission.o : mission.cpp mission.hpp jeu.hpp heros.hpp pnj.hpp
	$(CC) $(CFLAGS) mission.cpp
missioncombat.o : missioncombat.cpp missioncombat.hpp heros.hpp pnj.hpp jeu.hpp
	$(CC) $(CFLAGS) missioncombat.cpp
missionmaths.o : missionmaths.cpp missionmaths.hpp jeu.hpp heros.hpp 
	$(CC) $(CFLAGS) missionmaths.cpp
missionobjet.o : missionobjet.cpp missionobjet.hpp jeu.hpp pnj.hpp heros.hpp
	$(CC) $(CFLAGS) missionobjet.cpp
nonconsommable.o : nonconsommable.cpp nonconsommable.hpp jeu.hpp heros.hpp
	$(CC) $(CFLAGS) nonconsommable.cpp
objet.o : objet.cpp objet.hpp heros.hpp jeu.hpp
	$(CC) $(CFLAGS) objet.cpp
personnage.o : personnage.hpp personnage.cpp
	$(CC) $(CFLAGS) personnage.cpp
pnj.o : pnj.hpp pnj.cpp mission.hpp personnage.hpp 
	$(CC) $(CFLAGS) pnj.cpp
superette.o : superette.hpp superette.cpp objet.hpp lieu.hpp pnj.hpp heros.hpp jeu.hpp ville.hpp
	$(CC) $(CFLAGS) superette.cpp
ville.o : ville.hpp lieu.hpp jeu.hpp heros.hpp ville.cpp
	$(CC) $(CFLAGS) ville.cpp
clean:
	\rm *.o *~ jeurpj
