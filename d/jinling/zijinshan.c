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
		"westup" : __DIR__"zhaimen",
	       "eastdown" : __DIR__"guanroad",
]));
        set("objects", ([
              __DIR__"npc/wulinren" : 2,
			]) );
        set("outdoors", "xueshan");
        setup();
}

int do_go()
{
if(random(2)){
this_player()->move(this_object());
return 1;
}
}


