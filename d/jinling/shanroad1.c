inherit ROOM;

void create()
{
        set("short", "ɽ·");
        set("long", @LONG
����һ�������߳�����Сɽ·����Ȼ����ȴ�ǹ�һ����ͨ�С�С·
˳��ɽ�н�Ϊƽ̹�ش���������չ��
LONG
        );
        set("exits", ([ 
		"eastup" : __DIR__"zijinshan2",
	       "east" : "/d/sandboy/to_zhongzhou",
]));
        set("outdoors", "xueshan");
set("objects",([
              "/d/hainan/npc/man1" : 2,
]));
        setup();
}
void init()
{
        add_action("do_go","go");

}

int do_go()
{
if(random(2)){
this_player()->move(this_object());
return 1;
}
}


