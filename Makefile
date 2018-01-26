objects = wordSysPat.o watchRecited.o wordSqlLogin.o \
	wordSysSetPlan.o wordSysExit.o wordSysShow.o \
	my_dil.o wordRecite.o wordSysLogin.o \
	wordSysMain.o wordTest.o

wordSystem : $(objects)	
	cc -o   wordSystem $(objects)
wordSysPat.o :  wordSystem.h
watchRecite.o : mydil.h
wordSysSetPlan.o : mydil.h
wordSysShow.o : wordSystem.h
wordRecite.o : mydil.h
wordSysLogin.o : wordSystem.h mydil.h
wordSysMain.o : wordSystem.h

install :
	cp wordSystem  /usr/bin/my_wordSystem
remove :
	-rm -f /usr/bin/my_wordSystem
.PHONY :clean
clean :
	-rm wordSystem $(objects)

