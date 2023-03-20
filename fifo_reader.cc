#include "fifo_reader.h"

auto FifoReader::Read(void) const -> std::shared_ptr<std::string> {
	auto buf = std::make_shared<std::string>(1024, 0);
	int ret  = read(fd_, (uint8_t*)buf->data(), buf->size());

	if (ret > 0) {
		buf->resize(ret);
		return buf;
	}
	return nullptr;
}

