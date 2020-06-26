

#pragma once

#include <JuceHeader.h>



class RotationButtons  : public Component
{
public:
    //==============================================================================
    RotationButtons ();
    ~RotationButtons() override;


    void paint (Graphics& g) override;
    void resized() override;



private:
    std::unique_ptr<RotationButtons> rotationButtons;

    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (RotationButtons)
};

//[EndFile] You can add extra defines here...
//[/EndFile]

