// yan.c

#include <weapon.h>
inherit BLADE;
int do_fire(string arg);

int init()
{	add_action("do_fire","fire");
}

void create()
{
	set_name("ˮ��Ͳ", ({"yan tong", "tong"}));
	set_weight(50);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "����һ֧������ϲ����ˮ��Ͳ�������(fire)�����̡�\n");
		set("unit", "��");
		set("value", 100);
		set("material", "steel");
                set("wield_msg", "$N�������$n�������е���������\n");
                set("unwield_msg", "$N�����е�$n���˻�ȥ��\n");
	}
	init_blade(20);
        setup();

}
int do_fire(string arg)
{	
	object me=this_player(),ob;
	ob=present("yan", me);
	if (arg=="" || !arg) return notify_fail("��Ҫ��ʲô��\n");
	if ( (arg=="yan" || arg == "smoke") && objectp(ob) )
	{
	message_vision("������ˮ��Ͳ���������˼��ڣ��������³�����ֻ���ľ���ö��ˡ�\n",me);
	me->add("jing",20);
	if ((int)me->query("jing") > (int)me->query("max_jing")*2)
	me->set("jing",(int)me->query("max_jing")*2);
	destruct(ob);
	}
	else return notify_fail("���Ѿ�û������\n");
	return 1;
}	