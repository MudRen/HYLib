// ��ɫ��ǹ
#include <ansi.h>
#include <weapon.h>
inherit WHIP;

void create()
{
        set_name(HIB"ħ������"NOR, ({"magic whip", "mwhip"}));
        set_weight(15000);

        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", HIB"����һ��ħ������,�������侫��!\n"NOR);
                set("unique", 1);
                set("value", 15000);
		set("armor_prop/armor",30);
        }
     init_whip(470);
        setup();
}       