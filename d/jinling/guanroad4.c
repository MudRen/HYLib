
inherit ROOM;

void create()
{
        set("short", "��ʯ�ٵ�");
        set("long", @LONG
����һ������ʵ����ʯ�����
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
	"north" : __DIR__"guanroad3",  
	"south" : __DIR__"guanroad2",  
]));
        set("outdoors", "changan");
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
