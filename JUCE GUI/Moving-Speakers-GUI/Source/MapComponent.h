

#pragma once

#include <JuceHeader.h>

class MapComponent  : public Component
{
public:
    //==============================================================================
    MapComponent ();
    ~MapComponent() override;



    void paint (Graphics& g) override;
    void resized() override;



private:
    std::unique_ptr<MapComponent> mapComponent;

    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MapComponent)
};



