#encoding "utf-8"

Indistinct -> Adv<kwset="нечеткие"> | Word<kwtype=fuzzy>;

Inaccurate -> Adv<kwset = "нечеткие">;

Indefinite -> Adv<kwset = "нечеткие">;

FuzLex -> Indistinct interp(FuzzyLexeme.Indistinct) | Inaccurate interp(FuzzyLexeme.Inaccurate) | Indefinite interp(FuzzyLexeme.Indefinite);
