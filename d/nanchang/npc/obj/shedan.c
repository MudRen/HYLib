
 
inherit ITEM;
inherit F_FOOD;

void create()
{
   set_name("�ߵ�", ({"she dan","dan"}));
        set_weight(100);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "����һ���ߵ�������ʳ�ã�Ҳ����������ҩ��\n");
                set("unit", "��");
                set("value", 100);
                set("food_remaining", 20);
                set("food_supply", 50);
				set("heal",([
					"heals":30,
					]));
        }
}

