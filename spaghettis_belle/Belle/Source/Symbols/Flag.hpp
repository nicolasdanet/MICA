
/* 
    Copyright (c) 2007-2013 Andi Brae.
    Copyright (c) 2013 Jojo and others.
    
*/

/* < http://opensource.org/licenses/BSD-2-Clause > */

// -----------------------------------------------------------------------------------------------------------
// -----------------------------------------------------------------------------------------------------------

/* < https://en.wikipedia.org/wiki/Note_value > */

// -----------------------------------------------------------------------------------------------------------
// -----------------------------------------------------------------------------------------------------------

namespace belle {

// -----------------------------------------------------------------------------------------------------------
// -----------------------------------------------------------------------------------------------------------

namespace Shapes {

// -----------------------------------------------------------------------------------------------------------
// -----------------------------------------------------------------------------------------------------------
// MARK: -

class FlagStemUp {

// -----------------------------------------------------------------------------------------------------------
// -----------------------------------------------------------------------------------------------------------
// MARK: -

public:
    FlagStemUp() : affine_ (House::kAffineJoie * House::kAffineJoieFlag)
    {
    }

public:
    FlagStemUp (const FlagStemUp&) = default;
    FlagStemUp (FlagStemUp&&) = default;
    FlagStemUp& operator = (const FlagStemUp&) = default;
    FlagStemUp& operator = (FlagStemUp&&) = default;

// -----------------------------------------------------------------------------------------------------------
// -----------------------------------------------------------------------------------------------------------
// MARK: -

public:
    void addToPath (Path& path) const
    {
        path.addPath (House::getInstance().getJoie().getGlyph (0x0057)->getPath(), affine_);
    }

private:
    Affine affine_;

private:
    PRIM_LEAK_DETECTOR (FlagStemUp)
};

// -----------------------------------------------------------------------------------------------------------
// -----------------------------------------------------------------------------------------------------------
// MARK: -

class FlagStemDown {

// -----------------------------------------------------------------------------------------------------------
// -----------------------------------------------------------------------------------------------------------
// MARK: -

public:
    FlagStemDown() : affine_ (House::kAffineJoie * House::kAffineJoieFlag * Affine::flipHorizontal())
    {
    }

public:
    FlagStemDown (const FlagStemDown&) = default;
    FlagStemDown (FlagStemDown&&) = default;
    FlagStemDown& operator = (const FlagStemDown&) = default;
    FlagStemDown& operator = (FlagStemDown&&) = default;

// -----------------------------------------------------------------------------------------------------------
// -----------------------------------------------------------------------------------------------------------
// MARK: -

public:
    void addToPath (Path& path) const
    {
        path.addPath (House::getInstance().getJoie().getGlyph (0x0057)->getPath(), affine_);
    }

private:
    Affine affine_;

private:
    PRIM_LEAK_DETECTOR (FlagStemDown)
};

// -----------------------------------------------------------------------------------------------------------
// -----------------------------------------------------------------------------------------------------------

} // namespace Shapes

// -----------------------------------------------------------------------------------------------------------
// -----------------------------------------------------------------------------------------------------------

} // namespace belle

// -----------------------------------------------------------------------------------------------------------
// -----------------------------------------------------------------------------------------------------------