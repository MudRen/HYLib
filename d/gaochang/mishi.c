// Room: /d/gaochang/shulin13.c

#include <ansi.h>

inherit ROOM;

void create()
{
	set("short", "�߲����");
	set("long", @LONG
�������м��߰׹����� ֻ����빬����Ȼ���ݣ������ж����˻�ɳ;
�������ƺ�����·����������վ��һ�����õ�ס��ȥ·��

LONG   
	);

	set("exits", ([
		"south" : __DIR__"zoulang2",
		"north" : __DIR__"mishi2"
	]));

	set("outdoors", "gaochang");
	setup();
}

void init()
{

	object ob, room;
	ob = this_player();
	room = this_object();
	if (!ob) return;
	if (!userp(ob)) return;

	if (!ob) return;
	if (!userp(ob)) return;

	if (ob->query("id") == "ghost" || !living(ob)) return;
    else if	( present("map", ob)){
	message_vision(HIW"\nͻȻ֮�䣬ǰ��һ����ɭɭ������˵����
����Ȼ���е�֮ʿ!��ô���и߲��Թ��ĵ�ͼ,�ѵ������⣿\n
�߲��Թ�����ей��ĲƸ��𣿹��������������� \n
Ц����͸�����޵������ͱ�״��\n\n" NOR, ob);
	}
    else {
   	message_vision(HIW"\nͻȻ֮�䣬ǰ��һ����ɭɭ������˵����
�ô��߲��Թ�����! ֻ��һ�������Ϯ���������Ҳ�㲻����.
ԭ����һ���������������塣\n\n" NOR, ob);
	this_player()->die();
	}

}