 inherit ROOM;
void create()
{
        set("short", "草原");
        set("long", @LONG
这里是一望无际的大草原。绿色的草地美丽得就象晴朗的蓝天。草原上三三两
两的羊群则是蓝天上飘浮的朵朵白云。远处的布达拉宫在骄阳下看来亮如纯银；到
了夕阳西下时又变得灿烂如黄金。你也许从没想到，在塞外的边陲之地竟有如此美
妙的地方，美得辉煌而神秘，美得令人迷惑，美得令人都醉了。
LONG
        ); 
        set("exits", ([ 
                "west" : __DIR__"citygate",
                "east" : __DIR__"deadneck",
                "north" : "/d/zangbei/temple2",
        ]));
        set("outdoors", "guanwai"); 
        set("coor/x",-1180);
        set("coor/y",-10);
        set("coor/z",0);
        setup();
        replace_program(ROOM);
}
