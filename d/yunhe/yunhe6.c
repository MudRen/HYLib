// Room: /d/city/yunhe1
// Date:  inca netkill  98/08/18

#include <ansi.h>
inherit ROOM;

void create()
{
    set("short", HIY "�˺�����" NOR);
    set("long", HIY @LONG
�����������������ھ����˺��ϡ���������ബֻ����������
���������ݲ�Զ�����Ժ��ϻ��в��ٻ��������ϲ�ʱ���������
���������ο͵���Ц������֪��������������·�Ҳ����Ⱦ�ˣ�
���������ˡ�����ʮ��ᣬ��������ݡ���仰��
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
	if (i>30 && i<40 ) {
		me->move (__DIR__"yunhe7");
		message("vision","һֻС��ʻ�˹�����\n",environment(me), ({me}) );
		}
	if (i>40) {
		me->move (__DIR__"yunhe8");
		message("vision","һֻС��ʻ�˹�����\n",environment(me), ({me}) );
		}
	if (i<30) {
		me->move (__DIR__"yunhe5");
		message("vision","һֻС��ʻ�˹�����\n",environment(me), ({me}) );
		}
	}
}