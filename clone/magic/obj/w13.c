// �����
#include <ansi.h>
#include <weapon.h>
inherit STAFF;

void create()
{
        set_name(HIC"�����"NOR, ({"magic staffd", "mstaffd"}));
        set_weight(15000);

        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", HIC"����һ�ѿ����,�������侫��!\n"NOR);
                set("unique", 1);
                set("value", 15000);
		set("armor_prop/armor",100);
        }
     init_staff(500);
        setup();
}       