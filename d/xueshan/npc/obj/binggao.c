// binggao.c 

#include <weapon.h>
inherit STAFF;

void create()
{
        set_name( "����", ({ "bing gao", "binggao","gao"}));
        set_weight(5000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "�ʵ��õĹ��ߣ����������ڱ�ѩ���Ρ�\n");
                set("value", 100);
                set("material", "steel");
        }
        init_staff(10);
        setup();
}
