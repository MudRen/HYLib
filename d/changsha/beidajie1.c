// /d/zhuojun/beidajie1.c
// Room in �ÿ�
// laowuwu 99/04/11
inherit ROOM;
void create()	
{
	set("short", "�����");
	set("long", @LONG
��������ʯ�̳ɵ���·����������������ô�������ǳ�ɳ�ı�
���ţ��������߲�Զ���ǳ�ɳ�����Ĺ㳡�����洫�����������Ĵ�������
������һ��С�ﲻ֪ͨ��δ���
LONG
	);
set("outdoors", "changsha");
set("exits", ([
		"north" :__DIR__"beimen",
                "south"  :__DIR__"beidajie2",
                "west"  :__DIR__"tiejiangpu",
                 "east"  :__DIR__"xiaoxiang",
                
	]));
       setup();
	replace_program(ROOM);
}	
