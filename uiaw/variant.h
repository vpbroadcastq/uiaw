#pragma once

#include <array>
#include <cstddef>
#include <cstdint>
#include <cstring>
#include <optional>
#include <string_view>
#include <type_traits>

// Forward declarations for COM/OA pointer types.
// TODO:  Wrappers?
struct IUnknown;
struct IDispatch;
struct IRecordInfo;
//struct SAFEARRAY;

namespace Uiaw {
    

// BSTR is ABI-compatible with wchar_t* on Windows (OLECHAR*).
// This avoids exposing the Windows typedef while preserving the pointer type.
using BStr = wchar_t*;

// VARIANT_BOOL is a 16-bit signed integer in Win32 ABI.
using VariantBool = std::int16_t;

// VARTYPE is a 16-bit unsigned integer in Win32 ABI.
using VarTypeUnderlying = std::uint16_t;

// Analogue of VARENUM / VARTYPE.
// TODO:  This list is not exhaustive
enum class VarType : VarTypeUnderlying {
    Empty    = 0,    // VT_EMPTY
    Null     = 1,    // VT_NULL
    I2       = 2,    // VT_I2
    I4       = 3,    // VT_I4
    R4       = 4,    // VT_R4
    R8       = 5,    // VT_R8
    Cy       = 6,    // VT_CY
    Date     = 7,    // VT_DATE
    BStr     = 8,    // VT_BSTR
    Dispatch = 9,    // VT_DISPATCH
    Error    = 10,   // VT_ERROR
    Bool     = 11,   // VT_BOOL
    Variant  = 12,   // VT_VARIANT
    Unknown  = 13,   // VT_UNKNOWN
    Decimal  = 14,   // VT_DECIMAL
    I1       = 16,   // VT_I1
    Ui1      = 17,   // VT_UI1
    Ui2      = 18,   // VT_UI2
    Ui4      = 19,   // VT_UI4
    I8       = 20,   // VT_I8
    Ui8      = 21,   // VT_UI8
    Int      = 22,   // VT_INT
    UInt     = 23,   // VT_UINT
    Record   = 36,   // VT_RECORD

    // Flags (bitwise OR with base type)
    ByRef    = 0x4000, // VT_BYREF
    Array    = 0x2000, // VT_ARRAY
};

// TODO:  hide?
[[nodiscard]] constexpr VarType operator|(VarType a, VarType b) noexcept {
    return static_cast<VarType>(static_cast<VarTypeUnderlying>(a) | static_cast<VarTypeUnderlying>(b));
}

// TODO:  hide?
[[nodiscard]] constexpr bool has_flag(VarType value, VarType flag) noexcept {
    return (static_cast<VarTypeUnderlying>(value) &
            static_cast<VarTypeUnderlying>(flag)) != 0;
}

// TODO:  hide?
[[nodiscard]] constexpr VarType base_type(VarType value) noexcept {
    // Clear Array and ByRef bits.
    return static_cast<VarType>(
        static_cast<VarTypeUnderlying>(value) &
        static_cast<VarTypeUnderlying>(~(static_cast<VarTypeUnderlying>(VarType::Array) |
                                            static_cast<VarTypeUnderlying>(VarType::ByRef))));
}

// Minimal “CY/DATE/SCODE/DECIMAL” representations without Windows headers:
// - SCODE is a 32-bit signed integer (HRESULT-like).
using SCode = std::int32_t;

// DATE in OLE Automation is a double (days since 1899-12-30).
using Date = double;

// TODO
// CY is 64-bit signed scaled integer (value * 10,000).
struct Currency {
    std::int64_t int64 = 0; // scaled by 10,000
};

// TODO
// DECIMAL is 16 bytes in OLE Automation (layout matters, but you can keep it opaque for now).
// Since you included DECIMAL in VARIANT union, we provide a POD that is size-compatible
// and treat it as opaque until you wrap it properly.
struct alignas(alignof(std::uint64_t)) Decimal {
    std::array<std::byte, 16> bytes{};
};

class Variant {
    // Storage large enough for VARIANT on both x86/x64.
    // Verified via static_assert in the .cpp
    static constexpr std::size_t ArraySize  = 24;
    static constexpr std::size_t ArrayAlign = alignof(std::max_align_t);

    alignas(ArrayAlign) std::array<std::byte, ArraySize> d_{};

    void* NativePtr() noexcept;
    const void* NativePtr() const noexcept;

