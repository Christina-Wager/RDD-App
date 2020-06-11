/*
  Created with Projucer version: 5.4.5
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"

class TabsComponent  : public Component
{
public:
    //==============================================================================
    TabsComponent ();
    ~TabsComponent();

    //==============================================================================
    void paint (Graphics& g) override;
    void resized() override;

private:
    //==============================================================================
    std::unique_ptr<TabbedComponent> tabbedComponent;

    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (TabsComponent)
};


