// ����
#include <ansi.h>
#include <weapon.h>
inherit SWORD;

void create()
{
        set_name(YEL"����"NOR, ({"magic swordd", "mswordd"}));
        set_weight(15000);

        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", YEL"����һ������,�������侫��!\n"NOR);
                set("unique", 1);
                set("value", 15000);
		set("armor_prop/armor",50);
        }
     init_sword(550);
        setup();
}       