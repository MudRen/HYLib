// Room: danqingge.c
// HEM 1998/11/1
inherit ROOM;
void create()
{
	set("short", "�����");
	set("long", @LONG
	���ǻ�԰��һ�����µĸ�¥���������Ķ�ϲ������Ūī�ĵ��ӣ��������ڵ�
����н����鷨�����������й�����໭���鷨��Ʒ����������һ����ˮ��
LONG
	);
       	set("exits", ([
		"north" : __DIR__ "huayuan2",
		"south" : __DIR__ "mochi",
        ]));
	setup();
	replace_program(ROOM);
}

