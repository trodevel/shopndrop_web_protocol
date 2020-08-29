// system includes
#include <map>

// includes
#include "request_type_parser.h"

namespace shopndrop_web_protocol
{

#define TUPLE_VAL_STR(_x_)  _x_,"shopndrop_web/"+std::string(#_x_)

template< typename _U, typename _V >
std::pair<_V,_U> make_inverse_pair( _U first, _V second )
{
    return std::make_pair( second, first );
}

request_type_e RequestTypeParser::to_request_type( const std::string & s )
{
    typedef std::string KeyType;
    typedef request_type_e Type;

    typedef std::map< KeyType, Type > Map;
    static const Map m =
    {
        make_inverse_pair( Type:: TUPLE_VAL_STR( GetProductItemListRequest ) ),
        make_inverse_pair( Type:: TUPLE_VAL_STR( GetProductItemListResponse ) ),
        make_inverse_pair( Type:: TUPLE_VAL_STR( GetShoppingRequestInfoRequest ) ),
        make_inverse_pair( Type:: TUPLE_VAL_STR( GetShoppingRequestInfoResponse ) ),
        make_inverse_pair( Type:: TUPLE_VAL_STR( GetShoppingListWithTotalsRequest ) ),
        make_inverse_pair( Type:: TUPLE_VAL_STR( GetShoppingListWithTotalsResponse ) ),
        make_inverse_pair( Type:: TUPLE_VAL_STR( GetDashScreenUserRequest ) ),
        make_inverse_pair( Type:: TUPLE_VAL_STR( GetDashScreenUserResponse ) ),
        make_inverse_pair( Type:: TUPLE_VAL_STR( GetDashScreenShopperRequest ) ),
        make_inverse_pair( Type:: TUPLE_VAL_STR( GetDashScreenShopperResponse ) ),
    };

    auto it = m.find( s );

    if( it == m.end() )
        return request_type_e::UNDEF;

    return it->second;
}
} // namespace shopndrop_web_protocol

