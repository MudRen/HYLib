
inherit ITEM;
inherit F_FOOD;
#include <ansi.h>

void create()
{
        set_name(YEL"������"NOR, ({ "kao youyu", "youyu", "yu" }) );
        set_weight(100);
        if (clonep())
                set_default_object(__FILE__);
        else {
             set("long", "һ�̾��ļӹ����ɵġ�"+name()+"����\n");
             set("unit", "��");
             set("value", 1000);
             set("food_remaining", 10);
             set("food_supply", 30);
        }
}
