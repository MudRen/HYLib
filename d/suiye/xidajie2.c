// "suiye"/xidajie2
// Room in ��Ҷ
// laowuwu 99/03/28
inherit ROOM;
void create()	
{
	set("short", "�����");
	set("long", @LONG
��͵�����Ҷ�ľ�ͷ�ˣ����˱���һ��ҩ���������Ź˿��⣬����
һ��������ÿ����ս��ʼʱҩ�̾ͷ����ˣ�������˵�ϰ�һֱ�ڶڻ���
ҩ����˵���г���ɽ���˲Ρ�
LONG
	);
set("outdoors", "suiye");
set("exits", ([
		
		"north" :  __DIR__"yaopu",
                 "east" :__DIR__"xidajie1",
	]));
       setup();
	replace_program(ROOM);
}	
