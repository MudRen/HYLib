//Cracked by Roath
// huolu.c ��¯
// by zhangchi

#include <ansi.h>
inherit ITEM;

int check_busy(object me);

// #define OBJ_PATH "/u/zhangchi/mingjiao/upload"
#define OBJ_PATH "/d/kunlun/obj"

void create()
{
        set_name(HIR"��¯"NOR, ({ "huo lu", "lu" }) );
        set_weight(9000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "���������¯�������ۻ�ȼ�գ���������������\n");
                set("unit", "��");
		set("no_get", 1);
        }
}

void init()
{
	add_action("do_tou","tou");
	add_action("do_tou","put");
}

int do_tou(string arg)
{
        object me, ob,kuangshi;
        string item, target; 

        me = this_player();
        ob = this_object();
        
        if( me->is_busy() || me->query_temp("pending/job_busy") )
                return notify_fail("����æ���ء�\n");

        if (!arg || sscanf(arg, "%s in %s", item, target) != 2 )
            return notify_fail("��Ҫ��ʲô�����Ž����\n");

	if (item != "��ʯ" || target != "��¯")
		return notify_fail("��Ҫ��ʲô�����Ž����\n");

	if ( !kuangshi=present("wujin kuangshi",me) )
		return notify_fail("�����ϲ�û�п�ʯ��\n");

	if (query_temp("in_use"))
		return notify_fail("�����¯�Ѿ����������ˣ�\n");

	message_vision("$N��һ"+kuangshi->query("unit")+kuangshi->query("name")+"Ͷ����¯��\n",me);
	destruct(kuangshi);
	message_vision(HIC"$N�������䣬�����ɺ��������࣬����һ�ɶ�ߣ�\n"NOR,me);
	
	set_temp("in_use",1);
	me->set_temp("pending/job_busy",1);
	me->set_temp("refining",1);

	remove_call_out("burning");
	call_out("burning",10+random(5),me);
	me->start_busy((: check_busy :));

	return 1;
}

void burning(object me)
{
	write(HIW"��ʯ�Ѿ����յ�ͨ�죬�������Կ�ʼ������\n"NOR);
	add_action("do_datie","da");
	add_action("do_datie","refine");
	me->delete_temp("pending/job_busy");
}

int do_datie(string arg)
{	
	object me=this_player();

        if( me->is_busy() || me->query_temp("pending/job_busy") )
                return notify_fail("����æ���ء�\n");

	if (arg != "tie" && arg != "��")
		return notify_fail("��Ҫ��ʲô��\n");

	if (!present("tie chui",me))
		return notify_fail("��û����������ʲô��\n");

	if (me->query("neili") < 50 || me->query("jingli") < 50)
		return notify_fail(RED"���Ѿ���ƣ�����ˣ�\n"NOR);

	message_vision("$N�Ӷ��������������պ������ʯ�ݺݵش�����ȥ��\n",me);
	me->add("neili",-30);
	me->set_temp("pending/job_busy",1);

// let player improve their force level //add later
	remove_call_out("job_done");
	call_out("job_done",5+random(10),me);
	me->start_busy( (: check_busy :) );

	return 1;
}

void job_done(object me)
{
	object jingtie;

	if (random(me->query_str()) > 20 && random(10) > 5 )
	{
		message_vision(HIC"����ǧ�����������������������ˣ�$N���������£������۵ô�����������\n"NOR,me);
		jingtie=new(OBJ_PATH"/jingtie");
		jingtie->move(me);
		remove_action("do_datie","da");
		remove_action("do_datie","refine");
		delete_temp("in_use");
		me->delete_temp("refining");
	}
	else
	{
		tell_object(me,HIR"����˲����ϵĺ������˿���ʯ�����������ٴ�\n"NOR);
	}
	me->delete_temp("pending/job_busy");
}

int check_busy(object me)
{
	if (me->query_temp("pending/job_busy"))
		return 1;
	return 0;
}

