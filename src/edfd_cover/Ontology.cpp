#include "Ontology.h"

Ontology::Ontology()
{

}

Ontology::Ontology(const std::vector<Ontology::Top_level> &top_levels, const std::vector<Ontology::Method> &methods, const std::vector<Ontology::Ruc> &rucs,
                   const std::vector<Ontology::Top_level_rel> &top_level_rel, const std::vector<Ontology::Top_ruc_rel> &top_ruc_rel) : m_top_levels(top_levels),
    m_methods(methods),
    m_rucs(rucs),
    m_top_level_rel(top_level_rel),
    m_top_ruc_rel(top_ruc_rel)
{}
