
inherit ITEM;
inherit F_FOOD;
#include <ansi.h>

void create()
{
         set_name(MAG"�ϲ˷���"NOR, ({"zicai fantuan", "fantuan", "food"}));
        set_weight(50);
        if (clonep())
                set_default_object(__FILE__);
        else {
               set("long", "һ�����ϲ˰����������˱ǵ�"+name()+"��\n");
             set("unit", "��");
           set("value", 300);
             set("food_remaining", 4);
            set("food_supply", 40);
        }
}
