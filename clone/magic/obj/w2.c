// ��ɫ��ǹ
#include <ansi.h>
#include <weapon.h>
inherit SWORD;

void create()
{
        set_name(RED"����֮��"NOR, ({"w sword", "wsword"}));
        set_weight(15000);

        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", RED"����һ�Ѱ���֮��,�������侫��!\n"NOR);
                set("unique", 1);
                set("value", 15000);
		set("armor_prop/armor",10);
        }
     init_sword(450);
        setup();
}       