

#pragma once

#include <JuceHeader.h>

class Sequencer  : public Component
{
public:
    //==============================================================================
    Sequencer ();
    ~Sequencer() override;



    void paint (Graphics& g) override;
    void resized() override;



private:
    std::unique_ptr<Sequencer> sequencer;

    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (Sequencer)
};



