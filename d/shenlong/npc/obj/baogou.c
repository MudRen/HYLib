// baogou.c ����������

#include <weapon.h>
inherit STAFF;

void create()
{
        set_name("����������", ({ "shenlong gou", "gou" }));
        set_weight(3000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ�������ޱȵı�����\n");
                set("value", 30);
                set("material", "steel");
		set("rigidity", 9);
                set("unique", 1);
                set("treasure",1);
                set("wield_maxneili", 1000);
        }
            init_staff(400);
        setup();
}
