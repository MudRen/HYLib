// rich 99/04/05
inherit ROOM;
void create()	
{
	set("short", "�ϴ��");
	set("long", @LONG
���������������򣬸տ�ʼ�������һ����Ӫ�����պ���ͻ���ַ���
��Ǩ�Ƶ�������������γ����ڵĹ�ģ���ڽֵ��Ķ�����һ���ӻ��̣�
���������һ�ҹٰ���ξ֡�
LONG
	);
set("outdoors", "mayi");
set("exits", ([
                "north": __DIR__"center", 
                "south": __DIR__"nanmen",   
                "east": __DIR__"zahuopu", 
                "west": __DIR__"yanju",  
	]));
       setup();
	replace_program(ROOM);
}	
