#ifndef ONTOLOGY_H
#define ONTOLOGY_H

#include <string>
#include <list>
#include <vector>
#include "../ATCore/utils/xml_helpers.h"

class Ontology
{
private:
    class Top_level{
    private:
        std::size_t m_id;
        std::string m_name;
        std::size_t m_type;
    public:
        enum type{
            subsystem,
            tools,
            component
        };
        Top_level(std::size_t id, std::string name, std::size_t type) : m_id(id), m_name(name), m_type(type){}
        std::size_t get_id() const {
            return m_id;
        }
        std::string get_name() const {
            return m_name;
        }
        std::size_t get_type() const{
            return m_type;
        }
    };
    class Method {
    private:
        std::size_t m_id;
        std::string m_name;
    public:
        Method(std::size_t id, std::string name) : m_id(id), m_name(name){}
        std::size_t get_id() const {
            return m_id;
        }
        const std::string get_name() const {
            return m_name;
        }
    };
    class Ruc {
    private:
        std::size_t m_id;
        std::list<std::size_t> m_methods;
        std::list<std::size_t> m_interfaces;
    public:
        Ruc(std::size_t id, std::list<std::size_t> methods, std::list<std::size_t> interfaces) : m_id(id), m_methods(methods), m_interfaces(interfaces){}
        std::size_t get_id() const {
            return m_id;
        }
        std::list<std::size_t>& get_methods() {
            return m_methods;
        }
        std::list<std::size_t>& get_interfaces() {
            return m_interfaces;
        }
    };
    class Top_level_rel {
    private:
        std::size_t m_type;
        std::size_t m_src_id;
        std::size_t m_dest_id;
    public:
        Top_level_rel(std::size_t type, std::size_t src_id, std::size_t dest_id) : m_type(type), m_src_id(src_id),m_dest_id(dest_id) {}
        std::size_t get_type() const {
            return m_type;
        }
        std::size_t get_src_id() const {
            return m_src_id;
        }
        std::size_t get_dest_id() const {
            return m_dest_id;
        }
    };
    class Top_ruc_rel {
    private:
        std::size_t m_src_id;
        std::size_t m_dest_id;
        std::size_t m_weight;
    public:
        Top_ruc_rel(std::size_t src_id, std::size_t dest_id, std::size_t weight) : m_src_id(src_id), m_dest_id(dest_id), m_weight(weight){}
        std::size_t get_src_id() const {
            return m_src_id;
        }
        std::size_t get_dest_id() const {
            return m_dest_id;
        }
        std::size_t get_weight() const {
            return m_weight;
        }
    };
    std::string path = "kb/ontology.xml";
    std::vector<Top_level> m_top_levels;
    std::vector<Method> m_methods;
    std::vector<Ruc> m_rucs;
    std::vector<Top_level_rel> m_top_level_rel;
    std::vector<Top_ruc_rel> m_top_ruc_rel;
public:
    Ontology();
    Ontology(const std::vector<Top_level> &top_levels, const std::vector<Method> &methods, const std::vector<Ruc> &rucs, const std::vector<Top_level_rel> &top_level_rel,
             const std::vector<Top_ruc_rel> &top_ruc_rel);
};

#endif // ONTOLOGY_H
