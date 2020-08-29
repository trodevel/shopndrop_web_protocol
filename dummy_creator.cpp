// includes
#include "dummy_creator.h"
#include "shopndrop_protocol/dummy_creator.h"
#include "basic_parser/dummy_creator.h"
#include "generic_protocol/dummy_creator.h"
#include "basic_objects/dummy_creator.h"
#include "object_initializer.h"

namespace shopndrop_web_protocol
{

namespace dummy
{

// enums

// objects

ProductItemWithId create__ProductItemWithId()
{
    ProductItemWithId res;

    ::shopndrop_web_protocol::initialize( & res
        , ::basic_parser::dummy::create__uint32()
        , ::shopndrop_protocol::dummy::create__ProductItem()
        );

    return res;
}

ShoppingItemWithProduct create__ShoppingItemWithProduct()
{
    ShoppingItemWithProduct res;

    ::shopndrop_web_protocol::initialize( & res
        , ::shopndrop_protocol::dummy::create__ShoppingItem()
        , ::shopndrop_protocol::dummy::create__ProductItem()
        );

    return res;
}

ShoppingListWithProduct create__ShoppingListWithProduct()
{
    ShoppingListWithProduct res;

    ::shopndrop_web_protocol::initialize( & res
        , ::basic_parser::dummy::create__vector_t<ShoppingItemWithProduct, ShoppingItemWithProduct(*)()>( & dummy::create__ShoppingItemWithProduct ) // Array
        );

    return res;
}

ShoppingListWithTotals create__ShoppingListWithTotals()
{
    ShoppingListWithTotals res;

    ::shopndrop_web_protocol::initialize( & res
        , dummy::create__ShoppingListWithProduct()
        , ::basic_parser::dummy::create__double()
        , ::basic_parser::dummy::create__double()
        );

    return res;
}

RideSummaryWithShopper create__RideSummaryWithShopper()
{
    RideSummaryWithShopper res;

    ::shopndrop_web_protocol::initialize( & res
        , ::basic_parser::dummy::create__uint32()
        , ::shopndrop_protocol::dummy::create__RideSummary()
        , ::basic_parser::dummy::create__string()
        );

    return res;
}

RideWithId create__RideWithId()
{
    RideWithId res;

    ::shopndrop_web_protocol::initialize( & res
        , ::basic_parser::dummy::create__uint32()
        , ::shopndrop_protocol::dummy::create__Ride()
        );

    return res;
}

ShoppingRequestInfo create__ShoppingRequestInfo()
{
    ShoppingRequestInfo res;

    ::shopndrop_web_protocol::initialize( & res
        , ::basic_parser::dummy::create__uint32()
        , ::basic_parser::dummy::create__double()
        , ::basic_parser::dummy::create__double()
        , ::basic_parser::dummy::create__double()
        , ::shopndrop_protocol::dummy::create__Address()
        );

    return res;
}

AcceptedOrderUser create__AcceptedOrderUser()
{
    AcceptedOrderUser res;

    ::shopndrop_web_protocol::initialize( & res
        , ::basic_parser::dummy::create__uint32()
        , ::basic_objects::dummy::create__LocalTime()
        , ::shopndrop_protocol::dummy::create__Order()
        , ::basic_parser::dummy::create__double()
        , ::basic_parser::dummy::create__string()
        );

    return res;
}

AcceptedOrderShopper create__AcceptedOrderShopper()
{
    AcceptedOrderShopper res;

    ::shopndrop_web_protocol::initialize( & res
        , ::basic_parser::dummy::create__uint32()
        , ::basic_objects::dummy::create__LocalTime()
        , ::shopndrop_protocol::dummy::create__Order()
        , ::basic_parser::dummy::create__double()
        , ::basic_parser::dummy::create__double()
        , ::basic_parser::dummy::create__double()
        );

    return res;
}

DashScreenUser create__DashScreenUser()
{
    DashScreenUser res;

    ::shopndrop_web_protocol::initialize( & res
        , ::basic_objects::dummy::create__LocalTime()
        , ::basic_parser::dummy::create__vector_t<RideSummaryWithShopper, RideSummaryWithShopper(*)()>( & dummy::create__RideSummaryWithShopper ) // Array
        , ::basic_parser::dummy::create__vector_t<AcceptedOrderUser, AcceptedOrderUser(*)()>( & dummy::create__AcceptedOrderUser ) // Array
        );

    return res;
}

DashScreenShopper create__DashScreenShopper()
{
    DashScreenShopper res;

    ::shopndrop_web_protocol::initialize( & res
        , ::basic_objects::dummy::create__LocalTime()
        , ::basic_parser::dummy::create__vector_t<RideWithId, RideWithId(*)()>( & dummy::create__RideWithId ) // Array
        , ::basic_parser::dummy::create__vector_t<AcceptedOrderShopper, AcceptedOrderShopper(*)()>( & dummy::create__AcceptedOrderShopper ) // Array
        );

    return res;
}

// messages

GetProductItemListRequest * create__GetProductItemListRequest()
{
    auto res = new GetProductItemListRequest;

    ::shopndrop_web_protocol::initialize( res
        , ::basic_parser::dummy::create__string()
        );

    return res;
}

GetProductItemListResponse * create__GetProductItemListResponse()
{
    auto res = new GetProductItemListResponse;

    ::shopndrop_web_protocol::initialize( res
        , ::basic_parser::dummy::create__vector_t<ProductItemWithId, ProductItemWithId(*)()>( & dummy::create__ProductItemWithId ) // Array
        );

    return res;
}

GetShoppingRequestInfoRequest * create__GetShoppingRequestInfoRequest()
{
    auto res = new GetShoppingRequestInfoRequest;

    ::shopndrop_web_protocol::initialize( res
        , ::basic_parser::dummy::create__string()
        , ::basic_parser::dummy::create__uint32()
        );

    return res;
}

GetShoppingRequestInfoResponse * create__GetShoppingRequestInfoResponse()
{
    auto res = new GetShoppingRequestInfoResponse;

    ::shopndrop_web_protocol::initialize( res
        , ::basic_parser::dummy::create__vector_t<ShoppingRequestInfo, ShoppingRequestInfo(*)()>( & dummy::create__ShoppingRequestInfo ) // Array
        );

    return res;
}

GetShoppingListWithTotalsRequest * create__GetShoppingListWithTotalsRequest()
{
    auto res = new GetShoppingListWithTotalsRequest;

    ::shopndrop_web_protocol::initialize( res
        , ::basic_parser::dummy::create__string()
        , ::basic_parser::dummy::create__uint32()
        );

    return res;
}

GetShoppingListWithTotalsResponse * create__GetShoppingListWithTotalsResponse()
{
    auto res = new GetShoppingListWithTotalsResponse;

    ::shopndrop_web_protocol::initialize( res
        , dummy::create__ShoppingListWithTotals()
        );

    return res;
}

GetDashScreenUserRequest * create__GetDashScreenUserRequest()
{
    auto res = new GetDashScreenUserRequest;

    ::shopndrop_web_protocol::initialize( res
        , ::basic_parser::dummy::create__string()
        , ::basic_parser::dummy::create__uint32()
        , ::shopndrop_protocol::dummy::create__GeoPosition()
        );

    return res;
}

GetDashScreenUserResponse * create__GetDashScreenUserResponse()
{
    auto res = new GetDashScreenUserResponse;

    ::shopndrop_web_protocol::initialize( res
        , dummy::create__DashScreenUser()
        );

    return res;
}

GetDashScreenShopperRequest * create__GetDashScreenShopperRequest()
{
    auto res = new GetDashScreenShopperRequest;

    ::shopndrop_web_protocol::initialize( res
        , ::basic_parser::dummy::create__string()
        , ::basic_parser::dummy::create__uint32()
        , ::shopndrop_protocol::dummy::create__GeoPosition()
        );

    return res;
}

GetDashScreenShopperResponse * create__GetDashScreenShopperResponse()
{
    auto res = new GetDashScreenShopperResponse;

    ::shopndrop_web_protocol::initialize( res
        , dummy::create__DashScreenShopper()
        );

    return res;
}

} // namespace dummy

} // namespace shopndrop_web_protocol

