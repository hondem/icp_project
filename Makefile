chess: src/* src/FigureType/* src/Utils/*
	$(MAKE) -C src

clean:
	rm -rf chess.app
	rm -rf gui-compiled

runOSX:
	./chess.app/Contents/MacOS/chess