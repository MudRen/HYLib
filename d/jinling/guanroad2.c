
inherit ROOM;

void create()
{
        set("short", "��ʯ�ٵ�");
        set("long", @LONG
����һ������ʵ����ʯ�������ͨ�����ꡣ
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
	"east" : __DIR__"ximen",  
	"west" : __DIR__"guanroad",
	"north" : __DIR__"guanroad4",
]));
        set("outdoors", "changan");
set("objects",([
              "/d/hainan/npc/man2" : 2,
]));
        setup();
//        replace_program(ROOM);
}

int do_go()
{
if(random(3)){
this_player()->move(this_object());
return 1;
}
}
