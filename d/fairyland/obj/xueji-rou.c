// xzhang.c ѩ����

inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name("ѩ����", ({"xueji rou", "rou"}));
        set_weight(900);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "һֻ�ַ��ְ׵�ѩ���⡣\n");
                set("unit", "��");
                set("food_remaining", 3);
                set("food_supply", 40);
        }
}
