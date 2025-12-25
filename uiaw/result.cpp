#include "result.h"
#include "uia_all.h"


namespace Uiaw {

[[nodiscard]] bool ErrorCode::IsError() const noexcept {
	return !SUCCEEDED(static_cast<HRESULT>(value));
}


} // namespace Uiaw

