
inherit ROOM;

void create()
{
        set("short", "���ߴ��");
        set("long", @LONG
����һ���س����ϰ�������Ĺٵ���������ǲ�������ĳ�
�������󽭷紵�������Ŀ�������
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
	"east" : __DIR__"jiangdao3",
	"west" : __DIR__"jiangdao2",
	"south" : __DIR__"yuhuatai",
]));
        set("outdoors", "jinling");
        set("objects", 
        ([
              "/d/hainan/npc/man1" : 1,
        ]));

        setup();
        replace_program(ROOM);
}
