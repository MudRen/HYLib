// /d/yazhang/chaifengdain.c
// Room in ����
// laowuwu 99/05/05
inherit ROOM;
void create()	
{
	set("short", "�÷��");
	set("long", @LONG
�������������Ĳ÷�꣬�����������·���������ʽ�����ֹ���
������һָ�ģ����������ʶ��������ڶ��ҡ������Ʒ���·��۸񰺹�
��ȴ���Ǽ�Ʒ��
LONG
	);
set("exits", ([
                 "east" : __DIR__"nandajie1",    
	]));
 set("objects",([ __DIR__"npc/licaifeng":1,]));
       setup();
	replace_program(ROOM);
}	
