
 
inherit ITEM;
inherit F_FOOD;

void create()
{
   set_name("������", ({"kao yangrou","yangrou"}));
        set_weight(100);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "����һ����������Ŀ����⡣\n");
                set("unit", "��");
                set("value", 500);
                set("food_remaining", 15);
                set("food_supply", 50);
        }
}

