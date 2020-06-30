
/*******************************************************************************
 BEGIN_JUCE_PIP_METADATA

 name:             ManualControl
 version:          1.0.0
 description:      Contains components used for manual control features.

 dependencies:     juce_core, juce_data_structures, juce_events, juce_graphics,
                   juce_gui_basics, juce_gui_extra
 exporters:        xcode_mac, vs2019, codeblocks_windows

 moduleFlags:      JUCE_STRICT_REFCOUNTEDPOINTER=1

 type:             Component
 mainClass:        ManualControl

 useLocalCopy:     1

 END_JUCE_PIP_METADATA

*******************************************************************************/

#pragma once

#ifndef PIP_DEMO_UTILITIES_INCLUDED
 #include "../Assets/DemoUtilities.h"
#endif

//==============================================================================
struct RotationPanel  : public Component
{
    RotationPanel()
    {
        Rectangle<int> layoutArea { 20, 20, 300, 300 };
        auto rotarySliderArea = layoutArea.removeFromTop(100);
        auto horizontalSliderArea = layoutArea.removeFromTop(180);

/// TO DO: possibility to set a different text in the tooltip, such as  "Winkel zwischen ... und ..."?
/// Also: double-click returns to default angle? Or a separate button?

        auto* s = createSlider ();
        s->setSliderStyle (Slider::Rotary);
        s->setRotaryParameters (MathConstants<float>::pi * 1.2f, MathConstants<float>::pi * 2.8f, false);
        s->setTextBoxStyle (Slider::TextBoxBelow, false, 70, 20);
        s->setBounds (rotarySliderArea.removeFromLeft (75));
        s->setTextValueSuffix (" degr");
        rotarySliderArea.removeFromLeft(20);

        s = createSlider ();
        s->setSliderStyle (Slider::Rotary);
        s->setRotaryParameters (MathConstants<float>::pi * 1.2f, MathConstants<float>::pi * 2.8f, false);
        s->setTextBoxStyle (Slider::TextBoxBelow, false, 70, 20);
        s->setBounds (rotarySliderArea.removeFromLeft (75));
        s->setTextValueSuffix (" degr");

/// TO DO: decide on  horizontal or rotary sliders, or a combination of both,
/// then add labels accordingly
        s = createSlider ();
        s->setSliderStyle (Slider::ThreeValueHorizontal); //instead of LinearHorizontal
        s->setTextBoxStyle (Slider::TextEntryBoxPosition::TextBoxBelow, false, 80, 20);
        s->setBounds (horizontalSliderArea.removeFromTop (50));
        s->setPopupDisplayEnabled (true, false, this);
        s->setTextValueSuffix (" degr");
        s->setMinValue(10.0,sendNotificationAsync,false);
        s->setMaxValue(300.0,sendNotificationAsync,false);

        s = createSlider ();
        s->setSliderStyle (Slider::ThreeValueHorizontal); //instead of LinearHorizontal
        s->setTextBoxStyle (Slider::TextEntryBoxPosition::TextBoxBelow, false, 80, 20);
        s->setBounds (horizontalSliderArea.removeFromTop (50));
        s->setPopupDisplayEnabled (true, false, this);
        s->setTextValueSuffix (" degr");
        s->setMinValue(10.0,sendNotificationAsync,false);
        s->setMaxValue(300.0,sendNotificationAsync,false);

        /* Local copies of the current slider value. Useful for later on, when the rotation value
            has to be packaged with the rotation command and sent to the robot
        */
        Value sliderValue, maxValue, minValue;

        sliderValue = Random::getSystemRandom().nextDouble() * 100;
        minValue = Random::getSystemRandom().nextDouble() * 40.0;
        maxValue = Random::getSystemRandom().nextDouble() * 40.0 + 60.0;

        auto* selectedSlider = sliders.getUnchecked(0);
        selectedSlider->getValueObject().referTo (sliderValue);
        selectedSlider->getMaxValueObject().referTo (maxValue);
        selectedSlider->getMinValueObject().referTo (minValue);
        selectedSlider->setTextBoxStyle (Slider::NoTextBox, false, 0, 0);

        /// TO DO: consider packaging the hint label as a pop-up from a small button near the sliders,
        /// to let users know about JUCE's inherent slider options
        hintLabel.setBounds (layoutArea);
        //addAndMakeVisible (hintLabel);
    }

private:
    OwnedArray<Slider> sliders;
    Label hintLabel  { "hint", "Right-clicking on a slider opens the options menu \n\n"
                               "Holding down CTRL while dragging will turn on a slider's velocity-sensitive mode" };

