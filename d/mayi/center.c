// rich 99/04/05
inherit ROOM;
void create()	
{
	set("short", "���س�����");
	set("long", @LONG
���������������򣬸տ�ʼ�������һ����Ӫ�����պ���ͻ���ַ���
��Ǩ�Ƶ�������������γ����ڵĹ�ģ�����Ծ��γ����������ģ�����
��ס���������档
LONG);
set("outdoors", "mayi");
set("exits", ([
                "north": __DIR__"beimen", 
                "south": __DIR__"nanjie",
                "east" : __DIR__"dongjie", 
                "west" : __DIR__"xijie",
	]));
set("objects",([
  __DIR__"npc/zuihan":1,
  "/clone/npc/man":2,	
  ]));
       setup();
	replace_program(ROOM);
}	
