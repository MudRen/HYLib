// mcrystal.c ��֮ˮ��

#include <ansi.h>
#include <armor.h>

inherit HEAD;

void create()
{
	set_name(HIM "��֮ˮ��" NOR, ({ "magic crystal" }) );
	set_weight(50);
	if( clonep() )
		set_default_object(__FILE__);
	else {
                set("long", HIM "һ����˸�������â�ķ�ɫˮ����"
                    "���˸е�һ������ļ¡�\n" NOR);
                set("value", 12000);
		set("unit", "��");
                set("can_be_enchased", 1);
                set("magic/type", "magic");
                set("magic/power", 15 + random(16));
                set("armor_prop/percao", 18);
set("armor_prop/karay",18);
set("armor_prop/armor", 80);
                set("wear_msg", HIC "$N" HIC "����ذ�$n"
                    HIC "����ͷ�ϡ�\n" NOR);
                set("remove_msg", HIC "$N" HIC "����ذ�$n"
                    HIC "��ͷ��ժ��������\n" NOR);
	}
        setup();
}

