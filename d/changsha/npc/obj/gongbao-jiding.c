
 
inherit ITEM;
inherit F_FOOD;

void create()
{
   set_name("��������", ({"gongbao jiding","jiding"}));
        set_weight(100);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "����һ����������Ĺ���������\n");
                set("unit", "��");
                set("value", 2000);
                set("food_remaining", 30);
                set("food_supply", 50);
        }
}

