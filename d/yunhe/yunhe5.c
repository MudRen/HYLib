// Room: /d/city/yunhe1
// Date:  inca netkill  98/08/18

#include <ansi.h>
inherit ROOM;

void create()
{
    set("short", HIY "�˺�����" NOR);
    set("long", HIY @LONG
�������ھ����˺��ϡ����߲�ʱ���Կ���һЩϷˣ��С����Ҳ
�м��������ڴ˴���������ȥҲû����ʲô�㣬��ν����֮�ⲻ��
�ƣ��ں�ɽˮ֮�䣬�⼸���˿���ֻ��Ϊ��Ϸ�������ˡ�
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
	if (i>30) {
		me->move (__DIR__"yunhe6");
		message("vision","һֻС��ʻ�˹�����\n",environment(me), ({me}) );
		return;}
	if (i<20) {
		me->move (__DIR__"yunhe3");
		message("vision","һֻС��ʻ�˹�����\n",environment(me), ({me}) );
		}
	else{
		me->move (__DIR__"yunhe4");
		message("vision","һֻС��ʻ�˹�����\n",environment(me), ({me}) );
	    }
	}
}