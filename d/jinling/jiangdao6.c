
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
	"northeast" : __DIR__"chibi",
	"west" : __DIR__"jiangdao5",
]));
        set("outdoors", "jinling");

        setup();
        replace_program(ROOM);
}
