// shankou.c (kunlun)

#include <ansi.h>
#include <room.h>

inherit ROOM;

void create()
{
		  set("short", "����ɽ���");
		  set("long",@long
����λ����ɽ֮���һ��Сɽ�ڡ�ֻ������ɽ������ǧ�Ⱥɽ������
ɽ����ľ�����࣬��ʱ¶����ͺͺ��ɽ���ʯͷ��ɽ�����Ͼ�Ϊ��ѩ���ǣ�
�������ţ��߲�������
long);
		 set("exits",([
"west" : __DIR__"klshanlu",
"southeast" : __DIR__"kekexili",
]));
set("outdoors", "kunlun");
setup();
replace_program(ROOM);
}
