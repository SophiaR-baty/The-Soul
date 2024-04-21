#include "util.hpp"
#include "items.hpp"
#include "instance.hpp"
#include "functions.hpp"

#ifdef __EMSCRIPTEN__
#include <emscripten/bind.h>
using namespace emscripten;
EMSCRIPTEN_BINDINGS(Immolate) {
    //instance.hpp
    register_vector<std::string>("VectorStr");
    class_<InstParams>("InstParams")
        .constructor<>()
        .constructor<std::string, std::string, bool>()
        .property("deck", &InstParams::deck)
        .property("stake", &InstParams::stake)
        .property("showman", &InstParams::showman)
        .property("vouchers", &InstParams::vouchers);
    class_<Instance>("Instance")
        .constructor<std::string>()
        .function("get_node", &Instance::get_node)
        .function("random", &Instance::random)
        .function("randint", &Instance::randint)
        .function("randchoice", &Instance::randchoice)

        //functions.hpp
        .function("lock", &Instance::lock)
        .function("unlock", &Instance::unlock)
        .function("isLocked", &Instance::isLocked)
        .function("nextTarot", &Instance::nextTarot)
        .function("nextPlanet", &Instance::nextPlanet)
        .function("nextSpectral", &Instance::nextSpectral)
        .function("nextJoker", &Instance::nextJoker)
        .function("getShopInstance", &Instance::getShopInstance)
        .function("nextShopItem", &Instance::nextShopItem)
        .function("nextPack", &Instance::nextPack)
        .function("nextStandardCard", &Instance::nextStandardCard)
        .function("isVoucherActive", &Instance::isVoucherActive)
        .function("activateVoucher", &Instance::activateVoucher);

    //items.hpp
    class_<ShopInstance>("ShopInstance")
        .constructor<>()
        .constructor<double, double, double, double, double>()
        .function("getTotalRate", &ShopInstance::getTotalRate)
        .property("jokerRate", &ShopInstance::jokerRate)
        .property("tarotRate", &ShopInstance::tarotRate)
        .property("planetRate", &ShopInstance::planetRate)
        .property("playingCardRate", &ShopInstance::playingCardRate)
        .property("spectralRate", &ShopInstance::spectralRate);
    class_<JokerStickers>("JokerStickers")
        .constructor<>()
        .constructor<bool, bool, bool>()
        .property("eternal", &JokerStickers::eternal)
        .property("perishable", &JokerStickers::perishable)
        .property("rental", &JokerStickers::rental);
    class_<JokerData>("JokerData")
        .constructor<>()
        .constructor<std::string, std::string, std::string, JokerStickers>()
        .property("joker", &JokerData::joker)
        .property("rarity", &JokerData::rarity)
        .property("edition", &JokerData::edition)
        .property("stickers", &JokerData::stickers);
    class_<ShopItem>("ShopItem")
        .constructor<>()
        .constructor<std::string, std::string>()
        .constructor<std::string, std::string, JokerData>()
        .property("type", &ShopItem::type)
        .property("item", &ShopItem::item)
        .property("jokerData", &ShopItem::jokerData);
    class_<WeightedItem>("WeightedItem")
        .constructor<std::string, double>()
        .property("item", &WeightedItem::item)
        .property("weight", &WeightedItem::weight);
    class_<Pack>("Pack")
        .constructor<std::string, int, int>()
        .property("type", &Pack::type)
        .property("size", &Pack::size)
        .property("choices", &Pack::choices);
    class_<Card>("Card")
        .constructor<std::string, std::string, std::string, std::string>()
        .property("base", &Card::base)
        .property("enhancement", &Card::enhancement)
        .property("edition", &Card::edition)
        .property("seal", &Card::seal);
    constant("ENHANCEMENTS", &ENHANCEMENTS);
    constant("CARDS", &CARDS);
    constant("SUITS", &SUITS);
    constant("RANKS", &RANKS);
    constant("TAROTS", &TAROTS);
    constant("PLANETS", &PLANETS);
    constant("COMMON_JOKERS", &COMMON_JOKERS);
    constant("UNCOMMON_JOKERS", &UNCOMMON_JOKERS);
    constant("RARE_JOKERS", &RARE_JOKERS);
    constant("LEGENDARY_JOKERS", &LEGENDARY_JOKERS);
    constant("VOUCHERS", &VOUCHERS);
    constant("SPECTRALS", &SPECTRALS);
    constant("TAGS", &TAGS);
    constant("BOSSES", &BOSSES);
}
#endif