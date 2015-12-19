// KeypressInteractionReader.hpp
//
// ICS 45C Fall 2015
// Project #4: People Just Want to Play with Words
//
// A KeypressInteractionReader reads interactions by reading keypresses
// and then converting them (e.g., by converting Ctrl+Z to an undo
// interaction, or by converting a typical keypress like 'a' to a
// command interaction).
//
// Note that this class requires some modifications from you; check out
// the corresponding source file for more details.
//
// DO NOT MODIFY THIS FILE, BUT YOU WILL NEED TO MODIFY THE SOURCE FILE

#ifndef KEYPRESSINTERACTIONREADER_HPP
#define KEYPRESSINTERACTIONREADER_HPP

#include "InteractionReader.hpp"
#include "KeypressReader.hpp"



class KeypressInteractionReader : public InteractionReader
{
public:
    explicit KeypressInteractionReader(KeypressReader& keypressReader)
        : keypressReader{keypressReader}
    {
    }


    virtual Interaction nextInteraction();


private:
    KeypressReader& keypressReader;
};



#endif // KEYPRESSINTERACTIONREADER_HPP

