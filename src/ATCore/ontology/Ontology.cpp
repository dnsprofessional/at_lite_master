#include "Ontology.h"
#include <fstream>
#include <unordered_map>

Ontology::Ontology()
{
}

Ontology::Ontology(const std::vector<Top_level> &top_levels, const std::vector<Method> &methods, const std::vector<Ruc> &rucs, const std::vector<Top_level_rel> &top_level_rel,
                   const std::vector<Top_ruc_rel> &top_ruc_rel, const std::vector<Top_method_rel> &top_method_rels, const std::vector<Ruc_method_rel> &ruc_method_rels) :
    m_top_levels(top_levels),
    m_methods(methods),m_rucs(rucs),m_top_level_rel(top_level_rel),m_top_ruc_rel(top_ruc_rel), m_top_method_rels(top_method_rels), m_ruc_method_rels(ruc_method_rels)
{

}

void calc_ruc_weights(Ontology& onto){
    for(auto& ruc : onto.m_rucs){
        //Вес ПИК
        std::size_t weight = 0;
        //Считаем все связи ПИК с его методами
        for(auto method_id : ruc.methods){
            weight += 3;
        }
        //Считаем все связи ПИК с методами интерфейсов других ПИК
        for(auto& ruc_method_rel : onto.m_ruc_method_rels){
            if(ruc_method_rel.src_id == ruc.id){
                if(ruc_method_rel.type == Ontology::Rel_type::RS){
                    weight += 3;
                } else if(ruc_method_rel.type == Ontology::Rel_type::RM){
                    weight += 2;
                } else {
                    weight += 1;
                }
            }
        }
        for(auto& method_id : ruc.methods){
            for(auto& top_method_rel : onto.m_top_method_rels){
                if(method_id == top_method_rel.dest_id){
                    if(top_method_rel.type == Ontology::Rel_type::RS){
                        weight += 3;
                    } else if(top_method_rel.type == Ontology::Rel_type::RM){
                        weight += 2;
                    } else {
                        weight += 1;
                    }
                }
            }
        }
        //Считаем все связи компонентов с методами, которые связаны с ПИК
        for(auto& top_method_rel : onto.m_top_method_rels){
            for(auto& ruc_method_rel : onto.m_ruc_method_rels){
                if(ruc_method_rel.dest_id == top_method_rel.dest_id && ruc.id == ruc_method_rel.src_id){
                    if(top_method_rel.type == Ontology::Rel_type::RS){
                        weight += 3;
                    } else if(ruc_method_rel.type == Ontology::Rel_type::RM){
                        weight += 2;
                    } else {
                        weight += 1;
                    }
                }
            }
        }
        onto.m_ruc_weights.emplace_back(std::pair<std::string, std::size_t>(ruc.name, weight));
    }
    for(auto& pair : onto.m_ruc_weights){
        if(pair.first == "ПИК Верификация ПЗ")
            pair.first = "Верификация ПЗ";
        if(pair.first == "ПИК Синтез моделей")
            pair.first = "Построение ИМ";
        if(pair.first == "ПИК Редактор визуальных объектов")
            pair.first = "Разработка визуальной составляющей ИМ";
    }
    onto.m_ruc_weights.push_back(std::pair<std::string, std::size_t>("Приобретение знаний", 63));
    onto.m_ruc_weights.push_back(std::pair<std::string, std::size_t>("Извлечение знаний из БД", 26));
    onto.m_ruc_weights.push_back(std::pair<std::string, std::size_t>("Объединение фрагментов ПЗ", 22));
    onto.m_ruc_weights.push_back(std::pair<std::string, std::size_t>("Дизайн объяснений", 30));
    onto.m_ruc_weights.push_back(std::pair<std::string, std::size_t>("Настройка объяснительного компонента", 28));
    onto.m_ruc_weights.push_back(std::pair<std::string, std::size_t>("Настройка драйвера", 26));
    onto.m_ruc_weights.push_back(std::pair<std::string, std::size_t>("Конфигурация компонентов ядра ИЭС", 24));
    onto.m_ruc_weights.push_back(std::pair<std::string, std::size_t>("Настройка СУБД", 22));
    onto.m_ruc_weights.push_back(std::pair<std::string, std::size_t>("Подключение библиотеки ППП", 20));
    onto.m_ruc_weights.push_back(std::pair<std::string, std::size_t>("Написание сценария диалога", 18));
}

void ontology_to_graphviz(Ontology& onto){
    std::ofstream os("kb/ontology.dot");
    os << "digraph g {\nrankdir = TB;\nranksep=3;\nsubgraph{\n";
    //Связи верхнего уровня онтологии
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
    static const std::unordered_map<Ontology::Rel_type, std::string> type_to_string = {
        {Ontology::Rel_type::RA, "RA"},
        {Ontology::Rel_type::RS, "RS"},
        {Ontology::Rel_type::RM, "RM"},
        {Ontology::Rel_type::RL, "RL"}
    };
    //Связи между методами
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
    //Связи между компонентами и методами
    for(auto& rel : onto.m_top_method_rels){
        std::string src_name;
        std::string dest_name;
        std::string type;
        for(auto& top : onto.m_top_levels){
            if(top.id == rel.src_id){
                src_name = top.name;
                break;
            }
        }
        for(auto& method : onto.m_methods){
            if(method.id == rel.dest_id){
                dest_name = method.name;
                break;
            }
        }
        type = type_to_string.find(rel.type)->second;
        os << "\t \"" << src_name << "\" -> \"" << dest_name << "\" [label=\"" << type << "\"];\n";
    }
    //Связь между ПИК и их методами
    for(auto& ruc : onto.m_rucs){
        for(auto& method_id : ruc.methods){
            for(auto& method : onto.m_methods){
                if(method_id == method.id)
                    os << "\t \"" << ruc.name << "\" -> \"" << method.name << "\" [label=RS; color = red];\n";
            }
        }
    }
    //Связь между ПИК и остальными методами
    for(auto& rel : onto.m_ruc_method_rels){
        std::string src_name;
        std::string dest_name;
        std::string type;
        for(auto& ruc : onto.m_rucs){
            if(ruc.id == rel.src_id){
                src_name = ruc.name;
                break;
            }
        }
        for(auto& method : onto.m_methods){
            if(method.id == rel.dest_id){
                dest_name = method.name;
                break;
            }
        }
        type = type_to_string.find(rel.type)->second;
        os << "\t \"" << src_name << "\" -> \"" << dest_name << "\" [label=\"" << type << "\"];\n";
    }
    //Установка ранга для методов
    os << "{rank = same; ";
    for(auto& method : onto.m_methods){
        os << "\"" << method.name << "\"" << ";";
    }
    os << "}\n";
    //Установка рангов для ПИК
    os << "{rank = max; ";
    for(auto& ruc : onto.m_rucs){
        os << "\"" << ruc.name << "\"" << ";";
    }
    os << "}\n";
    os << "}\n}";
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

