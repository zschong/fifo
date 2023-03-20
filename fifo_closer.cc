
#include <stdio.h>
#include "fifo_closer.h"


FifoCloser::FifoCloser(const std::string& name) : name_(name) {}

FifoCloser::~FifoCloser(void) {
	Close();
}

bool FifoCloser::Open(void) {
	fd_ = open(name_.data(), O_RDONLY);
	if (fd_ == -1) {
		perror("open:");
		return false;
	}
	return true;
}

bool FifoCloser::Close(void) {
	int ret = close(fd_);
	if (ret == 0) {
		fd_ = -1;
	}
	return ret == 0;
}

