//niren dao.c
#include <ansi.h>
#include <weapon.h>

inherit BLADE;

void create()
{
    set_name(HIW"���е�"NOR, ({ "niren dao", "liren","dao" }) );
    set_weight(5000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
        	set("unit", "��");
        	set("value", 30000);
        	set("no_drop", "1");
        	set("material", "iron");
        	set("long", "����һ�ѷǵ��ǽ�����ʿ��������ֵ��ǵ������\n" );
        	set("wield_msg", HIW "һ�󺮹�����$N�԰ε��������е����˳���\n" NOR);
        	set("unwield_msg", HIW "$N��������㽫$n�ջ����ڡ�\n" NOR);
	}
    	init_blade(300);
	setup();
}
