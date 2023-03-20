#pragma once

#include <memory>
#include "fifo_closer.h"

class FifoReader : public FifoCloser {
 public:
 	explicit FifoReader(const std::string& name) : FifoCloser(name) {}
	auto Read(void) const -> std::shared_ptr<std::string>;
};

