/*
  ==============================================================================

   This file is part of the JUCE examples.
   Copyright (c) 2017 - ROLI Ltd.

   The code included in this file is provided under the terms of the ISC license
   http://www.isc.org/downloads/software-support-policy/isc-license. Permission
   To use, copy, modify, and/or distribute this software for any purpose with or
   without fee is hereby granted provided that the above copyright notice and
   this permission notice appear in all copies.

   THE SOFTWARE IS PROVIDED "AS IS" WITHOUT ANY WARRANTY, AND ALL WARRANTIES,
   WHETHER EXPRESSED OR IMPLIED, INCLUDING MERCHANTABILITY AND FITNESS FOR
   PURPOSE, ARE DISCLAIMED.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

#ifndef PIP_DEMO_UTILITIES_INCLUDED
 #define PIP_DEMO_UTILITIES_INCLUDED 1
#endif

//==============================================================================
/*
    This file contains utilities used in various JUCE demos and are implemented
    temporarily in the app for testing purposes.
*/
//==============================================================================


/*
    Returns the currently selected UI color scheme
*/
inline Colour getUIColourIfAvailable (LookAndFeel_V4::ColourScheme::UIColour uiColour, Colour fallback = Colour (0xff4d4d4d)) noexcept
{
    if (auto* v4 = dynamic_cast<LookAndFeel_V4*> (&LookAndFeel::getDefaultLookAndFeel()))
        return v4->getCurrentColourScheme().getUIColour (uiColour);

    return fallback;
}

//==============================================================================

/*
    Finds the JUCE examples folder (the assets there are used by these utilities)
*/
inline File getExamplesDirectory() noexcept
{
   #ifdef PIP_JUCE_EXAMPLES_DIRECTORY
    MemoryOutputStream mo;

    auto success = Base64::convertFromBase64 (mo, JUCE_STRINGIFY (PIP_JUCE_EXAMPLES_DIRECTORY));
    ignoreUnused (success);
    jassert (success);

    return mo.toString();
   #else
    auto currentFile = File::getSpecialLocation (File::SpecialLocationType::currentApplicationFile);
    auto exampleDir = currentFile.getParentDirectory().getChildFile ("examples");

    if (exampleDir.exists())
        return exampleDir;

    int numTries = 0; // keep track of the number of parent directories so we don't go on endlessly

    while (currentFile.getFileName() != "examples" && numTries++ < 15)
        currentFile = currentFile.getParentDirectory();

    return currentFile;
   #endif
}

//==============================================================================

/*
    Prepares assets (from Examples) (here: used for testing purposes)
*/
inline InputStream* createAssetInputStream (const char* resourcePath)
{
  #if JUCE_ANDROID
    ZipFile apkZip (File::getSpecialLocation (File::invokedExecutableFile));
    return apkZip.createStreamForEntry (apkZip.getIndexOfFileName ("assets/" + String (resourcePath)));
  #else
   #if JUCE_IOS
    auto assetsDir = File::getSpecialLocation (File::currentExecutableFile)
                          .getParentDirectory().getChildFile ("Assets");
   #elif JUCE_MAC
    auto assetsDir = File::getSpecialLocation (File::currentExecutableFile)
                          .getParentDirectory().getParentDirectory().getChildFile ("Resources").getChildFile ("Assets");

    if (! assetsDir.exists())
        assetsDir = getExamplesDirectory().getChildFile ("Assets");
   #else
    auto assetsDir = getExamplesDirectory().getChildFile ("Assets");
   #endif

    auto resourceFile = assetsDir.getChildFile (resourcePath);
    jassert (resourceFile.existsAsFile());

    return resourceFile.createInputStream();
  #endif
}

inline String loadEntireAssetIntoString (const char* assetName)
{
    std::unique_ptr<InputStream> input (createAssetInputStream (assetName));

    if (input == nullptr)
        return {};

    return input->readString();
}

//==============================================================================
//==============================================================================

/*
    Sets the look-and-feel of an in-program code editor (dark scheme)
*/
#if JUCE_MODULE_AVAILABLE_juce_gui_extra
 inline CodeEditorComponent::ColourScheme getDarkCodeEditorColourScheme()
 {
     struct Type
     {
         const char* name;
         juce::uint32 colour;
     };

     const Type types[] =
     {
         { "Error",              0xffe60000 },
         { "Comment",            0xff72d20c },
         { "Keyword",            0xffee6f6f },
         { "Operator",           0xffc4eb19 },
         { "Identifier",         0xffcfcfcf },
         { "Integer",            0xff42c8c4 },
         { "Float",              0xff885500 },
         { "String",             0xffbc45dd },
         { "Bracket",            0xff058202 },
         { "Punctuation",        0xffcfbeff },
         { "Preprocessor Text",  0xfff8f631 }
     };

     CodeEditorComponent::ColourScheme cs;

     for (auto& t : types)
         cs.set (t.name, Colour (t.colour));

     return cs;
 }

 //==============================================================================

/*
    Sets the look-and-feel of an in-program code editor (light scheme)
*/
 inline CodeEditorComponent::ColourScheme getLightCodeEditorColourScheme()
 {
     struct Type
     {
         const char* name;
         juce::uint32 colour;
     };

     const Type types[] =
     {
         { "Error",              0xffcc0000 },
         { "Comment",            0xff00aa00 },
         { "Keyword",            0xff0000cc },
         { "Operator",           0xff225500 },
         { "Identifier",         0xff000000 },
         { "Integer",            0xff880000 },
         { "Float",              0xff885500 },
         { "String",             0xff990099 },
         { "Bracket",            0xff000055 },
         { "Punctuation",        0xff004400 },
         { "Preprocessor Text",  0xff660000 }
     };

     CodeEditorComponent::ColourScheme cs;

     for (auto& t : types)
         cs.set (t.name, Colour (t.colour));

     return cs;
 }
#endif

