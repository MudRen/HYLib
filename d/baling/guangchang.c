// baling/zhongxinguanchang
// Room in ���� 
// laowuwu 99/04/11
inherit ROOM;

void create()
{
	set("short", "����㳡");
	set("long", @LONG
�����ǳ��е������ģ�һ���ܿ����Ĺ㳡��������ʯ���档һЩ��
�ֺ��е��������������������������������ݡ�������һ�ô���
�����̸���ڣ��ݴ�����ǧ������䣬���������е���ʷ��֤��������
�����У�һ�ɷ������󣬶��߲�ʱ�ش������ʵĶ������������������
�������ˣ�һƬ�ྲ��
LONG
	);
        set("outdoors", "baling");
       
	set("exits", ([
		"east" : __DIR__"dongdajie1",
		"south" : __DIR__"nandajie1",
		"west" : __DIR__"xidajie1",
		"north" : __DIR__"beidajie1",
	]));
set("objects", ([
		__DIR__"npc/old" : 1,
                __DIR__"npc/shang" : 1,
	]));
	setup();
}

// laowuwu 99/03/28
