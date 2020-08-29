#ifndef APG_SHOPNDROP_WEB__PROTOCOL_H
#define APG_SHOPNDROP_WEB__PROTOCOL_H

// system includes
#include <vector>
#include <map>

// includes
#include "basic_parser/object.h"
#include "shopndrop_protocol/protocol.h"

// includes for used modules
#include "generic_protocol/protocol.h"
#include "basic_objects/protocol.h"

namespace shopndrop_web_protocol
{

// Object
struct ProductItemWithId
{
    uint32_t             product_item_id;
    shopndrop_protocol::ProductItem product_item;
};

// Object
struct ShoppingItemWithProduct
{
    shopndrop_protocol::ShoppingItem shopping_item;
    shopndrop_protocol::ProductItem product_item;
};

// Object
struct ShoppingListWithProduct
{
    std::vector<ShoppingItemWithProduct> items     ;
};

// Object
struct ShoppingListWithTotals
{
    ShoppingListWithProduct shopping_list;
    double               price     ;
    double               weight    ;
};

// Object
struct RideSummaryWithShopper
{
    uint32_t             ride_id   ;
    shopndrop_protocol::RideSummary ride      ;
    std::string          shopper_name;
};

// Object
struct RideWithId
{
    uint32_t             ride_id   ;
    shopndrop_protocol::Ride ride      ;
};

// Object
struct ShoppingRequestInfo
{
    uint32_t             order_id  ;
    double               sum       ;
    double               earning   ;
    double               weight    ;
    shopndrop_protocol::Address address   ;
};

// Object
struct AcceptedOrderUser
{
    uint32_t             order_id  ;
    basic_objects::LocalTime delivery_time;
    shopndrop_protocol::Order order     ;
    double               sum       ;
    std::string          shopper_name;
};

// Object
struct AcceptedOrderShopper
{
    uint32_t             order_id  ;
    basic_objects::LocalTime delivery_time;
    shopndrop_protocol::Order order     ;
    double               sum       ;
    double               earning   ;
    double               weight    ;
};

// Object
struct DashScreenUser
{
    basic_objects::LocalTime current_time;
    std::vector<RideSummaryWithShopper> rides     ;
    std::vector<AcceptedOrderUser> orders    ;
};

// Object
struct DashScreenShopper
{
    basic_objects::LocalTime current_time;
    std::vector<RideWithId> rides     ;
    std::vector<AcceptedOrderShopper> orders    ;
};

// Message
struct GetProductItemListRequest: public shopndrop_protocol::Request
{
    enum
    {
        message_id = 1871702310
    };
};

// Message
struct GetProductItemListResponse: public generic_protocol::BackwardMessage
{
    enum
    {
        message_id = 2358384821
    };

    std::vector<ProductItemWithId> product_items;
};

// Message
struct GetShoppingRequestInfoRequest: public shopndrop_protocol::Request
{
    enum
    {
        message_id = 410040161
    };

    uint32_t             ride_id   ;
};

// Message
struct GetShoppingRequestInfoResponse: public generic_protocol::BackwardMessage
{
    enum
    {
        message_id = 1683829720
    };

    std::vector<ShoppingRequestInfo> requests  ;
};

// Message
struct GetShoppingListWithTotalsRequest: public shopndrop_protocol::Request
{
    enum
    {
        message_id = 2802146147
    };

    uint32_t             shopping_list_id;
};

// Message
struct GetShoppingListWithTotalsResponse: public generic_protocol::BackwardMessage
{
    enum
    {
        message_id = 2330732312
    };

    ShoppingListWithTotals shopping_list;
};

// Message
struct GetDashScreenUserRequest: public shopndrop_protocol::Request
{
    enum
    {
        message_id = 2366564411
    };

    uint32_t             user_id   ;
    shopndrop_protocol::GeoPosition position  ;
};

// Message
struct GetDashScreenUserResponse: public generic_protocol::BackwardMessage
{
    enum
    {
        message_id = 4017550701
    };

    DashScreenUser       dash_screen;
};

// Message
struct GetDashScreenShopperRequest: public shopndrop_protocol::Request
{
    enum
    {
        message_id = 2937124256
    };

    uint32_t             user_id   ;
    shopndrop_protocol::GeoPosition position  ;
};

// Message
struct GetDashScreenShopperResponse: public generic_protocol::BackwardMessage
{
    enum
    {
        message_id = 2290721212
    };

    DashScreenShopper    dash_screen;
};

} // namespace shopndrop_web_protocol

#endif // APG_SHOPNDROP_WEB__PROTOCOL_H

