#include <room.h>

inherit ROOM;
void create()
{
	set("short", "�����");
	set("long", @LONG
�������ݶ���֣�ͬ���Ŀ�����ɾ�����ȶ�����ֵ�Ҫ���ֵĶ�
�ˣ�����������������������������С�����ں�ͬ����ˣ�������в���
��Χ��һ��·������������׷һֻè��
LONG );
	set("exits", ([
		"southwest" : __DIR__"eastdao",
		"north" : __DIR__"chema",
		"northwest"  : __DIR__"beidajie",
		"east"  : __DIR__"dongmen",
	]));
	set("outdoors", "xuzhou");
	setup();
	replace_program(ROOM);
}

