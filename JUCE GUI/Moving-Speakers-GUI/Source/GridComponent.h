
#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "FilePanel.h"

//==============================================================================
class GridComponent   : public Component
{
public:

    GridComponent();
    ~GridComponent();

    void paint (Graphics& g) override;

    void resized() override;

     //==============================================================================

private:
    FlexBox gridItems[16]; //maximum number of permissible panels
    std::unique_ptr<GridComponent> gridComponent;
    FilePanel _filePanel;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (GridComponent)
};
