
inherit ROOM;

void create()
{
        set("short", "��ʯ�ٵ�");
        set("long", @LONG
����һ������ʵ����ʯ��������ӳ����ϰ����Ͻ�ɽ��ɽ·��
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
	"north" : __DIR__"boat_south",  
	"south" : __DIR__"guanroad4",  
//	"southwest" : "/u/gumu/tulu",  
//	"east" : "/d/wuhan/jiangbian3",
]));
        set("outdoors", "changan");
set("objects",([
              "/d/hainan/npc/man3" : 2,
]));
        setup();
        replace_program(ROOM);
}
