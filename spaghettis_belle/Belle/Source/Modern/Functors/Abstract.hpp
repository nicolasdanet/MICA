
/* 
    Copyright (c) 2007-2013 Andi Brae.
    Copyright (c) 2013 Jojo and others.
    
*/

/* < http://opensource.org/licenses/BSD-2-Clause > */

// -----------------------------------------------------------------------------------------------------------
// -----------------------------------------------------------------------------------------------------------

/* Engrave a stamp according to a token. */

// -----------------------------------------------------------------------------------------------------------
// -----------------------------------------------------------------------------------------------------------

namespace belle { 

// -----------------------------------------------------------------------------------------------------------
// -----------------------------------------------------------------------------------------------------------

class Music;

// -----------------------------------------------------------------------------------------------------------
// -----------------------------------------------------------------------------------------------------------
// MARK: -

class Engraver {

// -----------------------------------------------------------------------------------------------------------
// -----------------------------------------------------------------------------------------------------------
// MARK: -

public:
    virtual ~Engraver()
    {
    }

protected:
    Engraver() : selected_ (false)
    {
    }
    
    Engraver (const Engraver&) = default;
    Engraver (Engraver&&) = default;
    Engraver& operator = (const Engraver&) = default;
    Engraver& operator = (Engraver&&) = default;

// -----------------------------------------------------------------------------------------------------------
// -----------------------------------------------------------------------------------------------------------
// MARK: -

public:
    bool isSelected()
    {
        return selected_;
    }
    
    Engraver& setSelected (bool selected)
    {
        selected_ = selected; return *this;
    }
    
// -----------------------------------------------------------------------------------------------------------
// -----------------------------------------------------------------------------------------------------------

public:
    virtual Pointer<Engraver> clone() const = 0;

public:
    virtual void engrave (Music& music, NodePtr token, const Pointer<Stamp>& stamp) = 0;

// -----------------------------------------------------------------------------------------------------------
// -----------------------------------------------------------------------------------------------------------

private:
    bool selected_;
    
private:
    PRIM_LEAK_DETECTOR (Engraver)
};

// -----------------------------------------------------------------------------------------------------------
// -----------------------------------------------------------------------------------------------------------

/* Do something while traversing the music graph. */

// -----------------------------------------------------------------------------------------------------------
// -----------------------------------------------------------------------------------------------------------

class Music;

// -----------------------------------------------------------------------------------------------------------
// -----------------------------------------------------------------------------------------------------------
// MARK: -

struct Typesetter {

// -----------------------------------------------------------------------------------------------------------
// -----------------------------------------------------------------------------------------------------------
// MARK: -

class Partwise {

// -----------------------------------------------------------------------------------------------------------
// -----------------------------------------------------------------------------------------------------------

public:
    virtual ~Partwise()
    {
    }

protected:
    Partwise() = default;
    
    Partwise (const Partwise&) = default;
    Partwise (Partwise&&) = default;
    Partwise& operator = (const Partwise&) = default;
    Partwise& operator = (Partwise&&) = default;

public:
    virtual void start (Music&) const = 0;
    virtual void end (Music&) const = 0;
    virtual void endPart (Music&) const = 0;
    
public:
    virtual void perform (Music& music, NodePtr island) const = 0;

private:
    PRIM_LEAK_DETECTOR (Partwise)
};

// -----------------------------------------------------------------------------------------------------------
// -----------------------------------------------------------------------------------------------------------

class Instantwise {

// -----------------------------------------------------------------------------------------------------------
// -----------------------------------------------------------------------------------------------------------

public:
    virtual ~Instantwise()
    {
    }

protected:
    Instantwise() = default;
    
    Instantwise (const Instantwise&) = default;
    Instantwise (Instantwise&&) = default;
    Instantwise& operator = (const Instantwise&) = default;
    Instantwise& operator = (Instantwise&&) = default;

public:
    virtual void start (Music&) const = 0;
    virtual void end (Music&) const = 0;
    virtual void endInstant (Music&) const = 0;
    
public:
    virtual void perform (Music& music, NodePtr island) const = 0;

private:
    PRIM_LEAK_DETECTOR (Instantwise)
};

// -----------------------------------------------------------------------------------------------------------
// -----------------------------------------------------------------------------------------------------------

};

// -----------------------------------------------------------------------------------------------------------
// -----------------------------------------------------------------------------------------------------------

} // namespace belle

// -----------------------------------------------------------------------------------------------------------
// -----------------------------------------------------------------------------------------------------------
