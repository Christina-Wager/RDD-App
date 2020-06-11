
#pragma once

#include <JuceHeader.h>
#include "LogComponent.h"
#include "TabsComponent.h"
#include "MidiSettings.h"
#include "GridComponent.h"

class MainComponent   : public Component
{
public:
    //==============================================================================
    MainComponent();
    ~MainComponent();

    //==============================================================================
    void paint (Graphics&) override;
    void resized() override;

private:
    //==============================================================================

    LogComponent	_logComponent;
    TabsComponent	_tabsComponent;
    GridComponent   _gridComponent;
	rdd::MidiSettings	_midiSettings;


    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainComponent)
};
