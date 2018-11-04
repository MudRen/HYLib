// Room: /d/gaochang/shulin9.c

#include <ansi.h>

inherit ROOM;

void create()
{
	set("short", "�߲��Թ�");
	set("long", @LONG
������������ĳ���,��ǰ���������������
�Թ�֮�ڲ����㼣ָ�����㲻֪��Ҫ������·�ߡ�
����ϸ���������ף����׺�ǰ������·�϶��е������㼣��
���ƺ���ʧ�˷�����ûͷ��Ӭ�㵽���Ҵ���
LONG
	);

	set("exits", ([
		"east" : __DIR__"shulin"+(random(8)+6),
		"south" : __DIR__"shulin"+(random(8)+6),
		"west" : __DIR__"shulin"+(random(8)+6),
		"north" : __DIR__"shulin"+(random(8)+6),
	]));

	set("outdoors", "gaochang");
	setup();
}

void init()
{

	object ob, room;
	mapping fam;

	int i = random(2);
	if( i == 0) return;

	ob = this_player();
	room = this_object();
	if (!ob) return;
	if (!userp(ob)) return;

	if (ob->query("id") == "gui" || !living(ob)) return;
	if (!userp(ob)) return;
	message_vision(HIR "\n$Nһ��С�ģ��������Թ��Ļ��أ�
$Nֻ����ͷ��һ����죬ԭ����ͷ��һ���ʯ���¡�\n\n" NOR, ob);

	message_vision(HIR "\n$Nʹ�ü���ʧȥ��֪��......\n\n" NOR, ob);

	if((int)this_player()->query("qi")<250) this_player()->die();
        { this_player()->unconcious();
this_player()->move("/d/gaochang/road");}
}