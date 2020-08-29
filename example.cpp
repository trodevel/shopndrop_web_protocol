#include "protocol.h"
#include "str_helper.h"
#include "csv_helper.h"
#include "dummy_creator.h"
#include "validator.h"

#include <iostream>       // std::cout

template <class T>
void validate( const T & o, const std::string & name )
{
    try
    {
        shopndrop_web_protocol::validator::validate( o );
        std::cout << name << " : valid" << std::endl;
    }
    catch( std::exception & e )
    {
        std::cout << name << " : invalid : " << e.what() << std::endl;
    }
}

// enums


// objects

void example_ProductItemWithId()
{
    auto obj = shopndrop_web_protocol::dummy::create__ProductItemWithId();

    std::cout << "ProductItemWithId : STR : " << shopndrop_web_protocol::str_helper::to_string( obj ) << std::endl;
}

void example_ShoppingItemWithProduct()
{
    auto obj = shopndrop_web_protocol::dummy::create__ShoppingItemWithProduct();

    std::cout << "ShoppingItemWithProduct : STR : " << shopndrop_web_protocol::str_helper::to_string( obj ) << std::endl;
}

void example_ShoppingListWithProduct()
{
    auto obj = shopndrop_web_protocol::dummy::create__ShoppingListWithProduct();

    std::cout << "ShoppingListWithProduct : STR : " << shopndrop_web_protocol::str_helper::to_string( obj ) << std::endl;
}

void example_ShoppingListWithTotals()
{
    auto obj = shopndrop_web_protocol::dummy::create__ShoppingListWithTotals();

    std::cout << "ShoppingListWithTotals : STR : " << shopndrop_web_protocol::str_helper::to_string( obj ) << std::endl;
}

void example_RideSummaryWithShopper()
{
    auto obj = shopndrop_web_protocol::dummy::create__RideSummaryWithShopper();

    std::cout << "RideSummaryWithShopper : STR : " << shopndrop_web_protocol::str_helper::to_string( obj ) << std::endl;
}

void example_RideWithId()
{
    auto obj = shopndrop_web_protocol::dummy::create__RideWithId();

    std::cout << "RideWithId : STR : " << shopndrop_web_protocol::str_helper::to_string( obj ) << std::endl;
}

void example_ShoppingRequestInfo()
{
    auto obj = shopndrop_web_protocol::dummy::create__ShoppingRequestInfo();

    std::cout << "ShoppingRequestInfo : STR : " << shopndrop_web_protocol::str_helper::to_string( obj ) << std::endl;
}

void example_AcceptedOrderUser()
{
    auto obj = shopndrop_web_protocol::dummy::create__AcceptedOrderUser();

    std::cout << "AcceptedOrderUser : STR : " << shopndrop_web_protocol::str_helper::to_string( obj ) << std::endl;
}

void example_AcceptedOrderShopper()
{
    auto obj = shopndrop_web_protocol::dummy::create__AcceptedOrderShopper();

    std::cout << "AcceptedOrderShopper : STR : " << shopndrop_web_protocol::str_helper::to_string( obj ) << std::endl;
}

void example_DashScreenUser()
{
    auto obj = shopndrop_web_protocol::dummy::create__DashScreenUser();

    std::cout << "DashScreenUser : STR : " << shopndrop_web_protocol::str_helper::to_string( obj ) << std::endl;
}

void example_DashScreenShopper()
{
    auto obj = shopndrop_web_protocol::dummy::create__DashScreenShopper();

    std::cout << "DashScreenShopper : STR : " << shopndrop_web_protocol::str_helper::to_string( obj ) << std::endl;
}


// messages

void example_GetProductItemListRequest()
{
    auto & obj = * shopndrop_web_protocol::dummy::create__GetProductItemListRequest();

    std::cout << "GetProductItemListRequest : STR : " << shopndrop_web_protocol::str_helper::to_string( obj ) << std::endl;

    std::cout << "GetProductItemListRequest : CSV : " << shopndrop_web_protocol::csv_helper::to_csv( obj ) << std::endl;

    validate( obj, "GetProductItemListRequest" );

    delete & obj;
}

void example_GetProductItemListResponse()
{
    auto & obj = * shopndrop_web_protocol::dummy::create__GetProductItemListResponse();

    std::cout << "GetProductItemListResponse : STR : " << shopndrop_web_protocol::str_helper::to_string( obj ) << std::endl;

    std::cout << "GetProductItemListResponse : CSV : " << shopndrop_web_protocol::csv_helper::to_csv( obj ) << std::endl;

    validate( obj, "GetProductItemListResponse" );

    delete & obj;
}

void example_GetShoppingRequestInfoRequest()
{
    auto & obj = * shopndrop_web_protocol::dummy::create__GetShoppingRequestInfoRequest();

    std::cout << "GetShoppingRequestInfoRequest : STR : " << shopndrop_web_protocol::str_helper::to_string( obj ) << std::endl;

    std::cout << "GetShoppingRequestInfoRequest : CSV : " << shopndrop_web_protocol::csv_helper::to_csv( obj ) << std::endl;

    validate( obj, "GetShoppingRequestInfoRequest" );

    delete & obj;
}

