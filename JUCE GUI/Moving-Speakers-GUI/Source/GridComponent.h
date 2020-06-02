

#pragma once

//==============================================================================
/*
    This component contains the grid layout for the main window and renders the flexbox containers visible
*/

class GridComponent   : public Component
{
public:

    GridComponent()
    {
        setSize (800,600); //default max size of overall window
    }

    void paint (Graphics& g) override
    {
        g.fillAll(Colour(56,56,56));

        g.setColour(Colour(84,84,84));
        g.fillRect(getLocalBounds().reduced(15,15)); //The working window inside of the window

    }

    void resized() override
    {
        Rectangle<int> window = getLocalBounds().reduced(15,15);
        Grid grid;

        using Track = Grid::TrackInfo;

        // Rows for header (navbar), 4 for the panel items, and footer (message log)
        grid.templateRows   = { Track(40_px), Track (1_fr), Track(1_fr), Track(1_fr), Track(1_fr), Track(90_px)};

        // 4 columns for the overall grid
        grid.templateColumns = { Track(1_fr), Track(1_fr), Track(1_fr), Track(1_fr)};

        grid.justifyContent = Grid::JustifyContent::center;
        grid.alignContent = Grid::AlignContent::center;

        grid.setGap(20_px); //creates gutters between items 20 pixels wide/high

        //Wrapping logic changes relative to the shape of the window
        grid.autoFlow = (window.getHeight() > window.getWidth()) ? Grid::AutoFlow::rowDense
                                                             : Grid::AutoFlow::columnDense;


        //grid.performLayout(getLocalBounds().reduced(15,15));
    }

    //void fillGrid(FlexBox panels[])
    //{
    //        grid.items.addArray (panels)
    //        grid.performLayout{getLocalBounds().reduced(15,15};
    //}

     //==============================================================================

private:

    FlexBox gridItems[16]; //maximum number of permissible panels
    FlexBox naviBar; //navigation bar at the top
    FlexBox logger; //message log at the bottom

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (GridComponent)
};
