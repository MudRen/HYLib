// ������
#include <ansi.h>
#include <weapon.h>
inherit DAGGER;

void create()
{
        set_name(RED"����֮ذ"NOR, ({"magic daggerc", "mdaggerc"}));
        set_weight(15000);

        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", RED"����һ�Ѱ���֮ذ,�������侫��!\n"NOR);
                set("unique", 1);
                set("value", 15000);
		set("armor_prop/armor",100);
        }
     init_dagger(400);
        setup();
}       