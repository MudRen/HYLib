// houyuan.c (kunlun)

#include <ansi.h>
#include <room.h>

inherit ROOM;

void create()
{
		  set("short", "��Ժ");
		  set("long",@long
��������һ�����������������������ǣ�Ҳ�ͺܾ�û�б���ɨ���ˡ���Ҷ
���أ�����ȥ������ġ�ǽ������Щ���ƣ����½�����֩�������������һ��
С����Ϊ��ɹ���ܣ���ʼ���á�
long);
		 set("exits",([
			  "out" : __DIR__"fufengshan",
			  "south" : __DIR__"shanlin2",
]));
set("no_clean_up", 0);
create_door("out", "С��", "enter", DOOR_CLOSED);

set("outdoors", "kunlun");
setup();
replace_program(ROOM);
}
