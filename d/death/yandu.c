// TIE@FY3
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "ۺ����");
        set("long", @LONG
�����ǡ��޿����䣬����Ҳң����Ҳ�Т������������Ķ���š���
�����Ѻ����ͽ�����ȸոյ������ˣ�ۺ������������Ѻ�ģ�����
����ʵ��̫�࣬�����ڴ˹�Ѻ���������͵�����İ�������
LONG
        );
        set("exits", ([
		"up" : __DIR__"huokeng",
		"down" : __DIR__"bashe",
        ]) );
	set("coor/x",-1020);
	set("coor/y",-70);
	set("coor/z",-140);
	set("deathroom",1);set("no_fight",1);set("no_dazuo", "1");setup();
        replace_program(ROOM);
}
 
