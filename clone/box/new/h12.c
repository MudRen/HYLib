// fjade.c ϡ�����

#include <ansi.h>
#include <armor.h>

inherit HEAD;

void create()
{
	set_name(HIG "ϡ�����" NOR, ({ "flawless jade" }) );
	set_weight(40);
	if( clonep() )
		set_default_object(__FILE__);
	else {
                set("long", HIG "һ�����������ױȵĴ���䡣\n" NOR);
                set("value", 10000);
		set("unit", "��");
                set("armor_prop/percao", 17);
                set("armor_prop/karay",17);
set("armor_prop/armor", 67);
                set("wear_msg", HIC "$N" HIC "����ذ�$n"
                    HIC "����ͷ�ϡ�\n" NOR);
                set("remove_msg", HIC "$N" HIC "����ذ�$n"
                    HIC "��ͷ��ժ��������\n" NOR);
	}
        setup();
}


