#include <ansi.h>

inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name(NOR + RED "����" NOR, ({ "kao rou", "kao", "rou" }));
        set_weight(100);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", RED "����һ��������Ŀ��⡣\n" NOR);
                set("unit", "��");
                set("food_remaining", 8);
                set("food_supply", 50);
        }
}
