// /d/zhuojun/nanmen.c
// Room in �ÿ�
// laowuwu 99/04/11
inherit ROOM;
void create()	
{
	set("short", "����");
	set("long", @LONG
���ǳ�ɳ�����ţ������߾ͽ����������ǣ���Ϊ�������´�����
�԰��ŵ�ʿ����������·�����̲�÷ǳ��ϸ�
LONG
	);
set("outdoors", "changsha");
set("exits", ([
		"north" :__DIR__"nandajie1",
                "south"  :__DIR__"road5",
	]));
       set("objects",([
                __DIR__"npc/guanbing" : 2,
                __DIR__"npc/wujiang" : 1,
        ]));
       setup();
	replace_program(ROOM);
}	
