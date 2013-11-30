#ifndef RESOURCEHOLDER_H
#define RESOURCEHOLDER_H

#include <iostream>
#include <map>
#include <memory>
#include <utility>
#include "SFML/Graphics.hpp"

namespace Resource {
    enum ID {
        Earth,
        Stone
    };

    template<typename Resource, typename Identifier>
    class Holder
    {
        public:
            Holder();
            void load(Identifier id, std::string file);
            Resource& get(Identifier id);

        private:
            std::map<Identifier, std::unique_ptr<Resource> > ResourceMap;
    };

    template<typename Resource, typename Identifier>
    Holder<Resource,Identifier>::Holder()
    {}

    template<typename Resource, typename Identifier>
    void Holder<Resource,Identifier>::load(Identifier id, std::string file)
    {
        std::unique_ptr<sf::Texture> t(new sf::Texture());
        t->loadFromFile(file);

        ResourceMap.insert(std::make_pair(id, std::move(t)));
    }

    template<typename Resource, typename Identifier>
    Resource& Holder<Resource, Identifier>::get(Identifier id)
    {
        auto f = ResourceMap.find(id);
        return *f->second;
    }
}

#endif // RESOURCEHOLDER_H
