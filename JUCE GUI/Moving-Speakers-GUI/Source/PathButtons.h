

#pragma once

#include <JuceHeader.h>

class PathButtons  : public Component
{
public:
    //==============================================================================
    PathButtons ();
    ~PathButtons() override;


    void paint (Graphics& g) override;
    void resized() override;



private:
    OwnedArray<TextButton> pathButtonsArr;
    std::unique_ptr<PathButtons> pathButtons;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (PathButtons)
};

