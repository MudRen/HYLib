
inherit ROOM;

void create()
{
        set("short", "���ߴ��");
        set("long", @LONG
����һ���س����ϰ���������Ĺٵ���������ǲ�������ĳ�
�������󽭷紵�������Ŀ�������
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
	"east" : __DIR__"jiangdao1",
	//"west" : __DIR__"jiangdao2",
]));
        set("outdoors", "jinling");

        setup();
        replace_program(ROOM);
}
