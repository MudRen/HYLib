// shanmen.c (kunlun)

#include <ansi.h>
#include <room.h>

inherit ROOM;

void create()
{
		  set("short", "����ɽ��");
		  set("long",@long
��һ·���������ܴ���ɳ֮�࣬������ľ������������ʱ������֦Ҷ
�д�����������·�߲ݴ�ż��Ҳ�ܷ���һЩ���ŵ�Ұ�����������������
���컨��ʮ��ïʢ��������û�뵽��ɽ��ȴ��������ڣ������Ϊһ��ǰ
����һ��ɽ�ţ�д�š������ɡ��������֡�
long);
		 set("exits",([
"east" : __DIR__"shanmen",	
]));
set("objects",([
        __DIR__"npc/kl-dizi1" :  1,
		__DIR__"npc/kl-dizi2" :  1,
]));

set("outdoors", "kunlun");
setup();
replace_program(ROOM);
}