void example_GetShoppingRequestInfoResponse()
{
    auto & obj = * shopndrop_web_protocol::dummy::create__GetShoppingRequestInfoResponse();

    std::cout << "GetShoppingRequestInfoResponse : STR : " << shopndrop_web_protocol::str_helper::to_string( obj ) << std::endl;

    std::cout << "GetShoppingRequestInfoResponse : CSV : " << shopndrop_web_protocol::csv_helper::to_csv( obj ) << std::endl;

    validate( obj, "GetShoppingRequestInfoResponse" );

    delete & obj;
}

void example_GetShoppingListWithTotalsRequest()
{
    auto & obj = * shopndrop_web_protocol::dummy::create__GetShoppingListWithTotalsRequest();

    std::cout << "GetShoppingListWithTotalsRequest : STR : " << shopndrop_web_protocol::str_helper::to_string( obj ) << std::endl;

    std::cout << "GetShoppingListWithTotalsRequest : CSV : " << shopndrop_web_protocol::csv_helper::to_csv( obj ) << std::endl;

    validate( obj, "GetShoppingListWithTotalsRequest" );

    delete & obj;
}

void example_GetShoppingListWithTotalsResponse()
{
    auto & obj = * shopndrop_web_protocol::dummy::create__GetShoppingListWithTotalsResponse();

    std::cout << "GetShoppingListWithTotalsResponse : STR : " << shopndrop_web_protocol::str_helper::to_string( obj ) << std::endl;

    std::cout << "GetShoppingListWithTotalsResponse : CSV : " << shopndrop_web_protocol::csv_helper::to_csv( obj ) << std::endl;

    validate( obj, "GetShoppingListWithTotalsResponse" );

    delete & obj;
}

void example_GetDashScreenUserRequest()
{
    auto & obj = * shopndrop_web_protocol::dummy::create__GetDashScreenUserRequest();

    std::cout << "GetDashScreenUserRequest : STR : " << shopndrop_web_protocol::str_helper::to_string( obj ) << std::endl;

    std::cout << "GetDashScreenUserRequest : CSV : " << shopndrop_web_protocol::csv_helper::to_csv( obj ) << std::endl;

    validate( obj, "GetDashScreenUserRequest" );

    delete & obj;
}

void example_GetDashScreenUserResponse()
{
    auto & obj = * shopndrop_web_protocol::dummy::create__GetDashScreenUserResponse();

    std::cout << "GetDashScreenUserResponse : STR : " << shopndrop_web_protocol::str_helper::to_string( obj ) << std::endl;

    std::cout << "GetDashScreenUserResponse : CSV : " << shopndrop_web_protocol::csv_helper::to_csv( obj ) << std::endl;

    validate( obj, "GetDashScreenUserResponse" );

    delete & obj;
}

void example_GetDashScreenShopperRequest()
{
    auto & obj = * shopndrop_web_protocol::dummy::create__GetDashScreenShopperRequest();

    std::cout << "GetDashScreenShopperRequest : STR : " << shopndrop_web_protocol::str_helper::to_string( obj ) << std::endl;

    std::cout << "GetDashScreenShopperRequest : CSV : " << shopndrop_web_protocol::csv_helper::to_csv( obj ) << std::endl;

    validate( obj, "GetDashScreenShopperRequest" );

    delete & obj;
}

void example_GetDashScreenShopperResponse()
{
    auto & obj = * shopndrop_web_protocol::dummy::create__GetDashScreenShopperResponse();

    std::cout << "GetDashScreenShopperResponse : STR : " << shopndrop_web_protocol::str_helper::to_string( obj ) << std::endl;

    std::cout << "GetDashScreenShopperResponse : CSV : " << shopndrop_web_protocol::csv_helper::to_csv( obj ) << std::endl;

    validate( obj, "GetDashScreenShopperResponse" );

    delete & obj;
}


int main( int argc, char ** argv )
{
    if( argc > 1 )
    {
        std::srand( std::stoi( std::string( argv[1] ) ) );
    }

    // enums


    // objects

    example_ProductItemWithId();
    example_ShoppingItemWithProduct();
    example_ShoppingListWithProduct();
    example_ShoppingListWithTotals();
    example_RideSummaryWithShopper();
    example_RideWithId();
    example_ShoppingRequestInfo();
    example_AcceptedOrderUser();
    example_AcceptedOrderShopper();
    example_DashScreenUser();
    example_DashScreenShopper();

    // messages

    example_GetProductItemListRequest();
    example_GetProductItemListResponse();
    example_GetShoppingRequestInfoRequest();
    example_GetShoppingRequestInfoResponse();
    example_GetShoppingListWithTotalsRequest();
    example_GetShoppingListWithTotalsResponse();
    example_GetDashScreenUserRequest();
    example_GetDashScreenUserResponse();
    example_GetDashScreenShopperRequest();
    example_GetDashScreenShopperResponse();

    return 0;
}

