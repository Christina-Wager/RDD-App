

#pragma once

#include <JuceHeader.h>
#include "FileButtons.h"

class ManualControl  : public Component
{
public:
    ManualControl ();
    ~ManualControl() override;

    void paint (Graphics& g) override;
    void resized() override;



private:
    //FlexBox gridItems[16]; //maximum number of permissible panels
    std::unique_ptr<ManualControl> manualControl;
    FileButtons _fileButtons;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (ManualControl)
};


