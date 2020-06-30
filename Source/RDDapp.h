

/*******************************************************************************
 BEGIN_JUCE_PIP_METADATA

 name:             RDDapp
 version:          1.0.0
 description:      Manages tabs and applies layout of the overall program

 dependencies:     juce_core, juce_data_structures, juce_events, juce_graphics,
                   juce_gui_basics, juce_gui_extra
 exporters:        xcode_mac, vs2019, codeblocks_windows

 moduleFlags:      JUCE_STRICT_REFCOUNTEDPOINTER=1

 type:             Component
 mainClass:        ComponentTransformsDemo

 useLocalCopy:     1

 END_JUCE_PIP_METADATA

*******************************************************************************/

#pragma once

#include "DemoUtilities.h"
#include "ManualControl.h"

//==============================================================================
class RDDapp  : public Component
{
public:
    RDDapp()
    {
        content.reset (new ManualControl (true));
        addAndMakeVisible (content.get());
        content->setSize (800, 600);

        setSize (800, 600);
    }

    void paint (Graphics& g) override
    {
        g.fillAll (getUIColourIfAvailable (LookAndFeel_V4::ColourScheme::UIColour::windowBackground));
    }

    void resized() override
    {
    }


private:
    std::unique_ptr<Component> content;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (RDDapp)
};
