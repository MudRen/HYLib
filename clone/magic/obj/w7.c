// ����ս��
#include <ansi.h>
#include <weapon.h>
inherit STAFF;

void create()
{
        set_name(RED"����Ȩ��"NOR, ({"wl staff", "wlstaff"}));
        set_weight(15000);

        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", HIB"����һ�Ѱ���Ȩ��,�������侫��!\n"NOR);
                set("unique", 1);
                set("value", 15000);
		set("armor_prop/armor",10);
        }
     init_staff(450);
        setup();
}       