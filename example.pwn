// This is a comment
// uncomment the line below if you want to write a filterscript
//#define FILTERSCRIPT

#include <a_samp>
#include <promocode>
main()
{
	print("\n----------------------------------");
	print(" Promo Code Test");
	print("----------------------------------\n");
	
	if(PromoCodeExists("promonotex"))
	{
	    UsePromoCode(0, "promonotex");
	}
	else
	{
	    printf("NOT FOUND");
	}
	if(PromoCodeExists("testpromo1"))
	{
	    UsePromoCode(0, "testpromo1");
	}
	if(PromoCodeExists("testpromo"))
	{
	    UsePromoCode(0, "testpromo");
	}
	else
	{
	    printf("NOT FOUND 1");
	}
}

public OnPlayerUsePromoCode(playerid, const promo_name[])
{
	printf("PROMO CODE USED %s", promo_name);
	return 1;
}

public OnGameModeInit()
{
	AddPromoCode("testpromo1");
	AddPromoCode("testpromo2");
	// Don't use these lines if it's a filterscript
	SetGameModeText("Blank Script");
	AddPlayerClass(0, 1958.3783, 1343.1572, 15.3746, 269.1425, 0, 0, 0, 0, 0, 0);
	return 1;
}
