// /d/yazhang/zhangfang.c
// Room in ����
// laowuwu 99/05/05
inherit ROOM;
void create()	
{
	set("short", "�ʷ�");
	set("long", @LONG
�㴩����Ժ�����ʷ���һ��������Ŷ���������ǰ����һ�ų�����
����������һλ�ʷ���������������������ơ�
LONG
	);
set("exits", ([
                 "northeast" : __DIR__"shanghang",  
	]));
       setup();
	replace_program(ROOM);
}	