
 
inherit ITEM;
inherit F_FOOD;

void create()
{
   set_name("����", ({"ji tui","ji","tui"}));
        set_weight(200);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "����һ�����ȡ�\n");
                set("unit", "��");
                set("value", 500);
                set("food_remaining", 20);
                set("food_supply", 20);
        }
}

