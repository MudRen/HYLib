// Room: /d/city/yunhe1
// Date:  inca netkill  98/08/18

#include <ansi.h>
inherit ROOM;

void create()
{
    set("short", HIY "�˺�����" NOR);
    set("long", HIY @LONG
��һ·������������ɽ�����������������ۿ�ȥ����ɽ��
ˮ�����ϵĴ�Ҳ������࣬ż����һ��ֻ�촬���������ɿ��
ʻ���������ӣ�����Ϊ������Ĵ�ү���Ͷ����ġ�
LONG NOR
    );


    set("outdoors", "city");
    setup();
}


void init()

{	object me=this_player();
	tell_object(me, CYN "\n\n\n���ڴ����һ·�������С������ķ羰�����۵�...\n\n\n" NOR ) ;
	call_out("goto",6, me);
}
void goto(object me)
{   
	int i;
	i=(int)me->query_temp("exit");
	if (i)
	{
	if (i>20 && i<30) {
		me->move (__DIR__"yunhe4");
		message("vision","һֻС��ʻ�˹�����\n",environment(me), ({me}) );
		}
	if (i>30) {
		me->move (__DIR__"yunhe5");
		message("vision","һֻС��ʻ�˹�����\n",environment(me), ({me}) );
		}
	if (i<20) {
		me->move (__DIR__"yunhe2");
		message("vision","һֻС��ʻ�˹�����\n",environment(me), ({me}) );
		}
	}
}