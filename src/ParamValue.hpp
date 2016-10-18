#ifndef _PERFORMANCE_MAP_PARAM_VALUE_HPP_
#define _PERFORMANCE_MAP_PARAM_VALUE_HPP_

#include <string>
#include <vector>

namespace performance_map
{
    template <class T>
    class ParamValue
    {
        public:
            ParamValue(const std::string & name, const T & value)
            {
                this-> value = value;
                this-> name = name;
            }
            std::string get_name() const {return this->name;}
            bool is_equal(const ParamValue &target) const {
                bool ok = (value == target.value);
                return (ok and (this->name == target.get_name()));}

            std::string name;
            T value;
    };

    //template <typename T>
    //class ParamValue<T>: ParamValue
    //{
    //    public:
    //        <T> value;

    //        bool is_equal(ParamValue<T> param_value) const
    //        {
    //            bool ok = ParamValue::is_equal(param_value);
    //            return ((ok) and (this->value == param_value.value));
    //        }
    //};
}

#endif // _PERFORMANCE_MAP_PARAM_VALUE_HPP_
