
 
inherit ITEM;
inherit F_FOOD;

void create()
{
   set_name("����", ({"hua sheng","sheng"}));
        set_weight(100);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "����һ����������\n");
                set("unit", "��");
                set("value", 20);
                set("food_remaining", 5);
                set("food_supply", 20);
        }
}

