// ë�� /clone/eat/food/mao_sun.c
// by lala, 1997-12-16

#include <ansi.h>

inherit ITEM;

inherit F_FOOD;

void create()
{
    set_name(HIM"����"NOR, ({"liewu8"}));
    set_weight(50000);
    set("long", "һ������");
    set("unit", "��");

        set( "value", 800 + random( 600 ) );
        set( "food_remaining", 5 );
        set( "food_supply", 25 );
}

