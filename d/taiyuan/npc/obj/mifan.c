
 
inherit ITEM;
inherit F_FOOD;

void create()
{
   set_name("�׷�", ({"rice"}));
        set_weight(100);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "����һ��������Ĵ��׷���\n");
                set("unit", "��");
                set("value", 60);
                set("food_remaining", 15);
                set("food_supply", 60);
        }
}

