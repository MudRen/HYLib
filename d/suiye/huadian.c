// "suiye"/huadian
// Room in ��Ҷ
// laowuwu 99/03/28
inherit ROOM;
void create()	
{
	set("short", "����");
	set("long", @LONG
����һ�һ��꣬����ʱ��Ҳ��һЩ��û�����������㻨�Ľ�һ
�·��գ������ϰ��Ǹ�Ư���Ĺ����֪Ϊʲô��������������ҳ���
������������û���˸������굷�ҡ�
LONG
	);
set("exits", ([
		"south" : __DIR__"xidajie1",
		"east" : __DIR__"miaoyuan",
	]));
 set("objects",([
  __DIR__"npc/huanong":1,
  	]));		
       setup();
	replace_program(ROOM);
}	
