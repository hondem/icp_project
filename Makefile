chess: src/* src/FigureType/* src/Utils/*
	$(MAKE) -C src

clean:
	rm -rf chess.app
	rm -rf gui-compiled
	rm -rf chess doc xdemel01-xbucht28.zip

runOSX:
	./chess.app/Contents/MacOS/chess

doxygen: *
	doxygen Doxyfile

run:
	make chess
	./chess

pack:
	zip -r xdemel01-xbucht28.zip src/* tests/* Doxyfile Makefile README.md