    Slider* createSlider ()
    {
        auto* s = new Slider();
        sliders.add (s);
        addAndMakeVisible (s);
        s->setRange (0.0, 360.0, 1.0);
        s->setPopupMenuEnabled (true);
        s->setValue (90.0, dontSendNotification);
        return s;
    }

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (RotationPanel)
};

//==============================================================================
///TO DO: separate player and file option buttons into different panels
struct ButtonPanels   : public Component
{
    ButtonPanels ()
    {
        {
            /// Player Buttons
            auto stopBtn = addToPlayer (new ImageButton ("StopButton"));
            auto stopIcon = ImageFileFormat::loadFrom(BinaryData::player_stop_png, BinaryData::player_stop_pngSize);
            stopBtn = styleForPlayer(stopBtn, stopIcon);
            stopBtn->setTooltip ("Animation stoppen");

            /////////////////////////////////////////////////////////////

            auto backBtn = addToPlayer (new ImageButton ("BackButton"));
            auto backIcon = ImageFileFormat::loadFrom(BinaryData::player_back_png, BinaryData::player_back_pngSize);
            backBtn = styleForPlayer(backBtn, backIcon);
            backBtn->setTooltip ("Pfad zurückspulen");

            /////////////////////////////////////////////////////////////
            auto playBtn = addToPlayer (new ImageButton ("PlayButton"));
            auto playIcon = ImageFileFormat::loadFrom(BinaryData::player_play_png, BinaryData::player_play_pngSize);
            playBtn = styleForPlayer(playBtn, playIcon);
            playBtn->setTooltip ("Pfad abspielen");

            /////////////////////////////////////////////////////////////

            auto pauseBtn = addToPlayer (new ImageButton ("PauseButton"));
            auto pauseIcon = ImageFileFormat::loadFrom(BinaryData::player_pause_png, BinaryData::player_pause_pngSize);
            pauseBtn = styleForPlayer(pauseBtn, pauseIcon);
            pauseBtn->setTooltip ("Animation pausieren");

            /////////////////////////////////////////////////////////////

            auto fwdBtn = addToPlayer (new ImageButton ("FwdButton"));
            auto fwdIcon = ImageFileFormat::loadFrom(BinaryData::player_fwd_png, BinaryData::player_fwd_pngSize);
            fwdBtn = styleForPlayer(fwdBtn, fwdIcon);
            fwdBtn->setTooltip ("Pfad vorspulen");

            /////////////////////////////////////////////////////////////
            /// File Option Buttons
            //Load, Save, Import, Export

            auto loadBtn = addToFileOptions (new TextButton ("Load", "Pfad laden"));
            loadBtn = styleForFileOptions(loadBtn);

            auto saveBtn = addToFileOptions (new TextButton ("Save", "Pfad speichern"));
            saveBtn = styleForFileOptions(saveBtn);

            auto importBtn = addToFileOptions (new TextButton ("Import", "Pfad importieren"));
            importBtn = styleForFileOptions(importBtn);

            auto exportBtn = addToFileOptions (new TextButton ("Export", "Pfad exportieren"));
            exportBtn = styleForFileOptions(exportBtn);

        }
    }

