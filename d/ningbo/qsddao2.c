// /u/beyond/ningbo/qsddao1.c 
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "��ʯ�ٵ�");
        set("long",@long
������һ����ʯ����ϣ����������ǳ���æ����ʱ������������ҴҶ�����
���������һЩС��̯���ƺ���һ�����С�
long);
set("outdoors", "ningbo");
set("exits",([
"southwest" : __DIR__"qsddao3",
"northeast" : __DIR__"ttcsi",
]));
setup();
replace_program(ROOM);
}

