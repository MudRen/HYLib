
 
inherit ITEM;
inherit F_FOOD;

void create()
{
   set_name("����", ({"gou rou","rou"}));
        set_weight(100);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "����һ����������Ĺ��⡣\n");
                set("unit", "��");
                set("value", 400);
                set("food_remaining", 20);
                set("food_supply", 70);
        }
}

