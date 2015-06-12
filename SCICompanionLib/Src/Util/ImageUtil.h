#pragma once

struct PaletteComponent;
struct Cel;

namespace Gdiplus
{
    class Bitmap;
}

bool Save8BitBmpGdiP(const char *filename, const Cel &cel, const PaletteComponent &palette);
void FlipImageData(uint8_t *data, int cx, int cy, int stride);
int SquishPalette(uint8_t *data, size_t dataSize, const PaletteComponent &palette, RGBQUAD *results);
int CountActualUsedColors(const Cel &cel, bool *used);
int CountActualUsedColors(const std::vector<const Cel*> &cels, bool *used);
std::unique_ptr<PaletteComponent> GetPaletteFromImage(Gdiplus::Bitmap &bitmap, int *numberOfUsedEntriesOut = nullptr);
bool GetCelsAndPaletteFromGIFFile(const char *filename, std::vector<Cel> &cels, PaletteComponent &palette);
bool GetCelsAndPaletteFromGdiplus(Gdiplus::Bitmap &bitmap, uint8_t transparentColor, std::vector<Cel> &cels, PaletteComponent &palette);
bool DoPalettesMatch(const PaletteComponent &paletteA, const PaletteComponent &paletteB);
void ConvertBitmapToCel(Gdiplus::Bitmap &bitmap, uint8_t transparentColor, bool isEGA16, bool egaDither, int colorCount, const uint8_t *paletteMapping, const RGBQUAD *colors, std::vector<Cel> cels);
void ConvertCelToNewPalette(Cel &cel, PaletteComponent &currentPalette, uint8_t transparentColor, bool isEGA16, bool g_fDitherImages2, int colorCount, const uint8_t *paletteMapping, const RGBQUAD *colors);