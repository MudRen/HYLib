
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
	"southeast" : __DIR__"taihu",
	"west" : __DIR__"jiangdao3",
]));
        set("outdoors", "jinling");

        setup();
        replace_program(ROOM);
}
