
 
inherit ITEM;
inherit F_FOOD;

void create()
{
   set_name("�ҳ�����", ({"liang cai","cai"}));
        set_weight(100);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "����һ�̲���ļҳ����ˡ�\n");
                set("unit", "��");
                set("value", 1000);
                set("food_remaining", 40);
                set("food_supply", 50);
        }
}

