// ����ϣ�����
#include <ansi.h>
#include <weapon.h>
inherit DAGGER;

void create()
{
        set_name(GRN"ˮ��ذ��"NOR, ({"magic sworde", "msworde"}));
        set_weight(15000);

        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", GRN"����һ��ˮ��ذ��,�������侫��!\n"NOR);
                set("unique", 1);
                set("armor_prop/strength",15);
                set("value", 165000);
		set("armor_prop/armor",200);
        }
     init_dagger(500);
        setup();
}       