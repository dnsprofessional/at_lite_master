#include "OntologyDocument.h"
#include "../utils/xml_helpers.h"
#include <iostream>
#include <unordered_map>
#include <iterator>
#include <sstream>

void OntologyDocument::serialize(_xmlNode* document_node) const
{
    std::ignore = document_node;
    //TODO: maybe add real serialization later, not needed for now because AT has not editor for it
}

AError OntologyDocument::deserialize(_xmlNode* document_node)
{
    deserialize_ontology(document_node);
    return AError(AT_ERROR_OK);
}


ADocument::Type OntologyDocument::type() const
{
    return Type::Ontology;
}

std::list<std::size_t> string_to_list(std::stringstream item_stream){
    std::string item;
    std::list<std::size_t> item_list;
    while (std::getline(item_stream, item, ' ')) {
      item_list.push_back(stoi(item));
    }
    return item_list;
}

Ontology OntologyDocument::deserialize_ontology(_xmlNode* ontology_node) const {
    std::vector<Ontology::Top_level> v_top_levels;
    std::vector<Ontology::Method> v_methods;
    std::vector<Ontology::Ruc> v_rucs;
    std::vector<Ontology::Top_level_rel> v_top_level_rel;
    std::vector<Ontology::Top_ruc_rel> v_top_ruc_rels;
    std::vector<Ontology::Top_method_rel> v_top_method_rels;
    std::vector<Ontology::Ruc_method_rel> v_ruc_method_rels;

    xmlNode* top_level = child_for_path(ontology_node, "top_level");
    if (top_level != nullptr)
        xml_for_each_child(top_level, vertex)
            v_top_levels.push_back(deserialize_top_level(vertex));

    xmlNode* top_rels = child_for_path(ontology_node, "top_rels");
    if (top_rels != nullptr)
        xml_for_each_child(top_rels, top_rel)
            v_top_level_rel.push_back(deserialize_top_rel(top_rel));

    xmlNode* top_method_rels = child_for_path(ontology_node, "top_method_rels");
    if (top_rels != nullptr)
        xml_for_each_child(top_method_rels, top_method_rel)
            v_top_method_rels.push_back(deserialize_top_method_rel(top_method_rel));

    xmlNode* ruc_method_rels = child_for_path(ontology_node, "ruc_method_rels");
    if (top_rels != nullptr)
        xml_for_each_child(ruc_method_rels, ruc_method_rel)
            v_ruc_method_rels.push_back(deserialize_ruc_method_rel(ruc_method_rel));

//    xmlNode* top_ruc_rels = child_for_path(ontology_node, "top_ruc_rels");
//    if (top_ruc_rels != nullptr)
//        xml_for_each_child(top_ruc_rels, top_ruc_rel)
//            v_top_ruc_rels.push_back(deserialize_top_ruc_rel(top_ruc_rel));

    xmlNode* methods = child_for_path(ontology_node, "methods");
    if (methods != nullptr)
        xml_for_each_child(methods, method)
            v_methods.push_back(deserialize_method(method));

    xmlNode* rucs = child_for_path(ontology_node, "RUCs");
    if (rucs != nullptr)
        xml_for_each_child(rucs, ruc)
            v_rucs.push_back(deserialize_ruc(ruc));

    Ontology res(v_top_levels, v_methods, v_rucs, v_top_level_rel, v_top_ruc_rels, v_top_method_rels, v_ruc_method_rels);
    res.init_methods_rels();
    ontology_to_graphviz(res);
    system("dot -Tpng kb/ontology.dot -o kb/ontology.png");
    system("open kb/ontology.png");
    return Ontology(v_top_levels, v_methods, v_rucs, v_top_level_rel, v_top_ruc_rels, v_top_method_rels, v_ruc_method_rels);
}

Ontology::Top_method_rel OntologyDocument::deserialize_top_method_rel(_xmlNode* top_rel_node) const {
    Ontology::Top_method_rel result;
    static const std::unordered_map<std::string, Ontology::Rel_type> string_to_rel_type = {
        {"RA", Ontology::Rel_type::RA},
        {"RS", Ontology::Rel_type::RS},
        {"RM", Ontology::Rel_type::RM},
        {"RL", Ontology::Rel_type::RL}
    };
    result.src_id  = atoi(xml_prop(top_rel_node, "top_id"));
    result.dest_id = atoi(xml_prop(top_rel_node, "method_id"));
    result.type = string_to_rel_type.find(xml_prop(top_rel_node, "type"))->second;
    return result;
}

