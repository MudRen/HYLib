#include <ansi.h>

inherit ITEM;

inherit F_FOOD;

void create()
{
    set_name(GRN"�߲�"NOR, ({"shu cai", "cai"}));
    set_weight(5000);
    set("long", "һ���Ϻõ��߲�\n");
    set("unit", "��");
        set( "value", 2000 );
        set( "food_remaining", 5 );
        set( "food_supply", 25 );
}
