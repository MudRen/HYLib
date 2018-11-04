// dagger.c : an example weapon

#include <weapon.h>

inherit DAGGER;

void create()
{
        set_name("��ذ", ({ "duan bi","dagger" ,"bishou"}) );
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
            set("long", "����һ�ѷ��ź����ذ�ס�\n");
                 set("value", 1500);
		set("material", "steel");
	}
        init_dagger(12);

	set("wield_msg", "$N�ӻ�������һ��$n�������С�\n");
	set("unwield_msg", "$N�����е�$n���뻳�С�\n");

	setup();
}
