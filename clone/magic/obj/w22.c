// ����ϣ�����
#include <ansi.h>
#include <weapon.h>
inherit STAFF;

void create()
{
        set_name(HIB"������ǹ"NOR, ({"magic stafff", "mstafff"}));
        set_weight(15000);

        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", HIB"����һ�Ѱ�����ǹ,�������侫��!\n"NOR);
                set("unique", 1);
                set("armor_prop/strength",15);
                set("value", 165000);
		set("armor_prop/armor",100);
        }
     init_staff(800);
        setup();
}       