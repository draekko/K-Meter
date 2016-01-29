/* ----------------------------------------------------------------------------

   MZ common JUCE
   ==============
   Common classes for use with the JUCE library

   Copyright (c) 2010-2016 Martin Zuther (http://www.mzuther.de/)

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.

   Thank you for using free software!

---------------------------------------------------------------------------- */

#ifndef __GENERIC_METER_BAR_H__
#define __GENERIC_METER_BAR_H__

#include "JuceHeader.h"
#include "generic_meter_segment_continuous.h"
#include "generic_meter_segment_discrete.h"


/// Meter bar component.  This widget is an empty container that can
/// be filled with meter segment widgets.  These can then be
/// comfortably updated with a single function call.
///
/// @see GenericMeterSegment
///
class GenericMeterBar :
    public Component
{
public:
    /// Orientation for the meter.
    enum Orientation  // public namespace!
    {
        /// horizontal meter (bottom to top)
        orientationHorizontal =
            GenericMeterSegment::orientationHorizontal,

        /// inverted horizontal meter (top to bottom)
        orientationHorizontalInverted =
            GenericMeterSegment::orientationHorizontalInverted,

        /// vertical meter (left to right)
        orientationVertical =
            GenericMeterSegment::orientationVertical,

        /// inverted vertical meter (right to left)
        orientationVerticalInverted =
            GenericMeterSegment::orientationVerticalInverted
    };

    virtual void create();

    virtual void addSegment(GenericMeterSegment *segment,
                            int segmentHeight,
                            int spacingBefore);

    virtual void addDiscreteSegment(float lowerThreshold,
                                    float thresholdRange,
                                    bool isTopmost,
                                    int segmentHeight,
                                    int spacingBefore,
                                    const Colour &segmentColour,
                                    const Colour &colPeakMarker);

    virtual void addContinuousSegment(float lowerThreshold,
                                      float thresholdRange,
                                      bool isTopmost,
                                      int segmentHeight,
                                      int spacingBefore,
                                      const Colour &segmentColour,
                                      const Colour &colPeakMarker);

    virtual GenericMeterBar::Orientation getOrientation();
    virtual void setOrientation(GenericMeterBar::Orientation orientation);

    virtual void invertMeter(bool invert);
    virtual bool isMeterInverted();

    virtual int getSegmentWidth();
    virtual void setSegmentWidth(int segmentWidth);

    virtual void setNormalLevels(float normalLevel,
                                 float normalLevelPeak);

    virtual void setDiscreteLevels(float discreteLevel,
                                   float discreteLevelPeak);

    virtual void setLevels(float normalLevel,
                           float normalLevelPeak,
                           float discreteLevel,
                           float discreteLevelPeak);

    virtual void paint(Graphics &g);
    virtual void resized();

private:
    JUCE_LEAK_DETECTOR(GenericMeterBar);

    float normalLevel_;
    float normalLevelPeak_;

    float discreteLevel_;
    float discreteLevelPeak_;

    int barWidth_;
    int barHeight_;
    int segmentWidth_;

    bool isVertical_;
    bool isInverted_;

    GenericMeterBar::Orientation orientation_;
    Array<int> segmentSpacing_;
    OwnedArray<GenericMeterSegment> meterSegments_;
};


#endif  // __GENERIC_METER_BAR_H__


// Local Variables:
// ispell-local-dictionary: "british"
// End:
