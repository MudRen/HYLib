// Room: /d/city/yunhe2.c
// Date:  netkill  98/08/18

#include <ansi.h>
inherit ROOM;

void create()
{
    set("short", HIY "�����˺�" NOR);
    set("long", HIY @LONG
�������ھ����˺��ϡ���������ബֻ����������������
�������������ȥ��΢��ϰ�档����ྩ�ǲ�Զ�������Ĵ�ׯ
�ذ������������ǿ����˺ӵķ�������һЩС���������ӹ���
Ҳ����
LONG NOR
    );


    set("outdoors", "city");
    setup();
}


   

void init()

{	

	 object me=this_player();
	 tell_object(me, CYN "\n\n\n���ڴ����һ·�������С������ķ羰�����۵�...\n\n\n" NOR ) ;
	 call_out("goto",6, me);
	 
        }

void goto(object me)
{   
	int i;
	i=(int)me->query_temp("exit");
	if (i)
	{
	if (i<20) {
		me->move (__DIR__"yunhe1");
		message("vision","һֻС��ʻ�˹�����\n",environment(me), ({me}) );
		}
	
	if (i>20) {
		me->move (__DIR__"yunhe3");
		message("vision","һֻС��ʻ�˹�����\n",environment(me), ({me}) );
		}
	}


}