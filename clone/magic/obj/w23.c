// ����ϣ�����
#include <ansi.h>
#include <weapon.h>
inherit SWORD;

void create()
{
        set_name(RED"����֮��"NOR, ({"magic swordf", "mswordf"}));
        set_weight(15000);

        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", RED"����һ������֮��,�������侫��!\n"NOR);
                set("unique", 1);
                set("armor_prop/dexterity",15);
                set("value", 165000);
		set("armor_prop/armor",50);
        }
     init_sword(800);
        setup();
}       