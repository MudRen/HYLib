// /u/beyond/ningbo/qsddao1.c 
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "��ʯ�ٵ�");
        set("long",@long
������һ����ʯ����ϣ����������ǳ���æ����ʱ������������ҴҶ�����
���������һЩС��̯���ƺ���һ�����С���������Ǹ��ݳ��ˡ�
long);
set("outdoors", "ningbo");
set("exits",([
"southeast" : "/d/fuzhou/pingshan",
"north" : __DIR__"qsddao5",
]));
setup();
replace_program(ROOM);
}
