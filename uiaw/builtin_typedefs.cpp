#include "builtin_typedefs.h"
#include "uia_all.h"

#include <type_traits>

namespace Uiaw {

static_assert(std::is_same_v<Uiaw::PropertyId, ::PROPERTYID>);
static_assert(std::is_same_v<Uiaw::PatternId, ::PATTERNID>);
static_assert(std::is_same_v<Uiaw::EventId, ::EVENTID>);
static_assert(std::is_same_v<Uiaw::TextAttributeId, ::TEXTATTRIBUTEID>);
static_assert(std::is_same_v<Uiaw::ControlTypeId, ::CONTROLTYPEID>);
static_assert(std::is_same_v<Uiaw::LandmarkTypeId, ::LANDMARKTYPEID>);
static_assert(std::is_same_v<Uiaw::MetadataId, ::METADATAID>);
static_assert(std::is_same_v<Uiaw::HeadingLevelId, ::HEADINGLEVELID>);


} // namespace Uiaw
