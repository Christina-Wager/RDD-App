/* =========================================================================================

   This is an auto-generated file: Any edits you make may be overwritten!

*/

#pragma once

namespace BinaryData
{
    extern const char*   player_back_png;
    const int            player_back_pngSize = 6383;

    extern const char*   player_fwd_png;
    const int            player_fwd_pngSize = 6322;

    extern const char*   player_pause_png;
    const int            player_pause_pngSize = 6011;

    extern const char*   player_play_png;
    const int            player_play_pngSize = 6093;

    extern const char*   player_stop_png;
    const int            player_stop_pngSize = 5253;

    // Number of elements in the namedResourceList and originalFileNames arrays.
    const int namedResourceListSize = 5;

    // Points to the start of a list of resource names.
    extern const char* namedResourceList[];

    // Points to the start of a list of resource filenames.
    extern const char* originalFilenames[];

    // If you provide the name of one of the binary resource variables above, this function will
    // return the corresponding data and its size (or a null pointer if the name isn't found).
    const char* getNamedResource (const char* resourceNameUTF8, int& dataSizeInBytes);

    // If you provide the name of one of the binary resource variables above, this function will
    // return the corresponding original, non-mangled filename (or a null pointer if the name isn't found).
    const char* getNamedResourceOriginalFilename (const char* resourceNameUTF8);
}
