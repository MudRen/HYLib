// Room: /d/city/yunhe1
// Date:  inca netkill  98/08/18

#include <ansi.h>
inherit ROOM;

void create()
{
    set("short", HIY "�˺�����" NOR);
    set("long", HIY @LONG
�������ھ����˺��ϡ���������ബֻ���������������Ƿ�����
���ϣ������羰�续���������������Ĵ�ֻ���ڴ�ͣ���ۿ�������
ͣ��һֻ�󴬿�������һ����Ǯ�˵ģ���ͷվ�ż��������Ů������
ָָ���Ŀ��羰�������������ȥ��
LONG NOR
    );


    set("outdoors", "yunhe");
    setup();
}


void init()

{	
	object me=this_player();
	add_action("do_jump","jump");
	tell_object(me, CYN "\n\n\n���ڴ����һ·�������С������ķ羰�����۵�...\n\n\n" NOR ) ;
	call_out("goto",6, me);
}

int do_jump(string arg)
{
	object me=this_player();
	int i_dodge=(int)me->query_skill("dodge",0);
	me->delete_temp("exit");
	if (!arg || arg=="") return 0;
	if ( arg == "ship" && i_dodge > 60)
	{tell_object(me, "\n��һ������˫��һ�㣬����ˮ��Ư�Ĺ��������ˮ\n"+
			 "���������£�һת�ۣ���Ծ���˴��ϡ�\n\n"+
			 "ֻ�����ƶ������ʧ�����ȵĽ���һ������������һ��������ˮ�\n\n");
	me->move(__DIR__"ship");
	me->delete_temp("exit");
	}
	return 1;
}

void goto(object me)
{   
	int i;
	i=(int)me->query_temp("exit");
	if (i){
	if (i>40) {
		me->move (__DIR__"yunhe10");
		message("vision","һֻС��ʻ�˹�����\n",environment(me), ({me}) );
		return;}
	
	if (i<40) {
		me->move (__DIR__"yunhe8");
		message("vision","һֻС��ʻ�˹�����\n",environment(me), ({me}) );
		}
	}
}
