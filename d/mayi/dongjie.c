// rich 99/04/05
inherit ROOM;
void create()	
{
	set("short", "�����");
	set("long", @LONG
���������������򣬸տ�ʼ�������һ����Ӫ�����պ���ͻ���ַ���
��Ǩ�Ƶ�������������γ����ڵĹ�ģ���ڽֵ��ı����Ǿ�Ӫ��������
һ��СУ����
LONG
	);
set("outdoors", "mayi");
set("exits", ([
                "east": __DIR__"dongmen", 
                "west": __DIR__"center",  
	]));
set("objects",([
  __DIR__"npc/shiren":1,
  ]));
       setup();
	replace_program(ROOM);
}	
