// TIE@FY3
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "���޵�");
        set("long", @LONG
����һ·�����ĺڰ���է��������ţ�;���ҫ�۵Ĺ�â����һ�����Σ�
�����������̽�����������϶�����һλ����������������������ֻأ�
���������������������������й٣������������ᣬţͷ�����棬������
������üŭĿ���������˷�������һ�����棬��棬ë�棬�۽��޲��ɴ����С�
LONG
        );
        set("objects", ([
                __DIR__"npc/yanwang":1,
		__DIR__"npc/panguan2" : 4,
		__DIR__"npc/niutou" : 3,
		__DIR__"npc/mamian" : 3,
        ]) );
	set("coor/x",-1020);
	set("coor/y",-30);
	set("coor/z",-100);
	set("deathroom",1);set("no_fight",1);set("no_dazuo", "1");setup();
}
void init()
{
	
	remove_call_out("letgo");
	call_out("letgo",15,this_player());	
}

void letgo(object me)
{
	object room;
me=this_player();
	if(!me || environment(me) != this_object()) return;
	message_vision("\n\n\n����ү��̾һ�����������ˣ����ˣ���$N�Ĵ���䣬
֪���������ͷ�������ֻҪ$N������Ҳ���Һ�����Ϊ�Ϳ����ˣ���\n\n",me);
	message_vision("\n\nһ����紵ɢ��$N�����꣮����\n\n",me);
	room = load_object(__DIR__"dizang");
	if(objectp(room))  me->move(room);	
} 
