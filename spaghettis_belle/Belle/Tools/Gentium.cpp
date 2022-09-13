
/* 
    Copyright (c) 2007-2013 Andi Brae.
    Copyright (c) 2013 Jojo and others.
    
*/

/* < http://opensource.org/licenses/BSD-2-Clause > */

// -----------------------------------------------------------------------------------------------------------
// -----------------------------------------------------------------------------------------------------------

/* From Gentium.ttf to bellefont. */

// -----------------------------------------------------------------------------------------------------------
// -----------------------------------------------------------------------------------------------------------
// MARK: -

#define BELLE_COMPILE_INLINE

// -----------------------------------------------------------------------------------------------------------
// -----------------------------------------------------------------------------------------------------------

#include "../Source/Belle.hpp"
#include "../Source/Core/FreeType/FreeType.hpp"

// -----------------------------------------------------------------------------------------------------------
// -----------------------------------------------------------------------------------------------------------

using namespace prim;
using namespace belle;

// -----------------------------------------------------------------------------------------------------------
// -----------------------------------------------------------------------------------------------------------
// MARK: -

void convert (const std::string& name)
{
    /* LLVM analyzer seems to report false positives. */
    
    #ifndef __clang_analyzer__
    
    std::string filepath;
    
    filepath += "../../../Resources/Gentium/";
    filepath += name;
    filepath += ".ttf";
    
    Typeface typeface;
    
    if (typeface.importFont (filepath.c_str())) {
        Array<byte> t;
        typeface.exportBinary (t);
        File::writeByArray ((name + ".bellefont").c_str(), t);
    }
    
    #endif
}

// -----------------------------------------------------------------------------------------------------------
// -----------------------------------------------------------------------------------------------------------
// MARK: -

int main()
{
    convert ("GentiumBasicRegular");
    convert ("GentiumBasicBold");
    convert ("GentiumBasicItalic");
    convert ("GentiumBasicBoldItalic");
    
    return 0;
}

// -----------------------------------------------------------------------------------------------------------
// -----------------------------------------------------------------------------------------------------------
