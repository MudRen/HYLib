
 
inherit ITEM;
inherit F_FOOD;

void create()
{
   set_name("��ɳ������", ({"chou doufu","doufu"}));
        set_weight(100);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "����һ����������ĳ�ɳ��������\n");
                set("unit", "��");
                set("value", 2000);
                set("food_remaining", 100);
                set("food_supply", 100);
        }
}

