#ifndef ONTOLOGYDOCUMENT_H
#define ONTOLOGYDOCUMENT_H

#include "../ADocument.h"
#include "Ontology.h"
#include <memory>

class AT_CORE_API OntologyDocument : public AXMLDocument
{
private:
    Ontology deserialize_ontology(_xmlNode* ontology_node) const;
    Ontology::Top_level deserialize_top_level(_xmlNode* top_level_node) const;
    Ontology::Top_level_rel deserialize_top_rel(_xmlNode* top_rel_node) const;
    Ontology::Top_ruc_rel deserialize_top_ruc_rel(_xmlNode* top_ruc_rel_node) const;
    Ontology::Method deserialize_method(_xmlNode* method_node) const;
    Ontology::Ruc deserialize_ruc(_xmlNode* ruc_node) const;
    Ontology::Attribute deserialize_attribute(_xmlNode* attribute_node) const;
    Ontology::Top_method_rel deserialize_top_method_rel(_xmlNode* attribute_node) const;
    Ontology::Ruc_method_rel deserialize_ruc_method_rel(_xmlNode* attribute_node) const;
public:
    virtual void serialize(_xmlNode * document_node) const override;
    virtual AError deserialize(_xmlNode * document_node) override;
    virtual Type type() const override;
};

#endif // ONTOLOGYDOCUMENT_H
