
 
inherit ITEM;
inherit F_FOOD;

void create()
{
   set_name("��Ѽ", ({"kao ya","ya"}));
        set_weight(100);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "����һ��������Ŀ�Ѽ��\n");
                set("unit", "��");
                set("value", 100);
                set("food_remaining", 10);
                set("food_supply", 50);
        }
}