    void resized() override
    {
            Rectangle<int> btnArea (50, 50, 400, 100);

            FlexBox playerPanel;
            playerPanel.flexWrap = FlexBox::Wrap::wrap;
            playerPanel.justifyContent = FlexBox::JustifyContent::spaceBetween;
            playerPanel.alignContent = FlexBox::AlignContent::center;

            for (auto* b :  imgButtons)
                playerPanel.items.add(FlexItem(*b).withMinWidth(50.0f).withMinHeight(50.0f));

            playerPanel.performLayout(btnArea.removeFromTop(50));

            ///////////////////////////////////////////////////////

            FlexBox filePanel;
            filePanel.flexWrap = FlexBox::Wrap::wrap;
            filePanel.justifyContent = FlexBox::JustifyContent::spaceBetween;
            filePanel.alignContent = FlexBox::AlignContent::center;

            for (auto* b :  txtButtons)
                filePanel.items.add(FlexItem(*b).withMinWidth(60.0f).withMinHeight(40.0f));

            filePanel.performLayout(btnArea.removeFromTop(70));

    }


private:
    OwnedArray<Component> imgButtons;
    OwnedArray<Component> txtButtons;
    TooltipWindow tooltipWindow;

    // Adds button to the player array and renders visible (works for all button types)
    template <typename ComponentType>
    ComponentType* addToPlayer (ComponentType* newBtn)
    {
        imgButtons.add (newBtn);
        addAndMakeVisible (newBtn);
        return newBtn;
    }

    // Default style for every Player button
    template <typename ComponentType>
    ComponentType* styleForPlayer (ComponentType* newBtn, Image btnIcon)
    {
        newBtn->setImages (true, true, true,
                           btnIcon, 1.0f, Colours::transparentWhite,
                           btnIcon, 0.7f, Colours::transparentWhite,
                           btnIcon, 0.5f, Colours::transparentWhite,
                           0.5f);
            newBtn->setClickingTogglesState (true);
            newBtn->setBounds (100, 100, 30, 30);
            return newBtn;
    }

    // Adds button to the file options array and renders visible (works for all button types)
    template <typename ComponentType>
    ComponentType* addToFileOptions (ComponentType* newBtn)
    {
        txtButtons.add (newBtn);
        addAndMakeVisible (newBtn);
        return newBtn;
    }

    // Default style for every file button
    template <typename ComponentType>
    ComponentType* styleForFileOptions (ComponentType* newBtn)
    {
        newBtn->setColour (TextButton::buttonColourId, Colours::black);
        newBtn->setColour (TextButton::buttonOnColourId, Colours::black.brighter());
            newBtn->setBounds (100, 200, 65, 35);
            return newBtn;
    }

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (ButtonPanels)
};


