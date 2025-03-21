/*****************************************************************************
 * Copyright (c) 2014-2022 OpenRCT2 developers
 *
 * For a complete list of all authors, please refer to contributors.md
 * Interested in contributing? Visit https://github.com/OpenRCT2/OpenRCT2
 *
 * OpenRCT2 is licensed under the GNU General Public License version 3.
 *****************************************************************************/

#pragma once

#include "../../../paint/Supports.h"
#include "../../../sprites.h"
#include "../../RideData.h"
#include "../../ShopItem.h"
#include "../../Track.h"
#include "../BolligerMabillardTrack.hpp"

// clang-format off
constexpr const RideTypeDescriptor TwisterRollerCoasterRTD =
{
    SET_FIELD(AlternateType, RIDE_TYPE_NULL),
    SET_FIELD(Category, RIDE_CATEGORY_ROLLERCOASTER),
    SET_FIELD(EnabledTrackPieces, {TRACK_FLAT, TRACK_STRAIGHT, TRACK_STATION_END, TRACK_LIFT_HILL, TRACK_FLAT_ROLL_BANKING, TRACK_VERTICAL_LOOP, TRACK_SLOPE, TRACK_SLOPE_STEEP_UP, TRACK_SLOPE_STEEP_DOWN, TRACK_SLOPE_CURVE, TRACK_SLOPE_CURVE_STEEP, TRACK_S_BEND, TRACK_CURVE_SMALL, TRACK_CURVE, TRACK_HALF_LOOP, TRACK_CORKSCREW, TRACK_HELIX_SMALL, TRACK_BRAKES, TRACK_ON_RIDE_PHOTO, TRACK_SLOPE_VERTICAL, TRACK_BARREL_ROLL, TRACK_POWERED_LIFT, TRACK_HALF_LOOP_LARGE, TRACK_SLOPE_CURVE_BANKED, TRACK_BLOCK_BRAKES, TRACK_SLOPE_ROLL_BANKING, TRACK_SLOPE_STEEP_LONG, TRACK_CURVE_VERTICAL, TRACK_QUARTER_LOOP, TRACK_BOOSTER, TRACK_TWIST}),
    SET_FIELD(ExtraTrackPieces, {TRACK_LIFT_HILL_STEEP, TRACK_BRAKE_FOR_DROP}),
    SET_FIELD(CoveredTrackPieces, {}),
    SET_FIELD(StartTrackPiece, TrackElemType::EndStation),
    SET_FIELD(TrackPaintFunction, get_track_paint_function_bolliger_mabillard<METAL_SUPPORTS_TUBES>),
    SET_FIELD(Flags, RIDE_TYPE_FLAGS_TRACK_HAS_3_COLOURS | RIDE_TYPE_FLAG_HAS_LEAVE_WHEN_ANOTHER_VEHICLE_ARRIVES_AT_STATION |
                     RIDE_TYPE_FLAGS_COMMON_COASTER | RIDE_TYPE_FLAGS_COMMON_COASTER_NON_ALT | RIDE_TYPE_FLAG_HAS_LARGE_CURVES |
                     RIDE_TYPE_FLAG_PEEP_CHECK_GFORCES | RIDE_TYPE_FLAG_ALLOW_MULTIPLE_CIRCUITS),
    SET_FIELD(RideModes, EnumsToFlags(RideMode::ContinuousCircuit, RideMode::ContinuousCircuitBlockSectioned)),
    SET_FIELD(DefaultMode, RideMode::ContinuousCircuit),
    SET_FIELD(OperatingSettings, { 10, 27, 30, 17, 68, 0 }),
    SET_FIELD(Naming, { STR_RIDE_NAME_TWISTER_ROLLER_COASTER, STR_RIDE_DESCRIPTION_TWISTER_ROLLER_COASTER }),
    SET_FIELD(NameConvention, { RideComponentType::Train, RideComponentType::Track, RideComponentType::Station }),
    SET_FIELD(EnumName, nameof(RIDE_TYPE_TWISTER_ROLLER_COASTER)),
    SET_FIELD(AvailableBreakdowns, (1 << BREAKDOWN_SAFETY_CUT_OUT) | (1 << BREAKDOWN_RESTRAINTS_STUCK_CLOSED) | (1 << BREAKDOWN_RESTRAINTS_STUCK_OPEN) | (1 << BREAKDOWN_VEHICLE_MALFUNCTION) | (1 << BREAKDOWN_BRAKES_FAILURE)),
    SET_FIELD(Heights, { 40, 24, 8, 9, }),
    SET_FIELD(MaxMass, 31),
    SET_FIELD(LiftData, { OpenRCT2::Audio::SoundId::LiftBM, 5, 8 }),
    SET_FIELD(RatingsCalculationFunction, ride_ratings_calculate_twister_roller_coaster),
    SET_FIELD(RatingsMultipliers, { 52, 36, 10 }),
    SET_FIELD(UpkeepCosts, { 43, 20, 80, 11, 3, 10 }),
    SET_FIELD(BuildCosts, { 60.00_GBP, 2.50_GBP, 55, }),
    SET_FIELD(DefaultPrices, { 20, 20 }),
    SET_FIELD(DefaultMusic, MUSIC_OBJECT_ROCK_1),
    SET_FIELD(PhotoItem, ShopItem::Photo),
    SET_FIELD(BonusValue, 120),
    SET_FIELD(ColourPresets, TRACK_COLOUR_PRESETS(
        { COLOUR_YELLOW, COLOUR_YELLOW, COLOUR_BORDEAUX_RED },
        { COLOUR_AQUAMARINE, COLOUR_AQUAMARINE, COLOUR_DARK_PURPLE },
        { COLOUR_WHITE, COLOUR_WHITE, COLOUR_LIGHT_BLUE },
        { COLOUR_DARK_GREEN, COLOUR_MOSS_GREEN, COLOUR_DARK_BROWN },
        { COLOUR_BORDEAUX_RED, COLOUR_LIGHT_ORANGE, COLOUR_WHITE },
    )),
    SET_FIELD(ColourPreview, { SPR_RIDE_DESIGN_PREVIEW_TWISTER_ROLLER_COASTER_TRACK, SPR_RIDE_DESIGN_PREVIEW_TWISTER_ROLLER_COASTER_SUPPORTS }),
    SET_FIELD(ColourKey, RideColourKey::Ride),
    SET_FIELD(Name, "twister_rc"),
};
// clang-format on
