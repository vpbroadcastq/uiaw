#include "variant.h"

#include <cassert>
#include <new>
#include <utility>

#define NOMINMAX
#include <Windows.h>
#include <oaidl.h>
#include <oleauto.h>

namespace Uiaw {
namespace {
VARIANT* AsVariant(void* p) noexcept {
    return reinterpret_cast<VARIANT*>(p);
}

const VARIANT* AsVariant(const void* p) noexcept {
    return reinterpret_cast<const VARIANT*>(p);
}

// Compile-time ABI checks: these ensure our “Windows-free” public types match.
static_assert(std::is_same_v<DOUBLE, double>, "Win32 DOUBLE must be 'double'.");
static_assert(std::is_same_v<FLOAT, float>,   "Win32 FLOAT must be 'float'.");
static_assert(sizeof(VARIANT_BOOL) == sizeof(VariantBool), "VARIANT_BOOL size mismatch.");
static_assert(std::is_signed_v<VARIANT_BOOL>, "VARIANT_BOOL signedness mismatch (expected signed).");
static_assert(sizeof(VARTYPE) == sizeof(VarTypeUnderlying), "VARTYPE size mismatch.");
static_assert(sizeof(SCODE) == sizeof(SCode), "SCODE size mismatch.");
static_assert(std::is_same_v<DATE, double>, "DATE must be 'double'.");

static_assert(sizeof(CY) == sizeof(Currency), "CY size mismatch.");
static_assert(alignof(CY) <= alignof(Currency), "CY alignment mismatch.");

static_assert(sizeof(DECIMAL) == sizeof(Decimal), "DECIMAL size mismatch (opaque bytes).");
static_assert(alignof(DECIMAL) <= alignof(Decimal), "DECIMAL alignment mismatch.");
} // anonymous namespace

void Variant::StaticAssert() const noexcept {
    static_assert(sizeof(::VARIANT) == ArraySize, "Variant storage buffer too small for VARIANT.");
    static_assert(alignof(::VARIANT) == ArrayAlign, "Variant storage alignment too small for VARIANT.");
}

//
// Private helpers
//
void Variant::Init() noexcept {
    // TODO:  Do i need to placement new here?  start_lifetime_as?
    ::VariantInit(AsVariant(d_.data()));
}

void Variant::NativeClear() noexcept {
    // Do not use VariantClear on uninitialized variants; use VariantInit to initialize a new
    // VARIANTARG or VARIANT.  Variants containing arrays with outstanding references cannot be cleared.
    // Attempts to do so will return an HRESULT containing DISP_E_ARRAYISLOCKED.
    [[maybe_unused]] HRESULT hr = ::VariantClear(AsVariant(d_.data()));
}

// TODO:  Why do i need this???
void Variant::NativeCopyFrom(const Variant& other) {
    HRESULT hr = VariantCopy(AsVariant(d_.data()), AsVariant(other.d_.data()));
    if (FAILED(hr)) {
        // If you prefer exceptions, throw here. For now: assert and clear to a safe state.
        assert(false && "VariantCopy failed");
        NativeClear();
        Init();
    }
}

//
// Constructors
//
Variant::Variant() noexcept {
    Init();
}

Variant::Variant(std::nullptr_t) noexcept {
    Init();
    AsVariant(d_.data())->vt = VT_NULL;
}

//
// Copy & move
//
Variant::Variant(const Variant& other) {
    Init();
    NativeCopyFrom(other);
}

Variant& Variant::operator=(const Variant& rhs) {
    if (this == &rhs) {
        return *this;
    }

    NativeClear();
    Init();
    NativeCopyFrom(rhs);
    return *this;
}

Variant::Variant(Variant&& rhs) noexcept {
    std::memcpy(d_.data(), rhs.d_.data(), sizeof(VARIANT));

    // Does NOT free; just sets to VT_EMPTY
    // TODO:  Verify this
    VariantInit(AsVariant(rhs.d_.data()));
}

Variant& Variant::operator=(Variant&& rhs) noexcept {
    if (this == &rhs) {
        return *this;
    }

    NativeClear();

    std::memcpy(d_.data(), rhs.d_.data(), sizeof(VARIANT));
    VariantInit(AsVariant(rhs.d_.data())); // neuter without freeing (ownership transferred)

    return *this;
}

Variant::~Variant() {
    NativeClear();
}


//
//
//
Uiaw::VarType Variant::Type() const noexcept {
    const ::VARTYPE vt = AsVariant(d_.data())->vt;
    return static_cast<Uiaw::VarType>(static_cast<Uiaw::VarTypeUnderlying>(vt));
}

// TODO:  Needed?
void Variant::Clear() noexcept {
    NativeClear();
    Init();
}

//
// Getters
//
std::optional<std::int16_t> Variant::GetI2() const noexcept {
    const ::VARIANT* pv = AsVariant(d_.data());
    if (pv->vt != VT_I2) {
        return std::nullopt;
    }
    return static_cast<std::int16_t>(pv->iVal);
}

std::optional<std::int32_t> Variant::GetI4() const noexcept {
    const ::VARIANT* pv = AsVariant(d_.data());
    if (pv->vt != VT_I4) {
        return std::nullopt;
    }
    return static_cast<std::int32_t>(pv->lVal);
}

std::optional<std::int64_t> Variant::GetI8() const noexcept {
    const ::VARIANT* pv = AsVariant(d_.data());
    if (pv->vt != VT_I8) {
        return std::nullopt;
    }
    return static_cast<std::int64_t>(pv->llVal);
}

std::optional<std::uint8_t> Variant::GetUi1() const noexcept {
    const ::VARIANT* pv = AsVariant(d_.data());
    if (pv->vt != VT_UI1) {
        return std::nullopt;
    }
    return static_cast<std::uint8_t>(pv->bVal);
}

std::optional<std::uint16_t> Variant::GetUi2() const noexcept {
    const ::VARIANT* pv = AsVariant(d_.data());
    if (pv->vt != VT_UI2) {
        return std::nullopt;
    }
    return static_cast<std::uint16_t>(pv->uiVal);
}

std::optional<std::uint32_t> Variant::GetUi4() const noexcept {
    const ::VARIANT* pv = AsVariant(d_.data());
    if (pv->vt != VT_UI4) {
        return std::nullopt;
    }
    return static_cast<std::uint32_t>(pv->ulVal);
}

std::optional<std::uint64_t> Variant::GetUi8() const noexcept {
    const ::VARIANT* pv = AsVariant(d_.data());
    if (pv->vt != VT_UI8) {
        return std::nullopt;
    }
    return static_cast<std::uint64_t>(pv->ullVal);
}

std::optional<std::int32_t> Variant::GetInt() const noexcept {
    const ::VARIANT* pv = AsVariant(d_.data());
    if (pv->vt != VT_INT) {return std::nullopt;
        return std::nullopt;
    }
    return static_cast<std::int32_t>(pv->intVal);
}

std::optional<std::uint32_t> Variant::GetUint() const noexcept {
    const ::VARIANT* pv = AsVariant(d_.data());
    if (pv->vt != VT_UINT) {
        return std::nullopt;
    }
    return static_cast<std::uint32_t>(pv->uintVal);
}

std::optional<float> Variant::GetR4() const noexcept {
    const ::VARIANT* pv = AsVariant(d_.data());
    if (pv->vt != VT_R4) {
        return std::nullopt;
    }
    return static_cast<float>(pv->fltVal);
}

std::optional<double> Variant::GetR8() const noexcept {
    const ::VARIANT* pv = AsVariant(d_.data());
    if (pv->vt != VT_R8) {
        return std::nullopt;
    }
    return static_cast<double>(pv->dblVal);
}

std::optional<bool> Variant::GetBool() const noexcept {
    const ::VARIANT* pv = AsVariant(d_.data());
    if (pv->vt != VT_BOOL) {
        return std::nullopt;
    }
    return pv->boolVal != VARIANT_FALSE;
}

std::optional<SCode> Variant::GetScodex() const noexcept {
    const ::VARIANT* pv = AsVariant(d_.data());
    if (pv->vt != VT_ERROR) {
        return std::nullopt;
    }
    return static_cast<SCode>(pv->scode);
}

std::optional<Currency> Variant::GetCurrency() const noexcept {
    const ::VARIANT* pv = AsVariant(d_.data());
    if (pv->vt != VT_CY) {
        return std::nullopt;
    }
    Currency c{};
    c.int64 = static_cast<std::int64_t>(pv->cyVal.int64);
    return c;
}

std::optional<Date> Variant::GetDate() const noexcept {
    const ::VARIANT* pv = AsVariant(d_.data());
    if (pv->vt != VT_DATE) {
        return std::nullopt;
    }
    return static_cast<Date>(pv->date);
}

// TODO:  optional<BStr>?  Can it have a nullptr w/ type BSTR?
BStr Variant::GetBstr() const noexcept {
    const ::VARIANT* pv = AsVariant(d_.data());
    if (pv->vt != VT_BSTR) {
        return nullptr;
    }
    return reinterpret_cast<BStr>(pv->bstrVal);
}

// TODO:  optional<IUnknown*>?  Can it have a nullptr w/ type IUnknown?
IUnknown* Variant::GetUnknown() const noexcept {
    const ::VARIANT* pv = AsVariant(d_.data());
    if (pv->vt != VT_UNKNOWN) { 
        return nullptr;
    }
    return reinterpret_cast<IUnknown*>(pv->punkVal);
}

// TODO:  optional<IDispatch*>?  Can it have a nullptr w/ type IDispatch?
IDispatch* Variant::GetDispatch() const noexcept {
    const ::VARIANT* pv = AsVariant(d_.data());
    if (pv->vt != VT_DISPATCH) {
        return nullptr;
    }
    return reinterpret_cast<IDispatch*>(pv->pdispVal);
}

// TODO:  optional<SAFEARRAY*>?  Can it have a nullptr w/ type SAFEARRAY?
void* Variant::GetSafearray() const noexcept {
    const ::VARIANT* pv = AsVariant(d_.data());
    if ((pv->vt & VT_ARRAY) == 0) {
        return nullptr;
    }
    return reinterpret_cast<SAFEARRAY*>(pv->parray);
}

//TODO:  optional<void*>?  Can it have a nullptr w/ type Byref?
void* Variant::GetByref() const noexcept {
    const ::VARIANT* pv = AsVariant(d_.data());
    if ((pv->vt & VT_BYREF) == 0) {
        return nullptr;
    }
    return pv->byref;
}


//
// Static factories
// These named functions exist (rather than constructors overloaded on the argument type) because
// VARIANT considers things like 'int' and 'int32_t' to be different types, so overload resolution
// would probably be extreemely confusing if it worked at all.
//

// TODO:  SHORT <=> int16_t?  Would 'short' be better?
Variant Variant::FromI2(std::int16_t v) {
    Variant out;
    ::VARIANT* pv = AsVariant(out.d_.data());
    pv->vt = VT_I2;
    pv->iVal = static_cast<SHORT>(v);
    return out;
}

Variant Variant::FromI4(std::int32_t v) {
    Variant out;
    ::VARIANT* pv = AsVariant(out.d_.data());
    pv->vt = VT_I4;
    pv->lVal = static_cast<LONG>(v);
    return out;
}

Variant Variant::FromI8(std::int64_t v) {
    Variant out;
    ::VARIANT* pv = AsVariant(out.d_.data());
    pv->vt = VT_I8;
    pv->llVal = static_cast<LONGLONG>(v);
    return out;
}

Variant Variant::FromUi1(std::uint8_t v) {
    Variant out;
    ::VARIANT* pv = AsVariant(out.d_.data());
    pv->vt = VT_UI1;
    pv->bVal = static_cast<BYTE>(v);
    return out;
}

Variant Variant::FromUi2(std::uint16_t v) {
    Variant out;
    ::VARIANT* pv = AsVariant(out.d_.data());
    pv->vt = VT_UI2;
    pv->uiVal = static_cast<USHORT>(v);
    return out;
}

Variant Variant::FromUi4(std::uint32_t v) {
    Variant out;
    ::VARIANT* pv = AsVariant(out.d_.data());
    pv->vt = VT_UI4;
    pv->ulVal = static_cast<ULONG>(v);
    return out;
}

Variant Variant::FromUi8(std::uint64_t v) {
    Variant out;
    ::VARIANT* pv = AsVariant(out.d_.data());
    pv->vt = VT_UI8;
    pv->ullVal = static_cast<ULONGLONG>(v);
    return out;
}

Variant Variant::FromInt(std::int32_t v) {
    Variant out;
    ::VARIANT* pv = AsVariant(out.d_.data());
    pv->vt = VT_INT;
    pv->intVal = static_cast<INT>(v);
    return out;
}

Variant Variant::FromUint(std::uint32_t v) {
    Variant out;
    ::VARIANT* pv = AsVariant(out.d_.data());
    pv->vt = VT_UINT;
    pv->uintVal = static_cast<UINT>(v);
    return out;
}

Variant Variant::FromR4(float v) {
    Variant out;
    ::VARIANT* pv = AsVariant(out.d_.data());
    pv->vt = VT_R4;
    pv->fltVal = static_cast<FLOAT>(v);
    return out;
}

Variant Variant::FromR8(double v) {
    Variant out;
    ::VARIANT* pv = AsVariant(out.d_.data());
    pv->vt = VT_R8;
    pv->dblVal = static_cast<DOUBLE>(v);
    return out;
}

Variant Variant::FromBool(bool v) {
    Variant out;
    ::VARIANT* pv = AsVariant(out.d_.data());
    pv->vt = VT_BOOL;
    pv->boolVal = v ? VARIANT_TRUE : VARIANT_FALSE;
    return out;
}

Variant Variant::FromScode(SCode v) {
    Variant out;
    ::VARIANT* pv = AsVariant(out.d_.data());
    pv->vt = VT_ERROR;
    pv->scode = static_cast<SCODE>(v);
    return out;
}

Variant Variant::FromCurrency(Currency v) {
    Variant out;
    ::VARIANT* pv = AsVariant(out.d_.data());
    pv->vt = VT_CY;
    pv->cyVal.int64 = static_cast<LONGLONG>(v.int64);
    return out;
}

Variant Variant::FromDate(Date v) {
    Variant out;
    ::VARIANT* pv = AsVariant(out.d_.data());
    pv->vt = VT_DATE;
    pv->date = static_cast<DATE>(v);
    return out;
}

Variant Variant::FromBstr(BStr bstr_take_ownership) {
    Variant out;
    ::VARIANT* pv = AsVariant(out.d_.data());
    pv->vt = VT_BSTR;
    pv->bstrVal = reinterpret_cast<BSTR>(bstr_take_ownership);
    return out;
}

Variant Variant::FromString(std::wstring_view s) {
    Variant out;
    ::VARIANT* pv = AsVariant(out.d_.data());
    pv->vt = VT_BSTR;

    // SysAllocStringLen expects OLECHAR* (wchar_t on Windows).
    pv->bstrVal = SysAllocStringLen(s.data(), static_cast<UINT>(s.size()));
    if (!pv->bstrVal && !s.empty()) {
        // Allocation failure: represent as VT_EMPTY for now.
        // If you prefer: throw std::bad_alloc().
        pv->vt = VT_EMPTY;
    }

    return out;
}

// TODO:  I *believe* that VT_UNKNOWN takes ownership (ie, VariantClear will call Release())
// VT_UNKNOWN | VT_BYREF would avoid that.  See the VariantClear documentation.  Verify this.
Variant Variant::FromUnknown(IUnknown* p) {
    Variant out;
    ::VARIANT* pv = AsVariant(out.d_.data());
    pv->vt = VT_UNKNOWN;
    pv->punkVal = reinterpret_cast<::IUnknown*>(p);
    return out;
}

// TODO:  Verify ownership behavior
Variant Variant::FromDispatch(IDispatch* p) {
    Variant out;
    ::VARIANT* pv = AsVariant(out.d_.data());
    pv->vt = VT_DISPATCH;
    pv->pdispVal = reinterpret_cast<::IDispatch*>(p);
    return out;
}

// TODO:  Veirify ownership behavior
//TODO:  Not void*
Variant Variant::FromSafearray(void* psa) {
    Variant out;
    ::VARIANT* pv = AsVariant(out.d_.data());
    pv->vt = static_cast<VARTYPE>(VT_ARRAY); // element type not encoded here; caller may refine later
    pv->parray = reinterpret_cast<::SAFEARRAY*>(psa);
    return out;
}

Variant Variant::FromRecord(void* pvRecord, IRecordInfo* pRecInfo) {
    Variant out;
    ::VARIANT* pv = AsVariant(out.d_.data());
    pv->vt = VT_RECORD;
    pv->pvRecord = pvRecord;
    pv->pRecInfo = reinterpret_cast<::IRecordInfo*>(pRecInfo);
    return out;
}

} // namespace Uiaw