//==============================================================================
/**
    Sequencer is presented in the form of an editable table list box that currently
    uses sample data from an XML file
*/
class Sequencer    : public Component,
                              public TableListBoxModel
{
public:
    Sequencer()
    {
        // Load some data from an embedded XML file
        loadData();

        // Createtable component and add it to this component
        addAndMakeVisible (table);
        table.setModel (this);

        // give it a border
        table.setColour (ListBox::outlineColourId, Colours::grey);
        table.setOutlineThickness (1);

        // Add some columns to the table header, based on the column list in the database
        forEachXmlChildElement (*columnList, columnXml)
        {
            table.getHeader().addColumn (columnXml->getStringAttribute ("name"),
                                         columnXml->getIntAttribute ("columnId"),
                                         columnXml->getIntAttribute ("width"),
                                         50, 400,
                                         TableHeaderComponent::defaultFlags);
        }

        // change some initial settings
        table.getHeader().setSortColumnId (1, true); // sort forwards by the ID column
        //table.setMultipleSelectionEnabled (true);
    }

    // This is overloaded from TableListBoxModel, and must return the total number of rows in our table
    int getNumRows() override
    {
        return numRows;
    }

    // This is overloaded from TableListBoxModel, and should fill in the background of the whole row
    ///TO DO: consider using a white background without alternating colors instead (like the logger)
    void paintRowBackground (Graphics& g, int rowNumber, int /*width*/, int /*height*/, bool rowIsSelected) override
    {
        auto alternateColour = getLookAndFeel().findColour (ListBox::backgroundColourId)
                                               .interpolatedWith (getLookAndFeel().findColour (ListBox::textColourId), 0.03f);
        if (rowIsSelected)
            g.fillAll (Colours::lightblue);
        else if (rowNumber % 2)
            g.fillAll (alternateColour);
    }

    // This is overloaded from TableListBoxModel and paints over non-custom components
    void paintCell (Graphics& g, int rowNumber, int columnId,
                    int width, int height, bool /*rowIsSelected*/) override
    {
        g.setColour (getLookAndFeel().findColour (ListBox::textColourId));
        g.setFont (font);

        if (auto* rowElement = dataList->getChildElement (rowNumber))
        {
            auto text = rowElement->getStringAttribute (getAttributeNameForColumnId (columnId));

            g.drawText (text, 2, 0, width - 4, height, Justification::centredLeft, true);
        }

        g.setColour (getLookAndFeel().findColour (ListBox::backgroundColourId));
        g.fillRect (width - 1, 0, 1, height);
    }

    // This is overloaded from TableListBoxModel, and tells us that the user has clicked a table header
    // to change the sort order.
    void sortOrderChanged (int newSortColumnId, bool isForwards) override
    {
        if (newSortColumnId != 0)
        {
            DemoDataSorter sorter (getAttributeNameForColumnId (newSortColumnId), isForwards);
            dataList->sortChildElements (sorter);

            table.updateContent();
        }
    }

    // This is overloaded from TableListBoxModel, and updates custom components
    Component* refreshComponentForCell (int rowNumber, int columnId, bool /*isRowSelected*/,
                                        Component* existingComponentToUpdate) override
    {
        if (columnId == 1 || columnId == 3) // The StepNr and Length columns do not have a custom component
        {
            jassert (existingComponentToUpdate == nullptr);
            return nullptr;
        }

        // The other columns are editable text columns, for which we use the custom Label component
        auto* textLabel = static_cast<EditableTextCustomComponent*> (existingComponentToUpdate);

        // same as above...
        if (textLabel == nullptr)
            textLabel = new EditableTextCustomComponent (*this);

        textLabel->setRowAndColumn (rowNumber, columnId);
        return textLabel;
    }

    // This is overloaded from TableListBoxModel, and should choose the best width for the specified
    // column.
    int getColumnAutoSizeWidth (int columnId) override
    {
        if (columnId == 1) //StepNr column
            return 50;

        int widest = 32;

        // find the widest bit of text in this column..
        for (int i = getNumRows(); --i >= 0;)
        {
            if (auto* rowElement = dataList->getChildElement (i))
            {
                auto text = rowElement->getStringAttribute (getAttributeNameForColumnId (columnId));

                widest = jmax (widest, font.getStringWidth (text));
            }
        }

        return widest + 8;
    }

    // A couple of quick methods to set and get cell values when the user changes them

    String getText (const int columnNumber, const int rowNumber) const
    {
        return dataList->getChildElement (rowNumber)->getStringAttribute ( getAttributeNameForColumnId(columnNumber));
    }

    void setText (const int columnNumber, const int rowNumber, const String& newText)
    {
        auto columnName = table.getHeader().getColumnName (columnNumber);
        dataList->getChildElement (rowNumber)->setAttribute (columnName, newText);
    }

    //==============================================================================
    void resized() override
    {
        // position our table with a gap around its edge
        table.setBoundsInset (BorderSize<int> (8));
    }


private:
    TableListBox table;     // the table component itself
    Font font  { 14.0f };

    std::unique_ptr<XmlElement> demoData;  // This is the XML document loaded from the embedded file "demo table data.xml"
    XmlElement* columnList = nullptr;     // A pointer to the sub-node of demoData that contains the list of columns
    XmlElement* dataList   = nullptr;     // A pointer to the sub-node of demoData that contains the list of data rows
    int numRows;                          // The number of rows of data we've got

    //==============================================================================
    // This is a custom Label component, which we use for the table's editable text columns.
    class EditableTextCustomComponent  : public Label
    {
    public:
        EditableTextCustomComponent (Sequencer& td)  : owner (td)
        {
            // double click to edit the label text; single click handled below
            setEditable (false, true, false);
        }

        void mouseDown (const MouseEvent& event) override
        {
            // single click on the label should simply select the row
            owner.table.selectRowsBasedOnModifierKeys (row, event.mods, false);

            Label::mouseDown (event);
        }

        void textWasEdited() override
        {
            owner.setText (columnId, row, getText());
        }

        // Our demo code will call this when we may need to update our contents
        void setRowAndColumn (const int newRow, const int newColumn)
        {
            row = newRow;
            columnId = newColumn;
            setText (owner.getText(columnId, row), dontSendNotification);
        }

        void paint (Graphics& g) override
        {
            auto& lf = getLookAndFeel();
            if (! dynamic_cast<LookAndFeel_V4*> (&lf))
                lf.setColour (textColourId, Colours::black);

            Label::paint (g);
        }

    private:
        Sequencer& owner;
        int row, columnId;
        Colour textColour;
    };

    //==============================================================================
    // A comparator used to sort our data when the user clicks a column header
    class DemoDataSorter
    {
    public:
        DemoDataSorter (const String& attributeToSortBy, bool forwards)
            : attributeToSort (attributeToSortBy),
              direction (forwards ? 1 : -1)
        {
        }

        int compareElements (XmlElement* first, XmlElement* second) const
        {
            auto result = first->getStringAttribute (attributeToSort)
                                .compareNatural (second->getStringAttribute (attributeToSort));

            if (result == 0)
                result = first->getStringAttribute ("ID")
                               .compareNatural (second->getStringAttribute ("ID"));

            return direction * result;
        }

    private:
        String attributeToSort;
        int direction;
    };

    //==============================================================================
    // this loads the embedded database XML file into memory
    void loadData()
    {
        demoData = parseXML (loadEntireAssetIntoString ("sequencer sample.xml"));

        dataList   = demoData->getChildByName ("DATA");
         columnList = demoData->getChildByName ("COLUMNS");

        numRows = dataList->getNumChildElements();
    }

    // (a utility method to search our XML for the attribute that matches a column ID)
    String getAttributeNameForColumnId (const int columnId) const
    {
        forEachXmlChildElement (*columnList, columnXml)
        {
            if (columnXml->getIntAttribute ("columnId") == columnId)
                return columnXml->getStringAttribute ("name");
        }

        return {};
    }

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (Sequencer)
};


//==============================================================================
struct DemoTabbedComponent  : public TabbedComponent
{
    DemoTabbedComponent (bool isRunning)
        : TabbedComponent (TabbedButtonBar::TabsAtTop)
    {
        auto colour = findColour (ResizableWindow::backgroundColourId);

        addTab ("Manual Control",     colour, buttonPanels, true);
        addTab ("Waypoint Editor",     colour, rotationPanel,true);
        addTab ("Settings",      colour, sequencer,true);
    }

    ButtonPanels* buttonPanels = new ButtonPanels();
    RotationPanel* rotationPanel = new RotationPanel();
    Sequencer* sequencer = new Sequencer();

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (DemoTabbedComponent)
};

//==============================================================================
struct ManualControl   : public Component
{
    ManualControl (bool isRunning = false)
        : tabs (isRunning)
    {
        setOpaque (true);
        addAndMakeVisible (tabs);

        setSize (700, 500);
    }

    void paint (Graphics& g) override
    {
        g.fillAll (Colours::lightgrey);
    }

    void resized() override
    {
        tabs.setBounds (getLocalBounds().reduced (4));

    }

    DemoTabbedComponent tabs;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (ManualControl)
};
