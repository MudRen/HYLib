// fagate.c ϡ�����

#include <ansi.h>
#include <armor.h>

inherit HEAD;

int is_enchase_ob(){ return 1; }

void create()
{
	set_name(HIR "ϡ�����" NOR, ({ "flawless agate" }) );
	set_weight(40);
	if( clonep() )
		set_default_object(__FILE__);
	else {
                set("long", HIR "һ�������˵Ĵ���解�����"
                            "��ۼ���������С�\n" NOR);
                set("value", 100000);
		set("unit", "��");
                set("armor_prop/per", 7);
                set("no_identify", 1);
		set("wear_msg", HIC "$N" HIC "����ذ�$n"
                    HIC "����ͷ�ϡ�\n" NOR);
                set("remove_msg", HIC "$N" HIC "����ذ�$n"
                    HIC "��ͷ��ժ��������\n" NOR);
	}
        setup();
}

int query_autoload() { return 1; }
