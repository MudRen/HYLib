// suti2.c
// Date: Nov.1997 by Venus
#include <room.h>
inherit ROOM;
void create()
{
        set("short", "�յ�");
        set("long", @LONG
�յ��ϣ��ο����е���������������ʫ����̸���ۣ��е����
��ʯ����ˮ�������е��������ߣ���������������ǿ���ţ�������
�����ţ�������ȥ��԰��ɡ�
LONG);
        set("exits", ([
            "north"     : __DIR__"suti1",
            "south"     : __DIR__"suti3",
            "west"      : __DIR__"quyuanbei",
        ]));
        set("objects", ([
            __DIR__"npc/shu-sheng" : 1,
	"quest/skills2/wunon/yu/yutan" : 1,
        ]));

        set("no_clean_up", 0);
        set("outdoors", "hangzhou");
        setup();
        replace_program(ROOM);
}
