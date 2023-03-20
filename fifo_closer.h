#pragma once

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <string>

class FifoCloser {
 public:
 	FifoCloser(void) = delete;
 	explicit FifoCloser(const std::string& name);
	~FifoCloser(void);
 	bool Open(void);
	bool Close(void);

 protected:
 	std::string name_;
 	int fd_ = -1;
};


