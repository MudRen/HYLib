#include <ansi.h>

inherit ITEM;

inherit F_FOOD;

void create()
{
    set_name(BLU"Ұζ"NOR, ({"liewu", "lie"}));
    set_weight(5000);
    set("long", "һ���Ϻõ�Ұζ\n");
    set("unit", "��");
        set( "value", 2000 );
        set( "food_remaining", 5 );
        set( "food_supply", 25 );
}
