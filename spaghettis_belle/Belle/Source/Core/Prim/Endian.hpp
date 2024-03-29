
/* 
    Copyright (c) 2007-2013 Andi Brae.
    Copyright (c) 2013 Jojo and others.
    
*/

/* < http://opensource.org/licenses/BSD-2-Clause > */

// -----------------------------------------------------------------------------------------------------------
// -----------------------------------------------------------------------------------------------------------

namespace prim {

// -----------------------------------------------------------------------------------------------------------
// -----------------------------------------------------------------------------------------------------------
// MARK: -

struct Endian {

// -----------------------------------------------------------------------------------------------------------
// -----------------------------------------------------------------------------------------------------------
// MARK: -

public:
    template <class T> static void swapIfBigEndian (T& data)
    {
        (void)data;
        
        #if PRIM_BIG_ENDIAN
        swapByteOrder (data);
        #endif
    }

    template <class T> static void swapIfLittleEndian (T& data)
    {
        (void)data;
        
        #if PRIM_LITTLE_ENDIAN
        swapByteOrder (data);
        #endif
    }

// -----------------------------------------------------------------------------------------------------------
// -----------------------------------------------------------------------------------------------------------
// MARK: -

private:
    template <class T> static void swapByteOrder (T& data)
    {
        T v = 0;
        
        byte* a = reinterpret_cast<byte*> (&data);
        byte* b = reinterpret_cast<byte*> (&v);
      
        for (std::size_t i = 0; i < sizeof (T); ++i) { b[i] = a[sizeof (T) - i - 1]; }
        
        data = v;
    }

// -----------------------------------------------------------------------------------------------------------
// -----------------------------------------------------------------------------------------------------------

};

// -----------------------------------------------------------------------------------------------------------
// -----------------------------------------------------------------------------------------------------------

} // namespace prim

// -----------------------------------------------------------------------------------------------------------
// -----------------------------------------------------------------------------------------------------------
