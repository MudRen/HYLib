// ����ս��
#include <ansi.h>
#include <weapon.h>
inherit AXE;

void create()
{
        set_name(RED"����ս��"NOR, ({"lang axe", "langaxe"}));
        set_weight(15000);

        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", RED"����һ�ѳ���ս��,�������侫��!\n"NOR);
                set("unique", 1);
                set("value", 15000);
		set("armor_prop/armor",10);
        }
     init_axe(450);
        setup();
}       