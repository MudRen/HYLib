// mdiamond.c ��֮��ʯ

#include <ansi.h>
#include <armor.h>

inherit HEAD;

void create()
{
	set_name(HIW "��֮��ʯ" NOR, ({ "magic diamond" }) );
	set_weight(50);
	if( clonep() )
		set_default_object(__FILE__);
	else {
                set("long", HIW "һ�Ż���������Ĺ�ʵ���ʯ��"
                    "�����Բ�ͬѰ���ĸо���\n" NOR);
                set("value", 12000);
		        set("unit", "��");
                set("can_be_enchased", 1);
                set("magic/type", "lighting");
                set("magic/power", 15 + random(16));
                set("armor_prop/percao", 18);
                set("armor_prop/karay",18);
set("armor_prop/armor", 70);

                set("wear_msg", HIC "$N" HIC "����ذ�$n"
                    HIC "����ͷ�ϡ�\n" NOR);
                set("remove_msg", HIC "$N" HIC "����ذ�$n"
                    HIC "��ͷ��ժ��������\n" NOR);
	}
        setup();
}


