/*****************************************************************************
 * Copyright (c) 2014-2022 OpenRCT2 developers
 *
 * For a complete list of all authors, please refer to contributors.md
 * Interested in contributing? Visit https://github.com/OpenRCT2/OpenRCT2
 *
 * OpenRCT2 is licensed under the GNU General Public License version 3.
 *****************************************************************************/

#include "FootpathRailingsObject.h"

#include "../core/IStream.hpp"
#include "../core/Json.hpp"
#include "../drawing/Image.h"

void FootpathRailingsObject::Load()
{
    GetStringTable().Sort();
    NameStringId = language_allocate_object_string(GetName());

    auto numImages = GetImageTable().GetCount();
    if (numImages != 0)
    {
        PreviewImageId = gfx_object_allocate_images(GetImageTable().GetImages(), GetImageTable().GetCount());
        BridgeImageId = PreviewImageId + 37;
        RailingsImageId = PreviewImageId + 1;
    }

    _descriptor.Name = NameStringId;
    _descriptor.BridgeImage = BridgeImageId;
    _descriptor.PreviewImage = PreviewImageId;
    _descriptor.Flags = Flags;
    _descriptor.ScrollingMode = ScrollingMode;
    _descriptor.SupportType = SupportType;
    _descriptor.SupportColour = Colour;
    _descriptor.RailingsImage = RailingsImageId;
}

void FootpathRailingsObject::Unload()
{
    language_free_object_string(NameStringId);
    gfx_object_free_images(PreviewImageId, GetImageTable().GetCount());

    NameStringId = 0;
    PreviewImageId = 0;
    BridgeImageId = 0;
    RailingsImageId = 0;
}

void FootpathRailingsObject::DrawPreview(rct_drawpixelinfo* dpi, int32_t width, int32_t height) const
{
    auto x = width / 2;
    auto y = height / 2;
    auto helper = ImageId(ImageIndexUndefined);
    if (Colour != COLOUR_NULL)
        helper = helper.WithPrimary(Colour);

    if (SupportType == RailingEntrySupportType::Pole)
    {
        auto img = helper.WithIndex(BridgeImageId + 20 + 15);
        for (int i = 0; i < 2; i++)
        {
            auto h = i * 16;
            gfx_draw_sprite(dpi, img, { x - 8, y + 8 + h });
            gfx_draw_sprite(dpi, img, { x + 8, y + 16 + h });
        }

        gfx_draw_sprite(dpi, helper.WithIndex(BridgeImageId + 5), { x, y - 17 });
        gfx_draw_sprite(dpi, ImageId(RailingsImageId + 1), { x + 4, y - 14 });
        gfx_draw_sprite(dpi, ImageId(RailingsImageId + 1), { x + 27, y - 2 });
    }
    else
    {
        gfx_draw_sprite(dpi, helper.WithIndex(BridgeImageId + 22), { x + 0, y + 16 });
        gfx_draw_sprite(dpi, helper.WithIndex(BridgeImageId + 49), { x, y - 17 });
        gfx_draw_sprite(dpi, ImageId(RailingsImageId + 1), { x + 4, y - 14 });
        gfx_draw_sprite(dpi, ImageId(RailingsImageId + 1), { x + 27, y - 3 });
    }
}

void FootpathRailingsObject::ReadJson(IReadObjectContext* context, json_t& root)
{
    Guard::Assert(root.is_object(), "FootpathObject::ReadJson expects parameter root to be object");

    auto properties = root["properties"];
    if (properties.is_object())
    {
        SupportType = ParseSupportType(Json::GetString(properties["supportType"]));
        ScrollingMode = Json::GetNumber<uint8_t>(properties["scrollingMode"]);
        Colour = Colour::FromString(Json::GetString(properties["colour"]), COLOUR_NULL);
        Flags = Json::GetFlags<uint8_t>(
            properties,
            {
                { "hasSupportImages", RAILING_ENTRY_FLAG_HAS_SUPPORT_BASE_SPRITE },
                { "hasElevatedPathImages", RAILING_ENTRY_FLAG_DRAW_PATH_OVER_SUPPORTS },
                { "noQueueBanner", RAILING_ENTRY_FLAG_NO_QUEUE_BANNER },
            });
    }

    PopulateTablesFromJson(context, root);
}

RailingEntrySupportType FootpathRailingsObject::ParseSupportType(std::string_view s)
{
    if (s == "pole")
        return RailingEntrySupportType::Pole;
    else /* if (s == "box") */
        return RailingEntrySupportType::Box;
}
