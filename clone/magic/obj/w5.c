// ��ɫ��ǹ
#include <ansi.h>
#include <weapon.h>
inherit AXE;

void create()
{
        set_name(HIB"����"NOR, ({"water axe", "watersting"}));
        set_weight(15000);

        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", HIB"����һ������,�������侫��!\n"NOR);
                set("unique", 1);
                set("value", 15000);
		set("armor_prop/armor",10);
        }
     init_axe(550);
        setup();
}       