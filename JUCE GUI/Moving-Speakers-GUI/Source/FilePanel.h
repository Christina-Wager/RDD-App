/*
  Created with Projucer version: 5.4.7
*/

#pragma once

#include <JuceHeader.h>



//==============================================================================
/**

*/
class FilePanel  : public Component
{
public:
    //==============================================================================
    FilePanel ();
    ~FilePanel() override;

    void paint (Graphics& g) override;
    void resized() override;



private:
    OwnedArray<TextButton> fileButtons;
    std::unique_ptr<FilePanel> filePanel;
    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (FilePanel)
};


