// /d/jingzhou/chibi6.c
// netkill /98/9/10/
// ��ȸ����

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", YEL "��ڹ�ս��" NOR);
        set("long", @LONG
������������Ĺų�ڣ��԰�һ��޴�����������С���ڡ���
�����֣��뵱��ٰܲ��򾫱��ڴ˱�����ɱ��Ƭ�ײ��������޶��飬
����ѧ���ն������ٴ˵أ��п��������ˡ�ң�빫�����꣬С�ǳ���
�ˣ������ڽ�����Ӣ����̸Ц�䣬ǿ²�ҷ�����...���������
Ϊ�Ѿ䡣���������濴ȥ��ֻ��������ˮ����ȥ����������������
һ����������(tiesuo),ԭ���ǵ������Ϊ�˵����ܲٶ��޵���������
LONG
        );
        set("outdoors", "jingzhou");
	set("item_desc", ([
		"teisuo" : "ֻ��һ�������������ڽ��У����꽭ˮ�����Ȼ���ࡣ\n",
		]));
        set("exits", ([
                "east" : __DIR__"chibi5",
		            
        ]));

             
        setup();
	//replace_program(ROOM);
} 


void init()
{
	add_action("do_jump","jump");
	add_action("do_jump","tiao");
}

int do_jump(string arg)
{
	object me=this_player();

	if (arg=="" || ! arg ) return 0;
if (arg!="tiesuo") return 0;
	if ( (int)me->query_skill("dodge") < 100 )
		{
		message_vision("$Nһ���ۣ����������Ͻ�ˮ��\n",me);
		tell_object(me,"ֻ����һ��ǿ���ˮ���������˻�����\n");
		me->unconcious();
		}
	else {
		message_vision("$Nһ������������ȥ\n",me);
		tell_object(me,"�������������������\n");	
		me->move(__DIR__"tiesuo");
	 	}
	return 1;
}
