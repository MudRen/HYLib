#include <ansi.h>
inherit F_FOOD;
inherit ITEM;

void create()
{
        set_name(HIR"ɺ����"NOR, ({ "guozi" }) );
        set_weight(80);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "һ�����ɫ��Ұ������\n");
                set("unit", "��");
                set("value", 0);
                set("food_remaining", 5);
                set("food_supply", 100);
        }
}