Ontology::Ruc_method_rel OntologyDocument::deserialize_ruc_method_rel(_xmlNode* top_rel_node) const {
    Ontology::Ruc_method_rel result;
    static const std::unordered_map<std::string, Ontology::Rel_type> string_to_rel_type = {
        {"RA", Ontology::Rel_type::RA},
        {"RS", Ontology::Rel_type::RS},
        {"RM", Ontology::Rel_type::RM},
        {"RL", Ontology::Rel_type::RL}
    };
    result.src_id  = atoi(xml_prop(top_rel_node, "ruc_id"));
    result.dest_id = atoi(xml_prop(top_rel_node, "method_id"));
    result.type = string_to_rel_type.find(xml_prop(top_rel_node, "type"))->second;
    return result;
}

Ontology::Top_level OntologyDocument::deserialize_top_level(_xmlNode* top_level_node) const {
    Ontology::Top_level result;

    result.id = atoi(xml_prop(top_level_node, "id"));
    result.name = xml_prop(top_level_node, "name");

    static const std::unordered_map<std::string, Ontology::Top_level::Type> stringToType = {
        {"Subsystem", Ontology::Top_level::Type::Subsystem},
        {"Tools", Ontology::Top_level::Type::Tools},
        {"Component", Ontology::Top_level::Type::Component}
    };

    auto type_str = xml_prop(top_level_node, "type");
    auto type_it = stringToType.find(type_str);
    if (type_it != stringToType.end())
    {
        result.type = type_it->second;
    }
    else
    {
        std::cout << "Warning: wrong type of Top_level node " << type_str << std::endl;
        result.type = Ontology::Top_level::Type::Subsystem;
    }

    return result;
}

Ontology::Top_level_rel OntologyDocument::deserialize_top_rel(_xmlNode* top_rel_node) const {
    Ontology::Top_level_rel result;
    result.src_id  = atoi(xml_prop(top_rel_node, "src_id"));
    result.dest_id = atoi(xml_prop(top_rel_node, "dest_id"));
    return result;
}

Ontology::Top_ruc_rel OntologyDocument::deserialize_top_ruc_rel(_xmlNode* top_ruc_rel_node) const {
    Ontology::Top_ruc_rel result;
    result.src_id  = atoi(xml_prop(top_ruc_rel_node, "top_level_id"));
    result.dest_id = atoi(xml_prop(top_ruc_rel_node, "ruc_id"));
    result.weight = atoi(xml_prop(top_ruc_rel_node, "weight"));
    return result;
}

Ontology::Attribute OntologyDocument::deserialize_attribute(_xmlNode *attribute_node) const {
    Ontology::Attribute result;
    static const std::unordered_map<std::string, Ontology::Attribute::Type> stringToAttType = {
        {"Y", Ontology::Attribute::Type::Necessary},
        {"N", Ontology::Attribute::Type::NotNecessary}
    };
    result.name = xml_prop(attribute_node, "name");
    result.type = stringToAttType.find(xml_prop(attribute_node, "necessary"))->second;
    return result;
}

Ontology::Method OntologyDocument::deserialize_method(_xmlNode* method_node) const {
    Ontology::Method result;
    result.name = xml_prop(method_node, "name");
    result.id = atoi(xml_prop(method_node, "id"));
    xmlNode* attributes = child_for_path(method_node, "attributes");
    if(attributes != nullptr)
        xml_for_each_child(attributes, attribute)
            result.attributes.push_back(deserialize_attribute(attribute));
    return result;
}

Ontology::Ruc OntologyDocument::deserialize_ruc(_xmlNode* ruc_node) const {
    Ontology::Ruc result;
    result.name  = xml_prop(ruc_node, "name");
    result.methods = string_to_list(std::stringstream(xml_prop(ruc_node, "methods")));
    result.interfaces  = string_to_list(std::stringstream(xml_prop(ruc_node, "interfaces")));
    result.id  = atoi(xml_prop(ruc_node, "id"));
    return result;
}
