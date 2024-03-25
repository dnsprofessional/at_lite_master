#include "Ontology.h"
#include <fstream>
#include <unordered_map>

Ontology::Ontology()
{
}

Ontology::Ontology(const std::vector<Top_level> &top_levels, const std::vector<Method> &methods, const std::vector<Ruc> &rucs, const std::vector<Top_level_rel> &top_level_rel,
                   const std::vector<Top_ruc_rel> &top_ruc_rel) : m_top_levels(top_levels),m_methods(methods),m_rucs(rucs),m_top_level_rel(top_level_rel),m_top_ruc_rel(top_ruc_rel)
{

}

void ontology_to_graphviz(Ontology& onto){
    std::ofstream os("kb/ontology.dot");
    os << "digraph g {\n";
    for(auto& top_level_rel : onto.m_top_level_rel){
        std::string src_name;
        std::string dest_name;
        for(auto& top_level : onto.m_top_levels){
            if(top_level.id == top_level_rel.src_id){
                src_name = top_level.name;
                break;
            }
        }
        for(auto& top_level : onto.m_top_levels){
            if(top_level.id == top_level_rel.dest_id){
                dest_name = top_level.name;
                break;
            }
        }
        os << "\t \"" << src_name << "\" -> \"" << dest_name << "\";\n";
    }
    for(auto iter = onto.m_methods.begin(); iter != onto.m_methods.end() - 1; iter++){
        os << "\"" << iter->name << "\" -> ";
    }
    os << "\"" << (onto.m_methods.end() - 1)->name << "\"[style=invis];\n";
    for(auto iter = onto.m_rucs.begin(); iter != onto.m_rucs.end() - 1; iter++){
        os << "\"" << iter->name << "\" -> ";
    }
    os << "\"" << (onto.m_rucs.end() - 1)->name << "\"[style=invis];\n";
    static const std::unordered_map<Ontology::Rel_type, std::string> type_to_string = {
        {Ontology::Rel_type::RA, "RA"},
        {Ontology::Rel_type::RS, "RS"},
        {Ontology::Rel_type::RM, "RM"},
        {Ontology::Rel_type::RL, "RL"}
    };
    for(auto& method_rel : onto.m_method_rels){
        std::string src_name;
        std::string dest_name;
        std::string type;
        for(auto& method : onto.m_methods){
            if(method.id == method_rel.src_id){
                src_name = method.name;
                break;
            }
        }
        for(auto& method : onto.m_methods){
            if(method.id == method_rel.dest_id){
                dest_name = method.name;
                break;
            }
        }
        type = type_to_string.find(method_rel.type)->second;
        os << "\t \"" << src_name << "\" -> \"" << dest_name << "\" [label=\"" << type << "\"];\n";
    }
    for(auto& ruc : onto.m_rucs){
        for(auto& method_id : ruc.methods){
            for(auto& method : onto.m_methods){
                if(method_id == method.id)
                    os << "\t \"" << ruc.name << "\" -> \"" << method.name << "\" [label=RS];\n";
            }
        }
    }
    os << "}";
}

void Ontology::init_methods_rels(){
    for(auto& ruc : m_rucs){
        if(ruc.methods.empty())
            continue;
        std::vector<Method*> methods;
        //Извлекаем методы из ПИК по id методов
        for(auto& method_id : ruc.methods){
            for(auto& method : m_methods){
                if(method_id == method.id){
                    Method* ptr = &method;
                    methods.push_back(ptr);
                }
            }
        }
        for(auto method1 = methods.begin(); method1 != methods.end(); method1++){
            for(auto method2 = method1 + 1; method2 != methods.end(); method2++){
                std::size_t weight = 0;
                for(auto& attribute1 : (*method1)->attributes){
                    for(auto& attribute2 : (*method2)->attributes){
                        if(attribute1.name == attribute2.name){
                            if(attribute1.type == attribute2.type)
                                weight += 2;
                            else
                                weight += 1;
                        }
                    }
                }
                if(weight < 2)
                    continue;
                Method_rel method_rel;
                method_rel.src_id = (*method1)->id;
                method_rel.dest_id = (*method2)->id;
                if(weight >= 6){
                    method_rel.type = Ontology::Rel_type::RS;
                } else if(weight >= 4 && weight < 6) {
                    method_rel.type = Ontology::Rel_type::RM;
                } else {
                    method_rel.type = Ontology::Rel_type::RL;
                }
                m_method_rels.push_back(method_rel);
            }
        }
    }
}

