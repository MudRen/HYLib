
inherit ITEM;
inherit F_FOOD;
#include <ansi.h>

void create()
{
         set_name(WHT"����Ƭ"NOR, ({"sheng yupian", "yupian", "fish"}));
        set_weight(200);
        if (clonep())
                set_default_object(__FILE__);
        else {
               set("long", "һ������ζ����"+name()+"��\n");
                set("unit", "��");
                set("value", 3000);
                set("food_remaining", 10);
                set("food_supply", 50);
        }
}
