inherit ROOM;

void create()
{
        set("short", "�Ͻ�ɽ");
        set("long", @LONG
�Ͻ�ɽ������ɽ��ɽ���վ�����������������ʱ�����ν֮����ɽ��
󴡱��ɽ��Χ��ʤ�ż��ڶ࣬������Χ���ơ���ɽ���庣���İ���ʮ����
��Ϊ��������һ�����ϡ�
LONG
        );
        set("exits", ([ 
		"eastup" : __DIR__"zhaimen",
	       "westdown" : __DIR__"shanroad1",
]));
        set("outdoors", "xueshan");
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


