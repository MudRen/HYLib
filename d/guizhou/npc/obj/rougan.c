
 
inherit ITEM;
inherit F_FOOD;

void create()
{
   set_name("���", ({"rou gan","rou"}));
        set_weight(100);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "����һ����ɣ���ʱ�䲻�ḯ�á�\n");
                set("unit", "��");
                set("no_decay",1);
                set("value", 50);
                set("food_remaining", 5);
                set("food_supply", 20);
        }
}

