#include "fifo_reader.h"

int main(void) {
	FifoReader fifo("/tmp/motion");

	fifo.Open();
	while(1) {
		auto data = fifo.Read();
		if (data == nullptr) {
			fifo.Close();
			fifo.Open();
			continue;
		}
		printf("%3ld: %s", data->size(), data->data());
	}

	return 0;
}
