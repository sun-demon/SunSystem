#ifndef SUNSYSTEM_ICONSUMER_H
#define SUNSYSTEM_ICONSUMER_H


namespace SunSystem {
    template<typename T>
    class IConsumer {
    public:
        virtual void accept(T) = 0;
    };
}


#endif //SUNSYSTEM_ICONSUMER_H
