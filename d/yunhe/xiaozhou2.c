// Room: /d/city/xiaozhou2.c ��ɽС��
// Date: netkill /98/8/18

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "С��");
	set("long", @LONG
һҶС�ۣ����Ҳ�������������ˡ�һ������������ֳ�
����ݣ������ļ��Ŵ���
LONG
	);

	setup();
}

void init()

{	object me=this_player();
	me->delete_temp("ok");me->delete_temp("ok1");
	tell_object(me, CYN "\n\n\n���ڴ����һ·�������С������ķ羰�����۵�...\n\n\n" NOR ) ;
	call_out("goto",10, me);
}
void goto(object me)
{   
	int i;
	i=(int)me->query_temp("exit");
	find_object(__DIR__"xiaozhou2")->delete("yell_trigger");
	if (i<20) {
		me->move (__DIR__"yunhe3");
		message("vision","һֻС��ʻ�˹�����\n",environment(me), ({me}) );
		}
	if (i>30) {
		me->move (__DIR__"yunhe5");
		message("vision","һֻС��ʻ�˹�����\n",environment(me), ({me}) );
		}
	}