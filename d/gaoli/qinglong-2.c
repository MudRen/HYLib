// /d/gaoli/zhuquedajie2
// Room in ����
// rich 99/03/28
inherit ROOM;
void create()	
{
	set("short", "�ɷ���");
	set("long", @LONG
������һ��������ʯ�����ϣ�����Ϳ쵽�����ʹ��ˡ������Կ�
���ʹ���Χǽ�������Ǹ��������ŷɷ��ţ������Ǹ�������վ��������
�����ٷ������ξ֡�
LONG
	);
set("outdoors", "/d/gaoli");
set("exits", ([
		"west" : __DIR__"qinglongmen",
		"east" : __DIR__"qinglong-1",
                "north":__DIR__"yizhan",
                "south":__DIR__"yanju",    
	]));
       setup();
	replace_program(ROOM);
}	
