// rich 99/04/05
inherit ROOM;
void create()	
{
	set("short", "�����");
	set("long", @LONG
���������������򣬸տ�ʼ�������һ����Ӫ�����պ���ͻ���ַ���
��Ǩ�Ƶ�������������γ����ڵĹ�ģ���ڽֵ��ı�����������լԺ��
����ס��һ���Ǹ������
LONG
	);
set("outdoors", "mayi");
set("exits", ([
                "north": __DIR__"damen", 
                "east": __DIR__"center", 
                "west": __DIR__"ximen",  
	]));
set("objects",([
  __DIR__"npc/laozhe":1,
  ]));
       setup();
	replace_program(ROOM);
}	
