
inherit ROOM;

void create()
{
        set("short", "��ʯ�ٵ�");
        set("long", @LONG
����һ������ʵ����ʯ����������졣
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
	"east" : __DIR__"guanroad2",  
	"westup" : __DIR__"zijinshan",
]));
        set("outdoors", "changan");

        setup();
        replace_program(ROOM);
}
