
/* 
    Copyright (c) 2007-2013 Andi Brae.
    Copyright (c) 2013 Jojo and others.
    
*/

/* < http://opensource.org/licenses/BSD-2-Clause > */

// -----------------------------------------------------------------------------------------------------------
// -----------------------------------------------------------------------------------------------------------

/* To be safely used as a Key in a Table. */

// -----------------------------------------------------------------------------------------------------------
// -----------------------------------------------------------------------------------------------------------

namespace prim {

// -----------------------------------------------------------------------------------------------------------
// -----------------------------------------------------------------------------------------------------------
// MARK: -

class String {

// -----------------------------------------------------------------------------------------------------------
// -----------------------------------------------------------------------------------------------------------
// MARK: -

public:
    String (const char* s = nullptr)
    {
        int size = s ? static_cast<int> (std::strlen (s)) : 0;
    
        data_.resize (size + 1); PRIM_ASSERT (data_.getLast() == 0);
    
        if (size) { for (int i = 0; i < size; ++i) { data_[i] = s[i]; } }
    }
    
public:
    String (const String&) = default;
    String & operator = (const String& o) = default;
    String (String&&) = default;
    String& operator = (String&&) = default;

// -----------------------------------------------------------------------------------------------------------
// -----------------------------------------------------------------------------------------------------------
// MARK: -

public:
    void swapWith (String& o)
    {
        data_.swapWith (o.data_);
    }

// -----------------------------------------------------------------------------------------------------------
// -----------------------------------------------------------------------------------------------------------
// MARK: -

public:
    bool operator < (const String& o) const
    {
        const char *s1 = &data_[0]; const char *s2 = &o.data_[0];
        
        return std::strcmp (s1, s2) < 0;
    }

    bool operator > (const String& o) const
    {
        const char *s1 = &data_[0]; const char *s2 = &o.data_[0];
        
        return std::strcmp (s1, s2) > 0;
    }
    
    bool operator == (const String& o) const
    {
        const char *s1 = &data_[0]; const char *s2 = &o.data_[0];
        
        return std::strcmp (s1, s2) == 0;
    }
    
    bool operator != (const String& o) const
    {
        return !((*this) == o);
    }
    
// -----------------------------------------------------------------------------------------------------------
// -----------------------------------------------------------------------------------------------------------

private:
    Array<char> data_;

private:
    PRIM_LEAK_DETECTOR (String)
};

// -----------------------------------------------------------------------------------------------------------
// -----------------------------------------------------------------------------------------------------------
// MARK: -

void swap (String& a, String& b);

// -----------------------------------------------------------------------------------------------------------
// -----------------------------------------------------------------------------------------------------------

#ifdef BELLE_COMPILE_INLINE

// -----------------------------------------------------------------------------------------------------------
// -----------------------------------------------------------------------------------------------------------

void swap (String& a, String& b)
{
    a.swapWith (b);
}

// -----------------------------------------------------------------------------------------------------------
// -----------------------------------------------------------------------------------------------------------

#endif // BELLE_COMPILE_INLINE

// -----------------------------------------------------------------------------------------------------------
// -----------------------------------------------------------------------------------------------------------

} // namespace prim

// -----------------------------------------------------------------------------------------------------------
// -----------------------------------------------------------------------------------------------------------