// jiuqulang2.c (kunlun)

#include <ansi.h>
#include <room.h>

inherit ROOM;

void create()
{
		  set("short", "������");
		  set("long",@long
������ǰ���оŽ����������۵�������ˮ�档һ·������������ʯ��
Ȫ���仨������ˮɫ���ܡ����ߴ����������ӣ�������������ʯΪ������¥
��գ�ת�۴�����Сͤ��ӡ�
long);
		 set("exits",([
"northwest" : __DIR__"shanlin1",
"southeast" : __DIR__"sanshengtang",
]));
setup();
replace_program(ROOM);
}
