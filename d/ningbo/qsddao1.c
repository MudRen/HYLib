// /u/beyond/ningbo/qsddao1.c 
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "��ʯ�ٵ�");
        set("long",@long
������һ����ʯ����ϣ����������ǳ���æ����ʱ������������ҴҶ�����
���������һЩС��̯���ƺ���һ�����С���������Ǻ��ݳ��ˡ����ѿ���һ
Ƭ����ɫ���������Ǻ��ݷ���
long);
set("outdoors", "ningbo");
set("exits",([
"southeast" : __DIR__"qsddao",
"west" : "/d/hangzhou/yuhuangsj",
]));
setup();
replace_program(ROOM);
}
