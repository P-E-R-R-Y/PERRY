/**
 * @file ICore.hpp
 * @author @Perry-Chouteau (perry.chouteau@outlook.com)
 * @brief 
 * @version 0.1
 * @date 2025-01-29
 * 
 * 
 * @addtogroup core
 * @{
 */

#ifndef ICORE_HPP
#define ICORE_HPP

/**
 * @brief define the core interface
 * @interface ICore
 */
class ICore {
    public:
        virtual ~ICore() = default;

        virtual int start() = 0;    
};

/**
 * @brief define the engine interface
 * @interface Engine
 */
class Engine : public ICore {
    public:
        virtual ~Engine() = default;

    protected:

        virtual void initHandler() = 0;
        virtual void destroyHandler() = 0;

        virtual void eventHandler() = 0;
        virtual void updateHandler() = 0;
        virtual void displayHandler() = 0;

};

/**
 * @brief define the customisable engine
 * 
 * @tparam Parents 
 */
template <typename... Parents>
class CustomisableEngine : public Engine, public Parents... {

    public:

        /**
         * @brief Construct a new Customisable Engine object (Accepts parameters for each parent class)
         * 
         * @tparam Args 
         * @param params 
         */
        template <typename... Args>
        CustomisableEngine(Args... params)
            : Parents(constructParent<Parents>(params))... { // Forward parameters to the parent constructors
        }

    private:

        //params
        template<typename T, typename = void>
        struct has_params : std::false_type {};

        template<typename T>
        struct has_params<T, std::void_t<typename T::Params>> : std::true_type {};

        template<typename T>
        static constexpr bool has_params_v = has_params<T>::value;

        //tuple
        template<typename T>
        struct is_specialization_of_tuple : std::false_type {};

        template<typename... Args>
        struct is_specialization_of_tuple<std::tuple<Args...>> : std::true_type {};

        /**
         * @brief Construct a Parent object
         * 
         * @tparam Parent 
         * @tparam Arg 
         * @param arg 
         * @return Parent 
         */
        template <typename Parent, typename Arg>
        static Parent constructParent(Arg&& arg) {
            if constexpr (!has_params_v<Parent> || std::is_same_v<Arg, std::tuple<>>) {
                //no params or empty tuple
                std::cout << "NoParams" << " > " << typeid(Parent).name() << std::endl << "\t";
                return Parent();
            } else if constexpr (is_specialization_of_tuple<typename Parent::Params>::value) {
                // unpack tuple
                std::cout << "Tuple" << " > " << typeid(Parent).name() << std::endl << "\t";
                return std::apply([](auto&&... unpackedArgs) {
                    return Parent(std::forward<decltype(unpackedArgs)>(unpackedArgs)...);
                }, std::forward<Arg>(arg));
            } else {
                // single param
                std::cout << "SingleParams" << " > " << typeid(Parent).name() << std::endl << "\t";
                return Parent(std::forward<Arg>(arg));
            }
        }
};

#endif // ICORE_HPP