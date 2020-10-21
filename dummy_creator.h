#ifndef APG_SHOPNDROP_WEB_PROTOCOL__DUMMY_CREATOR_H
#define APG_SHOPNDROP_WEB_PROTOCOL__DUMMY_CREATOR_H

// includes
#include "protocol.h"

namespace shopndrop_web_protocol
{

namespace dummy
{

// enums


// objects

ProductItemWithId create__ProductItemWithId();
ShoppingItemWithProduct create__ShoppingItemWithProduct();
ShoppingListWithProduct create__ShoppingListWithProduct();
ShoppingListWithTotals create__ShoppingListWithTotals();
RideSummaryWithShopper create__RideSummaryWithShopper();
RideWithId create__RideWithId();
ShoppingRequestInfo create__ShoppingRequestInfo();
AcceptedOrderUser create__AcceptedOrderUser();
AcceptedOrderShopper create__AcceptedOrderShopper();
DashScreenUser create__DashScreenUser();
DashScreenShopper create__DashScreenShopper();

// messages

GetProductItemListRequest * create__GetProductItemListRequest();
GetProductItemListResponse * create__GetProductItemListResponse();
GetShoppingRequestInfoRequest * create__GetShoppingRequestInfoRequest();
GetShoppingRequestInfoResponse * create__GetShoppingRequestInfoResponse();
GetShoppingListWithTotalsRequest * create__GetShoppingListWithTotalsRequest();
GetShoppingListWithTotalsResponse * create__GetShoppingListWithTotalsResponse();
GetDashScreenUserRequest * create__GetDashScreenUserRequest();
GetDashScreenUserResponse * create__GetDashScreenUserResponse();
GetDashScreenShopperRequest * create__GetDashScreenShopperRequest();
GetDashScreenShopperResponse * create__GetDashScreenShopperResponse();

} // namespace dummy

} // namespace shopndrop_web_protocol

#endif // APG_SHOPNDROP_WEB_PROTOCOL__DUMMY_CREATOR_H
