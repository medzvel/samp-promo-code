
#if !defined MAX_PROMO_CODE_LEN
	#define MAX_PROMO_CODE_LEN (24)
#endif

#if !defined MAX_PROMO_CODE
	#define MAX_PROMO_CODE (15)
#endif

new 
	PROMO_CODE[MAX_PROMO_CODE][MAX_PROMO_CODE_LEN],
	PROMO_CODE_CREATED = 0
;


forward OnPlayerUsePromoCode(playerid, const promo_name[]);

stock AddPromoCode(promo_name[])
{
	strcat(PROMO_CODE[PROMO_CODE_CREATED], promo_name);
	return PROMO_CODE_CREATED++;
}

stock UsePromoCode(playerid, promo_name[])
{
	for(new i; i<PROMO_CODE_CREATED;i++)
	{
		if(!strcmp(promo_name, PROMO_CODE[i]))
		{
			CallLocalFunction("OnPlayerUsePromoCode", "ds", playerid, PROMO_CODE[i]);
			return 1;
		}
	}
	return 0;
}

stock bool:PromoCodeExists(promo_name[])
{
	for(new i; i<PROMO_CODE_CREATED;i++)
	{
		if(!strcmp(promo_name, PROMO_CODE[i]))
		{
			return true;
		}
	}
	return false;
}
