// ����ϣ�����
#include <ansi.h>
#include <weapon.h>
inherit WHIP;

void create()
{
        set_name(HIC"����ϣ�����"NOR, ({"magic whipd", "mwhipd"}));
        set_weight(15000);

        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", HIC"����һ�Ѳ���ϣ�����,�������侫��!\n"NOR);
                set("unique", 1);
                set("value", 15000);
		set("armor_prop/armor",10);
        }
     init_whip(600);
        setup();
}       