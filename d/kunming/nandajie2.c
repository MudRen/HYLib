// /d/kunming/ndajie1
// netkill /98/8/14/

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short",  "�ϴ��" );
        set("long", @LONG
��������������Ľֵ��ϣ������������ò����֣�������һ��
�͵꣬���Ǵ��ѡ��������ţ��Ա��ڸ�·�����������洫����̸Ц
�������϶���һ�Ҳ��̡�
LONG
        );
        set("outdoors", "kunming");

        set("exits", ([
                "south" : __DIR__"nanmen", 
		"north" : __DIR__"nandajie1",
		"west"  : __DIR__"kedian",
		"east"  : __DIR__"chapu",
        ]));

        setup();
        replace_program(ROOM);
}