    // Internal helpers implemented in .cpp (where VARIANT is known).
    void Init() noexcept;
    void NativeClear() noexcept;
    void NativeCopyFrom(const Variant& other);
    void StaticAssert() const noexcept;
public:
    Variant() noexcept;
    Variant(std::nullptr_t) noexcept; // VT_NULL

    // Copy / move
    Variant(const Variant& other);
    Variant& operator=(const Variant& other);
    Variant(Variant&& other) noexcept;
    Variant& operator=(Variant&& other) noexcept;

    ~Variant();

    // Type inspection
    // TODO:  Hide
    [[nodiscard]] VarType Type() const noexcept;
    [[nodiscard]] bool IsEmpty() const noexcept { return base_type(Type()) == VarType::Empty; }
    [[nodiscard]] bool IsNull()  const noexcept { return base_type(Type()) == VarType::Null; }
    [[nodiscard]] bool IsByRef() const noexcept { return has_flag(Type(), VarType::ByRef); }
    [[nodiscard]] bool IsArray() const noexcept { return has_flag(Type(), VarType::Array); }
    // Clear to VT_EMPTY
    void Clear() noexcept;

    //
    // Getters
    //
    // TODO:  Uiaw::Result<T>?
    [[nodiscard]] std::optional<std::int16_t> GetI2() const noexcept;
    [[nodiscard]] std::optional<std::int32_t> GetI4() const noexcept;
    [[nodiscard]] std::optional<std::int64_t> GetI8() const noexcept;
    [[nodiscard]] std::optional<std::uint8_t> GetUi1() const noexcept;
    [[nodiscard]] std::optional<std::uint16_t> GetUi2() const noexcept;
    [[nodiscard]] std::optional<std::uint32_t> GetUi4() const noexcept;
    [[nodiscard]] std::optional<std::uint64_t> GetUi8() const noexcept;
    [[nodiscard]] std::optional<std::int32_t> GetInt() const noexcept;
    [[nodiscard]] std::optional<std::uint32_t> GetUint() const noexcept;
    [[nodiscard]] std::optional<float> GetR4() const noexcept;
    [[nodiscard]] std::optional<double> GetR8() const noexcept;
    [[nodiscard]] std::optional<bool> GetBool() const noexcept;
    [[nodiscard]] std::optional<SCode> GetScodex() const noexcept;
    [[nodiscard]] std::optional<Currency> GetCurrency() const noexcept;
    [[nodiscard]] std::optional<Date> GetDate() const noexcept;
    [[nodiscard]] BStr GetBstr() const noexcept;     // returns pointer; nullptr if not VT_BSTR
    [[nodiscard]] IUnknown*  GetUnknown() const noexcept;  // nullptr if not VT_UNKNOWN
    [[nodiscard]] IDispatch* GetDispatch() const noexcept; // nullptr if not VT_DISPATCH
    // TODO:  Don't return a void*... need a SAFEARRAY wrapper
    [[nodiscard]] void* GetSafearray() const noexcept; // nullptr if not VT_ARRAY|...
    // Advanced: access byref raw pointer (opaque); you can refine later.
    [[nodiscard]] void* GetByref() const noexcept;

    //
    // Static factories
    //
    static Variant FromI2(std::int16_t v);
    static Variant FromI4(std::int32_t v);
    static Variant FromI8(std::int64_t v);
    static Variant FromUi1(std::uint8_t v);
    static Variant FromUi2(std::uint16_t v);
    static Variant FromUi4(std::uint32_t v);
    static Variant FromUi8(std::uint64_t v);
    static Variant FromInt(std::int32_t v);   // VT_INT
    static Variant FromUint(std::uint32_t v); // VT_UINT
    static Variant FromR4(float v);
    static Variant FromR8(double v);
    static Variant FromBool(bool v);
    static Variant FromScode(SCode v);
    static Variant FromCurrency(Currency v);
    static Variant FromDate(Date v);
    // Takes ownership
    static Variant FromBstr(BStr bstr_take_ownership);
    // Allocates a new BSTR
    static Variant FromString(std::wstring_view s);
    // COM pointers (no AddRef/Release policy enforced here; keep simple)
    static Variant FromUnknown(IUnknown* p);
    static Variant FromDispatch(IDispatch* p);
    // Arrays / records (TODO)
    // TODO:  SAFEARRAY wrapper...
    static Variant FromSafearray(void* psa);
    static Variant FromRecord(void* pvRecord, IRecordInfo* pRecInfo);
};
} // namespace uiaw::ole
