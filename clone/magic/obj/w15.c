// ����ʿǹ
#include <ansi.h>
#include <weapon.h>
inherit CLUB;

void create()
{
        set_name(HIW"����ʿǹ"NOR, ({"magic clubd", "mclubd"}));
        set_weight(15000);

        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", HIC"����һ������ʿǹ,�������侫��!\n"NOR);
                set("unique", 1);
                set("value", 15000);
		set("armor_prop/armor",200);
        }
     init_club(400);
        setup();
}       