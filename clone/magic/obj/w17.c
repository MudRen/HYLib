// ����ϣ�����
#include <ansi.h>
#include <weapon.h>
inherit SWORD;

void create()
{
        set_name(HIC"��Ԫ֮��"NOR, ({"magic sworde", "msworde"}));
        set_weight(15000);

        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", HIC"����һ�Ѵ�Ԫ֮��,�������侫��!\n"NOR);
                set("unique", 1);
                set("armor_prop/intelligence",15);
                set("value", 65000);
		set("armor_prop/armor",10);
        }
     init_sword(650);
        setup();
}       