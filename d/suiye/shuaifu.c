// "suiye"/shuaifu
// Room in ��Ҷ
// laowuwu 99/03/28
inherit ROOM;
void create()	
{
	set("short", "˧��");
	set("long", @LONG
������Ҷ��˧�������й�����������Ȩ�����ģ���������������
���������ս�֡�ÿ������﷢����������ս��ָ��������챾���
���ϡ������Ǻ�԰��������Ŀ�����ʱ�߳�����Ѿ�ߣ�����Ԫ˧��
Ϣ���鷿��ȥ��
LONG
	);
set("exits", ([
		"west" : __DIR__"keting",
		"north" :  __DIR__"dongdajie1",
                "east"  : __DIR__"shufang",
                "south"  :__DIR__"houhuayuan",
	]));
 set("objects",([ __DIR__"npc/bing":2,]));
       setup();
	replace_program(ROOM);
}	
