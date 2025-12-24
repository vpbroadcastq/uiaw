#pragma once
//
// utility.h
// Utility types and functions for Uiaw.  NOT wrappers for anyting in UIA; these are custom types that are
// entirely the createion of the Uiaw project.
//
#include <cstdint>
#include <utility>
#include <cstdlib>

namespace Uiaw {
enum class FailMode {
	Silent,
	Terminate,
};

struct ErrorCode {
	int32_t value{};
	[[nodiscard]] bool IsError() const noexcept;
};

template <typename T>
class Result {
	union {
		T value;
	};
	ErrorCode error{};

public:
	Result(T&& v) : value(std::move(v)), error{} {}
	Result(const ErrorCode& e) : error(e) {
		AbortIfNotError();
	}

	Result(const Result<T>& rhs ) {
		if (!rhs.error.IsError()) {
			value = rhs.value;
		}
		error = rhs.error;
	}

	Result(const Result<T>&& rhs ) {
		if (!rhs.error.IsError()) {
			value = std::move(rhs.value);
		}
		error = rhs.error;
	}

	Result<T>& operator=(const Result<T>& rhs) {
		if (this == &rhs) {
			return *this;
		}

		if (!this->error.IsError()) {
			this->value.~T();
		}

		if (!rhs.error.IsError()) {
			value = rhs.value;
		}
		error = rhs.error;

		return *this;
	}

	Result<T>& operator=(Result<T>&& rhs) {
		if (this == &rhs) {
			return *this;
		}

		if (!this->error.IsError()) {
			this->value.~T();
		}

		if (!rhs.error.IsError()) {
			value = std::move(rhs.value);
		}
		error = rhs.error;

		return *this;
	}

	~Result() {
		if (!error.IsError()) {
			value.~T();
		}
	}

	//
	// Getters
	//
	[[nodiscard]] T& Value() {
		AbortIfError();
		return value;
	}

	[[nodiscard]] const T& Value() const {
		AbortIfError();
		return value;
	}

	[[nodiscard]] ErrorCode Error() const noexcept {
		return error;
	}

	[[nodiscard]] operator bool() const noexcept {
		return !error.IsError();
	}

	void AbortIfError() const noexcept {
		if (error.IsError()) {
			std::abort();
		}
	}
	void AbortIfNotError() const noexcept {
		if (!error.IsError()) {
			std::abort();
		}
	}
};


} // namespace Uiaw