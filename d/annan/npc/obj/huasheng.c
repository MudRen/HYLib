
 
inherit ITEM;
inherit F_FOOD;

void create()
{
   set_name("����", ({"hua sheng","hua","sheng"}));
        set_weight(100);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "����һ�����㻨����\n");
                set("unit", "��");
                set("value", 80);
                set("food_remaining", 10);
                set("food_supply", 20);
        }
}

