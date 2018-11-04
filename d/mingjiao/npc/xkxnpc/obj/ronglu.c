//Cracked by Roath
// ronglu.c ��¯
// by zhangchi

#include <ansi.h>
inherit ITEM;

int check_busy(object me);

#define OBJ_PATH "/d/kunlun/obj"

void create()
{
        set_name(HIR"��¯"NOR, ({ "rong lu", "lu" }) );
        set_weight(9000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "����������¯�������һ�ȼ�գ������������ǹ�ġ�\n");
                set("unit", "��");
		set("value", 1);
		set("no_get", 1);
        }
}

void init()
{
	add_action("do_fang","fang");
	add_action("do_fang","put");
}

int do_fang(string arg)
{
        object me, ob, jingtie;
        string item, target; 

        me = this_player();
        ob = this_object();
        
        if( me->is_busy() || me->query_temp("pending/job_busy") )
                return notify_fail("����æ���ء�\n");

        if (!arg || sscanf(arg, "%s in %s", item, target) != 2 )
            return notify_fail("��Ҫ��ʲô�����Ž����\n");

	if (item != "����" || target != "��¯")
		return notify_fail("��Ҫ��ʲô�����Ž����\n");

	if ( !jingtie=present("jing tie",me) )
		return notify_fail("�����ϲ�û�о�����\n");

	if (query_temp("in_use"))
		return notify_fail("�����¯�Ѿ����������ˣ�\n");

	message_vision("$N��һ"+jingtie->query("unit")+jingtie->query("name")+"�Ž���¯��\n",me);
	destruct(jingtie);
	message_vision(HIR"$N�Ž�ȼ�ϣ�������䣬��̼������һ¯���ܴ��\n"NOR,me);
	
	set_temp("in_use",1);
	me->set_temp("pending/job_busy",1);
	me->set_temp("gun_making",1);

	remove_call_out("burning");
	call_out("burning",10+random(5),me,0);
	me->start_busy((: check_busy :));

	return 1;
}

void burning(object me, int stage)
{
	string *burning_msg=({
		HIC"¯���ɺ��������ࡣ\n"NOR,
		HIW"¯�����ཥ��ת�ס�\n"NOR,
		HIW"����"+HIR"�Ѿ���ʼ�ܻ��ˡ�\n"NOR,
		HIW"����"+HIR"�Ѿ�ȫ���ܻ��ˣ����Ե���ģ���ˡ�\n"NOR,
	});

	message_vision(burning_msg[stage],me);
	
	if (stage != 3)
	{
		remove_call_out("burning");
		call_out("burning",10+random(5),me,++stage);
	}
	else
	{
		add_action("do_pour","dao");
		add_action("do_pour","pour");
		me->delete_temp("pending/job_busy");
		me->set_temp("pouring",1);
	}

}

int do_pour(string arg)
{	
	string item, target;
	int busy_time=0;
	object me=this_player();


        if( me->is_busy() || me->query_temp("pending/job_busy") )
                return notify_fail("����æ���ء�\n");

        if (!arg || sscanf(arg, "%s in %s", item, target) != 2 )
            return notify_fail("��Ҫ��ʲô�����������\n");

	if (item != "��ˮ" || target != "��ǹģ��")
		return notify_fail("��Ҫ��ʲô�����Ž����\n");

	if (!present("huoqiang muzi",environment(this_object())) )
		return notify_fail("����û�л�ǹģ�ӡ�\n");

	if ( !me->query_temp("pouring") )
		return notify_fail("����û�ֵ���ɡ�\n");

	if (me->query("neili") < 50 || me->query("jingli") < 50)
		return notify_fail(RED"���Ѿ���ƣ�����ˣ�\n"NOR);

	message_vision("$N�����װ��ܻ�����ˮС������Ĵ�¯����ʢ�����������ĵ�����ǹģ���\n",me);
	if (random(10) > 3)
	{
		message_vision("��⣡$Nһ��С�ģ�������ˮ�����˽��ϣ�ʹ��$N���۴��!\n",me);
		me->receive_wound("qi",100);
		busy_time=3;
	}
	me->add("jingli",-100);
	me->add("neili",-100);

	busy_time=busy_time+1;
	me->start_busy(busy_time);

	remove_action("do_pour","pour");
	remove_action("do_pour","dao");
	add_action("add_xiaohuang","add");

	return 1;
}

int add_xiaohuang(string arg)
{	
	string item, target;
	object xiaohuang;
	object me=this_player();

        if( me->is_busy() || me->query_temp("pending/job_busy") )
                return notify_fail("����æ���ء�\n");

        if (!arg || sscanf(arg, "%s in %s", item, target) != 2 )
            return notify_fail("��Ҫ��ʲô�����Ž����\n");

	if (item != "����" || target != "��ǹģ��")
		return notify_fail("��Ҫ��ʲô�����Ž����\n");

	if (!(xiaohuang=present("xiaohuang shi",me)) )
		return notify_fail("�����ϲ�û������ʯ��\n");

	if (!present("huoqiang muzi",environment(this_object())) )
		return notify_fail("����û�л�ǹģ�ӡ�\n");

	if ( !me->query_temp("pouring") )
		return notify_fail("����û�ֵ���ɡ�\n");

	if (me->query("neili") < 50 || me->query("jingli") < 50)
		return notify_fail(RED"���Ѿ���ƣ�����ˣ�\n"NOR);

	message_vision("$N����ǹģ��������һЩ���ǡ�\n",me);
	destruct(xiaohuang);

	me->add("neili",-50);

	me->start_busy(1);

	remove_action("add_xiaohuang","add");
	remove_call_out("job_done");
	call_out("job_done",5+random(10),me);

	return 1;
}

void job_done(object me)
{
	object huoqiang;

	message_vision("$N�ҿ�ģ�ӣ�������ˮ�Ѿ����̡�$N����һ����ˮ��"+
			"ֻ���������죬һ��̱ǵ�Ũ�̹��󣬻�ǹ�Ѿ��Ƴɡ�\n",me);
	huoqiang=new(OBJ_PATH"/huoqiang");
	huoqiang->move(me);
	remove_action("add_xiaohuang","add");
	delete_temp("in_use");
	me->delete_temp("gun_making");
	me->start_busy(3);

}

int check_busy(object me)
{
	if (me->query_temp("pending/job_busy"))
		return 1;
	return 0;
}

