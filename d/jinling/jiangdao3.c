
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
	"east" : __DIR__"jiangdao4",
	"west" : __DIR__"jiangdao1",
]));
        set("outdoors", "jinling");

        setup();
//        replace_program(ROOM);
}
void init()
{
        add_action("do_go","go");

}

int do_go()
{
if(random(3)){
this_player()->move(this_object());
return 1;
}
}
