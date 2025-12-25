#pragma once
//
// utility.h
// Utility types and functions for Uiaw.  NOT wrappers for anyting in UIA; these are custom types that are
// entirely the createion of the Uiaw project.
//
#include "result.h"

#include <cstdint>
#include <utility>
#include <cstdlib>

namespace Uiaw {
enum class FailMode {
	Silent,
	Terminate,
};



} // namespace Uiaw