
/* Copyright (c) 2013 Jojo and others. */

/* < http://opensource.org/licenses/BSD-2-Clause > */

// -----------------------------------------------------------------------------------------------------------
// -----------------------------------------------------------------------------------------------------------

namespace MIR {

// -----------------------------------------------------------------------------------------------------------
// -----------------------------------------------------------------------------------------------------------
// MARK: -

struct Utils {

// -----------------------------------------------------------------------------------------------------------
// -----------------------------------------------------------------------------------------------------------
// MARK: -

static prim::Table<Concept> getAccidentalsByLetters (Concept keySignature)
{
    prim::Table<Concept> table;
    
    if (!keySignature.isUndefined()) {
    //
    PRIM_ASSERT (index (mica::KeySignatures, keySignature).isUndefined() == false);
    
    Concept letters = mica::Letters;
    
    for (int i = 0; i < letters.length(); ++i) { table[item (letters, i)] = mica::Natural; }
    
    Concept accidental = map (keySignature, mica::Accidental);
    
    for (int i = 0; i < keySignature.length(); ++i) { table[item (keySignature, i)] = accidental; }
    //
    }
    
    return table;
}

// -----------------------------------------------------------------------------------------------------------
// -----------------------------------------------------------------------------------------------------------

};

// -----------------------------------------------------------------------------------------------------------
// -----------------------------------------------------------------------------------------------------------

} // namespace MIR

// -----------------------------------------------------------------------------------------------------------
// -----------------------------------------------------------------------------------------------------------
