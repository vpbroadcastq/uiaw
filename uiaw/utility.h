#pragma once
//
// utility.h
// Utility types and functions for Uiaw.  NOT wrappers for anyting in UIA; these are custom types that are
// entirely the createion of the Uiaw project.
//
#include <cstdint>

namespace Uiaw {
enum class FailMode {
	Silent,
	Terminate,
};

struct ErrorCode {
	int32_t value{};
};

template <typename T>
struct Result {
	T value{};
	ErrorCode error{};
};


} // namespace Uiaw