// ������
#include <ansi.h>
#include <weapon.h>
inherit AXE;

void create()
{
        set_name(HIC"������"NOR, ({"magic axe", "maxe"}));
        set_weight(15000);

        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", HIC"����һ�ѵ�����,�������侫��!\n"NOR);
                set("unique", 1);
                set("value", 15000);
		set("armor_prop/armor",60);
        }
     init_axe(400);
        setup();
}       