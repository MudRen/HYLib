
 
inherit ITEM;
inherit F_FOOD;

void create()
{
   set_name("�ϲ�����", ({"hangzhou cuyu","yu","fish","cuyu"}));
        set_weight(200);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "�����ϲ�����ɫ��[�ϲ�����]��\n");
                set("unit", "��");
                set("value", 500);
                set("food_remaining", 30);
                set("food_supply", 50);
        }
}

