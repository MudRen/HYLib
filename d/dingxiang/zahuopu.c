// /d/yazhang/zahuopu.c
// Room in ����
// laowuwu 99/05/05
inherit ROOM;
void create()	
{
	set("short", "�ӻ���");
	set("long", @LONG
������˵�ط����󣬵�����ȴ���٣�����������Ϊ���֡���Ϊ���
�ӻ��Ļ���ǳ�ȫ��������һЩϡ��ŹֵĶ������������������Ŀ��ˡ�
LONG
	);
set("exits", ([
                   "south" : __DIR__"xidajie1",  
	]));
	set("objects",([
	__DIR__"npc/xiaoer2":1,
	]));
       setup();
	replace_program(ROOM);
}	
