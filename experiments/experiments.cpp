#include <uiaw/uiaw.h>
#include <uiaw/uia_all.h>


#include <type_traits>

namespace Uiaw {

	IRawElementProviderSimple* x{};

	using PropertyId = int;
	static_assert(std::is_same_v<Uiaw::PropertyId, ::PROPERTYID>);

//
//  RawElementProviderSimple
//
class RawElementProviderSimple {
	void* p_{}; // Pointer to owned IRawElementProviderSimple
	explicit RawElementProviderSimple(void*);
public:
	RawElementProviderSimple(const RawElementProviderSimple&);
	RawElementProviderSimple(RawElementProviderSimple&&);
	RawElementProviderSimple& operator=(const RawElementProviderSimple&);
	RawElementProviderSimple& operator=(RawElementProviderSimple&&);
	~RawElementProviderSimple();

	Uiaw::Result<Uiaw::ProviderOptions> GetProviderOptions();
	Uiaw::Result<IUnknown*> GetPatternProvider(Uiaw::PatternId);
	Uiaw::Result<VARIANT> GetPropertyId(Uiaw::PropertyId);
	Uiaw::Result<Uiaw::RawElementProviderSimple> GetHostRawElementProvider();
};

//
//  RawElementProviderSimple
//
RawElementProviderSimple::RawElementProviderSimple(void* provider) {
	p_ = provider;
}

RawElementProviderSimple::RawElementProviderSimple(const RawElementProviderSimple & rhs) {
	p_ = rhs.p_;
	reinterpret_cast<::IRawElementProviderSimple*>(p_)->AddRef();
}

RawElementProviderSimple::RawElementProviderSimple(RawElementProviderSimple && rhs) {
	p_ = rhs.p_;
	rhs.p_ = nullptr;
}

RawElementProviderSimple& RawElementProviderSimple::operator=(const RawElementProviderSimple& rhs) {
	p_ = rhs.p_;
	reinterpret_cast<::IRawElementProviderSimple*>(p_)->AddRef();
	return *this;
}

RawElementProviderSimple& RawElementProviderSimple::operator=(RawElementProviderSimple&& rhs) {
	p_ = rhs.p_;
	rhs.p_ = nullptr;
	return *this;
}

RawElementProviderSimple::~RawElementProviderSimple() {
	if (p_) {
		reinterpret_cast<::IRawElementProviderSimple*>(p_)->Release();
	}
}

/*Uiaw::Result<Uiaw::ProviderOptions> RawElementProviderSimple::GetProviderOptions() {
	::ProviderOptions result{};
	HRESULT hr = reinterpret_cast<::IRawElementProviderSimple*>(p_)->get_ProviderOptions(&result);
	return { .value = uiaw::ToUiaw(result), .error = ErrorCode {static_cast<int32_t>(hr)} };
}*/

} // namespace Uiaw

int main() {
	using ErrorCode = int32_t;

	constexpr auto y = sizeof(HRESULT);

    return 0;
}

