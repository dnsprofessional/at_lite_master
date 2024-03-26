#ifndef ONTOLOGY_H
#define ONTOLOGY_H

#include <string>
#include <list>
#include <vector>
#include "../config.h"

class AT_CORE_API Ontology
{
public:
    enum class Rel_type{
        RA,
        RS,
        RM,
        RL
    };
    struct Top_level{
        enum class Type{
            Subsystem,
            Tools,
            Component
        };
        std::size_t id;
        std::string name;
        Type type;
    };
    struct Attribute{
      std::string name;
      enum class Type{
        Necessary,
        NotNecessary
      };
      Type type;
    };
    struct Ruc_method_rel{
        Rel_type type;
        std::size_t src_id;
        std::size_t dest_id;
    };
    struct Top_method_rel{
        Rel_type type;
        std::size_t src_id;
        std::size_t dest_id;
    };
    struct Method_rel{
        Rel_type type;
        std::size_t src_id;
        std::size_t dest_id;
    };
    struct Method {
        std::size_t id;
        std::string name;
        std::list<Attribute> attributes;
    };
    struct Ruc {
        std::size_t id;
        std::string name;
        std::list<std::size_t> methods;
        std::list<std::size_t> interfaces;
    };
    struct Top_level_rel {
        std::size_t src_id;
        std::size_t dest_id;
    };
    struct Top_ruc_rel {
        std::size_t src_id;
        std::size_t dest_id;
        std::size_t weight;
    };
    friend void ontology_to_graphviz(Ontology& onto);
    void init_methods_rels();
    Ontology();
    Ontology(const std::vector<Top_level> &top_levels, const std::vector<Method> &methods, const std::vector<Ruc> &rucs, const std::vector<Top_level_rel> &top_level_rel,
             const std::vector<Top_ruc_rel> &top_ruc_rel, const std::vector<Top_method_rel> &top_method_rels, const std::vector<Ruc_method_rel> &ruc_method_rels);
private:
    std::vector<Top_level> m_top_levels;
    std::vector<Method> m_methods;
    std::vector<Ruc> m_rucs;
    std::vector<Top_level_rel> m_top_level_rel;
    std::vector<Top_ruc_rel> m_top_ruc_rel;
    std::vector<Method_rel> m_method_rels;
    std::vector<Top_method_rel> m_top_method_rels;
    std::vector<Ruc_method_rel> m_ruc_method_rels;
};

#endif // ONTOLOGY_H
