// diamond.c ��ʯ

#include <ansi.h>
#include <armor.h>

inherit HEAD;

void create()
{
	set_name(HIW "��ʯ" NOR, ({ "diamond" }) );
	set_weight(30);
	if( clonep() )
		set_default_object(__FILE__);
        else {
	        set("long", HIW "һ��������������ʯ��\n" NOR);
                set("value", 5000);
		set("unit", "��");
                set("armor_prop/percao", 15);
set("armor_prop/karay",15);
set("armor_prop/armor", 65);

                set("wear_msg", HIC "$N" HIC "����ذ�$n"
                    HIC "����ͷ�ϡ�\n" NOR);
                set("remove_msg", HIC "$N" HIC "����ذ�$n"
                    HIC "��ͷ��ժ��������\n" NOR);
	}
        setup();
}


