fifo.exe: fifo.cc fifo_reader.cc fifo_closer.cc
	g++ $+ -o $@

clean:
	rm -rf *.exe
