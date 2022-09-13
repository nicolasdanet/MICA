
/* < https://opensource.org/licenses/BSD-3-Clause > */

// -----------------------------------------------------------------------------------------------------------
// -----------------------------------------------------------------------------------------------------------
// MARK: -

/* Testing MIR pitch spelling. */

// -----------------------------------------------------------------------------------------------------------
// -----------------------------------------------------------------------------------------------------------

#include "t_spelling.hpp"

// -----------------------------------------------------------------------------------------------------------
// -----------------------------------------------------------------------------------------------------------

#if 0
void test170__corpus() {
#endif

// -----------------------------------------------------------------------------------------------------------
// -----------------------------------------------------------------------------------------------------------

TTT_BEGIN (MicaCorpus, 170, "MICA - Corpus")

    prim::Array<int> numbers;
    
    for (int i = 0; i < testCorpusSize; ++i) { numbers.add (testCorpus[i]); }
        
    prim::Array<mica::Concept> result = (mica::MIR::Spell (mica::CMajor).getSpelling (numbers));
    
    for (int i = 0; i < result.size(); ++i) {
        // ttt_stdout (TTT_COLOR_BLUE, "%s", const_cast<char*> (result[i].toString().c_str()));
    }
    
TTT_END

// -----------------------------------------------------------------------------------------------------------
// -----------------------------------------------------------------------------------------------------------

#if 0
}
#endif

// -----------------------------------------------------------------------------------------------------------
// -----------------------------------------------------------------------------------------------------------