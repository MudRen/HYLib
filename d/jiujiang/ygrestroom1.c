//Edit By Subzero
#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{

        set("short", YEL "����" NOR);
        set("long", @LONG
�������������������Ž��Ժ����������ص㡣�����������һ
�Ų輸���ͼ������ӣ�����������һ���������������Ů�ӡ�
LONG);

        set("valid_startroom", 1);
        set("exits", ([
        "north" : __DIR__"dongdajie3",
        "west" : __DIR__"ygrestroom2",
        ]));

		set("resouce/water",1);
        setup();
}
