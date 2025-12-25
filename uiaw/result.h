#pragma once
#include <cstdint>
#include <utility>
#include <cstdlib>


namespace Uiaw {


struct ErrorCode {
	int32_t value{};
	[[nodiscard]] bool IsError() const noexcept;
};

template <typename T>
requires (!std::is_reference_v<T>)
class Result {
	union {
		T value;
	};
	ErrorCode error{};

public:
    Result() = delete;

	Result(T&& v) noexcept(std::is_nothrow_move_constructible_v<T>) {
        new (&value) T(std::move(v));
        error = ErrorCode{};
    }

	Result(const ErrorCode& e) : error(e) {
		AbortIfNotError();
	}

	Result(const Result<T>& rhs ) noexcept(std::is_nothrow_copy_constructible_v<T>)
    requires (std::is_copy_constructible_v<T>) {
		if (!rhs.error.IsError()) {
			new (&value) T(rhs.value);
		}
		error = rhs.error;
	}

	Result(Result<T>&& rhs ) noexcept(std::is_nothrow_move_constructible_v<T>)
    requires (std::is_move_constructible_v<T>) {
		if (!rhs.error.IsError()) {
			new (&value) T(std::move(rhs.value));
		}
		error = rhs.error;
	}

	Result<T>& operator=(const Result<T>& rhs) noexcept(std::is_nothrow_copy_constructible_v<T>)
    requires (std::is_copy_constructible_v<T>) {
		if (this == &rhs) {
			return *this;
		}

		if (!this->error.IsError() && !rhs.error.IsError()) {
            value.~T();
            new (&value) T(rhs.value);
		} else if (this->error.IsError() && !rhs.error.IsError()) {
            new (&value) T(rhs.value);
        } else if (!this->error.IsError() && rhs.error.IsError()) {
            this->value.~T();
        }
		error = rhs.error;

		return *this;
	}

	Result<T>& operator=(Result<T>&& rhs) noexcept(std::is_nothrow_move_constructible_v<T>)
    requires (std::is_move_constructible_v<T>) {
		if (this == &rhs) {
			return *this;
		}

		if (!this->error.IsError() && !rhs.error.IsError()) {
            value.~T();
            new (&value) T(std::move(rhs.value));
		} else if (this->error.IsError() && !rhs.error.IsError()) {
            new (&value) T(std::move(rhs.value));
        } else if (!this->error.IsError() && rhs.error.IsError()) {
            this->value.~T();
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
	T& Value() {
		AbortIfError();
		return value;
	}

	const T& Value() const {
		AbortIfError();
		return value;
	}

    // I'd just call std::move(.Value()) on a non-const object
    //T&& ExtractValue() noexcept {
    //    AbortIfError();
    //    return std::move(value);
    //}

	[[nodiscard]] ErrorCode Error() const noexcept {
		return error;
	}

	[[nodiscard]] explicit operator bool() const noexcept {
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


